//.oO JaDe Oo.  Junio'02
inherit "/std/guildroom";

void setup()
{
  set_short("%^BOLD%^%^BLACK%^Caballeros de %^GREEN%^J%^RESET%^%^GREEN%^aDe%^RESET%^: Trono");
  set_long("%^BOLD%^%^BLACK%^Caballeros de %^GREEN%^J%^RESET%^%^GREEN%^aDe%^RESET%^: Trono\n\n"
           "Te encuentras en la sala principal del gremio, donde se alistan y se entrenan "
           "a los Caballeros de JaDe. El sal�n es bastante amplio con una cuidada decoraci�n. "
           "Una estrecha alfombra de terciopelo rojo se extiende desde la entrada de la sala "
           "hasta los pies de la escalinata, un par de escalones tallados sobre los que descansa "
           "el imponente trono de Vingardtur.\n\n");
  add_item(("trono"),"Un gran trono de oro negro exquisitamente tallado, con grabados dorados "
  	             "y un gran ojo esmeralda en el centro del respaldo. Tiene unos brazales "
  	             "acabados en cabezas de drag�n talladas con unas esmeraldas engastadas a "
  	             "modo de inhertes ojos.");
  add_sign("Un signo negro preside la pared.\n",
  	   "\t-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- \n"
           "\t|                                      | \n"
           "\t|   Gremio de los %^BOLD%^BLACK%^Caballeros de %^GREEN%^J%^RESET%^GREEN%^aDe%^RESET%^   | \n"
           "\t|                                      | \n"
           "\t|   -- Escribe 'alistarse' para unirte | \n"
           "\t|      al gremio.                      | \n"
           "\t|   -- Para mas informaci�n acerca del | \n"
           "\t|      del gremio, escribe 'info'.     | \n"
           "\t|   -- Para subir niveles escribe      | \n"
           "\t|      'avanzar'.                      | \n"
           "\t|   -- Para ver lo que te cuesta       | \n"
           "\t|      subir al siguiente nivel        | \n"
           "\t|      escribe 'coste'.                | \n"
           "\t|                                      | \n"
           "\t-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- \n");
          
  set_exit_color("magenta");
 
  set_guild("caballerojade");
  set_guildmaster("/d/asgard/npc/vingardtur.c");
	
  add_exit ("norte", "/d/asgard/room/caballeros/tablon.c", "corridor");
  add_exit ("abajo", "/d/asgard/room/caballeros/circulo.c", "corridor");
  modify_exit("abajo",({"function","chekeo"}));
    }
    
int chekeo() {
    if(TP->query_guild()=="caballerojade"||!TO->query_guildmaster()) return 1;
    return notify_fail("El Guildmaster no te permite adentrarte en el gremio.\n");
    }