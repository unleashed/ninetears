// Death, Version 2.0
// Complete recode of original "Cyric" version, now uses Grimbrand
// Now uses heart_beat instead of call_out's
// Radix - January 17, 1996

inherit "/std/object.c";

void person_died(string str);
void do_chat(string str);

object pl;
int cnt;

void person_died(string str)
{
   pl = find_living(str);
   if(!pl) return;
   pl->set_dead(1);
   pl->add_timed_property("noregen",1,50);
   set_heart_beat(1);
}

void do_chat(string str)
{
   tell_object(pl,str+"\n");
   return;
}

heart_beat()
{
   cnt++;
   
   // Damn, the bugger off and quit
   if(!pl) 
   {
      dest_me();
      return;
   }

   switch(cnt)
   {
   case(2) :
      do_chat("A razor sharp chill runs up your spine.");
      break;
   case(4) : 
      do_chat("A dark voice booms in your mind, cackling with laughter.");
      break;
   case(6) :
      if(pl->query_creator())
         do_chat("The voice asks: Foolish immortal, did you think you "
            "could escape me?");
      else
         do_chat("The voice says: Let me introduce myself, I'm "
            "Grimbrand, Demi-God of Darkness.");
      break;
   case(8) :
      if(pl->query_creator())
      {
         do_chat("The voice cackles and fades away.");
         pl->remove_timed_property("noregen");
         call_out("dest_me",0);
         break;
      }
      else
         do_chat("Grimbrand tells you: It looks like you were quite "
            "foolish today.");
      break;
   case(10) :
      do_chat("Grimbrand cackles with glee upon looking at your "
         "bloody corpse.");
      break;
   case(12) :
      do_chat("Grimbrand says: I can strike your soul to hell if "
         "I so choose.");
      break;
   case(14) :
      do_chat("Grimbrand grins wickedly.");
      break;
   case(16) :
      do_chat("Grimbrand exclaims: I'll give you another chance worthless "
         "mortal!");
      break;
   case(18) :
      do_chat("Grimbrand laughs malicously at you.");
      break;
   case(20) :
      do_chat("The feeling of evilness subsides as his voice disappears.");
      pl->remove_timed_property("noregen");
      call_out("dest_me",0);
      break;
   }
}
