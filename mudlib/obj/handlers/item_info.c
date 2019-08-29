// Another stat keeper... this one for all items in the
// game hopefully.  - 
// Radix Nov 1996 - Jan 1997
// Version 1.3
 
inherit "/std/object.c";
 
#define SAVE "/save/"
 
mapping container_data, armour_data, weapon_data;
 
void purge_info();

// Pouches, backpacks, ...
mapping query_container_data() { return container_data; }
// Armours...
mapping query_armour_data() { return armour_data; }
// Weapons...
mapping query_weapon_data() { return weapon_data; }

int query_prevent_shadow(object o) { return 1; }
 
void load_this_ob() {
     restore_object(SAVE+"item_info");
}
 
void save_this_ob() {
    save_object(SAVE+"item_info",1);
}
 
create()
{
   object::create();
   container_data = ([ ]);
   weapon_data = ([ ]);
   armour_data = ([ ]);
   load_this_ob();
   if(!container_data)
      container_data = ([ ]);
   if(!weapon_data)
      weapon_data = ([ ]);
   if(!armour_data)
      armour_data = ([ ]);
   seteuid("Root");
   purge_info();
}
 
dest_me()
{
   save_this_ob();
   destruct(this_object());
}
 
string crop_string(string longpa, int howlong) {
  string shorter;
  shorter = longpa[sizeof(longpa)-howlong..sizeof(longpa)];
  return shorter;
}
 
void purge_info()
{
   
}

// Called from /global/creator/cmds/qc.c
int query_qc_perms(string name)
{
   string *rights = ({ "taniwha", "radix" });
   return member_array(name, rights) != -1;
}

// Called from /global/creator/cmds/info.c 
int query_info_perms(string name, object obj)
{
   string dom = domain_origin(obj);
   mixed mas;
   if(!dom) return 0;   // /w/creator won't have data anyway
   mas = "/d/"+dom+"/master";
   return mas->valid_write(explode(real_filename(obj),"/"),name,0);
}

void display_item_properties(object ob)
{
   mapping m;
   int i;
   m = ob->query_properties();
   if(!sizeof(keys(m)))
      return ;
   write("Properties:\n   ");
   for(i=0; i<sizeof(keys(m)); i++)
      write(keys(m)[i]+" : "+m[keys(m)[i]]+"\n   ");
   write("\n");
   return;
}

// Called from /global/creator/cmds/info.c option -update
void mapping_update()
{
   string *k = keys(container_data);
   int i;
   if(sizeof(k))
   {
      write("Updating valid Containers...\n");
      for(i=0; i<sizeof(k); i++)
         if(file_size(k[i]+".c") < 1)
         {
            write("   Removing: "+k[i]+"\n");
            map_delete(container_data, k[i]);
         }
   }
   k = keys(weapon_data);
   if(sizeof(k))
   {
      write("Updating valid Weapons...\n");
      for(i=0; i<sizeof(k); i++)
         if(file_size(k[i]+".c") < 1)
         {
            write("   Removing: "+k[i]+"\n");
            map_delete(weapon_data, k[i]);
         }
   }
   k = keys(armour_data);
   if(sizeof(k))
   {
      write("Updating valid Armour...\n");
      for(i=0; i<sizeof(k); i++)
         if(file_size(k[i]+".c") < 1)
         {
            write("   Removing: "+k[i]+"\n");
            map_delete(armour_data, k[i]);
         }
   }
   save_this_ob();
   write("Done.\n");
   return 1;
}
/* container_data mapping:
     ([ "domain" : 
         ([ "path" : ({
                        max_weight,
                        enchant,
                        qc'ed,     
                        qc'ed by,
                        comments
                     })
         ])
     ])
*/
void update_container(object ob)
{
   mapping obmap = ([ ]);
   mixed tmp = ({ });
   int caught = 0;
   string dom, file;
   if(!ob) 
      return;
   dom = domain_origin(ob);
   file = real_filename(ob);
   if(!dom || !file)
      return;
   obmap = container_data[dom];
   if(!m_sizeof(obmap)) obmap = ([ ]);
   tmp = obmap[file];
   if(!sizeof(tmp))
   {
      tmp = allocate(5);
      tmp[0] = ob->query_max_weight();
      tmp[1] = ob->query_enchant();
      tmp[2] = 0;
      tmp[3] = 0;
      tmp[4] = 0;
      obmap[file] = tmp;
      container_data[dom] = obmap;
      save_this_ob();
      return;
   }
   if(tmp[0] != ob->query_max_weight()) caught = 1;
   if(tmp[1] != ob->query_enchant()) caught = 1;
   if(caught)
   {
      tmp[2] = 0;
      tmp[3] = 0;
      obmap[file] = tmp;
      container_data[dom] = obmap;
      save_this_ob();
   }
   return;
}
 
