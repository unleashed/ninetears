// This remote control was created by Mirath ...
//  Changed to the present form by Thane Mist
//changed alittle bit more by Tek Thane of Mithril Mountains
// For use by the members of Mithril Mountains domain...
//new item for /newbie domain, Tek 9/15/96

inherit "obj/weapon";

#define VER "4.0"
                    

void setup() {     
  set_base_weapon("quarterstaff");
   set_name("newbie domain staff");
   set_short("Newbie Domain Staff");
   add_alias("staff");
   set_main_plural("newbie domain staves");
   add_plural("staves");
   set_long("This beautiful curved staff is covered with incredible "
            "ornate carvings that depict every aspect of life in the "
            "realms.  It is said that in the hands of a skilled user "
            "this staff can be a very useful tool.  However, in the "
            "hands of a fool, this staff can only lead to destruction.  "
            "It is designed for the use of the members of the "
            "Newbie domain.  Any illegal use of this item "
            "strongly discouraged. \n\n");
   set_weight(0);
   set_holdable(1);
// reset_drop();
                                                                  
} /* setup() */                                                  

int query_holdable() {return 1;}
int query_hands_needed() {return 1;}
                                                                
int set_in_use(int i)
{
     object ob;
   if(environment()) ob = environment();
   else return ::set_in_use(i);

   if(!ob->query_creator()) return ::set_in_use(0);
   else
      return ::set_in_use(i);
}
void init() {                                                  
this_player()->remove_property("mmstaff");
   if(!this_player()->query_creator())
      return 1;
   add_action("do_help"    , "helpme"  );                          
   add_action("do_emoteto" , "emoteto" );                         
   add_action("do_light"   , "light"   );                       
   add_action("do_cmds"    , "cmds"    );                     
   add_action("do_bomb"    , "bomb"    );                    
   add_action("do_level"   , "level"   );                  
   add_action("do_time"    , "time"    );
   add_action("do_peace"   , "peace"   );
   add_action("do_mmcre"   , "staff"   );
   add_action("do_fetch"   , "fetch"   );
   add_action("do_times"   , "times"   );
   add_action("do_earmuffs", "earmuffs");
    add_action("mmwho","newbiewho");
    add_action("mmwho","nw");
  add_action("show_inss","in");
  add_action("qatt_me","qatt");
                                                        
} /* init() */                                         
                                                      
int do_cmds() {                                                       
   write("Commands in version "+VER+":\n");                                     
   write("      helpme [command]\n");                                           
   write("      cmds\n");                                      
   write("      emoteto <someone> <text>\n");                    
   write("      light [light]\n");                              
   write("      bomb\n");                                     
   write("      level <something|someone>\n");
   write("      time\n");
   write("      times\n");
   write("      peace\n");
   write("      staff cmd for channel\n");
   write("      earmuffs\n");
   write("      fetch <something>\n");
   write("      force <pc|npc> <command>\n");
     write("      newbiewho or nw  see who is on in mm\n");
   write("    in <domain>\n");
       write("     qatt\n");
   reset_drop();
   reset_get();
                                                             
   return 1;                                                
} /* do_cmds() */                                          

