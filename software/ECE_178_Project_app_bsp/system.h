/*
 * system.h - SOPC Builder system and BSP software package information
 *
 * Machine generated for CPU 'nios2_qsys' in SOPC Builder design 'nios_system'
 * SOPC Builder design path: ../../nios_system.sopcinfo
 *
 * Generated: Mon May 02 13:01:42 PDT 2022
 */

/*
 * DO NOT MODIFY THIS FILE
 *
 * Changing this file will have subtle consequences
 * which will almost certainly lead to a nonfunctioning
 * system. If you do modify this file, be aware that your
 * changes will be overwritten and lost when this file
 * is generated again.
 *
 * DO NOT MODIFY THIS FILE
 */

/*
 * License Agreement
 *
 * Copyright (c) 2008
 * Altera Corporation, San Jose, California, USA.
 * All rights reserved.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 *
 * This agreement shall be governed in all respects by the laws of the State
 * of California and by the laws of the United States of America.
 */

#ifndef __SYSTEM_H_
#define __SYSTEM_H_

/* Include definitions from linker script generator */
#include "linker.h"


/*
 * CPU configuration
 *
 */

#define ALT_CPU_ARCHITECTURE "altera_nios2_qsys"
#define ALT_CPU_BIG_ENDIAN 0
#define ALT_CPU_BREAK_ADDR 0x08200820
#define ALT_CPU_CPU_FREQ 50000000u
#define ALT_CPU_CPU_ID_SIZE 1
#define ALT_CPU_CPU_ID_VALUE 0x00000000
#define ALT_CPU_CPU_IMPLEMENTATION "fast"
#define ALT_CPU_DATA_ADDR_WIDTH 0x1c
#define ALT_CPU_DCACHE_LINE_SIZE 32
#define ALT_CPU_DCACHE_LINE_SIZE_LOG2 5
#define ALT_CPU_DCACHE_SIZE 2048
#define ALT_CPU_EXCEPTION_ADDR 0x00000020
#define ALT_CPU_FLUSHDA_SUPPORTED
#define ALT_CPU_FREQ 50000000
#define ALT_CPU_HARDWARE_DIVIDE_PRESENT 1
#define ALT_CPU_HARDWARE_MULTIPLY_PRESENT 1
#define ALT_CPU_HARDWARE_MULX_PRESENT 0
#define ALT_CPU_HAS_DEBUG_CORE 1
#define ALT_CPU_HAS_DEBUG_STUB
#define ALT_CPU_HAS_JMPI_INSTRUCTION
#define ALT_CPU_ICACHE_LINE_SIZE 32
#define ALT_CPU_ICACHE_LINE_SIZE_LOG2 5
#define ALT_CPU_ICACHE_SIZE 4096
#define ALT_CPU_INITDA_SUPPORTED
#define ALT_CPU_INST_ADDR_WIDTH 0x1c
#define ALT_CPU_NAME "nios2_qsys"
#define ALT_CPU_NUM_OF_SHADOW_REG_SETS 0
#define ALT_CPU_RESET_ADDR 0x00000000


/*
 * CPU configuration (with legacy prefix - don't use these anymore)
 *
 */

