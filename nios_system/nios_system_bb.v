
module nios_system (
	clk_clk,
	hex_displays_export,
	keys_export,
	ledg_export,
	ledr_export,
	reset_reset,
	sdram_clk_clk,
	sdram_controller_wire_addr,
	sdram_controller_wire_ba,
	sdram_controller_wire_cas_n,
	sdram_controller_wire_cke,
	sdram_controller_wire_cs_n,
	sdram_controller_wire_dq,
	sdram_controller_wire_dqm,
	sdram_controller_wire_ras_n,
	sdram_controller_wire_we_n,
	switches_export,
	video_vga_controller_CLK,
	video_vga_controller_HS,
	video_vga_controller_VS,
	video_vga_controller_BLANK,
	video_vga_controller_SYNC,
	video_vga_controller_R,
	video_vga_controller_G,
	video_vga_controller_B);	

	input		clk_clk;
	output	[31:0]	hex_displays_export;
	input	[3:0]	keys_export;
	output	[8:0]	ledg_export;
	output	[17:0]	ledr_export;
	input		reset_reset;
	output		sdram_clk_clk;
	output	[12:0]	sdram_controller_wire_addr;
	output	[1:0]	sdram_controller_wire_ba;
	output		sdram_controller_wire_cas_n;
	output		sdram_controller_wire_cke;
	output		sdram_controller_wire_cs_n;
	inout	[31:0]	sdram_controller_wire_dq;
	output	[3:0]	sdram_controller_wire_dqm;
	output		sdram_controller_wire_ras_n;
	output		sdram_controller_wire_we_n;
	input	[17:0]	switches_export;
	output		video_vga_controller_CLK;
	output		video_vga_controller_HS;
	output		video_vga_controller_VS;
	output		video_vga_controller_BLANK;
	output		video_vga_controller_SYNC;
	output	[7:0]	video_vga_controller_R;
	output	[7:0]	video_vga_controller_G;
	output	[7:0]	video_vga_controller_B;
endmodule
