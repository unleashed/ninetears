// Arrow Spell
// Traducido por Lummen 3-7-97
// Guldan Jul'98

#include <spells.h>
inherit BASE_SPELL;
//inherit "/d/gremios/hechizos/bases/patch.c";

#define	DDIV		4 
mixed	ESCUELA		= ({"conjuracion"});
mixed	ESFERA		= ({""});
#define	ARROWS_PER_ROUND ( caster->QL*POWER/10 )
#define	EXTRA		0
string	NOMBRE		= "Flecha de llamas";
string	TIPO		= "fuego";
int	SALV		= 50;
int	NIVEL		= 3;
int	SIZE_D		= 6;
int	NO_D		= 5;
int	BONUS		= 0;
int	LEVELS_PER_ARROW= 5;
int	LEVELS_PER_BONUS= 0;
int	DAMAGE_BON;
int	NUM_ARROWS;
int	MAX_ARROWS;

string tipo(string arg);

void setup()
{
  string tmp="Este hechizo proporciona una serie de flechas de "+tipo(TIPO);
  tmp+=" que impactan sobre un objetivo. El hechicero puede invocar una flecha por cada ";
  tmp+=(string)LEVELS_PER_ARROW+" nivel";
  tmp+=(LEVELS_PER_ARROW>1?"es":"");
  tmp+=" de experiencia. ";
  tmp+="Cada una es lanzada por turno, hasta hacerlo con todas. Cada flecha ";
  tmp+="produce "+NO_D+"d"+SIZE_D+" puntos de danyo";
  tmp+=(BONUS?(", +"+BONUS+" de bonus por cada "+LEVELS_PER_BONUS+" niveles del hechicero"):"");
  tmp+=". Si el objetivo sale de la habitacion, debera pasar una tirada de ";
  tmp+="salvacion que determine si las flechas le siguen.\n";
  set_spell_name(NOMBRE);
  set_spell_level(NIVEL);
  set_school(ESCUELA);
  set_sphere(ESFERA);
  set_target_type("one");
  set_range(100);
  set_line_of_sight_needed(0);
  set_help_extras("Tipo de danyo: "+tipo(TIPO)+"\nTirada de Salvacion: Especial");
  set_help_desc(tmp);
  set_gp_cost(NIVEL);
  set_casting_time(2);
  set_rounds(({"round1","round2"}));
}

int round1(object caster, mixed target, mixed out_range, int time, int quiet)
{
  if (target==caster)
  {
    tell_object(caster,MSG_SUIC_C);
    tell_room(ENV(caster),MSG_SUIC_R,caster);
    return -1;
  }

  if (!quiet)
  {
    tell_object(caster,"Un arco magico aparece en tus manos.\n");
    tell_room(ENV(caster),"Un arco magico aparece de improvisto en las manos de "+caster->QCN+"!\n", caster);
  }
  return NIVEL*40;
}

int round2(object caster, mixed target, mixed out_range, int time, int quiet)
{
  if (target==caster) return -1;

  if (!target)
  {
    tell_object(caster,MSG_NO_TARGET);
    return -1;
  }

  DAMAGE_BON=LEVELS_PER_BONUS?BONUS*caster->QL/LEVELS_PER_BONUS:0;
  NUM_ARROWS=MAX(1,caster->QL/LEVELS_PER_ARROW+POWER);
  MAX_ARROWS=MIN(random(ARROWS_PER_ROUND),NUM_ARROWS/4);
  
 
  if (MAX_ARROWS<POWER) MAX_ARROWS=POWER;
  MAX_ARROWS=1;
  if (!quiet)
  {
    tell_object(caster,NUM_ARROWS+" flechas de "+tipo(TIPO)+" aparecen flotando en el aire a tu alrededor.\n");
    tell_room(ENV(caster),"El aire explota en "+NUM_ARROWS+" flechas de "
        +tipo(TIPO)+" flotando alrededor de "+caster->QCN+".\n",caster);
  }
  caster->add_spell_effect(NUM_ARROWS+1,"spell",NOMBRE,TO,"hb_arrow", 
    ({NUM_ARROWS,target,ENV(caster),MAX_ARROWS}));
  return NIVEL*40;
}