#define NIOS2_BIG_ENDIAN 0
#define NIOS2_BREAK_ADDR 0x08200820
#define NIOS2_CPU_FREQ 50000000u
#define NIOS2_CPU_ID_SIZE 1
#define NIOS2_CPU_ID_VALUE 0x00000000
#define NIOS2_CPU_IMPLEMENTATION "fast"
#define NIOS2_DATA_ADDR_WIDTH 0x1c
#define NIOS2_DCACHE_LINE_SIZE 32
#define NIOS2_DCACHE_LINE_SIZE_LOG2 5
#define NIOS2_DCACHE_SIZE 2048
#define NIOS2_EXCEPTION_ADDR 0x00000020
#define NIOS2_FLUSHDA_SUPPORTED
#define NIOS2_HARDWARE_DIVIDE_PRESENT 1
#define NIOS2_HARDWARE_MULTIPLY_PRESENT 1
#define NIOS2_HARDWARE_MULX_PRESENT 0
#define NIOS2_HAS_DEBUG_CORE 1
#define NIOS2_HAS_DEBUG_STUB
#define NIOS2_HAS_JMPI_INSTRUCTION
#define NIOS2_ICACHE_LINE_SIZE 32
#define NIOS2_ICACHE_LINE_SIZE_LOG2 5
#define NIOS2_ICACHE_SIZE 4096
#define NIOS2_INITDA_SUPPORTED
#define NIOS2_INST_ADDR_WIDTH 0x1c
#define NIOS2_NUM_OF_SHADOW_REG_SETS 0
#define NIOS2_RESET_ADDR 0x00000000


/*
 * Define for each module class mastered by the CPU
 *
 */

#define __ALTERA_AVALON_JTAG_UART
#define __ALTERA_AVALON_NEW_SDRAM_CONTROLLER
#define __ALTERA_AVALON_PIO
#define __ALTERA_AVALON_TIMER
#define __ALTERA_NIOS2_QSYS
#define __ALTERA_UP_AVALON_RS232
#define __ALTERA_UP_AVALON_SRAM
#define __ALTERA_UP_AVALON_VIDEO_PIXEL_BUFFER_DMA
#define __ALTERA_UP_AVALON_VIDEO_RGB_RESAMPLER
#define __ALTERA_UP_SD_CARD_AVALON_INTERFACE


/*
 * System configuration
 *
 */

#define ALT_DEVICE_FAMILY "Cyclone IV E"
#define ALT_IRQ_BASE NULL
#define ALT_LEGACY_INTERRUPT_API_PRESENT
#define ALT_LOG_PORT "/dev/null"
#define ALT_LOG_PORT_BASE 0x0
#define ALT_LOG_PORT_DEV null
#define ALT_LOG_PORT_TYPE ""
#define ALT_NUM_EXTERNAL_INTERRUPT_CONTROLLERS 0
#define ALT_NUM_INTERNAL_INTERRUPT_CONTROLLERS 1
#define ALT_NUM_INTERRUPT_CONTROLLERS 1
#define ALT_STDERR "/dev/jtag_uart"
#define ALT_STDERR_BASE 0x8201558
#define ALT_STDERR_DEV jtag_uart
#define ALT_STDERR_IS_JTAG_UART
#define ALT_STDERR_PRESENT
#define ALT_STDERR_TYPE "altera_avalon_jtag_uart"
#define ALT_STDIN "/dev/jtag_uart"
#define ALT_STDIN_BASE 0x8201558
#define ALT_STDIN_DEV jtag_uart
#define ALT_STDIN_IS_JTAG_UART
#define ALT_STDIN_PRESENT
#define ALT_STDIN_TYPE "altera_avalon_jtag_uart"
#define ALT_STDOUT "/dev/jtag_uart"
#define ALT_STDOUT_BASE 0x8201558
#define ALT_STDOUT_DEV jtag_uart
#define ALT_STDOUT_IS_JTAG_UART
#define ALT_STDOUT_PRESENT
#define ALT_STDOUT_TYPE "altera_avalon_jtag_uart"
#define ALT_SYSTEM_NAME "nios_system"


/*
 * hal configuration
 *
 */

#define ALT_MAX_FD 32
#define ALT_SYS_CLK TIMER_0
#define ALT_TIMESTAMP_CLK TIMER_0


/*
 * hex_displays configuration
 *
 */

