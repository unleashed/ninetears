#include "udp.h"
/*
 * Support.  Do we support this protocol?
 */
void incoming_request(mapping info) {
  if (stringp(info["NAME"]) && stringp(info["PORTUDP"])) {
    if (info["NAME"] == mud_name())
      return ;
    if (!NAMESERVER_CD->query_mud_info(info["NAME"]))
      PING_Q->send_ping_q(info["HOSTADDRESS"], info["PORTUDP"]);
    if (!info["PARAM"]) info["PARAM"] = "";
    if (file_size(UDP_PATH+info["CMD"]+".c") <= 0 ||
        (strlen(info["PARAM"]) &&
         call_other(UDP_PATH+info["CMD"], "support_"+info["PARAM"]))) {
      if (!info["PARAM"]) info["PARAM"] = "";
      NAMESERVER_CD->send_udp(info["HOSTADDRESS"], info["PORTUDP"],
                            "@@@"+UDP_SUPPORT_A+
                            "||NAME:"+mud_name()+
                            "||PORTUDP:"+NAMESERVER_CD->query_my_port()+
                            "||CMD:"+info["CMD"]+
                            (strlen(info["PARAM"])?"||PARAM:"+info["PARAM"]:"")+
                            "||NOTSUPPORTED:yes"+
                            "||ANSWERID:"+info["ANSWERID"]+
                            "@@@\n");
    } else
      NAMESERVER_CD->send_udp(info["HOSTADDRESS"], info["PORTUDP"],
                            "@@@"+UDP_SUPPORT_A+
                            "||NAME:"+mud_name()+
                            "||PORTUDP:"+NAMESERVER_CD->query_my_port()+
                            "||CMD:"+info["CMD"]+
                            (strlen(info["PARAM"])?"||PARAM:"+info["PARAM"]:"")+
                            "||SUPPORTED:yes"+
                            "||ANSWERID:"+info["ANSWERID"]+
                            "@@@\n");
  }
} /* incoming_request() */

void send_support_q(string host, mixed port, string cmd, string param) {
  if (!param)
    param = "";

  tell_object(find_player("pinkfish"), "Got here...\n");
  NAMESERVER_CD->send_udp(host, port, "@@@"+UDP_SUPPORT_Q+
                             "||NAME:"+mud_name()+
                             "||PORTUDP:"+NAMESERVER_CD->query_my_port()+
                             "||CMD:"+cmd+
                             (strlen(param)?"||PARAM:"+param:"")+
                             "||ANSWERID:"+this_player()->query_name()+
                             "@@@\n");
} /* send_support_q() */

void create() {
  seteuid(getuid());
} /* create() */
