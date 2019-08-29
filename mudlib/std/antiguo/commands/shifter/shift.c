/* The main Shapeshifter command only to be used by that guild
 * added a random shift possibility so the shifter might not always be 
 * able to shift to form he expects too.  costs 10 GPs but most of the
 * GP is in each form.   also shift fails if shifter is currently being
 * shadowed.
 * Raskolnikov Oct 96
 */
#define OBJ "/d/aprior/guilds/shifter/handlers/shift_obj"
#define FORMS "/d/aprior/guilds/shifter/forms/"
#define GP_COST 10
#define RANDOM_SHIFT random(45)


void shift(string form)
{
    int delay, form_check;
    string delay_string;
    object ob, shift_obj;

    if(!form) {
	"/table/form_table"->list_valid_forms(this_player());
	return 1;
    }

    if(this_player()->query_gp() < GP_COST) {
	tell_object(this_player(), "Parece que no puedes generar "
	  "suficiente energia para transformarte ahora...\n");
	return 1;
    }

    form_check = "/table/form_table"->lookup_valid_forms(this_player(),
      form);
    if(!form_check) {
	tell_object(this_player(), "No conoces esa forma.\n");
	return 1;
    }

    if(this_player()->query_property("shifting")) {
	tell_object(this_player(), "Ya estas transformandote.\n");
	return 1;
    }

    if(!(shadow(this_player(), 0))) {
	ob = clone_object(FORMS+form+".c");
	shift_obj=clone_object(OBJ); 
	delay = ob->query_shift_delay();
	if(delay) {
	    delay_string = ob->query_shift_delay_message();
	    tell_object(this_player(), delay_string+"\n");
	    call_out("do_shift", delay, this_player(), 
	      form, ob, shift_obj);
	    return 1;
	}
	this_player()->add_property("shifting", 1);
	call_out("do_shift", 0, this_player(), 
	  form, ob, shift_obj);
	return 1;
    }
    tell_object(this_player(), "No has conseguido convertirte en "
      "esa forma...\n");
    return 1;
}

void do_shift(object player, string form, object ob, object shift_obj) {
    int i, no_inv_flag, random_shift;
    string *forms;
    object *obs;

    random_shift = (this_player()->query_int() + 
      this_player()->query_cha()) - RANDOM_SHIFT;
    if(random_shift < 0) {
	tell_object(this_player(), "Pierdes la concentracion momentaneamente "
	  "y te transformas en una forma al azar!\n");
	forms = "/table/form_table.c"->lookup_valid_forms(this_player(),
	  "all");
	form = forms[random(sizeof(forms))];
	ob = clone_object(FORMS+form+".c");
    }

    no_inv_flag = ob->query_no_inv();
    if(no_inv_flag) {
	obs = all_inventory(player);
	for(i=0;i<sizeof(obs);i++)
	    if(!(obs[i]->query_shift_ob()))
		player->drop_ob(obs[i]->query_name());
    }
    ob->setup_shadow(player, shift_obj);
    if(ob->query_ent_mess())
    {  player->setmin(ob->query_ent_mess()); }
    if(ob->query_out_mess())
    {  player->setmout(ob->query_out_mess()); }
    if(function_exists("setup_extras", ob))
	ob->setup_extras();
    shift_obj->set_get();
    shift_obj->move(player);
    shift_obj->reset_get();
    shift_obj->reset_drop();
    shift_obj->set_shift(player);
    player->add_shift_property("static", "nocast", 1, 0);
    player->adjust_gp(-GP_COST);
    shift_obj->set_shift_sh(ob);
    tell_object(player, "Tu cuerpo entero parece implosionarse "
      "y sientes tu mente tan pesada que parece que te vaya a "
      "estallar.\n\nTus sentido se alejan de la realidad momentaneamente, "
      "y cuando vuelves a tu ser has cambiado tu forma y eres un "
      +form+".\n\n");
    tell_room(environment(player), "Observas aterradamente como "
      +player->query_cap_name()+" parece mutar en una nueva forma "
      "delante de ti!\n\n", ({ player }) );
    this_player()->remove_property("shifting");
    return 1;
}

string help(string str) {
    return "Sintaxis: shift <forma>\n\n"
    "Este comando permite al shapeshifter cambiar su forma. Los GPs "
    "se consumen a un ritmo mantenido mientras experimentas una realidad "
    "alternativa, asi que transformate sabiamente. Debes volver a tomar tu "
    "forma normal antes de intentar cambiar a otra, y si tu inteligencia y "
    "tu suerte no fueran suficientemente altas, podrias perder la concentracion "
    "y transformarte en algo distinto de lo que querias.\n"
    "Coste inicial de GPs: 10\n\n";
}
