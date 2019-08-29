/* Cleaning, documentation by Hamlet.  Added a few features while I
   was at it.  Only a little of the actual code is mine.  Made most
   everything #defined at the top :)
*/
#include "login.h"
inherit "std/object";

#define TOTAL_SLOTS 40
#define IMMORT_SLOTS 10
#define MAX_RETRYS 2
#define MIN_LEN 3
#define MAX_LEN 11
/*
#define PLAYER_LOCKOUT 1
*/

int test_add(object ob, int flag) { return 1; }
int test_remove(object ob, int flag) { return 1; }

private nosave object new_copy, other_copy;
string password, title, al_title;
int cols;
int Str, Dex, gender, creator, app_creator;
string ident;

private nosave int no_times;
private nosave string player_ob;
private nosave int invis_wish;

protected void begin2(int new_pl);
protected void begin(int new_pl);
void logon3();
void logon4(int bing);
void logon5(int new_pl);
void guest_login();
void cat(string str);

void create() {
  	cols = 79;
  	::create();
  	set_name("logon");
  	gender = -1;
  	Str = -1;
  	Dex = -1;
  	invis_wish = -1;
  	seteuid("Root");
  	player_ob = "/global/player";
	}

int query_cols() { return cols; }
string query_cap_name() { return "Logon"; }
string query_title() { return "sin titulo"; }
int query_creator() { return creator; }

int check_valid_name(string str) {
  	int i;
  	for (i=0;i<strlen(str);i++)
    	if (str[i] < 'a' || str[i] > 'z') return i;
      	return -1;
	}

void logon() {
  	int tim,i;
	mixed txt;

  	call_out("time_out",300);
  	if (this_player() == this_object()) {
		txt=read_file("/doc/WELCOME");
		txt=explode(txt,"%^");
		for(i=0;i<sizeof(txt);i++) if("/obj/handlers/term"->ansi_code(txt[i])) txt[i]="/obj/handlers/term"->ansi_code(txt[i]);
		txt=implode(txt,"");
		TO->do_efun_write(txt);
		}
  	if(find_object("/obj/shut") && ("/obj/shut"->query_time_to_crash() >= 0)) {
    		tim = (int)"/obj/shut"->query_time_to_crash();
    		if (tim < 120) {
      			write(REBOOT_TOO_SOON);
      			dest_me();
      			return;
    			}
    		else {
      			write(REBOOT_AT[0]+(tim/60)+REBOOT_AT[1]);
    			}
  		}

  	if(uptime() < 10) {
    		write(JUST_REBOOTED);
    		dest_me();
    		return;
  		}

  	if(sizeof(users()) > TOTAL_SLOTS) {
    		write(MUD_FULL);
    		dest_me();
    		return;
  		}
	write(ENTER_NAME);
  	input_to("logon1",2);
	} /* logon() */

void logon1(string str);

int do_su(string str) {
  	object ob, tp;

  	ob = this_player();
  	tp = this_object();
  	exec(tp, ob);
  	ob->quit();
  	logon1(str);
  	return 1;
	} /* do_su() */

void time_out() {
  	write(TIME_OUT);
  	destruct(this_object());
	} /* time_out() */

// Checks for "five", "ten", ..."ninety" - Radix : Jan 3, 1996
int check_proper_name(string n) {
   	int i;
   	for(i=0; i<21; i++) if(query_num(i,100) == n) return 0;
   	for(i=20; i<101; i+=10) if(query_num(i,1000) == n) return 0;
   	return 1;
	}

