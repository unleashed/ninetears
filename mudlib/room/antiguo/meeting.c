inherit "std/room";

object orkito;

setup() 
{
  add_property("no_undead",1);
  set_light(75);
  set_short("Primera room editada en Ninetears");
  set_long("Primera room editada en Ninetears\n\n" +
           "Esta habitacion pasara a la historia por ser la primera " +
           "que se edito en este Mud. Snif :_)\n\n");

   add_exit("este","/room/entryroom.c","door");
   add_exit("norte","/room/meeting2.c","door");
   add_exit("sudoeste","/room/meeting3.c","door");
//   add_exit("portal","/d/newbie/nexus.c","portal");

}

void reset() {
   if(!orkito) {
	orkito = clone_object("/baseobs/monsters/orc");
	orkito->move(this_object());
	}
   ::reset();
}
