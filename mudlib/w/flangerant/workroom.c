#define CREATOR "flangerant"

inherit "/std/room.c";



void setup()
{
   set_short("Cabanya en el Arbol");

   set_long("Cabanya en el Arbol.\n\n"
      "   Esta es la cabanya que tenia Flangerant en el arbol "
      "de anduar. Cuando el bardo dejo su antiguo hogar y se "
      "fue a trotar mundos, se llevo la casa encima qual caracol. "
      "Es impresionante como puede haber una cabanya en el arbol aqui "
      "si tu no logras distinguir donde esta el arbol... todo parece "
      "ser bastante raro aqui. "
      "\n\n");

  
   add_clone("/obj/misc/button.c",1);
   add_exit("comun","/w/common","door");
   add_exit("entrada","/room/entryroom.c","door");
   add_exit("faeleen","/d/faeleen/common.c","door");
 
}