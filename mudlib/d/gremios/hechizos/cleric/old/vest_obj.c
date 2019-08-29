
inherit "/std/spells/patch.c";

/* find_unique_match() does a find match that ensures the returned 
   object list contains no duplicates
   find_one_match() returns only the first matched object
*/
mixed find_unique_match(string find,mixed inx);
mixed find_one_match(string find,mixed inx);
/*** Object for Magical Vestment spell ***/

inherit "/obj/armour"; 

mixed owner;

void setup()  
  { 
  /* THIS HAS TO BE THE FIRST LINE !!!! */
   set_base_armour("chainmail");  /* Will set up most of the armour for you */

  set_name("Magical Vestment");   /* The name is an identifier **/ 

  set_short("Magical Vestment");        /* What the players see */ 
   add_alias("vestment");

  set_main_plural("Magical Vestments"); /* What the the players see if there
                                           are more than one of that armour */
 
  reset_drop();
} 

void vestment_setup(int enchant, mixed caster)
{
  int level;
   
   this_object()->set_enchant(enchant);
    owner = caster;
  set_long("This is a suit of glowing armour created by "+
    (string)owner->query_cap_name()+"\n");
  level = (int)owner->query_level();
  call_out("wear_off", (3*level), owner);

}

void wear_off(mixed owner)
{
  tell_object(owner, "The Magical Vestment disappears!\n");
  say((string)owner->query_cap_name()+"'s Magical Vestment "
    "disappears!\n",owner);
   this_object()->unwear_ob();
  this_object()->dest_me();
}
