#define SP_COST 500
 
mixed spell(string str, int cast);

/* Power word Die.
   Made by Baldrick June 1993.
   Uses saving throw to balance the spell. But it should be *very* high level
   To get it:
   call add_spell("powerword die", "/std/spells/cleric/powr_die.c", "cast_word")     <whoever>
   Have fun with it.
*/

string help() 
  {
  return
    "This spell kills the one you use it at, if the victim is powerful enough "
    "it may survive.\n\n";
  }
 
int cast_spell(string str) 
  {
  mixed ret;
 
  str = (string)this_player()->expand_nickname(str);
  ret = spell(str, 1);
  if (stringp(ret)) 
    {
    notify_fail(ret);
    return 0;
    }
  return 1;
  }
 
mixed spell(string str, int cast) 
  {     
  mixed ob;
  int skill;
  int check;

  if (!str || str == "")
    return "You wave you hands in the air trying to touch nothing.\n";
  ob = find_match(str, environment(this_player()));
  if (sizeof(ob))
    ob = ob[0];
  else
    return "Who is " + capitalize(str) + "?\n";
  if (!living(ob))
    return ("Why kill a dead object ?.\n");
  if (ob->query_property("dead"))
    return (string)ob->query_cap_name() + " is already dead.\n";
if(ob->query_player()) return("You can't cast that on a fellow player.\n");

  if (cast && (int)this_player()->adjust_gp(-SP_COST) < 0)
    return "Too low on power.\n";
/* here is the "saving throw" I'm trying out */

  if ((random(2000)) < (ob->query_skill_bonus("occult") + 50))
    {
    ob->adjust_gp(-(SP_COST/20));
    return ("Your spell failed, nothing happens.\n");
    }
/*
  if (this_player()->query_skill_bonus("faith") <
      ob->query_skill_bonus("faith"))
    return (ob->query_cap_name() + " is too powerful.\n");
*/
  write("You call upon the gods to help you kill " + 
         ob->query_cap_name() + ".\n");
  say((string)this_player()->query_cap_name() + " shouts: DIE " +
     (string)ob->query_cap_name() + "!\n");
  tell_object(ob, "You feel " + (string)this_player()->query_cap_name() +
    "'s word attack you.\n\n" 
    "The powerword hurt you.\n\n");
   ob->do_death();
  return 1;
}