int hb_arrow(object caster,mixed params,int time)
{
//  NUM_ARROWS -> params[0]
//  target -> params[1]
//  env -> params[2]
//  max_arrows -> params[3]
  int damage,i,difroom,rvictim,rcaster;
  
  if (!params[1] || params[1]->query_dead())
  {
    tell_object(caster,"Tu arco magico desaparece en una nube de humo como tu objetivo.\n");
    call_out("end_spell",0,caster);
    return 0;
  }
  
  if(caster->query_timed_property_exists("passed out") || ENV(caster)!=params[2])
  {
    tell_object(caster,"Tu arco magico desaparece en una nube de humo.\n");
    call_out("end_spell",0,caster);
    return 0;
  }  

  tell_object(caster,"Lanzas "+params[3]+" flechas de "+tipo(TIPO)+" a "+params[1]->QCN+".\n");
  tell_object(params[1],params[3]+" flechas de "+tipo(TIPO)+" se dirigen hacia ti!\n");
  for (i=0;(i<params[3]) && (params[0]>0);++i,--params[0])
  {
    if (ENV(params[1])!=ENV(caster))
    {
      difroom=1;
      rvictim=((RANGE_HANDLER->calc_distance(caster,params[1])/DDIV)*(params[1]->query_dex()+params[1]->QL));
      rcaster=caster->query_int()+caster->query_level();
    }
    else difroom=0;

    if (difroom && (random(rvictim)>random(rcaster))) damage=0;
    else damage=fix_damage(caster,params[1],-roll(NO_D,SIZE_D)-DAMAGE_BON);
    damage=params[1]->spell_damage(damage,TIPO,query_sphere(),SALV,caster);
    params[1]->attack_by(caster);
    if (DEBUG(caster)) tell_object(caster,"\nNO_D:"+NO_D+" SIZE:"+SIZE_D+" BONUS:"+DAMAGE_BON+".\n");
    if (DEBUG(caster)) tell_object(caster,"\nTu flecha produce "+damage+" hps.\n");
    switch (damage)
    {
      case 1..9:
        tell_object(caster,"Tu flecha hiere levemente a "+params[1]->QCN+".\n");
        tell_object(params[1],"Eres herido por una flecha de "+tipo(TIPO)+".\n");
        break;
      case 10..19:
        tell_object(caster,"Tu flecha hiere a "+params[1]->QCN+".\n");
        tell_object(params[1], "Una flecha de "+tipo(TIPO)+" te hiere.\n");
        break;
      case 20..29:
        tell_object(caster, "Tu flecha hiere gravemente a "+params[1]->QCN+".\n");
        tell_object(params[1], "Una flecha de "+tipo(TIPO)+" te hiere gravemente.\n");
        break;
      case 30..39:
        tell_object(caster, "Tu flecha hiere criticamente a "+params[1]->QCN+".\n");
        tell_object(params[1], "Una flecha de "+tipo(TIPO)+" te hiere criticamente.\n");
        break;
      case 40..1000:
        tell_object(caster, "Tu flecha explota violentamente en "+params[1]->QCN+".\n");
        tell_object(params[1], "Una flecha de "+tipo(TIPO)+" explota violentamente"
        " en ti!\n");
        break;
      default:
        tell_object(params[1], "Eres atacado por una flecha de "+tipo(TIPO)+".\n");
        tell_object(caster, "Tu flecha de "+tipo(TIPO)+" impacta en "+params[1]->QCN+".\n");
        break;
    }
  }
  if (time==1 || params[0]<1)
  {
    tell_object(caster,"El arco magico desaparece en una nube de humo al usar tu ultima flecha.\n");
    call_out("end_spell",0,caster);
    return 0;
  }

  if (ENV(params[1])!=ENV(caster))
  {
    tell_room(ENV(caster),caster->QCN+" tensa el arco magico, y lanza "+params[3]+" flechas de "+tipo(TIPO)+" que flotan a su alrededor.\n",caster);
    tell_room(ENV(params[1]),params[1]->QCN+" es golpeado por una flecha de "+tipo(TIPO)+"!\n", params[1]);
    if (params[2]!=ENV(caster) && (random(params[1]->query_dex()+params[1]->QL))>random(caster->query_int()+caster->QL)||(params[0]<(random(params[0])+2)))
    {
      tell_object(caster, "Pierdes la pista de "+params[1]->QCN+", y tu arco magico muere en forma de humo.\n");
      call_out("end_spell",0,caster);
      return 0;
    }
  }
  tell_room(ENV(caster),caster->QCN+" tensa el arco magico y lanza una flecha a "+params[1]->QCN+".\n",({caster,params[1]}));
  return NIVEL*40+damage*2+100;
}

void end_spell(object caster)
{
  caster->remove_spell_effect(NOMBRE);
}



