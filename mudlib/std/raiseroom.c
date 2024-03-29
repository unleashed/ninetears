/* A temple for raising..
 * Needs money to work...
 * Inherits collect.c that uses the bank-handler to handle accounts.
 * Baldrick.
 */

#define HEALER "/baseobs/monsters/healer.c"
inherit "/std/collect";

int clean_up_room(int flag) { return 1; }
void clean_up(int flag) { }
string nurs;

void setup()
  {
   this_object()->add_property("no_undead",1);
  set_short("Raiseroom Object.");
}

void init()
  {
   this_object()->add_property("no_undead",1);
  add_action ("do_raise", "raise");
  ::init();
} /* void init */

void set_helper_name(string str)
  {
  nurs = str;
  return;
}

/* Here is the raise thingie. It will start with checking if there is a jill
 * in the room, so he can call upos the high priest for raise.
 * Then the usual check on who.
 * So will the moneystuff happen. It will check if the player has enoug money.
 * and raise him if the player has.
 */

int do_raise(string str)
  {
   object priest, poor_guy;
   object *olist;

//tell_object(this_player(), "Clamas por una resurrecion para "+str+".\n");

  if (str=="me") {
    poor_guy=this_player();
//tell_object(this_player(), "Eres me.\n");
  }
   else
   {
      notify_fail("Raise a quien?\n");
      if(!str) return 0;
      olist = find_match(str,this_object());
      if(!sizeof(olist)) return 0;
      poor_guy = olist[0];
      if(!find_living(str)) return 0;
   }
   if(!poor_guy->query_dead())
   {
     notify_fail("Por que pedir un levantar muertos si no lo necesitas?\n");
    return 0;
   }
//tell_object(this_player(), "Realmente parece q tas muerto.\n");

  if (!find_match(nurs, environment(this_player())))
    {
    notify_fail("The priestess is not here to help you with the " 
                "raising. You have to wait for her.\n");
    return 1;
    }

//tell_object(this_player(), "Hay nurse "+nurs+".\n");
 
    /*if ((int)poor_guy->query_level() > 10) 
    {
    cost = (int)poor_guy->query_level() * 5;
    if(!get_money(cost))
      {
      tell_room(this_object(), "The Nurse says: Due to sad lack of "
                    "money we will not be able to raise you.\n");
      return 1;
      } *//* if
    }  if int poorguy.. */


  priest = new(HEALER);
//tell_object(this_player(), "Priest creado.\n");

   priest->move(this_object());

//tell_object(this_player(), "Nos disponemos a levantar a "+str+".\n");
  if(priest->do_raising(poor_guy)) {
  tell_room(this_object(), "The Nurse"
            " walks out and comes back with an old man "
             "dressed in ceremonial clothing.  He chants a spell.\n");
  tell_room(this_object(), "The priest says: You are now alive again. " 
             "Be more careful this time.\n");
  tell_room(this_object(), "The priest walks out of the room.\n");
  }
  priest->dest_me();
  return 1;
} /* do  raise */
