// Original - Hamlet
// Added more_string for task list, Radix - Aug 1996

inherit "/std/object.c";

void setup() {
  reset_drop();
  set_name("notepad");
  set_short("notepad");
  set_long("My todo list.\n");
}

void init() {
  ::init();
  add_action("add_note","jot");
  add_action("list_tasks","todo");
  add_action("delete_note","check");
  add_action("do_help","help");
}

void do_help(string str) {
  if(!str || (str != "notepad"))  return 0;

tell_object(this_player(),
"Hamlet's todo-list notepad, version 1\n\n\n"
"Commands:\n"
"  jot <text>       :  Add a new note.\n"
"  todo             :  List all notes.\n"
"  check <number>   :  Check a note off your todo list.\n"
"  help notepad     :  Fairly obvious.\n\n\n"
"Note:  If you indent a note, it is considered part of the previous note.\n\n"
"Notes are saved in /w/<yourname>/TODO.LIST\n");

  return 1;
}

void add_note(string str) {
  if(!str)  return 0;

  seteuid(geteuid(this_player(1)));
  write_file("/w/"+this_player()->query_name()+"/TODO.LIST",str+"\n");
  tell_object(this_player(),"Ok.\n");
  return 1;
}

void list_tasks(string str) {
  string junk;
  string *morejunk;
  int i,j,k;
  string ret = "";
  seteuid(geteuid(this_player(1)));
  junk = read_file("/w/"+this_player()->query_name()+
                   "/TODO.LIST",1,file_size("/w/"+
                   this_player()->query_name()+"/TODO.LIST"));

  if(sizeof(junk))  morejunk = explode(junk,"\n");
  else  return 0;
  j=0;
  for(i=0;i<sizeof(morejunk);i++) {
    k = j;
    if(morejunk[i][0] != ' ')  j++;
    if(k==j)
//    tell_object(this_player(),"   "+morejunk[i]+"\n");
      ret += "   "+morejunk[i]+"\n";
    else
//    tell_object(this_player(),j+") "+morejunk[i]+"\n");
      ret += j+") "+morejunk[i]+"\n";
  }
   this_player()->more_string(ret);
  return 1;
}

void delete_note(string str) {
  string junk;
  string *morejunk;
  int i,j,k,m;
  int FOUND = 0;

  seteuid(geteuid(this_player(1)));
  junk = read_file("/w/"+this_player()->query_name()+
                   "/TODO.LIST",1,file_size("/w/"+
                   this_player()->query_name()+"/TODO.LIST"));
  morejunk = explode(junk,"\n");

  if(sizeof(junk))  morejunk = explode(junk,"\n");

  sscanf(str,"%d",k);
  if((k==0) || (k > sizeof(morejunk)))  return 0;

  j=0;
  for(i=0;i<sizeof(morejunk);i++) {
    if(morejunk[i][0] != ' ')  j++;
    if(k==j) {
      FOUND = 1;
      break;
    }
  }

  if(!FOUND)  return 0;

  for(m=i+1;m<sizeof(morejunk);m++)
    if(morejunk[m][0] != ' ')
      break;

  if(i == 0)
    morejunk = morejunk[m..sizeof(morejunk)-1];
  else if((m == sizeof(morejunk)) || (morejunk[m][0] == ' '))
    morejunk = morejunk[0..(i-1)];
  else
    morejunk = morejunk[0..(i-1)] + morejunk[m..sizeof(morejunk)-1];

  junk = implode(morejunk,"\n");
  rm("/w/"+this_player()->query_name()+"/TODO.LIST");
  write_file("/w/"+this_player()->query_name()+"/TODO.LIST",junk+"\n");
  tell_object(this_player(),"Ok.\n");
  return 1;
}

