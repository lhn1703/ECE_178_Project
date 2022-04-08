	nios_system u0 (
		.clk_clk                     (<connected-to-clk_clk>),                     //                   clk.clk
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
		.ledr_export                 (<connected-to-ledr_export>),                 //                  ledr.export
		.ledg_export                 (<connected-to-ledg_export>),                 //                  ledg.export
		.hex_displays_export         (<connected-to-hex_displays_export>),         //          hex_displays.export
		.keys_export                 (<connected-to-keys_export>),                 //                  keys.export
		.switches_export             (<connected-to-switches_export>)              //              switches.export
	);

