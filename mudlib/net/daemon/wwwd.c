/*
 * This will handle all world wide web thing a me jigs.
 */
#include "www.h"
#include "socket.h"
#include "globals.h"

#undef D_DEBUG

#ifdef D_DEBUG
#define TP(STR) if (find_player("pinkfish")) tell_object(find_player("pinkfish"), STR)
#else
#define TP(STR)
#endif

mapping in_progress,
        number_name;
string our_path;
int our_socket;
string tack_on_mess;

void setup_www(int port, string path);
int *closes;
void finish_lookup(string host, string number);

void create() {
  seteuid(getuid());
  in_progress = ([ ]);
  number_name = ([ ]);
  closes = ({ });
  call_out("setup_www", 2, ({ WWW_PORT, WWW_PATH }));
} /* create() */

/* From here on down is the gopher server code. */
void setup_www(mixed port, string path) {
  int ret;

  if (pointerp(port)) {
    path = port[1];
    port = port[0];
  }
  TP(sprintf("%O, %O\n", port, path));
  our_path = path;
  our_socket = socket_create(STREAM, "in_read_callback", "in_close_callback");
  if (our_socket < 0) {
    TP("Failed to create socket.\n");
    return ;
  }
  if ((ret = socket_bind(our_socket, port)) < 0) {
    TP(sprintf("Failed to bind socket. (%d)\n", ret));
    socket_close(our_socket);
    call_out("setup_www", 120, ({ port, path }));
    return ;
  }
  if (socket_listen(our_socket, "in_listen_callback") < 0) {
    TP("Failed to listen to socket.\n");
    return ;
  }
} /* setup_www() */

void in_listen_callback(int fd) {
  int new_fd;

  if ((new_fd = socket_accept(fd, "in_read_callback", "in_write_callback")) < 0) {
    return ;
  }
  call_out("in_close_callback", 120, new_fd);
} /* in_listen_callback() */

string create_page(string input) {
  string *bits, *blue, page;

  bits = explode(input, " ");
  if (bits[0] == "GET") {
/* We wants to get something. */
    blue = explode(bits[1], "?");
    if (sizeof(blue) == 1)
      blue += ({ "" });
    blue[1] = implode(blue[1..10000], "?");
    if (blue[0] == "/")
      blue[0] = "/index.html";
TP("Finding page "+blue[0]+"\n");
    if (file_size(WWW_PATH+blue[0]+".c") > 0) {
      catch(page = ((WWW_PATH+blue[0])->create_page(blue[1])));
    } else {
      page = read_file(WWW_PATH+blue[0]);
    }
    if (page)
      page = replace_string(page, "MY_HOSTPATH", MY_HOSTPATH);
  }
  if (!page) {
    page = "<htmf><head><title>Error message</title></head><body><h1>Failed www ";
    page += "page</h1>Page = http:"+MY_HOSTPATH+"/"+bits[1];
    page += "<p></body></htmf>";
  }
  return page;
} /* create_page() */

void in_read_callback(int fd, string str) {
  int type;
  string path, *bits, arg, s1, s2, page;

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
  page = create_page(str);
TP("Page: "+page+"\n");
  if (socket_write(fd, page) < 0) {
    TP("Errorr!\n");
  }
  socket_close(fd);
} /* in_read_callback() */

void in_close_callback(int fd) {
  socket_close(fd);
} /* in_close_callback() */

void set_tack_on_mess(string mess) { tack_on_mess = mess; }
string query_tack_on_mess() { return tack_on_mess; }
