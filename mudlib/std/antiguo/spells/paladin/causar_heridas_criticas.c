/*** Cause Critical Wounds Spell ***/
/*** Created by Eerevann Tokani ***/
/*** ->base spell by Wonderflug ***/

inherit "/std/spells/base.c";

#define TIPO "magico"
#define SALV "magico"

void setup()
{
  set_spell_name("Causar Heridas Criticas");
  set_spell_level(5);
  set_sphere("healing");

  set_target_type("one");
  set_range(0);
  set_line_of_sight_needed(0);

  set_help_extras(
    "Tipo de Danyo: " TIPO "\n"
    "Tirada de Salvacion: Ninguna");
  set_help_desc("This spell will do 3-24 + 2 points of damage to an enemy "
    "of your choice.  The spell, once cast, requires the caster to touch the "
    "target.  If the touch misses, the spell's energy is wasted.");

  set_gp_cost(10);
  set_casting_time(1);
  set_rounds( ({ "round1" }) );
}


int round1(object caster, mixed target, mixed out_range, int time, int quiet)
{
  int damage;
  int ac_hit;

  if ( wrong_alignment(caster) )
  {
    punish_align(caster);
    return -1;
  }

  if (!target)
  {
    tell_object(caster,
      "No hay nadie aqui con ese nombre.\n");
    return -1;
  }

  if(target == caster)
  {
    tell_object(caster, "Tendencias suicidas?\n");
    tell_room(environment(caster), (string)caster->query_cap_name()+
      " para de formular un hechizo.\n",caster);
    return -1;
  }

  if ( !quiet )
  {
    tell_room(environment(caster), (string)caster->query_cap_name()+
      " pronuncia el cantico 'magius criusis harmei'.\n", ({target,caster}));
    tell_object(caster, "Pronuncias el cantico 'magius criusis harmei'.\n");
  }

   
  ac_hit = (int)caster->query_thac0() - random(200) - 1;
  if((random((int)caster->query_thac0()) + target->query_total_ac()) > 0)
  {
    tell_object(target, (string)caster->query_cap_name()+
      " se acerca a ti y te toca provocandote cortes "
      "criticos.\n");
    tell_object(caster, "Te acercas a "+
      (string)target->query_cap_name() + " y le tocas provocandole "
      "cortes criticos.\n");
    tell_room(environment(caster), (string)caster->query_cap_name()+
      " se acerca a "+target->query_cap_name()+" y le toca provocandole "
      "cortes criticos.\n",
      ({target,caster}) );
  } 
  else 
  {
    tell_object(target, (string)caster->query_cap_name()+
      " se acerca a ti e intenta tocarte, fallando.\n");
    tell_object(caster, "Te acercas a "+
      (string)target->query_cap_name() + " e intentas tocarle, fallando.\n");
    tell_room(environment(caster), (string)caster->query_cap_name()+
      " se acerca a "+target->query_cap_name()+
      " e intenta tocarle, fallando.\n",
      ({target,caster}) );
    return 0;
  }
  


  damage = roll( 3, 8 );

  damage = cleric_fix_damage(caster,target,damage,SALV);
  target->adjust_hp(-damage);

  target->attack_by(caster);

  return 0;
}
