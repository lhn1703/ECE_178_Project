// simple decoder unit for a hex display
module hex_decoder (output [6:0] hex_output, input [3:0] bin_digit);
    reg [6:0] invertedHex;
    assign hex_output = ~invertedHex; //FPGA hex LEDs are enable LOW

    always @ (*) begin 
        case(bin_digit) 
            0:invertedHex = 7'h3F;
            1:invertedHex = 7'h06;
            2:invertedHex = 7'h5B;
            3:invertedHex = 7'h4F;
            4:invertedHex = 7'h66;
            5:invertedHex = 7'h6D;
            6:invertedHex = 7'h7D;
            7:invertedHex = 7'h07;
            8:invertedHex = 7'h7F;
            9:invertedHex = 7'h67;
            10:invertedHex = 7'h77;
            11:invertedHex = 7'h7C;
            12:invertedHex = 7'h39;
            13:invertedHex = 7'h5E;
            14:invertedHex = 7'h79;
            15:invertedHex = 7'h71;
        endcase
end 
endmodule

module ECE_178_Project_nios (
    input CLOCK_50,
    output [6:0] HEX0, HEX1, HEX2, HEX3, HEX4, HEX5, HEX6, HEX7,
    input [3:0] KEY,
    output [8:0] LEDG,
    output [17:0] LEDR,
	inout [4:0] GPIO,
    output [12:0] DRAM_ADDR,
    output [1:0] DRAM_BA,
    output DRAM_CAS_N, DRAM_CKE, DRAM_CS_N, DRAM_CLK,
    inout [31:0] DRAM_DQ,
    output [3:0] DRAM_DQM,
    output DRAM_RAS_N, DRAM_WE_N,
	inout [15:0] SRAM_DQ,     //  sram_controller_wire.DQ
	output [19:0] SRAM_ADDR,   //                      .ADDR
	output SRAM_LB_N,   //                      .LB_N
	output SRAM_UB_N,   //                      .UB_N
	output SRAM_CE_N,   //                      .CE_N
	output SRAM_OE_N,   //                      .OE_N
	output SRAM_WE_N,   // 
    input [17:0] SW,
	output VGA_CLK,
	output VGA_HS,
	output VGA_VS,
	output VGA_BLANK,
	output VGA_SYNC,
	output [7:0] VGA_R,
	output [7:0] VGA_G,
	output [7:0] VGA_B,
	inout SD_CMD,
	output SD_CLK,
	inout [3:0] SD_DAT,
	input UART_RXD,
	output UART_TXD
    );

    wire [31:0] hex_display_32;
    hex_decoder digit0 (HEX0, hex_display_32[3:0]);
    hex_decoder digit1 (HEX1, hex_display_32[7:4]);
    hex_decoder digit2 (HEX2, hex_display_32[11:8]);
    hex_decoder digit3 (HEX3, hex_display_32[15:12]);
    hex_decoder digit4 (HEX4, hex_display_32[19:16]);
    hex_decoder digit5 (HEX5, hex_display_32[23:20]);
    hex_decoder digit6 (HEX6, hex_display_32[27:24]);
    hex_decoder digit7 (HEX7, hex_display_32[31:28]);

    //assign DRAM_CLK = CLOCK_50;
    wire reset_wire;
    assign reset_wire = 1'b1;

    nios_system nios2 (
        .clk_clk(CLOCK_50),
        .hex_displays_export(hex_display_32),
		.joystick_stick_1_export(GPIO[1:0]),     //      joystick_stick_1.export
		.joystick_stick_2_export(GPIO[3:2]),     //      joystick_stick_2.export
        .keys_export(~KEY), //pushbuttons are logic LOW when pressed
        .ledg_export(LEDG),
        .ledr_export(LEDR),
		.piezo_pwm_export(GPIO[4]),
        .switches_export(SW),
        .reset_reset(reset_wire),
		.rs232_RXD(UART_RXD),
		.rs232_TXD(UART_TXD),
        .sdram_clk_clk(DRAM_CLK),
        .sdram_controller_wire_addr(DRAM_ADDR),
        .sdram_controller_wire_ba(DRAM_BA),
        .sdram_controller_wire_cas_n(DRAM_CAS_N),
        .sdram_controller_wire_cke(DRAM_CKE),
        .sdram_controller_wire_cs_n(DRAM_CS_N),
        .sdram_controller_wire_dq(DRAM_DQ),
        .sdram_controller_wire_dqm(DRAM_DQM),
        .sdram_controller_wire_ras_n(DRAM_RAS_N),
        .sdram_controller_wire_we_n(DRAM_WE_N),
		.sd_card_b_SD_cmd(SD_CMD),
		.sd_card_b_SD_dat(SD_DAT[0]),
		.sd_card_b_SD_dat3(SD_DAT[3]),
		.sd_card_o_SD_clock(SD_CLK),
		.sram_controller_wire_DQ(SRAM_DQ),
		.sram_controller_wire_ADDR(SRAM_ADDR),
		.sram_controller_wire_LB_N(SRAM_LB_N),
		.sram_controller_wire_UB_N(SRAM_UB_N),
		.sram_controller_wire_CE_N(SRAM_CE_N),
		.sram_controller_wire_OE_N(SRAM_OE_N),
		.sram_controller_wire_WE_N(SRAM_WE_N),
		.video_vga_controller_CLK(VGA_CLK),
		.video_vga_controller_HS(VGA_HS),
		.video_vga_controller_VS(VGA_VS),
		.video_vga_controller_BLANK(VGA_BLANK),
		.video_vga_controller_SYNC(VGA_SYNC),
		.video_vga_controller_R(VGA_R),
		.video_vga_controller_G(VGA_G),
		.video_vga_controller_B(VGA_B)
        );
endmodule