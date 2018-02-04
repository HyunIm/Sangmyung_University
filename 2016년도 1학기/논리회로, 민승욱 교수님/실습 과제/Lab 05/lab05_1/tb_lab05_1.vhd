library IEEE;

use IEEE.std_logic_1164.all;

entity tb_lab05_1 is

end tb_lab05_1;

architecture design of tb_lab05_1 is
  
    component lab05_1 is

      port( D, Clk : in std_logic;

            Q, QN : out std_logic);

    end component;

    

    signal D, Clk : std_logic := '0';

    signal Q, QN : std_logic := '0';

    

begin

   

   U0 : lab05_1 port map(D=>D, Clk=>Clk, Q=>Q, QN=>QN);

   

   

   process

   begin

      Clk <= '0';
      
      wait for 5ns;
		
		Clk <= '1';
      
      wait for 5ns;

   end process;
	
	
	process

   begin

      D <= '0';
      
      wait for 13ns;
		
		D <= '1';
      
      wait for 13ns;

   end process;

   

end design; 

