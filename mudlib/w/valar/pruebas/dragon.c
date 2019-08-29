//  Inheritable dragon base file by the hand of Dwimmerlaik
//  with invaluable aid from Radix.

//  I would greatly appreciate if you were to refrain from
//  making any changes to this file unless I know about it.
//  Dread Dwimmerlaik

inherit "obj/monster";

#define AN attacker->query_cap_name()
#define DN defender->query_cap_name()

void set_age(int i);   /* This MUST be set first */
void set_color(string str);
void set_breath_type(string type);
void set_breath_damage(int d);
void set_breath_chance(int c);
void set_in_lair(int l);
void set_breath_mess(string str);
void set_target_mess(string str);
void create_dragon();

string color,
       breath_mess,    /*  what the room sees  */
       target_mess,    /* what the target sees */
       breath_type;
int BASE,
    age,  x, l,
    breath_dam,
    breath_chance,
    in_lair;

void set_age(int i)  {
  switch(i)  {
    case(1) :
    case(2) :
    case(3) :
    case(4) :
    case(5) :
    case(6) :
    case(7) :
    case(8) :
    case(9) :
    case(10) :
    case(11) :
    case(12) :
      age = i;
    break;
    default : age = 4;
  }
}  /*  set_age()  */

void set_color(string str)  {
  switch(str)  {

    case("black") :
      color = str;
      BASE = 12;
       set_align(3000);
       set_ethics(1000);
      if(age == 1)  {  set_level(17);   }
      if(age >= 2 && age <= 3)  {  set_level(20);   }
      if(age >= 4 && age <= 5)  {  set_level(23);   }
      if(age >= 6 && age <= 7)  {  set_level(26);   }
      if(age >= 8 && age <= 9)  {  set_level(29);   }
      if(age >= 10 && age <= 11)  {  set_level(32);   }
      if(age == 12)  {  set_level(35);   }
      break;

    case("blue") :
      color = str;
      BASE = 14;
       set_align(3000);
       set_ethics(-1000);
      if(age == 1)  {  set_level(22);   }
      if(age >= 2 && age <= 3)  {  set_level(25);   }
      if(age >= 4 && age <= 5)  {  set_level(28);   }
      if(age >= 6 && age <= 7)  {  set_level(31);   }
      if(age >= 8 && age <= 9)  {  set_level(34);   }
      if(age >= 10 && age <= 11)  {  set_level(37);   }
      if(age == 12)  {  set_level(40);   }
      break;

    case("brass") :
      color = str;
      BASE = 12;
       set_align(-200);
       set_ethics(1000);
      if(age == 1)  {  set_level(17);   }
      if(age >= 2 && age <= 3)  {  set_level(20);   }
      if(age >= 4 && age <= 5)  {  set_level(23);   }
      if(age >= 6 && age <= 7)  {  set_level(26);   }
      if(age >= 8 && age <= 9)  {  set_level(29);   }
      if(age >= 10 && age <= 11)  {  set_level(32);   }
      if(age == 12)  {  set_level(35);   }
      break;

    case("bronze") :
      color = str;
      BASE = 14;
       set_align(-3000);
       set_ethics(-2000);
      if(age == 1)  {  set_level(22);   }
      if(age >= 2 && age <= 3)  {  set_level(25);   }
      if(age >= 4 && age <= 5)  {  set_level(28);   }
      if(age >= 6 && age <= 7)  {  set_level(31);   }
      if(age >= 8 && age <= 9)  {  set_level(34);   }
      if(age >= 10 && age <= 11)  {  set_level(37);   }
      if(age == 12)  {  set_level(40);  }
      break;

    case("copper") :
      color = str;
      BASE = 13;
       set_align(-1500);
       set_ethics(1500);
      if(age == 1)  {  set_level(20);   }
      if(age >= 2 && age <= 3)  {  set_level(23);   }
      if(age >= 4 && age <= 5)  {  set_level(26);   }
      if(age >= 6 && age <= 7)  {  set_level(29);   }
      if(age >= 8 && age <= 9)  {  set_level(32);   }
      if(age >= 10 && age <= 11)  {  set_level(35);   }
      if(age == 12)  {  set_level(38);   }
      break;

    case("gold") :
      color = str;
      BASE = 16;
       set_align(-5500);
       set_ethics(-5500);
      if(age == 1)  {  set_level(32);   }
      if(age >= 2 && age <= 3)  {  set_level(35);   }
      if(age >= 4 && age <= 5)  {  set_level(38);   }
      if(age >= 6 && age <= 7)  {  set_level(41);   }
      if(age >= 8 && age <= 9)  {  set_level(44);   }
      if(age >= 10 && age <= 11)  {  set_level(47);   }
      if(age == 12)  {  set_level(50);   }
      break;

    case("green") :
      color = str;
      BASE = 13;
       set_align(3000);
       set_ethics(-1500);
      if(age == 1)  {  set_level(20);   }
      if(age >= 2 && age <= 3)  {  set_level(23);   }
      if(age >= 4 && age <= 5)  {  set_level(26);   }
      if(age >= 6 && age <= 7)  {  set_level(29);   }
      if(age >= 8 && age <= 9)  {  set_level(32);   }
      if(age >= 10 && age <= 11)  {  set_level(35);   }
      if(age == 12)  {  set_level(38);   }
      break;

    case("red") :
      color = str;
      BASE = 15;
       set_align(5500);
       set_ethics(5500);
      if(age == 1)  {  set_level(27);   }
      if(age >= 2 && age <= 3)  {  set_level(30);   }
      if(age >= 4 && age <= 5)  {  set_level(33);   }
      if(age >= 6 && age <= 7)  {  set_level(36);   }
      if(age >= 8 && age <= 9)  {  set_level(39);   }
      if(age >= 10 && age <= 11)  {  set_level(42);   }
      if(age == 12)  {  set_level(45);   }
      break;

    case("silver") :
      color = str;
      BASE = 15;
       set_align(-2500);
       set_ethics(-1500);
      if(age == 1)  {  set_level(27);   }
      if(age >= 2 && age <= 3)  {  set_level(30);   }
      if(age >= 4 && age <= 5)  {  set_level(33);   }
      if(age >= 6 && age <= 7)  {  set_level(36);   }
      if(age >= 8 && age <= 9)  {  set_level(39);   }
      if(age >= 10 && age <= 11)  {  set_level(42);   }
      if(age == 12)  {  set_level(45);   }
      break;

    case("white") :
      color = str;
      BASE = 11;
       set_align(3000);
       set_ethics(3000);
      if(age == 1)  {  set_level(12);   }
      if(age >= 2 && age <= 3)  {  set_level(15);   }
      if(age >= 4 && age <= 5)  {  set_level(18);   }
      if(age >= 6 && age <= 7)  {  set_level(21);   }
      if(age >= 8 && age <= 9)  {  set_level(24);   }
      if(age >= 10 && age <= 11)  {  set_level(27);   }
      if(age == 12)  {  set_level(30);   }
      break;

    default : color = "green";
  }
}  /*  set_color()  */

