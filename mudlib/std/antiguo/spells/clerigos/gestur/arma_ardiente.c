#include <spells.h>
inherit BASE_SPELL;

#define	NOMBRE	"Arma ardiente"
#define	NIVEL   6
#define	ESCUELA	({""})
#define	ESFERA	({"gestur"})
#define	CANCION	"'in magius armoris ignis'"
#define SOMBRA	SHADOWS+"arma_ardiente_sh.c"

void setup()
{
  set_spell_name(NOMBRE);
  set_spell_level(NIVEL);
  set_sphere(ESFERA);
  set_school(ESCUELA);
  set_target_type("none");
  set_range(0);
  set_help_desc("Este hechizo canaliza el poder de un clerigo a sus manos, haciendo que estas ardan, al igual que "
                "las armas que se empunyen. Este hechizo consume 1 gp por arma que se lleve. Mientras el clerigo "
                "esta en este estado, su poder sobre el fuego es "
                "casi total, pero los ataques de agua le hacen un danyo anyadido.\n"
                "Para liberar tu cuerpo de las llamas, solo te hace falta decir 'noflame' y las llamas desapareceran.\n");
  set_gp_cost(NIVEL);
  set_casting_time(1);
  set_rounds(({ "round1"}));
}

int query_gp_cost()
{
   return 12; // Siempre costara 12 gps este spell
}

int round1(object caster, mixed target, mixed out_range, int time, int quiet)
{
  int duracion;
  object shadow;
  
  if(!quiet)
  {
  tell_object(caster,MSG_CAN_C);
  tell_room(ENV(caster),MSG_CAN_R,caster);
  }

  if(caster->query_arma_ardiente())
  {
  tell_object(caster,"Aun estas bajo el efecto de ese hechizo.\n");
  tell_room(ENV(caster),caster->query_cap_name()+" para de formular su hechizo.\n",caster);
  return 0;
  }
  
  tell_object(caster,"Tus armas se envuelven de un fuego divino.\n");
  tell_room(ENV(caster),"Las armas de "+caster->query_cap_name()+" se ven envueltas en un fuego divino.\n",caster);  
  shadow=clone_object(SOMBRA);
  shadow->move(caster);
  duracion=fix_damage(caster,caster,10*caster->QL);
  shadow->setup_shadow(caster,duracion);
  caster->add_timed_property("TIME_ARMAS_ARDIENTES",1,duracion);
  call_out("dispell_arma",duracion,caster);

  return 0;
}

void dispell_arma(object caster)
{
   if(caster)
   caster->dispell_burning_weapon();  
}
