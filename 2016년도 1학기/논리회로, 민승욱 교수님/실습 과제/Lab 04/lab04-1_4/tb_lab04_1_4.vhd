library IEEE;

use IEEE.std_logic_1164.all;

entity tb_lab04_1_4 is

end tb_lab04_1_4;

architecture design of tb_lab04_1_4 is
  
    component lab04_1_4 is

      port( w0, w1, w2, w3, En : in std_logic;

            y0, y1, y2, y3, y4, y5, y6, y7, y8, y9, y10, y11, y12, y13, y14, y15 : out std_logic);

    end component;

    

    signal w0, w1, w2, w3, En : std_logic := '0';

    signal y0, y1, y2, y3, y4, y5, y6, y7, y8, y9, y10, y11, y12, y13, y14, y15 : std_logic := '0';

    

begin

   

   U0 : lab04_1_4 port map(w0=>w0, w1=>w1, w2=>w2, w3=>w3, En=>En, y0=>y0, y1=>y1, y2=>y2, y3=>y3, y4=>y4, y5=>y5, y6=>y6, y7=>y7, y8=>y8, y9=>y9, y10=>y10, y11=>y11, y12=>y12, y13=>y13, y14=>y14, y15=>y15);

   

   

   process

   begin
	
		En <= '0';

      wait for 160ns;
		
		En <= '1';

      wait for 160ns;
		
	end process;
	
	process

   begin

      w0 <= '0';

      w1 <= '0';
		
		w2 <= '0';

      w3 <= '0';

      wait for 10ns;

      w0 <= '0';

      w1 <= '0';
		
		w2 <= '0';

      w3 <= '1';

      wait for 10ns;
		
      w0 <= '0';

      w1 <= '0';
		
		w2 <= '1';

      w3 <= '0';

      wait for 10ns;
		
      w0 <= '0';

      w1 <= '0';
		
		w2 <= '1';

      w3 <= '1';

      wait for 10ns;
		
      w0 <= '0';

      w1 <= '1';
		
		w2 <= '0';

      w3 <= '0';

      wait for 10ns;
		
      w0 <= '0';

      w1 <= '1';
		
		w2 <= '0';

      w3 <= '1';

      wait for 10ns;
		
      w0 <= '0';

      w1 <= '1';
		
		w2 <= '1';

      w3 <= '0';

      wait for 10ns;
		
      w0 <= '0';
		
      w1 <= '1';
		
		w2 <= '1';

      w3 <= '1';

      wait for 10ns;
		
      w0 <= '1';

      w1 <= '0';
		
		w2 <= '0';

      w3 <= '0';

      wait for 10ns;
		
      w0 <= '1';

      w1 <= '0';
		
		w2 <= '0';

      w3 <= '1';

      wait for 10ns;
		
      w0 <= '1';

      w1 <= '0';
		
		w2 <= '1';

      w3 <= '0';

      wait for 10ns;
		
      w0 <= '1';

      w1 <= '0';
		
		w2 <= '1';

      w3 <= '1';

      wait for 10ns;
		
      w0 <= '1';

      w1 <= '1';
		
		w2 <= '0';

      w3 <= '0';

      wait for 10ns;
		
      w0 <= '1';

      w1 <= '1';
		
		w2 <= '0';

      w3 <= '1';

      wait for 10ns;
		
      w0 <= '1';

      w1 <= '1';
		
		w2 <= '1';

      w3 <= '0';

      wait for 10ns;
				
      w0 <= '1';

      w1 <= '1';
		
		w2 <= '1';

      w3 <= '1';

      wait for 10ns;

   end process;

   

end design; 