// Called from /global/creator/cmds/unqc.c
void unqc_item_container(object ob)
{
   mapping obmap = ([ ]);
   mixed tmp = ({ });
   string dom, file;
   if(!ob) 
      return;
   dom = domain_origin(ob);
   file = real_filename(ob);
   if(!dom || !file)
      return;
   obmap = container_data[dom];
   if(!m_sizeof(obmap)) obmap = ([ ]);
   tmp = obmap[file];
   if(!sizeof(tmp))
   {
      write("ERROR: Container has no data!\n");
      return;
   }
   tmp[2] = 0;
   tmp[3] = 0;
   obmap[file] = tmp;
   container_data[dom] = obmap;
   save_this_ob();
   write("File: "+file+" now Un-QCed.\n");
   return;
}

void info_item_container(object ob)
{
   mapping obmap = ([ ]);
   mixed tmp = ({ });
   int caught = 0;
   string dom, file;
   if(!ob) 
      return;
   dom = domain_origin(ob);
   file = real_filename(ob);
   if(!dom || !file)
      return;
   obmap = container_data[dom];
   if(!m_sizeof(obmap)) obmap = ([ ]);
   tmp = obmap[file];
   if(!sizeof(tmp))
   {
      write("ERROR: Container has no data!\n");
      return;
   }
   write("Filename: "+file+"\n"+
        "Max weight: "+tmp[0]+"\n"
        "Enchant: "+tmp[1]+"\n"
        "QCed: ");
   if(tmp[2])
      write("Yes \nQCed by: "+capitalize(tmp[3])+"\n");
   else write("No\n");
   write("Comments:\n   ");
   if(!tmp[4]) 
      write("None.\n\n");
   else
      write(tmp[4]+"\n\n");
   return;
}

// Called from /global/creator/cmds/info.c
void domain_item_containers(string dom)
{
   string s;
   mixed obs, obmap;
   mixed tmp;
   int i;
   if(member_array(dom,get_dir("/d/")) == -1)
   {
      write(capitalize(dom)+" does not exist.\n");
      return;
   }
   obmap = container_data[dom];
   if(!obmap)
      obmap = ([ ]);
   obs = sort_array(keys(obmap),1);
   s = sprintf("%-40s %6s %6s %12s %6s\n",
      "Filename","Mx Wt","Enchnt","QCed by","Com'ed");
   if(!sizeof(obs))
      s+= sprintf("\nNo data.\n");
   for(i=0; i<sizeof(obs); i++)
   {
      tmp = explode(obs[i],"/");
      tmp = implode(tmp - ({ tmp[0], tmp[1] }),"/");
      s+= sprintf("%-35s%5d%5d ",
               tmp, obmap[obs[i]][0], obmap[obs[i]][1]); 
      s+= sprintf("%12s",obmap[obs[i]][3]);
      if(obmap[obs[i]][4]) 
         s += sprintf("%5s","Yes");
      s+= "\n";
   }
   write(s);
}

