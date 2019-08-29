/* By Shimmer */

inherit "/std/room";

void setup() {
   set_zone("cienaga");
   set_exit_color("blue");
   set_light(30);
   set_short("%^BOLD%^BLACK%^Monticulo de Rocas%^RESET%^");
   set_long("%^BOLD%^BLACK%^Monticulo de Rocas%^RESET%^\n\n"
   "Estas en lo alto de una roca en el medio de la cienaga, desde aqui apenas puedes ver a tu alrededor "
   "dado que la bruma lo cubre todo, pero puedes oir los gritos de los espectros y el chapotear de los "
   "alimanyas alla abajo. Si miras hacia el norte puedes divisar la parte superior de las dos torres, "
   "una al noroeste y la otra enfrentada al noreste.\n\n");
add_clone("/d/driade/shimmer/hahn/npcs/edlin.c",1);
add_exit("abajo","/d/driade/shimmer/hahn/cienaga/cie62.c","standard");

}