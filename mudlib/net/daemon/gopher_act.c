/*
 * This will talk to gophers and get the menu stuff back in a nice
 * format for you.
 *
 * You send it the field to look up, the host to goto and the port to
 * look at, the function to call back on you, and optionaly the
 * search text...
 */
#include "gopher.h"
#include "socket.h"
#include "mudlib.h"

mapping in_progress,
        number_name;
#ifdef GOPHER_PORT
string our_path;
int our_socket;
string tack_on_mess;

void setup_gopher(int port, string path);
#endif
int *closes;
void finish_lookup(string host, string number);

void create() {
  in_progress = ([ ]);
  number_name = ([ ]);
  closes = ({ });
#ifdef GOPHER_PORT
  call_out("setup_gopher", 2, ({ GOPHER_PORT, GOPHER_PATH }));
#endif
} /* create() */

void do_connect(int type, string name, string host, string port, string func,
                string search_text) {
  if (!in_progress[host]) {
    in_progress[host] = ({ ({ name, port, previous_object(),
                              func, search_text, "", type }) });
    if (number_name[host])
      finish_lookup(host, number_name[host]);
    else
      resolve(host, "finish_lookup");
  } else
    in_progress[host] += ({ ({ name, port, previous_object(),
                               func, search_text, "", type }) });
} /* do_connect() */

string query_number_name(string number) { return number_name[number]; }

void do_resolve(string name, string func) {
  if (number_name[name]) {
    call_other(previous_object(), func, name, number_name[name]);
    return ;
  }
  if (!in_progress[name]) {
    in_progress[name] = ({ ({ previous_object(), func }) });
    resolve(name, "finish_lookup");
  } else
    in_progress[name] += ({ ({ previous_object(), func }) });
} /* do_resolve() */

void finish_lookup(string host, string number) {
  int new_fd, ret;
  int i;

/* Make sure we only have one name for each host */
  if (!number_name[number])
    number_name[number] = host;
  number_name[host] = number;
/* We failed to lookup our host... :( */
  if (!number) {
    if (!in_progress[host]) {
      for (i=0;i<sizeof(in_progress[host]);i++)
        if (sizeof(in_progress[host][i]) == 2)
          call_other(in_progress[host][i][0], in_progress[host][i][1],
                     host, number);
        else
          call_other(in_progress[host][i][2], in_progress[host][i][3], 0);
    }
    return ;
  }
/* Ok, now we wanna connect up... */
  for (i=0;i<sizeof(in_progress[host]);i++) {
    if (sizeof(in_progress[host][i]) == 2) {
      call_other(in_progress[host][i][0], in_progress[host][i][1],
                 host, number);
      map_delete(in_progress, host);
      continue;
    }
    new_fd = socket_create(STREAM, "out_read_callback", "out_close_callback");
    if (new_fd < 0) {
      call_other(in_progress[host][i][2], in_progress[host][i][3], 0);
      return ;
    }
    ret = socket_connect(new_fd, number+" "+in_progress[host][i][1],
                         "out_read_callback", "out_write_callback");
    if (ret < 0) {
      call_other(in_progress[host][i][2], in_progress[host][i][3], 0,
                 in_progress[host][i][0..4]);
      map_delete(in_progress, host);
      return ;
    }
    remove_call_out("do_closes");
    call_out("do_closes", 120);
    closes += ({ new_fd });
    in_progress[new_fd] = in_progress[host][i];
/*
    if (in_progress[host][i][4])
      socket_write(new_fd, sprintf("%s\t%s\n", in_progress[host][i][0],
                                               in_progress[host][i][4]));
    else
      socket_write(new_fd, sprintf("%s\n", in_progress[host][i][0]));
 */
  }
  map_delete(in_progress, host);
} /* finish_lookup() */

void out_write_callback(int fd) {
  string str;

  if (in_progress[fd][4])
    socket_write(fd, (str = sprintf("%s\t%s\n", in_progress[fd][0],
                                             in_progress[fd][4])));
  else
    socket_write(fd, (str = sprintf("%s\n", in_progress[fd][0])));
} /* out_write_callback() */

void out_read_callback(int fd, string mess) {
  if (!in_progress[fd]) {
/* Hmmmmmm. */
    socket_close(fd);
    return ;
  }
  in_progress[fd][5] += replace_string(mess, "\r", "");
} /* out_read_callback() */

