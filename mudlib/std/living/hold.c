/* This equip code was started on by Dank.
 * It is completely rewritten by Baldrick, april '94
 */
/* Amptutated and cursed hands is removed. Will be added later. */
/* Dank used only tho hands, This will be "unlimited" hands.
 * so it won't be any "left" and "right" hand here.
 * Right now I am afraid shields won't work.
 * Will add that in version 2...:=)
 */

static private mixed *held_ob;
static private int free_hands_left;
static private int held_ac;

// prototypes:

int find_empty_slot(object ob, int nh, mixed *h);
void reset_hands();

object *query_held_ob() { return held_ob; }

// Support functions for the rest of the player object.

/* This is missing.. 
 * Check if the object is held.
 * Baldrick, adding sept '94 
 */
/* Hrmf.. I'm drunk.. I have query_in_use..:=) 
 * Don't need this one then..

int query_held(object ob)
  {
  int i;
  for (i=0;i>sizeof(held_ob);i++)
    {
    if (ob == held_ob[i])
      return 1;
    }
  return 0;
} */ /* int query_held */

int is_shield(mixed ob) 
{
    return (objectp(ob) && (int)ob->query_shield());
}

// This function is just used to filter out weapons from the 
// array of held objects.
int is_weapon(mixed ob) 
{
    return (objectp(ob) && (int)ob->query_weapon());
}

// This function returns an array containing all the weapons
// that are currently wielded. If no weapons wielded, an empty
// array is returned. -A
mixed *query_weapons_wielded() 
{
    return filter_array(held_ob, "is_weapon",this_object());
}


mixed *query_shields_held() 
{
    return filter_array(held_ob, "is_shield",this_object());
}


create() 
{
    held_ob = ({ });
    held_ac = 0;
    reset_hands();
}

/* Ac in here ? think I'll stick it to living/armour.c or armour_logic */
/* Nope, can be ac in shields and special weapons */

int query_held_ac() { return held_ac; }

/* Should reset held_ob instead. */
/* probably */

void reset_hands()
{
   object ob;
    // this shall be the correct line:
    //free_hands_left = query_limbs(); 
   ob = this_object()->query_race_ob();
   if(ob)
   {
      free_hands_left = ob->query_limbs();
   }
   else
    free_hands_left = 2;
    held_ob = allocate(free_hands_left);
} /* reset_hands */

/* The free_hand_left is a quickie, easier to have an int than go through
 * calc_free_hands all the time.. */

int query_free_hands_left()
{
    return free_hands_left;
}

/* this wil be in living/wear I think */
/* We need a dest_holding here.. will add it later.. */
/*
void dest_held()
  {

}
*/

int unhold_ob(object ob) 
{
    int slot;
    if ((slot = member_array(ob, held_ob)) == -1) 
    { 
	notify_fail("You don't hold this item.\n");
	return 0;
    }
    // Taniwha 1996
    if(ob->set_in_use(0) == 0)
    {
	held_ob[slot] = 0;
	// Not really needed but good for speed.
	// sanity check should be run against held_ob array every so often
	free_hands_left += (int)ob->query_hands_needed();

	tell_object(this_object(), "You lower your " + 
	  (string)ob->query_short() + ".\n");
	held_ac -= (int)ob->query_ac();
    }
    else tell_object(this_object(),"You can't unhold your "+
	  (string)ob->query_short() + ".\n");
    return 1;
}

