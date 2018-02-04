library IEEE;

use IEEE.std_logic_1164.all;

entity tb_lab02_1 is

end tb_lab02_1;

architecture design of tb_lab02_1 is
  
    component lab02_1 is

      port( w, x, y, z : in std_logic;

            f_NOR, f_NAND : out std_logic);

    end component;

    

    signal w, x, y, z : std_logic := '0';

    signal f_NOR, f_NAND : std_logic := '0';

    

begin

   

   U0 : lab02_1 port map(w=>w, x=>x, y=>y, z=>z, f_NOR=>f_NOR, f_NAND=>f_NAND);

   

   

   process

   begin

      w <= '0';

      x <= '0';
		
		y <= '0';

      z <= '0';

      wait for 10ns;

      w <= '0';

      x <= '0';
		
		y <= '0';

      z <= '1';

      wait for 10ns;

      w <= '0';

      x <= '0';
		
		y <= '1';

      z <= '0';

      wait for 10ns;

      w <= '0';

      x <= '0';
		
		y <= '1';

      z <= '1';

      wait for 10ns;

      w <= '0';

      x <= '1';
		
		y <= '0';

      z <= '0';

      wait for 10ns;

      w <= '0';

      x <= '1';
		
		y <= '0';

      z <= '1';

      wait for 10ns;

      w <= '0';

      x <= '1';
		
		y <= '1';

      z <= '0';

      wait for 10ns;

      w <= '0';

      x <= '1';
		
		y <= '1';

      z <= '1';

      wait for 10ns;

      w <= '1';

      x <= '0';
		
		y <= '0';

      z <= '0';

      wait for 10ns;

      w <= '1';

      x <= '0';
		
		y <= '0';

      z <= '1';

      wait for 10ns;

      w <= '1';

      x <= '0';
		
		y <= '1';

      z <= '0';
		
      wait for 10ns;

      w <= '1';

      x <= '0';
		
		y <= '1';

      z <= '1';

      wait for 10ns;

      w <= '1';

      x <= '1';
		
		y <= '0';

      z <= '0';

      wait for 10ns;

      w <= '1';

      x <= '1';
		
		y <= '0';

      z <= '1';
	
      wait for 10ns;

      w <= '1';

      x <= '1';
		
		y <= '1';

      z <= '0';

      wait for 10ns;

      w <= '1';

      x <= '1';
		
		y <= '1';

      z <= '1';

      wait for 10ns;

   end process;

   

end design; 

