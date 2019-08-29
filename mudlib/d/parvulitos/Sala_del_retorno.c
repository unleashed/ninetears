#include "path.h"

inherit "/std/room.c";

int i;
object not;
void setup()
{
   set_short("\n%^BLUE%^Sala%^RESET%^ del %^BLACK%^BOLD%^retorno%^RESET%^\n");

   set_long("Entras en la sala mas luminosa de todas las existentes. Aqui una sacerdotisa mantiene la sala en perfecto"
	      " orden. Hacia el norte ves una salida por un angosto tunel que posiblemente te lleve a tu hogar en el cielo."
            " Extranyamente la sala te invade un aura de bienestar y conocimiento dignos de un dios y sientes que podrias"
		" salir de aqui facilmente, aunque no por el tunel que parece mas bien un ciclo sin fin.\n");

   set_light(80);

   add_item ("tunel","\nOscuro y tenebroso, no sabes hasta donde llega.\n");

   add_clone(NPC+"yhan",1);

   add_exit("norte",APRENDICES+"Sala_del_retorno","tunnel");
   add_exit("oeste",APRENDICES+"pasillo_2","door");   

}

void init()
{
  ::init();
  add_action("salir","decir");
  add_action("trampa",({"go","goback","goto","dest","ed","home"}));
}

int trampa()
{
 write("Nonono, Cuando salgas de la zona ya lo usaras.\n");
 return 1;
}


int salir(string str)
{
 if (str == "No hay nada como el hogar!!")
    {
     switch (i)
     {
      case(0):
        write("Sientes que algo te empieza a poseer al gritar la frase magica.\n");
        say("Un aura azulacea empieza a cubrir el ser de "+TP->query_cap_name()+".\n");
        i++;/*aumenta en 1 la variable i*/
        return 1;
        break;
      case(1):
        i++;
        write("Empiezas a notar cierta intrascendencia en tu cuerpo. Parece como si te estuvieras descomponiendo"
       		 " por particulas.\n");
        say("El aura azulacea que cubria a "+TP->query_name()+" empieza a volverse verdacea. Notas que empiezas a ver"
 	     " a traves de el.\n");
        return 1;
        break;
      default:
        i=0;
        write("Tu cuerpo se desmaterializa por completo. Al principio tienes miedo pero luego te das cuenta que sigues entero"
 		 ". Te encuentras en tu hogar.\n");
        TP->move("/w/"+TP->query_name()+"/workroom");
        TP->look_me();
        say("Ante tus ojos, el cuerpo de "+TP->query_name()+" se vuelve rojo intenso por un momento y luego se desvanece en el aire."
 		" Como si lo hubieran desintegrado completamente.\n");
        if (!(TP->query_property("tablon")))
        {
         TP->add_property("tablon",1);
         write("Yhan te dice: No te olvides de la octavilla de ultimos consejos!!!.\n");
         not=new(OBJ+"cartoncito",1)->move(this_player());
        
        }
        else
        {
          write("Yhan te dice: Hasta la vista gran senyor!!\n");
        }
        return 1;
        break;
    }
   }
 notify_fail("Dilo dilo que no pasara nada.\n");
 return 0;
}



