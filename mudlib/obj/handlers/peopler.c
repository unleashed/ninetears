#define NAMEX 0
#define C_NAMEX 1
#define STRING 2
#define GENDERX 3
#define IP_NUMBER 4
#define IP_NAMEX 5
#define TYPE 6
#define AGE 7
#define GUILD 8
#define RACE 9
#define LEVELX 10
#define TERMINAL 11
#define ROWS 12
#define COLS 13
#define ROOM 14
#define EUID 15
#define UID 16
#define CFILE 17
#define CUR_DIR 18
#define GUILDOB 19
#define ALIGNMENT 20
#define PLAYERSETALIGNMENT 21
#define CENTER 128
#define RIGHT 64
#define MASK (RIGHT+CENTER)
#define ABBREV ({ \
          "n", \
          "N", \
          "", \
          "G", \
          "#", \
          "I", \
          "T", \
          "A", \
          "g", \
          "R", \
          "L", \
          "t", \
          "r", \
          "c", \
          "O", \
          "E", \
          "U", \
          "F", \
          "U", \
          "o", \
          "K", \
          "/", \
        })
#define DE_NAMEXS ({ \
          "Name", \
          "Name", \
          "", \
          "Gender", \
          "IP Number", \
          "IP Name", \
          "Type", \
          "Age", \
          "Guild", \
          "Race", \
          "Level", \
          "Terminal type", \
          "Rows", \
          "Cols", \
          "Room", \
          "Euid", \
          "Uid", \
          "Creator file", \
          "Current dir", \
	  "Guild object", \
          "GameAlignment",\
          "PSetAlignment",\
        })

/* This is the default people listing thingy. */
#define P_DEFAULT ({ \
          NAMEX, 12, \
          TYPE|CENTER, 4, \
          STRING, " ", \
          GENDERX|CENTER, 6, \
          STRING, " ", \
          GUILD|CENTER, 10, \
          STRING, " ", \
          RACE|CENTER, 10, \
          LEVELX|RIGHT, 5, \
          STRING, "  ", \
          ALIGNMENT, 10, \
          PLAYERSETALIGNMENT, 10, \
          AGE, 4, \
        })
#define QP_DEFAULT ({ \
          AGE|RIGHT, 4, \
          STRING, " ", \
          NAMEX, 25, \
	  RACE, 10, \
	  GUILDOB, 35, \
        })
#define T_DEFAULT ({ \
          NAMEX, 12, \
          ROWS|CENTER, 5, \
          STRING, " ", \
          COLS|CENTER, 5, \
          STRING, "    ", \
          TERMINAL|CENTER, 20, \
        })
#define N_DEFAULT ({ \
          NAMEX, 12, \
          STRING, " ", \
          IP_NUMBER, 16, \
          STRING, " ", \
          IP_NAMEX, 30, \
        })
#define D_DEFAULT ({ \
          NAMEX, 12, \
          STRING, " ", \
          CUR_DIR, 25, \
          STRING, " ", \
          ROOM, 40, \
        })

string *de_names,
       *abbrev,
       *var_names;

void create() {
  de_names = DE_NAMEXS;
  abbrev = ABBREV;
  var_names = ({ 
      "dirs",
      "netstat",
      "people",
      "qpeople",
      "terms",
    });
} /* create() */

object *get_people(string str) 
  {
  object *ob;
  int i, cr, god;
  string s1;

  ob = users();
  cr = (int)this_player()->query_creator();
  god = (int)this_player()->query_god();
  for (i=0; i < sizeof(ob); i++) 
  {
      /*  Removed... Radix
          users() doesn't return invis 2 obs if this_player != lord
          and below allowed thieves to hide completely
          July 1996
    if ((ob[i]->query_hidden() && !god) || (ob[i]->query_invis() && !cr)
       || (((int)ob[i]->query_invis() > 1) && !god)) 
    {
      ob = delete(ob, i--, 1);
      continue;
    }
      */
    if (str)
      if(sscanf(ob[i]->query_name(),str+"%s", s1) != 1)
        ob = delete(ob, i--, 1);
  } 
  return ob;
} /* get_people() */

string create_title(mixed *bits) 
  {
  int i, pos;
  string str;

  str = "";
  for (i=0;i<sizeof(bits);i+=2) {
    if ((pos = (bits[i]&~MASK)) == STRING)
      str += bits[i+1];
    else
      if (strlen(de_names[pos]) > bits[i+1])
        str += sprintf("%"+bits[i+1]+"."+bits[i+1]+"-s",de_names[pos][0..(bits[i+1]-2)]);
      else {
        switch (bits[i]&MASK) {
          case CENTER :
            str += sprintf("%"+bits[i+1]+"."+bits[i+1]+"|s", de_names[pos]);
            break;
          case RIGHT :
            str += sprintf("%"+bits[i+1]+"."+bits[i+1]+"s", de_names[pos]);
            break;
          default :
            str += sprintf("%"+bits[i+1]+"."+bits[i+1]+"-s", de_names[pos]);
            break;
        }
    }
  }
  return str;
} /* create_title() */

