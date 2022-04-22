#include <io.h>
#include <system.h>
#include <stdbool.h>

#include <altera_up_avalon_video_pixel_buffer_dma.h>
#include <altera_avalon_pio_regs.h>
#include <altera_avalon_timer_regs.h>
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


static void timer_0_init();
void timer_isr();

bool inPaddleBound(float y, float yp);
void resetObjects();
void updateBallPos();
void updatePaddlePos();
void drawBall();
void drawPaddles();
void draw();

alt_up_pixel_buffer_dma_dev *pixel_buffer;

int main() {
	pixel_buffer = alt_up_pixel_buffer_dma_open_dev("/dev/pixel_buffer_dma");
	alt_up_pixel_buffer_dma_clear_screen(pixel_buffer, 0);
	alt_up_pixel_buffer_dma_clear_screen(pixel_buffer, 1);
	xl1 = paddleW/2;
	yl1 = HEIGHT/2;
	xr1 = WIDTH-(paddleW/2);
	yr1 = HEIGHT/2;
	timer_0_init(1000/60);
	resetObjects();
	while(1)
	{
	}
//
	return 0;
}

static void timer_0_init(int period_arg) {
	// stop the timer first
	IOWR_ALTERA_AVALON_TIMER_CONTROL(TIMER_0_BASE, 0x8);

	// set the period to 1000 ms, TIMER_LOAD_VALUE is scalar for 1ms in the native clk freq
	int period = period_arg * TIMER_0_LOAD_VALUE;
	int periodlo = period & 0xffff;
	int periodhi = period >> 16;
	IOWR_ALTERA_AVALON_TIMER_PERIODL(TIMER_0_BASE, periodlo);
	IOWR_ALTERA_AVALON_TIMER_PERIODH(TIMER_0_BASE, periodhi);

	//enable ITO, CONT, and START bits
	IOWR_ALTERA_AVALON_TIMER_CONTROL(TIMER_0_BASE, 0b111);

	// timer interrupt handler
	alt_ic_isr_register(TIMER_0_IRQ_INTERRUPT_CONTROLLER_ID, TIMER_0_IRQ,
							timer_isr, NULL, NULL);
}
void timer_isr() {
	// clear the TO bit
	IOWR_ALTERA_AVALON_TIMER_STATUS(TIMER_0_BASE, 0);

	draw();

	// dummy instruction to synchronize
	IORD_ALTERA_AVALON_TIMER_STATUS(TIMER_0_BASE);
	return;
}

bool inPaddleBound(float y, float yp)
{
	return (y >= (yp-paddleH/2)) && (y <= (yp+paddleH/2));
}

void resetObjects()
{
	alt_up_pixel_buffer_dma_draw_box(pixel_buffer, 0, 0, WIDTH-1, HEIGHT-1, COLOR_BLACK, 0);
	xb1 = WIDTH/2;
	yb1 = HEIGHT/2;
	vbx = 2;
	vby = 0.3;
	vlx = 0;
	vly = 0;
	vrx = 0;
	vry = 0;
	alt_up_pixel_buffer_dma_draw_box(pixel_buffer, (int) xl1-paddleW/2, (int) yl1-paddleH/2, (int) xl1+paddleW/2, (int) yl1+paddleH/2, COLOR_WHITE, 0);
	alt_up_pixel_buffer_dma_draw_box(pixel_buffer, (int) xr1-paddleW/2, (int) yr1-paddleH/2, (int) xr1+paddleW/2, (int) yr1+paddleH/2, COLOR_WHITE, 0);
}

void updateBallPos()
{
	xb0 = xb1;
	yb0 = yb1;
	xb1 += vbx;
	yb1 += vby;
	if (xb1 <= paddleW)
	{
		if (!inPaddleBound(yb1, yl1))
		{
			scoreR += 1;
			resetObjects();
		}
		else
		{
			xb1 = 2*(paddleW) - xb1;
			vbx *= -1;
		}
	} else if (xb1 >= WIDTH-paddleW-1)
	{
		if (!inPaddleBound(yb1, yr1))
		{
			scoreL += 1;
			resetObjects();
		}
		else
		{
			xb1 = 2*(WIDTH-paddleW-1) - xb1;
			vbx *= -1;
		}
	}
	if (yb1 <= 0)
	{
		yb1 = -yb1;
		vby *= -1;
	} else if (yb1 >= HEIGHT-1)
	{
		yb1 = 2*(HEIGHT-1) - yb1;
		vby *= -1;
	}
}

