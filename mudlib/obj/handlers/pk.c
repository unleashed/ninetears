//  Radix 1996
//  Site and player data on PKs
/*  Basically break down killers by who they're killing (guilds, groups...)
    I'm sure Anirudh would find a better way, but then nobody would
    understand it.   (:
    Version 1.0
*/
/*  mapping killer_data 
      ([ "name" : time first logged in,
                  time this last touched,
                  ({ site1, site2, ... }),
                  ([ "guild_ob1" : ({  number killed,
                                       avg total xp of vics / 1000,
                                       avg level of vics,
                                   }),
                  ]),
                  ([ "group_ob1" : ({  number killed,
                                       avg total xp of vics / 1000,
                                       avg level of vics,
                                   }),
                  ]),
                  ([ "race_group_ob1" : ({ number killed,
                                           avg total xp of vics / 1000,
                                           avg level of vics,
                                        })
                  ])
      ])
*/

inherit "/std/object.c";

#define SAVE "/save/"

mapping killer_data;

mapping query_killer_data() { return killer_data; }

void load_this_ob() {
     restore_object(SAVE+"pk");
}

void save_this_ob() {
    save_object(SAVE+"pk",1);
}

create()
{
   ::create();
   killer_data = ([ ]);
   load_this_ob();
}

dest_me()
{
   save_this_ob();
   destruct(this_object());
}

int get_start_time(string name)
{
   return "/secure/start_time"->query_start_time(name);
}

string *get_orgs(object pl)
{
   return ({ pl->query_guild_ob(), pl->query_group_ob(), 
             pl->query_race_group_ob() });
}

// Called from /obj/handlers/death.c
void update_player_killed(object victim, object killer)
{
   mixed tmp, tmp_org;
   string *orgs;
   int i, tmp_avg;
   if(!victim || !killer) return;
   if(wizardp(victim) || wizardp(killer)) return;
    if("/global/omiq"->flag_in_progress()) return;
   load_this_ob();
   tmp = killer_data[killer->query_name()];
   if(!tmp) tmp = allocate(6);
   if(tmp[0] != get_start_time(killer->query_name()))
   {
      tmp = allocate(6);
      tmp[0] = get_start_time(killer->query_name());
   }
   tmp[1] = time();
   if(!tmp[2]) 
      tmp[2] = ({ });
   if(member_array(query_ip_number(killer),tmp[2]) == -1)
      tmp[2] += ({ query_ip_number(killer) });
   orgs = get_orgs(victim);
   if(!tmp[3]) tmp[3] = ([ ]);   // guilds
   if(!tmp[4]) tmp[4] = ([ ]);   // groups
   if(!tmp[5]) tmp[5] = ([ ]);   // race_groups
   for(i=0; i<sizeof(orgs); i++)
   {
      if(!orgs[i]) continue;
      tmp_org = tmp[3+i][orgs[i]];
      if(!tmp_org)
      {
         tmp_org = allocate(3);
         tmp_org[0] = 1;
         tmp_org[1] = victim->query_total_xp() /1000;
         tmp_org[2] = victim->query_level();
      }
      else
      {
         tmp_avg = tmp_org[0] * tmp_org[1] + victim->query_total_xp()/1000;
         tmp_org[0] = tmp_org[0] + 1;
         tmp_org[1] = tmp_avg / tmp_org[0];
         tmp_avg = (tmp_org[0] -1) * tmp_org[2] + victim->query_level();
         tmp_org[2] = tmp_avg / tmp_org[0]; 
      }
      tmp[3+i][orgs[i]] = tmp_org;
   }/* for */
   killer_data[killer->query_name()] = tmp;
   save_this_ob();
   return;
}/* update_player_killed */

// Called from /global/creator/cmds/info.c
void info_player(string name)
{
   mixed tmp, org;
   string *sites, *orgs;
   string ret;
   int i,j;
   int totk, totxp, totl;
   totk = totxp = totl = 0;
   if(!name) return;
   ret = "PK Data for "+capitalize(name)+"\n\n";
   tmp = killer_data[name];
   if(!tmp)
   {
      ret += "No data.\n\n";
      this_player()->more_string(ret);
      return;
   }
   sites = implode(tmp[2],"\n");
   ret += "Last PKed on:  "+ctime(tmp[1])+"\n";
   ret += sprintf("Sites:  %*#-s\n",this_player()->query_cols(),sites);
   for(i=0; i<3; i++)
   {
      switch(i)
      {
         case(0) :
            ret += sprintf("\n%-34s%12s%12s%10s\n","Guilds","# Killed",
               "Avg Tot XP","Avg Level");
            break;
         case(1) :
            ret += sprintf("\n%-35s\n","Groups");
            break;
         case(2) :
            ret += sprintf("\n%-35s\n","Race Groups");
            break;
      }
      orgs = keys(tmp[3+i]);
      for(j=0; j<sizeof(orgs); j++)
      {
         org = tmp[3+i][orgs[j]];
         if(!i)
         {
            totk += org[0];
             totxp += org[0] * org[1];
             totl += org[0] * org[2];
         }
         ret += sprintf("%-35O%10d%10d%9d\n",orgs[j],org[0],org[1],org[2]);
      }
   } 
   if(totk)
      ret += "\nTOTAL PKed: "+totk+"\nAVG TOTAL XP of Vics: "+(totxp/totk);
   if(totk)
      ret += ", AVG LEVEL of Vics: "+(totl/totk)+"\n";
   this_player()->more_string(ret);
   return;
}


int total_pk_no(string name)
{
 mapping guild_data;
 string *gnames;
 int i, total;
 

 if(!killer_data[name]) return 0;
 total = 0;
 guild_data = killer_data[name][3];
 gnames = keys(guild_data);
 for(i=0;i<sizeof(gnames);i++)
   {
     total += guild_data[gnames[i]][0];
   }
 return total;
}

int avg_pk_level(string name)
{
 mapping guild_data;
 string *gnames;
 int i, levels, people;

 if(!killer_data[name]) return 0;
 guild_data = killer_data[name][3];
 gnames = keys(guild_data);
 for(i=0;i<sizeof(gnames);i++)
  {
    people += guild_data[gnames[i]][0];
    levels += (guild_data[gnames[i]][0] * guild_data[gnames[i]][2]);
  }
  return (levels / people);
}

int last_pk(string name)
{
 if(killer_data[name])
   return killer_data[name][1];
 return 0;
}