string review_thingy(mixed *bing) {
  int i;
  string str;

  str = "";
  for (i=0;i<sizeof(bing);i+=2) {
    if (bing[i] == STRING) {
      str += bing[i+1];
    } else {
      switch (bing[i]&MASK) {
        case CENTER :
          str += "%|"+bing[i+1]+abbrev[bing[i]&~MASK];
          break;
        case RIGHT :
          str += "%-"+bing[i+1]+abbrev[bing[i]&~MASK];
          break;
        default :
          str += "%-"+bing[i+1]+abbrev[bing[i]&~MASK];
          break;
      }
    }
  }
  return str;
} /* review_thingy() */

/*
 * Ok, the method for doing the format is...
 *    ({ type, width,  ... })
 * With strings the width is the string...
 */
void print_entrys(object *obs, mixed *format) {
  int i, age, j;
  object g;
  string form, str;
string ret;

   ret = "";
  for (i=0;i<sizeof(obs);i++) {
    str = "";
    for (j=0;j<sizeof(format);j+=2) {
      switch (format[j]&MASK) {
        case RIGHT :
          form = "%"+format[j+1]+"."+format[j+1];
          break;
        case CENTER :
          form = "%|"+format[j+1]+"."+format[j+1];
          break;
        default :
          form = "%-"+format[j+1]+"."+format[j+1];
          break;
      }
      switch (format[j]&~MASK) {
        case STRING :
/* Ignore width for this one... */
          str += format[j+1];
          break;
        case C_NAMEX :
          str += sprintf(form+"s",
                         obs[i]->query_cap_name());
          break;
        case GENDERX :
          str += sprintf(form+"s",
                         obs[i]->query_gender_string());
          break;
        case NAMEX :
          str += sprintf(form+"s",
                         (obs[i]->query_in_editor()?"*":"")+
                         obs[i]->query_name());
          break;
        case GUILD :
           if(obs[i]->query_guild_ob()) {
             if( (file_size(obs[i]->query_guild_ob()) > 0) || (file_size(obs[i]->query_guild_ob()+".c") >0) )
               str += sprintf(form+"s",obs[i]->query_guild_ob()->query_name());
             else
               str += sprintf(form+"s","Unknown");
           }
           else
             str += sprintf(form+"s","No guild");
          break;
        case RACE :
	  str += sprintf(form+"s",
			 obs[i]->query_race());
          break; 
        case LEVELX :
          str += sprintf(form+"d",
                         obs[i]->query_level());
          break;
        case ROWS :
          str += sprintf(form+"d",
                         obs[i]->query_rows());
          break;
        case COLS :
          str += sprintf(form+"d",
                         obs[i]->query_cols());
          break;
        case TERMINAL :
          str += sprintf(form+"s",
                         obs[i]->query_term_name());
          break;
        case IP_NUMBER :
          str += sprintf(form+"s",
                         query_ip_number(obs[i]));
          break;
        case IP_NAMEX :
          str += sprintf(form+"s",
                         query_ip_name(obs[i]));
          break;
        case TYPE :
          str += sprintf(form+"s",
                         obs[i]->query_object_type());
          break;
        case AGE :
          age = (int)obs[i]->query_time_on();
          if (age < -86400)
            str += sprintf(form+"s",
                           (age/-86400)+"D");
          else if (age < -3600)
            str += sprintf(form+"s",
                           (age/-3600)+"h");
          else if (age < -60)
            str += sprintf(form+"s",
                           (age/-60)+"m");
          else
            str += sprintf(form+"s",
                           age+"s");
          break;
        case ROOM :
          str += sprintf(form+"s",
                         (environment(obs[i])?
                                       virtual_file_name(environment(obs[i]))
                                       :"No environment"));
          break;
        case EUID :
          str += sprintf(form+"s",
                         (environment(obs[i])?geteuid(environment(obs[i]))
                                       :"No environment"));
          break;
        case UID :
          str += sprintf(form+"s",
                         (environment(obs[i])?getuid(environment(obs[i]))
                                       :"No environment"));
          break;
        case CFILE :
          str += sprintf(form+"s",
                         (environment(obs[i])?"/secure/master"->creator_file(
                                            environment(obs[i]))
                                       :"No environment"));
          break;
        case CUR_DIR :
          str += sprintf(form+"s", (obs[i]->query_current_path()?
                          obs[i]->query_current_path():"No dir"));
          break;
        case GUILDOB :
          str += sprintf(form+"s", (obs[i]->query_guild_ob())?
                             obs[i]->query_guild_ob():"None");
	  break;
        case ALIGNMENT :
          str += sprintf(form+"s", (obs[i]->query_align_name()));
          break;
        case PLAYERSETALIGNMENT :
          str += sprintf(form+"s", (obs[i]->query_playerset_alname()));
          break;
      }
    } /* for j... */
  ret += sprintf("%s\n", str);
 } /* i */
ret = implode(sort_array(explode(ret, "\n"), 1), "\n");
 ret = ret = sprintf("%s\n", create_title(format)) + ret;
this_player()->more_string(ret);
} /* print_entrys() */