void out_close_callback(int fd) {
  string *bits, *bb;
  int i;
  mixed *ret;

  socket_close(fd);
  if (!in_progress[fd]) return ;
  if (in_progress[fd][0] == "")
    in_progress[fd][0] = "1";
  switch (in_progress[fd][6]) {
    case MENU :
    case SEARCH :
      bits = explode(in_progress[fd][5], "\n");
      ret = ({ });
      for (i=0;i<sizeof(bits);i++) {
        bb = explode(bits[i][1..10000], "\t");
        switch (bits[i][0]) {
          case '1' :
/* Menu...  */
            ret += ({ ({ MENU, bb }) });
            break;
          case '0' :
            ret += ({ ({ FILE, bb }) });
            break;
          case '7' :
            ret += ({ ({ SEARCH, bb }) });
            break;
        }
      }
      catch(call_other(in_progress[fd][2], in_progress[fd][3], ret,
                 in_progress[fd][0..4]));
      break;
    case FILE :
      in_progress[fd][5] = in_progress[fd][5][0..strlen(in_progress[fd][5])-3];
      catch(call_other(in_progress[fd][2], in_progress[fd][3],
                       in_progress[fd][5], in_progress[fd][0..4]));
      break;
  }
  map_delete(in_progress, fd);
  closes = closes - ({ fd });
} /* out_close_callback() */

void do_closes() {
  int i, *tmp;

  tmp = closes + ({ });
  for (i=0;i<sizeof(tmp);i++)
    out_close_callback(tmp[i]);
} /* do_closes() */

/* From here on down is the gopher server code. */
#ifdef GOPHER_PORT
void setup_gopher(mixed port, string path) {
  if (pointerp(port)) {
    path = port[1];
    port = port[0];
  }
  our_path = path;
  our_socket = socket_create(STREAM, "in_read_callback", "in_close_callback");
  if (our_socket < 0) {
    return ;
  }
  if (socket_bind(our_socket, port) < 0) {
    socket_close(our_socket);
    call_out("setup_gopher", 120, ({ port, path }));
    return ;
  }
  if (socket_listen(our_socket, "in_listen_callback") < 0) {
    return ;
  }
} /* setup_gopher() */

void in_listen_callback(int fd) {
  int new_fd;

  if ((new_fd = socket_accept(fd, "in_read_callback", "in_write_callback")) < 0) {
    return ;
  }
  call_out("in_close_callback", 120, new_fd);
} /* in_listen_callback() */

string create_menu(string path) {
  string *bing, ret, fn, rest, tmp, new_p, name;
  int i, len, type;

  bing = get_dir(our_path+path);
  ret = "";
  for (i=0;i<sizeof(bing);i++)
    if (file_size(our_path+path+bing[i]) == -2) {
      if (bing[i][0] != '.')
        ret += sprintf("%c%s\t%s\t%s\t%d\n", '1',
                       replace_string(bing[i], "_", " "),
                       "1"+path+bing[i]+"/", MACHINE_NAME, GOPHER_PORT);
    } else {
/* Allow c files to be . files. */
      if (sscanf(bing[i], "%s.c", tmp)) {
/* If its a file, we do terribly silly things. */
        fn = replace_string(our_path+path+tmp, "//", "/");
        if (fn->query_invisible()) continue;
        type = fn->query_type();
        if (!(rest = fn->query_rest()))
          rest = MACHINE_NAME+"\t"+GOPHER_PORT;
        if (!(new_p = fn->query_path())) {
          new_p = sprintf("%c:exec:%s", type, path+bing[i]);
          if (!(name = fn->query_arg()))
            new_p += ":";
          else
            new_p += ":"+name;
        }
        if (!(name = fn->query_name()))
          name = replace_string(tmp, "_", " ");
        ret += sprintf("%c%s\t%s\t%s\n", type, name, new_p, rest);
      } else if (bing[i][0] != '.')
        ret += sprintf("%c%s\t%s\t%s\t%d\n", '0',
                       replace_string(bing[i], "_", " "),
                       "0"+path+bing[i], MACHINE_NAME, GOPHER_PORT);
    }
  return ret;
} /* create_menu() */

int check_path(string str) {
  if (sizeof(explode(str, "..")) > 1)
    return 0;
  return 1;
} /* check_path() */

