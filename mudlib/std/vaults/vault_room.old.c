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
#include "login_handler.h"
#define FILE_SIZE 30000    // change, you die

 
string save_file = file_name(this_object())+"_save";
string vault_log = file_name(this_object())+"_log";
string *vault_admin = ({ });
string *guild_owner = ({ });
 
void set_save_file(string file) { if(file) save_file = file; }
string query_save_file() { return(save_file); }
 
void set_vault_log(string file) { if(file) vault_log = file; }
string query_vault_log() { return(vault_log); }
 
void set_admins(string *admin) { if(sizeof(admin)) vault_admin = admin; }
string *query_vault_admins() { return vault_admin; }

void set_guild_owner(string *gown) {if(sizeof(gown)) guild_owner = gown;}
string *query_guild_owner() { return guild_owner;}
 
create()
{
   ::create();
   add_sign("It is gold rimmed and engraved.\n",
      "\nType \"depositar <arma o armadura>\" para depositar un objeto.\n"
      "Type \"recuperar <arma o armadura>\" para recuperar un objeto del baul.\n"
      "Type \"listar\" obtener un listado de objetos en el baul..\n");
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
   add_action("do_deposit","depositar");
   add_action("do_retrieve","recuperar");
   add_action("do_list","listar");
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
      notify_fail("Sintaxis: logs\n");
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
   notify_fail("No estas autorizado a ver los logs.\n");
   return(0);
}


void do_deposit(string str)
{
   object vault = clone_object(STORAGE+"vault_obj.c");
   object ob, *all;
   int i,j, clonando = 0;
 
/* Added by Timion, 06 NOV 97
   To prevent deposits in vault during CTF */
    if (LOGIN_HANDLER->query_rebooting())
	{
	clonando = 1;
	log_file("ENTER_SOSPECHOSO", sprintf("Clonada: %15-s manda depositar en baul %s objeto %s [%s] [%d] [%s]\n",
	TP->query_short(),file_name(TO),str,ctime(time()),time(),(query_ip_name()?query_ip_name():query_ip_number())));
//	vault->dest_me();
//	return 1;
	}

 if("/global/omiq.c"->flag_in_progress())
   {
   notify_fail("Lo siento, no se puede depositar nada durante una flag-omiq.\n");
   vault->dest_me();
     return 0;
}
 
   if(query_property("vault_using"))
   {
      notify_fail("El baul esta siendo usado, prueba en unos minutos\n");
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
         write("No hay espacio suficiente para almacenar eso.\n");
         vault->dest_me();
         return(1);
      }
      for(i=0; i<sizeof(all); i++)
      {
         if((int)all[i]->query_auto_load())
         {
            write("Depositas "+all[i]->query_short()+" "
               "en el baul, y se convierte en una nube de humo.\n\n");
            vault->dest_me();
            all[i]->dest_me();
            return(1);
         }
        // This is here for a REASON, if you change it you had better
        // pray I don't find it - Radix
         if(!all[i]->query_weapon() && !all[i]->query_armour() &&
            !all[i]->query_scroll() && !all[i]->query_wand())
         {
            write("Ese objeto no esta permitido en el baul.\n");
            vault->dest_me();
            return 1;
         }
         else
         {
            write("Depositas satisfactoriamente "+all[i]->short()+".\n");
            say(this_player()->query_short()+" deposita "+
               all[i]->query_short()+" en el baul\n");
            all[i]->move(vault);
            if (clonando) {
            	log_file("ENTER_SOSPECHOSO", sprintf("Clonada efectiva: %s deposita %s (%s)\n",
            	TP->query_short(),all[i]->query_short(),file_name(all[i])));
            	all[i]->add_property("clonada_de", TP->query_short());
            }
            write_file(vault_log,this_player()->query_short()+
               "%^BOLD%^GREEN%^ deposito%^RESET%^:  "+all[i]->query_short()+" a las "+
               ctime(time())+"\n");
         }
      }
      vault->dest_me();
      return(1); // success
   }
   vault->dest_me();
   notify_fail("No puedes depositar "+str+".\n");
   return(0);
}
void do_retrieve(string str)
{
   object vault = clone_object(STORAGE+"vault_obj.c");
   object *all;
   int i;

   if(query_property("vault_using"))
   {
      notify_fail("El baul esta siendo usado, prueba en unos minutos.\n");
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
            say((string)this_player()->query_short()+" recupera "+
               all[i]->short()+" de un baul.\n");
            write("Recuperas "+all[i]->short()+" del baul.\n");
            write_file(vault_log,this_player()->query_short()+
               " %^BOLD%^RED%^recupero%^RESET%^:  "+all[i]->query_short()+" a las "+
               ctime(time())+"\n");
         }
         else
            write("Te asustas al abrir el gran peso de "+all[i]->short()+".\n");
      }
      vault->dest_me();
      return(1);
   }
   vault->dest_me();
   notify_fail("No puedes recuperar "+str+" de este baul.\n");
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
      notify_fail("El baul esta siendo usado, prueba en unos minutos.\n");
      vault->dest_me();
      return 0;
   }
   vault->move(this_object());
   vault->set_save_file(save_file);
   all = all_inventory(vault);
   if(sizeof(all))
   {
      write("Hay "+sizeof(all)+" objetos depositados en el baul:  \n\n");
      list = (string *)vault->list_contents();
      tmp="";
      for(i=0; i<sizeof(list); i++)
         tmp += list[i]+"\n";
      this_player()->more_string(tmp);
      write("\nCantidad maxima:  "+FILE_SIZE+"\n"
            "Cantidad actual:  "+file_size(query_save_file()+".o")+
            "\n\n");
   }
   else
      write("Este baul esta vacio actualmente.\n");
   vault->dest_me();
   return(1);
}

int query_vault_room() { return 1; }
