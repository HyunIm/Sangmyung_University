library IEEE;

use IEEE.std_logic_1164.all;

entity tb_lab02_2 is

end tb_lab02_2;

architecture design of tb_lab02_2 is
  
    component lab02_2 is

      port( x, y, z, P1 : in std_logic;

            P, C : out std_logic);

    end component;

    

    signal x, y, z, P1 : std_logic := '0';

    signal P, C : std_logic := '0';

    

begin

   

   U0 : lab02_2 port map(x=>x, y=>y, z=>z, P1=>P1, P=>P, C=>C);

   

   

   process

   begin

      x <= '0';

      y <= '0';
		
		z <= '0';

      P1 <= '0';

      wait for 10ns;
		
      x <= '0';

      y <= '0';
		
		z <= '0';

      P1 <= '1';

      wait for 10ns;
		
      x <= '0';

      y <= '0';
		
		z <= '1';

      P1 <= '0';

      wait for 10ns;
		
      x <= '0';

      y <= '0';
		
		z <= '1';

      P1 <= '1';

      wait for 10ns;
		
      x <= '0';

      y <= '1';
		
		z <= '0';

      P1 <= '0';

      wait for 10ns;
		
      x <= '0';

      y <= '1';
		
		z <= '0';

      P1 <= '1';

      wait for 10ns;
		
      x <= '0';

      y <= '1';
		
		z <= '1';

      P1 <= '0';

      wait for 10ns;
		
      x <= '0';

      y <= '1';
		
		z <= '1';

      P1 <= '1';

      wait for 10ns;
		
      x <= '1';

      y <= '0';
		
		z <= '0';

      P1 <= '0';

      wait for 10ns;
		
      x <= '1';

      y <= '0';
		
		z <= '0';

      P1 <= '1';

      wait for 10ns;
		
      x <= '1';

      y <= '0';
		
		z <= '1';

      P1 <= '0';

      wait for 10ns;
		
      x <= '1';

      y <= '0';
		
		z <= '1';

      P1 <= '1';

      wait for 10ns;
		
      x <= '1';

      y <= '1';
		
		z <= '0';

      P1 <= '0';

      wait for 10ns;
		
      x <= '1';

      y <= '1';
		
		z <= '0';

      P1 <= '1';

      wait for 10ns;
		
      x <= '1';

      y <= '1';
		
		z <= '1';

      P1 <= '0';

      wait for 10ns;
		
      x <= '1';

      y <= '1';
		
		z <= '1';

      P1 <= '1';

      wait for 10ns;

   end process;

   

end design; 

