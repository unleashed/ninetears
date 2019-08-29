inherit "/std/room";
#include "path.h";
#include "money.h";

void setup()
{
   set_short("Daggerford Medical Clinic");
   set_long("This is the new clinic here in town.  They don't deal with "+
            "problems of a spiritual nature, but if you've been banged up "+
            "by a baddie, then this is your place.  A large sign hangs on "+
            "the wall near a comely nurse.  A second, smaller sign hangs "+
            "just beneath the first one.\n");
add_item("nurse", "She's quite handsome.  If you are curious about the way "+
    "others are reacting to her, you ought to \"gaze\" at her a bit.\n");
/*
if(this_player()->query_gender() == 1) {
add_item("nurse", "The nurse is very, very attractive and fills out her "+
"uniform in a way that almost frightens you.  She glances demurely up at "+
"you from beneath thick lashes and whispers, \"How may I serve you?\"  "+
"You get the feeling that when she says serve, she _means_ Serve.\n");
} if(this_player()->query_gender() == 2) {
add_item("nurse", "The nurse is very attractive and well-endowed.  You feel "+
                  "a very slight twinge of jealousy as you note the reaction "+
                  "of the male patients in the clinic.  "+
                  "However, you can tell quite easily that her "+
                  "charms are shallow, so you don't "+
                  "feel threatened at all.\n\n");
}   if(this_player()->query_gender() == 0) {
add_item("nurse", "If you had a gender or sexual orientation, you might "+
         "find this nurse attractive.  Certainly, the other people around "+
         "you seem to think she's alluring, if a bit dense...\n\n");
}
*/
   
   set_light(85);
   add_exit("south", ROOM+"wall18a", "door");
   
    add_sign("This is a large, tasteful sign.  You might like to read it for more "+
 "information on the clinic's services...er, okay, just the one service.  ", 
 "The sign is emblazoned in large letters:\n\n"+
 "Adventurers:  Been had by one too many bandits?  Being massacred to "+
 "small fragments got you down?  Are rampaging dragons just _ruining_ your "+
 "day?  Well, WE are the solution for YOU.  All it costs is a measley 2 gold "+
 "coins for each hit point you need restored, and we swear that once we "+
 "get through with you, you won't even remember that "+
 "you were hurting before you walked through our doors!!!  Really!\n\n"+
 "We do regret, however, that because we are SO good at our work, we must "+
 "heal you back to your old, fully-healthy self.  Nothing less will do!\n"+
 "Oh, yes...to apply for treatment, just type \"heal\".  Simple, huh?\n");
add_alias("sign 2", "small sign");
add_item("sign 2", "The small, hand-written sign reads:\n\n"+
"Please do not ask for credit, as a punch in the mouth often offends....\n");
}

void init()
{
   ::init();
   add_action("heal", "heal");
   add_action("lanurse", "gaze nurse");
   add_action("lanurse", "gaze at nurse");
   add_action("lanurse", "gaze");
}

heal() 
/* Please use some spaces .......PLEEEEASE */

  {
  object ob;
  int i, mhp, hp, chp;
  mhp=this_player()->query_max_hp();
  hp=this_player()->query_hp();
  chp=mhp-hp;
  i=chp*200;
  if((this_player()->query_value() >=i) && (this_player()->query_max_hp() 
                                           > this_player()->query_hp())) 
    {
    notify_fail("You approach the nurse and are whisked away into a back room.  "+
"Moments after you enter, a large burly man grabs you and bangs your head "+
"into the wall until you cry out for mercy.  He then puts you down, hands "+
"you a bill, and carries you back out to the main room.\n\nAdmittedly, you "+
"feel pretty lousy, but you have forgotten about your previous injuries, "+
"so you really can't say that their motto is false advertising....\n");

    say(this_player()->query_cap_name()+" walks over to one of the nurses.  "+
"Apparently, this is an unwise thing to do, because he is immediately "+
"seized and carried away, only to be dumped back in the room a few minutes "+
"later by a large, brawny man.  He seems to have forgotten all about his "+
"previous injuries.\n");
    this_player()->adjust_hp(chp);
    this_player()->pay_money(({"copper", i}));
    } /* if (!this_player... */
  else 
    {
    if(this_player()->query_hp() == this_player()->query_max_hp()) 
     {
     notify_fail("You approach one of the nurses, who looks at you rather oddly..."+
           "She continues to stare at you, in fact, until you ask her what is "+
           "wrong.  The sound of your voice apparently startles her, but she "+
           "finally recovers enough to point out to you that there is nothing "+
           "physically wrong with you....if you seek spiritual guidance, "+
          "she suggests that you visit the monk's shrine just off of Farmer's "+
           "Way in the northwest sector of the city.\n");
     say(this_player()->query_cap_name()+"approaches one of the nurses, who "+
         "looks him up and down with a rather odd expression, before finally "+
         "pointing out that he does not need treatment.  At least, not "+
         "treatment for any *physical* injuries.  =)\n");
     } 
  else 
    {
    notify_fail("You approach one of the nurses, hoping for some sympathy since you "+
"don't have the proper change for the clinic.  Surely they will accept "+
"something other than gold....The nurse presses a button and you wake up "+
"in the street.  Hmm...guess not.\n");
    say("Uh-oh.  "+this_player()->query_cap_name()+" tries to sweet-talk the "+
"nurse into giving him treatment without the proper form of payment.  You "+
"watch in amazement as she presses a button and he melts into the floor.  Ick!\n");
    this_player()->move(ROOM+"wall18a.c");
    } /* else..*/
  return 0;
  }
  }

lanurse() {
if(this_player()->query_gender() == 0) {
   write("If you had a gender or sexual orientation, you might find this "+
         "nurse attractive.  Certainly, the other people around you seem "+
         "to think she's alluring, if a bit dense...\n\n");  }
if(this_player()->query_gender() == 1) {
   write("The nurse is very, very attractive and fills out her uniform in a "+
         "way that almost frightens you.  She glances demurely up at you "+
         "from beneath thick lashes and whispers, \"How may I serve you?\"  "+
         "You get the feeling that when she says serve, she _means_ Serve.\n\n"); }
if(this_player()->query_gender() == 2) {
   write("The nurse is very attractive and well-endowed.  You feel a "+
         "very slight twinge of jealousy as you note the reaction of the "+
            "the male patients in the clinic.  However, "+
        "you can tell quite easily that her charms "+
        "are shallow, so you don't feel threatened "+
        "at all.\n\n"); }
return 1;
}
