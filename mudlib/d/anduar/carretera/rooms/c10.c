//Paris Jun'98. Pequenya modificacion para poder entrar al Templo de Paris
// mediante la accion "abrir arbustos".

#include "path.h"
#include "weather.h"

inherit CARRETERA+"base";

void init()
{
	::init();
	add_action("do_abrir","abrir");
	add_action("do_abrir","apartar");
        add_action("do_rezar", "adorar");
}

void setup()
{
   set_long("Estas en el camino hacia Anduar, a ambos lados de la carretera"
            " hay arboles y arbustos. La gente no habla de"
            " este sitio como un lugar seguro, mas bien es la zona"
            " de trabajo de muchos bandidos, ladrones y rateros. "
            "Por las caracteristicas del terreno parece ideal para una "
            "emboscada. Al Norte ves un edificio hecho de piedra milenaria "
            "del que se irradia una sensacion de neutralidad y fuerza casi "
            "divina, pero los arbustos bloquean tu camino.\n");
   set_dark_long("Apenas distingues el camino hacia Anduar.\n\n");
   set_short("%^ORANGE%^Camino hacia Anduar%^RESET%^");
   add_alias("arboles", "arbol");
   add_item("arboles", "Ves arboles a ambos lados de la carretera."
                       " Tambien hay arbustos.\n");
   add_item(({"arbustos","arbusto"}), "Unos arbustos caracteristicos de la "
                                      "zona, con espinas, naturalmente.\n");
   add_item("suelo", "El suelo esta formado por tierra endurecida.\n");
   set_light(60);
   set_zone("carretera");
   
   add_exit("dentro",CARRETERA+"pos","road");
   add_exit("southwest",CARRETERA+"c9","road");
   add_exit("east",CARRETERA+"c11","road");
   crea_bichos();
}

void do_abrir(string str)
{
	if(capitalize(str) == "Arbustos")
	{
		write("Abres con delicadeza los arbustos revelandote una "
		      "entrada al Templo de Paris.\n");
		      
TP->move("/room/sacrifice/sac_paris");
		TP->look_me();
		
		return 1;
	}
	
	return 0;
} 

void dest_me()
{
   destruye_bichos();
   ::dest_me();
}
void do_rezar(string str)
{
  if(capitalize(str) == "Paris" && TP->query_group_name() =="Cofradia de las Garzas")
  {
    tell_object(TP,"Bienvenido a Casa.\n");
    TP->move("/d/clanes/cofradia_de_las_garzas/rooms/main.c");
TP->look_me();
    return 1;
  }
  return 0;
}
  
