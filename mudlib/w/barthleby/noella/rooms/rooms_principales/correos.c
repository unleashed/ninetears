#include "/w/barthleby/path.h"

inherit "/std/room.c";


void setup()

{
    set_short("%^RED%^Oficina de correos de Noella%^RESET%^");
     set_long("%^RED%^Oficina de correos de Noella%^RESET%^\n\n"+
      "Es un edificio sencillo con dos mostradores recibiendo la entrada y un acceso detr�s " +
      "para el almac�n. Puedes ver como m�s alla del mostrador, hay gente clasificando cartas y " +
      "paquetes para ser entregados a los repartidores. A pesar de la aparente dedicaci�n de " +
      "los empleados, siempre hay alguien protestando por el retraso o estado de cartas y " +
      "u objetos recibidos.\n\n");

    set_light(50);

add_item(({"mostrador","mostradores"}),"Dos cortos mostradores dividen el recinto en dos de " +
        "forma que no hay acceso a la parte posterior.\n");

add_exit("fuera", MURALLAS_NOELLA+"muralla1","road");
}

void init()
{
   ::init();
   add_action("mail", "leer");
   add_action("mail", "mail");
}

int mail(string str)
{
object ob;

ob = clone_object("/obj/handlers/post");
ob->move(this_player());
ob->start_mail(str);
   return 1;
}

void send_message(string to)
{
   write("Uno de los encargados le da las instrucciones a una paloma y se va "+
      "volando con tu carta metida en una bolsita colgada a su cuello.\n");
   say("Uno de los encargados le da instrucciones a una paloma para entregar una carta "+
      "de "+this_player()->query_cap_name()+" y sale volando por la puerta.\n");
   if (find_living(to))
      call_out("after_call",5,to);
}

void after_call(string to)
{
   object ob;

   ob = find_living(to);
   if (!ob)
      return ;
   if (environment(ob) == this_object())
      say("La paloma vuelve por la puerta y le da una nota a "+to+
      ".\n", this_player());
   else {
      tell_room(environment(ob), "Una paloma vuela hacia "+to+", dice algo, "+
         "y se va volando por donde vino.\n", ({ ob }));
      call_out("come_back",5);
   }
   tell_object(ob, "Una paloma vuela hacia ti y te informa de que "+
      "tienes correo.\n");
}

void come_back()
{
   tell_room(this_object(),"Una paloma vuelve de su reparto de correo.\n");
}
