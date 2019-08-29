/*** Floating Disc Spell ***/
/*** Created by Eerevann Tokani ***/


#define SP_NAME "Floating Disc"
#define GP_COST 2
#define SPELLTYPE "misc"


string help() {
       return
       "\n\n"
       "Spell Name: "+SP_NAME+"\n"
       "School: Conjuration\n"
       "Level: 1st\n"
       "Gp Cost: "+GP_COST+"\n"
       "Description: \n"
       "    This spell is caster only."
       "\n"
       "\n";
       

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
    return "You are already casting an "+SPELLTYPE+" spell.\n";
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
 object disc;


  if (!params[1])
  {
    tell_object(this_player(),
      "Your spell failed ... there is no one of that name here.\n");
    return 0;
  }
  if (params[2] && (int)previous_object()->adjust_gp(-GP_COST)<0)
  {
    tell_object(previous_object(), "You are too mentally drained to cast.\n");
    return 0;
  }
    
  say((string)previous_object()->query_cap_name()+
   " chants, 'dyscik ivnis'.\n", ({params[1],previous_object()}));
    
  if(params[1] == previous_object())
   { 

   /** when cast upon self ***  only need altar chant part ***/

    tell_object(params[1], "You chant, 'dyscik ivnis'.\n");
    tell_object(params[1], "You cast "+SP_NAME+" as one appears.\n");
    say((string)previous_object()->query_cap_name()+
      " casts a spell and a floating disc appears.\n",params[1]);
   }
  else
  {
   tell_object(previous_object(), "You can't cast this spell on others!\n");
   
   say((string)previous_object()->query_cap_name()+
    " stops casting.\n",({params[1],previous_object()}) );
   return 0;
  }

  /*** specific spell stuff here ***/

  disc = clone_object("/std/spells/wizard/disc_obj.c");
  disc->move(environment(this_player()));
  disc->configure(this_player());

  return GP_COST;
}
