
inherit "/std/room.c";



void setup()
{
   set_short("Reposo de %^BOLD%^%^BLACK%^Karn-Daragh%^RESET%^");

   set_long("Reposo de %^BOLD%^%^BLACK%^Karn-Daragh%^RESET%^\n\n"
      "   Una peque�a habitaci�n completamente blanca, sin nada en ella. Las paredes "
      "forman un oct�gono perfecto, y las salidas en la habitaci�n no son reales, sino que "
      "se crean cuando algun inmortal las visualiza.\n\n");

   add_clone("/obj/misc/button.c",1);
   add_exit("comun","/w/common","door");
   add_exit("entrada","/room/entryroom.c","door");
     
 
}

