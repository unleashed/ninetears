/* My rewrite of Danks armour object.
 * Guess it's basically PF's object tho, with Danks comments..
 * (it's not now..)
 * But I have to understand this, so I'm "making" my own
 * Baldrick, april '94 
 * This have to be more complicated than nessesary ?
 * it's a lot of code ...
 * I will remove the attack_out array and replace it with int's
 */
/* The most scary part of this, auto_load is not finished..
 * Have to do that pretty soon
 */

inherit "/std/item";

/* shield logic ? */
inherit "/std/shield_logic";
inherit "/std/basic/condition"; 
#include "move_failures.h";
#define SHIELD_TABLE "/table/shield_table.c"
#define COST_TO_FIX 300
#define SIZE 8

/* attack_out consists of concatenated 7-tuples */

/* Shields *can* be twohanded.. :=) */
static int twohanded;   /* used to be "str hand" */

int enchant,value_adjustment;

/* This is the armours damage_ac.. */
int ac, max_ac, min_ac;

/* The armours full ac value.. 
 * Will add magical ac later..
 */
static int armour_ac;
//static int value;

string cond_string()
{
   return condition::cond_string();
}
/* this is the values from the armour_table: */
/* Look at /table/armour_table for explanation. */

int ac_backup,min_level,n_bonus_backup;

int ench_gp_cost,
    gp_cost,
    armour_ac,
    armour_type,
    material,
    no_dex_bon,
	n_dados,
	n_caras,
	n_bonus;

/* This will hold whatever you send to set_base_shield().
   query_shield_name() returns it.  -- Hamlet 
*/
string shield_name = "crap";

/* need this one here ? */

void set_value(int i);

void set_twohanded(int flag)
  {
  twohanded = flag;
} /* void set_twohanded */

int query_shield() { return 1; }

/* here is the new setup routine, will make the whole a lot cleaner.. */
void set_base_shield(string lookup)
  {
  int *data;
  min_level=0;
  if(stringp(lookup))
    shield_name = lookup;  /* Hamlet */
  data = (int *)SHIELD_TABLE->lookup_shield_data(lookup);

  gp_cost = data[0]; // Value is GP's
  ench_gp_cost = data [1];
  set_weight(data[2]);
  set_size(data[3]);
  armour_ac = data [4];
  material = data [5];

  /* Ok, this slot is holdable or not, if it's not holdable, it's wearable */
  // todos los escudos son holdables.

    set_holdable(1);

	// num dados, caras de cada dado, bonus - danio de atake
	n_dados = data[6];
	n_caras = data[7];
	n_bonus = data[8];


  // Following if/else fix by Wonderflug.
  // Most entries don't HAVE a 10th entry, this driver complains.
  if ( sizeof(data) >= 10 )
    no_dex_bon = data [9]; 
  else
    no_dex_bon = 0;
  set_value(gp_cost);

}

void set_base_armour(string lookup)
{
	set_base_shield(lookup);
}

/* This just returns the basearmour name -- Hamlet */
string query_shield_name() {  return shield_name; }
string query_armour_name() {  return shield_name; }

int query_no_dex_bon() { return no_dex_bon; }

int query_ac() { return armour_ac + enchant; }
/* Mask it too */

int query_armour_ac() { return armour_ac + enchant; }

int query_armour_type() { return armour_type; }

string query_armour_type_name() 
  {
	return "shield";
} /* string query_attack_type_name() */

int query_material() { return material; }

string query_material_name()
  {
  switch (material)
    {
    case 1:
      return "wood";
    case 2:
      return "metal";
    case 3:
      return "leather";
    case 4:
      return "cloth";

    default:
      return "unknown";
   }
} /* string query_material_name */

void set_value(int gp_cost)
  {
  /* Make this simpler later.. 
   * And similar to weapon.c (not made either..:=)
   */
  if (enchant <= 0)
    if (gp_cost > 0)
      value = gp_cost * 100 + value_adjustment + (max_cond - cond) *
        COST_TO_FIX;
    else       
 /* negative values in data[0] mean silver, not gold */
      value = gp_cost * -10 + value_adjustment + (max_cond - cond) *
        COST_TO_FIX;
  else
    value = ench_gp_cost * enchant * 100 +
            value_adjustment + (max_cond - cond)
      * COST_TO_FIX;
}

void adjust_value(int i) 
  {
  value_adjustment = i * 100; /* to convert from gp to cp */
}

