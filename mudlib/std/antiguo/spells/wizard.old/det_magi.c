
/*** Detect Magic Spell ***/
/*** Created by Eerevann Tokani ***/
/* fixed for NPC's / wands Taniwha */

#define SP_NAME "Detect Magic"
#define GP_COST 2
#define SPELLTYPE "misc"

inherit "/std/spells/patch.c";

/* find_unique_match() does a find match that ensures the returned
	object list contains no duplicates
	find_one_match() returns only the first matched object
*/
mixed find_unique_match(string find,mixed in);
mixed find_one_match(string find,mixed in);
int ADJ_COST;
object caster;

string help() {
		 return
		 "\n\n"
       "Spell Name: "+SP_NAME+"\n"
		 "School: Lesser Divination\n"
       "Level: 1st\n"
		 "Gp Cost: "+GP_COST+"\n"
       "Description: \n"
		 "    This spell is used to determine whether an item is magical or "
       "not.  The brightness of a magical item also gives the caster "
       "an idea of its power.  This spell must be cast upon and item to "
	"work properly.\nNote: It now works on NPC's too.\n\n";
       

}

mixed spell(string str, int skill, int cast);

int cast_spell(string str,object cast)
{
  int skill;
  mixed ret;

  caster = cast ? cast : this_player();

  ret = spell(str, skill, 1);
  if (stringp(ret))
  {
     notify_fail(ret);
    return 0;
  }
  tell_object(caster,"You start to cast "+SP_NAME+".\n");
  tell_room(environment(caster),caster->query_cap_name()+" begins to cast a spell.\n",
      ({caster}));
  return 1;
  }

mixed spell(string str, int skill, int cast)
{
   object *olist;
   object ob;

  if ((int)caster->query_spell_effect(SPELLTYPE))
    return "You are already casting an "+SPELLTYPE+" spell.\n";
   olist = find_match(str,environment(caster));
   if(sizeof(olist)) ob = olist[0];

  caster->add_spell_effect(1, SPELLTYPE, SP_NAME,
    this_object(), "hb_spell", ({ skill,ob,cast }));
  return 1;
}
string powerp(object ob,string str,string show)
{
    if(!(int)ob->query_property(str)) return ("No sign of "+show+"\n");
    switch((int)ob->query_property(str))
    {
        case -100..-1:
           return("Black with flashes of "+show+"\n");
        break;
        case 1..10:
           return("Pale sparkles of "+show+"\n");
        break;
        case 11..30:
           return("Faint flashing "+show+"\n");
        break;
        case 31..50:
          return("A steady glowing "+show+"\n");
       case 51..80:
          return("Glowing bands of "+show+"\n");
       case 81..99:
          return("Solid sheets of "+show+"\n");
       case 100..199:
          return("A pulsating power sphere in "+show+"\n");
       default:
          return("A scrambled mess of "+show+"\n");
       }
}
int hb_spell(object caster, mixed *params)
{
/*** variables, dependant upon spell ***/
object ob;

   ob = params[1];

  if (!params[1])
  {
     tell_object(caster,
     "Your spell failed ... the item isn't here.\n");
    return 0;
  }
 
    /* Specialists spend only half guild points to cast spells native to their
    * school, so GP_COST is checked and halved, if necessary.     */

  ADJ_COST = GP_COST;

  if((string)caster->query_guild_name() == "diviner")
    ADJ_COST = GP_COST/2;

  if (params[2] && (int)caster->adjust_gp(-ADJ_COST)<0)
  {
    tell_object(caster, "You fail to draw enough energy "
    "from your god.\n");
    return 0;
  }

  tell_room(environment(caster),(string)caster->query_cap_name()+
    " chants, 'magius is iseio'.\n", ({params[1],caster}));



     tell_object(caster, "You chant, 'magius is iseio'.\n");
     if(living(params[1]))
     {
         tell_object(caster,"You look closely and"
         " "+(string)ob->query_cap_name()+
        " appears to be surrounded by:\n"+
        powerp(ob,"poison","green")+
        powerp(ob,"magical","silver")+
        powerp(ob,"fire","vermillion")+
        powerp(ob,"cold","cobalt blue")+
        powerp(ob,"acid","yellow")+
        powerp(ob,"electrical","azure")+
      powerp(ob,"air","lavendar")+
        "Womble on little frog, womble on\n");
     }
     else
     {
        tell_room(environment(caster),(string)caster->query_cap_name()+
            " casts a spell and"
            " looks intently at the "+params[1]->query_short()+".\n",
            caster);
      if(params[1]->enchant_string())
       tell_object(caster,
          params[1]->enchant_string()+"\n");
      else tell_object(caster,"Hmmm, can't tell anything much about this.\n");
    }

  return GP_COST;
}