#define ALT_MODULE_CLASS_hex_displays altera_avalon_pio
#define HEX_DISPLAYS_BASE 0x8201510
#define HEX_DISPLAYS_BIT_CLEARING_EDGE_REGISTER 0
#define HEX_DISPLAYS_BIT_MODIFYING_OUTPUT_REGISTER 0
#define HEX_DISPLAYS_CAPTURE 0
#define HEX_DISPLAYS_DATA_WIDTH 32
#define HEX_DISPLAYS_DO_TEST_BENCH_WIRING 0
#define HEX_DISPLAYS_DRIVEN_SIM_VALUE 0
#define HEX_DISPLAYS_EDGE_TYPE "NONE"
#define HEX_DISPLAYS_FREQ 50000000
#define HEX_DISPLAYS_HAS_IN 0
#define HEX_DISPLAYS_HAS_OUT 1
#define HEX_DISPLAYS_HAS_TRI 0
#define HEX_DISPLAYS_IRQ -1
#define HEX_DISPLAYS_IRQ_INTERRUPT_CONTROLLER_ID -1
#define HEX_DISPLAYS_IRQ_TYPE "NONE"
#define HEX_DISPLAYS_NAME "/dev/hex_displays"
#define HEX_DISPLAYS_RESET_VALUE 0
#define HEX_DISPLAYS_SPAN 16
#define HEX_DISPLAYS_TYPE "altera_avalon_pio"


/*
 * joystick_stick_1 configuration
 *
 */

#define ALT_MODULE_CLASS_joystick_stick_1 altera_avalon_pio
#define JOYSTICK_STICK_1_BASE 0x82014e0
#define JOYSTICK_STICK_1_BIT_CLEARING_EDGE_REGISTER 0
#define JOYSTICK_STICK_1_BIT_MODIFYING_OUTPUT_REGISTER 0
#define JOYSTICK_STICK_1_CAPTURE 0
#define JOYSTICK_STICK_1_DATA_WIDTH 5
#define JOYSTICK_STICK_1_DO_TEST_BENCH_WIRING 0
#define JOYSTICK_STICK_1_DRIVEN_SIM_VALUE 0
#define JOYSTICK_STICK_1_EDGE_TYPE "NONE"
#define JOYSTICK_STICK_1_FREQ 50000000
#define JOYSTICK_STICK_1_HAS_IN 1
#define JOYSTICK_STICK_1_HAS_OUT 0
#define JOYSTICK_STICK_1_HAS_TRI 0
#define JOYSTICK_STICK_1_IRQ -1
#define JOYSTICK_STICK_1_IRQ_INTERRUPT_CONTROLLER_ID -1
#define JOYSTICK_STICK_1_IRQ_TYPE "NONE"
#define JOYSTICK_STICK_1_NAME "/dev/joystick_stick_1"
#define JOYSTICK_STICK_1_RESET_VALUE 0
#define JOYSTICK_STICK_1_SPAN 16
#define JOYSTICK_STICK_1_TYPE "altera_avalon_pio"


/*
 * joystick_stick_2 configuration
 *
 */

#define ALT_MODULE_CLASS_joystick_stick_2 altera_avalon_pio
#define JOYSTICK_STICK_2_BASE 0x82014d0
#define JOYSTICK_STICK_2_BIT_CLEARING_EDGE_REGISTER 0
#define JOYSTICK_STICK_2_BIT_MODIFYING_OUTPUT_REGISTER 0
#define JOYSTICK_STICK_2_CAPTURE 0
#define JOYSTICK_STICK_2_DATA_WIDTH 5
#define JOYSTICK_STICK_2_DO_TEST_BENCH_WIRING 0
#define JOYSTICK_STICK_2_DRIVEN_SIM_VALUE 0
#define JOYSTICK_STICK_2_EDGE_TYPE "NONE"
#define JOYSTICK_STICK_2_FREQ 50000000
#define JOYSTICK_STICK_2_HAS_IN 1
#define JOYSTICK_STICK_2_HAS_OUT 0
#define JOYSTICK_STICK_2_HAS_TRI 0
#define JOYSTICK_STICK_2_IRQ -1
#define JOYSTICK_STICK_2_IRQ_INTERRUPT_CONTROLLER_ID -1
#define JOYSTICK_STICK_2_IRQ_TYPE "NONE"
#define JOYSTICK_STICK_2_NAME "/dev/joystick_stick_2"
#define JOYSTICK_STICK_2_RESET_VALUE 0
#define JOYSTICK_STICK_2_SPAN 16
#define JOYSTICK_STICK_2_TYPE "altera_avalon_pio"