/* all this code should be changed.. 
 * It can positively be simplified.
 * Can't be easier than this ? :=)
 * New code will be added later 
 */
void set_enchant(int i) 
  {
  enchant = i;
}
int query_enchant()
{
   return enchant;
}

/* I hope we don't ever use the following, but just in case: */
void set_ac(int max1, int min1) 
  {
  max_ac = max1;
  min_ac = min1;
  cond = max_ac - min_ac; 
  max_cond = max_ac - min_ac; 
  set_value(0);
}

void create() 
  {
  item::create();
	shield_logic::create();
  condition::create();
  max_ac = 3; min_ac = 0; ac = 3;
/* for cond_string() in condition.c: */
  cond = max_ac - min_ac; 
  max_cond = max_ac - min_ac; 
  add_alias("escudo"); 
  add_plural("escudos"); 

  // Radix : Oct 1996
  if(!clonep(this_object()))
     catch("/obj/handlers/item_info"->update_armour(this_object()));
} 

int query_armour() { return 1; } 

int query_hands_needed()
  {
  if (twohanded) return 2;
  return 1;
} 

/* moved to /std/item.c    Radix - Jan 18, 1996
string long(string s, int dark) 
  {
// Radix was here to put things in their proper order, Dec 14, 1995
//return cond_string()+::long(s, dark); 
  return ::long(s, dark)+cond_string();
} 
*/

void dest_me() 
  {
  enchant = 0;
  /* Call equip-> dest equipment here when that's done */
  return ::dest_me();
}

/* returns the amount that the weapon was actually adjusted.  Use hit_weapon
if you're doing melee damage to weapon.  This function is for other kinds of
damage and repair to the condition of the weapon.  At this time, I expect all
non-enchanted weapons to have max_ac 3 and min_ac 0.  Adjust_weapon can't
change the ac to anything outside these bounds.  The only way to change max_ac
and min_ac is to enchant the weapon.
*/
int adjust_armour(int mod) 
  {
  int old_ac;
  old_ac = ac;
  ac += mod;
  if (ac < min_ac) 
    ac = min_ac;
  else if (ac > max_ac)
    ac = max_ac;
  mod = ac - old_ac;
  cond += mod;
  value += mod * COST_TO_FIX;
/* This only works if only the first 7-tuple concerns a swing; it doesn't
modify any other tuples that might concern swings, since I dont expect any,
for now. */
  return mod;
}

int hit_armour(int dam) 
  {
  if (dam > 1)
    dam = 1;
/* note this will return a nonpositive int when given a nonnegative int: */
  return adjust_armour(-dam);
}

/* I'm assuming this is right, but I don't know...I borrowed it from Ducky's
   armour.c */
/* The players will have to use detect_magic to know anyway, so it won't
   be used. Baldrick. */
string enchant_string() 
  {
  switch(enchant) 
    {
    case 1 : return "It has a dim, magical glow.\n";
    case 2 : return "It has a faint, magical glow.\n";
    case 3 : return "It has a magical glow.\n";
    case 4 : return "It has a bright, magical glow.\n";
    case 5 : return "It has a very bright, magical glow.\n";
    case 6 : return "It has a brilliant, pulsating, magical glow.\n";
    }
  return "";
}

mixed *armour_stats() 
  {
  int i;
  mixed *ret; 
  string form;
  
  ret = ({ }); 
  ret += ({ 
            ({ "Armour type", query_armour_type_name() }), 
            ({ "Armour AC", armour_ac })
          }); 
  return ret; 
} 

mixed *stats() 
  {
  return 
     ({ 
     ({ "Value (in copper pieces)", query_value() }),
     ({ "Cond", cond }),
     ({ "ac", ac }),
     ({ "holdable", query_holdable() }),
     ({ "Max ac", max_ac }),
     ({ "Min ac", min_ac }),
     ({ "Enchant", enchant }),
     ({ "Weight", weight }),
     ({ "Material", query_material_name() })
    }) + armour_stats(); 
}

/* How much of this is needed ? */
mapping int_query_static_auto_load() 
  {
  mapping tmp;

  tmp = ::int_query_static_auto_load();
  return ([ "::" : tmp,
    "max cond" :max_cond, "no_limbs":twohanded,
          ]);
} /* int_query_static_auto_load() */

