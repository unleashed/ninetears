/* Ok, this time it's this code I will walk through...
 * Baldrick, april '94
 * Death.c removed from cmbat.c to make it cleaner.
 */

#define DIV_NUM 6
#define OMIQ_HAND "/global/omiq"
#define DEATH_HAND "/obj/handlers/death"
#define NOGOD "ninguna"

// prototypes:
void actual_death();

int do_death(object killed_by) {
    	int dead_xp, tot, i;
    	float xp_adj;
    	mapping damage_done;
    	int att_level;
    	int attackers, attacker_xp;
    	string deity;
    	int ethos,dei;
    	object *attacker_list, *call_outed;

    // Death statistics - Radix April 1996
    	catch(xp_adj=DEATH_HAND->update_statistics(this_object(),killed_by));
    	xp_adj = 1;
    // Taniwha, 1996.
    	if(this_object()->query_race_ob()) catch(this_object()->query_race_ob()->on_death(this_object(),killed_by));
    	if(this_object()->query_guild_ob()) catch(this_object()->query_guild_ob()->on_death(this_object(),killed_by));

    	if(capitalize(this_object()->query_deity()) != capitalize(NOGOD)) {
		string handler;
	// SI NO USAS EL CATCH NO MUERES! :?
		handler = "/baseobs/misc/gods/"+TO->query_deity()+"_hand";
	// SI NO CALCULAMOS ANTES EL PATH, AL HACERLO DENTRO DE CATCH NO RULAAA!!!
		catch(handler->on_death(this_object(),killed_by));
    		}

    /* Added to maybe fix an annoying bug..
     * The dead on login bug..
     * Baldrick, April '95.
     */
    	if (this_object()->query_property("loading")) return 0;

    	attacker_list = this_object()->query_attacker_list();
    	call_outed = this_object()->query_call_outed();
    /* Added this because 0's in the attacker/call outed list sometimes
     * pop up and screw things up royally.  Monsters not dying, that sort of thing.
     * --WF, apr 95
     */
    	attacker_list -= ({ 0 });
    	call_outed -= ({ 0 });

    	att_level = (int)this_object()->query_level();
    	damage_done = (mapping)this_object()->query_damage_done();
    	if (!damage_done) damage_done = ([ ]);
    	for (i=0;i<sizeof(attacker_list);i++) {
		attacker_list[i]->stop_fight(this_object());
		tot += damage_done[attacker_list[i]];
		attackers++;
    		}
    	for (i=0;i<sizeof(call_outed);i++) call_outed[i]->stop_fight(this_object());

    /* ??? where is this from ???
     * It is the victims XP, so it can be added to the killer..
     * Smart, and nice..
     */
    	dead_xp = (int)this_object()->query_xp();
    	if(interactive(this_object())) secure_log_file("exp_loss",ctime(time())+": "+this_object()->query_cap_name()+" lost "+dead_xp+".\n");

    	if (!tot) tot = 1;

    /* this gives the total for each attacker.. */
    	if (dead_xp != 0) attacker_xp = dead_xp / 20;
    	if (attackers) attacker_xp+=(int)this_object()->query_kill_xp()/attackers;

   	if(interactive(this_object())) attacker_xp = 0;
    /* Deliver the XP.. */
    	for (i=0;i<sizeof(attacker_list);i++) {
		if(!attacker_list[i]) continue;
		if(function_exists("adjust_xp",attacker_list[i])) {
	    		ethos = (int)this_object()->query_ethics();
	    		deity = (string)this_object()->query_deity();
	    		dei = (int)this_object()->query_deity_status(deity);
	    		attacker_list[i]->adjust_xp(attacker_xp);
	    		attacker_list[i]->adjust_ethics(-ethos);
	    		attacker_list[i]->adjust_deity_status(-dei,deity);
			}
    		}
    	this_object()->set_dead(1);
    	if(OMIQ_HAND->omiq_in_progress() && interactive(this_object())) this_object()->add_property("OMIQ_KILLED",1);
    	if (killed_by) {
		tell_room(environment(this_object()),killed_by->query_cap_name()+" acaba con la vida de "+this_object()->query_cap_name()+".\n",({killed_by,TO}));
		tell_object(TO,killed_by->QCN+" ha acabado con tu vida.\n");
		tell_object(killed_by,"Acabas con la vida de "+this_object()->query_cap_name()+".\n");
    		}
  	else {
		tell_room(environment(this_object()),this_object()->query_cap_name()+" muere horriblemente.\n",TO);
		tell_object(TO,"Mueres horriblemente.\n");
		}

    	if (environment()) event(environment(),"death",attacker_list,killed_by);
    	actual_death();
    	return 0;
	}

