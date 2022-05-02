#include <io.h>
#include <system.h>
#include <sys/alt_irq.h>
#include <stdbool.h>

#include <altera_up_avalon_video_pixel_buffer_dma.h>
#include <altera_avalon_pio_regs.h>
#include <altera_avalon_timer_regs.h>
#include <Altera_UP_SD_Card_Avalon_Interface.h>
#include <altera_up_avalon_rs232.h>

#include "piezo.h"

#define COLOR_WHITE 0xFFFF
#define COLOR_BLACK 0x0000
#define COLOR_INTEL_BLUE 0x1D3C
#define WIDTH 320
#define HEIGHT 240
#define PIXEL_BUFFER_ADDR 0x8000000

float xl0, yl0, xr0, yr0;
float xb0, yb0;
float xl1, yl1, xr1, yr1;
float xb1, yb1;
float vlx, vly, vrx, vry;
float vbx, vby;
int scoreL = 0, scoreR = 0;

int paddleW = 6, paddleH = 50;
float paddleSpeed = 2;
int ballSize = 2;

short int sd_card_handle;

static void timer_2_int_init();
void timer_2_isr();
void update_timer_2(float duration_period);
static void timer_3_init();
void timer_3_isr();

bool inPaddleBound(float y, float yp);
void resetObjects();
void updateBallPos();
void updatePaddlePos();
void drawBall();
void drawPaddles();
void draw();

alt_up_pixel_buffer_dma_dev *pixel_buffer_dev;
alt_up_sd_card_dev *sd_card_dev;
short int config;

float static timer_note_period[37] = { // C5 to C8
		95556.62, 90192.47, 85131.02, 80353.56, 75843.76, 71586.06, 67568.48,
				63776.32, 60196.72, 56818.18, 53629.08, 50619.07, 47778.31,
				45096.64, 42565.51, 40176.45, 37921.59, 35793.29, 33784.24,
				31888.16, 30098.36, 28409.09, 26814.54, 25309.66, 23889.15,
				22548.32, 21282.75, 20088.23, 18960.8, 17896.58, 16892.12,
				15944.08, 15049.18, 14204.55, 13407.31, 12654.8, 11944.55 };

int pokemon_song_index[98] = { 12, 14, 16, 16, 16, 12, 14, 16, 16, 16, 12, 14,
		16, 16, 17, 16, 14, 11, 12, 14, 14, 14, 11, 12, 14, 14, 14, 11, 12, 14,
		14, 16, 14, 12, 12, 14, 16, 16, 16, 12, 14, 16, 16, 16, 12, 14, 16, 16,
		17, 16, 14, 11, 12, 14, 17, 16, 14, 12, 11, 9, 11, 21, 11, 0, 11, 9, 11,
		12, 16, 17, 19, 19, 16, 12, 24, 23, 21, 23, 19, 16, 12, 16, 14, 16, 17,
		19, 19, 16, 12, 24, 23, 21, 17, 19, 24, 23, 26, 24 };
int pokemon_song_duration[98] = { 8, 8, 4, 4, 4, 8, 8, 4, 4, 4, 8, 8, 4, 4, 3,
		8, 1.5,

		8, 8, 4, 4, 4, 8, 8, 4, 4, 4, 8, 8, 4, 4, 3, 8, 1.5,

		8, 8, 4, 4, 4, 8, 8, 4, 4, 4, 8, 8, 4, 4, 3, 8, 1.5,

		8, 8, 4, 4, 4, 8, 8, 4, 4, 4, 8, 8, 4, 4, 3, 8, 1.5,

		8, 8, 4, 4, 4, 4, 4, 4, 4, 4, 3, 16, 16, 8, 8, 8, 1.5,

		8, 8, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 1.5, 8, 8, 4, 4, 4, 4, 4, 4,
		4, 4, 4, 4, 4, 4, 1.5 };
float tempo = 85 / 60; // 85 bpm
int song_ptr = 0;
int song_length = 98;

