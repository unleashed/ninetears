#define CREATOR "xerxes"
inherit "/std/outside.c";
void setup()
{
  set_short("Confines del Plano Abismal");
  set_long("\nAqui todo es tierra inerte. Eres incapaz de divisar "
           "cualquier signo de vida.\n\n");
  set_light(40);
  set_exit_color("white");
  add_clone("/obj/misc/button.c",1);
//    add_clone("/w/xerxes/npc/aragami.c",1);
  add_exit("comun","/w/common","door");
  add_exit("entrada","/room/entryroom.c","door");
  add_exit("urghak","/d/urghak/common.c","door");
  "/w/common.c"->add_exit( CREATOR,"/w/"+CREATOR+"/workroom","door");
}
