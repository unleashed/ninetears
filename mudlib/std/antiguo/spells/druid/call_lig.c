/*** Call Lightning ***/
/*** By Wonderflug ***/

inherit "/std/spells/base.c";

#define TYPE "electrical"
#define save_type "electrical"

void setup()
{
  set_spell_name("Call Lightning");
  set_spell_level(5);
  set_sphere("Druid");

  set_target_type("many");
  set_range(0);

  set_help_extras(
    "Damage Type: " TYPE "\n"
    "Saving Throw: 1/2");
  set_help_desc("This spell brings down the wrath of nature upon your foes. "
    "Lightning will lance out from even the clearest skies to strike "
    "your enemies for 8d8 hp damage.  Of course, the damage is "
    "greatly reduced indoors.");

  set_gp_cost(10);
  set_casting_time(1);
  set_rounds( ({ "round1" }) );
}

int round1(object caster, mixed target, mixed out_range, int time, int quiet)
{
  int i;
  int damage;
  int outside_flag;

  if ( sizeof(target) )
    target -= ({ caster });

  if ( !sizeof(target) )
  {
    tell_object(caster, "Alas, there is nobody here by that name.\n");
    return -1;
  }

  if ( !quiet )
  {
    tell_room(environment(caster),(string)caster->query_cap_name()+
      " clenches a fist heavenward, and the skies rumble in response.\n",
      ({ caster }) );
    tell_object(caster, "You clench your fist heavenward, and the skies "
      "rumble in response.\n");
  }

  tell_room( environment(caster), "A blinding bolt of lightning suddenly "
    "explodes into the room!\n");

  outside_flag = 0;
  if ( environment(caster)->query_outside() )
    outside_flag = 1;

  tell_object(caster, "The bolt forks into "+sizeof(target)+" lances of "
    "electricity, blasting into\n"+query_multiple_short(target)+".\n");
  tell_room(environment(caster), "The bolt forks into "+sizeof(target)+
    " lances of energy, blasting into\n"+query_multiple_short(target)+".\n",
    target + ({ caster }) );

  for ( i=0; i<sizeof(target); i++)
  {
    damage = roll(8, 8);
    damage = cleric_fix_damage(caster, target[i], damage, save_type);
    if (outside_flag) 
      damage = damage/(random(3)+2);
    target[i]->spell_damage(target[i], damage, TYPE, caster);
    target[i]->attack_by(caster);
    tell_object(target[i], "Pain spasms through your body as the bolt "
      "forks and blasts into you.\n");
  }

  return 0;
}