int main() {
	sd_card_dev = alt_up_sd_card_open_dev("/dev/sd_card");
	while (!alt_up_sd_card_is_Present()) {
		IOWR_ALTERA_AVALON_PIO_DATA(HEX_DISPLAYS_BASE, 1);
	}
	while (!alt_up_sd_card_is_FAT16()) {
		IOWR_ALTERA_AVALON_PIO_DATA(HEX_DISPLAYS_BASE, 2);
	}
	pixel_buffer_dev = alt_up_pixel_buffer_dma_open_dev(
			"/dev/pixel_buffer_dma");
	alt_up_pixel_buffer_dma_clear_screen(pixel_buffer_dev, 0);
	alt_up_pixel_buffer_dma_clear_screen(pixel_buffer_dev, 1);
	xl1 = paddleW / 2;
	yl1 = HEIGHT / 2;
	xr1 = WIDTH - (paddleW / 2);
	yr1 = HEIGHT / 2;
	timer_0_int_init();
	timer_1_int_init();
	timer_2_int_init();
	update_timer_2(0.01);
	timer_3_init(1000 / 60);
	time_t t;
	srand((unsigned) time(&t));
	resetObjects();

	sd_card_handle = alt_up_sd_card_fopen("config.txt", 0);
	config = alt_up_sd_card_read(sd_card_handle);
	alt_up_sd_card_fclose(sd_card_handle);
	while (1) {
		IOWR_ALTERA_AVALON_PIO_DATA(LEDR_BASE, config);
	}
//
	return 0;
}

static void timer_2_int_init() {
	// stop the timer first
	IOWR_ALTERA_AVALON_TIMER_CONTROL(TIMER_2_BASE, 0x8);

	// timer interrupt handler
	alt_ic_isr_register(TIMER_2_IRQ_INTERRUPT_CONTROLLER_ID, TIMER_2_IRQ,
			timer_2_isr, NULL, NULL);
}
void timer_2_isr() { // signals when the note is done playing
	// clear the TO bit first
	IOWR_ALTERA_AVALON_TIMER_STATUS(TIMER_2_BASE, 0);

	float note_period = timer_note_period[pokemon_song_index[song_ptr]];
	float note_duration = tempo / pokemon_song_duration[song_ptr];
	play_note(note_period, note_duration);
	update_timer_2(note_duration);
	if (song_ptr < song_length)
		song_ptr++;
	else
		song_ptr = 0;

	// dummy instruction to synchronize
	IORD_ALTERA_AVALON_TIMER_STATUS(TIMER_2_BASE);
	return;
}

void update_timer_2(float duration_period) {
	// stop the timer
	IOWR_ALTERA_AVALON_TIMER_CONTROL(TIMER_2_BASE, 0x8);

	// load the correct value into the registers
	int period = duration_period * 1000 * TIMER_2_LOAD_VALUE;
	int periodlo = period & 0xffff;
	int periodhi = period >> 16;
	IOWR_ALTERA_AVALON_TIMER_PERIODL(TIMER_2_BASE, periodlo);
	IOWR_ALTERA_AVALON_TIMER_PERIODH(TIMER_2_BASE, periodhi);

	//enable ITO, not CONT, and START bits
	IOWR_ALTERA_AVALON_TIMER_CONTROL(TIMER_2_BASE, 0b101);
}

