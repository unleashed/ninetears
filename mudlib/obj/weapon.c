/* My rewrite of Danks weapon object.
 * Guess it's basically PF's object tho, with Danks comments..
 * But I have to understand this, so I'm "making" my own
 * Baldrick, april '94 
 * This have to be more complicated than nessesary ?
 * it's a lot of code ...
 * I will remove the attack_out array and replace it with int's
 */

/* std/held ???????????? geeesus.. Dank is incredible..
 * wonder what's happening if I just remove it..
 * Not smart to remove it, have to change the darn thingie tho..

* held.c ? Hmm... thought I did this in std/living/hold.c 
 * Should be able to inherit std/object instead.. 
 * Adding it to std/item instead.. 
 */
inherit "/std/item";
inherit "/std/weapon_logic";
inherit "/std/basic/condition"; 

#include "move_failures.h";
#define WEAPON_TABLE "/table/weapon_table.c"
#define COST_TO_FIX 300 
#define SIZE 8

/* attack_out consists of concatenated 7-tuples */

int twohanded;   
int enchant,value_adjustment;

/* AC in a weapon ????? why ??? */
/* Magical weapons can work as armour tho.. 
 * but at least it should default as 0
 * We should wait with implementing it 
 * Baldrick. */
/* I know now, it's how much damage the weapon itself stands.. */

int ac, max_ac, min_ac;

/* this is the values from the weapon_table: */
/* Look at /table/weapon_table for explanation. */

string weapon_name;
int gp_cost, 
    ench_gp_cost,
    wep_weight,
    attack_type,
    material;

private int rolls,
            dice,
            roll_add;


static object wielder; 

/* HACK !!! HAS TO BE FIXED ASAP"!!!!!! */
/* Baldrick 9 apr '94 */
/* these can de removed after I have fixed the auto_load thingie..*/
mixed attack_name, attack_data, skill;

void set_value(int i);
void set_twohanded(int flag);

/* here is the new setup routine, will make the whole a lot cleaner.. */
void set_base_weapon(string lookup)
  {
  int *data;
  
  data = WEAPON_TABLE->lookup_weapon_data(lookup);
  weapon_name = lookup;
  gp_cost = data[0];
  ench_gp_cost = data [1];
  wep_weight = data [2];
  attack_type = data [3];
  rolls = data [4];
  dice = data [5];
  roll_add = data [6];
  material = data [7]; 

  /* calculate the twohanded. If the weapon has a max damage of more than 
   * 8 it will be defaulted to twohanded. */
  if (((rolls * dice) + roll_add) > 8)
    set_twohanded(1); 

  set_weight(wep_weight);
  set_value(gp_cost);
}
string cond_string() { return condition::cond_string() ;}

string query_weapon_name()
  {
  return weapon_name;
}

int query_attack_type() { return attack_type; }

string query_attack_type_name() 
  {
  switch (attack_type)
    {
    case 1:
      return "slashing";
    case 2:
      return "blunt";
    case 3:
      return "piercing";
    default:
      return "unknown";
    }
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
    default:
      return "unknown";
   }
} /* string query_material_name */

/* why here? and not in /std/object ? Baldrick. */
void set_value(int i) 
  {
  if (enchant <= 0)
    if (gp_cost > 0)
      value = gp_cost * 100 + value_adjustment + (max_cond - cond) *
        COST_TO_FIX;
    else     
    /* negative values in data[0] mean silver, not gold */
      value = gp_cost * -10 + value_adjustment + (max_cond - cond) *
        COST_TO_FIX;
  else
    value = ench_gp_cost * exp(2,enchant-1) + 
            value_adjustment + (max_cond - cond)
      * COST_TO_FIX;
}

void adjust_value(int i) 
  {
  value_adjustment = i * 100; /* to convert from gp to cp */
}

void set_enchant(int i) 
  {
  int mod;
  if (i > 6)
    i = 6;
  if (i < -3)
    i = -3;
  /* Nope, not the weight, but what ? */
  wep_weight = i;
/* tohit bonus for this weapon is enchant */
/* modify by the amount that the new enchant exceeds the old enchant */
  mod = i - enchant;
  roll_add += mod; 
  ac += mod;
  if (wielder)
    wielder->adjust_weapon(mod);
  max_ac += mod;
  min_ac += mod;
  enchant = i;
  set_value(0);
} 

void adjust_enchant(int i) 
  {
  set_enchant(enchant + i);
}

int query_enchant() 
  {
  return enchant;
}
/* used to be set_hand() */
void set_twohanded(int flag) { twohanded = flag; }
int query_twohanded() { return twohanded; }

