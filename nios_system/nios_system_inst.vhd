	component nios_system is
		port (
			clk_clk                     : in    std_logic                     := 'X';             -- clk
			hex_displays_export         : out   std_logic_vector(31 downto 0);                    -- export
			joystick_stick_1_export     : in    std_logic_vector(4 downto 0)  := (others => 'X'); -- export
			joystick_stick_2_export     : in    std_logic_vector(4 downto 0)  := (others => 'X'); -- export
			keys_export                 : in    std_logic_vector(3 downto 0)  := (others => 'X'); -- export
			ledg_export                 : out   std_logic_vector(8 downto 0);                     -- export
			ledr_export                 : out   std_logic_vector(17 downto 0);                    -- export
			piezo_pwm_export            : out   std_logic;                                        -- export
			reset_reset                 : in    std_logic                     := 'X';             -- reset
			sd_card_b_SD_cmd            : inout std_logic                     := 'X';             -- b_SD_cmd
			sd_card_b_SD_dat            : inout std_logic                     := 'X';             -- b_SD_dat
			sd_card_b_SD_dat3           : inout std_logic                     := 'X';             -- b_SD_dat3
			sd_card_o_SD_clock          : out   std_logic;                                        -- o_SD_clock
			sdram_clk_clk               : out   std_logic;                                        -- clk
			sdram_controller_wire_addr  : out   std_logic_vector(12 downto 0);                    -- addr
			sdram_controller_wire_ba    : out   std_logic_vector(1 downto 0);                     -- ba
			sdram_controller_wire_cas_n : out   std_logic;                                        -- cas_n
			sdram_controller_wire_cke   : out   std_logic;                                        -- cke
			sdram_controller_wire_cs_n  : out   std_logic;                                        -- cs_n
			sdram_controller_wire_dq    : inout std_logic_vector(31 downto 0) := (others => 'X'); -- dq
			sdram_controller_wire_dqm   : out   std_logic_vector(3 downto 0);                     -- dqm
			sdram_controller_wire_ras_n : out   std_logic;                                        -- ras_n
			sdram_controller_wire_we_n  : out   std_logic;                                        -- we_n
			sram_controller_wire_DQ     : inout std_logic_vector(15 downto 0) := (others => 'X'); -- DQ
			sram_controller_wire_ADDR   : out   std_logic_vector(19 downto 0);                    -- ADDR
			sram_controller_wire_LB_N   : out   std_logic;                                        -- LB_N
			sram_controller_wire_UB_N   : out   std_logic;                                        -- UB_N
			sram_controller_wire_CE_N   : out   std_logic;                                        -- CE_N
			sram_controller_wire_OE_N   : out   std_logic;                                        -- OE_N
			sram_controller_wire_WE_N   : out   std_logic;                                        -- WE_N
			switches_export             : in    std_logic_vector(17 downto 0) := (others => 'X'); -- export
			video_vga_controller_CLK    : out   std_logic;                                        -- CLK
			video_vga_controller_HS     : out   std_logic;                                        -- HS
			video_vga_controller_VS     : out   std_logic;                                        -- VS
			video_vga_controller_BLANK  : out   std_logic;                                        -- BLANK
			video_vga_controller_SYNC   : out   std_logic;                                        -- SYNC
			video_vga_controller_R      : out   std_logic_vector(7 downto 0);                     -- R
			video_vga_controller_G      : out   std_logic_vector(7 downto 0);                     -- G
			video_vga_controller_B      : out   std_logic_vector(7 downto 0);                     -- B
			rs232_RXD                   : in    std_logic                     := 'X';             -- RXD
			rs232_TXD                   : out   std_logic                                         -- TXD
		);
	end component nios_system;

	u0 : component nios_system
		port map (
			clk_clk                     => CONNECTED_TO_clk_clk,                     --                   clk.clk
			hex_displays_export         => CONNECTED_TO_hex_displays_export,         --          hex_displays.export
			joystick_stick_1_export     => CONNECTED_TO_joystick_stick_1_export,     --      joystick_stick_1.export
			joystick_stick_2_export     => CONNECTED_TO_joystick_stick_2_export,     --      joystick_stick_2.export
			keys_export                 => CONNECTED_TO_keys_export,                 --                  keys.export
			ledg_export                 => CONNECTED_TO_ledg_export,                 --                  ledg.export
			ledr_export                 => CONNECTED_TO_ledr_export,                 --                  ledr.export
			piezo_pwm_export            => CONNECTED_TO_piezo_pwm_export,            --             piezo_pwm.export
			reset_reset                 => CONNECTED_TO_reset_reset,                 --                 reset.reset
			sd_card_b_SD_cmd            => CONNECTED_TO_sd_card_b_SD_cmd,            --               sd_card.b_SD_cmd
			sd_card_b_SD_dat            => CONNECTED_TO_sd_card_b_SD_dat,            --                      .b_SD_dat
			sd_card_b_SD_dat3           => CONNECTED_TO_sd_card_b_SD_dat3,           --                      .b_SD_dat3
			sd_card_o_SD_clock          => CONNECTED_TO_sd_card_o_SD_clock,          --                      .o_SD_clock
			sdram_clk_clk               => CONNECTED_TO_sdram_clk_clk,               --             sdram_clk.clk
			sdram_controller_wire_addr  => CONNECTED_TO_sdram_controller_wire_addr,  -- sdram_controller_wire.addr
			sdram_controller_wire_ba    => CONNECTED_TO_sdram_controller_wire_ba,    --                      .ba
			sdram_controller_wire_cas_n => CONNECTED_TO_sdram_controller_wire_cas_n, --                      .cas_n
			sdram_controller_wire_cke   => CONNECTED_TO_sdram_controller_wire_cke,   --                      .cke
			sdram_controller_wire_cs_n  => CONNECTED_TO_sdram_controller_wire_cs_n,  --                      .cs_n
			sdram_controller_wire_dq    => CONNECTED_TO_sdram_controller_wire_dq,    --                      .dq
			sdram_controller_wire_dqm   => CONNECTED_TO_sdram_controller_wire_dqm,   --                      .dqm
			sdram_controller_wire_ras_n => CONNECTED_TO_sdram_controller_wire_ras_n, --                      .ras_n
			sdram_controller_wire_we_n  => CONNECTED_TO_sdram_controller_wire_we_n,  --                      .we_n
			sram_controller_wire_DQ     => CONNECTED_TO_sram_controller_wire_DQ,     --  sram_controller_wire.DQ
			sram_controller_wire_ADDR   => CONNECTED_TO_sram_controller_wire_ADDR,   --                      .ADDR
			sram_controller_wire_LB_N   => CONNECTED_TO_sram_controller_wire_LB_N,   --                      .LB_N
			sram_controller_wire_UB_N   => CONNECTED_TO_sram_controller_wire_UB_N,   --                      .UB_N
			sram_controller_wire_CE_N   => CONNECTED_TO_sram_controller_wire_CE_N,   --                      .CE_N
			sram_controller_wire_OE_N   => CONNECTED_TO_sram_controller_wire_OE_N,   --                      .OE_N
			sram_controller_wire_WE_N   => CONNECTED_TO_sram_controller_wire_WE_N,   --                      .WE_N
			switches_export             => CONNECTED_TO_switches_export,             --              switches.export
			video_vga_controller_CLK    => CONNECTED_TO_video_vga_controller_CLK,    --  video_vga_controller.CLK
			video_vga_controller_HS     => CONNECTED_TO_video_vga_controller_HS,     --                      .HS
			video_vga_controller_VS     => CONNECTED_TO_video_vga_controller_VS,     --                      .VS
			video_vga_controller_BLANK  => CONNECTED_TO_video_vga_controller_BLANK,  --                      .BLANK
			video_vga_controller_SYNC   => CONNECTED_TO_video_vga_controller_SYNC,   --                      .SYNC
			video_vga_controller_R      => CONNECTED_TO_video_vga_controller_R,      --                      .R
			video_vga_controller_G      => CONNECTED_TO_video_vga_controller_G,      --                      .G
			video_vga_controller_B      => CONNECTED_TO_video_vga_controller_B,      --                      .B
			rs232_RXD                   => CONNECTED_TO_rs232_RXD,                   --                 rs232.RXD
			rs232_TXD                   => CONNECTED_TO_rs232_TXD                    --                      .TXD
		);

