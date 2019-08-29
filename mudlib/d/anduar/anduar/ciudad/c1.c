#include "../path.h"
inherit ANDUAR+"roadroom";

object bicho;

void setup()
{
  base_desc();
  add_item("cartel","\n _______________________________"
                    "\n|                               |\n"
                      "| Bienvenido osado viajero esta |\n"
                      "|                               |\n"
                      "| apunto de entrar en Anduar la |\n"
                      "|                               |\n"
                      "| ancestral ciudad. Disfrute de |\n"
                      "|                               |\n"
                      "| su estancia entre nosotros.   |\n"
                      "|_______________________________|" );
   add_exit("north",ANDUAR+"c2","road");
  crea_bichos();
}

void dest_me()
{
   ::dest_me();
   destruye_bichos();
}
void init()
{
  add_action("entra","arrastrar");
  ::init();
}

int entra(string str)
{
  if(!str && str != "tapa")
    {
      notify_fail("Perdon?\n");
      return 0;
    }   

  if(TP->query_group_name() != "Amigos de la Muerte" )
    {
      notify_fail("Perdon?\n");
      return 0;
    }
  else
    {
   TP->move("/d/clanes/amigos_muerte/rooms/jur.c");
      TP->look_me();
    } 
}
