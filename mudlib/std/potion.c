// Radix - December 16, 1995
// Potion inventory control .. must be used for all potions in the 
// mud.

inherit "/std/item.c";

int query_potion() { return(1); }

int delayed_bust()
{
   tell_room(environment(),query_short()+" "+
      ({"shatters","busts","ruptures"})[random(3)]+"!\n");
   call_out("dest_me",0);
   return(1);
}

varargs int move(mixed dest, mixed messout, mixed messin)
{
   int i;
   object *ob, *potions = ({ });
   if(!dest) return 0;

   if(dest && dest->query_property("location")) 
      return ::move(dest,messout,messin);

   ob = all_inventory(dest);
   for(i=0; i<sizeof(ob); i++)
      if(ob[i]->query_potion()) potions += ({ ob[i] });
   if(potions && sizeof(potions) > 5)
      for(i=0; i<sizeof(potions); i++)
         if(random(2))
            potions[i]->delayed_bust();
   return ::move(dest,messout,messin);
}
