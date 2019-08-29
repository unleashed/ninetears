// Muahahahaha, mi preciosa hachita

inherit "/obj/weapon";

void setup() {
  	set_base_weapon("hacha_dosmanos");
  	set_name("Hacha Sangrienta");
  	add_alias("hacha");
	add_alias("sangrienta");
  	set_short("Hacha %^RED%^%^BOLD%^Sangrienta%^RESET%^");
  	set_long("	Esta es la poderosa Hacha Sangrienta, forjada por Karn-Daragh para "
	         "que le sirviera en la batalla, es una de las hojas mas grandes y bien afiladas de "
		 "todo el universo. Sus dos filos estan hechos de hierro siempre incandescente, y, "
		 "pese a su enorme peso, crees que podrias blandirla con suma rapidez. \n");
  	set_main_plural("Hachas %^RED%^%^BOLD%^Sangrientas%^RESET%^");
  	add_plural("hachas sangrientas");
  	add_plural("hachas");
	add_plural("sangrientas");
	//add_attack("slashing",5,10,0);
	//add_attack("slashing",2,8,5);
	set_min_level(20);
	set_weight(3500);
	set_enchant(5);
	set_read_mess("\nEsta poderosa hacha solo puede ser empu�ada por el Gran Se�or de la Guerra.\n");
	reset_drop();
	}

int set_in_use(int i, object owner)
{
  if (i) {
    if (owner->query_name() != "karndaragh") {
      tell_object(owner, "\nUna oleada de terror te llega procedente de tu arma "
      "ral empu�arla y no reconocerte ella como su creador. \n"
      "Espasmos de dolor sacuden tu coraz�n y no puedes soportar la presion de tener "
      "el hacha en tus manos.\n");
      owner->do_death();
    }
    else {
      tell_object(owner, "\nNotas un sonido en tu mente procedente del hacha:"
       " Estoy a punto para la batalla, mi se�or.\n");
      return ::set_in_use(i, owner);
    }
  } else {
    tell_object(owner, "\nEl Hacha abandona tu mano con resignaci�n.\n");
    return ::set_in_use(i, owner);
  }
}

