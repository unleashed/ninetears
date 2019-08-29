/** coded by Raskolnikov Nov 96 **/

/* for the parasite form.  the shifter becomes invisible to the env
 * of the victim and stays with him no matter what because he is 
 * inside the victims bloodstream.  the actual damage is done with an
 * object added to the victims inv (withering ob).  the shifter has slim
 * chance of living if cure poison is cast upon him, but mostly likely he
 * will die instantly.  if he does live he becomes visible and takes a 
 * drastic hp cut.  also the cure MUST come from a player and 
 * not a potion.
 */

#define INFECT_OB "/d/gremios/comandos/shifter/obj/infect_ob.c"
#define GP_COST 30

void infect(string str) {
    object victim, infect_ob;

    if(this_player()->query_parasite_shadow() != 1) {
	tell_object(this_player(), "You are not currently "
	  "in parasitic form and should therefore not have this "
	  "command.\n");
	this_player()->remove_known_command("infect");
	return 1;
    }

    if(str == "stop") {
	if(this_player()->query_property("infecting") != 1) {
	    tell_object(this_player(), "Umm you are not currently "
	      "infecting anything so there is no need to stop.\n");
	    return 1;
	}
	tell_room(environment(this_player()),
	  this_player()->query_cap_name()+" begins to seep out of "
	  ""+this_player()->query_possessive()+" victims body.\n");
	this_player()->stop_infecting();
	return 1;
    }

    if(this_player()->query_property("infecting") == 1) {
	tell_object(this_player(), "You are already infecting "
	  "someone and there is not enough of you to go around infecting "
	  "everyone.\n");
	return 1;
    }

    victim = present(str, environment(this_player()));

    if(victim == this_player()) {
	tell_object(this_player(), "Why would you want to infect "
	  "yourself?\n");
	return 1;
    }

    if(!victim || !living(victim)) {
	tell_object(this_player(), "You can not seem to find "
	  "that target anywhere around.\n");
	return 1;
    }

    if(victim->query_property("disease")) {
	tell_object(this_player(), "Your victim is currently "
	  "immune to disease attacks!\n");
	return 1;
    }

    tell_object(this_player(), "You seep "
      "into "+victim->query_cap_name()+"'s "
      "bloodstream and infect him!\n");
    tell_object(victim, "Your body is invaded by "
      ""+this_player()->query_cap_name()+"!  You need to find "
      "a cleric with disease curing powers "
      "or else you will surely die!\n\n");
    infect_ob = clone_object(INFECT_OB);
    this_player()->add_property("infecting", 1);
    this_player()->do_infection(victim, infect_ob);
    this_player()->adjust_gp(-GP_COST);
    victim->add_property("infected", this_player()->query_name());
    infect_ob->get_players(this_player(), victim);
    infect_ob->move(victim);
    return 1;
}

string help(string str) {
    return 
    "Syntax: infect <victim>\n"
    "        infect stop\n\n"
    "This command allows the parasite to enter his victims body slowly "
    "killing him.  The only way the parasite can be expelled is to have a "
    "cleric cast cure disease on him.  This will most likely result in the "
    "instant death of the parasite.\n"
    "GP cost: 30\n\n";
}
