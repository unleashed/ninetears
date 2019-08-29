// March 13, 1995
/*
   Vaults - Originally designed to contain items for players
      to save'em through reboots.  Too much work, changed to
      group/guild/clan/house access instead of an object file
      for each individual player.
   For FR III, guilds and any other group willing to purchase
   these for 5000 platinum coins will be allowed to have access.
   Main purpose was for newbie equipment but other vaults can be
   purchased for individual Guild masters and even senior members
   of a group.  Keep in mind, the fewer with access, charge
   them more.  
   Vault restrictions NOT to be changed: 
   Nothing but weapons, armours, scrolls, and wands, and definitely
   no unsaveable items.

   How to make your own in the game:
   Simple, inherit this file and describe your room.  Make sure to
   copy or design your own add_sign()   *grin*   
   However, before putting it into the game, must be approved by
   a Demi-God beforehand and /d/apriors/doms/VAULTS should be 
   updated.
   Have fun!
 
                        Radix : Thane of Hoerk
*/
// Added logging with player readable abilities for monitoring
// by Guild leader and immortals.
// Use set_admins( ({"name1","name2",... }) ); or "all" for everyone.
// Radix - December 4, 1995
//
// Changed to use /global/auto_load as Taniwha showed me how  (:
// New driver allows larger buffer, save object file can be huge,
// won't break BUT, the restriction is set to 30k for a reason.
// Radix - February 10, 1996
//
// Missing item bug regretfully fixed.  Calling save_object
// when someone else simultaneously uses the vault as well
// caused it.  Radix - Jan 4, 1996
 
inherit "/std/room";
#include "path.h"
#define FILE_SIZE 30000    // change, you die
 
string save_file = file_name(this_object())+"_save";
string vault_log = file_name(this_object())+"_log";
string *vault_admin = ({ });
 
void set_save_file(string file) { if(file) save_file = file; }
string query_save_file() { return(save_file); }
 
void set_vault_log(string file) { if(file) vault_log = file; }
string query_vault_log() { return(vault_log); }
 
void set_admins(string *admin) { if(sizeof(admin)) vault_admin = admin; }
string *query_vault_admins() { return vault_admin; }
 
create()
{
   ::create();
   add_sign("It is gold rimmed and engraved.\n",
      "\nType \"deposit <weapon or armour>\" to store an object.\n"
      "Type \"retrieve <weapon or armour>\" to get an item from the vault.\n"
      "Type \"list\" to get a list of all stored items.\n");
}
setup()
{
   set_light(80);
   set_short("Vaultroom");
   set_long("This is a vaultroom.  A large platinum vault is built "
      "securely into the foundation of the room.\n\n");
 
}
 
void init()
{
   ::init();
   add_action("do_deposit","deposit");
   add_action("do_retrieve","retrieve");
   add_action("do_list","list");
   add_action("view_vault_log","logs");
}
 
