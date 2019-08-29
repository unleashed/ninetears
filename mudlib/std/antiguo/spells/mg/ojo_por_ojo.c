//Paris. Nov'98

#include <spells.h>
inherit BASE_SPELL;

#define	NOMBRE	"Ojo Por Ojo"
#define NIVEL	8
#define	ESCUELA	({"wizwar"})
#define	ESFERA	({""})

void setup()
{
  set_spell_name(NOMBRE);
  set_spell_level(NIVEL);
  set_school(ESCUELA);
  set_target_type("none");
  set_range(0);
  set_line_of_sight_needed(0);
  set_help_desc("Este es un cojuro que permite llevar al conjurador una esfera "
                "de proteccion que hace que el atacante reciba el mismo danyo "
                "que el portador en un unico ataque.\n");
  
  set_casting_time(3);
  set_rounds(({"round1","round2","round3"}));
  set_gp_cost(NIVEL);
}


int round1(object caster, mixed target, mixed out_range, int time, int quiet)
{
  tell_object(caster,"Empiezas a convocar las Fuerzas de la Naturaleza.\n");
  tell_room(ENV(caster),caster->QCN+" comienza a invocar la Fuerza de la Naturaleza.\n",({caster}));
  return 1;
}
int round2(object caster, mixed target, mixed out_range, int time, int quiet)
{
  tell_object(caster,"Una capa protectora de energia comienza a formarse a tu alrededor.\n");
  tell_room(ENV(caster),"Una capa protectora de intensa energia comienza a "
                        "formarse alrededor de "+caster->QCN+".\n",({caster}));
  return 1;
}
int round3(object caster, mixed target, mixed out_range, int time, int quiet)
{
  object sombra;
  if(caster->query_property("nocast"))
  {
    tell_object(caster,"Aun puedes notar los efectos de la fuerza magica en "
                       "tu cuerpo. No puedes volver a invocarla.\n");
    return -1;
  }
  
  if(caster->query_ojo_por_ojo_shadow())
  {
    tell_object(caster,"Ya posees un efecto de Ojo por Ojo en ti.\n");
    return -1;
  }
  tell_room(ENV(caster),caster->QCN+" finaliza su conjuro y un Aura Blanquecina "
                        "de intensa energia le rode.\n",caster);
  tell_object(caster,"Finalizas tu hechizo y un Aura Blanquecina de intensa "
                     "energia te protege.\n");
  sombra =   clone_object(SHADOWS+"ojo_por_ojo_sh.c");
  sombra->setshadow(caster);
  return 0;  
}
