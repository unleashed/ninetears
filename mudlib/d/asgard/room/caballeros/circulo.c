//.oO JaDe Oo.  Junio'02
inherit "/std/room";

void setup() {
   set_short("%^BOLD%^%^BLACK%^Caballeros de %^GREEN%^J%^RESET%^%^GREEN%^aDe%^RESET%^: Sal�n del C�rculo.");
   set_long("%^BOLD%^%^BLACK%^Caballeros de %^GREEN%^J%^RESET%^%^GREEN%^aDe%^RESET%^: Sal�n del C�rculo.\n\n"
   "Este es el lugar de reuni�n de los miembros destacados del gremio. "
   "Una amplia sala abovedada con cuatro arcos, uno a cada lado, sin "
   "cristaleras ni ventanas de ninguna clase, pues se encuentra en el "
   "segundo nivel del edificio. La unica iluminaci�n de la sala proviene "
   "de unos grandes pebeteros colocados en cada esquina de la sala. "
   "Una mesa ovalada con un gran ojo esmeralda dibujado en el centro y "
   "unas sillas de piedra que parecen fundirse con el suelo constituyen "
   "el parco mobiliario de la estancia.\n\n");
 
  set_exit_color("magenta");
  add_item("lista","Escribe 'leer lista' para leer la lista, y 'a�adir <nombre>' para a�adir un nombre a la lista.\n");
  add_exit("este", "/d/asgard/room/caballeros/baul.c","door");
  add_exit("oeste", "/d/asgard/room/caballeros/forja.c","door");
  add_exit("arriba", "/d/asgard/room/caballeros/trono.c","door");
  
}

write_list(arg)
{
 
  if(!(this_player()->query_guild_ob()=="/d/gremios/guerreros/caballerojade"))
   {
    write("No eres un Caballero de JaDe! No provoques la ira de la Diosa!");
    return 1;
   }
 if(!arg)
   {
    write("Sintaxis:  a�adir <pj>");
    return 1;
   }


  if((this_player()->query_level()>=10 || ((string)(this_player()->query_guild_ob()) !=
        "/d/gremios/guerreros/caballerojade")))
{
    write("Ok, "+arg+" a�adido.\n");
   write_file("/d/asgard/room/caballeros/list.txt","%^BOLD%^WHITE%^MATAR A:  %^BOLD%^RED%^"+arg+"\t%^WHITE%^REPUDIADO POR: %^GREEN%^"+this_player()->query_cap_name()+".\n");
}
 else
  write("Eres demasiado inexperto como para escribir en la lista. Se requiere nivel 11 o superior.\n");
  return 1;
}
 
exa_list(arg)
{
 if(!arg)
  {
    write("Sintaxis:  leer lista\n");
    return 1;
   }
 if(!(arg=="lista"))
  return 0;
 write("\n%^BOLD%^WHITE%^POR CRIMENES CONTRA EL GREMIO: \n"+
	 "%^BOLD%^WHITE%^------------------------------\n"+read_file("/d/asgard/room/caballeros/list.txt"));

 return 1;
}
 
void init()
{
 add_action("write_list","a�adir");
 add_action("exa_list","leer");
 ::init();
}
