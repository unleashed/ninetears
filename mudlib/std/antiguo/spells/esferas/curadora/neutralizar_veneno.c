#include <spells.h>
inherit BASE_SPELL;

#define	NOMBRE	"Neutralizar veneno"
#define	ESCUELA	({"necromancia"})
#define	ESFERA	({"curadora"})
#define	CANCION	"'toxus wrathi aborum'"
#define	NIVEL	4

void setup()
{
  set_spell_name(NOMBRE);
  set_spell_level(NIVEL);
  set_sphere(ESFERA);
  set_school(ESCUELA);

  set_target_type("one");
  set_range(0);
  set_line_of_sight_needed(0);

  set_help_desc("Este hechizo puede curar a un objetivo de cualquier "
    "envenenamiento. Por lo que solo curar a aquellos afectados de "
    "hechizos de efectos de Veneno y heridas de veneno.");

  set_gp_cost(NIVEL);
  set_casting_time(1);
  set_rounds(({"round1"}));
}

int round1(object caster, mixed target, mixed out_range, int time, int quiet)
{
  object* obs;
  int i;

  if (!target)
  {
    tell_object(caster,MSG_NO_TARGET);
    return -1;
  }

  if (!quiet)
  {
    tell_room(ENV(caster),MSG_CAN_R,caster);
    tell_object(caster,MSG_CAN_C);
  }

  if (target!= caster) tell_object(caster,"Acabas el hechizo y extraes el veneno que "+target->QCN+" tiene en su cuerpo.\n");
  tell_room(ENV(caster),caster->QCN+" acaba el hechizo y "+target->QCN+" se ve mucho mejor.\n",({caster, target}));
  tell_object(target,"Comienzas a sentirte mucho mejor puesto que el veneno de tu cuerpo ha sido extraido.\n");

  obs = all_inventory(target);
  for (i=0;i<sizeof(obs);i++)
    if (obs[i]->query_name()=="herida envenenada") obs[i]->dispell_me(); 
  return 0;
}
