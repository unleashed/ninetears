inherit "/std/outside.c";
 void setup()
{
set_short("%^BOLD%^%^CYAN%^ Acueducto %^RESET%^");
set_long("%^BOLD%^%^CYAN%^Acueducto %^RESET%^\n\n Te encuentras"
    " ante una gran obra arquitectonica , utilizada para transportar el agua  "
    " hacia los numerosos cultivos que hay por esta zona .\n\n");
          
add_exit("sudoeste","/d/adiel/room/cultivos/room/acueducto3.c","road");
add_exit("noreste","/d/adiel/room/cultivos/room/acueducto5.c","road"); 
}