#include "/std/spells/wizard/tweaks.h"

/*** Detect Magic Spell ***/
/*** Created by Eerevann Tokani ***/
/* fixed for NPC's / wands Taniwha */
/* Adapted to base spell, wonderflug 95 */
/* further screw by Taniwha, colour added + time remaining */
#define SP_NAME "Detect Magic"
#define GP_COST 2
inherit "/std/spells/base.c";
void setup()
{
  set_spell_name("Detect Magic");
  set_sphere("cleric divination");
  set_spell_level(1);
  set_target_type("item");
  set_range(0);
  set_line_of_sight_needed(0);
  set_help_desc("This spell is used to determine whether an item is "
    "magical or not.  The brightness of a magical item also gives the "
    "caster an idea of its power.  This spell must be cast upon an item "
    "or an npc (in which case it will give some idea of its magical auras) "
    "to work properly.");
  set_casting_time(1);
  set_gp_cost(1);
  set_rounds( ({ "round1" }) );
}
string powerp(int level,object ob,string str,string show)
{
  string temp;
  temp ="";
  if(!(int)ob->query_property(str)) return ("No sign of "+show+"\n");
  switch((int)ob->query_property(str))
  {
    case -399..-1:
      temp = "Black with flashes of "+show+" ";
    break;
    case 1..10:
      temp = "Pale sparkles of "+show+" ";
    break;
    case 11..30:
      temp = "Faint flashing "+show+" ";
    break;
    case 31..50:
      temp = "A steady glowing "+show+" ";
    break;
    case 51..80:
      temp = "Glowing bands of "+show+" ";
    break;
    case 81..99:
      temp = "Solid sheets of "+show+" ";
    break;
    case 100..399:
      temp = "A pulsating power sphere in "+show+" ";
    break;
    default:
      temp = "A scrambled mess of "+show+" ";
   break;
  }
  if(level > 15) switch((int)ob->query_time_remaining(str))
  {
    case 0:
        temp += "and it's permanent.";
    break;
    case 1..10:
        temp += "showing signs of immenent failure.";
    break;
    case 11..100:
        temp += "which looks a bit unstable.";
    break;
    case 101..500:
        temp += "which looks fairly stable.";
    break;
    case 501..2000:
        temp += "showing no sign of weakening soon.";
    break;
    default:
        temp + "and it looks solid for a goodly long time.";
    break;
    }
    return temp+".\n";
}
int round1(object caster, mixed target, mixed out_range, int time, int quiet)
{
  string es;
  int level;
  if (!target)
  {
    tell_object(caster,
      "Your spell failed ... the item isn't here.\n");
    return -1;
  }
 
  if ( !quiet )
  {
    tell_room(environment(caster),(string)caster->query_cap_name()+
      " chants, 'magius is iseio'.\n", ({target,caster}));
    tell_object(caster, "You chant, 'magius is iseio'.\n");
  }
  level = caster->query_level();

  if(living(target))
  {
    tell_object(caster,"You look closely and"
      " "+(string)target->query_cap_name()+
      " appears to be surrounded by:\n"+
      "%^GREEN%^"+powerp(level,target,"poison","green")+
      "%^WHITE%^%^BOLD%^"+powerp(level,target,"magical","silver")+
      "%^RED%^"+powerp(level,target,"fire","vermillion")+
      "%^BLUE%^"+powerp(level,target,"cold","cobalt blue")+
      "%^YELLOW%^"+powerp(level,target,"acid","yellow")+
      "%^MAGENTA%^"+powerp(level,target,"electrical","magenta")+
      "%^CYAN%^"+powerp(level,target,"air","lavendar")+"%^RESET%^"+
      powerp(level,target,SPIRIT_ARMOUR_PROPERTY,"armour")+
      "Womble on little frog, womble on.\n");
      tell_object(target, caster->query_cap_name()+" seems to stare at "
      "you intently for a minute.\n");
  }
  else
    if(stringp(es=target->enchant_string()) && strlen(es))
      tell_object(caster, "Peering intently for magical auras, you "
        "find...\n"+es+"\n");
    else 
      tell_object(caster,"Hmmm, can't tell anything much about this.\n");
  return 0;
}



