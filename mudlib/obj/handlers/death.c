// NPC statistic tracker for FR-Mud
// Radix - April 6, 1996
// Version 1.7

#include "timestuff.h"
#include "XP_adjust.h"
/* The data mappings...
  ([ "directory of death room" :
     ([ "filename" : ({  
                       kills, 
                       levels killed, 
                       total xp killed/100, 
                       last kill, 
                       time averaged,
                       killed, 
                       level killed by, 
                       total xp killed/100 by, 
                       xp awarded
                       lasted killed, 
                       time averaged,
                       kill xp
      }) ])
  ])
*/

inherit "/std/object.c";

#define SAVE "/save/"
#define PKHAND "/obj/handlers/pk"

mapping data;
int totaldif,diftimes;

void reset_screw_rate() {
  totaldif = 0;
  diftimes = 0;
}

int query_screw_rate() {
  int num = diftimes;
  int dif = totaldif;
  write(num+"\n");
  if(num > 20000) reset_screw_rate();
  if(num <= 0) return 1; // Taniwha
  return dif/num;
}

int query_number_screwed() { return diftimes; }

mapping query_data() { return data; }

void load_this_ob() {
   if(!m_sizeof(data))
     restore_object(SAVE+"death");
}

void save_this_ob() {
  if(m_sizeof(data)) 
    save_object(SAVE+"death",1);
}