void logon1(string str) {
  	int tmp;
  	int NEWBIE = 0;
  	creator = 0;
  	app_creator = 0;

  	if (str=="") {
    		write(TIME_SHORT);
    		destruct(this_object());
    		return ;
  		}

#ifdef PLAYER_LOCKOUT
  	if (str=="guest") {
    		write("No se admiten invitados por ahora...\n");
    		destruct(this_object());
    		return;
  		}
#endif

  	name = lower_case(str);

  	if(name[0] == '#') {
    		invis_wish = 0;
    		name = name[1..strlen(name)-1];
  		}
  	else if(name[0] == '*') {
    		invis_wish = 1;
    		name = name[1..strlen(name)-1];
  		}
  	else if(name[0] == '@') {
    		invis_wish = 2;
   		name = name[1..strlen(name)-1];
  		}

  	if(strlen(name) > MAX_LEN) {
    		write("Nombre demasiado largo (max "+MAX_LEN+" letras).\n");
    		write(ENTER_NAME);
    		input_to("logon1",2);
    		return;
  		}
  	if(strlen(name) < MIN_LEN) {
    		write("Nombre demasiado corto (min "+MIN_LEN+" letras).\n");
    		write(ENTER_NAME);
    		input_to("logon1",2);
    		return;
  		}
   	if(!check_proper_name(name)) {
      		write(NOT_PROPER_NAME);
      		write(ENTER_NAME);
      		input_to("logon1");
      		return;
   		}
  	if ((tmp = check_valid_name(name)) != -1) {
    		write("El caracter '"+str[tmp]+"'  ("+str+") es INVALIDO.\n\n");
    		write(ENTER_NAME);
    		input_to("logon1");
    		return;
  		}

#ifdef PLAYER_LOCKOUT
  	if(!read_file("/w/"+name+"/workroom.c")) {
    		write("\n\nNinetears\n\n"+
    			"El mud esta cerrado a jugadores ahora mismo, eso suele significar " +
    			"que o bien estamos arreglando bugs o estamos en preparando nuevos " +
    			"cambios. Prueba despues de algun tiempo.\n\n");
    		destruct(this_object());
    		return;
  		}
#endif

  	if(!restore_object("/players/"+name[0..0]+"/"+name,1)) NEWBIE = 1;

  	player_ob = (string)"/secure/bastards"->query_player_ob(name);

  	if (!stringp(player_ob) || !strlen(player_ob)) {
    		write("Intentalo dentro de un tiempo.\n");
    		dest_me();
    		return ;
  		}

  	if(player_ob == "/global/player") {
    		if(sizeof(users()) > TOTAL_SLOTS - IMMORT_SLOTS) {
      			write("Demasiados jugadores. Prueba dentro de un rato.\n");
      			dest_me();
      			return;
    			}
  		}

	if (name == "guest") {
    		guest_login();
    		return;
  		}

  	if(NEWBIE) {
    		cat("/doc/NEW");
    		write(NEW_PLAYER);
    		write("Tu nombre ["+name+"] es correcto (s/n) ? ");
    		input_to("check_name");
    		return ;
  		}
  	else if (!password) {
    		logon3();
    		return;
  		}
  	write(ENTER_PASSWORD);
  	input_to("logon2",1);
	}

int check_name(string str) {
  	str = implode(explode(str," "),"");
  	if (str[0] == 's') {
    		write(NEW_PLAYER);
    		write(ENTER_PASSWORD);
    		input_to("logon2", 1);
    		return 1;
  		}
  	if (str[0] == 'n') {
    		write("De acuerdo, escribelo otra vez: ");
    		input_to("logon1");
    		return 1;
  		}
  	write("No entiendo... (s/n)  ? ");
  	input_to("check_name",2);
  	return 1;
	}

/* This function doesen't get called by any function in login.c ?
 * Why is it here then ?
 */
int test_password(string name, string pass) {
  string tmp;

  if (!stringp(name) || strlen(name) < 2 || sscanf(name, "%s %s", tmp, tmp)
      || name[0] == '.' || sscanf(name, "%s..%s", tmp,tmp))
    return 0;
  if(!restore_object("/players/"+name[0..0]+"/"+name,1))
    return 0;
  return crypt(pass, password) == password;
} /* test_password() */

