/* Coded by Santino.  SAN-TI-NO  (get it?) */
/** (that's where all the bugs came from :) ) **/
inherit "/obj/weapon";
#define HOME environment(this_player())
int mycounter;


string enchant_string()
{
    return "As you concentrate your focus upon the mighty"
    " weapon, its form shimmers and \nbegins to melt, tiny"
    " droplets of magical energy coalescing into the"
    " form of a \ndark elven woman, her eyes torn from"
    " their sockets, and an insane smile upon \nher"
    " bloodless lips.  Sensing your gaze, the banshee"
    " curtseys mockingly.  \n\"My Lord... I am yourss"
    " to command...\"\n";
}

void setup()
{
    set_base_weapon("bastard sword");
    set_name("xuerin");
    set_short("Xuerin, the Soulsword");
    add_alias("soulsword");
    set_long("This is Xuerin, known as the Stealer of Souls,"
      " forged in the earliest millenia of the Realm's"
      " existence.  Looking at its three and a half foot"
      " length, you can only imagine the bloodshed it"
      " might wreak.  One ruby in its hilt seems to"
      " wink at you...\n");
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

    if(sizeof(me->query_weapons_wielded()) > 1)
    {
	tell_object(me, "The Xuerin demands your complete concentration "
	  "and you fail miserably in your attack!\n\n");
	tell_room(environment(me), me->query_cap_name()+" is unable "
	  "to wield the mighty Xuerin!\n\n", me);
	return 0;
    }
    if((sizeof(me->query_weapons_wielded()) == 1) && (sizeof(me->query_shields_held()) == 0))
    {
	x=random(800);
	if(x < 60)
	{
	    tell_object(me, "You grasp Xuerin with both hands, and"
	      " are able to attack twice!\n");
	    ::weapon_attack(him,me);
	}
	if ( x > 780)
	{
	    tell_object(me, "As you attack, a sharp keening fills the"
	      " air, like the sound a banshee might make.  Your"
	      " blade pulses angrily.\n");
	    tell_object(him, "The dark blade in "+TP->query_cap_name()+"
""'s hand shimmers angrily, and a horrible wail"
	      " emanates from its form, shattering"
	      " all boundaries of reason and hope.\n");
	    him->adjust_hp(-(random(25)));
	    him->set_wimpy(50);
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
		    if(GU=="/std/guilds/warriors/paladin.c")
		    {
			if(!((int)DOODOO->query_timed_property("xuerin_on") == 1))
			{
			    tell_object(DOODOO, "Xuerin screams out in rage:"
			      "\n   \"A vile Paladin!  I will have that"
			      " accursed knight's blood!\"\n"
			      "  Xuerin pulls you into battle!\n");
			    DOODOO->attack_ob(ob[i]);
			    "/std/commands/charge"->charge(TARGET, DOODOO);
			    DOODOO->add_timed_property("xuerin_on",1,3000);
			}
		    }
		}
	    }
	}
	switch(mycounter)
	{
		case 1000..1010:
	    tell_object(DOODOO, "A wave of numbing cold runs up your arm"
	      " from Xuerin, sapping your strength.  Deep within"
	      " your mind, you hear the quiet echoes of a"
	      " woman's laughter.\n");
	    tell_room(WIGGLE, DOODOO->query_cap_name()+
	      " shudders,"
	      " "+DOODOO->query_possessive()+" eyes dark and shadowed.\n", DOODOO);
	    DOODOO->adjust_hp(-(random(15)));
	    mycounter += random(30) + 15;
	    break;
		case 5000..10000:
	    mycounter=1;
	    if(DOODOO->query_str() < 29)
	    {
		tell_object(DOODOO, "Xuerin gleams darkly in your grasp, and"
		  " a rush of strength flows into you,"
		  " restoring your depleted reserves.\n");
DOODOO->adjust_tmp_str(1);
	    }
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
	write("As you unsheath Xuerin, a female cry of exultation"
	  " explodes in your mind, like the birth cry of"
	  " a dozen worlds.\n");
	tell_room(ob, TP->query_cap_name()+" firmly grasps a "
	  "wicked bastard sword.  You can feel malevolence radiating from "
	  "the weapon itself, and even a seasoned adventurer such "
	  "as yourself can barely keep from fleeing in terror.\n\n", TP);

	this_object()->add_static_property("wielded",1);
	this_player()->add_static_property("undead", (TP->query_level()) * 1.5);
	return 1;
    }
    else if(i==0)
    {
	write("As you sheath Xuerin, its voice fills"
	  " your mind with an angry cry: \"Massster... is THIS the"
	  " veangance you promised me?  I'm sssso"
	  " hungry still...\"\n"
	  "   The ebon blade pulses twice, and"
	  " you feel the icy hand of death upon your"
	  " soul.  When the chill passes, you feel weaker,"
	  " but Xuerin is safely sheathed.\n");
	tell_room(HOME, TP->query_cap_name()+" sheaths a wicked"
	  " looking sword, and the air about you seems to"
	  " grow less oppressive.\n", TP);
	TP->adjust_hp(-5-random(4));
	this_object()->remove_static_property("wielded");
	this_player()->remove_property("undead");
	return 0;
    }
}

void setup_spell(object ob)
{
    tell_room(environment(ob), ob->query_cap_name()+" focus on "
      "the small Obsidian Skull which begins to radiate a pale "
      "light.  There is a bright flash and after you regain your "
      "you see "+ob->query_cap_name()+" holding a long, sinister "
      "looking sword.\n\n", ob);
    tell_object(ob, "You focus the spell on the Obsidian Skull "
      "and it begins to radiate a pale light.  Suddenly there is "
      "blinding flash of light and in your hands appears the mighty "
      "sword Xuerin!\n\n");
    this_object()->move(ob);
    return;
}

int query_count() { return mycounter; }

int query_auto_load() { return 1; }
