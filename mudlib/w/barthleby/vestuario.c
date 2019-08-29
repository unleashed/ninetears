inherit "/std/room";

#include "/w/barthleby/path.h"

void setup()

{
    set_short("%^RED%^Vestuario de %^BOLD%^%^WHITE%^Bar%^GREEN%^th%^YELLOW%^le%^CYAN%^by%^RESET%^");
     set_long("%^RED%^Vestuario de %^BOLD%^%^WHITE%^Bar%^GREEN%^th%^YELLOW%^le%^CYAN%^by%^RESET%^\n\n"+
      "Has entrado en un lugar que parece estar suspendido en el tiempo y el espacio en " +
      "el que no alcanzas a diferenciar las divisiones entre suelo, paredes o techo. " +
      "En el centro de la habitaci�n flota una peque�a esfera muy extra�a.\n\n");

    set_light(50);


add_exit("fuera", "/w/barthleby/workroom","corridor");

add_clone(ITEMS+"esfera", 1);
}



void init()
{
   ::init();
   add_action("tocar_esfera","tocar");
}

int tocar_esfera(string que)
{
	if (!que || que!="esfera") {
		notify_fail("Tocar que?");
		return 0;
	}
if (TP->query_cap_name()=="Barthleby")
      {
      write("Tocas la esfera y tu equipo surge de la misma, se pone a girar a tu elrededor y " +
         "finalmente te es entregado.\n");

      say(this_player()->query_cap_name()+" toca la esfera y unos objetos que surgen de la esfera " +
         "se ponen a girar a su alrededor hasta que finalmente pasan a formar parte de su equipo.\n");

      clone_object(ITEMS+"/equipo_barthleby/xxx.c")->move(this_object());
      return(1);
      }

      write("Tocas la esfera y el equipo de Barthleby surge de la misma, se pone a girar a tu elrededor " +
         "pero al no reconocerte como su due�o vuelve a desaparecer en la esfera.\n");
      
      say(this_player()->query_cap_name()+" toca la esfera y unos objetos que surgen de la esfera " +
         "se ponen a girar a su alrededor hasta que finalmente regresan a la esfera.\n");
      return(1);

/*    }
   notify_fail("No hay nada exceptuando una esfera en esta habitaci�n.\n");
   return(0);*/
}
