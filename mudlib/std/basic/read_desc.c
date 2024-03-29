inherit "/std/basic/desc";
#include "language.h"

nosave mixed *read_mess;
nosave int max_size,cur_size;


void create() {
    ::create();
    max_size = 100;
    cur_size = 0;
    }

mixed add_read_mess(string str, string type, string lang, int size);

void set_max_size(int siz) { max_size = siz; }
int query_max_size() { return max_size; }

void set_cur_size(int siz) { cur_size = siz; }
int query_cur_size() { return cur_size; }

void add_read_this(object ob) {
    ob->add_command("leer", this_object());
    }

varargs void set_read_mess(mixed str, string lang, int size) { 
    if (pointerp(str)) {
	read_mess = str;
	return ;
	}
    if (!read_mess && str && environment()) {
	filter_array(all_inventory(environment()), "add_read_this", this_object());
	add_action("do_leer","leer");
	}
    if (!lang) lang = "comun";
    if (!size) size = 1;
    if (str) {
	read_mess = ({ ({ str, 0, lang, size }) });
	} 
    else read_mess = 0; 
    }

string *query_read_mess() { return read_mess; }

mixed add_read_mess(mixed str, string type, string lang, int size) { 
    int de_size;

    if (cur_size >= max_size) return "";
    if (!size) size = 1;
    if (!read_mess && environment()) {
	filter_array(all_inventory(environment()), "add_read_this", this_object());
	add_action("do_leer","leer");
	}
    de_size = size*((int)LANGUAGE_HAND->query_language_size(lang, str));
    if (cur_size+de_size > max_size) {
	str = (string)LANGUAGE_HAND->squidge_text(lang, str,(max_size-cur_size)/size);
	if (!strlen(str)) return ;
	cur_size += size*((int)LANGUAGE_HAND->query_language_size(lang, str));
	}
    if (!read_mess) read_mess = ({ ({ str, type, lang, size }) });
    else read_mess += ({ ({ str, type, lang, size }) });
    return str;
    }

int remove_read_mess(string str, string type, string lang) {
    int i;

    for (i=0;i<sizeof(read_mess);i++) {
	if (str && read_mess[i][READ_STR] != str) continue;
	if (type && read_mess[i][READ_TYPE] != type) continue;
	if (lang && read_mess[i][READ_LANG] != lang) continue;
	cur_size -= read_mess[i][READ_SIZE]*((int)LANGUAGE_HAND->query_language_size(lang,read_mess[i][READ_STR]));
	read_mess = delete(read_mess, i, 1);
	return 1;
	}
    return 0;
    }

void init() {
    if (read_mess || sizeof(labels)) add_action("do_leer", "leer");
    }

string create_read_array(object ob) {
    mixed *bing;
    int i;
    string ret;

    bing = (mixed *)ob->query_read_mess();
    ret = "";
    if (!bing || !sizeof(bing)) return "Nada escrito en "+ob->short()+".\n";
    for (i=0;i<sizeof(bing);i++)
    ret += (string)this_player()->read_message(bing[i][READ_STR],
                                               bing[i][READ_TYPE],
                                               bing[i][READ_LANG],
                                               bing[i][READ_SIZE]);
    return ret;
    }

mixed do_leer() {
    string s1, s2, s3, str, str2;
    int i;

    if (!read_mess && !sizeof(labels)) return 0;
    if (read_mess) {
	for (i=0;i<sizeof(read_mess);i++) {
    	    str = read_mess[i][READ_STR];
	    if (stringp(str)) {
    		str2 = "";
    		while (sscanf(str, "%s$$%s$$%s", s1, s2, s3) == 3) {
        	    str2 += s1 + read_file(s2);
        	    str = s3;
    		    }
    		write((string)this_player()->read_message(str2 + str,
                                                  read_mess[i][READ_TYPE],
                                                  read_mess[i][READ_LANG],
                                                  read_mess[i][READ_SIZE]));
    		} 
	    else {
    		write((string)this_player()->read_message(str,
                                                  read_mess[i][READ_TYPE],
                                                  read_mess[i][READ_LANG],
                                                  read_mess[i][READ_SIZE]));
    		}
	    }
	}
    labels = labels - ({ 0 });
    if (sizeof(labels)) {
	str = implode(map_array(labels, "create_read_array", this_object()), "");
	write(str);
	if (!read_mess) if ((s1 = (string)this_object()->query_property("read id"))) return query_multiple_short(labels)+" en "+s1;
        else return query_multiple_short(labels)+" en "+short(0);
	}
    if ((s1 = (string)this_object()->query_property("read id"))) return s1;
    return 1;
    }

mixed do_read() {
  string s1, s2, s3, str, str2;
  int i;

  if (!read_mess && !sizeof(labels)) return 0;
  if (read_mess) {
    for (i=0;i<sizeof(read_mess);i++) {
      str = read_mess[i][READ_STR];
/* Its not a string when we are dealing with magical writing */
      if (stringp(str)) {
        str2 = "";
        while (sscanf(str, "%s$$%s$$%s", s1, s2, s3) == 3) {
          str2 += s1 + read_file(s2);
          str = s3;
        }
        write((string)this_player()->read_message(str2 + str,
                                                  read_mess[i][READ_TYPE],
                                                  read_mess[i][READ_LANG],
                                                  read_mess[i][READ_SIZE]));
      } else {
/* It magic!  She blinded me with science! */
        write((string)this_player()->read_message(str,
                                                  read_mess[i][READ_TYPE],
                                                  read_mess[i][READ_LANG],
                                                  read_mess[i][READ_SIZE]));
      }
    }
  }
/* Ok...  now we stick all the label info in... */
  labels = labels - ({ 0 });
  if (sizeof(labels)) {
    str = implode(map_array(labels, "create_read_array", this_object()), "");
    write(str);
    if (!read_mess)
      if ((s1 = (string)this_object()->query_property("read id")))
        return query_multiple_short(labels)+" en "+s1;
      else
        return query_multiple_short(labels)+" en "+short(0);
  }
  if ((s1 = (string)this_object()->query_property("read id")))
    return s1;
  return 1;
} /* do_read() */

/* Modify the long if we have something written on us */
string long(string str, int dark) {
  if (read_mess)
    return ::long(str)+"Parece que tiene algo escrito.\n";
  return ::long(str, dark);
} /* long() */

/* std/basic/read_desc: */
mixed *query_init_data() {
   return ::query_init_data() +
      ({ "read_mess", read_mess, "set_read_mess/P0/P2/" });
} /* query_init_data() */
