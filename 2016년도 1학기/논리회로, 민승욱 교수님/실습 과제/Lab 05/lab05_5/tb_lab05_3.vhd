library IEEE;

use IEEE.std_logic_1164.all;

entity tb_lab05_3 is

end tb_lab05_3;

architecture design of tb_lab05_3 is
  
    component lab05_3 is

      port( T, Clk : in std_logic;

            Q : out std_logic);

    end component;

    

    signal T, Clk : std_logic := '0';

    signal Q : std_logic := '0';

    

begin

   

   U0 : lab05_3 port map(T=>T, Clk=>Clk, Q=>Q);

   

   

   process

   begin

      Clk <= '0';
      
      wait for 5ns;
		
		Clk <= '1';
      
      wait for 5ns;

   end process;
	
	
	process

   begin

      T <= '0';
      
      wait for 13ns;
		
		T <= '1';
      
      wait for 13ns;

   end process;

   

end design; 

