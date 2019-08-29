// Use this for backpacks, pouches, ...
// Radix, July 1996

#include "move_failures.h"
inherit "/std/container.c";

create()
{
   container::create();
   set_prevent_insert();

   // Radix : Oct 1996
   if(!clonep(this_object()))
      catch("/obj/handlers/item_info"->update_container(this_object()));
}

int query_item_container() { return 1; }

varargs int move(mixed dest, mixed messin, mixed messout)
{
   return (int)container::move(dest,messin,messout);
}
