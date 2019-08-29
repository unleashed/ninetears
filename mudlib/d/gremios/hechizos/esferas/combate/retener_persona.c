// Traducido por Lummen '98

#include <spells.h>
inherit BASE_SPELL;

#define	NOMBRE	"Retener persona"
#define	NIVEL	3
#define	ESCUELA	({"encantamiento"})
#define	ESFERA	({"combate"})
#define	CANCION	"'amri xeno haltem'"
#define	TIPO	"magical"
#define SHADOW	SHADOWS+"hold_person_sh"

void setup()
{
  set_spell_name(NOMBRE);
  set_spell_level(NIVEL);
  set_sphere(ESFERA);
  set_school(ESCUELA);

  set_target_type("one");
  set_range(0);
  set_line_of_sight_needed(0);

  set_help_desc("Este hechizo crea una barrera invisible sobre el objetivo, previniendo "
    "que este ataque. Los objetivos fuertes puedes desembarazarse de su efecto.");

  set_gp_cost(NIVEL);
  set_casting_time(1);
  set_rounds(({"round1"}));
}

int round1(object caster, mixed target, mixed out_range, int time, int quiet)
{
  int duration;
  object shad;

  if (!target)
  {
    tell_object(caster,MSG_NO_TARGET);
    return -1;
  }
  
  if (caster->QP("RETENER_PERSONA"))
  {
    tell_object(caster,"Aun no puedes volver a formular este hechizo.\n");
    return -1;
  }
  caster->ATP("RETENER_PERSONA",1,50);

  if (target->query_time_spell())
  {
    target->dispell_time_spell();
    return 0;
  }

  if ( target->query_hold_spell() || target->query_pacify_spell() )
  {
    tell_object(caster,"Tu objetivo ya esta incapacitado.\n");
    return -1;
  }

  if (!quiet)
  {
    tell_room(ENV(caster),MSG_CAN_R,caster);
    tell_object(caster,MSG_CAN_C);
  }

  if (target->spell_saving_throw(caster,query_sphere()))
  {
    tell_object(caster,target->QCN+" resiste los efectos de tu hechizo!\n");
    tell_object(target,"Resistes los efectos del hechizo!\n");
    tell_room(ENV(caster),target->QCN+" resiste los efectos del hechizo.\n",({caster,target}));
    caster->attack_by(target);
    return 0;
  }

  tell_object(caster,"Paralizas a "+target->QCN+" mediante una fuerza invisible que le rodea.\n");
  tell_object(target, "Sientes como una fuerza invisible te rodea, frenando la posibilidad de cualquier movimiento.\n");
  tell_room(ENV(caster),caster->QCN+" acaba un hechizo con unos gestos y "+target->QCN+", es paralizado por una fuerza invisible.\n",({caster,target}));

  duration=-fix_damage(caster,target,-caster->QL/5);
  target->ATP("hold_person_on",1,duration);
  target->ATP("nocast",1,duration);
  target->ATP("noguild",1,duration);  
  shad=clone_object(SHADOW);
  shad->setup_shadow(target, caster); 
  target->add_extra_look(shad);
  target->attack_by(caster);
  return NIVEL*100;
}