void in_read_callback(int fd, string str) {
  int type;
  string path, *bits, arg, s1, s2;

  if (!in_progress[fd])
    in_progress[fd] = str;
  else
    in_progress[fd] += str;
  if (sscanf(str, "%s\n%s", s1, s2) != 2) {
/* We have to queue the damn thing... */
    return ;
  }
  str = in_progress[fd];
  map_delete(in_progress, fd);
  str = replace_string(str, "\n", "");
  str = replace_string(str, "\r", "");
  if (str == "" || str == "1") {
/* Root dir... */
    if (tack_on_mess) {
      socket_write(fd, create_menu("/")+tack_on_mess+".\n");
      tack_on_mess = 0;
    } else
      socket_write(fd, create_menu("/")+".\n");
/* I hope it does flushing... */
    socket_close(fd);
    return ;
  }
  if (sscanf(str, "%d:exec:%s", type, path) == 2) {
/* For use with the search facility */
    bits = explode(path, "\t");
    sscanf(bits[0], "%s:%s", bits[0], arg);
    bits[0] = our_path+bits[0];
    if (check_path(bits[0])) {/* Not allowed to have ..'s...  */
      bits[0] = replace_string(bits[0], "//", "/");
      if (type != 0 && tack_on_mess) {
        socket_write(fd, bits[0]->do_gopher(bits, arg, fd)+tack_on_mess+".\n");
        tack_on_mess = 0;
      } else
        socket_write(fd, bits[0]->do_gopher(bits, arg, fd)+".\n");
    } else {
      switch (type) {
        case 1 :
        case 7 :
          if (tack_on_mess) {
            socket_write(fd, "0Big nasty error\t0/error.error\t"+
                             "error.host\t70\n"+
                             "1Root menu\t\t"+MACHINE_NAME+"\t"+GOPHER_PORT+
                             "\n"+tack_on_mess+".\n");
            tack_on_mess = 0;
          } else
            socket_write(fd, "0Big nasty error\t0/error.error\t"+
                             "error.host\t70\n"+
                             "1Root menu\t\t"+MACHINE_NAME+"\t"+GOPHER_PORT+
                             "\n.\n");
          break;
        case 0 :
          socket_write(fd, "You have just encountered an error, "+
                           "lucky you.\n.\n");
          break;
      }
    }
    socket_close(fd);
    return ;
  }
  sscanf(str, "%d/%s", type, path);
  if (!path || !check_path(str)) {
    switch (type) {
      case 1 :
      case 7 :
        if (tack_on_mess) {
          socket_write(fd, "0Big nasty error\t0/error.error\terror.host\t70\n"+
                         "1Root menu\t\t"+MACHINE_NAME+"\t"+GOPHER_PORT+
                         "\n"+tack_on_mess+".\n");
          tack_on_mess = 0;
        } else
          socket_write(fd, "0Big nasty error\t0/error.error\terror.host\t70\n"+
                         "1Root menu\t\t"+MACHINE_NAME+"\t"+GOPHER_PORT+
                         "\n.\n");
        break;
      case 0 :
        socket_write(fd, "You have just encountered an error, "+
                         "lucky you.\n.\n");
        break;
    }
    socket_close(fd);
    return ;
  }
  path = "/"+path;
  switch (type) {
    case 0 :
/* Grab the file and give it to them. */
      str = read_file(our_path+path);
      if (!str) {
        str = "File requested was not found!  Oh no!  Find a hose clamp.\n";
      } else if (str[0] == '.') {
#ifdef NROFF_HAND
        NROFF_HAND->create_nroff(our_path+path, "/tmp/gopher");
        str = NROFF_HAND->cat_file("/tmp/gopher");
        rm("/tmp/gopher");
#endif
      }
      socket_write(fd, str+"\n.\n");
      break;
    case 1 :
      if (tack_on_mess) {
        socket_write(fd, create_menu(path)+tack_on_mess+".\n");
        tack_on_mess = 0;
      } else
        socket_write(fd, create_menu(path)+".\n");
      break;
  }
  socket_close(fd);
} /* in_read_callback() */

void in_close_callback(int fd) {
  socket_close(fd);
} /* in_close_callback() */
#endif /* GOPHER_PORT */

void set_tack_on_mess(string mess) { tack_on_mess = mess; }
string query_tack_on_mess() { return tack_on_mess; }