int set_name(string str) 
  {
  ::set_name(str);
  return 1;
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

void create() 
  {
  item::create();
  weapon_logic::create();
  condition::create();
  max_ac = 3; min_ac = 0; ac = 3;
/* for cond_string() in condition.c: */
  cond = max_ac - min_ac; 
  max_cond = max_ac - min_ac; 
  weapon_logic::create();
  add_alias("weapon"); 
  add_plural("weapons"); 
  set_holdable(1);

  // Radix : Oct 1996
  if(!clonep(this_object()))
     catch("/obj/handlers/item_info"->update_weapon(this_object()));
} 

int query_weapon() { return 1; } 

int query_hands_needed()
  {
  if (twohanded) return 2;
  return 1;
} 
int query_damage_roll()
  {
  return ( roll(rolls, dice) + roll_add );
}

// Called by /obj/handlers/item_info.c - Radix
int *query_damage_vals()
{
  return ({ rolls, dice, roll_add });
}

/* dank: wield() and unwield() are always called from creature that wields the
weapon, even if a spell is thrown on the weapon or the weapon breaks.  These
are the functions to mask if you want the weapon to do something special when
wielded.  Ask me how to do it if you want to mask.
*/ 
/* Naah........(baldy) good idea tho.. 
int wield(object ob) 
  {
  wielder = ob; 
  return 1; 
}

int unwield() 
  {
  if (enchant >= 0) 
    {
    wielder = 0;
    return 1;
    }
  else 
    {
    tell_room(environment(wielder), "The weapon wielded by "+
      wielder->query_name()+" won't come loose!\n.", wielder);
    tell_object(wielder, "Your wielded weapon won't come loose!\n");
    return 0;
    }
}
*/

/* This is moved to std/item, Baldrick.
move(mixed dest, mixed messout, mixed messin) 
  {
  if (!wielder)
    return ::move(dest, messout, messin);
  else
    if (wielder->unwield_weapon(this_object()))
      return ::move(dest, messout, messin);
    else 
      {
      tell_room(environment(wielder), "The weapon wielded by "+
        wielder->query_name()+" won't come loose!\n.", wielder);
      tell_object(wielder, "Your wielded weapon won't come loose!\n");
      return MOVE_NO_DROP;
      }
}
*/

void dest_me() 
  {
  enchant = 0;
  return ::dest_me();
}

/* returns the amount that the weapon was actually adjusted.  Use hit_weapon
if you're doing melee damage to weapon.  This function is for other kinds of
damage and repair to the condition of the weapon.  At this time, I expect all
non-enchanted weapons to have max_ac 3 and min_ac 0.  Adjust_weapon can't
change the ac to anything outside these bounds.  The only way to change max_ac
and min_ac is to enchant the weapon.
*/
int adjust_weapon(int mod) 
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
  // Nope, no need to add the cost this way... 
  // attack_out[3] += mod;
  roll_add += mod;
  if (wielder)
    wielder->adjust_weapon(mod);
  return mod;
}

int hit_weapon(int dam) 
  {
  if (dam > 1)
    dam = 1;
/* note this will return a nonpositive int when given a nonnegative int: */
  return adjust_weapon(-dam);
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

mixed *weapon_stats() 
  {
  int i;
  mixed *ret; 
  string form;
  
  ret = ({ }); 
  // for (i=0;i<sizeof(attack_out);i+=7) 
  ret += ({ 
            ({ "Attack", query_attack_type_name() }), 
            ({ "Damage", rolls + "D"+ dice + "+" + roll_add })
          }); 
  return ret; 
} 

mixed *stats() 
  {
  return 
     ({ 
     ({ "Value (in copper pieces)", query_value() }),
     ({ "ac", ac }),
     ({ "Cond", cond }),
     ({ "Max ac", max_ac }),
     ({ "Min ac", min_ac }),
     ({ "Enchant", enchant }),
     ({ "Weight", weight }),
     ({ "Material", query_material_name() }),
     ({ "Base Damage", rolls + "d"+ dice + "+" + roll_add }),
  }) + weapon_stats();
}


mapping int_query_static_auto_load() 
  {
  mapping tmp;

  tmp = ::int_query_static_auto_load();
  return ([ "::" : tmp,
    "attack name" : attack_name, "attack data" : attack_data, "skill" : skill,
    "max cond" :max_cond, "no_limbs":twohanded,
          ]);
} /* int_query_static_auto_load() */

mapping query_dynamic_auto_load() 
  {
    mapping tmp;    /* Hamlet */

    tmp = ::query_dynamic_auto_load(); /* Hamlet */
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

void init_dynamic_arg(mapping map) 
  {
  if (map["::"])
    ::init_dynamic_arg(map["::"]);
  cond = map["cond"];
  lowest_cond = map["lowest cond"];
  enchant = map["enchant"];
} /* init_dynamic_arg() */


mapping query_static_auto_load() 
  {
  if (file_name(this_object())[0..10] == "/obj/weapon")
    return int_query_static_auto_load();
  return ([ ]);
} /* query_static_auto_load() */

