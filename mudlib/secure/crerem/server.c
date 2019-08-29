
/*    /lib/server.c
 *    from the Nightmare IV LPC Library
 *    a TCP server object
 *    created by Descartes of Borg 950429
 *    modified by Dyraen@Rod to suite Rod.
 */

#include "socket.h"
#include "socket_errors.h"
#include "server.h"

private static int DestructOnClose;
private static function Read;
private static mapping Listen;
private static mapping Sockets;

static void create() {
    Sockets = ([]);
}

/** Dyraen@Rod - Had to use mappings instead of 'class server' **/
mapping createClassServer() {
    return ([ "Descriptor" : 0,
              "Blocking" : 0,
              "Closing" : 0,
              "Buffer" : ({ }),
             ]);
}

int eventCreateSocket(int port) {
    int x;
    Listen = createClassServer();
    x = socket_create(STREAM, "eventServerReadCallback",
                      "eventServerAbortCallback");
    if( x < 0 ) {
        eventSocketError("Error in socket_create().", x);
        return x;
    }
    Listen["Descriptor"] = x;
    x = socket_bind(Listen["Descriptor"], port);
    if( x != EESUCCESS ) {
        eventClose(Listen);
        eventSocketError("Error in socket_bind().", x);
        return x;
    }
    x = socket_listen(Listen["Descriptor"], "eventServerListenCallback");
    if( x != EESUCCESS ) {
        eventClose(Listen);
        eventSocketError("Error in socket_listen().", x);
        return x;
    }
}

static void eventServerListenCallback(int fd) {
    int x;
    x = socket_accept(fd, "eventServerReadCallback",
                      "eventServerWriteCallback");
    if( x < 0 ) {
        eventSocketError("Error in socket_accept().", x);
        return;
    }
    eventNewConnection(x);
}

static void eventServerAbortCallback(int fd) {
    if( Listen && Listen["Descriptor"] == fd) eventClose(Listen);
    else if( Sockets[fd] ) eventClose(Sockets[fd]);
}

static void eventServerReadCallback(int fd, string str) {
    if( functionp(Read) ) evaluate(Read, fd, str);
    else eventRead(fd, str);
}

static void eventRead(int fd, string str) { }

static void eventServerWriteCallback(int fd) {
    mapping sock;
    int x;
    if( Listen && Listen["Descriptor"] == fd ) sock = Listen;
    else if( Sockets[fd] ) sock = Sockets[fd];
    else return;
    sock["Blocking"] = 0;
    if( !sock["Buffer"] && sock["Closing"] ) {
        return;
    }
    x = EESUCCESS;
    while( sock["Buffer"] && x == EESUCCESS ) {
        switch( x = socket_write(sock["Descriptor"], sock["Buffer"][0]) ) {
            case EESUCCESS:
                break;
            case EECALLBACK:
                sock["Blocking"] = 1;
                break;
            case EEWOULDBLOCK:
                call_out( (: eventServerWriteCallback :), 0, fd);
                return;
            case EEALREADY:
                sock["Blocking"] = 1;
                return;
            default:
                eventClose(sock);
                eventSocketError("Error in socket_write().", x);
                return;
        }
        if( sizeof(sock["Buffer"]) == 1 ) {
            sock["Buffer"] = 0;
            if( sock["Closing"] && !sock["Blocking"] ) eventClose(sock);
        }
        else sock["Buffer"] = sock["Buffer"][1..];
    }
}

varargs void eventWrite(int fd, string str, int close) {
    mapping sock;
    int x;
    if( Listen && Listen["Descriptor"] == fd ) sock = Listen;
    else if( Sockets[fd] ) sock = Sockets[fd];
    else return;
    if( sock["Buffer"] ) sock["Buffer"] += ({ str });
    else sock["Buffer"] = ({ str });
    sock["Closing"] = close;
    if( sock["Blocking"] ) return;
    else eventServerWriteCallback(sock["Descriptor"]);
}

static void eventClose(mapping sock) {
    if( !sock ) return;
    if( Sockets[sock["Descriptor"]] ) map_delete(Sockets, sock["Descriptor"]);
    socket_close(sock["Descriptor"]);
    eventSocketClosed(sock["Descriptor"]);
    sock = 0;
    if( DestructOnClose && sock == Listen ) dest_me();
}

static void eventSocketClosed(int fd) { }

int dest_me() {
    eventClose(Listen);
    destruct(this_object());
    return !this_object();
}

static void eventNewConnection(int fd) {
    Sockets[fd] = createClassServer();
    (Sockets[fd])["Descriptor"] = fd;
    (Sockets[fd])["Blocking"] = 0;
}

static void eventSocketError(string str, int x) { }

function SetRead(function f) { return (Read = f); }

int SetDestructOnClose(int x) { return (DestructOnClose = x); }


