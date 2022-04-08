
module nios_system (
	clk_clk,
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
	ledr_export,
	ledg_export,
	hex_displays_export,
	keys_export,
	switches_export);	

	input		clk_clk;
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
	output	[17:0]	ledr_export;
	output	[8:0]	ledg_export;
	output	[31:0]	hex_displays_export;
	input	[3:0]	keys_export;
	input	[17:0]	switches_export;
endmodule
