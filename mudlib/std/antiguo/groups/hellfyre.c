inherit "/std/group.c";

setup()
{
   set_name("cult of hellfyre");

   set_short("Cult of Hellfyre");

   set_long("Here you must put the groups information the player "
      "can read before actually joining the group.  Here, describe "
      "the main focus or purpose of the group and a general recruiting "
      "paragraph to persuade the player this is the best group "
      "around.  (:\n\n");
}

int query_channel() { return(1); }

