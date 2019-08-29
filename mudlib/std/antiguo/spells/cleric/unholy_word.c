/* Santino '96 */
/* Unholy Word is a spell by which evil clerics can 'strike down' their
opponents, calling upon their god(ess)' power to brand the target
with the holy symbol of the deity.  This 'brand' reduces the
target's ability to function... he/she is flooded with lethargy
and fear, making even the simplest application of guild or
spell abilities difficult.  Furthermore, until the symbol
has been removed, (by a dispel magic spell [maybe], or over a period
of time), the target is unable to regen HPs *or* GPs. */
 
#include "tweaks.h"

inherit "/std/spells/base.c";
inherit "/std/spells/cleric/UD_query.c";

#define UNHOLY_OBJ "/std/spells/cleric/unholy_obj.c"
#define UNHOLY_GP 30
#define UNHOLY_LEVELX 6
#define UNHOLY_DURATION_LEVELX 6


void setup()
{ 
  set_spell_name("Unholy Word");
  set_spell_level(UNHOLY_LEVELX);
  set_sphere("necromantic");

  set_target_type("one");
  set_range(0);

  set_help_desc("This powerful spell calls down the full power"
		" of "+this_player()->query_guild_name()+" upon"
		" an opponent.  Targets struck by the unholy word"
		" lose a portion of their strength, and are thereafter"
		" unable to regenerate HPs or GPs until the spell"
		" has been lifted.  The dread power of this spell is"
		" such that the caster must be attuned solely to"
		" the destructive nature of his/her deity."
		"  Consequently, the spell heal will be wiped from"
		" the caster's mind.  Equally important, the caster must"
		" be within the Underdark, their deity's"
		" base of power, for this prayer to be heard.\n");

  set_gp_cost(UNHOLY_GP);
  set_casting_time(2);
  set_rounds( ({ "round1", "round2" }) );
}

int round1(object caster, mixed target, mixed out_range, int time, int quiet)
{

  tell_room(environment(caster), "A dark cloud gathers about"
	" "+caster->query_cap_name()+", its depths flickering with"
		" crimson lightning.\n", ({ }) );
  return 0;
}


int round2(object caster, mixed target, mixed out_range, int time, int quiet)
{
  object ob;
  int resist;
  int theroll;
  int here;
  int i;
  int has_symbol;
  mixed symbol;
  string faith;
  object WHO = this_player();
  here = where_me(WHO);
  faith = (string)target->query_guild_name();
  symbol = find_match("holy symbols", target);

	if(here==0)
	{
		tell_object(this_player(), "You are too far from the"
			" Underdark for your deity to aid you.\n");
		call_out("cast_end", 0);
		return -1;
	}

  if ( !target )
  {
    tell_object(caster,
      "Your spell failed ... there is nobody of that name here.\n");
    return -1;
  }

   if ( target->query_property("unholy_on") )
  {
	tell_object(caster, "Your target has already been struck with"
		" an Unholy Word.\n");
    return 1;
  }

  if ( !quiet )
  {
	tell_object(caster, "You chant 'xysiargin'.\n\n");
    tell_room(environment(caster),(string)caster->query_cap_name()+
	" chants, 'xysiargin'.\n\n", ({ caster }));
  }

  resist = (int)target->query_property("magical");
  theroll = 20 + random(80);

  if(sizeof(symbol))
  {
    has_symbol = 0;
    for(i=0;i<sizeof(symbol);i++)
      if((string)symbol[i]->query_property("faith") == faith)
      {
        resist = resist + 50;
          if(resist > 100) { resist = 100; }
      }
  }

  if(theroll < resist) 
  {
    tell_object(caster, "You point at "+target->query_cap_name()+" but "
      "nothing seems to happen!\n");
    tell_object(target,caster->query_cap_name()+" completes the spell, "
      "and points at you but nothing seems to happen!\n");
    tell_room(environment(caster),caster->query_cap_name()+" completes the "
      "spell and points at "+target->query_cap_name()+" but nothing "
      "seems to happen!\n", ({ caster, target }) );
    return 0;
  }
 
   ob = clone_object(UNHOLY_OBJ);
  ob->set_get();
  ob->move(target);
  ob->reset_get();
  ob->reset_drop();

	target->set_no_heal();
	target->add_extra_look(ob);
	target->add_static_property("noregen",1);
	target->add_timed_property("unholy_on",1,
	(int)caster->query_level() * UNHOLY_DURATION_LEVELX);

if(target->query_str() > 6)
{
  target->adjust_temp_str(-3);
}

  tell_room(environment(caster), target->query_cap_name()+" is"
	" thrown back by a violent burst of magical energy,"
	" "+capitalize(caster->query_guild_name())+"'s Symbol"
	" burned into "+target->query_possessive()+" forehead.\n",
	({ caster, target }) );
  tell_object(caster, "You cast Unholy Word at "+target->query_cap_name()+
	" and "+capitalize(caster->query_guild_name())+"'s symbol"
	" brands itself upon "+target->query_possessive()+
	" forehead!\n");
  tell_object(target, caster->query_cap_name()+" completes the spell, "
	"and you feel unholy energies tearing into your flesh,"
	" branding you with the symbol of"
	" "+capitalize(caster->query_guild_name())+"!\n");

  target->attack_by(caster);
  caster->remove_spell("heal");
}

void cast_end()
{
	tell_room(environment(this_player()),
		this_player()->query_cap_name()+" stops casting.\n",
		this_player());
	return 1;
	}