/*
 * jtag_uart configuration
 *
 */

#define ALT_MODULE_CLASS_jtag_uart altera_avalon_jtag_uart
#define JTAG_UART_BASE 0x8201558
#define JTAG_UART_IRQ 0
#define JTAG_UART_IRQ_INTERRUPT_CONTROLLER_ID 0
#define JTAG_UART_NAME "/dev/jtag_uart"
#define JTAG_UART_READ_DEPTH 64
#define JTAG_UART_READ_THRESHOLD 8
#define JTAG_UART_SPAN 8
#define JTAG_UART_TYPE "altera_avalon_jtag_uart"
#define JTAG_UART_WRITE_DEPTH 64
#define JTAG_UART_WRITE_THRESHOLD 8


/*
 * keys configuration
 *
 */

#define ALT_MODULE_CLASS_keys altera_avalon_pio
#define KEYS_BASE 0x8201500
#define KEYS_BIT_CLEARING_EDGE_REGISTER 0
#define KEYS_BIT_MODIFYING_OUTPUT_REGISTER 0
#define KEYS_CAPTURE 1
#define KEYS_DATA_WIDTH 4
#define KEYS_DO_TEST_BENCH_WIRING 0
#define KEYS_DRIVEN_SIM_VALUE 0
#define KEYS_EDGE_TYPE "FALLING"
#define KEYS_FREQ 50000000
#define KEYS_HAS_IN 1
#define KEYS_HAS_OUT 0
#define KEYS_HAS_TRI 0
#define KEYS_IRQ 1
#define KEYS_IRQ_INTERRUPT_CONTROLLER_ID 0
#define KEYS_IRQ_TYPE "EDGE"
#define KEYS_NAME "/dev/keys"
#define KEYS_RESET_VALUE 0
#define KEYS_SPAN 16
#define KEYS_TYPE "altera_avalon_pio"


/*
 * ledg configuration
 *
 */

#define ALT_MODULE_CLASS_ledg altera_avalon_pio
#define LEDG_BASE 0x8201520
#define LEDG_BIT_CLEARING_EDGE_REGISTER 0
#define LEDG_BIT_MODIFYING_OUTPUT_REGISTER 0
#define LEDG_CAPTURE 0
#define LEDG_DATA_WIDTH 9
#define LEDG_DO_TEST_BENCH_WIRING 0
#define LEDG_DRIVEN_SIM_VALUE 0
#define LEDG_EDGE_TYPE "NONE"
#define LEDG_FREQ 50000000
#define LEDG_HAS_IN 0
#define LEDG_HAS_OUT 1
#define LEDG_HAS_TRI 0
#define LEDG_IRQ -1
#define LEDG_IRQ_INTERRUPT_CONTROLLER_ID -1
#define LEDG_IRQ_TYPE "NONE"
#define LEDG_NAME "/dev/ledg"
#define LEDG_RESET_VALUE 0
#define LEDG_SPAN 16
#define LEDG_TYPE "altera_avalon_pio"


/*
 * ledr configuration
 *
 */

