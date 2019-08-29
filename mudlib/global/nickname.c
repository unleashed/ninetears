/*
 * The great and wonderful alias driver by me ;)
 * pinkfish.
 */
mapping map_nicknames;
 
string *query_nicknames() { return keys(map_nicknames) + ({ }); }

void nickname_commands() {
  add_action("delete_nickname", "dnick");
  add_action("nickname", "nick");
add_action("flushnicknames","flushnicks");
}
int flushnicknames(string str)
{
  write("Esto borrara todos tus nicks. Estas seguro? (S/N)\n");
input_to("flushnicks",0);
return 1;
}
int flushnicks(string str)
{
if(str=="S"||str=="s")
  {
map_nicknames=0;
write ("Nicknames borrados.\n");
}
else write("Otro dia entonces.\n");
return 1;
}

int add_nickname(string str) {
  string s1,s2;

  if (sscanf(str,"%s %s",s1,s2)!=2) {
    notify_fail("Eres una rana.\n");
    return 0;
  }
  if (!map_nicknames)
    map_nicknames = ([ ]);
  if (!map_nicknames[s1]) {
    map_nicknames[s1] = s2;
    write("Anyadiendo nombre corto "+s1+" como "+s2+".\n");
    return 1;
  }
  write("Cambiando nombre corto "+s1+" desde "+map_nicknames[s1]+" por "+s2+".\n");
  map_nicknames[s1] = s2;
  return 1;
}

string expand_nickname(string str) {
  string *arra;
  int i;

  if (stringp(str))
    arra = explode(lower_case(str)," ");
  else
    return str;
  if (!map_nicknames)
    map_nicknames = ([ ]);
  for (i=0;i<sizeof(arra);i++)
    if (map_nicknames[arra[i]])
      arra[i] = map_nicknames[arra[i]];
  return implode(arra," ");
}

int delete_nickname(string str) {
  if (!map_nicknames)
    map_nicknames = ([ ]);
  if (!map_nicknames[str]) {
    notify_fail("Ese nick no existe.\n");
    return 0;
  }
  map_nicknames = m_delete(map_nicknames, str);
  write("Nick borrado : "+str+"\n");
  return 1;
}

int print_nicknames() {
  int i, cols;
  string str, str1, str2, bit, *tmp;

  bit = "";
  str1 = "";
  str2 = "";
  if (!map_nicknames)
    map_nicknames = ([ ]);
  tmp = m_indices(map_nicknames);
  cols = (int)this_player()->query_cols();
  for (i=0;i<sizeof(tmp);i++) {
    str = tmp[i]+": "+map_nicknames[tmp[i]]+"  ";
    if (strlen(str)>39)
      printf(tmp[i]+": %-=*s\n", cols - strlen(tmp[i]), map_nicknames[tmp[i]]);
    else if (strlen(str) > 19)
      str1 += str+"\n";
    else
      str2 += str+"\n";
  }
  if (strlen(str1))
    printf("%-#*s\n", cols, str1);
  if (strlen(str2))
    printf("%-#*s\n", cols, str2);
  return 1;
}

int nickname(string str) {
  string s1,s2;

  if (!map_nicknames)
    map_nicknames = ([ ]);
  if (!str || str == "")
    return print_nicknames();

  if (sscanf(str,"%s %s",s1,s2)!=2) {
    if (!map_nicknames[str]) {
      notify_fail("Ese nick no existe.\n");
      return 0;
    }
    write("El nombre corto "+str+" es "+map_nicknames[str]+".\n");
    return 1;
  }
  return add_nickname(str);
}
