inherit "/std/outside.c";
 void setup()
{
set_short("%^BOLD%^%^CYAN%^ Acueducto %^RESET%^");
set_long("%^BOLD%^%^CYAN%^Acueducto %^RESET%^\n\n Te encuentras"
    " ante una gran obra arquitectonica , utilizada para transportar el agua  "
    " hacia los numerosos cultivos que hay por esta zona .\n\n");
          
add_exit("oeste","/d/adiel/room/cultivos/room/acueducto7.c","road");
add_exit("noreste","/d/adiel/room/cultivos/room/acueducto9.c","road"); 
}