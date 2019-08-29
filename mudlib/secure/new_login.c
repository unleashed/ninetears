// Taniwha cat barfs
inherit "std/object";

#define MAX_RETRYS 3
#define MIN_LEN 3
#define TOTAL_SLOTS 70
#define IMMORT_SLOTS 70

int test_add(object ob, int flag) { return 1; }
int test_remove(object ob, int flag) { return 1; }

static object new_copy, other_copy;
string password, title, al_title;
int cols;
int Str, Dex, gender, creator, app_creator;
static int no_times;
static string player_ob;

static void begin2(int new_pl);
static void begin(int new_pl);
void logon3();
void logon4(int bing);
void logon5(int new_pl);
void guest_login();
 
void create() {
  cols = 79;
  ::create();
  set_name("logon");
  gender = -1;
  Str = -1;
  Dex = -1;
  seteuid("Root");
  player_ob = "/global/player";
} /* create() */
 
int query_cols() { return cols; }
string query_cap_name() { return "Logon"; }
string query_title() { return "the title-less"; }
int query_creator() { return creator; }
 
int check_valid_name(string str) {
int i;
  for (i=0;i<strlen(str);i++)
    if (str[i] < 'a' || str[i] > 'z') return i;
  return -1;
} /* check_valid_name() */
 
void logon() {
  int tim;

  call_out("time_out",300);
  if (this_player() == this_object())
        cat("/doc/WELCOME");
  if (find_object("/obj/shut")) 
    {
    tim = (int)"/obj/shut"->query_time_to_crash();
    if (tim < 120) 
      {
      write("Sorry, too close to reboot, please log on in a few minutes.\n");
      dest_me();
      return;
      }
     else 
      { 
      write("Mud shutting down in "+(tim/60)+" minutes.\n");
      }
    }
  write("Enter your name: ");
  input_to("logon1");
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
  write("Time out.\n\n");
  destruct(this_object());
} /* time_out() */
 
void logon1(string str) {
int tmp, frog;
object ob, me;
  creator = 0;
  app_creator = 0;
  if (str=="") {
    write("Well, come back some other time then!\n");
    destruct(this_object());
    return ;
  }
  /* This is a part of the lockout..
  if (str=="guest")
    {
    write("Well, we can't let guests in.\n");
    destruct(this_object());
    return;
    }
  */

  name = lower_case(str);
/* query_player_ob() should only be passed 1 as its 2nd argument HERE!
   It's a big mistake to pass a second arg at all anywhere else. - Hamlet
*/
  player_ob = (string)"/secure/bastards"->query_player_ob(name,1);
/* changed next line to be stringp - Hamlet */
  if (!stringp(player_ob)) {
    write("Sorry, that player name has been banished.\n");
    dest_me();
    return ;
  }

/* A hack while login_handler is being looked at -- Hamlet */
  if(player_ob == "/global/player") {
    if(sizeof(users()) > TOTAL_SLOTS - IMMORT_SLOTS) {
      write("Too many players.  Try back later.\n");
      dest_me();
      return;
    }
  }
  else {
    if(sizeof(users()) > TOTAL_SLOTS) {
      write("The mud is full.  Try back later.\n");
      dest_me();
      return;
    }
  }
/* End hack */
  if( (strlen(name) > 11) || (strlen(name) < MIN_LEN) ) {
    write("Name too long (max 11 chars). Please retry.\n");
    write("Enter your name: ");
    return input_to("logon1");
  }
  if ((tmp = check_valid_name(name)) != -1) {
    write("Invalid character '"+str[tmp]+"'  ("+str+").\n\n");
    write("Enter your name: ");
    input_to("logon1");
    return;
  }
    /* To use when we will lock out players */
    /* Open again..
  if(!read_file("/w/"+name+"/workroom.c")) 
     {
     write("\n\nFINAL REALMS MUD \n\n"+
          "This is the development site for FR.\n\n " + 
          "The playable FR has been moved to fr.hiof.no port 2001\n\n");
    destruct(this_object());
    }
    */
  if (name == "guest")
    return guest_login();

  if(!restore_object("/players/"+name[0..0]+"/"+name,1)){
    cat("/doc/NEW");
    write("Your name is not in our annals.\n");
    write("Did you enter your name ["+name+"] correctly (y/n) ? ");
    input_to("check_name");
    return ;
  }
  else if (!password)
    return logon3();
  write("Enter password: ");
  input_to("logon2",1);
} /* logon1() */

int check_name(string str) {
  str = implode(explode(str," "),"");
  if (str[0] == 'y') {
    write("New character.\n");
    write("Enter password : ");
    input_to("logon2", 1);
    return 1;
  }
  if (str[0] == 'n') {
    write("Ok, try again... Please enter your name : ");
    input_to("logon1");
    return 1;
  }
  write("No... (y/n)  ? ");
  input_to("check_name");
  return 1;
} /* check_name() */

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

static void logon2(string str) {
  write("\n");
  if (str == "") {
    write("Come back some other time then!\n");
    destruct(this_object());
    return ;
  }
  str = crypt(str,password);
  if (password && str != password) {
    if (++no_times > MAX_RETRYS) {
      write("Too many retries.\n");
      destruct(this_object());
      return ;
    }
    if (Dex == -1) {
      write("Didn't match up with first password.\n");
      write("Enter password again : ");
      Str = -1;
      input_to("logon2",1);
      return ;
    }
    write("Wrong...\nTry again :");
    input_to("logon2",1);
    return ;
  }
  password = str;
  if (Str == -1) {
    Str = 13;
    write("\nPassword (again): ");
    input_to("logon2", 1);
    return;
  }
  if (Dex == -1)
    Dex = 10;
  logon3();
} /* logon2() */
 
