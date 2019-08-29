#include <standard.h>
inherit "/obj/armour"
#define BLANK "   "
 
string get_ipmsg(object);
string get_file_name(object);
string get_filemsg(object);
 
void setup()
{
position = 1;
set_base_armour("anillo");
set_name("anillo");
set_short("anillo");
set_main_plural("anillos");
set_long("Un trozo de metal con forma thorica que se adapta a tus dedos.\n");
}

void init()
{
	add_action("multi","anillo");	
}
 
static int multi()
{
  object *usuarios = users();
  object *ips, *users_ok, env;
  int i = 0, j=0;
  string ip;
  users_ok = ({ });
  for(i=0;i<sizeof(usuarios);i++) {
    users_ok += ({ usuarios[i] });
  }
  write("%^GREEN%^Gente con el mismo ip:%^RESET%^\n");
  i=0;
  while(i < sizeof(usuarios))
  {
    ip   = usuarios[i]->query_my_ip();
    ips  = ({ });
    j = i+1;
   while (j < sizeof(usuarios))
    {
      if (ip && (ip == usuarios[j]->query_my_ip()))
      {
       ips += ({ usuarios[j] });
        usuarios -= ({ usuarios[j] });
      }
      j++;
    }
    if(sizeof(ips))
    {
      write("%^BOLD%^* "+ip+" ->%^RESET%^\n");
      write(get_ipmsg(usuarios[i]));
      for (j=0;j<sizeof(ips);j++) {
        write(get_ipmsg(ips[j]));
      }
    }
    i++;
 }
   write("%^GREEN%^Gente con el mismo environment(party detect):%^RESET%^\n");
  usuarios = ({ });
  for(i=0;i<sizeof(users_ok);i++) {
    usuarios += ({ users_ok[i] });
  }
  i=0;
  while(i < sizeof(usuarios))
  {
    env   = environment(usuarios[i]);
    ips  = ({ });
    j = i+1;
   while (j < sizeof(usuarios))
    {
     if (env && (env == environment(usuarios[j])) )
      {
       ips += ({ usuarios[j] });
        usuarios -= ({ usuarios[j] });
      }
      j++;
    }
    if(sizeof(ips))
    {
      write("%^BOLD%^* "+get_file_name(usuarios[i])+" ->%^RESET%^\n");
      write(get_filemsg(usuarios[i]));
      for (j=0;j<sizeof(ips);j++) {
        write(get_filemsg(ips[j]));
      }
    }
    i++;
 }
  write("%^GREEN%^Gente con el mismo login:%^RESET%^\n");
  usuarios = ({ });
  for(i=0;i<sizeof(users_ok);i++) {
    usuarios += ({ users_ok[i] });
  }
 for (i=0; i<sizeof(usuarios)-1; i++)
 {
   ip = usuarios[i]->query_ident();
   for(j=i+1; j<sizeof(usuarios); j++)
     if (ip && (ip == usuarios[j]->query_ident()))
       write(ip+"\t--- "+usuarios[i]->query_short()+" y "+
                         usuarios[j]->query_short()+".\n");
 }
   return 1;
}
 
static string get_ipmsg(object obj)
{
   string back, color;
   switch(obj->query_property("bando"))
    {
     case 1: { color = "%^CYAN%^%^BOLD%^"; break; }
     case 2: { color = "%^RED%^%^BOLD%^"; break; }
     case 3: { color = "%^BLACK%^%^BOLD%^"; break; }
     case 4: { color = "%^YELLOW%^"; break; }
     default:{ color = "%^GREEN%^ SIN BANDO"; break; }
    }
   if( query_idle(obj) > 120 ) {
     back = sprintf("  %sIdle: %d%s %10-s%s%s\n",
            "%^RED%^",query_idle(obj)/60,"%^RESET%^",color+" "+obj->query_short()+"%^RESET%^",
             BLANK,get_file_name(obj));
   } else {
     back = sprintf("          %10-s%s%s\n",color+" "+obj->query_short()+"%^RESET%^",
             BLANK,get_file_name(obj));
   }
   return(back);
}
 
static string get_file_name(object obj)
{
   return (environment(obj)? virtual_file_name(environment(obj))
                      :"Esta en el limbo");
}
 
static string get_filemsg(object obj)
{
   string back, color;
   switch(obj->query_property("bando"))
    {
     case 1: { color = "%^CYAN%^%^BOLD%^"; break; }
     case 2: { color = "%^RED%^%^BOLD%^"; break; }
     case 3: { color = "%^BLACK%^%^BOLD%^"; break; }
     case 4: { color = "%^YELLOW%^"; break; }
     default:{ color = "%^GREEN%^ SIN BANDO"; break; }
    }
   if( query_idle(obj) > 120 ) {
     back = sprintf("  %sIdle: %d%s %10-s%s%s\n",
            "%^RED%^",query_idle(obj)/60,"%^RESET%^",color+" "+obj->query_short()+"%^RESET%^",
             BLANK,obj->query_my_ip());
   } else {
     back = sprintf("          %10-s%s%s\n",color+" "+obj->query_short()+"%^RESET%^",
             BLANK,obj->query_my_ip());
   }
   return(back);
}
