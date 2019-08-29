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

// Traduccion - Leviathan - Mar'02
// Log de clonadas - Leviathan & Tyrael - Mar'02
// Nueva funcionalidad de Bans/Unbans, niveles de acceso,
// saqueos, interfaz para designar Admins, persistencia,
// rotacion de logs, control de gremios, clanes y casas, depositar,
// recuperar y saquear definible por el usuario (la vaultroom concreta)
// y nueva cara en general :P - Tyrael - May'02

// NOTA: Probablemente exista una mejor manera de hacer uso de save_object()
// ya que aqui se ejecuta (por mi seguridad :P) tras modificar las variables
// y tambien al setearlas, cosa que no creo que sea muy decente :). - Tyrael.

// HEREDANDO: Al hacer un baul la primera linea del setup de la room debe
// ser ::setup() o vault_room::setup(), si no no se leeran los permisos y demas

inherit "/std/room";
#include "path.h"
#include "login_handler.h"
#define FILE_SIZE 30000    // change, you die - lease, si lo cambias, mueres :)
#define MAX_LOG_SIZE	10000

#define BAUL_SAQ_LOCK		300	// hearts reales sin poder volver a ser sakeado
#define BAUL_SAQ_PJ_LOCK	400	// hearts de juego sin poder volver a sakear este baul
 
string save_file = file_name(this_object())+"_save";
string vault_log = file_name(this_object())+"_log";
string vault_perms = file_name(TO)+"_perms";
string vault_saqs = file_name(TO)+"_saqs";
string *vault_admin = ({ });
string *guild_owner = ({ });
string *group_owner = ({ }); // nuevo para control de CLANES
string *race_group_owner = ({ }); // nuevo para control de CASAS (Y DEMAS RACE_GROUPS)
string depositar_fn = 0;	// FUNCION QUE DETERMINA SI SE PUEDE O NO DEPOSITAR
string recuperar_fn = 0;	// FUNCION QUE DETERMINA SI SE PUEDE O NO RECUPERAR
string saquear_fn = 0;	// FUNCION QUE DETERMINA SI SE PUEDE O NO SAQUEAR

string allow_fn = 0;	// FN PARA DETERMINAR SI UN OBJ ES ADMITIDO NEL BAUL

mixed razones = ([ ]);

int nivel = 0;
int saqueable = 0;
int allow_all = 0;	// permite TODO tipo de objetos *a menos* que allow_fn defina otra cosa

int max_saqs = 0;	// maximo numero de saqueos de un tiron
int max_pj_saqs = 0;	// maximo numero de saqueos por pj de un tiron (ALWAYS <= max_saqs)


void set_save_file(string file) { if(file) save_file = file; }
string query_save_file() { return(save_file); }

void set_vault_log(string file) { if(file) vault_log = file; }
string query_vault_log() { return(vault_log); }

void set_vault_perms(string file) { if(file) vault_perms = file; }
string query_vault_perms() { return(vault_perms); }

void set_vault_saqs(string file) { if(file) vault_saqs = file; }
string query_vault_saqs() { return(vault_saqs); }

/* FUNCION EN DESUSO! NO USAR! USAR INTERFAZ INTERACTIVA! ESTO LA SOBRESCRIBIRIA!
void set_admins(string *admin) { if(sizeof(admin)) { vault_admin = admin; save_object(vault_perms); } }
*/
string *query_vault_admins() { return vault_admin; }

// ATENCION: aki se llama a guild_name() Y SIEMPRE ESTARA EN MINUSCULAS -el gremio k no te asi cambiadlo-
void set_guild_owner(string *gown)
{
	if(sizeof(gown)) {
		guild_owner = gown;
		save_object(vault_perms);
	}
}

// PARA CLANES Y CASAS, el name() dewelve el NOMBRE TAL COMO VIENE, QUE SUELE SER CON ALGUNAS MAYUS!
void set_group_owner(string *gown) 
{
	if (sizeof(gown)) { 
		group_owner = gown;
		save_object(vault_perms);
	}
}

void set_race_group_owner(string *gown)
{
	if (sizeof(gown)) {
		race_group_owner = gown;
		save_object(vault_perms);
	}
}

// EL PROTO DE ESTAS FNS ES: int fn_depositar_recuperar_o_saqueo_baul(object miplayer, string str);

