#include "path.h"
inherit HAVMAND+"pirate.c";
object captain;
void setup()
{
    
   set_light(LIGHT);
    set_short("Isla de Havmand: Campamento pirata.\n");
    set_long("\nIsla de Havmand: Campamento pirata.\n"
    "   Aqui es donde el lider de los piratas tiene su campamento. Hay un pequenyo "
    "refugio construido a un lado, con varias botellas vacias esparcidas alrededor. "
    "Un camino conduce a la playa, y otro hacia el campamento principal"
    ". "
    "\n\n");
    add_item("refugio","Una estructura basica hecha con ramas de arboles y helechos, "
    "al menos parece proteger de la lluvia.\n");
    add_item("botellas","Botellas vacias esparcidas por el suelo, te imaginas que su "
    "contenido era algun brebaje alcoholico.\n");
}
void init()
{
    add_exit("oeste",HAVMAND+"j20.c","path");
    add_exit("este",HAVMAND+"b02.c","path");
    add_exit("sudoeste",HAVMAND+"p03.c","path");

    ::init();
}
void reset()
{
   if(!captain)
   {
      captain = new(CHARS+"prat");
      captain->move(this_object());
   }
   ::reset();
}
void dest_me()
{
   if(captain) captain->dest_me();
   ::dest_me();
}
