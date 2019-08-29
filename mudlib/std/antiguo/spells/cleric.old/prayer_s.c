/*** temp shadow for Prayer spell ***/
inherit "/std/spells/patch.c";

/* find_unique_match() does a find match that ensures the returned 
   object list contains no duplicates
   find_one_match() returns only the first matched object
*/
mixed find_unique_match(string find,mixed in);
mixed find_one_match(string find,mixed in);

object my_player;


void setshadow(object ob) 
{
   shadow(ob,1);
   my_player = ob;
}

void destruct_prayer_shadow()
{
  destruct(this_object());
}

      
int query_prayer() { return 1; }

/*** query_armour_spell <- identifies which spell, if its say a shield 
 spell, it would be query_shield_spell(), etc. ***/

