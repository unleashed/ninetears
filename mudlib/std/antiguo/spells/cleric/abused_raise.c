// Abused spell by Radix ..
// remove_spell("raise dead") and then
// add_spell("raise dead", "abused_raise")
// ie, replaces the bastards raise dead spell with this void spell


inherit "/std/spells/base.c";

void setup()
{
  set_spell_name("Raise Dead");
  set_spell_level(5);
  set_sphere("necromantic");

  set_target_type("one");
  set_range(0);
  set_line_of_sight_needed(0);

   set_help_desc("This spell has been made void by your god.  "
    "You have obviously abused its powers and your diety is REALLY "
     "angered.");

  set_gp_cost(30);
  set_casting_time(1);
  set_rounds( ({ "round1" }) );
}
 

int round1(object caster, mixed target, mixed out_range, int time, int quiet)
{
   tell_object(caster,"You chant some weak words but your diety doesn't answer in return.\n");

   tell_object(caster,"Perhaps reading the help for the spell may help.\n");

   tell_room(environment(caster),caster->query_short()+" attempts to cast a spell "
      "but failed miserably.\n");

   return 0;
}