create()
{
   ::create();
   data = ([ ]);
   load_this_ob();
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

string environment_path(object obj)
{
  string fname = file_name(environment(obj));
  string *dom = explode(fname,"/");
  dom -= ({ dom[sizeof(dom)-1] });
  return implode(dom,"/");
}

mapping query_npcstats() {
  load_this_ob();
  return data;
}

mapping query_domain_npcstats( string dom ) { 
  load_this_ob();
  if(data[dom]) return data[dom];
  return 0;
}

mixed *query_npc_stat( string dom, string pathname ) {
  load_this_ob();
  if(data[dom]) {
    if(data[dom][pathname]) return data[dom][pathname];
  }
  return 0;
}

void full_path_report(string dom) {
  int i,j;
  string outgoing;
  string *indic;
  load_this_ob();
  outgoing = "\nfilename kills lvkls xpkls lakil tiavg killd lvkby "
      "xpkb xpaw lakld tiavg kxp\n";
  outgoing += "(XP in units of 100, time in player minutes)\n\n";
  if(data[dom]) {
    indic = m_indices(data[dom]);
    for(i=0;i<m_sizeof(data[dom]);i++) {
      outgoing += crop_string(indic[i],10)+" ";
      for(j=0;j<sizeof(data[dom][indic[i]]);j++) {
        outgoing += data[dom][indic[i]][j]+" ";
      }
      outgoing += "\n";
    }
    outgoing += "\n";
    this_player()->more_string(outgoing);
  }
}

void killed_awarded_ratio(string dom) {
  int i,j;
  int killed,kt,awarded,at;
  float ratio;
  string outgoing;
  string *indic;
  load_this_ob();
  outgoing = "\nEnd of filename     player xp killed / xp awarded \n";
   outgoing += "(player xp in units of 100)\n\n";
  if(data[dom]) {
    indic = m_indices(data[dom]);
    for(i=0;i<m_sizeof(data[dom]);i++) {
      killed = data[dom][indic[i]][2];
      awarded = data[dom][indic[i]][8];
      kt+=killed;
      at+=awarded;
      outgoing += crop_string(indic[i],30)+" ";
     if(awarded)
      outgoing += (killed+0.0)/(awarded+0.0)+"\n";
     else
      outgoing += killed+" killed, never been killed.\n";
    }
    outgoing += "\nTOTAL "+(kt+0.0)/(at+0.0)+"\n\n";
    this_player()->more_string(outgoing);
  }
}

void full_domain_kar(string realdom) {
  int i,j;
  int killed,kt,awarded,at;
  int tim, timt, timtt, time_now;
  int ktt,att;
  float ratio;
  string dom, outgoing;
  string *indic;
  string *ind;
  string *tmp;
  load_this_ob();
  time_now = TIMEKEEPER->query_running_time()/60.0;
  outgoing = "\nDirectory      pc xp killed/xp award    awarded rate\n";
  outgoing += "(player xp in units of 100, time in player hours)\n\n";
  if(!mappingp(data)) data = ([ ]); // Taniwha
  ind = m_indices(data);
  for(i=0;i<sizeof(ind);i++) {
    tmp = explode(ind[i],"/");
    if(sizeof(tmp) < 2) continue;
    if(tmp[1] == realdom) {
      dom = ind[i];
      indic = m_indices(data[dom]);
          if(!m_sizeof(data[dom])) {
            data = m_delete(data,data[dom]);
            continue;
          }
      for(j=0;j<m_sizeof(data[dom]);j++) {
        killed = data[dom][indic[j]][2];
        awarded = data[dom][indic[j]][8];
        if(((time_now - data[dom][indic[j]][3]) > BASE_WEEK/30.0
          && (time_now - data[dom][indic[j]][9]) > BASE_WEEK/30.0)
          || (time_now - data[dom][indic[j]][3]) < 0.0
          || (time_now - data[dom][indic[j]][9]) < 0.0)
        {
          data[dom] = m_delete(data[dom],indic[j]);
          continue;
        }
        tim = data[dom][indic[j]][10];
        if(tim > timt) timt = tim;
        kt+=killed;
        at+=awarded;
      }
      if(dom)
         dom = dom[strlen(realdom)+3..1000]+"/";
      if(at)
         outgoing += sprintf("%-35s %15.4f ", dom, ((kt+0.0) / (at+0.0)));
      else
         outgoing += sprintf("%-35s %15.4f ", dom, 0.0);
      if(timt)
         outgoing += sprintf("%15.4f\n", ((at+0.0) * 60.0) / (timt+0.0));
      else
      outgoing += sprintf("%15.4f\n", 0.0);
      ktt += kt;
      att += at;
      if(timt > timtt) timtt = timt;
      at = 0;
      kt = 0;
      timt = 0;
    }
  }
  if(att)
  outgoing += "\nTOTAL  "+(ktt+0.0)/(att+0.0)+" ";
  if(timtt) outgoing += (att+0.0)*60.0/(timtt+0.0)+"\n";
  else outgoing += " NKTT";
  this_player()->more_string(outgoing);
}

void original_radix_data(string dom) {
  int i,j;
  int died,dt,kills,kt,timd,tmdt,timk,tmkt,levd,ldt,levk,lkt,xpd,
      xdt,xpk,xkt,awded,awdt;
  float ratio;
  string outgoing;
  string *indic;
  load_this_ob();
  outgoing = "\nfilename  freqdied freqkills avglevd avglevk avgxpd"
      " avgxpk rateawarded\n";
  outgoing += "(player xp in units of 100, time in player hours)\n\n";
  if(data[dom]) {
    indic = m_indices(data[dom]);
    for(i=0;i<m_sizeof(data[dom]);i++) {
      died = data[dom][indic[i]][5];
      dt += died;
      kills = data[dom][indic[i]][0];
      kt += kills;
      timd = data[dom][indic[i]][10];
      if(timd > tmdt) tmdt = timd;
      timk = data[dom][indic[i]][4];
      if(timk > tmkt) tmkt = timk;
      levd = data[dom][indic[i]][6];
      ldt += levd;
      levk = data[dom][indic[i]][1];
      lkt += levk;
      xpd = data[dom][indic[i]][7];
      xdt += xpd;
      xpk = data[dom][indic[i]][2];
      xkt += xpk;
      awded = data[dom][indic[i]][8];
      awdt += awded;
      outgoing += crop_string(indic[i],20);
      if(timd) outgoing += " "+(died+0.0)*60.0/(timd+0.0);
      else outgoing += " NTD";
      if(timk) outgoing += " "+(kills+0.0)*60.0/(timk+0.0);
      else outgoing += " NTK";
      if(died) outgoing += " "+(levd+0.0)/(died+0.0);
      else outgoing += " ND";
      if(kills) outgoing += " "+(levk+0.0)/(kills+0.0);
      else outgoing += " NK";
      if(died) outgoing += " "+(xpd+0.0)/(died+0.0);
      else outgoing += " ND";
      if(kills) outgoing += " "+(xpk+0.0)/(kills+0.0);
      else outgoing += " NK";
      if(timd) outgoing += " "+(awded+0.0)*60.0/(timd+0.0);
      else outgoing += " NTD";
      outgoing += "\n";
    }
    outgoing += "\nTOTAL";
      if(tmdt) outgoing += " "+(dt+0.0)*60.0/(tmdt+0.0);
      else outgoing += " NTD";
      if(tmkt) outgoing += " "+(kt+0.0)*60.0/(tmkt+0.0);
      else outgoing += " NTK";
      if(dt) outgoing += " "+(ldt+0.0)/(dt+0.0);
      else outgoing += " ND";
      if(kt) outgoing += " "+(lkt+0.0)/(kt+0.0);
      else outgoing += " NK";
      if(dt) outgoing += " "+(xdt+0.0)/(dt+0.0);
      else outgoing += " ND";
      if(kt) outgoing += " "+(xkt+0.0)/(kt+0.0);
      else outgoing += " NK";
      if(tmdt) outgoing += " "+(awdt+0.0)*60.0/(tmdt+0.0);
      else outgoing += " NTD";
    outgoing += "\n\n";
    this_player()->more_string(outgoing);
  }
}

float get_real_rate(mixed vals, object npc)
{
   float rateret;
   if(sizeof(vals) < 12)
      return -1;
   if(vals[5] && vals[6] / vals[5] < 4) return -1;
   if(vals[10] < BASE_WEEK/60 && vals[7] < 1000000000) return -1;
   if (!vals[8]) {
     if (vals[2]) return MAX_XP_BON;
     else return -1;
   }
   rateret = (vals[2]+0.0)/(vals[8]+0.0)/BASE_KAR;
   if(rateret*vals[11] > npc->query_level()*60*MAX_XP_BON)
     rateret = MAX_XP_BON*(npc->query_level()+0.0)*60.0/(vals[11]+0.0);
   if(rateret*vals[11] < npc->query_level()*60*MAX_XP_PEN)
   {
     rateret = MAX_XP_PEN*(npc->query_level()+0.0)*60.0/(vals[11]+0.0);
     if(rateret > 1.0) rateret = 1.0;
   }
   return rateret;
}

float update_npc_died(object npc, object player)
{
   mixed vals;
   mapping tmp;
   string domname, obname;
   int i, temp;
   int time_now, time_since, total_time, time_extra;
   float rateret;

   if(!(obname = real_filename(npc))) 
      return 1;
   if(!(domname = environment_path(npc)))
      return 1;
   load_this_ob();
   tmp = data[domname];
   if(!tmp) 
      tmp = ([ ]);
   vals = tmp[obname];
   if(!vals) vals = ({0,0,0,0,0,0,0,0,0,0,0,0});
   
   if(!(player->query_creator()) && 
     strsrch(player->query_name(),"test") == -1) {
   time_now = TIMEKEEPER->query_running_time()/60.0;
   if(!vals[9]) vals[9] = time_now;
   time_since = time_now - vals[9];
  if(time_since < 0) time_since = 0;
   if(time_since > BASE_WEEK/30.0) {
     vals[5]=0;
     vals[6]=0;
     vals[7]=0;
     vals[8]=0;
     vals[9]=time_now;
     vals[10]=time_since;
   }
   else {
     total_time = vals[10]+time_since;
     if(total_time > BASE_WEEK/30.0) {
       time_extra = total_time - BASE_WEEK/30.0;
       temp = vals[5]*((vals[10]-time_extra)*10.0/vals[10])/10;
       vals[5] = temp;
       temp = vals[6]*((vals[10]-time_extra)*10.0/vals[10])/10;
       vals[6] = temp;
       temp = vals[7]*((vals[10]-time_extra)*10.0/vals[10])/10;
       vals[7] = temp;
       temp = vals[8]*((vals[10]-time_extra)*10.0/vals[10])/10;
       vals[8] = temp;
       temp = BASE_WEEK/30.0;
       vals[10] = temp;
     }
     else vals[10] = total_time;
     vals[9] = time_now;
   }
   
   if(vals[10] < 0) vals[10] = BASE_WEEK/30;
   vals[5] += 1;
   vals[6] += player->query_level();
   vals[7] += player->query_total_xp()/100;
   vals[11] = npc->query_kill_xp();
   vals[8] += vals[11];
     if(vals[7] > 2000000000) {
       temp=vals[5]*2000000000.0/vals[7];
       vals[5]=temp;
       temp=vals[6]*2000000000.0/vals[7];
       vals[6] = temp;
       temp=vals[8]*2000000000.0/vals[7];
       vals[8] = temp;
       temp=vals[10]*2000000000.0/vals[7];;
       vals[10] = temp;
       vals[7]=2000000000;
     }

   tmp[obname] = vals;
   data[domname] = tmp;
   save_this_ob();
   }

   // Made seperate function for other purposes - Radix
  rateret = get_real_rate(vals, npc);
  if(rateret == -1)
     return 1.0;

   if(!(player->query_creator()) &&
     strsrch(player->query_name(),"test") == -1) {
   totaldif += rateret*vals[11]-(npc->query_level()*60);
   diftimes += 1;
  }
   if(rateret) return rateret;
   return 1.0;
}

// Called from /global/creator/cmds/info.c
void info_npc(object npc)
{
   mixed vals;
   mapping tmp;
   float rateret;
   string domname, obname;
   
   if(!(obname = real_filename(npc)) || !(domname = environment_path(npc)))
   {
      write("Invalid NPC object filename or environment path.\n");
      return 0;
   }
   tmp = data[domname];
   if(!tmp)
   {
      write("No data for NPC in this environment.\n");
      return 0;
   }
   vals = tmp[obname];
   rateret = get_real_rate(vals, npc);
   if(rateret == -1)
      rateret = 1.0;
   write("Info Data for NPC: "+npc->query_short()+"\n");
   write("Filename: "+obname+"\n");
   write("Environment: "+domname+"\n");
   write("----------------------------------------\n");
   write("Kill xp: "+npc->query_kill_xp()+"\n");
   write("Rate Return: "+rateret+"\n");
   write("Total: "+npc->query_kill_xp() * rateret+"\n");
   return;
}
void update_player_died(object npc, object player)
{
   mixed vals;
   mapping tmp;
   string domname, obname;
   int i, temp;
   int time_now, time_since, total_time, time_extra;

   if(player->query_creator() || 
     strsrch(player->query_name(),"test") != -1) return;
   if(!(obname = real_filename(npc))) 
      return;
  if(!(domname = environment_path(npc)))
    return;
   load_this_ob();
   tmp = data[domname];
   if(!tmp) 
      tmp = ([ ]);
   vals = tmp[obname];
   if(!vals) vals = ({0,0,0,0,0,0,0,0,0,0,0,0});
   
   time_now = TIMEKEEPER->query_running_time()/60.0;
   if(!vals[3]) vals[3] = time_now;
   time_since = time_now - vals[3];
   if(time_since < 0) time_since = 0;
   if(time_since > BASE_WEEK/30.0) {
     vals[0]=0;
     vals[1]=0;
     vals[2]=0;
     vals[3]=time_now;
     vals[4]=time_since;
   }
   else {
     total_time = vals[4]+time_since;
     if(total_time > BASE_WEEK/30.0) {
       time_extra = total_time - BASE_WEEK/30.0;
       temp = vals[0]*((vals[4]-time_extra)*10.0/vals[4])/10;
       vals[0] = temp;
       temp = vals[1]*((vals[4]-time_extra)*10.0/vals[4])/10;
       vals[1] = temp;
       temp = vals[2]*((vals[4]-time_extra)*10.0/vals[4])/10;
       vals[2] = temp;
       temp = BASE_WEEK/30.0;
       vals[4] = temp;
     }
     else vals[4] = total_time;
     vals[3] = time_now;
   }
   
   if(vals[4] < 0) vals[4] = BASE_WEEK/30;
   vals[0] += 1;
   vals[1] += player->query_level();
   vals[2] += player->query_total_xp()/100;
   vals[11] = npc->query_kill_xp();
   
   tmp[obname] = vals;
   data[domname] = tmp;
   save_this_ob();
   return;

}

void domain_death(object victim, object enemy)
{
   string *path = explode(file_name(environment(victim)),"/");
   mixed mas;
   if(sizeof(path) < 2 || (path[0] != "d" && path[0] != "w"))
      return;
   mas = "/"+path[0]+"/"+path[1]+"/master";
   catch(mas->domain_death(victim, enemy));
}

void mud_death(object victim, object enemy)
{
   string *path = explode(file_name(environment(victim)),"/");
   mixed mas;
   string *doms = get_dir("/d/");
   int i;
   for(i=0; i<sizeof(doms); i++)
   {
      mas = "/d/"+doms[i]+"/master";
      catch(mas->mud_death(victim, enemy));
   }
   return;
}

float update_statistics(object victim, object enemy)
{
   string create_name;
   if(enemy && victim)
   {
      if(environment(enemy) && environment(victim))
      {
         domain_death(victim, enemy);
         mud_death(victim, enemy);
      }
      if(interactive(victim) && enemy->query_npc()) {
         update_player_died(enemy, victim);
         return 1;
      }
      create_name = victim->query_create_me();
      if(victim->query_npc() && interactive(enemy)) {
         if(!enemy->query_creator())
            if(create_name != "Object" && create_name != "Root")
               log_file("CREATE_ME",real_filename(victim)+
                  " ["+victim->query_create_me()+"] killed by "+
                  enemy->query_cap_name()+" for "+
                  victim->query_kill_xp()+" :"+ctime(time())+"\n");
         return update_npc_died(victim, enemy);
      }
      // PKing...
      if(interactive(victim) && interactive(enemy))
         catch(PKHAND->update_player_killed(victim, enemy));
  }
  return 1;
}
