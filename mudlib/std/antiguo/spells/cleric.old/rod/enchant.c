 
mixed spell(string str, int skill, int cast);

/* Enchant Item.
   Made by Baldrick July 1993.
   This spell enchants an item.
   To get it:
   call add_spell("powerword die", "/std/spells/cleric/powr_die.c", "cast_word")     <whoever>
   Have fun with it.
*/

string help() 
  {
  return
    ("This spell enchants any item, but you should only use it on weapon " 
     "or armour.\n\n");
  }
 
int cast_spell(string str) 
  {
  mixed ret;
  int skill;

  skill = (int)this_player()->query_skill_bonus("faith.items"); 
/* dont think this spell need expand_nickname */
/*
  str = (string)this_player()->expand_nickname(str);
*/
  ret = spell(str, skill, 1);
  if (stringp(ret)) 
    {
    notify_fail(ret);
    return 0;
    }
  return 1;
  }
 
mixed spell(string str, int skill, int cast) 
  {     
  mixed ob;
  int enchant;

  if (!str || str == "")
    return "You wave you hands in the air trying to touch nothing.\n";
  ob = find_match(str, this_player());
  if (sizeof(ob))
    ob = ob[0];
  else
    return "Where is " + str + " ?\n";
  if (living(ob))
    return ("You have problems enchanting a living object.\n");
  if (ob->query_enchant() > 0)
    return ("The item is already enchanted.\n");

/* This will calculate the enchantment the item will get.
   It depends on the skill_bonus the spellcaster has */

  enchant = (skill/10);

/* The spell cost depends on how good enchantingthe item gets */

  if (cast && (int)this_player()->adjust_gp(-(enchant*3)) < 0)
    return "Too low on power.\n";
  
  write("You call upon the gods to help you enchant this item.\n");
  ob->set_enchant(enchant);
  return 1;
}
