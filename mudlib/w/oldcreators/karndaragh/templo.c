
inherit "/std/room.c";
object espada,armadura,escudo;



void setup()
{
   set_short("%^BOLD%^Templo%^RESET%^ de la %^BOLD%^%^BLACK%^Guerra%^RESET%^");

   set_long("%^BOLD%^Templo%^RESET%^ de la %^BOLD%^%^BLACK%^Guerra%^RESET%^\n\n"
      "   Una enorme habitaci�n circular, con una enorme estatua de m�rmol en el "
      "centro, representando un guerrero completamente cubierto por una armadura, y "
      "empu�ando una magnifica espada y un recio escudo. En las paredes puedes ver "
      "montones de espadas, escudos y armaduras colgados, de diversas formas y tama�os, asi "
      "como varios tapices en los que se observan escenas de grandes batallas. C�modos sillones "
      "alrededor de la estatua permiten a los visitantes sentarse y relajarse, si es que eso"
      " es posible en un lugar como este.\n\n");

   add_item("armaduras","De todo tipo y forma, las armaduras que ves a tu alrededor te hacen estremecer al sentir el"
			  " poder que emana de ellas.\n");
   add_item("espadas","Montones de espadas colgadas en las paredes, la mayoria de una calidad insuperable. \n");
   add_item("escudos","Una gran variedad de escudos decoran tambi�n las paredes, mostrando muchas clases de banderas y s�mbolos.\n");
   add_item("sillones","Puedes ver cinco sillones rojos muy comodos, dispuestos alrededor de la estatua.\n");
   add_item(({"estatua","guerrero","marmol","centro"}),"En el centro mismo de la habitaci�n se erige una formidable"
            " estatua de marmol, representando un guerrero de raza indeterminada, con su armadura cubriendole el cuerpo"
            " al igual que el yelmo su rostro, y empu�ando de forma amenazadora una espada y un escudo.\n");
  
   add_exit("arriba","/w/karndaragh/mapa.c","door");
   add_exit("abajo","/w/karndaragh/entrada.c","door");
   
 
}

void init()
{
   ::init();
   add_action("coger","coger");
}

int coger(string str)
{
   switch (str)
   {
     case ("espada"):
       if (TP->query_timed_property("espada_karndaragh"))
        {
           write("Ya cogiste una espada hace poco, no crees que sea buena idea agotar todas las armas.\n");
           return 1;
        }
       else
        {
           write("Coges una espada colgada en la pared.\n");
     	   TP->add_clone("/baseobs/weapons/bastarda.c",1);
           TP->add_timed_property("espada_karndaragh",1,1000);
           say(TP->query_name()+" coge una espada que estaba colgada en la pared.\n");
           return 1;
        }
       break; 
     case ("escudo"):
       if (TP->query_timed_property("escudo_karndaragh"))
        {
           write("Ya cogiste un escudo hace poco, no crees que sea buena idea agotar todas los escudos.\n");
           return 1;
        }
       else
        {
           write("Coges un escudo colgada en la pared.\n");
           TP->add_clone("/baseobs/shieldscorporal.c",1);
           TP->add_timed_property("escudo_karndaragh",1,1000);
           say(TP->query_name()+" coge un escudo que estaba colgada en la pared.\n");
           return 1;
        }
     case ("armadura"):
       if (TP->query_timed_property("armadura_karndaragh"))
        {
           write("Ya cogiste una armadura hace poco, no crees que sea buena idea agotar todas las armaduras.\n");
           return 1;
        }
       else
        {
           write("Coges una armadura colgada en la pared.\n");
           TP->add_clone("/baseobs/armours/completa.c",1);
           TP->add_timed_property("armadura_karndaragh",1,1000);
           say(TP->query_name()+" coge una armadura que estaba colgada en la pared.\n");
           return 1;
        }
       break; 
     default:
        notify_fail("No puedes coger ningun "+str+".\n\n");
        return 0;
        break;
   }
   return 1;
}
