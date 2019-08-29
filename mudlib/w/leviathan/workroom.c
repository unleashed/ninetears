inherit "/std/room.c";
//inherit "/std/noncombat.c";
#define CREADOR "Leviathan"
void setup() {
set_short("%^BOLD%^WHITE%^Entrada al palacete de %^BOLD%^RED%^"+CREADOR+"%^RESET%^.");

  set_long("%^BOLD%^WHITE%^Entrada al palacete de %^BOLD%^RED%^"+CREADOR+"%^RESET%^.\n"
      "   \nTe encuentras al aire libre, en los jardines de un majestuoso palacio"
      " que parece levantarse en medio de la nada. Todo en la zona es paz y tranquilidad"
      " una vaga sensacion de seguridad llega de alguna parte, como si aqui no pudiera"
      " ocurrirte nada malo.En el centro del jardin, una fuente vierte su agua mientras"
      " las aves cantan en tonos melodiosos. Pasillos de granito serpentean por todas"
      " partes sin parecer que lleven a algun sitio en concreto.\n\n");

   add_clone("/w/leviathan/npcs/servicio.c",1);
   set_light(70);
   add_item("fuente","Es una preciosa fuente, de la cual mana "
      " un agua limpia y clara, en el fondo hay monedas.");
   add_item("elefante","Es una preciosa fuente, de la cual mana "
   	  " un agua limpia y clara, en el fondo hay monedas.");
   add_item(({"setos","seto"}),"son unos setos verdes que delimitan la estancia,"
      " cuando te acercas a ellos te da la sensacion de que tienen vida "
      " propia.");
   add_item("suelo","el suelo es bastante llamativo parece como si estuviese "
      "esculpido directamente en una gran roca de granito.");
   add_item("agua","pues parece agua normal, eso si... muy limpia.\n");
   add_smell(({"estancia","aire"}),"El olor es semejante al de una noche de"
        " primavera, es un olor fresco y que te llena el corazon.");
   add_smell("agua","no te ensenyaron en la escuela que el agua es inodora?");
   add_taste("agua","no te ensenyaron en la escuela que el agua es insipida?");
   add_feel("agua","vaya... parece que moja.");
   add_sound(({"agua","fuente"}),"el agua cae a borbotones del chorro principal de "
       "la fuente.");
  add_sound("estancia","No hay el mas minimo ruido, excepto el viento y el agua"
	     " de la fuente.");
   add_feel("suelo","es un suelo de granito, bastante suave pero granito no "
        "obstante.");

        add_exit("comun","/w/common","hidden");
        set_zone("leviathan");
	add_exit("sur","/w/leviathan/pensar.c","door");
	 modify_exit("sur",( "function", "pon_titulo"));

//	add_exit("accesos","/room/admin/site_control.c","door");
//	add_exit("derechos","/room/admin/access_control.c","door");
	add_exit("guild","/w/leviathan/guildtroll/barracks.c","door");
        add_exit("entrada","/room/entryroom.c","hidden");
        add_exit("anduar","/w/leviathan/anduar.c","hidden");
	add_exit("capilla","/w/leviathan/capilla.c","door");
        add_exit("dentro","/w/leviathan/baul.c","door");
        add_exit("biblioteca","/w/leviathan/biblioteca.c","door");

	return(0);
}
void init()
{
  ::init();
  add_action("trampa",({"salir","exit","quit","retire"}));
}

int trampa()
{
if (this_player()->query_name() != "leviathan")
{
	write("\nSi claro salirte en mi casa para beberte el vino cuando no este eh listo???.\n\n");
}
 return 1;
}


int pon_titulo(string str, object ob, string special_mess)
{
if (this_player()->query_cap_name()=="Leviathan")
{
        this_player()->set_title("%^BOLD%^YELLOW%^Buscando %^CYAN%^Nuevos %^BLACK%^Caminos.%^RESET%^(Away from keyboard)%^RESET%^");
}
return 1;
}

