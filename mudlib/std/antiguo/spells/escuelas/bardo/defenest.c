/***  PUFF esto es bestial, cuando lo logre entender esra la enloquecedor
 *** hasta entonces estoy en el  ;)    Osucaru   */

#include <spells.h>
inherit BASE_SPELL;
#define NOMBRE "Palabra poderosa defenestration"
#define	NIVEL	9

void setup()
{
  set_spell_name(NOMBRE);
  set_spell_level(NIVEL);
  set_school("bardo");
  set_target_type("one");
  set_range(0);
  set_help_extras("Tipo de danyo: Magico\nCaracteristica influyente: Dex");
  set_help_desc("Este hechizo crea una ventana entre dimensiones que "
     "absorbe a la victima atraves de esta. Solo funciona en sitios cerrados.\n"
     "Danyos: varia, bonifica por ser usado en lugares de altura, bares o "
     "dormitorios.");

  set_gp_cost(NIVEL);
  set_casting_time(2);
  set_rounds(({"round1","round2"}));
}

int round1(object caster, mixed target, mixed out_range, int time, int quiet )
{
  if (ENV(caster)->QP("location")!="inside")
  {
    tell_object(caster, "Miras a tu alrededor dandote cuenta que no hay "
        "lugar posible para poner una ventana.\n");
    tell_room(ENV(caster), caster->QCN+
      " mira confuso a su alrededor y para de invocar so hechizo.\n",caster);
    caster->ATP("nope",1,6);
    return -1;
  }

  if (!quiet)
  {
    tell_object(caster," Mirentras perfilas el marco de una supuesta "
        "ventana en el aire tu brazos se alargan y se hacen mas fuertes.\n");
    tell_room(ENV(caster),caster->QCN+
     " agita sus brazos y ellos parece que crecen y hacen mas fuertes "
     "mientras gesticula definiendo el marco de un fantasmal marco de una "
     "ventana.\n",caster);
  }
  return 1;
}

int round2(object caster, mixed target, mixed out_range, int time, int quiet )
{
  int damage,bonus,i;
  int *co;
  string *direc;
  string which;

  if (!target) return 0;
  if (caster->QP("nope")) return 0;

  co = ENV(caster)->query_co_ord();

  if ( !quiet )
  {
    tell_object(caster, "\nGritas: 'defenestrate bastards'.\n");
    tell_room(ENV(caster), "\n"+caster->QCN+
      " grita, 'defenestrate'.\n",caster);
  }
  damage = 5;
  if(sizeof(co)) damage += co[2];
  bonus = 1;
  if (member_array("/std/pub.c",deep_inherit_list(ENV(caster))) >= 0)
  {
    bonus = 5;
  }
  else if (member_array("dormitorio",explode(ENV(caster)->query_long()," ")) >= 0)
  {
    bonus = 10;
  }
   direc = ENV(caster)->query_direc();
   which = direc[random(sizeof(direc))];

   if(!target->QP("NOBUDGE"))
   {
        tell_object(caster,"Your ape like arms hurl "+target->QCN+" through the "+which+" window.\n");

        tell_room(ENV(caster),(string)caster->QCN+" grabs "+target->QCN+
            "and hurls them through the "+which+" window.\n",({caster,target}));
        tell_object(target,(string)caster->QCN+" hurls you through the "+which+" window.\n");

        ENV(caster)->do_exit_command("",({which," "+(string)target->QCN+" hurtles through the "+which+" window."}),target,0);

        damage = damage * bonus;

        target->attack_by(caster);
        if(random((int)target->query_dex()) > 10) damage = damage / 2;
        target->adjust_hp( -random(damage) ,caster);
    }
    else
    {
        tell_object(caster,"You strain mightilly, but "+target->QCN+
        " just won't budge.\n");
        tell_room(ENV(caster),(string)caster->QCN+" appears to nearly have a hernia "
        " trying to throw "+target->QCN+" through the window.\n",({target,caster}));
        target->attack_by(caster);
    }
   ENV(caster)->add_item(({"windowframe","window frame"}),"A neatly made window frame is fitted "
   "into the wall by the "+which+" exit.\n"
   "It seems out of place somehow since the view through the window isn't of the "
   "adjacent room, but seems to flicker with a variety of images.\n"
   "In neat gold lettering on the sill are the words: "
   "%^YELLOW%^\""+caster->QCN+" was here.\"%^RESET%^\n");
   return 1;
}