// FUNCIONES QUE DEVOLVERAN 1 SI SE PERMITE DEPOSITAR / RECUPERAR - UTILIDAD PARA LORDS DE CASAS
void set_depositar_fn(string dep_fn) { depositar_fn = dep_fn; save_object(vault_perms); }
void set_recuperar_fn(string rec_fn) { recuperar_fn = rec_fn; save_object(vault_perms); }
// LO MISMO SI SE PERMITE SAQUEAR
void set_saquear_fn(string saq_fn) { saquear_fn = saq_fn; save_object(vault_perms); }

// EL PROTO DE ESTA FN ES: int fn_allow_obj(object miplayer, object objeto);
void set_allow_fn(string all_fn) { allow_fn = all_fn; save_object(vault_perms); }

string *query_guild_owner() { return guild_owner; }
string *query_group_owner() { return group_owner; }
string *query_race_group_owner() { return race_group_owner; }

void set_saqueable(int saq) {
	saqueable = saq;
	if (saq) {
		if (!max_saqs)
			max_saqs = 2;
		if (!max_pj_saqs)
			max_pj_saqs = 2;
	}
	save_object(vault_perms);
}

int query_saqueable() { return saqueable; }

void set_allow_all(int allow) { allow_all = allow; save_object(vault_perms); }
int query_allow_all() { return allow_all; }

void set_max_saqs(int n) {
	if (!saqueable)
		saqueable = 1;
	max_saqs = n;
	save_object(vault_perms);
}

void set_max_pj_saqs(int n) {
	if (!saqueable)
		saqueable = 1;
	max_pj_saqs = n;	// DEBE SER SIEMPRE <= QUE max_saqs
	save_object(vault_perms);
}

int query_max_saqs() { return max_saqs; }
int query_max_pj_saqs() { return max_pj_saqs; }


void create()
{
   ::create();
   add_sign("Esta pegado a la pared y esta escrito con letras hechas en oro.\n",
	"\n\tM O D O   D E   E M P L E O   D E L   B A U L\n\n"
	"Comandos %^BOLD%^generales%^RESET%^:\n\n"
	"Escribe \"%^MAGENTA%^listar%^RESET%^\" obtener un listado de objetos en el baul.\n"
	"Escribe \"%^MAGENTA%^admins%^RESET%^\" para obtener la lista de administradores del baul.\n\n"
	"Comandos para %^BOLD%^miembros%^RESET%^:\n\n"
	"Escribe \"%^MAGENTA%^nivel%^RESET%^\" para ver el nivel minimo para poder recuperar objetos del baul.\n"
	"Escribe \"%^MAGENTA%^depositar %^CYAN%^<objeto>%^RESET%^\" para depositar un objeto en el baul.\n"
	"Escribe \"%^MAGENTA%^recuperar %^CYAN%^<objeto>%^RESET%^\" para recuperar un objeto del baul.\n\n"
	"Comandos para %^BOLD%^%^RED%^intrusos%^RESET%^:\n\n"
	"Escribe \"%^RED%^saquear%^RESET%^\" para saquear este baul.\n\n"
	"Comandos para %^BOLD%^administradores%^RESET%^:\n\n"
	"Escribe \"%^ORANGE%^logs%^RESET%^\" para ver el registro de operaciones del baul.\n"
	"Escribe \"%^ORANGE%^establecer %^CYAN%^<nivel>%^RESET%^\" para exigir un nivel minimo de acceso al baul.\n"
	"Escribe \"%^ORANGE%^banear %^CYAN%^<persona> <razon>%^RESET%^\" para impedirle recuperar objetos.\n"
	"Escribe \"%^ORANGE%^desbanear %^CYAN%^<persona>%^RESET%^\" para volver a permitirle recuperar objetos.\n"
	"Escribe \"%^ORANGE%^bans%^RESET%^\" para obtener la lista de personas baneadas.\n\n"
	"Comandos para %^BOLD%^CYAN%^inmortales%^RESET%^:\n\n"
	"Escribe \"%^GREEN%^anyadir %^CYAN%^<persona>%^RESET%^\" para anyadir un nuevo administrador.\n"
	"Escribe \"%^GREEN%^quitar %^CYAN%^<persona>%^RESET%^\" para eliminar un administrador.\n"
	"Escribe \"%^GREEN%^saqueos%^RESET%^\" para ver el log de saqueos del baul.\n"
	"Escribe \"%^GREEN%^limpiar%^RESET%^\" para forzar a rotar los logs.\n");
}

