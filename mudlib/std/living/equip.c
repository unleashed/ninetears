/* The "merger file" for wear.c and hold.c */

/* shall I add combat here ? or have it in living ? */

inherit "/std/living/hold.c";
inherit "/std/living/wear.c";
inherit "/std/living/combat.c";

private static int worn_ac;
mixed *stats()
{
   return hold::stats();
}
void create()
  {
  hold::create();
  wear::create();
  combat::create();
  worn_ac = 0;
}
/* the equip_ac will be added to body_ac and then calculated to a
 * defender_ac that weapon_logic can query on */
/* Body_ac will be added to either stats.c or skills.c 
 * not sure about the yet.. */

int query_equip_ac()
  {
   return this_object()->query_worn_ac() + this_object()->query_held_ac();
}

// do_equip() by Aragorn
//
// Has to be slightly intelligent as the NPCs depend on this for
//
// Here is how it works (should work :-)
//
// 1. A weapon
// 2. A piece of holdable armour (holdable non-weapon with ac)
// 3. Anything holdable, starting with weapons, then armour, then the rest
// 4. Wearable armour (wearable objects with ac)
// 5. Wearable objects
//
// This means we're going to have a _lot_ of arrays here to do a basic
// job. Luckily equip is only called every blue moon. :-)

/* Ok, Aragorn is finished, time for me to clean it up and fix the bugs,
 * he forgot to put query_wearable & query_holdable in here, so everything is..
 * He had holdable, but not wearable..
 */

int do_equip(string str)
   {
   object *obs, *holds, *wears;
   int i, j;
   int size;

   // Assum going to tell us something about the autoequip
   if (str && stringp(str)) {
      if (str == "off") {
         this_object()->remove_property("autoequip");
         write("Automatic equip at login turned OFF.\n");
      } else if (str == "on") {
         this_object()->add_property("autoequip","yes");
         write("Automatic equip at login turned ON.\n");
      } else
         write("Usage : equip [on|off].\n(NOTE! on/off are for automatic equip at login.)\n");
      return 1;
   }

   // Don't blow your top, the empty array is a shared array. No memory wasted.
   holds = wears = ({ });

   // Get the objects from the player, we don't care about what he's got
   // in various containers
   obs = all_inventory(this_object());

   // Split into holdables and wearables.
   for(i=0;i<sizeof(obs);i++)
      {
      if(!interactive(this_object()) && obs[i]->
        query_static_property("pc_gave_npc")) continue;
      if ( (obs[i]->query_holdable()) && !obs[i]->query_in_use() )
             {
               if(!obs[i])  continue;  /* Hamlet */
         holds += ({ obs[i] });
         }
        /* Items can be both not_holdable & not_wearable, so we have to 
         * check both. 
         */
            if(!obs[i])  continue;   /* Hamlet */
      if ( (obs[i]->query_wearable()) && !obs[i]->query_in_use() )
         {
            if(!obs[i])  continue;   /* Hamlet */
        wears += ({ obs[i] });
          }
      }

   // First of all, take care of holdables.
   // The 'if' here is to save a few for-loop checks later

   if (sizeof(holds)) 
      {
      object *wpns, *harms;

      wpns = harms = ({ });

      // Split in weapons, holdable armour and other objects
      for(i=0;i<sizeof(holds);i++)

         if (holds[i]->query_weapon())
            wpns += ({ holds[i] });
         /* Weapons can have AC, but they are taken care of by the above */
         else if (holds[i]->query_ac())
            harms += ({ holds[i] });
      holds = holds - wpns - harms;

      // Wield a weapon, remember to check if it's actually wielded
      // as it may be a twohanded weapon (or worse) and the person
      // may only have 1 hand. I.e. a loop...

      for(j=0;j<sizeof(wpns);j++)
        if (this_object()->hold_ob(wpns[j])) {
           wpns -= ({ wpns[j] });
           break;
        }

      // Time for a shield of some sort.
      // Note the flaw in the logic:
      //    Someone as a twohanded weapon, a onehanded weapon and a shield.
      //    Assuming the person has 2 hands the two handed weapon _might_
      //    get wielded. Would 1 weapon and 1 shield be better?

      for(j=0;j<sizeof(harms);j++)
        if (this_object()->hold_ob(harms[j])) {
           harms -= ({ harms[j] });
           break;
        }

      // Now just pile the rest of the objects in, starting with weapons
      // Note that we can't really find out if the hold array is full or
      // not. Need another function in hold.c for that.
      // As the number of objects in someone inv tend to be low, this ain't
      // too bad...

      for(j=0;j<sizeof(wpns);j++) this_object()->hold_ob(wpns[j]);

      // More holdable armour, same problem as above.
      for(j=0;j<sizeof(harms);j++) this_object()->hold_ob(harms[j]);

      // holding rest of junk (torches, whatever)
      for(j=0;j<sizeof(holds);j++) this_object()->hold_ob(holds[j]);

      // End of the line for holdable objects. Either we've got
      // no hands left or no holdable objects left.
   }

   // Then put some clothes/armour on the naked critter.

   if (sizeof(wears)) {
      object *warms;

      warms = ({ });

      // Split in wearable armours and other wearables

      for(i=0;i<sizeof(wears);i++)
         if (wears[i]->query_ac())
            warms += ({ wears[i] });

      // Subtract one from the other to split the original array
      wears -= warms;

      // First of all, we burn through the loop of wearable armour
      for(j=0;j<sizeof(warms);j++) 
        this_object()->wear_ob(warms[j]);

      // Then anything without ac.
      for(j=0;j<sizeof(wears);j++) 
        this_object()->wear_ob(wears[j]);

      // End of line here as well.
      // No more objects to wear or no more slots free.
   }

   // Mission accomplished
   return 1;
}
