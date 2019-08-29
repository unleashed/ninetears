/*** Symbol Transformation ***/
/*** NPC friendly, coded by Wonderflug ***/

#include "tweaks.h"
inherit "/std/spells/patch.c";

#define SP_NAME "Symbol Transformation"
#define SPELLTYPE "offensive"  
#define SPELLPATH "/std/spells/cleric/"


string help() {
  string str;

  str = "\n\n"
       "Spell Name: "+SP_NAME+"\n"
       "Sphere: Summoning\n"
       "Level: 7th\n"
       "Gp Cost: Special\n"
       "Description: \n"
       "  This spell is granted only to the most faithful of a deities' "
       "worshippers.  The effects, cost, and duration vary according to the "
       "deity of the cleric.  A holy symbol is required and in some cases "
       "consumed in the casting.\n";
  switch( (string)this_player()->query_guild_name() )
  {
    case "Lolth":
	str += "  For worshippers of Lolth, your "
	"holy symbol grows and animates into a Massive "
	"spider.  The spider will follow and protect "
	"you, staying around for at most 1 turn "
	"per level.  At this time it will revert back into "
	"your holy symbol.  If, however, the spider is "
  "killed, your symbol will not be recovered.  Additionally, "
  "you may 'dismiss spider', to cause the spider to immediately "
  "revert back into your holy symbol.\n"
	"GP cost:  15\n\n";
	break;
    case "tymora":
	str += "  For Tymorans, your holy symbol will fracture into four "
	  "leaves, which array around you and block damage from attacks. "
	  "They will last for 1 round / level, and block 4*level HP worth "
	  "of damage.  When both of these conditions have occurred, the "
	  "leaves will revert back into your holy symbol. \n"
	  "GP Cost: 20 \n"
	  "NOTE: if you don't have the available encumbrance, or you quit "
	  "while the leaves are still on, you will (probably) not get your "
	  "holy symbol back.\n";
	break;
    case "tempus":
     str += "     For worshippers of Tempus, your holy symbol will "
     "grow into a massive enchanted Hammer.  The power of "
     "the enchant will be +1 per 6 levels of the caster, to a "
     "maximum of +5.  The hammer will only be "
     "effective in the hands of the faithful of tempus, and "
      "will not save.  The holy symbol is utterly consumed in the "
    "casting.  The damage done will always increase with level.\nGP Cost: 14 GP\n\n";
     break;
    default:
	break;
  }
  return str;
}

int cast_spell(string str, object my_caster)
{
  int i, has_symbol;
  object caster;
  string faith;
  object* symbol;

  if (my_caster)
	caster = my_caster;
  else 
  {
	caster = this_player();
	str = (string)caster->expand_nickname(str);
  }

/* Do holy symbol check here */
  faith = (string)caster->query_guild_name();
  symbol = find_match("holy symbol", caster);
  if ( !sizeof(symbol) )
  {
	tell_object(caster, "You need a holy symbol to cast this spell.\n");
	return 1;
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
	return 1;
  }

  if ((int)caster->query_spell_effect(SPELLTYPE))
  {
	tell_object(caster,"You are already casting an "+SPELLTYPE+" spell.\n");
	return 1;
  }

  tell_object(caster, "You start to cast "+SP_NAME+".\n");
  tell_room(environment(caster), caster->query_cap_name()+
	" begins to cast a spell.\n",
	caster);

  caster->add_spell_effect( 3, SPELLTYPE, SP_NAME, this_object(),
	"hb_spell", ({ symbol, faith }) );
  return 1;
}
int hb_spell( object caster, mixed* params, int time )
{
  string symfile;
  object sym;
  int cost;

  switch( time )
  {
    case 3:
	tell_object(caster, "You make somantic gestures while chanting "
	  "softly.\n");
	tell_room(environment(caster), caster->query_cap_name()+" makes "
	  "somantic gestures while chanting softly.\n", caster);
	return 1;
    case 2:
	tell_room(environment(caster), caster->query_cap_name()+" raises "+
	  caster->query_possessive()+" holy symbol, shouting syllables "
	  "of faith and devotion.\n", caster);
	tell_object(caster, "You raise your holy symbol, shouting out "
	  "syllables of faith and devotion \nto "+capitalize(params[1])+".\n");
	return 1;
    default:
	break;
  }

  switch ( params[1] )
  {
     case "Lolth":
	cost = 15;
	break;
     case "tymora":
	if (caster->query_skin_spell())
	{
	  tell_object(caster, "You cannot complete this spell right now.\n");
	  tell_room(environment(caster), caster->query_cap_name()+
	    " stops casting.\n", caster);
	  return 1;
    }
	cost = 20;
	break;
     case "lathander":
	cost = 10;
	break;
    case "tempus":
	cost = 14;
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
	return 1;
  }
  caster->adjust_gp(-cost);

  symfile = SPELLPATH+"sym_"+params[1]+".c";

  sym = clone_object(symfile);
  sym->setup_spell(caster);

  params[0]->dest_me();
  return cost;
}
