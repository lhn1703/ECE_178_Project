	component nios_system is
		port (
			clk_clk                     : in    std_logic                     := 'X';             -- clk
			hex_displays_export         : out   std_logic_vector(31 downto 0);                    -- export
			keys_export                 : in    std_logic_vector(3 downto 0)  := (others => 'X'); -- export
			ledg_export                 : out   std_logic_vector(8 downto 0);                     -- export
			ledr_export                 : out   std_logic_vector(17 downto 0);                    -- export
			reset_reset                 : in    std_logic                     := 'X';             -- reset
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
			switches_export             : in    std_logic_vector(17 downto 0) := (others => 'X'); -- export
			video_vga_controller_CLK    : out   std_logic;                                        -- CLK
			video_vga_controller_HS     : out   std_logic;                                        -- HS
			video_vga_controller_VS     : out   std_logic;                                        -- VS
			video_vga_controller_BLANK  : out   std_logic;                                        -- BLANK
			video_vga_controller_SYNC   : out   std_logic;                                        -- SYNC
			video_vga_controller_R      : out   std_logic_vector(7 downto 0);                     -- R
			video_vga_controller_G      : out   std_logic_vector(7 downto 0);                     -- G
			video_vga_controller_B      : out   std_logic_vector(7 downto 0)                      -- B
		);
	end component nios_system;

	u0 : component nios_system
		port map (
			clk_clk                     => CONNECTED_TO_clk_clk,                     --                   clk.clk
			hex_displays_export         => CONNECTED_TO_hex_displays_export,         --          hex_displays.export
			keys_export                 => CONNECTED_TO_keys_export,                 --                  keys.export
			ledg_export                 => CONNECTED_TO_ledg_export,                 --                  ledg.export
			ledr_export                 => CONNECTED_TO_ledr_export,                 --                  ledr.export
			reset_reset                 => CONNECTED_TO_reset_reset,                 --                 reset.reset
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
			switches_export             => CONNECTED_TO_switches_export,             --              switches.export
			video_vga_controller_CLK    => CONNECTED_TO_video_vga_controller_CLK,    --  video_vga_controller.CLK
			video_vga_controller_HS     => CONNECTED_TO_video_vga_controller_HS,     --                      .HS
			video_vga_controller_VS     => CONNECTED_TO_video_vga_controller_VS,     --                      .VS
			video_vga_controller_BLANK  => CONNECTED_TO_video_vga_controller_BLANK,  --                      .BLANK
			video_vga_controller_SYNC   => CONNECTED_TO_video_vga_controller_SYNC,   --                      .SYNC
			video_vga_controller_R      => CONNECTED_TO_video_vga_controller_R,      --                      .R
			video_vga_controller_G      => CONNECTED_TO_video_vga_controller_G,      --                      .G
			video_vga_controller_B      => CONNECTED_TO_video_vga_controller_B       --                      .B
		);