#define ALT_MODULE_CLASS_ledr altera_avalon_pio
#define LEDR_BASE 0x8201530
#define LEDR_BIT_CLEARING_EDGE_REGISTER 0
#define LEDR_BIT_MODIFYING_OUTPUT_REGISTER 0
#define LEDR_CAPTURE 0
#define LEDR_DATA_WIDTH 18
#define LEDR_DO_TEST_BENCH_WIRING 0
#define LEDR_DRIVEN_SIM_VALUE 0
#define LEDR_EDGE_TYPE "NONE"
#define LEDR_FREQ 50000000
#define LEDR_HAS_IN 0
#define LEDR_HAS_OUT 1
#define LEDR_HAS_TRI 0
#define LEDR_IRQ -1
#define LEDR_IRQ_INTERRUPT_CONTROLLER_ID -1
#define LEDR_IRQ_TYPE "NONE"
#define LEDR_NAME "/dev/ledr"
#define LEDR_RESET_VALUE 0
#define LEDR_SPAN 16
#define LEDR_TYPE "altera_avalon_pio"


/*
 * piezo_pwm configuration
 *
 */

#define ALT_MODULE_CLASS_piezo_pwm altera_avalon_pio
#define PIEZO_PWM_BASE 0x82014c0
#define PIEZO_PWM_BIT_CLEARING_EDGE_REGISTER 0
#define PIEZO_PWM_BIT_MODIFYING_OUTPUT_REGISTER 0
#define PIEZO_PWM_CAPTURE 0
#define PIEZO_PWM_DATA_WIDTH 1
#define PIEZO_PWM_DO_TEST_BENCH_WIRING 0
#define PIEZO_PWM_DRIVEN_SIM_VALUE 0
#define PIEZO_PWM_EDGE_TYPE "NONE"
#define PIEZO_PWM_FREQ 50000000
#define PIEZO_PWM_HAS_IN 0
#define PIEZO_PWM_HAS_OUT 1
#define PIEZO_PWM_HAS_TRI 0
#define PIEZO_PWM_IRQ -1
#define PIEZO_PWM_IRQ_INTERRUPT_CONTROLLER_ID -1
#define PIEZO_PWM_IRQ_TYPE "NONE"
#define PIEZO_PWM_NAME "/dev/piezo_pwm"
#define PIEZO_PWM_RESET_VALUE 0
#define PIEZO_PWM_SPAN 16
#define PIEZO_PWM_TYPE "altera_avalon_pio"


/*
 * pixel_buffer configuration
 *
 */

#define ALT_MODULE_CLASS_pixel_buffer altera_up_avalon_sram
#define PIXEL_BUFFER_BASE 0x8000000
#define PIXEL_BUFFER_IRQ -1
#define PIXEL_BUFFER_IRQ_INTERRUPT_CONTROLLER_ID -1
#define PIXEL_BUFFER_NAME "/dev/pixel_buffer"
#define PIXEL_BUFFER_SPAN 2097152
#define PIXEL_BUFFER_TYPE "altera_up_avalon_sram"


/*
 * pixel_buffer_dma configuration
 *
 */

#define ALT_MODULE_CLASS_pixel_buffer_dma altera_up_avalon_video_pixel_buffer_dma
#define PIXEL_BUFFER_DMA_BASE 0x8201540
#define PIXEL_BUFFER_DMA_IRQ -1
#define PIXEL_BUFFER_DMA_IRQ_INTERRUPT_CONTROLLER_ID -1
#define PIXEL_BUFFER_DMA_NAME "/dev/pixel_buffer_dma"
#define PIXEL_BUFFER_DMA_SPAN 16
#define PIXEL_BUFFER_DMA_TYPE "altera_up_avalon_video_pixel_buffer_dma"


/*
 * pixel_rgb_resampler configuration
 *
 */

#define ALT_MODULE_CLASS_pixel_rgb_resampler altera_up_avalon_video_rgb_resampler
#define PIXEL_RGB_RESAMPLER_BASE 0x8201560
#define PIXEL_RGB_RESAMPLER_IRQ -1
#define PIXEL_RGB_RESAMPLER_IRQ_INTERRUPT_CONTROLLER_ID -1
#define PIXEL_RGB_RESAMPLER_NAME "/dev/pixel_rgb_resampler"
#define PIXEL_RGB_RESAMPLER_SPAN 4
#define PIXEL_RGB_RESAMPLER_TYPE "altera_up_avalon_video_rgb_resampler"