void setup()
{
   set_light(80);
   set_short("El Baul");
   set_long("Estas en una habitacion con un baul. Un gran baul de plata ha sido encajado en los "
      "cimientos de las paredes para servir a sus duenyos de forma segura.\n\n");
	restore_object(vault_perms);
}
 
void init() {
	::init();
	add_action("do_deposit","depositar");
	add_action("do_retrieve","recuperar");
	add_action("do_list","listar");
	add_action("view_vault_log","logs");
	add_action("do_nivel", "nivel");
	add_action("do_establecer", "establecer");
	add_action("do_banear", "banear");
	add_action("do_desbanear", "desbanear");
	add_action("do_bans", "bans");
	add_action("do_saquear", "saquear");
	add_action("do_anyadir", "anyadir");
	add_action("do_quitar", "quitar");
	add_action("do_admins", "admins");
	add_action("do_saqueos", "saqueos");
	add_action("do_limpiar", "limpiar");
}

/* EL EFECTO DE ESTO ES SOBRESCRIBIR EL ARCHIVO DE PERMISOS! NO USAR!
void reset()
{
	save_object(vault_perms);
	::reset();
}*/

int do_saqueos(string str) {
	string tmp;

	if (!TP->query_creator()) {
			notify_fail("No tienes acceso a esta informacion.\n");
			return 0;
	}
	if (file_exists(vault_saqs+".old")) {
   	tell_object(TP, "%^BOLD%^Log %^RESET%^de saqueos %^BOLD%^RED%^antiguo%^RESET%^:\n\n");
      tmp = read_file(vault_saqs+".old");
      	TP->more_string(tmp);
	}
	else {
		write_file(vault_saqs+".old", "Nuevo log en "+ctime(time())+".\n");
		tell_object(TP, "No existe log antiguo. Se ha creado uno nuevo.\n");
	}
	if (file_exists(vault_saqs)) {
      	tell_object(TP, "\n\n%^BOLD%^Log %^RESET%^de saqueos %^BOLD%^GREEN%^nuevo%^RESET%^:\n\n");
      tmp = read_file(vault_saqs);
      TP->more_string(tmp);
	}
	else {
		write_file(vault_saqs, "Nuevo log en "+ctime(time())+".\n");
		notify_fail("No existe log de saqueos. Se ha creado uno nuevo.\n");
		return 0;
	}
	return 1;
}

int do_quitar(string str);

int miembro_array(mixed uno, mixed *arr) {
	int i, j;

	if (!(j = sizeof(arr)))
		return (-1);
	for (i = 0; i < j; i++)
		//tell_object(TP, "arr "+i+" = "+arr[i]+ " uno = "+uno+"\n");
		if (uno == arr[i])
			return 0;
	return (-1);
}

int no_me_mola(object ob)
{
	// por alguna extranya razon member_array() dice que espera en el primer parametro un int
	if (!ob)
		return 1;
	if (sizeof(guild_owner)) {
		if (!ob->query_guild_ob())
			return 1;
		if (miembro_array(ob->query_guild_name(), guild_owner) == -1) {
			//tell_object(ob, "No eres miembro del array\n");
			return 1;
		}
	}
	if (sizeof(group_owner)) {
		if (!ob->query_group_ob())
			return 1;
		if (miembro_array(ob->query_group_name(), group_owner) == -1)
			return 1;
	}
	if (sizeof(race_group_owner)) {
		if (!ob->query_race_group_ob())
			return 1;
		if (miembro_array(ob->query_race_group_name(), race_group_owner) == -1)
			return 1;
	}
	return 0;
}

int do_bans(string str) {
	string *frog;
	int i;

	if ((i = member_array(TP->QCN, vault_admin)) == -1 && !TP->query_creator()) {
		notify_fail("No tienes acceso a la lista de baneados.\n");
		return 0;
	}
	if (no_me_mola(TP) && !TP->query_creator()) {	// admin MAL PUESTO
		// caso de admin que no debe tener acceso al baul
		vault_admin -= ({ vault_admin[i] });
		save_object(vault_perms);
		notify_fail("Que hacia alguien como tu de administrador de este baul?\n");
		return 0;
	}
	if (!m_sizeof(razones)) {
		tell_object(TP, "No hay ningun baneado.\n");
		return 1;
	}
	frog = m_indices(razones);
	tell_object(TP, "Lista de baneados:\n\n");
	printf("%#-*s\n",TP->query_cols(),implode(frog,"\n"));
	return 1;
}