/* weapon_data mapping:
     ([ "domain" : 
         ([ "path" : ({
                        weight,
                        enchant,
                        rolls,
                        dice,
                        roll_add,
                        twohanded,
                        qc'ed by,
                        comments
                     })
         ])
     ])
*/
void update_weapon(object ob)
{
   mapping obmap = ([ ]);
   mixed tmp = ({ });
   int caught = 0;
   string dom, file;
   int *dmg;
   if(!ob) 
      return;
   dom = domain_origin(ob);
   file = real_filename(ob);
   if(!dom || !file)
      return;
   obmap = weapon_data[dom];
   if(!m_sizeof(obmap)) obmap = ([ ]);
   tmp = obmap[file];
   dmg = ob->query_damage_vals();
   if(!sizeof(tmp))
   {
      tmp = allocate(8);
      tmp[0] = ob->query_weight();
      tmp[1] = ob->query_enchant();
      tmp[2] = dmg[0];
      tmp[3] = dmg[1];
      tmp[4] = dmg[2];
      tmp[5] = ob->query_twohanded();
      tmp[6] = 0;
      tmp[7] = 0;
      obmap[file] = tmp;
      weapon_data[dom] = obmap;
      save_this_ob();
      return;
   }
   if(tmp[0] != ob->query_weight()) caught = 1;
   if(tmp[1] != ob->query_enchant()) caught = 1;
   if(tmp[2] != dmg[0]) caught = 1;
   if(tmp[3] != dmg[1]) caught = 1;
   if(tmp[4] != dmg[2]) caught = 1;
   if(tmp[5] != ob->query_twohanded()) caught = 1;
   if(caught)
   {
      tmp[6] = 0;
      obmap[file] = tmp;
      weapon_data[dom] = obmap;
      save_this_ob();
   }
   return;
}
 
// Called from /global/creator/cmds/qc.c
void qc_weapon(object ob)
{
   mapping obmap = ([ ]);
   mixed tmp = ({ });
   int caught = 0;
   string dom, file;
   if(!ob) 
      return;
   dom = domain_origin(ob);
   file = real_filename(ob);
   if(!dom || !file)
      return;
   obmap = weapon_data[dom];
   if(!m_sizeof(obmap)) obmap = ([ ]);
   tmp = obmap[file];
   if(!sizeof(tmp))
   {
      write("ERROR: Weapon has no data!\n");
      return;
   }
   tmp[6] = geteuid(this_player());
   obmap[file] = tmp;
   weapon_data[dom] = obmap;
   save_this_ob();
   write("File: "+file+" now QCed.\n");
   return;
}

// Called from /global/creator/cmds/unqc.c
void unqc_weapon(object ob)
{
   mapping obmap = ([ ]);
   mixed tmp = ({ });
   string dom, file;
   if(!ob) 
      return;
   dom = domain_origin(ob);
   file = real_filename(ob);
   if(!dom || !file)
      return;
   obmap = weapon_data[dom];
   if(!m_sizeof(obmap)) obmap = ([ ]);
   tmp = obmap[file];
   if(!sizeof(tmp))
   {
      write("ERROR: Weapon has no data!\n");
      return;
   }
   tmp[6] = 0;
   obmap[file] = tmp;
   weapon_data[dom] = obmap;
   save_this_ob();
   write("File: "+file+" now Un-QCed.\n");
   return;
}

void info_weapon(object ob)
{
   mapping obmap = ([ ]);
   mixed tmp = ({ });
   int caught = 0;
   string dom, file;
   if(!ob) 
      return;
   dom = domain_origin(ob);
   file = real_filename(ob);
   if(!dom || !file)
      return;
   obmap = weapon_data[dom];
   if(!m_sizeof(obmap)) obmap = ([ ]);
   tmp = obmap[file];
   if(!sizeof(tmp))
   {
      write("ERROR: Weapon has no data!\n");
      return;
   }
   write("Filename: "+file+"\n"+
        "Weight  : "+tmp[0]+"\n"
        "Enchant : "+tmp[1]+"\n"
        "Damage  : "+tmp[2]+"d"+tmp[3]+"+"+tmp[4]+"\n"
        "Hands   : ");
   if(ob->query_twohanded())
      write("2\n");
   else
      write("1\n");
   write("QCed : ");
   if(tmp[6])
      write("Yes \nQCed by: "+capitalize(tmp[6])+"\n");
   else 
      write("No\n");
   if(!tmp[5]) 
      if(file_size(file+".comments") > 0)
         write(read_file(file+".comments")+"\n\n");
      else
         write("None.\n\n");
   else
      write(tmp[5]+"\n\n");
   display_item_properties(ob);
   return;
}