void view_vault_log(string str)
{
   string name;
   string *logf = ({ });
   string tmp;
   int i;
 
   if(str) 
   {
      notify_fail("Syntax: logs\n");
      return(0);
   }
   name = this_player()->query_name();
   if(this_player()->query_creator() ||
      member_array(name,vault_admin) != -1 ||
      vault_admin[0] == "all" || !sizeof(vault_admin))
   {
      tmp = read_file(query_vault_log());
      this_player()->more_string(tmp);
      return(1);
   }
   notify_fail("You don't have permission to view the logs.\n");
   return(0);
}
void do_deposit(string str)
{
   object vault = clone_object(STORAGE+"vault_obj.c");
   object ob, *all;
   int i,j;
 
/* Added by Timion, 06 NOV 97
   To prevent deposits in vault during CTF */
 if("/global/omiq.c"->flag_in_progress())
   {
   notify_fail("Sorry, you may not deposit items during a Flag Game.\n");
   vault->dest_me();
     return 0;
}
 
   if(query_property("vault_using"))
   {
      notify_fail("Vault is being used, try again in a minute.\n");
      vault->dest_me();
      return 0;
   }
   all = find_match(str,this_player());
   if(sizeof(all))
   {
      vault->move(this_object());
      vault->set_save_file(save_file);
      
      if(file_size(query_save_file()+".o") > FILE_SIZE)
      {
         write("There is not enough room within the vaults to hold "
            "that.\n");
         vault->dest_me();
         return(1);
      }
      for(i=0; i<sizeof(all); i++)
      {
         if((int)all[i]->query_auto_load())
         {
            write("As you deposit the "+all[i]->query_short()+" "
               "into the vault, it vanishes in a puff of blue "
               " smoke!\n\n");
            vault->dest_me();
            all[i]->dest_me();
            return(1);
         }
        // This is here for a REASON, if you change it you had better
        // pray I don't find it - Radix
         if(!all[i]->query_weapon() && !all[i]->query_armour() &&
            !all[i]->query_scroll() && !all[i]->query_wand())
         {
            write("That item is not allowed within these vaults.\n");
            vault->dest_me();
            return 1;
         }
         else
         {
            write("You successfully deposit "+all[i]->short()+".\n");
            say(this_player()->query_short()+" deposits a "+
               all[i]->query_short()+" into the vault.\n");
            all[i]->move(vault);
            write_file(vault_log,this_player()->query_short()+
               " deposited:  "+all[i]->query_short()+" on "+
               ctime(time())+"\n");
         }
      }
      vault->dest_me();
      return(1); // success
   }
   vault->dest_me();
   notify_fail("You cannot deposit "+str+".\n");
   return(0);
}
void do_retrieve(string str)
{
   object vault = clone_object(STORAGE+"vault_obj.c");
   object *all;
   int i;

   if(query_property("vault_using"))
   {
      notify_fail("Vault is being used, try again in a minute.\n");
      vault->dest_me();
      return 0;
   }
   vault->move(this_object());
   vault->set_save_file(save_file);
   all = find_match(str,vault);
   if(sizeof(all))
   {
      for(i=0; i<sizeof(all); i++)
      {
         if(this_player()->query_loc_weight() + all[i]->query_weight() <
            this_player()->query_max_weight())
         {
            all[i]->move(this_player());
            say((string)this_player()->query_short()+" retrieves "+
               all[i]->short()+" from a vault.\n");
            write("You retrieve "+all[i]->short()+" from the vault.\n");
            write_file(vault_log,this_player()->query_short()+
               " retrieved:  "+all[i]->query_short()+" on "+
               ctime(time())+"\n");
         }
         else
            write("You strain as you open the door and gasp at the "
                  "added weight of retrieving "+all[i]->short()+".\n");
      }
      vault->dest_me();
      return(1);
   }
   vault->dest_me();
   notify_fail("You cannot retrieve "+str+" from this vault.\n");
   return(0);
}
void do_list()
{
   object vault = clone_object(STORAGE+"vault_obj.c");
   object *all;
   int i;
   string *list;
   string tmp;   // Radix Nov 29, 1997

   if(query_property("vault_using"))
   {
      notify_fail("Vault is being used, try again in a minute.\n");
      vault->dest_me();
      return 0;
   }
   vault->move(this_object());
   vault->set_save_file(save_file);
   all = all_inventory(vault);
   if(sizeof(all))
   {
      write("There are "+sizeof(all)+" items stored in this vault:  \n\n");
      list = (string *)vault->list_contents();
      tmp="";
      for(i=0; i<sizeof(list); i++)
         tmp += list[i]+"\n";
      this_player()->more_string(tmp);
      write("\nMax amount:  "+FILE_SIZE+"\n"
            "Current amount:  "+file_size(query_save_file()+".o")+
            "\n\n");
   }
   else
      write("This vault is currently empty.\n");
   vault->dest_me();
   return(1);
}

int query_vault_room() { return 1; }