status hold_ob(object ob) 
{
    int weap_hands; // hands the weapon needs.
    int slot;
    object gobj;

    /** Check to make sure weapon is an allowed weapon **/

    // Taniwha 1995, make it work ...
    if(ob->query_weapon())
    {
	gobj = this_object()->query_guild_ob();
	if( gobj && !gobj->query_legal_weapon(ob->query_weapon_name()))
	{
	    tell_object(this_object(),"You lack the skill to wield this weapon.\n");
	    return 1;
	}
    }
    if(ob->query_armour())
    {
	gobj = this_object()->query_guild_ob();
	if( gobj && !gobj->query_legal_armour(ob->query_armour_name()))
	{
	    tell_object(this_object(),"You lack the skill to wield this armour.\n");
	    return 1;
	}
    }

    /* Maybe this check is/can be another place ? */
    /* Made a query_holdable in living.c.. */
    /*
    if (!ob->query_weapon())
      return notify_fail("Right now, the only you can hold is weapons.\n");
    */

    weap_hands = (int)ob->query_hands_needed();
    // The find_empty_slot can check for and output things like
    // this. -A
    if (free_hands_left < weap_hands)
    {
	notify_fail("You don't have enough hands left to hold this weapon.\n");
	return 0;
    }
    if ((slot = find_empty_slot (ob, weap_hands, held_ob)) == -1)
    {
	notify_fail("Sorry, can't hold it.\n");
	return 0;
    }
// Taniwha 1996
   if(!ob->set_in_use(1)) return 0;
    held_ob[slot] = ob;
    held_ac += (int)ob->query_ac();
    free_hands_left -= weap_hands; 
    tell_object(this_object(), "You hold " + (string)ob->short() + ".\n");
    return 1;

} /* status hold_ob */

/* Returns a penalty to hit for using two weapons at once
 * based on guild object.
  * Wonderflug, oct 95
  */
int query_dual_wield_penalty()
{
    object gob;

    if ( sizeof(held_ob) <= 1 || !is_weapon(held_ob[0])
      || !is_weapon(held_ob[1]) )
	return 0;

  if ( !this_object()->query_guild_ob() ||
       !objectp(gob=load_object(this_object()->query_guild_ob())) )
	return 50;
    else
	return gob->query_dual_wield_penalty(this_object(), held_ob[0], held_ob[1] );
}




/* Returns what's in what hand, will traverse through the hands.
 * have to take care of two handed (or more) weapons, can't return an iten for both hands then..
 */
mixed *stats() 
{

}

/* Add for new weapon_logic.c */
/* Look in /w/sojan/combat/excode.new for explanation. */
/* Probably be in living/armour.c */
int shield_bonus()
{
    return 0;
}

// This function coded by Aragorn@NANVAENT for Final Realms
// No guarantee whatsoever... ;-)

int find_empty_slot(object ob, int nh, mixed *h) {

    int i, good, start_slot;

    // How many hands do we need?   
    // sent from hold,,
    nh = (int)ob->query_hands_needed();

    // No hands? Not a holdable object.
    // More hands than we have needed? Skip it...
    if (!nh || nh > sizeof(h)) return -1;

    // This is the counter of how many good slots we've got in a row.
    good = 0;

    // Loop through all slots looking for (a) suitable empty slot(s).
    for(i=0;i<sizeof(h);i++) {

	// if there is an object in this slot, skip this slot plus any
	// extra slots this object controls. 
	if (objectp(h[i])) 
	{
	    i += ((int)h[i]->query_hands_needed()-1); // -1 as we skip current slot
	    // at the end of the for-loop.
	    good = 0;

	    continue;
	}
	// Later, differenciate between the various integer values in the 
	// slots for amputated hands, cursed hands etc
	// For now, just assume a !0 slot is a no-no

	else 
	if (h[i]) 
	{
	    // No continue here, just subtract one from the good-counter.
	    // This allows a three handed monster to wield a twohanded weapon
	    // even though the middle hand is gone. This will also have to 
	    // depend on the integer given at some point. I.e. can't do it
	    // if the hand in between is cursed, but no problem if it's 
	    // amputated etc.

	    good -= 1;
	} 
	// Now we have to remember what slot we actually started off in
	// so we can return that to the calling function.
	if (!good)
	    start_slot = i; 

	// We have a good slot!
	good++;

	// enough good slots?
	if (good == nh) return start_slot;
    }
    return -1;
}

