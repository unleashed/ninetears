#include "udp.h"
#include "socket.h"
#include "inet.h"
/*
 * This has the list of cd muds that are known.  We get this from the
 * mudlist server when we boot.
 * 
 * Revision: Modified to send shutdown packets by Turrican 17-1-1995
 *           Credits to Wodan for adding the possibility to talk to muds with 
 *           spaces in their name.
 */

object monitor;
mapping known_muds;
mapping stats;
int stats_on;
int my_port, my_socket;
string my_addr;
string my_host;

void create() {
  stats = ([ ]);
  known_muds = ([ ]);
  seteuid(getuid());
  call_out("send_startup_udp", 2);
  call_out("do_pings", 3*60);
} /* create() */

void send_startup_udp() {
  NAMESERVER->lookup_service("cd-udp", lower_case(mud_name()), "finish_lookup");
} /* send_startup_udp() */

void send_shutdown_udp() {
  int i;
  string *muds;

  muds=keys(known_muds);
  for (i=0;i<sizeof(muds);i++) {
    reset_eval_cost();
    if (!mapp(known_muds[muds[i]]))
      continue;
    this_object()->send_udp(known_muds[muds[i]]["HOSTADDRESS"],
                            known_muds[muds[i]]["PORTUDP"],
                            "@@@"+UDP_SHUTDOWN+
                            "||NAME:"+mud_name()+
                            "||PORTUDP:"+my_port+
                            "@@@\n");
  }
}

void do_pings() {
  int i;
  string *muds, ping_packet;

  call_out("do_pings", 60*60);

/* Get rid of our entry from this list just in case it exists */
  map_delete(known_muds, capitalize(mud_name()));

/* Both to keep us alive in tehir arrays and to check on dead muds. */
  muds = keys(known_muds);
  for (i=0;i<sizeof(muds);i++) {
    if (!mapp(known_muds[muds[i]]))
      continue;
    known_muds[muds[i]][UDP_NO_CONTACT] = known_muds[muds[i]][UDP_NO_CONTACT]+1;
    PING_Q->send_ping_q(known_muds[muds[i]]["HOSTADDRESS"],
                        known_muds[muds[i]]["PORTUDP"]);
    if (known_muds[muds[i]][UDP_NO_CONTACT] >= MAX_RETRYS) {
      map_delete(known_muds, muds[i]);
    }
  }
} /* do_pings() */

void finish_lookup(string service, string addr, int port, mixed *args) {
  string host;
  int dport, i;
  mixed *muds;

  my_port = port;
  my_addr = addr;
  muds = MUDLIST_UDP;
  for (i=0;i<sizeof(muds);i+=2) {
    this_object()->send_udp(muds[i], muds[i+1], "@@@"+UDP_STARTUP+
                                         this_object()->start_message()+
                                         "@@@\n");
    (UDP_PATH+"mudlist_q")->send_mudlist_q(muds[i], muds[i+1]);
  }
  if (!my_socket) {
    my_socket = socket_create(DATAGRAM, "read_callback", "close_callback");
    if (my_socket < 0)
      return ;
    if (socket_bind(my_socket, port) <= 0)
      socket_close(my_socket);
  }
} /* finish_lookup() */

string start_message() {
  return "||NAME:"+capitalize(mud_name())+
         "||VERSION:10.10"+
         "||MUDLIB:Discworld"+
         "||HOST:"+query_host_name()+
         "||PORT:4001"+
         "||DRIVER:"+__VERSION__+
         "||TCP:some"+
         "||PORTUDP:"+my_port+
         "||TIME:"+ctime(time());
} /* start_message() */

void send_udp(string host, int port, string msg) {
  int sock;

  if (host == my_addr)
    return ;
  if (monitor)
    tell_object(monitor, "Sending "+msg);
  if (host == my_host) {
/* Sending to ourselves!  Arggghh */
    return ;
  }
  sock = socket_create(DATAGRAM, "read_callback", "close_callback");
  if (sock < 0) {
    log_file("NAMESERVER", "Failed to open socket to "+host+" "+port+"\n");
    return ;
  }
  socket_write(sock, msg, host+" "+port);
  socket_close(sock);
} /* send_udp() */

void read_callback(int sock, string msg, string addr) {
  string func, rest, *bits, name, arg;
  mapping args;
  int i;

  if (monitor)
    tell_object(monitor, "Got "+msg);
  if (!sscanf(msg, "@@@%s||%s@@@%*s", func, rest)) {
    if (!sscanf(msg, "@@@%s@@@%*s", func)) {
      return ;
    }
    rest = "";
  }

/*
 * We don't want to know about packets we are aciently looping back
 * on ourselves.
 */
  sscanf(addr, "%s %*s", addr);
  if (addr == my_addr)
    return ;

  if (!stringp(rest)) return ;
  bits = explode(rest, "||");
  args = ([ ]);
  for (i=0;i<sizeof(bits);i++) {
    if (stringp(bits[i]) && sscanf(bits[i], "%s:%s", name, arg) == 2) {
      args[name] = arg;
    }
  }

  args["HOSTADDRESS"] = addr;
  if (mapp(known_muds[args["NAME"]]))
    known_muds[args["NAME"]][UDP_NO_CONTACT] = 0;

  if (stats_on) {
    stats[addr] ++;
    stats[args["NAME"]] ++;
    stats[func] ++;
  }
/* Ok, now we need to lookup the command and execute it... */
  // if (file_size(UDP_PATH+func+".c") > 0)
    catch((UDP_PATH+func)->incoming_request(args));
/* Otherwise, we just ignore it... */
} /* read_callback() */

mapping query_known_muds() { return known_muds + ([ ]); }

void set_mud_info(string name, mapping junk) { 
  if (previous_object() != this_object() &&
      file_name(previous_object())[0..strlen(UDP_PATH)-1] != UDP_PATH)
    return ;
/* Hm...sure this should be HERE ? */
  if (!known_muds[name]) {
/* Send them a mudlist query...
    (UDP_PATH+"mudlist_q")->send_mudlist_q(junk["HOSTADDRESS"],
                                          junk["PORTUDP"]); */
    this_object()->send_udp(junk["HOSTADDRESS"],
                            junk["PORTUDP"], "@@@"+UDP_PING_Q+
                            "||NAME:"+mud_name()+
                            "||PORTUDP:"+my_port+
                            "@@@\n");
  }
  known_muds[replace(name, " ", ".")] = name;
  known_muds[name] = junk;
  if (lower_case(name) != name) {
    known_muds[replace(lower_case(name), " ", ".")] = name;
    known_muds[lower_case(name)] = name;
  }
} /* set_mud_info() */

void zap_mud_info(string name, mapping junk) { 
  if (previous_object() != this_object() &&
      file_name(previous_object())[0..strlen(UDP_PATH)-1] != UDP_PATH)
    return ;
  map_delete(known_muds, name);
} /* zap_mud_info() */

mapping query_mud_info(string name) {
  mixed bing;

  bing = known_muds[name];
  if (stringp(bing))
    return known_muds[bing];
  return bing;
} /* query_mud_info() */

int query_my_port() { return my_port; }

void set_monitor(object ob) { monitor = ob; }
object query_monitor() { return monitor; }

void set_stats(int flag) { stats_on = flag; }
int query_stats_o() { return stats_on; }

void reset_stats() { stats = ([ ]); }
mapping query_stats() { return stats; }