int do_help(string str) {
   if(!str) { 
      write("This power staff is made for the members of the Newbie "
            "domain "
            "exclusively. I dare not even think of what we will do if it is "
            "found on any non-member... This is version "+VER+". If you have "
            "any new ideas you would "
            "like incorporated in it, tell Raisa about it... :)\n");
      write("The following commands are included : \n");
      write("\thelpme    - This help message.\n");
      write("\tcmds      - Short help with parameter requirements.\n");
      write("\temoteto   - Self explaining...\n");
      write("\tlight     - Set light level.\n");
      write("\tbomb      - Dest all items in the room except player objects.\n");
      write("\tlevel     - Check level of pc/npc.\n");
      write("\ttime      - Norwegian local time.\n");
      write("\ttimes     - shows Eastern, Central, Mountain and Pacific US \n"
            "\t            time.\n");
      write("\tpeace     - Stops all fighting in the room.\n");
      write("\tstaff     - Personal cre-channel for  Newbie Domain.\n");
      write("\tfetch     - Fetches something from the /baseobs/* dir.\n");
      write("\tforce     - Force a pc/npc to do a command.\n");
      write("\tearmuffs  - Works as old earmuffs + it can earmuff 'staff'.\n");
      write("\tnewbiewho   -Shows who is on in mm domain 'nw' works also.\n");
     write("\tin       - Shows you who is in a certain domain.\n");
      write("\tqatt      -Shows you who is in a fight.\n");
   } else {
          switch(str) {
      case "light":
         write("light [number]\n");
         write("\tJust 'light' returns the light-setting on the control.\n");
         write("\t'light <nubmer>' sets it to the nubmer...\n");
         break;
      default:
         write("Sorry, no help on that topic.\n");
         break;
      }
   }
   return 1;
} /* do_help() */
                                                          
int do_emoteto(string str) {                                 
   object ob;                                               
   string who, bing;                                       
   if(!str) {      
      write("Usage: emoteto <nick> <text>\n");  
      return 1;                              
   }                                        
   if(sscanf(str,"%s %s", who, bing) != 2) {      
      write("Usage: emoteto <nick> <text>\n");     
      return 1;                                 
   }                                           
   ob=find_living(who);                     
   if(!ob) {                               
      write("Can't find "+ capitalize(who) +".\n"); 
      return 1;                                    
   }                                              
   tell_object(ob, this_player()->query_cap_name() +" "+ bing +"\n");
   write("You emoteto "+ ob->query_cap_name() +": "+ bing +"\n");        
   return 1;                                                       
                                                                  
} /* do_emoteto() */                                      
                                                         
                     
int do_light(string str) {      
   int bong;                   
   if(!str) {                 
      write("Current light is "+ query_light() +".\n");   
      return 1;                                          
   }                                                    
   if(sscanf(str,"%d", bong) == 1) {                   
      if(bong == 0) {                                 
         if(query_light() != 0) {                    
            write("You turn off the light...\n");   
            tell_room(environment(this_player()), 
                      this_player()->query_cap_name() +" pushes a carving "
                      "on his "
                      "staff, and the light is shut off.\n",
                      ({this_player()}));           
            set_light(bong);
            return 1;                                                     
         }                                                               
         write("The light is already that low...\n");                   
         return 1;                                                     
      }                                                               
      if(bong == query_light()) {                                    
         write("The light is already at that level.\n");            
         return 1;                                                 
      }                                                           
      if(((bong-query_light())<20)&&((query_light()-bong)<20)) { 
         if(bong < query_light()) {                             
            write("You dim the light slightly.\n");            
            tell_room(environment(this_player()), 
                      this_player()->query_cap_name() +" presses a carving "
                      "on his "
                      "staff, and the light dims slightly.\n",
                      this_player());
            set_light(bong);                                               
            return 1;                                                     
         }                                                               
         write("You brighten the light slightly.\n");                   
         tell_room(environment(this_player()), this_player()->query_cap_name()+
                   " presses a carving on his "
                   "staff, and the place gets a little brighter.\n",
                   this_player()); 
         set_light(bong);                                               
         return 1;                                                     
      }                                                               
      if(bong < query_light()) {                                     
         write("You make the place darker.\n");  
         tell_room(environment(this_player()), this_player()->query_cap_name()+
                   " presses a carving on his "
                   "staff, and the place gets darker.\n",
                   this_player());
         set_light(bong);                                               
         return 1;                                                     
      }                                                               
      write("You light up the place.\n");                            
      set_light(bong);                                                
      return 1;                                                      
   } 
   return 0;                                                               
                                                                   
} /* do_light() */                                                
                                                                
                                                                       
int do_bomb() {                                          
   object ob, temp;                                     
   int changed;                                        
   changed = 1; 
   write("You press a series of carvings on your staff and cause "
         "a sudden, brilliant flash of light.\n");
   tell_room(environment(this_player()), this_player()->query_cap_name() +
      "presses a series of carvings on the power staff and there "
      "is a sudden, brilliant flash.\n",
             this_player());
   while (changed) {                                                   
   write_file("/d/mm/logs/BOMB",this_player()->query_cap_name()+
              " bombed a room with these objects present:\n"+
   query_multiple_short(all_inventory(environment(this_player())))+" on: "+
              ctime(time())+"\n");
      changed = 0;                                                    
      ob = first_inventory(environment(this_player()));              
      while (ob) {                                                  
         if (ob != this_object() && !query_ip_number(ob)) {        
            changed = 1;                                          
            temp = ob;                                           
         }                                                     
         ob = next_inventory(ob);                             
         if (temp) {                                         
            temp->dest_me();                                
         }                                                 
      }                                                   
   }                                                     
   return 1;                                            
                                                       
} /* do_bomb() */  

