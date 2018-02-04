library IEEE;

use IEEE.std_logic_1164.all;

entity tb_and_2 is

end tb_and_2;

architecture design of tb_and_2 is
  
    component and_2 is

      port( X, Y : in std_logic;

            A : out std_logic);

    end component;

    

    signal X, Y : std_logic := '0';

    signal A : std_logic := '0';

    

begin

   

   U0 : and_2 port map(X=>X, Y=>Y, A=>A);

   

   

   process

   begin

      X <= '0';

      Y <= '0';

      wait for 10ns;

      X <= '0';

      Y <= '1';

      wait for 10ns;

      X <= '1';

      Y <= '0';

      wait for 10ns;

      X <= '1';

      Y <= '1';

      wait for 10ns;

   end process;

   

end design; 