protected void logon2(string str) {
  	write("\n");
  	if (str == "") {
    		write(COME_BACK);
    		destruct(this_object());
    		return ;
  		}
  	str = crypt(str,password);
  	if (password && str != password) {
    		if (++no_times > MAX_RETRYS) {
      			write(TOO_MANY_RETRIES);
      			destruct(this_object());
      			return ;
    			}
    		if (Dex == -1) {
      			write("Los passwords no son iguales.\n");
      			write(ENTER_PASSWORD_AGAIN);
      			Str = -1;
      			input_to("logon2",1);
      			return ;
    			}
    		write("Parece que te has equivocado...\nPrueba otra vez :");
    		input_to("logon2",1);
    		return ;
  		}
  	password = str;
  	if (Str == -1) {
    		Str = 13;
    		write(ENTER_PASSWORD_AGAIN);
    		input_to("logon2", 1);
    		return;
  		}
  	if (Dex == -1) Dex = 10;
  	logon3();
	}

protected void logon3() {
  	if (gender == -1) {
    		write("�Deseas ser hombre o mujer (h/m) ? ");
    		input_to("get_sex");
    		return;
  		}
  	logon4(0);
	} /* logon3() */

protected void get_sex(string str) {
  	str = lower_case(str);
  	if (str != "") {
		if (str[0] == 'h') gender = 1;
  		else if (str[0] == 'm') gender = 2;
		else {
	   		write("Bonito sexo, pero no vale.\n");
    			write("Elige hombre o mujer (h/m): ");
    			input_to("get_sex");
    			return;
			}
		}
  	else {
   		write("Bonito sexo, pero no vale.\n");
    		write("Elige hombre o mujer (h/m): ");
    		input_to("get_sex");
    		return;
  		}
  	if (!query_property("guest")) save_object("/players/"+name[0..0]+"/"+name,1);
    	logon4(!query_property("guest"));
  	}

protected void logon4(int new_pl) {
  	if (name != "root" && name != "guest") {
    		other_copy = find_player(name);
    		if(other_copy == this_player()) {
      			begin(new_pl);
      			return;
    			}
    		if(other_copy) {
      			write("Ya estabas viciando. Saco al impostor (s/n) ? ");
      			input_to("try_throw_out");
      			return;
    			}
  		}
  	begin(new_pl);
	}

void guest_login() {
  	write(GUEST_ENTER_NAME);
  	input_to("guest_login2");
  	return ;
	}

void guest_login2(string str) {
  	int tmp;

  	if (!str || str == "") {
    		write(COME_BACK);
    		destruct(this_object());
    		return ;
  		}
  	if (strlen(str) < MIN_LEN) {
    		write("Y por que no pruebas a poner nombres aun mas cortos???.\n");
    		write("Pon ya tu nombre : ");
    		input_to("guest_login2");
    		return ;
  		}
  	str = lower_case(str);
  	str = str[0..11];
  	if(str == "guest") {
    		write("Si, ya sabemos que eres un invitado.\nIntroduce tu nombre durante la visita : ");
    		input_to("guest_login2");
    		return;
  		}
  	if ((tmp = check_valid_name(str)) != -1) {
    		printf("Caracter no aceptado '%d'-%c\n", str[tmp], str[tmp]);
    		printf("Di tu nombre de nuevo : ");
    		input_to("guest_login2");
    		return ;
  		}
  	if (file_size("/players/"+str[0..0]+"/"+str+".o") > 0) {
    		write("Ese nombre esta ocupado.\n");
    		write("Elige otro : ");
    		input_to("guest_login2");
    		return ;
  		}
  	name = str;
  	add_property("guest", 1);
  	printf("Eres hombre o mujer (h/m) ? ");
  	input_to("get_sex");
	}

