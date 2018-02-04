library IEEE;

use IEEE.std_logic_1164.all;

entity tb_lab06_1 is

end tb_lab06_1;

architecture design of tb_lab06_1 is
  
    component lab06_1 is

      port( w, Clk : in std_logic;

            z : out std_logic);

    end component;

    

    signal w, Clk : std_logic := '0';

    signal z : std_logic := '0';

    

begin

   

   U0 : lab06_1 port map(w=>w, Clk=>Clk, z=>z);

   

   

   process

   begin

      Clk <= '0';

      wait for 5ns;

      Clk <= '1';

      wait for 5ns;
		
	end process;
		
	process

	begin

      w <= '0';

      wait for 13ns;
		
		w <= '1';

      wait for 9ns;
		
		w <= '0';

      wait for 53ns;
		
		w <= '1';

      wait for 23ns;
		
		w <= '0';

      wait for 7ns;
		
		w <= '1';

      wait for 17ns;
		
		w <= '0';

      wait for 13ns;
		
		w <= '1';

      wait for 65ns;

   end process;

end design; 