void updatePaddlePos()
{
	xl0 = xl1;
	yl0 = yl1;
	xr0 = xr1;
	yr0 = yr1;
	if (IORD_ALTERA_AVALON_PIO_DATA(SWITCHES_BASE) & 0x1)
		vry = paddleSpeed;
	else if (IORD_ALTERA_AVALON_PIO_DATA(SWITCHES_BASE) & 0x2)
		vry = -paddleSpeed;
	else
		vry = 0;
	if (IORD_ALTERA_AVALON_PIO_DATA(SWITCHES_BASE) & (0x1 << 16))
		vly = paddleSpeed;
	else if (IORD_ALTERA_AVALON_PIO_DATA(SWITCHES_BASE) & (0x2 << 16))
		vly = -paddleSpeed;
	else
		vly = 0;
	yl1 += vly;
	if (yl1 < paddleH/2) yl1 = paddleH/2;
	else if (yl1 > HEIGHT-1-paddleH/2) yl1 = HEIGHT-1-paddleH/2;
	yr1 += vry;
	if (yr1 < paddleH/2) yr1 = paddleH/2;
	else if (yr1 > HEIGHT-1-paddleH/2) yr1 = HEIGHT-1-paddleH/2;
}

void draw()
{
	updateBallPos();
	updatePaddlePos();
	drawBall();
	drawPaddles();
	IOWR_ALTERA_AVALON_PIO_DATA(HEX_DISPLAYS_BASE, (scoreL << 16) + scoreR);
}

void drawBall()
{
	alt_up_pixel_buffer_dma_draw_box(pixel_buffer, (int) (xb0-ballSize/2), (int) (yb0-ballSize/2), (int) (xb0+ballSize/2), (int) (yb0+ballSize/2), COLOR_BLACK, 0);
	alt_up_pixel_buffer_dma_draw_box(pixel_buffer, (int) (xb1-ballSize/2), (int) (yb1-ballSize/2), (int) (xb1+ballSize/2), (int) (yb1+ballSize/2), COLOR_WHITE, 0);
}

void drawPaddles()
{
	if (yl1 > yl0)
	{
		alt_up_pixel_buffer_dma_draw_box(pixel_buffer, (int) xl0-paddleW/2, (int) yl0-paddleH/2, (int) xl0+paddleW/2, (int) yl1-paddleH/2, COLOR_BLACK, 0);
		alt_up_pixel_buffer_dma_draw_box(pixel_buffer, (int) xl0-paddleW/2, (int) yl0+paddleH/2, (int) xl0+paddleW/2, (int) yl1+paddleH/2, COLOR_WHITE, 0);
	}
	else
	{
		alt_up_pixel_buffer_dma_draw_box(pixel_buffer, (int) xl0-paddleW/2, (int) yl1+paddleH/2, (int) xl0+paddleW/2, (int) yl0+paddleH/2, COLOR_BLACK, 0);
		alt_up_pixel_buffer_dma_draw_box(pixel_buffer, (int) xl0-paddleW/2, (int) yl1-paddleH/2, (int) xl0+paddleW/2, (int) yl0-paddleH/2, COLOR_WHITE, 0);
	}
	if (yr1 > yr0)
	{
		alt_up_pixel_buffer_dma_draw_box(pixel_buffer, (int) xr0-paddleW/2, (int) yr0-paddleH/2, (int) xr0+paddleW/2, (int) yr1-paddleH/2, COLOR_BLACK, 0);
		alt_up_pixel_buffer_dma_draw_box(pixel_buffer, (int) xr0-paddleW/2, (int) yr0+paddleH/2, (int) xr0+paddleW/2, (int) yr1+paddleH/2, COLOR_WHITE, 0);
	}
	else
	{
		alt_up_pixel_buffer_dma_draw_box(pixel_buffer, (int) xr0-paddleW/2, (int) yr1+paddleH/2, (int) xr0+paddleW/2, (int) yr0+paddleH/2, COLOR_BLACK, 0);
		alt_up_pixel_buffer_dma_draw_box(pixel_buffer, (int) xr0-paddleW/2, (int) yr1-paddleH/2, (int) xr0+paddleW/2, (int) yr0-paddleH/2, COLOR_WHITE, 0);
	}
}