int do_level(string str) {
   object ob;
   if(!str) {
      write("Usage: level <something|someone>\n");
      return 1;
   }
   ob = find_living(str);
   if(!ob) {
      write("Can't find "+capitalize(str)+".\n");
      return 1;
   }
   write("Level of "+ob->query_cap_name()+" is "+ob->query_level()+".\n");
   return 1;

} /* do_level() */

int do_time() {
   write("The time in Norway: "+ctime(time())+".\n");
   return 1;
} /* do_time() */

int do_peace() {
   object *ob;
   object *att;
   object *call;
   int i, s;

   ob=all_inventory(environment(this_player()));
   i=0;
   for(i=0; i<sizeof(ob); i++) {
      if(living(ob[i])) {
         att=ob[i]->query_attacker_list();
         call=ob[i]->query_call_outed();
         for(s=0; s<sizeof(att); s++) {
            ob[i]->stop_fight(att[s]);
            att[s]->stop_fight(ob[i]);
         }
         for(s=0; s<sizeof(call); s++) {
            ob[i]->stop_fight(call[s]);
            call[s]->stop_fight(ob[i]);
         }
      }
   }
   write("You raise your hand and say: "
         "Peace, brother...\n");
   tell_room(environment(this_player()), this_player()->query_cap_name()+
             " raises his hand and says: Peace, brother...\n",
             ({this_player()}));
   return 1;
} /* do_peace() */

/* do_mmcre() */


int do_mmcre(string msg)
{
    object *people;
    int i;
    string ME;

    if(!msg)
    {
	write("Syntax: staff <message> or staff on/off.\n");
	return 1;
    }
    if(msg=="off")
    {
	this_player()->add_property("newbiestaff",1);
	write("Ok, staff channel off!\n");
	return 1;
    }
    if(msg=="on")
    {
	this_player()->remove_property("newbiestaff");
	write("Ok, staff channel turned on!\n");
	return 1;
    }
    if(this_player()->query_property("newbiestaff"))
    {
	write("Maybe turning your staff on will improve your broadcast.\n");
	return 1;
    }
    ME=this_player()->query_cap_name();
    people=users();
    for(i=0;i<sizeof(people);i++)
	if(sizeof(find_match("newbie domain staff",people[i])))
	    if(!people[i]->query_property("newbiestaff") )
		tell_object(people[i], ME+" [NEWBIE_CRE]: "+msg+"\n");
    return 1;
}



