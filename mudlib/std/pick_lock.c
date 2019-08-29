inherit "/std/item.c";
static int pick_skill;
static string tool_type;
varargs int box_unlock_part2(string chest, object ob2);
object locd_ob;

int query_pick_skill()
{
 object ob = this_player();
 int level = ob->query_level();
 string g_name = ob->query_guild_name();
 int stat_int = ob->query_int();
 int stat_dex = ob->query_dex();
 int toolbonus = this_object()->query_property("skill enhance");
   if((string)ob->query_race_name() == "dwarf"){
      pick_skill = pick_skill + 10;
   }
   if((string)ob->query_race_name() == "duergar"){
      pick_skill = pick_skill + 10;
   }
   if((string)ob->query_race_name() == "elf"){
      pick_skill = pick_skill - 5;
   }
   if((string)ob->query_race_name() == "orc"){
      pick_skill = pick_skill - 20;
   }
   if((string)ob->query_race_name() == "drow"){
      pick_skill = pick_skill - 5;
   }
   if((string)ob->query_race_name() == "kender"){
      pick_skill = pick_skill + 15 + random(20);
   }
   if((string)ob->query_race_name() == "goblin"){
      pick_skill = pick_skill + 10 + random(5);
   }
   if((string)ob->query_race_name() == "gnome"){
      pick_skill = pick_skill + 10 + random(5);
   }
   if((string)ob->query_race_name() == "halfling"){
      pick_skill = pick_skill + 5 + random(5);
   }
   switch(g_name){
      case "wizthief":
         pick_skill=5+random(10)+((level*3)/2)+((stat_int+stat_dex)/2);
         break;
      case "thief":
         pick_skill=10+random(10)+((level*3)/2)+((stat_int+stat_dex)/2);
         break;
      case "hokemj":
         pick_skill=random(20)-40+((level*3)/2)+((stat_int+stat_dex)/2);
         break;
      case "Grimbrand":
         pick_skill=5+random(10)+((level*3)/2)+((stat_int+stat_dex)/2);
         break;
      case "bard":
         pick_skill=random(10)-20+((level*3)/2)+((stat_int+stat_dex)/2);
         break;
      default:
         pick_skill = random(10)-50+((level*3)/2)+((stat_int+stat_dex)/2);
         break;
   }
   pick_skill = pick_skill + toolbonus;

   return pick_skill;
}

string query_tool_type()
{
   string ttype;
   ttype = this_object()->query_property("tool_type");
   return ttype;
}

int pick_door_lock(string direc)
{
  int lock_str,lock_dir,skill;
  string lock_type, tool_type;
  object ob;

  ob = this_player();
  lock_str = environment(ob)->query_lock_str(direc);
  lock_dir = environment(ob)->query_lock_dir(direc);
  lock_type = environment(ob)->query_lock_type(direc);
  skill = query_pick_skill();
  tool_type = query_tool_type();

  if(ob->query_gp() <= 1) {
    tell_object(ob,"\n   Sorry pal, but you don't seem to have "
        "what it takes to pick a lock at this time.\n");
    return 1;
  }
  if(lock_dir == 0)
  {
    tell_object(ob,"\n   Why unlock that which was never locked in"
                   " the first place. \n\n");
    return(1);
  }


//  Logging lock_strength and players pick skill... Piper [2.24.96]

   log_file("pick_lock.bugs", ctime(time())+
      "-> "+ob->query_cap_name()+" tried pick'n "+
      lock_str+" lock with "+pick_skill+" skill.\n");

  if(lock_type != tool_type)
  {
    tell_object(ob,"\n  You fumble around a bit, but fail to pick"
                   " the lock... perhaps you need better"
                   " tools.\n\n");
     ob->adjust_gp(-1);
    return(1);
  }

  if(skill < lock_str)
  {
    tell_object(ob,"\n  You fumble around a bit, but fail to pick"
                " the lock... perhaps you just need to practice.\n\n");
     ob->adjust_gp(-1);
    return(1);
  }

  if((skill >= lock_str)&&(lock_type == tool_type))
  {
    tell_object(ob,"\n  After a few minutes of trying to jimmy"
                   " the lock, it clicks open.\n\n");
     ob->adjust_xp(random(50));
    environment(ob)->remove_lock(direc);
    return(1);
  }

  tell_object(ob,"\n  What exactly are you trying to do?\n\n");
  return(1);
}

