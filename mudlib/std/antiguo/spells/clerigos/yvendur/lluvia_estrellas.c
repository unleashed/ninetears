/*** Shooting stars Spell ***/
/*** Coded by:  Wonderflug ***/

#define TYPE "magical"
#define SIZE_OF_DICE 6
#define save_type "spells"

#include "weather.h"

inherit "/std/spells/base.c";

void setup()
{
  set_spell_name("Lluvia de estrellas");
  set_spell_level(7);
  set_sphere("astral");

  set_target_type("many");
  set_range(0);

  set_help_extras(
    "Tipo de Danyo: " TYPE "\n"
    "Tirada de salvacion: 1/2");
  set_help_desc("Este hechizo envuelve a un grupo de enemigos en una lluvia "
    "de estrellas que caen del cielo. El numero de estrellas que caen depende del "
    "nivel del clerigo.  Este hechizo solo es util por las noches y al aire libre.");

  set_gp_cost(28);
  set_casting_time(3);
  set_rounds( ({ "round1", "round2", "round3" }) );
}


int round1(object caster, mixed target, mixed out_range, int time, int quiet)
{
  tell_object(caster, "Levantas tus manos hacia el cielo nocturno, cantando "
    "un complicado ritual simbolico.\n");
  tell_room(environment(caster), caster->query_cap_name()+
    "levanta sus manos hacia el cielo de la noche, "
    "cantando una especie de ritual que le lleva a un trance profundo.\n", caster);

  return 0;
}

int round2(object caster, mixed target, mixed out_range, int time, int quiet)
{
  tell_room(environment(caster), "Varias estrellas aparecen de repente moviendose "
    "en el cielo..\nParece que estan a punto de caer..\n", ({ }));

  return 0;
}

int round3(object caster, mixed target, mixed out_range, int time, int quiet)
{
  int num_dice, damage;
  int i, j;

   if(!environment(caster)->query_outside()&&!caster->query_static_property("stars_on"))
  {
    tell_object(caster, "Este hechizo solo puede formularse al aire libre.\n");
    return -1;
  }

   if(WEATHER->query_day(environment(caster))&&!caster->query_property("stars_on"))
  {
    tell_object(caster, "No pueden caer estrellas durante el dia !\n");
    return -1;
  }

  if ( !quiet )
  {
    tell_object(caster,"Cantas, 'astra nova pyris'.\n");
    tell_room(environment(caster),caster->query_cap_name()+ 
      " canta, 'astra nova manus'.\n", caster);
  }

  if ( !sizeof(target) )
  {
    tell_object(caster, "No hay nadie aqui con ese nombre.\n");
    return -1;
  }

  num_dice = (int)caster->query_level();

  if(num_dice == 0)
    num_dice = 1;

  tell_object(caster,"Comienzas a rezar a Yvendur y varias estrellas "
    "caen desde el cielo empicado hacia donde estas!\n");
  tell_room(environment(caster),caster->query_cap_name()+" reza "
    "fervientemente y de repente varias estrellas comienzan a descender\n"
    "del cielo a gran velocidad hacia donde tu estas..\n", caster);

  for ( i = 0; i < sizeof(target); i++ )
  {
    if (!living(target[i]) || !target[i]->query_alive()) 
      continue;
    target[i]->attack_by(caster);
    damage = 0;
    damage = roll(num_dice, SIZE_OF_DICE);
    damage = target[i]->spell_saving_throw(target[i],damage,save_type);
    damage = cleric_fix_damage(caster,target[i],damage,TYPE);
    if ( target == caster )
    {
      tell_object(caster, "Oops, una estrella te golpea!  Deberias ser mas cuidadoso "
        "la proxima vez!\n");
      tell_room(environment(caster), caster->query_cap_name()+" chilla y maldice "
        "al ser golpeado por una estrella caida del cielo!\n", caster);
    }
    else switch( damage )
    {
      case 0..10:
        tell_room(environment(caster), target[i]->query_cap_name()+
	  " es quemado por una estrella que acaba de caer.\n", target[i] );
        tell_object(target[i], "Eres quemado por una estrella caida del cielo.\n");
        break;
      case 11..30:
        tell_room(environment(caster), "Una estrella fugaz golpea a "+
	  target[i]->query_cap_name()+", quemandole "
          "severamente.\n", target[i]);
        tell_object(target[i], 
          "Una estrella fugaz te golpea y te quemas bajo la explosion.\n");
        break;
      case 31..80:
        tell_room(environment(caster), target[i]->query_cap_name()+
	  " es incinerado por una gigantesca estrella "
	  "caida del cielo.\n", target[i]);
        tell_object(target[i], "Eres incinerado por una estrella caida del cielo.\n");
        break;
      case 81..150:
        tell_room(environment(caster), target[i]->query_cap_name()+
	  " es demolido y su cuerpo arrasado por una estrella dorada.\n", target[i]);
        tell_object(target[i], "Una estrella dorada caida del cielo te arrasa el cuerpo "
	  "demoliendote los huesos.\n");
        break;
      case 151..10000:
        tell_room(environment(caster), "Una estrella fugaz embiste con "
	  " britalidad sobre "+target[i]->query_cap_name()+" y "
	  " es inmolado bajo una enorme explosion de rocas y fuego.\n",
	  target[i]);
        tell_object(target[i], "Una estrella fugaz te envuelve y eres "
	  "inmolado por una gran explosion de rocas y fuego.\n");
        break;
      default:
        tell_room(environment(caster), target[i]->query_cap_name()+
	  " milagrosamente ha esquivado una estrella fugaz caida del cielo.\n", target[i]);
        tell_object(target[i], "Esquivas una estrella que cae del cielo.\n");
    }
    target[i]->adjust_hp(-damage,caster);
  }

  return 0;
}
