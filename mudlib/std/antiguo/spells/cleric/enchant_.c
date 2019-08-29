/* Spell coded by Cobra*/
inherit "/std/spells/base.c";

void setup()
{
  set_spell_name("Enchant weapon");
  set_spell_level(3);
  set_sphere("combat");

  set_target_type("item");
  set_range(0);
  set_line_of_sight_needed(0);

  set_help_desc("This spells gives the weapon a bonus to damage in "
    "battle for a limited duration.");

  set_gp_cost(6);
  set_casting_time(1);
  set_rounds( ({ "round1" }) );
}

int round1(object caster, mixed target, mixed out_range, int time, int quiet)
{
  int level;

  if (!present(target,this_player()))
  {
    tell_object(caster,
      "Your spell failed ... There is no item with that name here.\n");
    return -1;
  }
  if(!target->query_weapon())
  {
    tell_object(caster,"Your spell failed ... You need to cast it on "
                       "a weapon!\n");
    return -1;
  }
  if (target->query_property("enchant_weapon"))
  {
    tell_object(caster,
      "The weapon is already under the effects of the enchant weapon "
      "spell.\n");
    return 0;
  }
    
  if ( !quiet )
  {
    tell_room(environment(caster),(string)caster->query_cap_name()+
      " chants, 'amenis unos weaponis'.\n", ({caster}));
    tell_object(caster, "You chant, 'amenis unos weaponis'.\n");
  }


  
  target->add_static_property("enchant_weapon", 1);
  target->adjust_enchant(2);

  level = (int)caster->query_level();
  switch( caster->query_sphere_power("combat") )
  {
    case "minor":
      level -= 5;
      break;
    case "major":
      level += 5;
      break;
  }
  call_out("wear_off",100+(level*5));
  return 0;
}

void wear_off(object target, object caster)
{
  if(target)
  {
    target->adjust_enchant(-2);
    target->remove_static_property("enchant_weapon");
    tell_object(this_player(), "The magical glow dissapears from the weapon.\n");
  }
}
