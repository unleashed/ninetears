// Original - Hamlet
// Added more_string for task list, Radix - Aug 1996

inherit "/std/object.c";

void setup() {
  reset_drop();
  set_name("Block de Notas");
  set_short("Block");
  add_alias("block");
  add_alias("block de notas");
  set_long("Es un pequenyo block de notas, te permitira recordar rapidamente tus tareas "
	"pendientes y demas, ligera y pequenya, pero un objeto realmente util.\n");
}

void init() {
  ::init();
  add_action("add_note","nota");
  add_action("list_tasks","todo");
  add_action("delete_note","borranota");
  add_action("do_help","help");
}

void do_help(string str) {
  if(!str || (str != "notepad"))  return 0;

tell_object(this_player(),
"\n\nComandos:\n"
"  nota <text>         :  Anyade una nueva nota.\n"
"  todo                :  Lista todas las notas.\n"
"  borranota <numero>  :  Elimina una nota de la lista.\n"
"  help notepad        :  No komment.\n\n\n"
"Nota:  Si indentas una nota, esta es considerada como parte de la nota anterior.\n\n"
"Las notas son salvadas en /w/<tunombre>/TODO.LIST\n");

  return;
}

void add_note(string str) {
  if(!str)  return 0;

  seteuid(geteuid(this_player(1)));
  write_file("/w/"+this_player()->query_name()+"/TODO.LIST",str+"\n");
  tell_object(this_player(),"OK.\n");
  return ;
}

int list_tasks(string str) {
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

int delete_note(string str) {
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

