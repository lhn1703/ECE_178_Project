#include <stdio.h>
#include <stdlib.h>
#include "system.h"
#include "altera_avalon_pio_regs.h"
#include <sys/alt_irq.h>


int n;
// volatile indicates that this variable may be changed
// by an external program or hardware device
volatile int keys_edge_capture;

static void keys_int_init();
void keys_isr(void* context);
void increment_n();
void decrement_n();

int main() {
    keys_int_init();
    while (1){
        IOWR_ALTERA_AVALON_PIO_DATA(LEDG_BASE, n);
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

    if (*keys_edge_capture_ptr & 0b0100) // extract KEY2
        n = 1;
    else if (*keys_edge_capture_ptr & 0b1000) { // extract KEY3
        int sw_value = IORD_ALTERA_AVALON_PIO_DATA(SWITCHES_BASE);
        if (sw_value == 1)
            increment_n();
        else if (sw_value == 0)
            decrement_n();
    }
    IOWR_ALTERA_AVALON_PIO_EDGE_CAP(KEYS_BASE, 0x00);

    IORD_ALTERA_AVALON_PIO_EDGE_CAP(KEYS_BASE);
    return;
}
void increment_n() {
    n += 2;
    if (n > 9)
        n = 9;
}
void decrement_n() {
    n -= 2;
    if (n < 1)
        n = 1;
}
