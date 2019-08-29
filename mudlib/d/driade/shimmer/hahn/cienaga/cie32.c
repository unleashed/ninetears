/* By Shimmer */

inherit "/std/room";

void setup() {
   set_zone("cienaga");
   set_exit_color("yellow");
   set_light(30);
   set_short("Cienaga de los %^BOLD%^%^YELLOW%^Espectros%^RESET%^");
   set_long("Cienaga de los %^BOLD%^%^YELLOW%^Espectros%^RESET%^\n\n"
   "Te encuentras en un terreno fangoso y enpantanado, te cuesta moverte debido a que te hundes "
   "en el barro a medida que intentas caminar. Todo a tu alrededor esta cubierto de una espesa bruma. "
   "Esta es una zona muy peligrosa debido a las numerosas leyendas que hablan de espectros malignos"
   "y horribles monstruos que habitaban esta zona, de la que se sabe poco desde tiempos antiguos, "
   "antes de que la maldad se apodara de ella.\n\n");
add_clone("/d/driade/shimmer/hahn/npcs/varios_cienaga1.c",2);
add_exit("noroeste","/d/driade/shimmer/hahn/cienagap/ciep0.c","standard");
add_exit("este","/d/driade/shimmer/hahn/cienaga/cie31.c","standard");
add_exit("oeste","/d/driade/shimmer/hahn/cienaga/arbol_ameline.c","standard");
add_exit("sudoeste","/d/driade/shimmer/hahn/cienaga/cie69.c","standard");
}