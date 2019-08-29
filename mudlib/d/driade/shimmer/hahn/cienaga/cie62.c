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
   "antes de que la maldad se apodara de ella. A un lado puedes ver un gran monticulo de rocas gigantes "
   "que llaman tu atencion.\n\n");

add_item("rocas","Unas inmensas rocas de unos 7 o 8 metros de alto se encuentran ante ti, ves una especie de "
                 "marcas por las cuales una persona podria subir aunque con algo de dificultad, no sabes lo que "
                 "podrias encontrate alli arriba.\n\n");


add_clone("/d/driade/shimmer/hahn/npcs/varios_cienaga1.c",1);
add_exit("norte","/d/driade/shimmer/hahn/cienaga/cie61.c","standard");
add_exit("sur","/d/driade/shimmer/hahn/cienaga/cie6.c","standard");

}

void init()
{
   ::init();
   add_action("sube", "escala*r");  /* si en la room pones escalar/escala/subir rocas te manda a la room de edlin para hacer la Quest */
   add_action("sube", "subir");
}

void sube(string rocas)
{
   if (!rocas || rocas!="rocas")
   {
      this_player()->notify_fail(query_verb()+" que?\n");
      return 0;
   }
   write("\nComienzas a escalar por la roca con mucho cuidado de no caer, "
   "ya que no te gustaria romperte la crisma contra el suelo.\n");
   say(this_player()->query_cap_name()+" comienza a escalar la roca con cuidado y "
   "desaparece de tu vista en lo alto.\n");
   this_player()->move("/d/driade/shimmer/hahn/cienaga/cie63.c");
   this_player()->look_me();
   return 1;
}