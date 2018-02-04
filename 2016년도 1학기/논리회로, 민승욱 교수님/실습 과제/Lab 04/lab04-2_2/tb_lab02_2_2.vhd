library IEEE;

use IEEE.std_logic_1164.all;

entity tb_lab04_2_2 is

end tb_lab04_2_2;

architecture design of tb_lab04_2_2 is
  
    component lab04_2_2 is

      port( A, B, C : in std_logic;

            F : out std_logic);

    end component;

    

    signal A, B, C : std_logic := '0';

    signal F : std_logic := '0';

    

begin

   

   U0 : lab04_2_2 port map(A=>A, B=>B, C=>C, F=>F);

   

   

   process

   begin

      A <= '0';

      B <= '0';
		
      C <= '0';

      wait for 10ns;

      A <= '0';

      B <= '0';
		
      C <= '1';

      wait for 10ns;
		
      A <= '0';

      B <= '1';
		
      C <= '0';

      wait for 10ns;
		
      A <= '0';

      B <= '1';
		
      C <= '1';

      wait for 10ns;
		
      A <= '1';

      B <= '0';
		
      C <= '0';

      wait for 10ns;
		
      A <= '1';

      B <= '0';
		
      C <= '1';

      wait for 10ns;
		
      A <= '1';

      B <= '1';
		
      C <= '0';

      wait for 10ns;
		
      A <= '1';

      B <= '1';
		
      C <= '1';

      wait for 10ns;

   end process;

   

end design; 

