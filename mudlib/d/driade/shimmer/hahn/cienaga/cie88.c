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
add_clone("/d/driade/shimmer/hahn/npcs/varios_cienaga1.c",1);
add_exit("norte","/d/driade/shimmer/hahn/cienaga/cie87.c","standard");
add_exit("sur","/d/driade/shimmer/hahn/cienaga/cie16.c","standard");

}