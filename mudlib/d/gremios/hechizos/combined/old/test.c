/*** Magical Vestment Spell ***/
/*** Created by Eerevann Tokani ***/


#define SP_NAME "Magical Vestment"
#define GP_COST 6
#define SPELLTYPE "defensive"


string help() {
       return
       "\n\n"
       "Spell Name: "+SP_NAME+"\n"
       "Sphere: Protection\n"
       "Level: 3rd\n"
       "Gp Cost: "+GP_COST+"\n"
       "Description: \n"
       "    This spell creates a suit of magical armour for the caster "
       "to wear.  The armour is equal to Chainmail, AC 5.  The vestment " 
       "receives a -1 enchantment for every 3 levels of the caster beyond "
       "5th, to a maximum of AC 1 at 17th level.  The vestment lasts for "
       "moderate amount of time dependant upon the casters level.\n\n";
       

}

mixed spell(string str, int skill, int cast);

int cast_spell(string str)
{
  int skill;
  mixed ret;

  str = (string)this_player()->expand_nickname(str);
  
  ret = spell(str, skill, 1);
  if (stringp(ret))
  {
    notify_fail(ret);
    return 0;
  }
  write("You start to cast "+SP_NAME+".\n");
  say(this_player()->query_cap_name()+" begins to cast a spell.\n",
     previous_object());
  return 1;
  }

mixed spell(string str, int skill, int cast)
{
  mixed ob;

  if ((int)this_player()->query_spell_effect(SPELLTYPE))
    return "You are already casting a "+SPELLTYPE+" spell.\n";
  ob = find_match(str, environment(this_player()));
  if (sizeof(ob))
    ob = ob[0];
  else
    ob = 0;

  this_player()->add_spell_effect(1, SPELLTYPE, SP_NAME,
    this_object(), "hb_spell", ({ skill,ob,cast }));
  return 1;
}

int hb_spell(object attacker, mixed *params)
{
/*** variables, dependant upon spell ***/
  object armour;
  int enchant;

  if (params[1] != this_player())
  {
    tell_object(this_player(),
      "Your spell failed ... you may only cast this spell upon yourself.\n");
    return 0;
  }
  if (params[2] && (int)previous_object()->adjust_gp(-GP_COST)<0)
  {
    tell_object(previous_object(), "You fail to draw enough power from "
          "your god.\n");
    return 0;
  }
    
  say((string)previous_object()->query_cap_name()+
   " chants, 'vesios magius arimani'.\n", ({params[1],previous_object()}));
    

   /** when cast upon self ***  only need altar chant part ***/

    tell_object(params[1], "You chant, 'vesios magius arimani'.\n");
    tell_object(params[1], "You cast "+SP_NAME+" upon yourself.\n");
    say((string)previous_object()->query_cap_name()+
      " casts a spell upon "+params[1]->query_objective()+"self.\n",params[1]);

  /*** specific spell stuff here ***/

  enchant = ((int)this_player()->query_level() - 5) / 3;
  
  write(enchant+"\n");

  if (enchant > 4)
   enchant = 4;

  armour = clone_object("/std/spells/cleric/vest_obj.c");
  armour->move(this_player());
  armour->vestment_setup(enchant, this_player());
  
  return GP_COST;
}
