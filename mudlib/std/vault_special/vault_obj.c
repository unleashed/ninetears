// Vault object- Radix 1996
 
inherit "/std/container.c";
inherit "/global/auto_load";

mixed *auto_load;
string savefile;

void create()
{
   ::create();
   reset_get();
}
 
string query_savefile() { return savefile; }

set_save_file(string file)
{
   object olist;
   set_prevent_insert(0);
   savefile = file;
   if(!environment() || !environment()->query_vault_room())
      destruct(this_object());      // die screaming
   auto_load = ({ });
   seteuid("Root");
   restore_object(savefile);
   seteuid("PLAYER");
   if(sizeof(auto_load))  
      olist = load_auto_load(auto_load,this_object());
   else
      olist = ({ });
   reset_get();
   environment()->add_property("vault_using",1);
}
 
void dest_me()
{
   int i;
   object *olist = all_inventory(this_object());

   if(!savefile || !environment() || !environment()->query_vault_room())
   {
      destruct(this_object());    // die screaming
      return;
   }
   
   if(sizeof(olist)) 
      auto_load = create_auto_load(olist);
   else
      auto_load = ({ });
   seteuid("Root");
   save_object(savefile);
   seteuid("PLAYER");
   environment()->remove_property("vault_using");
   ::dest_me();
}
 