int do_people(string str) 
  {
  mixed *bing;
  object *obs;

  bing = (mixed *)this_player()->query_property("people list");
  if (!bing)
    bing = P_DEFAULT;
  obs = get_people(str);
  if (!sizeof(obs)) 
    {
    notify_fail("Nobody seems to start with "+str+", sorry.\n");
    return 0;
  }
  print_entrys(obs, bing);
  return 1;
} /* do_people() */

int do_terms(string str) {
  mixed *bing;
  object *obs;

  bing = (mixed *)this_player()->query_property("term list");
  if (!bing)
    bing = T_DEFAULT;
  obs = get_people(str);
  if (!sizeof(obs)) {
    notify_fail("Nobody seems to start with "+str+", sorry.\n");
    return 0;
  }
  print_entrys(obs, bing);
  return 1;
} /* do_terms() */

int do_dirs(string str) {
  mixed *bing;
  object *obs;

  bing = (mixed *)this_player()->query_property("dir list");
  if (!bing)
    bing = D_DEFAULT;
  obs = get_people(str);
  if (!sizeof(obs)) {
    notify_fail("Nobody seems to start with "+str+", sorry.\n");
    return 0;
  }
  print_entrys(obs, bing);
  return 1;
} /* do_dirs() */

int do_netstat(string str) {
  mixed *bing;
  object *obs;

  bing = (mixed *)this_player()->query_property("netstat list");
  if (!bing)
    bing = N_DEFAULT;
  obs = get_people(str);
  if (!sizeof(obs)) {
    notify_fail("Nobody seems to start with "+str+", sorry.\n");
    return 0;
  }
  print_entrys(obs, bing);
  return 1;
} /* do_dirs() */

int do_qpeople(string str) {
  mixed *bing;
  object *obs;

  bing = (mixed *)this_player()->query_property("qpeople list");
  if (!bing)
    bing = QP_DEFAULT;
  obs = get_people(str);
  if (!sizeof(obs)) {
    notify_fail("Nobody seems to start with "+str+", sorry.\n");
    return 0;
  }
  print_entrys(obs, bing);
  return 1;
} /* do_qpeople() */

int review() {
  mixed *bing;

  bing = (mixed *)this_player()->query_property("people list");
  if (!bing)
    bing = P_DEFAULT;
  write("People : "+review_thingy(bing)+"\n");
  bing = (mixed *)this_player()->query_property("qpeople list");
  if (!bing)
    bing = QP_DEFAULT;
  write("Qpeople: "+review_thingy(bing)+"\n");
  bing = (mixed *)this_player()->query_property("netstat list");
  if (!bing)
    bing = N_DEFAULT;
  write("Netstat: "+review_thingy(bing)+"\n");
  bing = (mixed *)this_player()->query_property("term list");
  if (!bing)
    bing = T_DEFAULT;
  write("Terms  : "+review_thingy(bing)+"\n");
  bing = (mixed *)this_player()->query_property("dir list");
  if (!bing)
    bing = D_DEFAULT;
  write("Dirs   : "+review_thingy(bing)+"\n");
} /* review() */

mixed *create_review(string str) {
  string *bits, rest;
  int i, bing, width, tmp;
  mixed *ret;

  bits = explode("$"+str, "%");
  bits[0] = bits[0][1..1000];
  if (!strlen(bits[0]))
    ret = ({ });
  else
    ret = ({ STRING, bits[0] });
  for (i=1;i<sizeof(bits);i++) {
    bing = RIGHT;
    rest = bits[i];
    if (rest[0] == '|') {
      bing = CENTER;
      rest = rest[1..1000];
    } else if (rest[0] == '-') {
      bing = 0;
      rest = rest[1..1000];
    }
    if (sscanf(rest, "%d%s", width, rest) == 2) {
      tmp = member_array(rest[0..0], abbrev);
      if (tmp == -1) {
        write("Unknown thingy '"+rest[0..0]+"'\n");
        return 0;
      }
      ret += ({ tmp+bing, width });
      rest = rest[1..1000];
      if (strlen(rest))
        ret += ({ STRING, rest });
    } else {
      ret += ({ STRING, bits[i] });
    }
  }
  return ret;
} /* create_review() */

void list_matches() {
  int i;

  for (i=0;i<sizeof(de_names);i++) {
    if (i == STRING) continue;
    write(abbrev[i]+": "+de_names[i]+"\n");
  }
} /* list_matches() */

int set_var(string str) {
  string name, type;
  mixed *bing;

  if (sscanf(str, "%s %s", name, type) != 2) {
    notify_fail("Syntax: "+query_verb()+" <var_name> <value>\n"+
                "        "+query_verb()+" help\n");
    return 0;
  }
  if (str == "help") {
    write("The non helpful help.\nThis is the list of things that go after "+
          "the %'s in the value.\n");
    list_matches();
    return 1;
  }
  if (member_array(name, var_names) == -1) {
    notify_fail("You cannot set the var "+name+" has to be one of "+
                implode(var_names, ", ")+".\n");
    return 0;
  }
  bing = create_review(type);
  if (!bing)
    return 1;
  this_player()->add_property(name+" list", bing);
  write("Ok, set var "+name+" to "+type+".\n");
  return 1;
} /* set_var() */
