library IEEE;

use IEEE.std_logic_1164.all;

entity tb_lab03_1 is

end tb_lab03_1;

architecture design of tb_lab03_1 is
  
    component lab03_1 is

      port( A1, A0, B1, B0 : in std_logic;

            C2, S1, S0 : out std_logic);

    end component;

    

    signal A1, A0, B1, B0 : std_logic := '0';

    signal C2, S1, S0 : std_logic := '0';

    

begin

   

   U0 : lab03_1 port map(A1=>A1, A0=>A0, B1=>B1, B0=>B0, C2=>C2, S1=>S1, S0=>S0);

   

   

   process

   begin

      A1 <= '0';

      A0 <= '0';
		
		B1 <= '0';

      B0 <= '0';

      wait for 10ns;
		
		A1 <= '0';

      A0 <= '0';
		
		B1 <= '0';

      B0 <= '1';

      wait for 10ns;
		
		A1 <= '0';

      A0 <= '0';
		
		B1 <= '1';

      B0 <= '0';

      wait for 10ns;
		
		A1 <= '0';

      A0 <= '0';
		
		B1 <= '1';

      B0 <= '1';

      wait for 10ns;
		
		A1 <= '0';

      A0 <= '1';
		
		B1 <= '0';

      B0 <= '0';

      wait for 10ns;
		
		A1 <= '0';

      A0 <= '1';
		
		B1 <= '0';

      B0 <= '1';

      wait for 10ns;
		
		A1 <= '0';

      A0 <= '1';
		
		B1 <= '1';

      B0 <= '0';

      wait for 10ns;
		
		A1 <= '0';

      A0 <= '1';
		
		B1 <= '1';

      B0 <= '1';

      wait for 10ns;
		
		A1 <= '1';

      A0 <= '0';
		
		B1 <= '0';

      B0 <= '0';

      wait for 10ns;
		
		A1 <= '1';

      A0 <= '0';
		
		B1 <= '0';

      B0 <= '1';

      wait for 10ns;
		
		A1 <= '1';

      A0 <= '0';
		
		B1 <= '1';

      B0 <= '0';

      wait for 10ns;
		
		A1 <= '1';

      A0 <= '0';
		
		B1 <= '1';

      B0 <= '1';

      wait for 10ns;
		
		A1 <= '1';

      A0 <= '1';
		
		B1 <= '0';

      B0 <= '0';

      wait for 10ns;
		
		A1 <= '1';

      A0 <= '1';
		
		B1 <= '0';

      B0 <= '1';

      wait for 10ns;
		
		A1 <= '1';
		
      A0 <= '1';
		
		B1 <= '1';

      B0 <= '0';

      wait for 10ns;
		
		A1 <= '1';

      A0 <= '1';
		
		B1 <= '1';

      B0 <= '1';

      wait for 10ns;

   end process;

   

end design; 