/*
 * rs232 configuration
 *
 */

#define ALT_MODULE_CLASS_rs232 altera_up_avalon_rs232
#define RS232_BASE 0x8201550
#define RS232_IRQ 9
#define RS232_IRQ_INTERRUPT_CONTROLLER_ID 0
#define RS232_NAME "/dev/rs232"
#define RS232_SPAN 8
#define RS232_TYPE "altera_up_avalon_rs232"


/*
 * sd_card configuration
 *
 */

#define ALT_MODULE_CLASS_sd_card Altera_UP_SD_Card_Avalon_Interface
#define SD_CARD_BASE 0x8201000
#define SD_CARD_IRQ -1
#define SD_CARD_IRQ_INTERRUPT_CONTROLLER_ID -1
#define SD_CARD_NAME "/dev/sd_card"
#define SD_CARD_SPAN 1024
#define SD_CARD_TYPE "Altera_UP_SD_Card_Avalon_Interface"


/*
 * sdram_controller configuration
 *
 */

#define ALT_MODULE_CLASS_sdram_controller altera_avalon_new_sdram_controller
#define SDRAM_CONTROLLER_BASE 0x0
#define SDRAM_CONTROLLER_CAS_LATENCY 3
#define SDRAM_CONTROLLER_CONTENTS_INFO
#define SDRAM_CONTROLLER_INIT_NOP_DELAY 0.0
#define SDRAM_CONTROLLER_INIT_REFRESH_COMMANDS 2
#define SDRAM_CONTROLLER_IRQ -1
#define SDRAM_CONTROLLER_IRQ_INTERRUPT_CONTROLLER_ID -1
#define SDRAM_CONTROLLER_IS_INITIALIZED 1
#define SDRAM_CONTROLLER_NAME "/dev/sdram_controller"
#define SDRAM_CONTROLLER_POWERUP_DELAY 100.0
#define SDRAM_CONTROLLER_REFRESH_PERIOD 7.8125
#define SDRAM_CONTROLLER_REGISTER_DATA_IN 1
#define SDRAM_CONTROLLER_SDRAM_ADDR_WIDTH 0x19
#define SDRAM_CONTROLLER_SDRAM_BANK_WIDTH 2
#define SDRAM_CONTROLLER_SDRAM_COL_WIDTH 10
#define SDRAM_CONTROLLER_SDRAM_DATA_WIDTH 32
#define SDRAM_CONTROLLER_SDRAM_NUM_BANKS 4
#define SDRAM_CONTROLLER_SDRAM_NUM_CHIPSELECTS 1
#define SDRAM_CONTROLLER_SDRAM_ROW_WIDTH 13
#define SDRAM_CONTROLLER_SHARED_DATA 0
#define SDRAM_CONTROLLER_SIM_MODEL_BASE 0
#define SDRAM_CONTROLLER_SPAN 134217728
#define SDRAM_CONTROLLER_STARVATION_INDICATOR 0
#define SDRAM_CONTROLLER_TRISTATE_BRIDGE_SLAVE ""
#define SDRAM_CONTROLLER_TYPE "altera_avalon_new_sdram_controller"
#define SDRAM_CONTROLLER_T_AC 5.4
#define SDRAM_CONTROLLER_T_MRD 3
#define SDRAM_CONTROLLER_T_RCD 15.0
#define SDRAM_CONTROLLER_T_RFC 70.0
#define SDRAM_CONTROLLER_T_RP 15.0
#define SDRAM_CONTROLLER_T_WR 14.0


/*
 * switches configuration
 *
 */

