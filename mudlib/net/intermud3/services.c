/*    /daemon/services.c
 *    from the Nightmare IV LPC Library
 *    handles intermud services
 *    created by Descartes of Borg 950523
 *    modified for the Discworld mudlib by Turrican 25-10-95
 */

#ifndef __PACKAGE_SOCKETS__
#error You should not try to load /daemon/services.c without the sockets package
#else

#include <network.h>

mapping GetServices();

void create() {
  seteuid(getuid());
}

#include "/net/intermud3/services/channel.c"
#include "/net/intermud3/services/emoteto.c"
#include "/net/intermud3/services/error.c"
#include "/net/intermud3/services/finger.c"
#include "/net/intermud3/services/locate.c"
#include "/net/intermud3/services/tell.c"
#include "/net/intermud3/services/who.c"

mapping GetServices() {
    return ([
#ifdef whatsthis
	     "amcp" : "1.1",
#endif
#ifdef SERVICE_AUTH
	     "auth" : 1,
#endif
#ifdef SERVICE_CHANNEL
	     "channel" : 1,
#endif
#ifdef SERVICE_EMOTETO
	     "emoteto" : 1,
#endif
#ifdef SERVICE_FILE
	     "file" : 1,
#endif
#ifdef SERVICE_FINGER
	     "finger" : 1,
#endif
#ifdef SERVICE_LOCATE
	     "locate" : 1,
#endif
#ifdef SERVICE_MAIL
	     "mail" : 1,
#endif
#ifdef SERVICE_NEWS
	     "news" : 1,
#endif
#ifdef SERVICE_TELL
	     "tell" : 1,
#endif
#ifdef SERVICE_UCACHE
	     "ucache" : 1,
#endif
#ifdef SERVICE_WHO
	     "who" : 1,
#endif
#ifdef FTP_PORT
	     "ftp" : FTP_PORT,
#endif
#ifdef HTTP_PORT
	     "http" : HTTP_PORT,
#endif
#ifdef NNTP_PORT
	     "nntp" : NNTP_PORT,
#endif
#ifdef PORT_RCP
	     "rcp" : PORT_RCP,
#endif
#ifdef PORT_SMTP
	     "smtp" : PORT_SMTP,
#endif
	     ]);
}

void eventShutdown(int secs) {
  if (file_name(previous_object()) != "/obj/shut")
    return;
  INTERMUD_D->eventWrite( ({ "shutdown", 5, mud_name(), 0, 
      INTERMUD_D->GetNameserver(), 0, secs }) );
}

#endif /* __PACKAGE_SOCKETS__ */
