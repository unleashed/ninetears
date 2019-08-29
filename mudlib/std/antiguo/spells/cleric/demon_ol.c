/*** Demon Howl Spell ***/
/*** Lucius Santino ***/
/*** ->base spell by Wonderflug ***/

inherit "/std/spells/base.c";

#define TYPE "evil"
#define SIZE_OF_DICE 3
#define save_type "evil"

void setup()
{
  set_spell_name("Demon Howl");
  set_spell_level(5);
  set_sphere("necromantic");

  set_target_type("many");
  set_range(0);
  set_line_of_sight_needed(0);

  set_help_extras(
    "Damage Type: " TYPE "\n"
    "Saving Throw: 1/2");
  set_help_desc("This spell causes the caster to emit"
		" a horrifying howl, the sound of which is heavily"
		" laced with demonic energies.  Targets"
		" suffer damage from the excruciating"
		" pain of the powerful sonic attack.  The Priest"
		" can not channel the energies required for"
		" spellcasting for a short time after using"
		" this spell.  Furthermore, the chaotic nature of"
		" the forces using the caster as a conduit is such"
		" that all knowledge of the spell \"Heal\" is lost.\n");
 
	set_gp_cost(8);
  set_casting_time(1);
  set_rounds( ({ "round1" }) );
}


int round1(object caster, mixed target, mixed out_range, int time, int quiet)
{
  int i;
  int damage;
  int NO_OF_DICE;

  switch( caster->query_sphere_level("necromantic") )
  {
    case "major":  
	NO_OF_DICE=15;
      break;
    case "minor": 
	NO_OF_DICE=15-random(10);
      break;
    default:
	NO_OF_DICE=15;
  }

 
for(i=0;i<sizeof(target);i++)
{
	if(!living(target[i]) || !target[i]->query_alive())
	  continue;


if(target[i] == caster)
  { 
    tell_object(target, "Wouldn't that be suicide?\n");
    tell_room(environment(caster),(string)caster->query_cap_name()+
	" stops casting.\n", target[i]);
    return -1;
  }
    

if((int)caster->query_timed_property("howl_cast")==1)
  {
    tell_object(caster, "You are not yet able to cast this spell again.\n");
    return -1;
  }
  if ( !quiet )
  {
    tell_room(environment(caster),(string)caster->query_cap_name()+
	" chants, 'kyrnie ov daemon'.\n", ({target[i], caster}));
   tell_object(caster, "You chant, 'kyrnie ov daemon'.\n");
  }

   tell_object(target[i], (string)caster->query_cap_name()+
	" throws back "+caster->query_possessive()+" head, emitting"
	" a piercing howl, the noise of which batters at your"
	" senses!\n");
   
   tell_object(caster, "You finish your spell, and feel the familiar"
	" energies course through you, until a terrible howl erupts"
		" from within, battering your targets!\n");
   
  tell_room(environment(caster),(string)caster->query_cap_name()+
	" throws back "+this_player()->query_possessive()+" head and emits"
		" a piercing howl, the sound of which batters"
	" "+target[i]->query_cap_name()+".\n", ({target[i], caster}));


  damage = 0;
  damage = roll(NO_OF_DICE, SIZE_OF_DICE);
  damage = target[i]->spell_saving_throw(target[i],damage,save_type);
  damage = cleric_fix_damage(caster, target[i], damage, TYPE);
  target[i]->adjust_hp(-damage, caster);
  target[i]->attack_by(caster);
   caster->add_timed_property("stillcasting",1, random(3));
    caster->remove_spell("heal");
  caster->add_timed_property("howl_cast",1, random(15));

}
  return 0;
}
