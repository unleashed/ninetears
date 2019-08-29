/* Taniwha was here 09/94
 * extended the code to allow more types
 * so clothing like shirts can be worn with armour
 *
 */
int do_unwear_ob(object on);
int do_wear_ob(object ob);
void reset_types();

#define PASSED_OUT "passed out"
#define MAXTYPES 20

/* Wear.c used for wearable objects.. or rather for players to be able
 * to wear armour and other stuff. 
 * Will make it possible for items to be worn even if they're not armour.
 * And also make armour heldable, not only wearable.
 * It is completely rewritten by Baldrick, april '94 
 * (With a lot help from Aragorn)
 */

/* we will have different types of worn objects.
 * Body armour, Body clothing, boots/shoes and head will be one only.
 * Rings will be multipple.  Maybe add an amount_heads ? :=)
 * It won't be any problem to add new types later.
 */

static private mixed *worn_objects;
static private int worn_ac;
static private int *armour_types;

object *query_worn_ob() { return worn_objects; }


create() 
{
    worn_objects = ({ });
    worn_ac = 0;
    reset_types();
}

void reset_types()
{
    int e;
    armour_types = allocate (MAXTYPES);
    for (e=0;e<MAXTYPES;e++)
    {
	armour_types[e] = 0;
    }
}

/* The total AC for all worn objects.. */
/* Shall I add the hold AC (shields) here or caculate everything 
 * in an equip.c ? */

int query_worn_ac() { return worn_ac; }


int unwear_ob(object ob) 
{
    int size;
    int slot;
    if(!ob) return 0;
    if ((slot = member_array(ob, worn_objects)) == -1) 
    {
	notify_fail("You don't wear this item.\n");
	return 0;
    }

    size = ob->query_size() / 4;
    if (size < 1)
	size = 1;
    tell_object(this_object(), "You start to take off " +  
      (string)ob->short() + ".\n");

    // Taniwha 1995, restrictions in, this isn't needed.
    // this_object()->add_static_property("nocast",1);
    // call_out("do_unwear_ob", size, ob);

    return do_unwear_ob(ob);

} /* unwear_ob */

int do_unwear_ob(object ob)
{
    int a_type;

    if(!ob) return;
    // taniwha 1996
    if(ob->set_in_use(0) == 0)
    {
	worn_objects -= ({ ob });
	a_type = ob->query_armour_type();
	armour_types[a_type] -= 1;

	tell_object(this_object(),"You take off your " + 
	  (string)ob->query_short() + ".\n");
	worn_ac -= ob->query_ac();
	this_object()->remove_static_property("nocast");
    }
    else tell_object(this_object(),"You can't remove your "+
	  (string)ob->query_short() + ".\n");
    return 1;
}


status wear_ob(object ob) 
{
    int a_type, occupied;
    string *exp;
    string thisone;
    int size, i;
    /* Maybe this check is/can be another place ? */
    /* Made a query_holdable in living.c.. */

    if(this_object()->query_property("loading"))
    {
	notify_fail("Your equipment is still in limbo, wearing it is "
	  "impossible.\n");
	return 0;
    }
    if(ob->query_ac() != 0)
	if(this_object()->query_guild_ob() && 
	  !this_object()->query_guild_ob()->
	  query_legal_armour(ob->query_armour_name()))
	{
	    tell_object(this_object(),"Wearing this item doesn't fit with "
	      "your chosen guild.\n");
	    return 1;
	}

	/* Test if the type is worn already.. */
	/* This check is a mess, since I want to use the return as a string.
	 * query_wear_type is a string.. */
	/* I'll add the whole thingie later.. */

	/* Well, only one of each item, including rings and amulets.
	 * altho you can have more different rings and amulets..
	 * Maybe a a_type for the different types of amulets, but that would be
	 * a hellova table.
	 * Baldrick, feb '96.
	 * This is starting to become really ugly.
	 * Check for one of a type
	 */
    notify_fail("You are already wearing this type of object.\n");
    exp = explode(file_name(ob),"#");
    thisone = exp[0];
    for (i=0;i<sizeof(worn_objects);i++)
    {
	exp = explode(file_name(worn_objects[i]),"#");
	if(thisone == exp[0])
	{
	    return 0;
	}
    }
    a_type = (int)ob->query_armour_type();
    /* Rings and amulets can be multipple worn.
     * that's type 5 & 7 
     */
    switch(a_type)
    {
    default:
	if (armour_types[a_type]) 
	    return 0;
    case 5:
    case 7:    		
	if (armour_types[a_type] >= 4)
	    return 0;
    }

    if (!size = ob->query_size())
    {
	notify_fail("Your item has not a set size, bug it with the BUG command");
	return 0;
    }
    if(ob->set_in_use(1))
    {
	worn_objects += ({ ob });
	worn_ac += (int)ob->query_ac();
	armour_types[a_type] += 1;
	size = size /5;
	tell_object(this_object(), "You start wearing " +  
	  (string)ob->short() + ".\n");
	/* Dwimmerlaik 97 */
	if(this_object()->query_creator()) return (1);
	/* Raskolnikov 96 */
	this_object()->add_timed_property(PASSED_OUT, "You are still "
	  "trying to wear "+(string)ob->short()+".\n", size);
	return 1;	
    }
    else tell_object(this_object(),"You can't wear "+(string)ob->short()+ ".\n");
    return 0;	

} /* wear_ob */