// Called from /global/creator/cmds/info.c
void domain_weapons(string dom)
{
   string s;
   mixed obs, obmap;
   mixed tmp;
   int i;
   if(member_array(dom,get_dir("/d/")) == -1)
   {
      write(capitalize(dom)+" does not exist.\n");
      return;
   }
   obmap = weapon_data[dom];
   if(!obmap)
      obmap = ([ ]);
   obs = sort_array(keys(obmap),1);
   s = sprintf("%-40s %6s %6s %12s %6s\n",
      "Filename","Enchnt","Damage","QCed by","Com'ed");
   if(!sizeof(obs))
      s+= sprintf("\nNo data.\n");
   for(i=0; i<sizeof(obs); i++)
   {
      tmp = explode(obs[i],"/");
      tmp = implode(tmp - ({ tmp[0], tmp[1] }),"/");
      s+= sprintf("%-40s%5d ",
               tmp, obmap[obs[i]][1]); 
      s+= sprintf("%6s",obmap[obs[i]][2]+"d"+obmap[obs[i]][3]+"+"+
               obmap[obs[i]][4]);
      if(obmap[obs[i]][6])
         s+= sprintf("%12s",capitalize(obmap[obs[i]][6]));
      else
         s+= sprintf("%12s","");
      if(obmap[obs[i]][7]) 
         s += sprintf("%5s","Yes");
      s+= "\n";
   }
   this_player()->more_string(s);
}

/* armour_data mapping:
     ([ "domain" : 
         ([ "path" : ({
                        weight,
                        size,
                        enchant,
                        ac,
                        qc'ed by,
                        comments
                     })
         ])
     ])
*/
void update_armour(object ob)
{
   mapping obmap = ([ ]);
   mixed tmp = ({ });
   int caught = 0;
   string dom, file;
   if(!ob) 
      return;
   dom = domain_origin(ob);
   file = real_filename(ob);
   if(!dom || !file)
      return;
   obmap = armour_data[dom];
   if(!m_sizeof(obmap)) obmap = ([ ]);
   tmp = obmap[file];
   if(!sizeof(tmp))
   {
      tmp = allocate(6);
      tmp[0] = ob->query_weight();
      tmp[1] = ob->query_size();
      tmp[2] = ob->query_enchant();
      tmp[3] = ob->query_ac();
      tmp[4] = 0;
      tmp[5] = 0;
      obmap[file] = tmp;
      armour_data[dom] = obmap;
      save_this_ob();
      return;
   }
   if(tmp[0] != ob->query_weight()) 
   {
      caught = 1;
      tmp[0] = ob->query_weight();
   }
   if(tmp[1] != ob->query_size()) 
   {
      caught = 1;
      tmp[1] = ob->query_size();
   }
   if(tmp[2] != ob->query_enchant()) 
   {
      caught = 1;
      tmp[2] = ob->query_enchant();
   }
   if(tmp[3] != ob->query_ac()) 
   {
      caught = 1;
      tmp[3] = ob->query_ac();
   }
   if(caught)
   {
      if(this_player() && this_player()->query_creator() && tmp[4])
         write("\nThis item needs to be QCed.\n");
      tmp[4] = 0;
      obmap[file] = tmp;
      armour_data[dom] = obmap;
      save_this_ob();
   }
   return;
}
 