int pick_box_lock(string chest)
{
  int i,j;
  object ob,*olist,*olist2;

  ob = this_player();
  olist = all_inventory(environment(ob));
  olist2 = all_inventory(ob);

  for(i=0; i<sizeof(olist); i++)
  {
    if((string)olist[i]->query_name() == chest)
    {
      if(olist[i]->check_lock(chest) == 0)
      {
        int k;
        int lnum = olist[i]->query_num_locks();
        mixed *lock_list = olist[i]->query_lock_list();

        printf("\n%s%d%s","  It seems that there are ",lnum," locks.");
        printf("\n%s","  Which lock do you want to pick:");
        for(k=0; k<sizeof(lock_list); k++)
        {
          printf("\n%s%s","       ",(string)lock_list[k]);
        }
        printf("\n%s\n","  Pick one of the above.  ");
        locd_ob = olist[i];
        input_to("box_unlock_part2");
        return(1);
      }
      box_unlock_part2(chest,olist[i]);
      return(1);
    }
  }
  for(j=0; j<sizeof(olist2); j++)
  {
    if((string)olist2[j]->query_name() == chest)
    {
      if(olist2[j]->check_lock(chest) == 0)
      {
        int k;
        int lnum = olist2[j]->query_num_locks();
        mixed *lock_list = olist2[j]->query_lock_list();

        printf("\n%s%d%s","  It seems that there are ",lnum," locks.");
        printf("\n%s","  Which lock do you want to pick:");
        for(k=0; k<sizeof(lock_list); k++)
        {
          printf("\n%s%s","       ",(string)lock_list[k]);
        }
        printf("\n%s\n","  Pick one of the above.  ");
        locd_ob = olist2[j];
        input_to("box_unlock_part2");
        return(1);
      }
      box_unlock_part2(chest,olist2[j]);  
      return(1);
    }
  }
  box_unlock_part2(chest);
  return(1);
}


varargs int box_unlock_part2(string chest, object ob2)
{
  int lock_str,skill;
  string lock_type,tool_type;
  object ob;

  ob = this_player();
  skill = query_pick_skill();
  tool_type = query_tool_type();

  if((locd_ob)&&(!ob2)) { ob2 = locd_ob; }

  if((ob2)&&(ob2->check_lock(chest) != 0))
  {
    lock_str = ob2->query_lock_str(chest);
    lock_type = ob2->query_ltype(chest);
  }

  if((!ob2)||(lock_str == 0)||(ob2->check_lock(chest) == 0))
  {
    tell_object(ob,"\n  Why unlock that which was never locked"
                   " in the first place. \n\n");
    return(1);
  }

  if(lock_type != tool_type)
  {
    tell_object(ob,"\n  You fumble around a bit, but fail to"
                   " pick the lock... perhaps you need better"
                   " tools.\n\n");
    return(1);
  }

  if(skill < lock_str)
  {
    tell_object(ob,"\n  You fumble around a bit, but fail to"
                   " pick the lock... perhaps you just need"
                   " a little practice.\n\n");
    return(1);
  }

  if((skill >= lock_str)&&(lock_type == tool_type))
  {
    tell_object(ob,"\n  After a few minutes of trying to"
                   " jimmy the lock, it clicks open.\n\n");
     ob->adjust_xp(random(50));
    ob2->remove_lock(chest);
    return(1);
  }

  tell_object(ob,"\n  What exactly are you trying to do??\n\n");
  return(1);
}


int pick_lock(string pickin)
{
   int i;
   string *direcs = environment(this_player())->query_direc();
   for(i=0;i<sizeof(direcs);i++)
   {
      if(pickin == direcs[i])
      {
         this_object()->pick_door_lock(pickin);
         return(1);
      }
   }
   this_object()->pick_box_lock(pickin);
   return(1);
}


string alt_lock_name_too(string lock_name)
{
  return lock_name;
}

int lock_help(string str)
{
   if((str == "picklock")||(str == "pick"))
   {
   write("\n"
   "Syntax: picklock <locked exit name>\n"
   "        picklock <locked object name(lowercase)>\n\n"
   "   These tools allow anyone to 'try' to unlock"
   " something that is locked.\n    *Note* Any can try"
   " not all may suceed."
   "\n\n");
   return(1);
   }
}



void init()
{
   ::init();
   add_action("pick_lock", "picklock");
   add_action("pick_lock", "pick");
   add_action("lock_help","help");
}