int do_fetch(string str) {
   object ob;
   if(!str) {
      write("Usage: fetch <something-from-/baseobs/*-or-/obj/misc>\n");
      return 1;
   }
   if(file_size("/baseobs/monsters/"+str+".c")>0)
      ob=new("/baseobs/monsters/"+str);
   else if(file_size("/baseobs/armours/"+str+".c")>0)
      ob=new("/baseobs/armours/"+str);
   else if(file_size("/baseobs/weapons/"+str+".c")>0)
      ob=new("/baseobs/weapons/"+str);
   else if(file_size("/baseobs/misc/"+str+".c")>0)
      ob=new("/baseobs/misc/"+str);
   else if(file_size("/obj/misc/"+str+".c")>0)
      ob=new("/obj/misc/"+str);

   if(!ob) 
      write(str+" not found in /baseobs/* dirs.\n");
   else {
      ob->move(environment(this_player()));
 write_file("/d/mm/logs/FETCH",this_player()->query_cap_name()+" fetched "
" a "+ob->query_short()+" at : "+ctime(time())+"\n");
      write("You press the correct carvings on your staff and open "
            "a small hole in the fabric of space and out "
            "falls a "+ob->query_short()+".\n");
      tell_room(environment(this_player()), this_player()->query_cap_name()+
      "opens a small hole in the fabric of space, "
                " and out falls a "+ob->query_short()+".\n",
                this_player());
   }
   return 1;
} /* do_fetch() */
  




// Function made by Timion....modified by Mirath...
int do_times() {
   if(!this_player()->query_creator()) {
      return 0;
   }
   write("It is now "+ctime(time())+" Norway Time.\n");
   write("It is now "+ctime(time() - 21600)+" Eastern Time.\n");
   write("It is now "+ctime(time() - 25200)+" Central Time.\n");
   write("It is now "+ctime(time() - 28800)+" Mountain Time.\n");
   write("It is now "+ctime(time() - 32400)+" Pacific Time.\n");
   return 1;
} /* do_times() */

int do_earmuffs(string str) {
   if(str=="mmcre") {
      if(this_player()->query_property("earmuff_staff")) {
         write("You are now no longer earmuffing staff.\n");
         this_player()->remove_property("earmuff_staff");
      } else {
         write("You are now earmuffing staff.\n");
         this_player()->add_property("earmuff_staff", 1);
      }
      return 1;
   }
   if(!str)
      if(this_player()->query_property("earmuff_staff"))
         write("You are currently earmuffing staff.\n");
      else
         write("You are currently listening to staff.\n");
} /* do_earmuffs() */

                                                        


int mmwho()
{
    object *people;
    int i;
    string ME;

    ME=this_player()->query_cap_name();
       tell_object(this_player(),"Newbie Domain Members currently logged on now : \n");
    people=users();
    for(i=0;i<sizeof(people);i++)
	if(sizeof(find_match("newbie domain staff",people[i])))
                 tell_object(this_player(), people[i]->short()+" \n ");
    tell_object(this_player(),"\n");
    return 1;
}


int qatt_me()
{
    object *ob;
    int i;
    int yep = 0;
    object *fig;
    int f;
    ob = users();
    for (i=0;i<sizeof(ob);i++)
    {
	if (sizeof(ob[i]->query_attacker_list())) {
	    write ("\n"+ ob[i]->query_cap_name()+ " is fighting:\n");
	    fig = ob[i]->query_attacker_list();
	    for (f=0;f<sizeof(fig);f++) {
		write ("\t"+ fig[f]->query_short()+ "\t("+ file_name(fig[f])+ ")\n");
		yep = 1;
	    }}}
    if (yep == 0) {
	write ("Wow, noone is fighting at the moment.\n");
	return 1;
    }return 1;}


int show_inss(string input)
{
    string *doms;
    object *ob;
    int i;
    string str;
    int yep = 0;
    object env;
    string *bass;

    ob = users();

    for (i=0; i<sizeof(ob); i++) {
	if ((string)ob[i]->query_gender_string() != "blue") {
	    str = file_name(environment(ob[i]));
	    bass = explode (str, "/");
	    doms = get_dir("/d/");
	    if (member_array(input, doms) == -1) { return 0; }
	    if (bass[1] == input) {
		yep = 1;
		write (ob[i]->query_cap_name()+ " in "+
		  environment(ob[i])->query_short()+ "   ("+
		  file_name(environment(ob[i]))+ ")\n");
	    }
	}
    }

    if (yep == 0) {
	write (sprintf("Noone in %s at the moment. *weep*\n", capitalize(input)));
	return 1;
    }
    return 1;
}

