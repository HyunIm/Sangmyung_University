library IEEE;

use IEEE.std_logic_1164.all;

entity tb_lab04_1_2 is

end tb_lab04_1_2;

architecture design of tb_lab04_1_2 is
  
    component lab04_1_2 is

      port( A, B, C, En : in std_logic;

            Y0N, Y1N, Y2N, Y3N, Y4N, Y5N, Y6N, Y7N, Si, Cip1 : out std_logic);

    end component;

    

    signal A, B, C, En : std_logic := '0';

    signal Y0N, Y1N, Y2N, Y3N, Y4N, Y5N, Y6N, Y7N, Si, Cip1 : std_logic := '0';

    

begin

   

   U0 : lab04_1_2 port map(A=>A, B=>B, C=>C, En=>En, Y0N=>Y0N, Y1N=>Y1N, Y2N=>Y2N, Y3N=>Y3N, Y4N=>Y4N, Y5N=>Y5N, Y6N=>Y6N, Y7N=>Y7N, Si=>Si, Cip1=>Cip1);

   

   

   process

   begin
	
		En <= '0';
		
		wait for 100ns;

      En <= '1';

      wait for 100ns;
		
	end process;
	
	process

   begin

      C <= '0';

      B <= '0';
		
		A <= '0';

      wait for 10ns;

      C <= '0';

      B <= '0';
		
		A <= '1';

      wait for 10ns;
		
		C <= '0';

      B <= '1';
		
		A <= '0';

      wait for 10ns;
		
		C <= '0';

      B <= '1';
		
		A <= '1';

      wait for 10ns;
		
		C <= '1';

      B <= '0';
		
		A <= '0';

      wait for 10ns;
		
		C <= '1';

      B <= '0';
		
		A <= '1';

      wait for 10ns;
		
		C <= '1';

      B <= '1';
		
		A <= '0';

      wait for 10ns;
		
		C <= '1';

      B <= '1';
		
		A <= '1';

      wait for 10ns;

   end process;  

	
end design; 

