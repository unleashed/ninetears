#include <spells.h>
inherit BASE_SPELL;

#define	NOMBRE	"Resurreccion"
#define	NIVEL	7
#define	ESCUELA	({"necromancia"})
#define	ESFERA	({"necromantica","lummen"})
#define	CANCION	""

void setup()
{
  set_spell_name(NOMBRE);
  set_spell_level(NIVEL);
  set_sphere(ESFERA);
  set_school(ESCUELA);
  set_target_type("one");
  set_range(0);
  set_line_of_sight_needed(0);
  set_help_desc("Este hechizo resucita a alguien que este muerto. "
    "Lo bueno de este hechizo es que no deja tan debilitado al objetivo "
    "como el de levantar muertos. Al igual que todos los hechizos de vida, "
    "debes de tener el consentimiento de la victima para traerle de vuelta "
    "a este mundo.\n"
   "El nivel del hechicero influye en el exito de este hechizo, al igual "
   "que el de la victima. A mas diferencia de niveles entre el hechicero y "
   "la victima, menos probabilidad de perder constitucion.\n");
  set_gp_cost(NIVEL);	// 20 antes
  set_casting_time(1);
  set_rounds(({"round1"}));
}

int round1(object caster, mixed target, mixed out_range, int time, int quiet)
{
  int suerte;

  if (!target)
  {
    tell_object(caster,MSG_NO_TARGET);
    return -1;
  } 

  if (!target->query_dead())
  {
    tell_object(caster,target->QCN+" no esta muerto ... aun.\n");
    return -1;
  }

  if (target->query_property("noregen"))
  {
    tell_object(caster,"La Muerte te dice: ESPERA, AUN NO HE TERMINADO.\n");
    return -1;
  }

  if (!target->query_consent("resurrection"))
  {
    tell_object(caster,"El fantasma no desea volver a la vida por el momento. (ver 'help consent')\n");
    return -1;
  }

  tell_object(caster,"Haces un llamamiento a los dioses para hacer regresar a "+target->QCN+" del mas alla y un gran relampago cae del cielo y va a parar a la figura espectral de "+target->QCN+".\n");
  tell_object(target,caster->QCN+" invoca a los dioses y de repente un gran relampago cae sobre ti. No parece doler.\n");
  tell_room(ENV(caster),caster->QCN+" levanta la cabeza hacia el cielo y oyes un estruendo en la distancia. De repente un gran relampago cae del cielo y va a parar a "+target->QCN+", restaurandole a su forma material.\n",({caster,target}));
  target->remove_ghost();

  suerte=caster->query_cha()*POWER-15+ENV(caster)->query_santuario()*caster->QL;
  suerte=fix_damage(caster,target,suerte);
  if((caster->query_guild_name() == "Cleriga de Lloth" && target->query_race_name() == "Drow") && 
    random(100)>5 && caster->query_level()>9)
  {
    target->RAP("OMIQ_KILLED");
    target->adjust_con(1);
  }
  else if (target->QL>9 && (target->QP("OMIQ_KILLED") || caster->QP("no_fallar_resurrect") 
       || random(caster->QL+suerte)>random(target->QL)))
  {
    target->RAP("OMIQ_KILLED");
    if(target->query_race_name() != "Drow") 
       target->adjust_con(1);
  }
  log_file("RESURRECT",caster->query_cap_name()+" resucito a "+target->query_cap_name()+" el "+ctime(time())+".\n");
  
  return NIVEL*100;
}