// Called from /global/creator/cmds/qc.c
void qc_armour(object ob)
{
   mapping obmap = ([ ]);
   mixed tmp = ({ });
   string dom, file;
   if(!ob) 
      return;
   dom = domain_origin(ob);
   file = real_filename(ob);
   if(!dom || !file)
      return;
   obmap = armour_data[dom];
   if(!m_sizeof(obmap)) obmap = ([ ]);
   tmp = obmap[file];
   if(!sizeof(tmp))
   {
      write("ERROR: Armour has no data!\n");
      return;
   }
   tmp[4] = geteuid(this_player());
   obmap[file] = tmp;
   armour_data[dom] = obmap;
   save_this_ob();
   write("File: "+file+" now QCed.\n");
   return;
}
 
// Called from /global/creator/cmds/unqc.c
void unqc_armour(object ob)
{
   mapping obmap = ([ ]);
   mixed tmp = ({ });
   string dom, file;
   if(!ob) 
      return;
   dom = domain_origin(ob);
   file = real_filename(ob);
   if(!dom || !file)
      return;
   obmap = armour_data[dom];
   if(!m_sizeof(obmap)) obmap = ([ ]);
   tmp = obmap[file];
   if(!sizeof(tmp))
   {
      write("ERROR: Armour has no data!\n");
      return;
   }
   tmp[4] = 0;
   obmap[file] = tmp;
   armour_data[dom] = obmap;
   save_this_ob();
   write("File: "+file+" now Un-QCed.\n");
   return;
}

// Called from /global/creator/cmds/info.c
void info_armour(object ob)
{
   mapping obmap = ([ ]);
   mixed tmp = ({ });
   string dom, file;
   if(!ob) 
      return;
   dom = domain_origin(ob);
   file = real_filename(ob);
   if(!dom || !file)
      return;
   obmap = armour_data[dom];
   if(!m_sizeof(obmap)) obmap = ([ ]);
   tmp = obmap[file];
   if(!sizeof(tmp))
   {
      write("ERROR: Armour has no data!\n");
      return;
   }
   write("Filename: "+file+"\n"+
        "Weight  : "+tmp[0]+"\n"
        "Size    : "+tmp[1]+"\n"
        "Enchant : "+tmp[2]+"\n"
        "AC      : "+tmp[3]+"\n"
        "QCed    : ");   
   if(tmp[4])
      write("Yes \nQCed by : "+capitalize(tmp[4])+"\n");
   else 
      write("No\n");
   write("Comments:\n   ");
   if(!tmp[5]) 
      if(file_size(file+".comments") > 0)
         write(read_file(file+".comments")+"\n\n");
      else
         write("None.\n\n");
   else
      write(tmp[5]+"\n\n");
   display_item_properties(ob);
   return;
}

// Called from /global/creator/cmds/info.c
void domain_armours(string dom)
{
   string s;
   mixed obs, obmap;
   mixed tmp;
   int i;
   if(member_array(dom,get_dir("/d/")) == -1)
   {
      write(capitalize(dom)+" does not exist.\n");
      return;
   }
   obmap = armour_data[dom];
   if(!obmap)
      obmap = ([ ]);
   obs = sort_array(keys(obmap),1);
   s = sprintf("%-40s%4s%4s%4s%5s%12s%10s\n",
      "Filename","Wt","Sz","AC","Ench","QCed by","Commented");
   if(!sizeof(obs))
      s+= sprintf("\nNo data.\n");
   for(i=0; i<sizeof(obs); i++)
   {
      tmp = explode(obs[i],"/");
      tmp = implode(tmp - ({ tmp[0], tmp[1] }),"/");
      s+= sprintf("%-40s%4d",tmp, obmap[obs[i]][0]); 
      s+= sprintf("%4d%4d",obmap[obs[i]][1],obmap[obs[i]][3]);
      s+= sprintf("%5d",obmap[obs[i]][2]);
      if(stringp(obmap[obs[i]][4]))
         s+= sprintf("%12s",capitalize(obmap[obs[i]][4]));
      else
         s+= sprintf("%12s","");
      if(stringp(obmap[obs[i]][5]))
         s+= sprintf("%10s","Yes");
      else
         s+= sprintf("%10s","No");
      s+= "\n";
   }
   this_player()->more_string(s);
}


