/*** Symbol Transformation ***/
/*** NPC friendly, coded by Wonderflug ***/
/*** Adopted for Anti/Paladins by Raskolnikov ***/

#include "tweaks.h"
inherit "/std/spells/base.c";

#define SP_NAME "Symbol Transformation"
#define SPELLTYPE "offensive"  
#define SPELLPATH "/std/spells/cleric/"

void setup()
{
  set_spell_name("Symbol Transformation");
  set_spell_level(7);
  set_sphere("summoning");

  set_target_type("none");
  set_range(0);

  set_help_desc("This spell is granted only to the most faithful of a deities' "
    "worshippers.  The effects, cost, and duration vary according to the "
    "deity of the cleric.  A holy symbol is required and in some cases "
    "consumed in the casting.");

  set_gp_cost(0);
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
    case "Cyrcia":
      str += "  For worshippers of Cyrcia, your "
        "holy symbol grows and animates into a Massive "
        "spider.  The spider will follow and protect "
        "you, staying around for at most 1 turn "
        "per level.  At this time it will revert back into "
        "your holy symbol.  If, however, the spider is "
        "killed, your symbol will not be recovered.  Additionally, "
        "you may 'dismiss spider', to cause the spider to immediately "
        "revert back into your holy symbol.\n"
	"GP cost:  15";
      break;
    case "hokemj":
      str += "  For Hokemj's followers, your holy symbol will fracture into "
        "four leaves, which array around you and block damage from attacks. "
        "They will last for 1 round / level, and block 4*level HP worth "
        "of damage.  When both of these conditions have occurred, the "
        "leaves will revert back into your holy symbol. \n"
        "GP Cost: 20 \n"
        "NOTE: if you don't have the available encumbrance, or you quit "
        "while the leaves are still on, you will (probably) not get your "
        "holy symbol back.";
      break;
    case "timion":
      str += "     For worshippers of Timion, your holy symbol will "
        "grow into a massive enchanted Hammer.  The power of "
        "the enchant will be +1 per 6 levels of the caster, to a "
        "maximum of +5.  The hammer will only be "
        "effective in the hands of the faithful of Timion, and "
        "will not save.  The holy symbol is utterly consumed in the "
        "casting.  The damage done will always increase with level.\n"
        "GP Cost: 14 GP";
      break;
  case "antipaladin":
   str += "     For Dark Lords the Holy Symbol will grow into "
          "a mystical sword with unspeakable powers.  Though the "
          "Evil Knight is Lawful the sword knows no bounds "
          "so beware.  The sword will not save and the symbol "
          "will be destroyed in the casting.\n"
          "GP Cost: 20 GP";
     break;
  case "paladin":
   str += "     For Lords the Holy Symbol will grow into "
          "a mystical sword with unspeakable powers.  Though the "
          "Good Knight is Lawful the sword knows no bounds "
          "so beware.  The sword will not save and the symbol "
          "will be destroyed in the casting.\n"
          "GP Cost: 20 GP";
     break;
    case "virga":
      str += "For worshippers of Virga, your symbol summons an Avatar of "
	     "Virga.  The Avatar will follow and protect you for your level"
	     " times 20 heartbeats and then revert back into your holy "
	     "symbol.  If the Avatar is killed then your symbol will be "
	     "lost.  Additionally, you may 'dismiss avatar' to immediately "
	     "revert back to your holy symbol.\n"
	     "   GP cost: 20";
      break;
    default:
	break;
  }
  return str+"\n\n";
}

int round1(object caster, mixed target, mixed out_range, int time, int quiet)
{
  tell_object(caster, "You make somantic gestures while chanting "
    "softly.\n");
  tell_room(environment(caster), caster->query_cap_name()+" makes "
    "somantic gestures while chanting softly.\n", caster);
  return 0;
}

int round2(object caster, mixed target, mixed out_range, int time, int quiet)
{
  tell_room(environment(caster), caster->query_cap_name()+" raises "+
    caster->query_possessive()+" holy symbol, shouting syllables "
    "of faith and devotion.\n", caster);
  tell_object(caster, "You raise your holy symbol, shouting out "
    "syllables of faith and devotion.\n");
  return 0;
}

int round3(object caster, mixed target, mixed out_range, int time, int quiet)
{
  int i, has_symbol;
  string faith;
  mixed symbol;
  string symfile;
  object sym;
  int cost;

  /* Do holy symbol check here */
  faith = (string)caster->query_guild_name();
  symbol = find_match("holy symbols", caster);
  if ( !sizeof(symbol) )
  {
    tell_object(caster, "You need a holy symbol to cast this spell.\n");
    return 0;
  }

  has_symbol = 0;
  for (i=0;i<sizeof(symbol);i++)
    if ( (string)symbol[i]->query_property("faith") == faith )
    {
      symbol = symbol[i];
      has_symbol = 1;
      break;
    }

  if ( !has_symbol )
  {
    tell_object(caster, "You need a holy symbol to cast this spell.\n");
    return 0;
  }

  switch ( faith )
  {
    case "Cyrcia":
      cost = 15;
      break;
    case "hokemj":
      if (caster->query_skin_spell())
      {
        tell_object(caster, "You cannot complete this spell right now.\n");
        tell_room(environment(caster), caster->query_cap_name()+
          " stops casting.\n", caster);
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
    tell_object(caster,"You are too mentally drained to complete "
      "this spell.\n");
    tell_room(environment(caster), caster->query_cap_name()+" stops "
      "casting.\n", caster);
    return 0;
  }
  caster->adjust_gp(-cost);

  symfile = SPELLPATH+"sym_"+lower_case(faith)+".c";
  sym = clone_object(symfile);
  sym->setup_spell(caster);

  symbol->dest_me();
  return 0;
}