void swap_logs(string fname)
{
	if (file_exists(fname)) {
		if (file_size(fname) > MAX_LOG_SIZE) {
			if (file_exists(fname+".old"))
				rm(fname+".old");
			rename(fname, fname+".old");
			write_file(fname, "Nuevo log en "+ctime(time())+"\n\n");
		}
	}
}

int do_limpiar(string str) {
	if (!TP->query_creator()) {
		tell_object(TP, "Limpias el baul con Scotch Brite. Ahora reluce impecablemente!\n");
		tell_room(TO, TP->QCN + " limpia emocionadamente el baul con su Scotch Brite. Ahora brilla impecablemente!\n", TP);
		notify_fail("");
		return 0;
	}
	tell_object("Logs rotados.\n");
	if (file_exists(vault_log+".old"))
		rm(vault_log+".old");
	if (file_exists(vault_log))
		rename(vault_log, vault_log+".old");
	write_file(vault_log, "Nuevo log en "+ctime(time())+"\n\n");

	if (file_exists(vault_saqs+".old"))
		rm(vault_saqs+".old");
	if (file_exists(vault_saqs))
		rename(vault_saqs, vault_saqs+".old");
	write_file(vault_saqs, "Nuevo log en "+ctime(time())+"\n\n");
	return 1;
}

int do_admins(string str) {
	int i, j;
	//object race_ob; tal vez esto se anyada mas tarde

	if (!(j = sizeof(vault_admin))) {
		tell_object(TP, "Este baul no tiene administradores, contacta con un inmortal.\n");
		return 1;
	}
	tell_object(TP, "Los administradores de este baul son:\n\n");
		for (i = 0; i < j; i++) {
			if (vault_admin[i] == "all")
				continue;
			//race_ob = 0;
			//restore_object("/players/"+vault_admin[i][0..0]+"/"+vault_admin[i],1);
			tell_object(TP, vault_admin[i]);
			//if (race_ob)
			//	tell_object(TP, ", "+CAP(race_ob->query_name()));
			tell_object(TP, "\n");
		}
	return 1;
}

int do_nivel(string str) {
	if (no_me_mola(TP) && !TP->query_creator()) {
		notify_fail("No tienes acceso a esa informacion.\n");
		return 0;
	}
	tell_object(TP, "El nivel minimo para poder recuperar objetos del baul es "+nivel+".\n");
	return 1;
}

int do_anyadir(string str)
{
	if (!TP->query_creator()) {
		notify_fail("Si, pero no, como el amor oral.\n");
		return 0;
	}
	if (!str) {
		notify_fail("Sintaxis: anyadir <persona>\n");
		return 0;
	}
	str = CAP(str);
	if (razones[str]) {
		notify_fail("Funcionara mejor si primero lo desbaneas.\n");
		return 0;
	}
	if (member_array(str, vault_admin) != -1) {
		tell_object(TP, str + " ya era administrador de este baul.\n");
		notify_fail("");
		return 0;
	}

	vault_admin += ({ str });
	save_object(vault_perms);
	tell_object(TP, str + " es un nuevo administrador de este baul.\n");
	return 1;
}

int do_quitar(string str)
{
	int i;

	if (!TP->query_creator()) {
		notify_fail("Si, pero no, como el amor oral.\n");
		return 0;
	}
	if (!str) {
		notify_fail("Sintaxis: quitar <persona>\n");
		return 0;
	}
	str = CAP(str);
	if ((i = member_array(str, vault_admin)) == -1) {
		tell_object(TP, str + " no es administrador de este baul.\n");
		notify_fail("");
		return 0;
	}

	vault_admin -= ({ vault_admin[i] });
	save_object(vault_perms);
	tell_object(TP, str + " ya no es administrador de este baul.\n");
	return 1;
}