void set_breath_type(string type) {
  switch(type) {

    case("acid") :
    case("air") :
    case("cold") :
    case("electrical") :
    case("fire") :
    case("magic") :
    case("magical") :
    case("poison") :
      breath_type = type;
      break;
    default : 
      if(color == "black")   breath_type = "acid"; 
      if(color == "blue")    breath_type = "electrical"; 
      if(color == "brass")   breath_type = "fire"; 
      if(color == "bronze")  breath_type = "electrical"; 
      if(color == "copper")  breath_type = "acid"; 
      if(color == "gold")    breath_type = "fire"; 
      if(color == "green")   breath_type = "poison"; 
      if(color == "red")     breath_type = "fire"; 
      if(color == "silver")  breath_type = "cold"; 
      if(color == "white")   breath_type = "cold"; 
  }
}  /*  set_breath_type()  */

void set_in_lair(int l) {
  switch(l) {
    case(0) :
      set_aggressive(0);
      in_lair = l;
      break;
    case(1) :
      set_aggressive(2);
      adjust_tmp_str(20);
      adjust_tmp_dex(20);
      in_lair = l;
      break;
    default : in_lair = 0;
  }
}  /*  set_in_lair()  */

void set_breath_damage(int d) {  breath_dam = d; }

void set_breath_chance(int c) {  breath_chance = c; }

void set_breath_mess(string str) {  breath_mess = str; }

void set_target_mess(string str)  {  target_mess = str;  }

void create_dragon()  {
   set_name(color+" dragon");
   set_short(capitalize(color)+" Dragon");
   set_long("This "+query_short()+" is looking rather testy.\n\n");

   adjust_tmp_damage_bon(age);
   set_random_stats(12, 15+random(age));
   set_gender(0);
   set_race("dragon");
 
   add_alias("dragon");
   add_alias("Dragon");
   set_main_plural(color+" dragons");
   add_plural("dragons");
   add_plural("Dragons");
   set_max_hp( ((BASE + age) * 70) + random(500) );
   set_gp(1000);
   set_cha((random(30)) + (random(age)));
   set_kill_xp((BASE * age) * 150);
   set_thac0(100 - (BASE * age));
   set_ac(200 - ((BASE * age) + random(100)));
   set_main_plural(query_short()+"s");

   set_breath_mess("\nThe dragon leans forward and gouts its "
                   "fearsome breath!!\n\n");
   set_target_mess("\nYou have been gouted upon!!\n\n");
   set_breath_damage(50);
   set_breath_chance(30);
   set_breath_type(" ");

   add_property(breath_type, 100);
}  /*  create_dragon()  */

int unarmed_attack(object target,object me) {
  object *att;
  att = (object*)me->query_attacker_list();
  monster::unarmed_attack(att[random(sizeof(att))],me);
  monster::unarmed_attack(att[random(sizeof(att))],me);
  monster::unarmed_attack(att[random(sizeof(att))],me);
}  /*  unarmed_attack()  */

