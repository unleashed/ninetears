/*** Sticks to Snakes -- Druids Spell ***/
/*** By Wonderflug ***/

#include "tweaks.h"

inherit "/std/spells/base.c";

#define SP_NAME "Sticks to Snakes"
#define GP_COST STICK_GP
#define SPELLTYPE "offensive"

void setup()
{
  set_spell_name("Sticks to Snakes");
  set_spell_level(2);
  set_sphere("druid");

  set_target_type("none");
  set_range(0);

  set_help_desc("This spell will turn all sticks in the Druid's inventory "
    "into snakes.  The maximum number of sticks that can be transformed "
    "is one per 3 levels of the druid.  The snakes will defend the "
    "Druid until all attackers have either fled or been killed, or "
    "the Druid herself is killed or leaves.  Once any of these "
    "conditions have been met, the snakes "
    "will return to their natural homes, living out the normal life of a "
    "snake.  The sticks cannot be recovered.");

  set_gp_cost(STICK_GP);
  set_casting_time(3);
  set_rounds( ({ "round1", "round2", "round3" }) );
}

int round1(object caster, mixed target, mixed out_range, int time, int quiet)
{
  tell_object(caster, "You draw in power from the world for your "
    "enchantment.\n");
  tell_room(environment(caster), caster->query_cap_name()+" goes into "
    "an odd trance-like state.\n", caster);
  return 0;
}

int round2(object caster, mixed target, mixed out_range, int time, int quiet)
{
  tell_object(caster, "You throw several sticks down on the ground.\n");
  tell_room(environment(caster),caster->query_cap_name()+
    " throws several sticks down on the ground.\n", caster );
  return 0;
}

int round3(object caster, mixed target, mixed out_range, int time, int quiet)
{
  object* ob;
  int i, j;
  object snake;

  ob = find_unique_match(STICKNAME, caster);
  if (!sizeof(ob))
  {
    tell_object(caster, "You don't have any sticks.\n");
    tell_room(environment(caster), caster->query_cap_name()+" stares blankly "
      "at the sticks.\n", caster);
    return -1;
  }

  tell_object(caster, "You transform the sticks into small but vicious "
    "snakes.\n\nThe snakes start attacking your enemies.\n");
  tell_room(environment(caster), "The sticks suddenly morph into snakes "
    "and protect "+caster->query_cap_name()+"!\n", caster);

  i = (int)caster->query_level() / 3;
  i = ( i > sizeof(ob) ? sizeof(ob) : ( i <= 0 ? 1 : i ));

  for (j=0; j < i; j++)
  {
    snake = clone_object(SNAKE);
    snake->set_spell(caster);
    ob[j]->dest_me();
  }

  return 0;
}
