// Ok, los dioses son dioses y tal, y deberian ser los unicos
// HIGHLords. Si un no-dios es declarado HIGHLord habra sitios
// donde no tenga derechos, de forma q debe ser un LORD.
// En algunos sitios se hace distincion entre HighProgrammer y
// Lord. El Lord se supone que puede administrar tambien (bans, etc)
#define ROOT "Root"
#define BACKBONE "Root"

#include "/include/log.h"
#define HIGHLords ([ROOT:1, "Tyrael":1, "Barthleby":1, "Jade":1, "Vilat":1, "Leviathan":1, "Kivara":1 ])

#ifdef VERSION
#define version() VERSION
#endif

#define READ_MASK 1
#define WRITE_MASK 2
#define GRANT_MASK 4

#define LORD 1
#define HIGH_LORD 2

string  *preload;
string  *call_out_preload;
mapping  positions;
mapping  permissions;
nosave mapping HighLords;
nosave   int done;
nosave mapping checked_master;
nosave mapping snoop_list;

void create() {
  permissions = ([ ]);
  positions   = ([ ]);
  checked_master = ([ ]);
  snoop_list = ([ ]);
  HighLords = HIGHLords;
  call_out("load_object", 0);
} /* create() */

/* This frees some memory.
 * Baldrick aug '94
 * Taniwha, moved it to /w/common
 */

/*
 * This function is called every time a player connects.
 * input_to() can't be called from here.
 */
object connect( int cPort ) 
  {
  object ob;
  if (!find_object("/secure/login")) {
      log_file("REBOOT", "Mud rebooted at "+ctime(time())+"["+time()+"]"+"\n");
  }
 /*
  printf("LPmud version: "+version()+".\nMudlib version: " 
         + "Fuckin' Fic - Dvelopin'" + "\n");
 */

// FFICMUD ahora es NINETEARS / Driade

	printf("Ninetears - Dvelopin'\n");

  if (cPort==4000) 
    ob = clone_object("/secure/login_new");
   else
    ob = clone_object("/secure/login");
  printf("\n");
  return ob;
} /* connet() */

int high_programmer(string str) {
  if (str == ROOT) return 1;
/*   if (str == "tyrael") return 1;
   if (str == "barthleby") return 1;
   if(str == "Tyrael") return 1;
  if(str == "Barthleby") return 1;*/
// parece ser q aki dicen q un HighProgrammer <==> HighLord. -> NO
// lo q si es verdad es q un HighLord es un (==>) HighProgrammer
  return ((positions[CAP(str)] == HIGH_LORD) || (HighLords[CAP(str)]));
} /* high_programmer() */

int query_lord(string str) {
  return positions[str] == LORD || high_programmer(str);
} /* query_lord() */

int query_only_lord(string str) {
  return positions[str] == LORD;
} /* query_only_lord() */

string *query_lords() {
  return filter_array(keys(positions), "query_only_lord", this_object());
} /* query_lords() */

// psche, aki mestan haciendo un (<==>) pero en fin...
int query_player_high_lord(string str) {
  return high_programmer(str) && "/secure/login"->test_user(str);
} /* query_player_high_lord() */

string *high_programmers() {
  return filter_array(keys(positions), "query_player_high_lord", this_object())+
         keys(HIGHLords);
} /* high_programmers() */

int check_permission(string euid, string *path, int mask);

int valid_load(string path, mixed euid, string func) {return 1;}

string get_root_uid() { return ROOT; }
string get_bb_uid() { return BACKBONE; }

string *define_include_dirs() {
  return ({ "/include/%s" });
} /* define_include_dirs() */

int valid_trace() { return 1; }

void shut(int min) {
  "/obj/shut"->shut(min);
} /* shut() */

void remove_checked_master(string name) {
  map_delete(checked_master, name);
} /* remove_checked_master() */

// Wonderflug 96, Secure this baby.
mapping query_checked_master() { return checked_master + ([ ]); }

/* Allow masters to be unchecked */
void uncheck_master(string str) {
  if(!this_player() || !high_programmer(geteuid(this_player(1)))) return;
  map_delete(checked_master, str);
}

#include "/secure/master/permission.c"
#include "/secure/master/crash.c"
// ??
void trace();
#include "/secure/master/create_dom_creator.c"
#include "/secure/master/creator_file.c"
#include "/secure/master/create_me.c"
#include "/secure/master/dest_env.c"
#include "/secure/master/ed_stuff.c"
#include "/secure/master/logging.c"
#include "/secure/master/retire.c"
#include "/secure/master/parse_command.c"
#include "/secure/master/preload.c"
#include "/secure/master/query_pl_level.c"
#include "/secure/master/simul_efun.c"
#include "/secure/master/snoop.c"
#include "/secure/master/valid_exec.c"
#include "/secure/master/valid_hide.c"
#include "/secure/master/valid_ident.c"
#include "/secure/master/valid_link.c"
#include "/secure/master/valid_override.c"
#include "/secure/master/valid_read.c"
#include "/secure/master/valid_seteuid.c"
#include "/secure/master/valid_shadow.c"
#include "/secure/master/valid_socket.c"
#include "/secure/master/valid_write.c"
#include "/secure/master/adjust_xp.c"
#include "/secure/master/virtual_objects.c"
#include "/secure/master/valid_save_binary.c"