static void timer_3_init(int period_arg) {
	// stop the timer first
	IOWR_ALTERA_AVALON_TIMER_CONTROL(TIMER_3_BASE, 0x8);

	// set the period to 1000 ms, TIMER_LOAD_VALUE is scalar for 1ms in the native clk freq
	int period = period_arg * TIMER_3_LOAD_VALUE;
	int periodlo = period & 0xffff;
	int periodhi = period >> 16;
	IOWR_ALTERA_AVALON_TIMER_PERIODL(TIMER_3_BASE, periodlo);
	IOWR_ALTERA_AVALON_TIMER_PERIODH(TIMER_3_BASE, periodhi);

	//enable ITO, CONT, and START bits
	IOWR_ALTERA_AVALON_TIMER_CONTROL(TIMER_3_BASE, 0b111);

	// timer interrupt handler
	alt_ic_isr_register(TIMER_3_IRQ_INTERRUPT_CONTROLLER_ID, TIMER_3_IRQ,
			timer_3_isr, NULL, NULL);
}
void timer_3_isr() {
	// clear the TO bit
	IOWR_ALTERA_AVALON_TIMER_STATUS(TIMER_3_BASE, 0);

	draw();

	// dummy instruction to synchronize
	IORD_ALTERA_AVALON_TIMER_STATUS(TIMER_3_BASE);
	return;
}

bool inPaddleBound(float y, float yp) {
	return (y >= (yp - paddleH / 2)) && (y <= (yp + paddleH / 2));
}

void resetObjects() {
	alt_up_pixel_buffer_dma_draw_box(pixel_buffer_dev, 0, 0, WIDTH - 1,
			HEIGHT - 1, COLOR_BLACK, 0);
	xb1 = WIDTH / 2;
	yb1 = HEIGHT / 2;
	vbx = 2;
	vby = 0.3;
	vlx = 0;
	vly = 0;
	vrx = 0;
	vry = 0;
	alt_up_pixel_buffer_dma_draw_box(pixel_buffer_dev, (int) xl1 - paddleW / 2,
			(int) yl1 - paddleH / 2, (int) xl1 + paddleW / 2,
			(int) yl1 + paddleH / 2, COLOR_WHITE, 0);
	alt_up_pixel_buffer_dma_draw_box(pixel_buffer_dev, (int) xr1 - paddleW / 2,
			(int) yr1 - paddleH / 2, (int) xr1 + paddleW / 2,
			(int) yr1 + paddleH / 2, COLOR_WHITE, 0);
}

int note = 0;
void updateBallPos() {
	xb0 = xb1;
	yb0 = yb1;
	xb1 += vbx;
	yb1 += vby;
	if (xb1 <= paddleW) {
		if (!inPaddleBound(yb1, yl1)) {
			scoreR += 1;
			resetObjects();
		} else {
			xb1 = 2 * (paddleW) - xb1;
			vbx *= -1;
			vby += 0.7 * vly;
			//play_note(timer_note_period[rand() % 37], tempo / 4);
		}
	} else if (xb1 >= WIDTH - paddleW - 1) {
		if (!inPaddleBound(yb1, yr1)) {
			scoreL += 1;
			resetObjects();
		} else {
			xb1 = 2 * (WIDTH - paddleW - 1) - xb1;
			vbx *= -1;
			vby += 0.5 * vry;
			//play_note(timer_note_period[rand() % 37], tempo / 4);
		}
	}
	if (yb1 <= 0) {
		yb1 = -yb1;
		vby *= -1;
		//play_note(timer_note_period[rand() % 37], tempo / 4);
	} else if (yb1 >= HEIGHT - 1) {
		yb1 = 2 * (HEIGHT - 1) - yb1;
		vby *= -1;
		//play_note(timer_note_period[rand() % 37], tempo / 4);
	}
}

void updatePaddlePos() {
	xl0 = xl1;
	yl0 = yl1;
	xr0 = xr1;
	yr0 = yr1;
	if (IORD_ALTERA_AVALON_PIO_DATA(JOYSTICK_STICK_1_BASE) & 0x1)
		vry = -paddleSpeed;
	else if (IORD_ALTERA_AVALON_PIO_DATA(JOYSTICK_STICK_1_BASE) & 0x2)
		vry = paddleSpeed;
	else
		vry = 0;
	if (IORD_ALTERA_AVALON_PIO_DATA(JOYSTICK_STICK_2_BASE) & 0x1)
		vly = -paddleSpeed;
	else if (IORD_ALTERA_AVALON_PIO_DATA(JOYSTICK_STICK_2_BASE) & 0x2)
		vly = paddleSpeed;
	else
		vly = 0;
	yl1 += vly;
	if (yl1 < paddleH / 2)
		yl1 = paddleH / 2;
	else if (yl1 > HEIGHT - 1 - paddleH / 2)
		yl1 = HEIGHT - 1 - paddleH / 2;
	yr1 += vry;
	if (yr1 < paddleH / 2)
		yr1 = paddleH / 2;
	else if (yr1 > HEIGHT - 1 - paddleH / 2)
		yr1 = HEIGHT - 1 - paddleH / 2;
}

