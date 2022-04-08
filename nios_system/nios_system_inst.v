	nios_system u0 (
		.clk_clk                     (<connected-to-clk_clk>),                     //                   clk.clk
		.hex_displays_export         (<connected-to-hex_displays_export>),         //          hex_displays.export
		.keys_export                 (<connected-to-keys_export>),                 //                  keys.export
		.ledg_export                 (<connected-to-ledg_export>),                 //                  ledg.export
		.ledr_export                 (<connected-to-ledr_export>),                 //                  ledr.export
		.reset_reset                 (<connected-to-reset_reset>),                 //                 reset.reset
		.sdram_clk_clk               (<connected-to-sdram_clk_clk>),               //             sdram_clk.clk
		.sdram_controller_wire_addr  (<connected-to-sdram_controller_wire_addr>),  // sdram_controller_wire.addr
		.sdram_controller_wire_ba    (<connected-to-sdram_controller_wire_ba>),    //                      .ba
		.sdram_controller_wire_cas_n (<connected-to-sdram_controller_wire_cas_n>), //                      .cas_n
		.sdram_controller_wire_cke   (<connected-to-sdram_controller_wire_cke>),   //                      .cke
		.sdram_controller_wire_cs_n  (<connected-to-sdram_controller_wire_cs_n>),  //                      .cs_n
		.sdram_controller_wire_dq    (<connected-to-sdram_controller_wire_dq>),    //                      .dq
		.sdram_controller_wire_dqm   (<connected-to-sdram_controller_wire_dqm>),   //                      .dqm
		.sdram_controller_wire_ras_n (<connected-to-sdram_controller_wire_ras_n>), //                      .ras_n
		.sdram_controller_wire_we_n  (<connected-to-sdram_controller_wire_we_n>),  //                      .we_n
		.switches_export             (<connected-to-switches_export>),             //              switches.export
		.video_vga_controller_CLK    (<connected-to-video_vga_controller_CLK>),    //  video_vga_controller.CLK
		.video_vga_controller_HS     (<connected-to-video_vga_controller_HS>),     //                      .HS
		.video_vga_controller_VS     (<connected-to-video_vga_controller_VS>),     //                      .VS
		.video_vga_controller_BLANK  (<connected-to-video_vga_controller_BLANK>),  //                      .BLANK
		.video_vga_controller_SYNC   (<connected-to-video_vga_controller_SYNC>),   //                      .SYNC
		.video_vga_controller_R      (<connected-to-video_vga_controller_R>),      //                      .R
		.video_vga_controller_G      (<connected-to-video_vga_controller_G>),      //                      .G
		.video_vga_controller_B      (<connected-to-video_vga_controller_B>)       //                      .B
	);