static void logon3() {
  if (gender == -1) {
    write("Are you male or female ? ");
    return input_to("get_sex");
  }
  logon4(0);
} /* logon3() */
 
static void get_sex(string str) {
int i;
  str = lower_case(str);
  if (str != "")
    i = str[0];
  if (i == 'm')
    gender = 1;
  else if (i== 'f')
    gender = 2;
  else {
    write("Thats too wierd for even this game!\n");
    write("Try male or female :");
    return input_to("get_sex");
  }
  if (!query_property("guest"))
    save_object("/players/"+name[0..0]+"/"+name,1);
  logon4(!query_property("guest"));
} /* get_sex() */

static void logon4(int new_pl) {
  int i;
  object *kopi;
  if (name != "root" && name != "guest")
  {
   other_copy = find_player(name);
   if(other_copy == this_player())
    return begin(new_pl);
   if(other_copy)
    {
     write("You are already playing. Throw the other copy out (y/n) ? ");
     return input_to("try_throw_out");
    }
  }
  begin(new_pl);
} /* logon4() */

void guest_login() {
  write("Use what name for your visit ? ");
  input_to("guest_login2");
  return ;
}  /* guest_login() */

void guest_login2(string str) {
  int tmp;

  if (!str || str == "") {
    write("Ok see you some other time then.\n");
    write("Have fun.\n");
    destruct(this_object());
    return ;
  }
  if (strlen(str) < MIN_LEN) {
    write("That name is too short.\n");
    write("Try again with a longer name : ");
    input_to("guest_login2");
    return ;
  }
  str = lower_case(str);
  str = str[0..11];
  if(str == "guest") {
    write("Yes, we know you are a guest.\n" +
      "Please enter a name for this visit : ");
    input_to("guest_login2");
    return;
  }
  if ((tmp = check_valid_name(str)) != -1) {
    printf("Invalid character '%d'-%c\n", str[tmp], str[tmp]);
    printf("Please enter your name again : ");
    input_to("guest_login2");
    return ;
  }
  if (file_size("/players/"+str[0..0]+"/"+str+".o") > 0)
  {
    write("Sorry that name is already used.\n");
    write("Please try another name : ");
    input_to("guest_login2");
    return ;
  }
  name = str;
  add_property("guest", 1);
  printf("What sex do you want to be (M/F) ? ");
  input_to("get_sex");
} /* guest_login2() */

static void try_throw_out(string str) {
object tmp, ob, ob1;
  if (str == "restart") {
    if (catch(other_copy->quit()))
      if (catch(other_copy->dest_me()))
        destruct(other_copy);
    return begin(0);
  }
  if (str == "" || (str[0] != 'y' && str[0] != 'Y')) {
    write("Ok, come back later on then!\n");
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
/* force a look ;) */
  other_copy->look_me();
  tell_room(environment(other_copy), other_copy->query_cap_name()+
    " has reconnected.\n", ({ other_copy }) );
/* Getting error on dested object here...  Which could not be considered
 * good.  Hopefully the - ({ 0 }) will fix this.   Though I think I will patch
 * event to avoid it altogether...
 */
  event(users() - ({ 0 }), "inform",
        other_copy->query_cap_name() + " reconnected", "link-death");
  destruct(this_object());
} /* try_throw_out() */

static void begin(int new_pl) {
  player_ob = (string)"/secure/bastards"->query_player_ob(name);
  if (!find_object(player_ob)) {
    write("Please wait... Loading player object.\n");
    call_out("begin2", 0, new_pl);
  } else
    begin2(new_pl);
} /* begin() */

static void begin2(int new_player) {
object ob, ob1, tp;
/* clone the player object */
  catch(new_copy = clone_object(player_ob));
  if (!new_copy) {
    write("Arrggghhhh something bad happened.\n");
    destruct(this_object());
    return 0;
  }
  new_copy -> set_name(name);
  new_copy -> set_password(password);
  tp = this_object();
  exec(new_copy, tp);
  if (tp != this_object())
    tp -> quit();
  if (query_property("guest")) {
    new_copy->add_property("guest",1);
    new_copy->set_title(title);
  }
  new_copy->move_player_to_start(name, new_player);
  new_copy->set_gender(gender);
  destruct(this_object());
} /* begin2() */
 
int query_level() { return 1; }
int query_gender() { return gender; }

/*
 * used by the mailer to determine if bing is a real man
 */
int test_user(string str) {
  string tmp;

  if (!stringp(str) || !str || sscanf(str, "%s ",tmp))
    return 0;
return restore_object("/players/"+str[0..0]+"/"+str,1);
} /* test_user() */

int test_creator(string str) {
  if (!stringp(str) || strlen(str) < 2)
    return 0;
if(!restore_object("/players/"+str[0..0]+"/"+str,1))
    return 0;
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
  new_one->move_player_to_start(name, 0);
  destruct(this_object());
} /* new_player() */

int query_prevent_shadow() { return 1; }

/*
 * Needed so the object actually writes things to the screen.  Mildly
 * embarasing otherwise.
 */
void do_efun_write(string str) {
  efun::tell_object(this_object(), str);
} /* do_efun_write() */

string query_object_type() { return "X"; }

string query_gender_string() { return "blue"; }
