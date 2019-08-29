inherit "/std/races/standard";
#include "light_defs.inc"

// and you always wondered why they hated water
int query_swim_stamina(object player) { return 0; } // glug
int query_underwater_breathing(object player) { return 0; } // die

void setup() 
{
    set_long("A dark mysterious figure with very red lips and long sharp teeth.\n");
    set_name("vampire");
    set_light_limits(-100,50);
    reset_get();
}

void set_racial_bonuses() 
{
    previous_object()->adjust_bonus_str(5);
    previous_object()->adjust_bonus_con(-5);
    previous_object()->adjust_bonus_dex(-5);
    previous_object()->adjust_bonus_int(5);
    previous_object()->adjust_bonus_cha(5);
}

int query_skill_bonus(int lvl, string skill) 
{
    return 0;
}

string query_desc(object ob) 
{
    return
    "A dark and menacing form, yet somehow strangely compelling.";
}
void race_heartbeat(object player)
{
    object *list;
   object wraith;
    int i;
    if(!player) return;
    if(!ENV(player)) return;
    if(player->query_dead())
    {
   player->remove_static_property("noregen");
	return;
    }
    list = all_inventory(ENV(player));
   list -= ({ player });
    for(i = 0; i < sizeof(list); i++)
    {
	if(list[i]->query_hp() > 5)
	{
	    if(list[i]->query_property("evil")) // resist evil
	    {
		player->adjust_hp(-4,list[i]);
	    }
	    else
	    {
		list[i]->adjust_hp(-2,player);
		player->adjust_hp(2,list[i]);
		list[i]->adjust_gp(-2);
		player->adjust_gp(2);
	    }
	}
    }
    if(ENV(player)->query_property("no_undead"))
    {
      tell_object(player,"Some terrible force in the area fills your "
        "dark heart with fear.\n");
      player->run_away();
    }

    if(ENV(player)->query_outside() && ENV(player)->query_light() > 30 )
    {
	player->adjust_hp(-20,player);
    }
    player->adjust_hp(-1,player);
    if(player->query_hp() < 5)
    {
	wraith = clone_object("/std/spells/wizard/waithform_sh.c");
	wraith->setup_shadow(player);
	player->remove_static_property("noregen");
    }
   if(!player->query_hide_shadow())
   {
   wraith = clone_object("/std/commands/shadows/hide");
   wraith->setup_shadow(player);
   }
  ::race_heartbeat(player);
}
void start_player(object player)
{
   object ob;
   player->add_static_property("undead",50);
    player->add_static_property("noregen",1);
   player->add_static_property("magical",200);
    tell_object(player,"You must find life, and soon, or die.\n");
  catch( ob = clone_object("/std/races/shadows/cloak_darkness"));
    if(ob) ob->move(player);
    ::start_player(player);
}
