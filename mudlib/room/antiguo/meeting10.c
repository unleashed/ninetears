inherit "std/room";

setup() 
{
  add_property("no_undead",1);
  set_light(75);
  set_short("XP FOR YOU!");
  set_long("This is the meeting hall of applicants for FR:Illumitech. " +
           "It looks rather comfortable, but seems a place for only a " +
           "temporary stay--until you can find a proper home.  There " +
           "is a bulletin board here, and also a curious portal that " +
           "will let you mill about the sample areas that have been " +
           "created.\n\n");

   add_exit("norte","/room/meeting11.c","door");
   add_exit("oeste","/room/meeting9.c","door");
   add_exit("sudeste","/room/raisepowah.c","door");
   add_exit("sur","/room/entryroom.c","door");
   add_clone("/baseobs/monsters/orc", 1);
}
