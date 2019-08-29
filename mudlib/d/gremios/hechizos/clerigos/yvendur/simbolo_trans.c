/*** Symbol Transformation ***/
/*** NPC friendly, coded by Wonderflug ***/
/*** Adopted for Anti/Paladins by Raskolnikov ***/

#include "tweaks.h"
inherit "/d/gremios/hechizos/base.c";

#define SP_NAME "Transformacion de Simbolo"
#define SPELLTYPE "offensive"  
#define SPELLPATH "/d/gremios/hechizos/clerigo/yvendur"

void setup()
{
  set_spell_name("Transformacion de Simbolo");
  set_spell_level(7);
  set_sphere("alteracion");
  set_school("yvendur");
  set_target_type("none");
  set_range(0);

  set_help_desc("Este hechizo es solo obtenido por la gente mas devota de una deidad. "
    " Los efectos, duracion y danyo varian segun la deidad del clerigo. "
    " Se requiere un simbolo sagrado de tu Gremio para consumar el hechizo correctamente.\n");

  set_gp_cost(1);
  set_casting_time(3);
  set_rounds( ({ "round1", "round2", "round3" }) );
}

/* Yes, we need to overload this, alas */
string help() 
{
  string str;

  str = ::help();
  switch( (string)this_player()->query_guild_name() )
  {
  case "antipaladin":
   str += "     For Dark Lords the Holy Symbol will grow into "
          "a mystical sword with unspeakable powers.  Though the "
          "Evil Knight is Lawful the sword knows no bounds "
          "so beware.  The sword will not save and the symbol "
          "will be destroyed in the casting.\n"
          "GP Cost: 20 GP";
     break;
  case "Paladin":
   str += "     For Lords the Holy Symbol will grow into "
          "a mystical sword with unspeakable powers.  Though the "
          "Good Knight is Lawful the sword knows no bounds "
          "so beware.  The sword will not save and the symbol "
          "will be destroyed in the casting.\n"
          "GP Cost: 20 GP";
     break;
  case "Clerigo de Yvendur":
      str += "Para los devotos de Yvendur, tu simbolo se transforma en una "
	     "espada sagrada con empunyadura tricolor. Te protegera de los "
             "ataques mas peligrosos. Esta espada tiene efectos curativos "
	     "y de proteccion en la persona que la lleva.\n"
	     "   Coste en PG: 20";
      break;
    default:
	break;
  }
  return str+"\n\n";
}

int round1(object caster, mixed target, mixed out_range, int time, int quiet)
{
  tell_object(caster, "Haces unos gestos con tus manos mientras cantas "
    "un ritual con palabras relajantes.\n");
  tell_room(environment(caster), caster->query_cap_name()+" hace "
    "gestos con sus manos como si de ello dependiera su vida.\n", caster);
  return 0;
}

int round2(object caster, mixed target, mixed out_range, int time, int quiet)
{
  tell_room(environment(caster), caster->query_cap_name()+" levanta "+
    "su simbolo sagarado, gritando silabas "
    "de fe y devocion.\n", caster);
  tell_object(caster, "Levantas tu simbolo segrado al cielo, gritando "
    "silabas de fe y devocion.\n");
  return 0;
}

int round3(object caster, mixed target, mixed out_range, int time, int quiet)
{
  int i, has_symbol;
  string faith;
  object *symbol;
  string symfile;
  object sym;
  int cost;

  /* Do holy symbol check here */
  faith = (string)caster->query_guild_name();
  symbol = find_match("alzacuellos purpura", caster);
  if ( !sizeof(symbol) )
  {
    tell_object(caster, "Necesitas un simbolo sagrado para formular este hechizo.\n");
    return 0;
  }

  has_symbol = 0;
  for (i=0;i<sizeof(symbol);i++)
    if ( (string)symbol[i]->query_property("faith") == faith )
    {
      symbol[0] = symbol[i];
      has_symbol = 1;
      break;
    }

  if ( !has_symbol )
  {
    tell_object(caster, "Necesitas un simbolo de tu deidad para formular este hechizo.\n");
    return 0;
  }

  switch ( faith )
  {
    case "Clerigo de Yvendur":
      cost = 20;
      break;
    case "hokemj":
      if (caster->query_skin_spell())
      {
        tell_object(caster, "No puedes completar este hechizo ahora.\n");
        tell_room(environment(caster), caster->query_cap_name()+
          " para de formular un hechizo.\n", caster);
        return 0;
      }
      cost = 20;
      break;
    case "taniwha":
      cost = 10;
      break;
    case "timion":
      cost = 14;
      break;
  case "paladin":
    cost = 20;
    break;
  case "antipaladin":
    cost = 20;
    break;
  case "virga":
    cost = 20;
  break;
    default:
      break;
  }

  if ((int)caster->query_gp() < cost )
  {
    tell_object(caster,"Estas demasiado drenado mentalmente para completar "
      "este hechizo.\n");
    tell_room(environment(caster), caster->query_cap_name()+" para "
      "de formular un hechizo.\n", caster);
    return 0;
  }
  caster->adjust_gp(-cost);

  symfile = "/d/gremios/hechizos/clerigo/yvendur/espada_sagrada.c";
  sym = clone_object(symfile);
  sym->setup_spell(caster);

  symbol[0]->dest_me();
  return 0;
}
