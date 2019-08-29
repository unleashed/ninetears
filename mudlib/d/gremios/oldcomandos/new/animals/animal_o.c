inherit "/std/object";
object my_player, my_animal;
int query_auto_load() { return 1; }
void animal_setup(object ranger, object animal, int animal_hp, int animal_gp)
{
   my_player=ranger;
   my_animal=animal;
   my_animal->set_hp(animal_hp);
   my_animal->set_gp(animal_gp);
   my_animal->set_my_player(my_player);
}
void setup()
{
   reset_drop();
}
void init()
{
   add_action("do_command","order");
   add_action("do_dismiss","dismiss");
   if(my_player&&!my_player->query_static_property("animal_summoned"))
      this_object()->dest_me();
   ::init();
}
int do_dismiss(string str)
{
   if(capitalize(str)==my_animal->query_cap_name())
   {
      tell_room(environment(this_object()),
         this_object()->query_cap_name()+" nods and slowly wanders off.\n");
      my_animal->dest_me();
      my_player->remove_static_property("animal_summoned");
      return 1;
   }
   notify_fail("You can't dismiss that animal.\n");
   return 0;
}
int do_command(string str)
{
   string *command;
   object *animals;
   object ob;
   int flag=0;
   if(this_player()!=my_player)
   {
      notify_fail("How the hell did you get this object?  You should "
         "be banished!  Report it immediately or die!\n\n"
         "Alansyn, Thane of Guilds and Magic.\n\n"
         "Have a nice day. :)\n");
      return 0;
   }
   command=explode(str," ");
   switch(command[0])
   {
      case "weasel":
      case "hawk":
      case "wolf":
      case "boar":
      case "tiger":
      case "bear":
         break;
      default:
         notify_fail("There are no "+command[0]+"'s around for you "
            "to command.\n");
         return 0;
   }
   if(command[1]!="to")
   {
      notify_fail("Syntax: command <animal> to <command> <target>\n");
      return 0;
   }
   animals=find_match(command[0],environment(my_player));
   for(int i=0;i<sizeof(animals);i++)
   {
      if(animals[i]==my_animal)
         flag=1;
   }
   if(!flag)
   {
      notify_fail("There are no animals here that you can command.\n");
      return 0;
   }
   switch(command[2])
   {
      case "follow":
         my_animal->do_command("follow "+command[3]);
         break;
      case "unfollow":
         my_animal->do_command("unfollow "+command[3]);
         break;
      case "protect":
         if(command[0]=="weasel"||command[0]=="hawk")
         {
            notify_fail("That animal is too small to protect anything.\n");
            return 0;
         }
         my_animal->do_command("protect "+command[3]);
         break;
      case "unprotect":
         my_animal->do_command("unprotect "+command[3]);
         break;
      case "kill":
      if(this_player()->query_creator())
   {
      write("kill "+command[3]+"\n");
   }
         my_animal->do_command("kill "+command[3]);
         ob = present(command[3],environment(this_player()));
      if(ob)
      {
         ob->attack_by(my_animal);
         ob->attack_by(this_player());
      }
         break;
      case "stop":
         my_animal->do_command("stop");
         break;
      case "bearhug":
         if(command[0]!="bear")
         {
            notify_fail("Only a Grizzly Bear can bearhug.\n");
            return 0;
         }
         "/d/gremios/comandos/bearhug.c"->bearhug(command[3],my_animal);
         break;
      case "release":
         if(command[0]!="bear")
         {
            notify_fail("Only a Grizzly Bear can release.\n");
            return 0;
         }
         my_animal->do_command("release"+command[3]);
         break;
      default:
         notify_fail(my_animal->query_short()+" can't perform that task.\n");
         return 0;
      break;
   }
   return 1;
}
