inherit "/std/outside.c";
 void setup()
{
set_short("%^BOLD%^%^CYAN%^ Acequia %^RESET%^");
set_long("%^BOLD%^%^CYAN%^Acequia %^RESET%^\n\n Te encuentras"
    " sobre la acequia de estos cultivos , es un canal de irrigacion "
    " utilizado desde hace muxo tiempo por esta zona para abastecer"
    " de agua a los numerosos cultivos y pastos de la zona. Podrias tener"
    " dificultades para desplazarte por aki, debido a lo mojado del terreno.\n\n");
          
add_exit("sur","/d/adiel/room/cultivos/room/acequia2.c","road");

}