#define ALT_MODULE_CLASS_switches altera_avalon_pio
#define SWITCHES_BASE 0x82014f0
#define SWITCHES_BIT_CLEARING_EDGE_REGISTER 0
#define SWITCHES_BIT_MODIFYING_OUTPUT_REGISTER 0
#define SWITCHES_CAPTURE 1
#define SWITCHES_DATA_WIDTH 18
#define SWITCHES_DO_TEST_BENCH_WIRING 0
#define SWITCHES_DRIVEN_SIM_VALUE 0
#define SWITCHES_EDGE_TYPE "FALLING"
#define SWITCHES_FREQ 50000000
#define SWITCHES_HAS_IN 1
#define SWITCHES_HAS_OUT 0
#define SWITCHES_HAS_TRI 0
#define SWITCHES_IRQ 2
#define SWITCHES_IRQ_INTERRUPT_CONTROLLER_ID 0
#define SWITCHES_IRQ_TYPE "EDGE"
#define SWITCHES_NAME "/dev/switches"
#define SWITCHES_RESET_VALUE 0
#define SWITCHES_SPAN 16
#define SWITCHES_TYPE "altera_avalon_pio"


/*
 * timer_0 configuration
 *
 */

#define ALT_MODULE_CLASS_timer_0 altera_avalon_timer
#define TIMER_0_ALWAYS_RUN 0
#define TIMER_0_BASE 0x82014a0
#define TIMER_0_COUNTER_SIZE 32
#define TIMER_0_FIXED_PERIOD 0
#define TIMER_0_FREQ 50000000
#define TIMER_0_IRQ 3
#define TIMER_0_IRQ_INTERRUPT_CONTROLLER_ID 0
#define TIMER_0_LOAD_VALUE 49999
#define TIMER_0_MULT 0.001
#define TIMER_0_NAME "/dev/timer_0"
#define TIMER_0_PERIOD 1
#define TIMER_0_PERIOD_UNITS "ms"
#define TIMER_0_RESET_OUTPUT 0
#define TIMER_0_SNAPSHOT 1
#define TIMER_0_SPAN 32
#define TIMER_0_TICKS_PER_SEC 1000
#define TIMER_0_TIMEOUT_PULSE_OUTPUT 0
#define TIMER_0_TYPE "altera_avalon_timer"


/*
 * timer_1 configuration
 *
 */

#define ALT_MODULE_CLASS_timer_1 altera_avalon_timer
#define TIMER_1_ALWAYS_RUN 0
#define TIMER_1_BASE 0x8201480
#define TIMER_1_COUNTER_SIZE 32
#define TIMER_1_FIXED_PERIOD 0
#define TIMER_1_FREQ 50000000
#define TIMER_1_IRQ 4
#define TIMER_1_IRQ_INTERRUPT_CONTROLLER_ID 0
#define TIMER_1_LOAD_VALUE 49999
#define TIMER_1_MULT 0.001
#define TIMER_1_NAME "/dev/timer_1"
#define TIMER_1_PERIOD 1
#define TIMER_1_PERIOD_UNITS "ms"
#define TIMER_1_RESET_OUTPUT 0
#define TIMER_1_SNAPSHOT 1
#define TIMER_1_SPAN 32
#define TIMER_1_TICKS_PER_SEC 1000
#define TIMER_1_TIMEOUT_PULSE_OUTPUT 0
#define TIMER_1_TYPE "altera_avalon_timer"


/*
 * timer_2 configuration
 *
 */

#define ALT_MODULE_CLASS_timer_2 altera_avalon_timer
#define TIMER_2_ALWAYS_RUN 0
#define TIMER_2_BASE 0x8201460
#define TIMER_2_COUNTER_SIZE 32
#define TIMER_2_FIXED_PERIOD 0
#define TIMER_2_FREQ 50000000
#define TIMER_2_IRQ 5
#define TIMER_2_IRQ_INTERRUPT_CONTROLLER_ID 0
#define TIMER_2_LOAD_VALUE 49999
#define TIMER_2_MULT 0.001
#define TIMER_2_NAME "/dev/timer_2"
#define TIMER_2_PERIOD 1
#define TIMER_2_PERIOD_UNITS "ms"
#define TIMER_2_RESET_OUTPUT 0
#define TIMER_2_SNAPSHOT 1
#define TIMER_2_SPAN 32
#define TIMER_2_TICKS_PER_SEC 1000
#define TIMER_2_TIMEOUT_PULSE_OUTPUT 0
#define TIMER_2_TYPE "altera_avalon_timer"


