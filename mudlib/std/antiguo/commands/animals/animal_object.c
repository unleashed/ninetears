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
   add_action("do_command","ordena");
   add_action("do_dismiss","despide");
   if(my_player&&!my_player->query_static_property("animal_summoned"))
      this_object()->dest_me();
   ::init();
}
int do_dismiss(string str)
{
	if (!str) {
		notify_fail("Despedir a quien?\n");
		return 0;
	}
   if(capitalize(str)==my_animal->query_cap_name())
   {
         //this_object()->query_cap_name()+" asiente y se va lentamente.\n");
      tell_room(environment(this_object()),
         my_animal->query_cap_name()+" asiente y se va lentamente.\n");
      my_animal->dest_me();
      my_player->remove_static_property("animal_summoned");
      return 1;
   }
   notify_fail("No puedes despedir a ese animal.\n");
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
      notify_fail("Como has conseguido este animal?  Deberias ser "
         "baneado!  Informalo inmediatamente o muere!\n\n"
         "Logged.\n\n"
         "Que tengas un buen dia. :)\n");
      return 0;
   }
   command=explode(str," ");
   switch(command[0])
   {
      case "weasel":
      case "halcon":
      case "lobo":
      case "boar":
      case "tigre":
      case "oso":
         break;
      default:
         notify_fail("No hay ningun "+command[0]+" por aqui que "
            "obedezca tus ordenes.\n");
         return 0;
   }
   /*if(command[1]!="a")
   {
      notify_fail("Sintaxis: ordena <animal> a <comando> <objetivo>\n");
      return 0;
   }*/
   animals=find_match(command[0],environment(my_player));
   for(int i=0;i<sizeof(animals);i++)
   {
      if(animals[i]==my_animal)
         flag=1;
   }
   if(!flag)
   {
      notify_fail("Aqui no hay ningun animal que obedezca tus ordenes.\n");
      return 0;
   }
   switch(command[1])
   {
      case "follow":
	case "seguir":
         my_animal->do_command("seguir "+command[2]);
         break;
      case "unfollow":
	case "noseguir":
         my_animal->do_command("noseguir "+command[2]);
         break;
      case "protect":
	case "proteger":
         if(command[0]=="weasel"||command[0]=="halcon")
         {
            notify_fail("Este animal es demasiado pequenyo para proteger algo.\n");
            return 0;
         }
         my_animal->do_command("proteger "+command[2]);
         break;
      case "unprotect":
	case "desproteger":
         my_animal->do_command("desproteger "+command[2]);
         break;
      case "kill":
	case "matar":
      if(this_player()->query_creator())
   {
      write("kill "+command[2]+"\n");
   }
         my_animal->do_command("k "+command[2]);
         ob = present(command[2],environment(this_player()));
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
            notify_fail("Solo un Oso Grizzly puede hacer un abrazo de oso.\n");
            return 0;
         }
         "/d/gremios/comandos/bearhug.c"->bearhug(command[2],my_animal);
         break;
      case "release":
	case "soltar":
         if(command[0]!="oso")
         {
            notify_fail("Solo un Oso Grizzly puede soltar a alguien.\n");
            return 0;
         }
         my_animal->do_command("release "+command[2]);
         break;
      default:
         notify_fail(my_animal->query_short()+" no puede hacer eso.\n");
         return 0;
      break;
   }
   return 1;
}
