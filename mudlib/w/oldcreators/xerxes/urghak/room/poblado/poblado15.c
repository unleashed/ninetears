// Xerxes '02

inherit "/std/outside";

void setup()
{
   set_short("%^BOLD%^Atalayas %^BLACK%^de %^GREEN%^Urghak: %^RESET%^Atalaya Norte");
   set_long("La funcion de estas atalayas es localizar a los posibles enemigos "
            "procedentes del este con la antelacion suficiente para preparar "
            "la defensa de la ciudad.\n");
   set_light(80);

   add_exit("este", POBLADO + "poblado14.c", "path");
      
   set_zone("ciudad_urghak");
}