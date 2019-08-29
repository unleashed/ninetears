/* Coded by Santino.  SAN-TI-NO  (get it?) */
/** (that's where all the bugs came from :) ) **/
/** HB made to actually work by Raskolnikov :) **/
inherit "/obj/weapon";
#define HOME environment(this_player())
int mycounter;


string enchant_string()
{
    return "As your magically enhanced vision traces the runes"
    " in Salvation's blade, \ndistant bells ring solemnly"
    " in your mind.  A being of glimmering light"
    " forms \nbefore you with a respectful bow."
    "\n\"Master, know that it is your destiny to wield"
    " this blade, as it is my \ndestiny to aid you"
    " in your holy quest.\"\n";
}


void setup()
{
    set_base_weapon("long sword");
    set_name("salvation");
    set_short("Salvation");
    set_long("This is Salvation, the ancient blade"
      " of paladin saints.  Through the eons, the massed"
      " faith of its wielders has imbued the deadly"
      " looking long sword with a power all its own."
      "  Light gleams along its edges, and a single"
      " diamond in its hilt seems to wink at you...\n");
    reset_drop();
    add_static_property("dead",1);
    set_value(0);
    set_enchant(1);

    dice = 5;
    rolls = 3;
    set_heart_beat(1);
    mycounter = 1;
}

object him, me;



int weapon_attack(object himx, object me)
{
    int x;
    him = himx;

    if( sizeof(me->query_weapons_wielded()) > 1)
    {
	tell_object(me, "Salvation demands your complete concentration "
	  "and fails to respond!\n\n");
	tell_room(environment(me), me->query_cap_name()+" is unable to "
	  "wield the mighty Salvation!\n\n", me);
	return 0;
    }
    if((sizeof(me->query_weapons_wielded()) == 1) && (sizeof(me->query_shields_held()) == 0))
    {
	x=random(800);
	if(x < 60)
	{
	    tell_object(me, "You grasp Salvation with both hands, and"
	      " are able to attack twice!\n");
	    ::weapon_attack(him,me);
	}
	if ( x > 780)
	{
	    tell_object(me, "As you pursue your righteous war,"
	      " Salvation glows softly in your grasp, its"
	      " holy light easing the pain of your wounds.\n");
	    me->adjust_hp(10+(random(20)));
	    return 1;
	}
    }
::weapon_attack(him,me);
}



void heart_beat()
{
    object WIGGLE, *ob;
    object DOODOO;
    int i;
    WIGGLE = environment(this_object());
   if(!WIGGLE) 
   {
      set_heart_beat(0);
    return;
   }
    if(WIGGLE->query_hp())
	DOODOO=WIGGLE;
    WIGGLE = environment(WIGGLE);
    ob = all_inventory(WIGGLE);
    i=0;

    if(this_object()->query_static_property("wielded")==1)
    {

	for(i=0; i<sizeof(ob); i++)
	{
	    string TARGET=ob[i]->query_name();

	    if(living(ob[i]))
	    {
		string GU=ob[i]->query_guild_ob();
		if(ob[i] != DOODOO)
		{
		    if(GU=="/std/guilds/warriors/antipaladin.c")
		    {
			if(!((int)DOODOO->query_timed_property("salvation_on") == 1))
			{
			    tell_object(DOODOO, "Salvation screams out in rage:"
			      "\n   \"A vile Anti-Paladin!  I will have that"
			      " accursed knight's blood!\"\n"
			      "  Salvation pulls you into battle!\n");
			    DOODOO->attack_ob(ob[i]);
			    "/std/commands/charge"->charge(TARGET, DOODOO);
			    DOODOO->add_timed_property("salvation_on",1,3000);
			}
		    }
		}
	    }
	}
	switch(mycounter)
	{ 
	case 1000..1010:
	    tell_object(DOODOO, "A solemn chanting echoes within your mind"
	      " and Salvation glows white-hot, tapping into your"
	      " strength to maintain its holy vigor.\n");
	    tell_room(WIGGLE, DOODOO->query_cap_name()+
	      " shudders,"+
	      " "+DOODOO->query_possessive()+" eyes dark and shadowed.\n", DOODOO);
	    DOODOO->adjust_hp(-(random(15)));
	    break;
	case 5000..10000:
	    mycounter = 1;
	    tell_object(DOODOO, "Salvation glows white-hot in your grasp,"
	      " and a tide of energy flows into you, restoring"
	      " your depleted reserves.\n");
	    DOODOO->adjust_gp(5);
	    break;
	}
	mycounter += random(10) + 10;
    }
}


set_in_use(int i)
{

    object ob;
    ob=environment(TP);

    if (i==1)
    {
	write("As you unsheath Salvation, an aura of righteousness"
	  " floods your very being.\n");
	tell_room(ob, TP->query_cap_name()+" firmly grasps a "+
	  "beautiful long sword.  An aura of holiness"
	  " washes over you.\n", TP);

	this_object()->add_static_property("wielded",1);
	return 1;
    }
    else if(i==0)
    {
	this_object()->remove_static_property("wielded");
	return 0;
    }
}

void setup_spell(object ob)
{
    tell_room(environment(ob), ob->query_cap_name()+" focus on "
      "the small Silver Cross which begins to radiate a pale "
      "light.  There is a bright flash and after you regain your "
      "you see "+ob->query_cap_name()+" holding a long, powerful "
      "looking sword.\n\n", ob);
    tell_object(ob, "You focus the spell on the Silver Cross "
      "and it begins to radiate a pale light.  Suddenly there is "
      "blinding flash of light and in your hands appears the mighty "
      "sword Salvation!\n\n");
    this_object()->move(ob);
    return;
}

int query_count() { return mycounter; }

int query_auto_load() { return 1; }

