/* By Shimmer */

inherit "/std/outside";

void setup() {
   set_zone("cienagaprofunda");
   set_exit_color("blue");
   set_light(40);
   set_short("%^YELLOW%^Zona Profunda de la Cienaga%^RESET%^");
   set_long("%^YELLOW%^Zona Profunda de la Cienaga%^RESET%^\n\n"
   "Estas en la parte profunda de la cienaga, esta es la zona donde mas encarnizada fue la batalla "
   "entre los humanos y los orcos, a tu alrededor puedes oir levemente los llantos y los gritos "
   "de los combatientes, cuyos espiritus aun pululan por la zona. A tu alrededor puedes ver restos y "
   "mas restos de armas rotas y armaduras oxidadas entre montones de huesos que por algun motivo no "
   "se han consumido con el paso de los anyos, es como si el tiempo no corriera aqui dentro\n\n");
add_clone("/d/driade/shimmer/hahn/npcs/cienaga2.c",3);

add_exit("sudoeste","/d/driade/shimmer/hahn/cienagap/ciep53.c","standard");
add_exit("oeste","/d/driade/shimmer/hahn/cienagap/ciep25.c","standard");
add_exit("sur","/d/driade/shimmer/hahn/cienagap/ciep55.c","standard");
add_exit("noreste","/d/driade/shimmer/hahn/cienagap/ciep86.c","standard");
add_exit("sudeste","/d/driade/shimmer/hahn/cienagap/ciep60.c","standard");
}