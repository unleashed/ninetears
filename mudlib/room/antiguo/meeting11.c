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

   add_exit("sur","/room/meeting10.c","door");
   add_exit("sudoeste","/room/meeting9.c","door");
   add_clone("/baseobs/monsters/orc", 2);
}