int do_saquear(string str)
{
	int n;
	object vault = clone_object(STORAGE+"vault_obj.c");
	object *all;

	if (!no_me_mola(TP) && !TP->query_creator()) {
		vault->dest_me();
		notify_fail("Aja, intentando saquear tu propio baul!?!\n");
		return 0;
	}
	if (!saqueable) {
		vault->dest_me();
		notify_fail("No eres capaz de saquear el baul.\n");
		return 0;
	}
	if (saquear_fn) {
		if (!call_other(TO, saquear_fn, TP, str)) {
			vault->dest_me();
			notify_fail("Oops, no has podido saquear el baul.\n");
			return 0;
		}
	}
   if(query_property("vault_using"))
   {
      notify_fail("El baul esta siendo usado, prueba en unos momentos.\n");
      vault->dest_me();
      return 0;
   }

    if (TP->query_property(vault_saqs) >= max_pj_saqs) {
		vault->dest_me();
		notify_fail("Hace muy poco que saqueaste este baul, no deberias repetirlo tan a menudo.\n");
		return 0;
	}

    if (query_property("baul_saqueado") >= max_saqs) {
		vault->dest_me();
		notify_fail("Este baul ya ha sido saqueado hace poco, una magia divina te impide coger nada.\n");
		return 0;
    }

	vault->move(this_object());
	vault->set_save_file(save_file);
	all = all_inventory(vault);

	if(!(n = sizeof(all))) {
		vault->dest_me();
		notify_fail("Vaya, para una vez que puedes saquear un baul resulta que esta vacio.\n");
		return 0;
	}

	n = random(n);

    if(this_player()->query_loc_weight() + all[n]->query_weight() <
       this_player()->query_max_weight())
         {
            all[n]->move(this_player());
            say((string)this_player()->query_short()+" saquea el baul obteniendo "+
               all[n]->short()+".\n");
            write("Saqueas el baul y obtienes "+all[n]->short()+".\n");
            swap_logs(vault_log);
            write_file(vault_log,"Intruso %^BOLD%^BLACK%^S A Q U E O%^RESET%^:  "+all[n]->query_short()+" a las "+
               ctime(time())+"\n");
			swap_logs(vault_saqs);
			write_file(vault_saqs, TP->QCN + " %^BOLD%^%^BLACK%^saqueo%^RESET%^: "+all[n]->query_short()+" a las "+ctime(time())+".\n");
		}
	else {
           write("Eliges mal y no eres capaz de cargar con "+all[n]->short()+".\n");
            swap_logs(vault_saqs);
			write_file(vault_saqs, TP->QCN + " %^BOLD%^no pudo %^RESET%^con: "+all[n]->query_short()+" a las "+ctime(time())+".\n");
	}
      vault->dest_me();
		TP->add_timed_property(vault_saqs, TP->query_property(vault_saqs) + 1, BAUL_SAQ_PJ_LOCK);
		add_timed_property("baul_saqueado", query_property("baul_saqueado") + 1, BAUL_SAQ_LOCK);
		save_object(vault_perms);
      return 1;
}

int do_desbanear(string quien)
{
	//string quien;
	int i;

	if (((i = member_array(TP->QCN, vault_admin)) == -1) && !TP->query_creator()) {
		notify_fail("Tu mente lo desea, pero tu cuerpo no responde.\n");
		return 0;
	}
	if (no_me_mola(TP) && !TP->query_creator()) {	// admin MAL PUESTO
		// caso de admin que no debe tener acceso al baul
		vault_admin -= ({ vault_admin[i] });
		save_object(vault_perms);
		notify_fail("Que hacia alguien como tu de administrador de este baul?\n");
		return 0;
	}
	//if (!str || sscanf(str, "%s", quien) != 1) {
	if (!quien || !sizeof(quien)) {
		notify_fail("Sintaxis: desbanear <persona>\n");
		return 0;
	}

	quien = CAP(quien);

	if (!razones[quien]) {
		notify_fail("Esa persona no estaba baneada.\n");
		return 0;
	}

            swap_logs(vault_log);
      write_file(vault_log,this_player()->query_short()+
               " %^BOLD%^CYAN%^desbaneo%^RESET%^ a "+quien+" en "+
               ctime(time())+".\n");
	razones = m_delete(razones, quien);
	save_object(vault_perms);
	//razones[quien] = ({ });
	tell_object(TP, "Has desbaneado a "+quien+".\n");
	return 1;
}

