#include "virtual.h"

void dest_me() { destruct(this_object()); }

void create() {
object clone;

  seteuid((string)"/secure/master"->creator_file(this_object()));
  clone = (object)SERVER->create_virtual_object("/obj/armour.c", 1);
  clone->add_property("virtual name", "obj/armours/leather.arm");
  call_other(clone, "set_name", "jacket" );
  call_other(clone, "set_short", "leather jacket" );
  call_other(clone, "add_adjective", ({ "leather" }) );
