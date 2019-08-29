/* summon_base.c
  Taniwha 1996
*/

inherit "/std/spells/base.c";
string type = "undead";
string base_dir = "/obj/chars/";
string * npcs = ({ "skeleton","skeleton","ghoul","zombie","zombie","wraith","spectre"});

void setup()
{
    set_spell_name("summon undead");
    set_spell_level(20);
    set_sphere("necromantic");

    set_target_type("none");
    set_range(0);
    set_line_of_sight_needed(0);

    set_help_desc(
      "This is the base summoning spell, you shouldn't GET this message "
      "because it should have been changed already, but it summons "
      "something which will beat up on anything currently "
      "attacking you.\n"
    );
set_gp_cost(10);
set_casting_time(2);
set_rounds( ({ "round1", "round2" }) );
}

int round1(object caster, mixed target, mixed out_range, int time, int quiet)
{
    tell_object(caster, "You begin your appeal with a chant "
      "\n");
    tell_room(environment(caster), caster->query_cap_name()+" begins a chant."
      "\n", caster);
    return 0;
}

int round2(object caster, mixed target, mixed out_range, int time, int quiet)
{
   int i,j;
    string npcfile;
    object npc;
    object *atts;
    tell_object(caster, "Your chanting becomes a shout !"
      ".\n");
    tell_room(environment(caster), caster->query_cap_name()+"'s chant "
      "grows louder, becoming a shout!.\n", caster);
    atts = caster->query_attacker_list()+caster->query_call_outed();
    atts -= ({ 0 });;
    if(!sizeof(atts))
    {
	tell_object(caster,"You just don't feel threatened, your spell fails.\n");
	return 0;
    }	  
    for(i = 0;i < (caster->query_cha()/10)+1; i++)
    {
	npcfile = base_dir + npcs[random(sizeof(npcs))];
	npc = clone_object(npcfile);
	if(!npc) continue;
	npc->set_aggressive(0);
	caster->set_protector(npc);
	npc->move(environment(caster));

	tell_room(environment(caster),
	  "A rip appears in the fabric of space and a "+
	  npc->query_short()+" comes to "+
	  caster->query_cap_name()+"'s aid.\n",caster);
   npc->set_friend(caster);

   tell_object(caster,"A "
	  +npc->query_short()+" comes to your aid.\n");

	for(j = 0; j < sizeof(atts); j++)
	{
	    npc->attack_ob(atts[j]);
	}

    }			
    return 0;
}