int do_banear(string str)
{
	string quien;
	int i;

	if (((i = member_array(TP->QCN, vault_admin)) == -1) && !TP->query_creator()) {
		notify_fail("Te dispones a banear como un campeon, pero una voz en tu mente dice: No0oRL!\n");
		return 0;
	}
	if (no_me_mola(TP) && !TP->query_creator()) {	// admin MAL PUESTO
		// caso de admin que no debe tener acceso al baul
		vault_admin -= ({ vault_admin[i] });
		save_object(vault_perms);
		notify_fail("Que hacia alguien como tu de administrador de este baul?\n");
		return 0;
	}
	if (!str || sscanf(str, "%s %s", quien, str) != 2) {
		notify_fail("Sintaxis: banear <persona> <razon>\n"
				"Si la razon no se considera adecuada o si se abusa de este comando el ban se invertira.\n");
		return 0;
	}

	quien = CAP(quien);
	if ((i = member_array(quien, vault_admin)) != -1) {
		if (!TP->query_creator()) {
			notify_fail("Tan solo un inmortal puede banear a un administrador.\n");
			return 0;
		}
		vault_admin -= ({ vault_admin[i] });
		// vault_admin = delete(vault_admin, i, 1);
		tell_object(TP, "Administrador "+quien+" demoteado.\n");
	}
            swap_logs(vault_log);
      write_file(vault_log,this_player()->query_short()+
               " %^BOLD%^RED%^baneo%^RESET%^ a "+quien+" en "+
               ctime(time())+" porque: "+str+".\n");

	razones[quien] = str;
	save_object(vault_perms);
	tell_object(TP, "Has baneado a "+quien+".\n");
	// pensar en meter un event de info para inmortales aki.
	return 1;
}

int do_establecer(string str)
{
	int lvl, i;

	if (((i = member_array(TP->QCN, vault_admin)) == -1) && !TP->query_creator()) {
		notify_fail("Buen intento! Pero mejor seria que primero te las ingeniases para ser administrador de este baul.\n");
		return 0;
	}
	
	if (no_me_mola(TP) && !TP->query_creator()) {	// admin MAL PUESTO
		// caso de admin que no debe tener acceso al baul
		vault_admin -= ({ vault_admin[i] });
		save_object(vault_perms);
		notify_fail("Que hacia alguien como tu de administrador de este baul?\n");
		return 0;
	}
	
	if (!str || sscanf(str, "%d", lvl) != 1)
	{
		notify_fail("Sintaxis: establecer <nivel>\n");
		return 0;
	}

            swap_logs(vault_log);
	write_file(vault_log, TP->QCN+" %^BOLD%^establece %^RESET%^el nivel minimo en "+lvl+".\n");
	nivel = lvl;
	save_object(vault_perms);
	tell_object(TP, "Nivel del baul establecido a "+lvl+".\n");
	return 1;
}

int view_vault_log(string str)
{
   string name;
   string tmp;
   int i;
 
   /*if(str) 
   {
      notify_fail("Sintaxis: logs\n");
      return(0);
   }*/
   name = this_player()->QCN;
   if(!this_player()->query_creator() &&
      (i = member_array(name,vault_admin)) == -1)
   {
   	notify_fail("No tienes acceso para ver los logs.\n");
   	return 0;
   }
	if (no_me_mola(TP) && !TP->query_creator()) {	// admin MAL PUESTO
		// caso de admin que no debe tener acceso al baul
		vault_admin -= ({ vault_admin[i] });
		save_object(vault_perms);
		notify_fail("Que hacia alguien como tu de administrador de este baul?\n");
		return 0;
	}
   
   	tell_object(TP, "%^BOLD%^Log %^RED%^antiguo%^RESET%^:\n\n");
      tmp = read_file(vault_log+".old");
      	TP->more_string(tmp);
      	tell_object(TP, "\n\n%^BOLD%^Log %^GREEN%^nuevo%^RESET%^:\n\n");
      tmp = read_file(vault_log);
      TP->more_string(tmp);
      return 1;
}

