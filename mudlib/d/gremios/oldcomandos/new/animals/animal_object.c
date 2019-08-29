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
   add_action("do_command","ordenar");
   add_action("do_dismiss","despedir");
   if(my_player&&!my_player->query_static_property("animal_summoned"))
      this_object()->dest_me();
   ::init();
}
int do_dismiss(string str)
{
   if(capitalize(str)==my_animal->query_cap_name())
   {
      tell_room(environment(this_object()),
         this_object()->query_cap_name()+" sonrie y su companyia se aleja.\n");
      my_animal->dest_me();
      my_player->remove_static_property("animal_summoned");
      return 1;
   }
   notify_fail("No puedes despedir este animal.\n");
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
      notify_fail("Como demonios conseguistes este objeto?  Deberias "
         "ser baneado!  Reportalo inmediatamente o muere!\n\n"
         "Que tengas un buen dia. :)\n");
      return 0;
   }
   command=explode(str," ");
   switch(command[0])
   {
      case "comadreja":
      case "halcon":
      case "lobo":
      case "jabali":
      case "tigre":
      case "oso":
         break;
      default:
         notify_fail("No hay "+command[0]+" a tu alrededor "
            "para mandar algo.\n");
         return 0;
   }
   if(command[1]!="a")
   {
      notify_fail("Sintaxis: comando <animal> a <comando> <objetivo>\n");
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
      notify_fail("No hay animales aqui para que puedas mandarles algo.\n");
      return 0;
   }
   switch(command[2])
   {
      case "seguir":
      case "follow":
         my_animal->do_command("follow "+command[3]);
         break;
      case "perder":
      case "unfollow":
         my_animal->do_command("unfollow "+command[3]);
         break;
      case "protect":
      case "proteger":
         if(command[0]=="comadreja"||command[0]=="halcon")
         {
            notify_fail("Este animal es demasiado pequenyo para proteger.\n");
            return 0;
         }
         my_animal->do_command("protect "+command[3]);
         break;
      case "unprotect":
      case "desproteger":
         my_animal->do_command("unprotect "+command[3]);
         break;
      case "kill":
      case "matar":
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
      case "parar":
         my_animal->do_command("stop");
         break;
      case "bearhug":
      case "abrazo":
         if(command[0]!="oso")
         {
            notify_fail("Solo un gran oso puedes hacer esto.\n");
            return 0;
         }
         "/d/gremios/comandos/bearhug.c"->bearhug(command[3],my_animal);
         break;
      case "release":
      case "liberar":
         if(command[0]!="oso")
         {
            notify_fail("Solo un gran oso puede liberar.\n");
            return 0;
         }
         my_animal->do_command("release"+command[3]);
         break;
      default:
         notify_fail(my_animal->query_short()+" no puede hacer esto.\n");
         return 0;
      break;
   }
   return 1;
}