mixed valid_attack() {
  int two = random(2);
  int three = random(3);
  int four = random(4);
  int five = random(5);
  int BREATH = random(100);
  int CHANCE = breath_chance;
  int GP = attacker->query_gp();
  int TYPE = attacker->query_breath_type();

if(BREATH >= 100 - CHANCE)  {
  if(GP >= 20)  {
      if(x == 0)    {
          say("%^BOLD%^"+AN+" rears its head back and its eyes roll "
                    "over white.\n\n%^RESET%^");
          x = x + 1; }
      else if(x == 1)    {
          x = 0;
          say("%^BOLD%^YELLOW%^"+breath_mess+"%^RESET%^");
          tell_object(defender,sprintf("%-=*s",defender->query_cols(),
                      "%^BOLD%^RED%^"+target_mess+"%^RESET%^"));
          attacker->adjust_gp(-20);
        breath_dam=(breath_dam*(100-(int)defender->query_property(TYPE)))/100;
          defender->adjust_hp(-(age + random(breath_dam)));    }
        }
    }

    return([
      "knee"  :({AN+" slashes "+DN+" with its claws.\n",
                 "You slash "+DN+".\n",
                 AN+" slashes you with its claws.\n"}),
      "punch" :({AN+" slashes "+DN+" with its claws.\n",
                 "You slash "+DN+".\n",
                 AN+" slashes you with its claws.\n"}),
      "kick"  :({AN+" bites a gaping wound into "+DN+".\n",
                 "You bite "+DN+".\n",
                 AN+" bites a gaping wound into you.\n"})  ]);
}  /*  valid_attack()  */

string query_dragon_title(string i)  {
  switch(i)  {
    case(1) :
      return("hatchling");
      break;
    case(2) :
      return("very young");
      break;
    case(3) :
      return("young");
      break;
    case(4) :
      return("juvenile");
      break;
    case(5) :
      return("young adult");
      break;
    case(6) :
      return("adult");
      break;
    case(7) :
      return("mature adult");
      break;
    case(8) :
      return("old");
      break;
    case(9) :
      return("very old");
      break;
    case(10) :
      return("venerable");
      break;
    case(11) :
      return("wyrm");
      break;
    case(12) :
      return("great wyrm");
      break;
  }
}  /*  query_dragon_title()  */

int query_dragon() { return(1); }
string query_color() { return(color); }
string query_dragon_color() { return(color); }
string query_race() { return("dragon"); }
string query_breath_type() {  return (breath_type); }
int query_breath_damage() {  return (breath_dam); }
int query_breath_chance() {  return (breath_chance); }
int query_in_lair() { return (in_lair); }
string query_breath_mess() {  return (breath_mess); }
string query_target_mess() {  return (target_mess); }


/*************************************************************
**************************************************************
** Note to anyone wishing to use dragon.c to create a beast **
** of dragonkind....                                        **

If you are going to use dragon.c, please look through it and
be familiar with what everything does. Set everything that is
settable. EVERYTHING.

X) : Dread Dwimmerlaik

 ((=========================================================))
        Use this as a psuedo-guide when using dragon.c
                  Dwimmerlaik : Nov. 21, 1995
 ((=========================================================))

inherit "/obj/dragon.c";

void setup() {

  set_name("Ted the raging red dragon");
  add_alias("ted");

  set_age(6);    Settable ages are 1 through 12 ( 1 being a hatchling
                 12 being a greaty wyrm );  Age presets thac0 and level
                 Age MUST be set first.

  set_color("red");  Settable colors are : black, blue, brass, bronze,
                     copper, gold, green, red, silver and white. Evil
                     dragons are actual colors, good dragons are the
                     metal colors, i.e. brass, gold, etc.

  create_dragon();  This must be set to make this monster a dragon. Adds
                    defaults, attacks and special attacks. Also adds logical
                    aliases and plurals, i.e. dragon, dragons, etc.

  set_breath_type("fire");  Settable types are : acid, cold, electrical,
                            fire, magic, magical, poison. Must set this
                             so that player resistances may be taken into
                             account when hit with the dragon's breath
                             weapon.

  set_breath_damage(150);  Can be set to anything. This is the maximum
                           amount of damage a breath weapon can do in
                           one strike. Damage for this case would be
                           1 - 150 (*not counting possible player
                                     resistances*)

  set_breath_chance(50);  Can be set from 1 - 100. Quite simply, the
                          higher the number, the greater the frequency
                          of times the dragon employs the breath weapon.

  set_in_lair(1);  Can be set either 0 or 1. If set to 1, the dragon will
                   be aggressive to those who enter into the room it is in,
                   otherwise it will sit dormant.

  set_breath_mess("\nThe dragon rears back and gouts his breath!!\n\n");
           This sets the message that the room sees when a
           dragon employs its breath weapon.

  set_target_mess("\nOw! That hurt!!\n\n");
           This sets the message that the target of the breath
           weapon sees.

  ********----  Now comes the traditional stuff ----********
  ********----  note that create_dragon(); has  ----********
  ********----     defaults for most of this    ----********

  set_short("ted the raging red dragon");
  set_long("\nYup.. it's a dragon.\n\n");

*******************************************************************
******************************************************************/