int do_deposit(string str)
{
   object vault = clone_object(STORAGE+"vault_obj.c");
   object *all;
   int i, clonando = 0;

   if (!str || !sizeof(str)) {
	   vault->dest_me();
	   notify_fail("Depositar que?\n");
	   return 0;
   }

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
      notify_fail("El baul esta siendo usado, prueba en unos momentos.\n");
      vault->dest_me();
      return 0;
   }
	if (no_me_mola(TP) && !TP->query_creator()) {
		vault->dest_me();
		notify_fail("No deberias depositar cosas en baules ajenos.\n");
		return 0;
	}

	if (depositar_fn) {
		if (!call_other(TO, depositar_fn, TP, str)) {
			vault->dest_me();
			notify_fail("Oops, no has podido depositar nada en el baul.\n");
			return 0;
		}
	}

	if (razones[TP->QCN]) {
		vault->dest_me();
		tell_object(TP, "No puedes depositar cosas en este baul. Razon: "+razones[TP->QCN]+".\n");
		notify_fail("");
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
            write("Depositas "+all[i]->query_short()+
               " en el baul, y se convierte en una nube de humo.\n\n");
            //vault->dest_me();
            all[i]->dest_me();
            continue; //return(1);
         }

			// Determinando si este objeto puede entrar en nuestro baul :P
		// This is here for a REASON, if you change it you had better
        // pray I don't find it - Radix
         if(!allow_fn && !allow_all && !all[i]->query_weapon() && !all[i]->query_armour() &&
            !all[i]->query_scroll() && !all[i]->query_wand())
         {
            tell_object(TP, all[i]->query_short() +" no esta permitido en el baul.\n");
            //vault->dest_me();
            //return 1;
			continue;
         }
         else
         {
  			if (allow_fn) {
				if (!call_other(TO, allow_fn, TP, all[i])) {
					//vault->dest_me();
					tell_object(TP, all[i]->query_short()+ " no esta permitido en el baul.\n");
					continue; //return 0;
				}
			}
          write("Depositas satisfactoriamente "+all[i]->short()+".\n");
            say(this_player()->query_short()+" deposita "+
               all[i]->query_short()+" en el baul\n");
            all[i]->move(vault);
            if (clonando) {
            	log_file("ENTER_SOSPECHOSO", sprintf("Clonada efectiva: %s deposita %s (%s)\n",
            	TP->query_short(),all[i]->query_short(),file_name(all[i])));
            	all[i]->add_property("clonada_de", TP->query_short());
            }
            swap_logs(vault_log);
            write_file(vault_log,this_player()->query_short()+
               " %^BOLD%^GREEN%^deposito%^RESET%^:  "+all[i]->query_short()+" a las "+
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

int do_retrieve(string str)
{
   object vault = clone_object(STORAGE+"vault_obj.c");
   object *all;
   int i;

   if (!str || !sizeof(str)) {
	   vault->dest_me();
	   notify_fail("Recuperar que?\n");
	   return 0;
   }

   if(query_property("vault_using"))
   {
      notify_fail("El baul esta siendo usado, prueba en unos momentos.\n");
      vault->dest_me();
      return 0;
   }
	if (no_me_mola(TP) && !TP->query_creator()) {
		vault->dest_me();
		notify_fail("No deberias recuperar cosas de baules ajenos.\n");
		return 0;
	}

	if((TP->query_level() < nivel) && (member_array(TP->QCN, vault_admin) == -1) && !TP->query_creator())
	{
		notify_fail("No tienes el nivel requerido para recuperar objetos.\n");
		vault->dest_me();
		return 0;
	}

	if (recuperar_fn) {
		if (!call_other(TO, recuperar_fn, TP, str)) {
			vault->dest_me();
			notify_fail("Oops, no has podido recuperar nada del baul.\n");
			return 0;
		}
	}

	//if ((i = member_array(TP->QCN, razones)) != -1) {
	if (razones[TP->QCN]) {
		vault->dest_me();
		tell_object(TP, "No puedes sacar cosas de este baul. Razon: "+razones[TP->QCN]+".\n");
		notify_fail("");
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
            swap_logs(vault_log);
            write_file(vault_log,this_player()->query_short()+
               " %^BOLD%^YELLOW%^recupero%^RESET%^:  "+all[i]->query_short()+" a las "+
               ctime(time())+"\n");
         }
         else
            write("Te asustas al ver lo que pesa "+all[i]->short()+".\n");
      }
      vault->dest_me();
      return(1);
   }
   vault->dest_me();
   notify_fail("No puedes recuperar "+str+" de este baul.\n");
   return(0);
}

int do_list()
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
      write("Hay "+sizeof(all)+" objetos depositados en el baul:\n\n");
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