void draw() {
	updateBallPos();
	updatePaddlePos();
	drawBall();
	drawPaddles();
	IOWR_ALTERA_AVALON_PIO_DATA(HEX_DISPLAYS_BASE, (scoreL << 16) + scoreR);
}

void drawBall() {
	alt_up_pixel_buffer_dma_draw_box(pixel_buffer_dev,
			(int) (xb0 - ballSize / 2), (int) (yb0 - ballSize / 2),
			(int) (xb0 + ballSize / 2), (int) (yb0 + ballSize / 2), COLOR_BLACK,
			0);
	alt_up_pixel_buffer_dma_draw_box(pixel_buffer_dev,
			(int) (xb1 - ballSize / 2), (int) (yb1 - ballSize / 2),
			(int) (xb1 + ballSize / 2), (int) (yb1 + ballSize / 2), COLOR_WHITE,
			0);
}

void drawPaddles() {
	if (yl1 > yl0) {
		alt_up_pixel_buffer_dma_draw_box(pixel_buffer_dev,
				(int) xl0 - paddleW / 2, (int) yl0 - paddleH / 2,
				(int) xl0 + paddleW / 2, (int) yl1 - paddleH / 2, COLOR_BLACK,
				0);
		alt_up_pixel_buffer_dma_draw_box(pixel_buffer_dev,
				(int) xl0 - paddleW / 2, (int) yl0 + paddleH / 2,
				(int) xl0 + paddleW / 2, (int) yl1 + paddleH / 2, COLOR_WHITE,
				0);
	} else {
		alt_up_pixel_buffer_dma_draw_box(pixel_buffer_dev,
				(int) xl0 - paddleW / 2, (int) yl1 + paddleH / 2,
				(int) xl0 + paddleW / 2, (int) yl0 + paddleH / 2, COLOR_BLACK,
				0);
		alt_up_pixel_buffer_dma_draw_box(pixel_buffer_dev,
				(int) xl0 - paddleW / 2, (int) yl1 - paddleH / 2,
				(int) xl0 + paddleW / 2, (int) yl0 - paddleH / 2, COLOR_WHITE,
				0);
	}
	if (yr1 > yr0) {
		alt_up_pixel_buffer_dma_draw_box(pixel_buffer_dev,
				(int) xr0 - paddleW / 2, (int) yr0 - paddleH / 2,
				(int) xr0 + paddleW / 2, (int) yr1 - paddleH / 2, COLOR_BLACK,
				0);
		alt_up_pixel_buffer_dma_draw_box(pixel_buffer_dev,
				(int) xr0 - paddleW / 2, (int) yr0 + paddleH / 2,
				(int) xr0 + paddleW / 2, (int) yr1 + paddleH / 2, COLOR_WHITE,
				0);
	} else {
		alt_up_pixel_buffer_dma_draw_box(pixel_buffer_dev,
				(int) xr0 - paddleW / 2, (int) yr1 + paddleH / 2,
				(int) xr0 + paddleW / 2, (int) yr0 + paddleH / 2, COLOR_BLACK,
				0);
		alt_up_pixel_buffer_dma_draw_box(pixel_buffer_dev,
				(int) xr0 - paddleW / 2, (int) yr1 - paddleH / 2,
				(int) xr0 + paddleW / 2, (int) yr0 - paddleH / 2, COLOR_WHITE,
				0);
	}
}