mapping query_dynamic_auto_load() 
  {
    mapping tmp;      /* Hamlet */

    tmp = ::query_dynamic_auto_load();  /* Hamlet */
    return ([ "::" : tmp,   /* Hamlet */
     "cond" : cond,
     "enchant":enchant,
     "lowest cond" : lowest_cond,
          ]);
} /* query_dynamic_auto_load() */

void init_static_arg(mapping args) 
  {
  if (!mappingp(args)) return ;
  if (args["::"])
    ::init_static_arg(args["::"]);
  if (!undefinedp(args["max cond"]))
    max_cond = args["max cond"];
  if (!undefinedp(args["no limbs"]))
  twohanded = args["no limbs"];
} /* init_static_arg() */

player_wield(int pos) 
  {
  if (!environment()) return ;
  environment()->set_hold(this_object(), pos);
 /*
  environment()->hold((sizeof(adjectives)?implode(adjectives, " ")+" ":"")
                       +name+" in "+(environment()->query_limbs()[pos]), 1);
 */
} /* player_wield() */

void init_dynamic_arg(mapping map) 
  {
  if (map["::"])
    ::init_dynamic_arg(map["::"]);
  cond = map["cond"];
  lowest_cond = map["lowest cond"];
  enchant = map["enchant"];
  if (map["wielded"])
 /* Not valid function yet till equip.c is done */
   call_out("player_wield",0, map["wielded"]-1);
} /* init_dynamic_arg() */


mapping query_static_auto_load() 
  {
  if (file_name(this_object())[0..10] == "/obj/weapon")
    return int_query_static_auto_load();
  return ([ ]);
} /* query_static_auto_load() */

/** parte weapon **/

int query_attack_type() { return 2; }

string query_attack_type_name() 
{
      return "blunt";
} /* string query_attack_type_name() */

int set_name(string str) 
  {
  ::set_name(str);
  return 1;
}

/* we'll probably keep add_attack, but maube a more describing way than 
 * this ?
 * Baldrick */
/* this add attack routine *has* to be rewritten... */
/* I think I have an idea on how I will do it..
 * Basically the same way as it is now, a mixed array... */
/* But I'll make it more decsriptive..*/
/* Hmm, not compatible with the new one.. 
void add_attack(int slot0, int slot1, string slot2, int slot3, int slot4,
                int slot5, int slot6) 
  {
  int num;
  num = (int)"/table/attack_num"->attack_num(slot2);
  attack_out += ({ slot0, slot1, num, slot3, slot4, slot5, slot6 });
}

*/

/* int arg of delete_attack is the number of the tuple to delete; you wouldn't
want to reference by the values, since two different attacks might have the
same values */

/* Nope, this will go out.. until I have the new add_attack routine/system */
void delete_attack(int i) 
  {
  // attack_out = delete(attack_out, i*7, 7);
}

/* Not, maybe later.. */
void add_temp_attack(int *slots) 
  {
  /*
  int i;
  for (i=0;i<7;i++)
    temp_attack_out += ({ slots[i] });
  */
}

/* int arg of delete_temp_attack is the number of the tuple to delete; you
woulnd't want to reference by the values, since two different attacks might
have the same values */
/* Temp attacks should be named, not numbered.. */

void delete_temp_attack(int i) 
{
   // temp_attack_out = delete(temp_attack_out, i*7, 7);
}

int query_damage_roll()
{
  //Zonzamas '02 como el roll_add puede ser negativo el danyo minimo es 1
  int damage = roll(n_dados, n_caras) + n_bonus;
  return (damage<0?1:damage);
  //  return ( roll(n_dados, n_caras) + n_bonus );
}

// Called by /obj/handlers/item_info.c - Radix
int *query_damage_vals()
{
  return ({ n_dados, n_caras, n_bonus });
}

//Zonzamas '02

void set_min_level(int level){
  min_level = level;
}

void hold(object owner){
  ac_backup = armour_ac;
  n_bonus_backup = n_bonus;
  if (owner->query_level()<min_level){    
    tell_object(owner,"Te sientes algo incomodo usando "+(string)this_object()->short()+".\n");
    armour_ac =(int) armour_ac/(1.0+((min_level-owner->query_level())*10)/min_level);
    n_bonus = - (int)(2+(min_level-owner->query_level()/2));
  }     
}

void unhold(){
  armour_ac = ac_backup;
  n_bonus = n_bonus_backup;
}
