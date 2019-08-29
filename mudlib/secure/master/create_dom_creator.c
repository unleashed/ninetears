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
      tell_object(this_player(),"Debes ser un dios para crear un nuevo dominio.\n");
      return 0;
   }
   if(high_programmer(capitalize(name))) 
   {
      tell_object(this_player(), "Nombre invalido...\n");
      return 0;
   }
   if(file_size("/d/"+name) != -1) 
   {
      tell_object(this_player(),"El Dominio ya existe (o invalido).\n");
      return 0;
   }
   if(sizeof(explode(name, "/")) > 1) 
   {
      tell_object(this_player(),"No se puede usar una / en el "
          "nombre del dominio.\n");
      return 0;
   }
   if(!"/secure/login"->test_creator(lord)) 
   {
      tell_object(this_player(),"El Thane debe existir y ser un "
         "creador.\n");
      return 0;
   }
   mkdir("/d/"+name);
   file = read_file("/std/dom/master.c");
   write_file("/d/"+name+"/master.c", "#define DOM_LORD \""+lord+"\"\n");
   write_file("/d/"+name+"/master.c", "#define DOMAIN \""+name+"\"\n"); 
   write_file("/d/"+name+"/master.c", file);
   file = read_file("/std/dom/common.c");
   write_file("/d/"+name+"/common.c",
              "#define DOM_TITLE \"dominio de "+capitalize(name)+"\"\n");
   write_file("/d/"+name+"/common.c", "#define DOM_LORD \""+capitalize(lord)+"\"\n");
   write_file("/d/"+name+"/common.c", "#define DOMAIN \""+name+"\"\n");
   write_file("/d/"+name+"/common.c", file);
   file = read_file("/std/dom/loader.c");
   write_file("/d/"+name+"/loader.c", "#define DOMAIN \""+name+"\"\n");
   write_file("/d/"+name+"/loader.c", file);
   save_object("/secure/master",1);
   write("Created domain "+name+".\n");
   log_file("PROMOTIONS", "Dominio "+name+" creado con Thane "+lord+
              " por "+geteuid(previous_object())+"\n");
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
      write("Directorio ya existe o invalido.\n");
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
   write("Creador "+name+" promocionado.\n");
   if(find_player(name))
   {
      find_player(name)->set_creator(1);
      find_player(name)->save();
      tell_object(find_player(name), "Acabas de ser promocionado a Creador "
         "por "+capitalize(geteuid(previous_object()))+".\n"+
	 "Reentra en el mud. Aprovecha tu oportunidad, suerte.\n");
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
      notify_fail("Uso: demote <creador> <razon>\n");
      return 0;
   }
   if(!"/secure/login"->test_creator(name))
      return 0;
   if(query_lord(name))
   { 
      notify_fail("Los Lords no pueden ser demoteados.\n");
      return 0;
   }
   write_file("/log/DEMOTE", name+" demoteado por "+
              previous_object()->query_cap_name()+" en "+ctime(time())+
              "\nRazon: "+reason+"\n");
   if(find_player(name)) 
   {
      find_player(name)->set_creator(0);
      find_player(name)->save();
      tell_object(find_player(name), "Acabas de ser devuelto a tu estado de mortal por "+
                capitalize(previous_object()->query_cap_name())+".\n");
      find_player(name)->really_quit();
   } 
   write_file("/players/"+name[0..0]+"/"+name+".o","creator 0\n");
   rename("/w/"+name,"/w/oldcreators/"+name);
   rename("/players/"+name[0..0]+"/"+name+".o","/w/oldcreators/"+name);
	// rmdir("/w/"+name);
   write("Creador "+capitalize(name)+" demoteado.\n");
   write("Borrando su mail...");
   POSTAL_D->retire_user(name);
   write("Done.\n");
   write_file("/w/oldcreators/"+name+"/DEMOTED",
              capitalize(name)+" demoteado por "+
              previous_object()->query_cap_name()+" : "+ctime(time())+
              "\nRazon: "+reason+"\n\n");
   return 1;
}
