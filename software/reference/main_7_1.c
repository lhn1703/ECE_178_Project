#include <stdio.h>
#include <stdlib.h>
#include "system.h"
#include "altera_avalon_pio_regs.h"
#include "altera_avalon_timer_regs.h"
#include <sys/alt_irq.h>

int n = 0;
int direction = 1;

// volatile indicates that this variable may be changed
// by an external program or hardware device
volatile int keys_edge_capture;

static void keys_int_init();
static void timer_int_init();
void keys_isr(void* context);
void timer_isr();

void toggle_timer();
void cycle_n();
void cycle_bit();

int main() {
    keys_int_init();
    timer_int_init();
    while (1){
        IOWR_ALTERA_AVALON_PIO_DATA(HEX_DISPLAYS_BASE, n);
    }
    return 0;
}

static void keys_int_init() {
    void* keys_edge_capture_ptr = (void*) &keys_edge_capture;
    // Enable all three keys as interrupt
    IOWR_ALTERA_AVALON_PIO_IRQ_MASK(KEYS_BASE, 0x0F);
    // Reset edge capture register
    IOWR_ALTERA_AVALON_PIO_EDGE_CAP(KEYS_BASE, 0x00);
    // Register ISR and place it on the interrupt table
    alt_ic_isr_register(KEYS_IRQ_INTERRUPT_CONTROLLER_ID, KEYS_IRQ,
            keys_isr, keys_edge_capture_ptr, 0x00);
}
void keys_isr(void* context) {
    // Recast context to keys_edge_capture type
    volatile int* keys_edge_capture_ptr = (volatile int*) context;
    // Read the edge capture to determine what triggered the interrupt
    *keys_edge_capture_ptr = IORD_ALTERA_AVALON_PIO_EDGE_CAP(KEYS_BASE);

    toggle_timer();

    IOWR_ALTERA_AVALON_PIO_EDGE_CAP(KEYS_BASE, 0x00);

    IORD_ALTERA_AVALON_PIO_EDGE_CAP(KEYS_BASE);
    return;
}
static void timer_int_init() {
    // stop the timer first
    IOWR_ALTERA_AVALON_TIMER_CONTROL(TIMER_0_BASE, 0x8);

    // set the period to 1000 ms, TIMER_LOAD_VALUE is scalar for 1ms in the native clk freq
    int period = 1000 * TIMER_0_LOAD_VALUE;
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

    cycle_n();

    // dummy instruction to synchronize
    IORD_ALTERA_AVALON_TIMER_STATUS(TIMER_0_BASE);
    return;
}

void toggle_timer() {
    int is_running = IORD_ALTERA_AVALON_TIMER_STATUS(TIMER_0_BASE) & 0b10;
    if (is_running) // stop the timer
        IOWR_ALTERA_AVALON_TIMER_CONTROL(TIMER_0_BASE, 0b1000);
    else // enable START, CONT, and ITO
        IOWR_ALTERA_AVALON_TIMER_CONTROL(TIMER_0_BASE, 0b111);
}

void cycle_n() {
    if (n == 0)
        direction = 1;
    else if (n == 0xf)
        direction = 0;

    if (direction)
        n++;
    else
        n--;
}