/*
 * timer_3 configuration
 *
 */

#define ALT_MODULE_CLASS_timer_3 altera_avalon_timer
#define TIMER_3_ALWAYS_RUN 0
#define TIMER_3_BASE 0x8201440
#define TIMER_3_COUNTER_SIZE 32
#define TIMER_3_FIXED_PERIOD 0
#define TIMER_3_FREQ 50000000
#define TIMER_3_IRQ 6
#define TIMER_3_IRQ_INTERRUPT_CONTROLLER_ID 0
#define TIMER_3_LOAD_VALUE 49999
#define TIMER_3_MULT 0.001
#define TIMER_3_NAME "/dev/timer_3"
#define TIMER_3_PERIOD 1
#define TIMER_3_PERIOD_UNITS "ms"
#define TIMER_3_RESET_OUTPUT 0
#define TIMER_3_SNAPSHOT 1
#define TIMER_3_SPAN 32
#define TIMER_3_TICKS_PER_SEC 1000
#define TIMER_3_TIMEOUT_PULSE_OUTPUT 0
#define TIMER_3_TYPE "altera_avalon_timer"


/*
 * timer_4 configuration
 *
 */

#define ALT_MODULE_CLASS_timer_4 altera_avalon_timer
#define TIMER_4_ALWAYS_RUN 0
#define TIMER_4_BASE 0x8201420
#define TIMER_4_COUNTER_SIZE 32
#define TIMER_4_FIXED_PERIOD 0
#define TIMER_4_FREQ 50000000
#define TIMER_4_IRQ 7
#define TIMER_4_IRQ_INTERRUPT_CONTROLLER_ID 0
#define TIMER_4_LOAD_VALUE 49999
#define TIMER_4_MULT 0.001
#define TIMER_4_NAME "/dev/timer_4"
#define TIMER_4_PERIOD 1
#define TIMER_4_PERIOD_UNITS "ms"
#define TIMER_4_RESET_OUTPUT 0
#define TIMER_4_SNAPSHOT 1
#define TIMER_4_SPAN 32
#define TIMER_4_TICKS_PER_SEC 1000
#define TIMER_4_TIMEOUT_PULSE_OUTPUT 0
#define TIMER_4_TYPE "altera_avalon_timer"


/*
 * timer_5 configuration
 *
 */

#define ALT_MODULE_CLASS_timer_5 altera_avalon_timer
#define TIMER_5_ALWAYS_RUN 0
#define TIMER_5_BASE 0x8201400
#define TIMER_5_COUNTER_SIZE 32
#define TIMER_5_FIXED_PERIOD 0
#define TIMER_5_FREQ 50000000
#define TIMER_5_IRQ 8
#define TIMER_5_IRQ_INTERRUPT_CONTROLLER_ID 0
#define TIMER_5_LOAD_VALUE 49999
#define TIMER_5_MULT 0.001
#define TIMER_5_NAME "/dev/timer_5"
#define TIMER_5_PERIOD 1
#define TIMER_5_PERIOD_UNITS "ms"
#define TIMER_5_RESET_OUTPUT 0
#define TIMER_5_SNAPSHOT 1
#define TIMER_5_SPAN 32
#define TIMER_5_TICKS_PER_SEC 1000
#define TIMER_5_TIMEOUT_PULSE_OUTPUT 0
#define TIMER_5_TYPE "altera_avalon_timer"

#endif /* __SYSTEM_H_ */
