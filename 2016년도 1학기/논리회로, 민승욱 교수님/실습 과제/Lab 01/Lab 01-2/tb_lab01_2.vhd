library IEEE;

use IEEE.std_logic_1164.all;

entity tb_lab01_2 is

end tb_lab01_2;

architecture design of tb_lab01_2 is
  
    component lab01_2 is

      port( w, x, y, z : in std_logic;

            a, d, f, g : out std_logic);

    end component;

    

    signal w, x, y, z : std_logic := '0';

    signal a, d, f, g : std_logic := '0';

    

begin

   

   U0 : lab01_2 port map(w=>w, x=>x, y=>y, z=>z, a=>a, d=>d, f=>f, g=>g);

   

   

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



   end process;

   

end design; 

