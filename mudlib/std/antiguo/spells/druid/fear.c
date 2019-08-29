/** This is NOT a Rnager spell, pure druidic. **/
/*** Fear Spell ***/
/*** Coded by:  Taniwha ***/
/*** NPC/bard spell ***/

#define TYPE "fear"
#define save_type "psionic"

inherit "/std/spells/base.c";

void setup()
{
    set_spell_name("Fear");
    set_spell_level(5);
    set_school("invocation");

    set_target_type("many");
    set_range(0);
    set_line_of_sight_needed(0);

    set_help_extras(
      "Damage Type: " TYPE "\n"
      "Saving Throw: Psionic");
    set_help_desc("This spell will make everyone in the area who doesn't "
      " save against the spell afraid for a period of time of "
      "two rounds/level of the caster.\n"
      "How afraid depends to some extent on the level and charisma of "
      "the targets and how resistant to psionic attacks the victims are.\n");

    set_gp_cost(10);
    set_casting_time(1);
    set_rounds( ({ "round1" }) );
}

int round1(object caster, mixed target, mixed out_range, int time, int quiet)
{
    int damage;
    int i;
    string str;

    /* to remove the caster, if he uses 'all' */
    if((i = member_array(caster, target)) != -1)
	target = delete(target, i, 1);

    if(!sizeof(target)) 
    {
	tell_object(caster, "There is noone here by that name.\n");
	return -1;
    }

    if ( !quiet )
    {
	tell_room(environment(caster), "A wave of blackness rolls "
	  "outwards from "+caster->query_cap_name()+".\n\n", 
	  ({ caster, target }) );
	tell_object(caster, "You call upon the gods "
	  "before the gods and a wave "
	  "of silver light rolls away from you.\n");
    }

    for ( i=sizeof(target)-1; i>=0; i-- )
    {
	target[i]->attack_by(caster);
	damage = roll(3, caster->query_cha());
	if(damage > 100) damage = 100;	
	damage = wiz_fix_damage(caster,target[i],damage,save_type);
	if(damage > 99) damage = 99;
	target[i]->add_timed_property("fear",
	  damage,2*(int)caster->query_level());	
	tell_object(target[i],"The dark phantasm summoned "
	  "by "+ caster->query_cap_name()+ 
	  " overwealms you as terrors conjured from a time "
	  "beyond time strike the "
	  "depths of your soul.\n");
	target[i]->set_wimpy(99);	
	if(!target[i])
	    target = delete(target, i, 1);
    }

    tell_room(environment(caster), caster->query_cap_name() + 
      " envelopes "+(str = query_multiple_short(target))+
      " within an aura of darkest terror\n", ({caster,target}));
    tell_object(caster, "You envelope " + str + " in a aura "
      "of uttermost horror!\n");

    return 0;
}
