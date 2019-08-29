/*
   /secure/master/create_dom_creator.c
   Originally bashed at Final Realms
   Fixed and tweaked by Radix : March 5, 1997
*/

#define POSTAL_D "/obj/handlers/postal_d"

int create_creator(string);
int create_domain(string, string);
int demote_creator(string);

int create_domain(string name, string lord) 
{
   string file;
  
   if(this_player() != this_player(1) || !this_player()->query_god())
   {
      tell_object(this_player(),"You must be a god to create a "
         "new domain.\n");
      return 0;
   }
   if(high_programmer(capitalize(name))) 
   {
      tell_object(this_player(), "Invalid name....\n");
      return 0;
   }
   if(file_size("/d/"+name) != -1) 
   {
      tell_object(this_player(),"Domain already exists (or invalid).\n");
      return 0;
   }
   if(sizeof(explode(name, "/")) > 1) 
   {
      tell_object(this_player(),"Invalid to have a / in the "
          "domain name.\n");
      return 0;
   }
   if(!"/secure/login"->test_creator(lord)) 
   {
      tell_object(this_player(),"The lord must exist and be a "
         "creator.\n");
      return 0;
   }
   mkdir("/d/"+name);
   file = read_file("/std/dom/master.c");
   write_file("/d/"+name+"/master.c", "#define DOM_LORD \""+lord+"\"\n");
   write_file("/d/"+name+"/master.c", "#define DOMAIN \""+name+"\"\n"); 
   write_file("/d/"+name+"/master.c", file);
   file = read_file("/std/dom/common.c");
   write_file("/d/"+name+"/common.c",
              "#define DOM_TITLE \"the domain of "+name+"\"\n");
   write_file("/d/"+name+"/common.c", "#define DOM_LORD \""+lord+"\"\n");
   write_file("/d/"+name+"/common.c", "#define DOMAIN \""+name+"\"\n");
   write_file("/d/"+name+"/common.c", file);
   file = read_file("/std/dom/loader.c");
   write_file("/d/"+name+"/loader.c", "#define DOMAIN \""+name+"\"\n");
   write_file("/d/"+name+"/loader.c", file);
   save_object("/secure/master",1);
   write("Created domain "+name+".\n");
   log_file("PROMOTIONS", "Domain "+name+" created with a lord of "+lord+
              " by "+geteuid(previous_object())+"\n");
   return 1;
}

int create_creator(string name) 
{
   string file;
 
   seteuid("Root");
   if(!query_lord(geteuid(previous_object())))
      return 0;
   if(!"/secure/login"->test_user(name))
      return 0;

   if(file_size("/w/"+name) != -1) 
   {
      write("Directory already exists or invalid.\n");
      return 0;
   }
   mkdir("/w/"+name);
   file = read_file("/std/creator/workroom.c");
   write_file("/w/"+name+"/workroom.c", "#define CREATOR \""+name+"\"\n");
   write_file("/w/"+name+"/workroom.c", file);
   file = read_file("/std/creator/workroom2.c");
    write_file("/w/"+name+"/workroom2.c", "#define CREATOR \""+name+"\"\n");
    write_file("/w/"+name+"/workroom2.c", file);
   log_file("PROMOTIONS", name+" promoted to creator by "+
           geteuid(previous_object())+"\n");
   write("Creator "+name+" promoted.\n");
   if(find_player(name)) 
   {
      find_player(name)->set_creator(1);
      find_player(name)->save();
      tell_object(find_player(name), "You have been promoted to "
         "creator by "+capitalize(geteuid(previous_object()))+".\n");
   } 
   else 
      write_file("/players/"+name[0..0]+"/"+name+".o","creator 1\n");
   return 1;
} 

int demote_creator(string str) 
{
   string name, reason;

   if(!query_lord(geteuid(previous_object())))
      return 0;
   if(sscanf(str, "%s %s", name, reason) != 2) 
   {
      notify_fail("Usage: demote <creator> <reason>\n");
      return 0;
   }
   if(!"/secure/login"->test_creator(name))
      return 0;
   if(query_lord(name))
   { 
      notify_fail("Lords can not be demoted.\n");
      return 0;
   }
   write_file("/log/DEMOTE", name+" demoted by "+
              previous_object()->query_cap_name()+" at "+ctime(time())+
              "\nReason: "+reason+"\n");
   if(find_player(name)) 
   {
      find_player(name)->set_creator(0);
      find_player(name)->save();
      tell_object(find_player(name), "You have just been demoted by "+
                capitalize(previous_object()->query_cap_name())+".\n");
      find_player(name)->really_quit();
   } 
   write_file("/players/"+name[0..0]+"/"+name+".o","creator 0\n");
   rename("/w/"+name,"/w/oldcreators/"+name);
   rename("/players/"+name[0..0]+"/"+name+".o","/w/oldcreators/"+name);
   write("Creator "+capitalize(name)+" demoted.\n");
   write("Removing their mail...");
   POSTAL_D->retire_user(name);
   write("Done.\n");
   write_file("/w/oldcreators/"+name+"/DEMOTED",
              capitalize(name)+" demoted by "+
              previous_object()->query_cap_name()+" : "+ctime(time())+
              "\nReason: "+reason+"\n\n");
   return 1;
} 

