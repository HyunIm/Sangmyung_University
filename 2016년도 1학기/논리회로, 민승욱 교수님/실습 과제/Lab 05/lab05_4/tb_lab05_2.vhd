library IEEE;

use IEEE.std_logic_1164.all;

entity tb_lab05_2 is

end tb_lab05_2;

architecture design of tb_lab05_2 is
  
    component lab05_2 is

      port( J, K, Clk : in std_logic;

            D : out std_logic);

    end component;

    

    signal J, K, Clk : std_logic := '0';

    signal D : std_logic := '0';

    

begin

   

   U0 : lab05_2 port map(J=>J, K=>K, Clk=>Clk, D=>D);

   

   

   process

   begin

      Clk <= '0';
      
      wait for 5ns;
		
		Clk <= '1';
      
      wait for 5ns;

   end process;
	
	
	process

   begin

      J <= '0';
		
		K <= '0';
      
      wait for 13ns;
		
		J <= '0';
		
		K <= '1';
      
      wait for 13ns;
		
		J <= '1';
		
		K <= '0';
      
      wait for 13ns;
		
		J <= '1';
		
		K <= '1';
      
      wait for 13ns;		

   end process;

   

end design; 

