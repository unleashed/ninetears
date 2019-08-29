/*** By Wonderflug ***/

inherit "/std/spells/base.c";
#include "tweaks.h"

void setup() 
{
  set_spell_name("Fumble");
  set_spell_level(4);
  set_school("necromancy");

  set_target_type("one");
  set_range(2);
  set_line_of_sight_needed(1);

  set_help_desc("Este hechizo consigue debilitar las manos del objetivo "
    "hasta el punto de hacer caer todo aquello que llebe en sus manos, "
    "ya sean armas, escudos o todo aquel equipo que sea posible llevar en las "
    "manos. teniendo en cuenta que aquellos que sean mas habilidosos y "
    "expertos que tu no sufriran el poder de tu hechizo.\n");

  set_casting_time(1);
  set_gp_cost(FUMBLE_GP_COST);
  set_rounds( ({ "round1" }) );
}


int round1(object caster, mixed target, mixed out_range, int time, int quiet)
{
  object* ob;
  object* ob2;
  int caster_level; 
  int target_level;
  int caster_int; 
  int target_dex;
  int caster_roll; 
  int target_roll;
  int i, j;

  if ( !target )
  {
    tell_object(caster, 
      "Tu hechizo falla ... nadie con ese nombre esta aqui.\n");
    return -1;
  }

  if ( !quiet )
  {
    tell_room(environment(caster), (string)caster->query_cap_name()+
      " chants, 'mantequitis digitis transformatis'.\n", caster);
    tell_object(caster, "You chant, 'mantequitis digitis transformatis'.\n");
  }

  caster_level = (int)caster->query_level();
  target_level = (int)target->query_level();
  caster_int = (int)caster->query_int();
  target_dex = (int)target->query_dex();

  caster_roll = random(FUMBLE_CASTER_ADJ*(caster_level+caster_int));
  target_roll = target_level+
    random(FUMBLE_TARGET_ADJ*(target_level+target_dex));

  if ( caster_roll > target_roll )
  {
    tell_object(caster, "Debilitas las manos de "+target->query_short()+
      ", y sus armas caen al suelo.\n");
    tell_object(target, caster->query_short()+
      " Notas como pierdes momentaneamente la fuerza en las manos, "
      " y no puedes soportar el peso de tus armas.\n");
    tell_room(environment(target), caster->query_short()+
      " termina su hechizo con unos gestos sobre las manos de "+target->query_short()+
      ".\n", ({ caster, target }) );
  }
  else
  {
    tell_object(caster, "Pronuncias el cantico sobre "+target->query_short()+
      ", pero no parece enterarse.\n");
    tell_object(target, caster->query_short()+
      " intenta hechizarte pero no parece que lo consiga.\n");
    tell_room(environment(target), caster->query_cap_name()+
      " pronuncia un cantico sobre "+target->query_cap_name()+
      ", pero no parece que pase nada.\n", ({ caster, target}) );
    return 1;
  }

  /* kludge since drop_ob notifies the caster of items dropping, not the
   * the target.  no way around except to rewrite drop_ob HERE, which is
   * an even worse kludge, i think.  -- wonderflug
   */
  caster_roll = target_roll+10;

  switch( caster_roll - target_roll )
  {
    case 1..20:
      ob = (object*)target->query_held_ob();
      for (i=0;i<sizeof(ob);i++)
        if ( ob[i] )
          target->unhold_ob(ob[i]);
      break;
    default:
      ob = all_inventory(target);
      ob2 = (object*)target->query_worn_ob();
      for (i=0;i<sizeof(ob);i++)
        if ( member_array(ob[i], ob2) == -1 )
          target->drop_ob(ob[i]->query_name());
      break;
  }

  // Make monsters attack sometimes (well, ok, often)
  if ( !interactive(target) && random(4) )
    target->attack_by(caster);
  
  return 0;
}