object make_corpse() {
    	object corpse;
    	mixed *usedstuff;
    	string my_mess, room_mess;
    	int i;

    	my_mess = "";
    	room_mess = "";

    	corpse = clone_object("/obj/corpse");
    /* Hamlet fixed next line */
    	corpse->set_owner(this_object()->short(0),this_object());
    	corpse->set_race_name(this_object()->query_race());

    //? corpse->add_alias((string)this_object()->query_name());
    //? corpse->add_alias((string *)this_object()->query_aliases());
    //? corpse->add_plural((string *)this_object()->query_plurals());

    	corpse->start_decay();
    //corpse->add_adjective(this_object()->query_adjectives());
    	if (!this_object()->query_race_ob()) if (file_size("/std/races/"+this_object()->query_race()+".c") >= 0) corpse->set_race_ob("/std/races/"+this_object()->query_race());
		else corpse->set_race_ob("/std/races/unknown");
    	else corpse->set_race_ob(this_object()->query_race_ob());

    //dk Until we make an informed decision here, I'm going to have corpses
    //unhold, unwear and unwield everything.  Otherwise, since some items have a
    //special effect on the room only if they're worn or held by a living
    //creature, creators would have to code each such item carefully to
    //distinguish the effects when worn or held by a corpse...we probly don't
    //want to do this, but even if we do, I don't want to deal with it right now.

    /* Un equip the player ? or corpse ? */
    	usedstuff = (mixed *)this_object()->query_held_ob();

    	if (sizeof(usedstuff)) {
		my_mess = "Caes al suelo destrozado";
		room_mess = (string)this_object()->query_cap_name() +" cae al suelo destrozado";
    		}

    	for (i=0;i<sizeof(usedstuff);i++) {
		if (objectp(usedstuff[i])) {
	    		object ok;
	    		ok = usedstuff[i];
	    		this_object()->unhold_ob(ok);
	    		ok->move(environment(this_object()));
			}
    		}

    /* Reset the array (to be sure ) */
    	usedstuff = ({ });

    	usedstuff = (mixed *)this_object()->query_worn_ob();

    	if (sizeof(usedstuff))
		if (stringp(my_mess)) {
	    		my_mess += ", y tus armas caen de tus manos y chocan contra el suelo";
	    		room_mess += ", y sus armas caen de sus manos y chocan contra el suelo";
		}
		else { // pa mi kesto es... unreachaaaaable
	    		my_mess += "Your weapons fall from your limp hands and drop to the floor";
	    		room_mess += this_object()->query_cap_name() +"'s weapons fall from "+this_object()->query_possessive()+" limp hands and drop to the floor";
			}

    		for (i=0;i<sizeof(usedstuff);i++) {
			if (objectp(usedstuff[i])) {
	    		this_object()->unwear_ob(usedstuff[i]);
			} /* if (usedstuff.. */
    		} /* for.. */

    /* Let the corpse loose everything */
    /* But they won't loose it, can put it back later tho.. */
    /*
    obs = all_inventory(this_object());
    for (i=0; i<sizeof(obs); i++)
      obs[i]->move(environment());
    */

    	if (stringp(room_mess)) {
		tell_room(environment(this_object()),room_mess+".\n", this_object());
		tell_object(this_object(), my_mess+".\n");
    		}

    // AS for now, the corpse contains the remaining stuff.
    	all_inventory(this_object())->move(corpse);
    	corpse->move(environment());
    	return corpse;
	}

//? shouldnt need to call this... so make it static, just in case

void actual_death() {
    	object ob, ob2;
    // Radix made this so it didn't HAVE to create a corpse,
    // so creators could mask this in their NPCs
    // Feb. 28, 1996
    	object corp = make_corpse();

    //dw if second_life returns false... do stupid things...

    	if (!((int)this_object()->second_life())) {
		if(corp)  corp->move(environment(this_object()));
		ob = first_inventory(this_object());
		while(ob) {
	    		ob2 = next_inventory(ob);
	    		ob->dest_me();
	    		ob = ob2;
			}
		this_object()->dest_me();
    		}
	} /* void actual death */