protected void try_throw_out(string str) {
  	object tmp, ob;
  	if (str == "restart") {
    		if (catch(other_copy->quit())) if (catch(other_copy->dest_me())) destruct(other_copy);
    		begin(0);
    		return;
  		}
  	if (str == "" || (str[0] != 's' && str[0] != 'S')) {
    		write(COME_BACK);
    		destruct(this_object());
    		return;
  		}
  	if (interactive(other_copy)) {
    		ob = clone_object("/std/object");
    		tmp = other_copy;
    		exec(ob, other_copy);
    		ob->dest_me();
  		}
  	tmp = other_copy;
  	ob = this_object();
  	exec(other_copy, ob);
  	other_copy->look_me();
  	tell_room(environment(other_copy), other_copy->query_cap_name()+ " se ha reconectado.\n", ({ other_copy }) );
  	event(users() - ({ 0 }), "inform", other_copy->query_cap_name() + " se ha reconectado", "link-death");
  	destruct(this_object());
	}

protected void begin(int new_pl) {
	player_ob = (string)"/secure/bastards"->query_player_ob(name);
  	if (!find_object(player_ob)) {
    		write(LOADING_PLAYER);
    		call_out("begin2", 0, new_pl);
  		}
  	else begin2(new_pl);
	} /* begin() */

protected void begin2(int new_player) {
  	object tp;
  	new_copy = clone_object(player_ob);
/*  	if (!new_copy) {
    		write("Vaya parece que Leviathan o Vilat (o los dos xD) han tocado algun archivo critico... Prueba otro dia.\n");
    		destruct(this_object());
    		return;
  		}
	*/
  	new_copy -> set_name(name);
  	new_copy -> set_password(password);
  	if( query_property("NOMULTI") ) new_copy->add_static_property("NOMULTI", query_property("NOMULTI"));
  	tp = this_object();

  	exec(new_copy, tp);
  	if (tp != this_object()) tp -> quit();
  	if (query_property("guest")) {
    		new_copy->add_property("guest",1);
    		new_copy->set_title(title);
  		}

  	if(!creator) invis_wish = -1;
  	else if( (invis_wish == 2) && !"/secure/master"->query_lord(name) ) invis_wish = 1;


  	new_copy->move_player_to_start(name, new_player, invis_wish);

  	new_copy->set_gender(gender);
  	WHO_HANDLER->add_user(new_copy);
  	destruct(this_object());
	}

int query_level() { return 1; }
int query_gender() { return gender; }

int test_user(string str) {
  	string tmp;

  	if (!stringp(str) || !str || sscanf(str, "%s ",tmp)) return 0;
  	return restore_object("/players/"+str[0..0]+"/"+str,1);
	} /* test_user() */

int test_creator(string str) {
  	if (!stringp(str) || strlen(str) < 2) return 0;
  	if(!restore_object("/players/"+str[0..0]+"/"+str,1)) return 0;
  	return creator;
	} /* test_creator() */

int new_player(object old) {
  	object new_one, tp;
  	string name;

  	name = (string)old->query_name();
  	tp = this_object();
  	exec(tp, old);
  	creator = (int)old->query_creator();
  	old->quit();
  	creator = (int)this_player()->query_creator();
  	new_one = clone_object((string)"/secure/bastards"->query_player_ob(name));
  	exec(new_one, tp);
  	new_one->move_player_to_start(name, 0, -1);
  	destruct(this_object());
	}

int query_prevent_shadow() { return 1; }

string fix_string(string str) { return str; }

void do_efun_write(string str) {
  	efun::tell_object(this_object(), fix_string(str));
	} /* do_efun_write() */

string query_object_type() { return "X"; }

string query_gender_string() { return "blue"; }

void cat(string str) {
  	do_efun_write(read_file(str)+"\n");
	}

int query_lord() {
  	return "/secure/master"->query_lord(name);
	}

string query_ident() {  return ident;  }

void terminal_type( string term ) {
  	log_file("terminal.type",file_name(this_object())+": "+term+"\n");
	}

void window_size(int rows, int cols){
  	log_file("terminal.type",file_name(this_object())+": "+rows+" cols and "+cols+" rows.\n");
	}
