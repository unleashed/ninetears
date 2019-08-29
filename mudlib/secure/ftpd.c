/* /secure/ftpd... */
/*
 * Originaly written by Pinkfish@Discworld.
 *
 * 93-08-22  Bannor@newmoon
 *           - Added DEBUG and LOGGING flags.
 *           - Fixed a problem with sending files larger then 1k.
 *           - Added support for events.
 *           - Added support for finger ftp.
 *           - Fixed security problems that allowed anyone to read/write
 *             to any directory.
 *           - Improved readability (well, I think so anyway)
 *
 * 13-07-94  Pinkfish@Discworld
 *           - Fixed up the handling of new lines.
 *
 * 28-11-94  Pinkfish@Discworld
 *           - Added in binary mode communications.
 * 
 * 26-6-95   Turrican@Discworld
 *           - Fixed binary mode communications.
 *           - Fixed ABOR handling (control characters), and now the data socket
 *             is closed instead of the control socket ;-)
 *           - Fixed the "CWD ~" bug.
 *           - Fixed the STAT and the SIZE command.
 *           - Added "long" listing of ls.
 *           - Made NLST and LIST take arguments like -C, -l.
 *           - Fixed timeout checking.
 *           - Added commands MKD, RMD, RNFR, RNTO, MDTM, DELE, REST,
 *             HELP, and some SITE commands.
 *
 * 19-8-95   Turrican@Discworld
 *           - Fixed login timeout checking.
 *           - Fixed data_write_callback function, it was quite broken.
 *             Sending of double packets should now belong to the past.
 *           - Fixed data_conn function, it violated the flow control model.
 */
#include <ftp.h>
#include <socket.h>
#include <socket_errors.h>
#include <localtime.h>
 
 
 
/*
-----------------------------------------------
   debugging defines.
-----------------------------------------------
*/
#define TP_CRE "asmodean"
 
#undef DEBUG
 
#ifdef DEBUG
 
#define TPX(STR) if (find_player(TP_CRE)) \
                    tell_object(find_player(TP_CRE), STR)
 
#define DEBUG_SEND   /* define to debug data_write_callback() */
 
#else
 
#define TPX(STR)
#undef DEBUG_SEND
 
#endif
 
 
/*
-----------------------------------------------
   log file defines.
-----------------------------------------------
*/
#define LOGGING
 
#ifdef LOGGING
 
#define LOG_CONNECT /* define to log all connections */
#define LOG_FILE    /* define to log all file xfers */
#undef LOG_CD_SIZE /* define to log cd's and file size commands */
 
#else
 
#undef LOG_CONNECT
#undef LOG_FILE
#undef LOG_CD_SIZE
 
#endif
 
#define BLOCK_SIZE 4096

 
/*
-----------------------------------------------
   driver version defines.
-----------------------------------------------
*/
#define NEWDRIVER
 
#ifdef __VERSION__
#define VERSION __VERSION__
#else
#ifndef VERSION
#define VERSION version()
#endif
#endif
 
 
 
#define CHECK_LOGIN() if (!socket_info[fd][LOGGED_IN]) \
                      { \
                        socket_write(fd, "530 Please login with USER and PASS.\r\n"); \
                        break; \
                      }
#define CHECK_CMD(INT) if (sizeof(bits) < INT+1) \
                       { \
                         socket_write(fd, sprintf("500 '%s': command not understood.\r\n", \
                            str)); \
                         break; \
                       }
#define CHECK_PLAYER() if (socket_info[fd][LOGGED_IN] == 2) \
		       { \
                         socket_write(fd, "553 Permission denied (you are not a creator)\r\n"); \
                         break; \
                       }
#define CHECK_STRING socket_info[pfd][TYPE] == STRING
#define UNAME   socket_info[fd][USER_NAME]


#define HOME_DIR(NAME) "/w/"+NAME

 
/*
-----------------------------------------------
    Variables
-----------------------------------------------
*/
 
mapping socket_info;
int our_socket, offset;
string rnfr;
 
 
 
/*
-----------------------------------------------
    Prototypes
-----------------------------------------------
*/
void setup_ftp(int port);
void finish_lookup(string host, string number);
string get_path(int fd, string str);
static void do_update(string name, int fd);
 
mixed *query_connections()
/* returns an array of users connected to ftpd */
{
mixed  *vals;
string *list;
int  count;
 
  list = ({ });
  vals = values(socket_info);
 
  for (count = 0; count < sizeof(vals); count++)
  {
    if (vals[count][USER_NAME]) {
      if (vals[count][LOGGED_IN]) {
        list += ({ capitalize((string)((vals[count])[USER_NAME])) });
      } else {
        list += ({ "login" });
      }
    }
  }
  return list;
 
} /* query_connections() */
 
 
void  create()
{
  seteuid("Root");
  socket_info = ([]);
  rnfr = "";
  offset = 0;
call_out("setup_ftp", 2, FR_FTP_PORT);
  call_out("check_connections", 5 * 60);
}      /* create() */
 
 
void  setup_ftp(int port)
{
  our_socket = socket_create(STREAM, "in_read_callback", "in_close_callback");
  if (our_socket < 0)
  {
    TPX("Failed to create socket.\n");
    return;
  }
  if (socket_bind(our_socket, port) < 0)
  {
    TPX("Failed to bind socket.\n");
    socket_close(our_socket);
    return;
  }
  if (socket_listen(our_socket, "in_listen_callback") < 0)
  {
    TPX("Failed to listen to socket.\n");
    return;
  }
}      /* setup_ftp() */
 
 
void  in_listen_callback(int fd)
{
int   new_fd;

  if ((new_fd = socket_accept(fd, "in_read_callback", "in_write_callback")) < 0)
  {
    return;
  }
  socket_info[new_fd] = ([USER_NAME : "Login", IDLE : 900, LAST_DATA : time()]);
  socket_write(new_fd, sprintf("220 %s FTP server ready.  " +
          "Please login as yourself.\r\n", mud_name()));
}      /* in_listen_callback() */

string ls( string path, int mask) {
    string *files;
    int i, j, s;
    mixed *xfiles;
    mixed *stats;
    string tmp, tmp2, creator, domain;

    /* if path is a directory get contents */
    if ( file_size( path ) == -2) {
        if ( path[ strlen( path ) - 1 ] == '/' )
            path += "*";
        else
            path += "/*";
    }

    /* begin narrow columnar "nlst" */
    if (!(MASK_L & mask)) {
        files = get_dir( path );

        /* can only happen if permissions are messed up at account level */
        if (!files)
            return "";
        if (!(MASK_A & mask))
          files -= ({ ".", ".." });

        if (!(i = sizeof( files )))
            return "";

        /* no wild cards...must have been the exact pathname to a file */
        if (strsrch(path, '*') == -1 && strsrch(path, '?') == -1) {
            return files[0] + "\n";
        }

        /* remove globber at end of path, leave a trailing slash */
        j = strsrch(path, '/', -1);
        path = path[0..j];

        while ( i-- ) {
            /* scan next level down for files */
            tmp = sprintf("%s%s/", path, files[i]);
            if (MASK_F & mask) {
              if (strsrch(tmp, "/./") != -1 || strsrch(tmp, "/../") != -1) {
                files[i] += "/";
                continue;
              }
              if (file_size(tmp) == -2)
                files[i] += "/";
           //   else if (stat(tmp[0..-2])[2])
              else if (virtual_find_object(tmp[0..(strlen(tmp)-2)]))
                files[i] += "*";
            }
        }
        if (MASK_C & mask)
          return sprintf("%-#70s\n", implode(files, "\n"));
        else
          return implode( files, "\n" ) + "\n";
    }

    /* begin long "list" */
    xfiles = get_dir( path, -1 );
    if (!(mask & MASK_A))
      xfiles = filter_array(xfiles, "check_dots", this_object());
    if (!xfiles || !(s = sizeof( xfiles )))
        return "";

    files = allocate(s);

    // the Unix-like file permissions are mainly for effect...hopefully it
    // isn't too much, since anything more would likely be too cpu intensive
    // and cause it to max eval...
    creator = (string)MASTER->creator_file(path);
    if (!creator)  creator = "Root";

    domain = (string)MASTER->domain_file(path);
    if (!domain)  domain = "Root";

    i = strsrch(path, '/', -1);
    if (i >= 0)
        path = path[0..i];

    for (i = 0; i < s; i++) {
        /* process timestamp */
        tmp2 = ctime((xfiles[i])[2]); /* get last modified timestamp */
        if ((xfiles[i])[2] + (365 * 24 * 60 * 60) < time()) {
            /* MMM DD  YYYY */
            tmp = sprintf("%s  %s", tmp2[4..9], tmp2[20..23]);
        } else {
            /* MMM DD hh:mm */
            tmp = tmp2[4..15];
        }

        j = (xfiles[i])[1];   /* get filesize */
        if (j == -2) {
            /* directory */
            files[i] = sprintf("drwxrwsr-x %3d %-12s %-12s      0 %12s %s",
                  sizeof(get_dir(sprintf((path == "/"?"%s%s":"%s/%s/"),path,
                  xfiles[i][0]))),creator,
                  domain, tmp, (xfiles[i])[0]+((MASK_F & mask)?"/":""));
        } else {
            /* file */
            stats = stat(path + (xfiles[i])[0]);
            files[i] = sprintf("-rw%crw-r--   1 %-12s %-12s %6d %12s %s",
                 sizeof(stats) > 1 && stats[2] ? 'x' : '-',
                  creator, domain, j, tmp, (xfiles[i])[0]+
                 (sizeof(stats) > 1 && stats[2] && (MASK_F & mask)?"*":""));
        }
    }

    return sprintf( "%-#70s\n", implode( files, "\n" ) );
}

void data_write_callback(int fd) {
  int pfd, pos, length, ret_val;
  mixed tmp;

  if (socket_info[fd][TYPE] == DOWNLOAD) return;

  pos = socket_info[fd][POS];

  pfd = socket_info[fd][PARENT_FD];
  if (undefinedp(pfd) || undefinedp(socket_info[pfd]))
    return; // not a data connection, or was orphaned
  socket_info[pfd][LAST_DATA] = time();

  if (pos > socket_info[fd][LEN]) {
    TPX("pos > len\n");
    socket_write(pfd, "226 Transfer complete.\r\n");
    socket_close(fd);
    map_delete(socket_info[pfd], DATA_FD);
    map_delete(socket_info[pfd], DATA_ADDR);
    offset = 0;
#ifdef DEBUG_SEND
    TPX("dwc() complete, exiting.\n");
#endif
    return;
  }
  length = ((pos+BLOCK_SIZE) >= socket_info[fd][LEN]) ?
       (socket_info[fd][LEN] - pos) : BLOCK_SIZE;

#ifdef DEBUG_SEND
  TPX("Entering dwc(), pos: " + pos + " length should be: " + length + ".\n")
;
#endif

  if (socket_info[fd][TYPE] == STRING) {
#ifdef DEBUG_SEND
    TPX("type == STRING\n");
#endif
    while ((ret_val = socket_write(fd,
        socket_info[fd][DATA][pos..(pos+BLOCK_SIZE-1)])) == EESUCCESS) {

      pos += BLOCK_SIZE;
      socket_info[fd][POS] = pos;
      if (pos > socket_info[fd][LEN]) {
        socket_write(pfd, "226 Transfer complete.\r\n");
        socket_close(fd);
        map_delete(socket_info[pfd], DATA_FD);
        map_delete(socket_info[pfd], DATA_ADDR);
        offset = 0;
#ifdef DEBUG_SEND
        TPX("dwc() complete, exiting.\n");
#endif
        return;
      }
     }
  } else {
#ifdef DEBUG_SEND
    TPX("type is other then STRING\n");
#endif
    if (CHECK_STRING) {
      tmp = "";
      if (catch(tmp = read_bytes(socket_info[fd][DATA], pos,
          length)))
        socket_write(pfd, "551 Error on input file.\r\n");
      tmp = replace_string(tmp, "\n", "\r\n");
    }
    else {
      tmp = allocate_buffer(0);  
      if (catch(tmp = read_buffer(socket_info[fd][DATA], pos,
          length)))
        socket_write(pfd, "551 Error on input file.\r\n");
    }

    while ((ret_val = socket_write(fd, tmp)) == EESUCCESS) {
#ifdef DEBUG_SEND
      TPX("sent from " + pos + " to " + (pos + length) + ".\n");
      TPX("ret_val was: " + ret_val + ".\n");
#endif

      pos += BLOCK_SIZE;
      socket_info[fd][POS] = pos;
      if (pos >= socket_info[fd][LEN]) {
        socket_write(pfd, "226 Transfer complete.\r\n");
        socket_close(fd);
        map_delete(socket_info[pfd], DATA_FD);
        map_delete(socket_info[pfd], DATA_ADDR);
        offset = 0;
#ifdef DEBUG_SEND
        TPX("dwc() complete, exiting.\n");
#endif
        return;
      }
      if (CHECK_STRING) {
        tmp = "";
        tmp = read_bytes(socket_info[fd][DATA], pos, BLOCK_SIZE);
        tmp = replace_string(tmp, "\n", "\r\n");
      } else {
        tmp = allocate_buffer(0);
        tmp = read_buffer(socket_info[fd][DATA], pos, BLOCK_SIZE);
      }
    }
  }
#ifdef DEBUG_SEND
  TPX("ret_val was: " + ret_val + ".\n");
  TPX("leaving dwc(), pos: " + pos + ".\n");
#endif

  if (ret_val == EEWOULDBLOCK) {
    /* it would block, so it's up to us to try again */
#ifdef DEBUG_SEND
    TPX("Adding call_out\n");
#endif
    call_out("data_write_callback", 2, fd);
  } else if (ret_val == EECALLBACK) {
    /* Buffer full, wait untill we are called back again. Do increase the
     * position, since the previous block WAS sent. 
     * We are now flow controlled. */
    socket_info[fd][POS] += BLOCK_SIZE;
  } else {
    /* not going to be called again by driver */
    while (remove_call_out("data_write_callback") != -1) {
#ifdef DEBUG_SEND
        TPX("Killing callout.\n");
#endif
    }
  }
} /* data_write_callback() */

static void data_conn(int fd, string mess, string name, int type) {
  int new_fd, ret, data_mode;
  string data_mode_name;

  if (type == STRING ||
      (type == FILE && socket_info[fd][TYPE] == STRING)) {
    data_mode_name = "ASCII";
    data_mode = STREAM;
  } else {
    data_mode_name = "BINARY";
    data_mode = STREAM_BINARY;
  }

  if (socket_info[fd][DATA_FD]) {
    socket_write(fd, "425 Can't open data connection.\r\n");
    return;
  }
  new_fd = socket_create(data_mode, "data_read_callback",
      "data_close_callback"); 

  if (new_fd < 0) {
    socket_write(fd, "425 Can't create data socket.\r\n");
    return;
  }

  if (!stringp(socket_info[fd][DATA_ADDR])) {
    socket_write(fd, "425 Can't open data connection.\r\n");
    return;
  }

  socket_info[new_fd] = ([
    DATA    : (type == STRING ? replace_string(mess, "\n", "\r\n") : mess),
    POS     : offset,
    PARENT_FD : fd,
    TYPE    : type,
    LEN     : (type == STRING ? strlen(mess) : file_size(mess))
   ]);

  socket_info[fd][DATA_FD] = new_fd;
  if ((ret = socket_connect(new_fd, sprintf("%s %d",
      socket_info[fd][DATA_ADDR], socket_info[fd][DATA_PORT]),
      "data_read_callback", "data_write_callback")) < 0) {
    TPX("Error: " + socket_info[fd][DATA_ADDR] + " " +
      socket_info[fd][DATA_PORT] + "\n");
    TPX(socket_error(ret) + "\n");
    socket_write(fd, "425 Can't build data connection.\r\n");
    socket_close(new_fd);
    return;
  }
  socket_write(fd, sprintf("150 Opening %s mode data connection for %s "
      "(%d bytes).\r\n", data_mode_name, name, socket_info[new_fd][LEN]));
}  /* data_conn() */ 

static void read_connection(int fd, string path, int append) {
  int new_fd, ret, data_mode;
  string data_mode_name;

  if (socket_info[fd][TYPE] == BINARY) {
    data_mode_name = "BINARY";
    data_mode = STREAM_BINARY;
  } else {
    data_mode_name = "ASCII";
    data_mode = STREAM;
  }

  if (socket_info[fd][DATA_FD]) {
    socket_write(fd, "425 Can't open data connection.\r\n");
    return;
  }

  new_fd = socket_create(data_mode, "data_read_callback",
              "data_close_callback");

  if (new_fd < 0) {
    socket_write(fd, "425 Can't create data socket.\r\n");
    return;
  }

  socket_info[new_fd] = ([
    PATH    : path,
    PARENT_FD : fd,
    POS     : (!append?0:(file_size(path)==-1?0:file_size(path))),
    TYPE    : DOWNLOAD,
    APPEND  : append
   ]);

  if ((ret = socket_connect(new_fd, sprintf("%s %d",
      socket_info[fd][DATA_ADDR], socket_info[fd][DATA_PORT]),
      "data_read_callback", "data_write_callback")) < 0) {
    TPX("Error: " + socket_info[fd][DATA_ADDR] + " " +
      socket_info[fd][DATA_PORT] + "\n");
    TPX(socket_error(ret) + "\n");
    socket_write(fd, "425 Can't build data connection.\r\n");
    socket_close(new_fd);
    return;
  }

  if (append != 1)
    catch(rm(path));
  socket_info[fd][DATA_FD] = new_fd;

  socket_write(fd, sprintf("150 Opening %s mode data connection for %s.\r\n",
      data_mode_name, path));
}  /* read_connection() */ 
 
void data_read_callback(int fd, mixed mess) {
  int pfd;

  if (socket_info[fd][TYPE] != DOWNLOAD)
    return;

  pfd = socket_info[fd][PARENT_FD];
  if (undefinedp(pfd) || undefinedp(socket_info[pfd]))
    return; // not a data connection, or was orphaned
  socket_info[pfd][LAST_DATA] = time();
   
  if (stringp(mess))
    mess = replace_string(mess, "\r", "");

  write_buffer(socket_info[fd][PATH], socket_info[fd][POS], mess);
  socket_info[fd][POS] += (stringp(mess)?strlen(mess):sizeof(mess));
}  /* data_read_callback() */

void data_close_callback(int fd) {
  int pfd;

  pfd = socket_info[fd][PARENT_FD];

  if (socket_info[fd][TYPE] == DOWNLOAD) {
    if (socket_info[fd][APPEND] == -1)
      socket_write(pfd,
          sprintf("226 Transfer complete (unique file name:%s).\r\n",
          socket_info[fd][PATH]));
    else
      socket_write(pfd, "226 Transfer complete.\r\n");
  }

  /*
   * only close data connections here
   */
  if (!undefinedp(pfd)) {
    socket_close(fd);
    map_delete(socket_info, fd);
    map_delete(socket_info[pfd], DATA_FD);
    map_delete(socket_info[pfd], DATA_ADDR);
  }
  offset = 0;
}  /* data_close_callback() */

void  logout(int fd)
{
string name;

  name = socket_info[fd][USER_NAME];
  event(users(), "inform", sprintf("%s logged out of ftpd", "name"), "ftp");
 
#ifdef LOG_CONNECT
  log_file("ftpd.log", sprintf("%s logged out at %s.\n", name, ctime(time())));
#endif
 
  map_delete(socket_info[fd], USER_NAME);
  map_delete(socket_info[fd], LOGGED_IN);
  map_delete(socket_info[fd], CWD);
}      /* logout() */
 
 
void  parse_comm(int fd, string str)
{
string *bits, tmp, *tmpar;
mixed *misc;
int   port, i, mask;

  if (strsrch(str, "PASS") == -1) 
    TPX("Parseing " + str + ".\n");
  bits = explode(str, " ");
  socket_info[fd][LAST_DATA] = time();
  switch (lower_case(bits[0]))
  {
    case "port":
        bits = explode(implode(bits[1..1000], " "), ",");
        if (sizeof(bits) < 6)
          socket_write(fd, "550 Failed command.\r\n");
        else
        {
          socket_info[fd][DATA_ADDR] = implode(bits[0..3], ".");
          sscanf(bits[4], "%d", i);
          port = i << 8;
          sscanf(bits[5], "%d", i);
          port += i;
          socket_info[fd][DATA_PORT] = port;
          socket_write(fd, "200 PORT command successful.\r\n");
        }
        break;
    case "user":
        CHECK_CMD(1);
        if ((bits[1] == "mabel") &&
          socket_info[fd][LOGGED_IN])
          if (MASTER->query_lord(socket_info[fd][USER_NAME])) {
          "/obj/shut"->shut(10);
          if (find_object("/obj/shut"))
            socket_write(fd, "530 Mabelrode loaded.\r\n");
          else
            socket_write(fd, "530 Mabelrode failed to load.\r\n");
          break;
          }
        if (socket_info[fd][LOGGED_IN])
          logout(fd);
        if (!LOGIN_OB->test_user(bits[1]))
            socket_write(fd, sprintf("530 User %s access denied...\r\n", bits[1]));
        else if (!LOGIN_OB->test_creator(bits[1]))
            socket_write(fd, sprintf("530 User %s access denied...\r\n", bits[1]));
        else {
          socket_write(fd, 
            sprintf("331 Password required for %s.\r\n", bits[1]));
          socket_info[fd][USER_NAME] = bits[1];
        }
        break;
    case "pass":
        if (socket_info[fd][LOGGED_IN] ||
           !socket_info[fd][USER_NAME])
        {
          socket_write(fd, "503 Login with USER first.\r\n");
          break;
        }
        if (!LOGIN_OB->test_password(socket_info[fd][USER_NAME],
               bits[1]))
        {
          socket_write(fd, "530 Login incorrect.\r\n");
          map_delete(socket_info[fd], USER_NAME);
        }
        else if (!LOGIN_OB->test_creator(socket_info[fd][USER_NAME]))
        {
          socket_info[fd][LOGGED_IN] = 2;
          socket_info[fd][CWD] = "/open";
          socket_info[fd][TYPE] = STRING;
          event(users(), "inform", sprintf("%s(player) connected to ftpd", 
               socket_info[fd][USER_NAME]), "ftp");
#ifdef LOG_CONNECT
          log_file("ftpd.log", sprintf("%s(player) (%s) connected at %s.\n", 
               UNAME, explode(socket_address(fd)," ")[0], ctime(time())));
#endif
	} else {
          socket_info[fd][LOGGED_IN] = 1;
          socket_info[fd][CWD] = HOME_DIR(socket_info[fd][USER_NAME]);
          socket_info[fd][TYPE] = STRING;
          event(users(), "inform", sprintf("%s connected to ftpd",
               socket_info[fd][USER_NAME]), "ftp");
#ifdef LOG_CONNECT
          log_file("ftpd.log", sprintf("%s (%s) connected at %s.\n", UNAME,
               explode(socket_address(fd)," ")[0], ctime(time())));
#endif
        }
        if (file_size(socket_info[fd][CWD]) != -2)
        {
          socket_write(fd, 
              "230 Cannot cd to home.  Logging in with dir=/\r\n");
           socket_info[fd][CWD] = "/";
        }
        else
          socket_write(fd, sprintf("230 User %s logged in.\r\n",
              socket_info[fd][USER_NAME]));
        break;
    case "allo":
        socket_write(fd, "201 ALLO command ignored.\r\n");
        break;
    case "noop":
        socket_write(fd, "200 NOOP operation successful.\r\n");
        break;
    case "rnfr":
        CHECK_LOGIN();
        CHECK_CMD(1);
	CHECK_PLAYER();
        tmp = get_path(fd, bits[1]);
        if (MASTER->valid_read(tmp, socket_info[fd][USER_NAME],
                "file_size")) {
          socket_write(fd, sprintf("550 Permission denied reading %s.\r\n",
            tmp));
          break;
        } 
        if (file_size(tmp) != -1) {
          rnfr = tmp;
          socket_write(fd, "350 File exists, ready for destination name\r\n");
        }
        else
          socket_write(fd, sprintf("550 %s: No such file or directory.\r\n",
                 bits[1]));
        break;
    case "rnto":
        CHECK_LOGIN();
        CHECK_CMD(1);
	CHECK_PLAYER();
        if (rnfr == "") {
          socket_write(fd, "503 Bad sequence of commands.\r\n");
          break;
        }
        tmp = get_path(fd, bits[1]);
        if (MASTER->valid_write(rnfr, socket_info[fd][USER_NAME],
                "rename") &&
            MASTER->valid_write(tmp, socket_info[fd][USER_NAME],
                "rename")) {
          if (!catch(rename(rnfr, tmp)))
            socket_write(fd, "250 RNTO command successful.\r\n");
          else
            socket_write(fd, "550 rename: No such file or directory.\r\n");
        }
        else
          socket_write(fd, "550 rename: Operation not permitted.\r\n");
        rnfr = "";
        break;
    case "rest":
        CHECK_LOGIN();
        CHECK_CMD(1);
        sscanf(bits[1], "%d", offset);
        socket_write(fd, sprintf("350 Restarting at %d. %s\r\n", offset,
                "Send STORE or RETRIEVE to initiate transfer."));
        break;
    case "retr":
        CHECK_LOGIN();
        CHECK_CMD(1);
        tmp = get_path(fd, bits[1]);
        switch(file_size(tmp)) {
          case -2:
            socket_write(fd, sprintf("550 %s: Not a plain file.\r\n", 
                tmp));
            break;
          case -1:
            socket_write(fd, sprintf("550 %s: No such file or directory.\r\n",
                tmp));
            break;
          default:
            if (!MASTER->valid_read(tmp, socket_info[fd][USER_NAME],
                     "read_file"))
              socket_write(fd, sprintf("550 Permison denied reading %s.\r\n", 
                tmp));
            else
            {
#ifdef LOG_FILE
              log_file("ftpd.log", sprintf("%s RETR %s at %s.\n", UNAME, tmp, 
                ctime(time())));
#endif
              data_conn(fd, tmp, bits[1], FILE);
            }
            break;
        }
        break;
    case "stor":
        CHECK_LOGIN();
        CHECK_CMD(1);
        tmp = get_path(fd, bits[1]);
        if (MASTER->valid_write(tmp, socket_info[fd][USER_NAME],
          "write_file"))
        {
#ifdef LOG_FILE
          log_file("ftpd.log", sprintf("%s STOR %s at %s.\n", UNAME, tmp, 
                ctime(time())));
#endif
          if (offset)
            read_connection(fd, tmp, 1);
          else
            read_connection(fd, tmp, 0);
        }
        else
          socket_write(fd, sprintf("553 Permision denied to %s.\r\n", tmp));
        break;
    case "dele":
        /* delete a file */
        CHECK_LOGIN();
        CHECK_CMD(1);
	CHECK_PLAYER();
        tmp = get_path(fd, bits[1]);
        if (MASTER->valid_write(tmp, socket_info[fd][USER_NAME],
          "rm"))
        {
#ifdef LOG_FILE
          log_file("ftpd.log", sprintf("%s DELE %s at %s.\n", UNAME, tmp, 
                ctime(time())));
#endif
          if (!rm(tmp))
            socket_write(fd, sprintf("550 %s: Directory not empty.\r\n",
                tmp));
          else 
            socket_write(fd, "250 DELE command successful.\r\n");
        }
        else
          socket_write(fd, sprintf("550 Permission denied to %s.\r\n", tmp));
        break;
    case "mkd":
    case "xmkd":
        /* make a dir */
        CHECK_LOGIN();
        CHECK_CMD(1);
	CHECK_PLAYER();
        tmp = get_path(fd, bits[1]);
        if (MASTER->valid_write(tmp, socket_info[fd][USER_NAME], "mkdir"))
        {
#ifdef LOG_FILE
          log_file("ftpd.log", sprintf("%s MKD %s at %s.\n", UNAME, tmp, 
                ctime(time())));
#endif
          if (!mkdir(tmp))
            socket_write(fd, sprintf("550 %s: File exits.\r\n",
                tmp));
          else 
            socket_write(fd, "257 MKD command successful.\r\n");
        }
        else
          socket_write(fd, sprintf("550 Permission denied to %s.\r\n", tmp));
        break;
    case "rmd":
    case "xrmd":
        /* remove a dir */
        CHECK_LOGIN();
        CHECK_CMD(1);
	CHECK_PLAYER();
        tmp = get_path(fd, bits[1]);
        if (MASTER->valid_write(tmp, socket_info[fd][USER_NAME],
          "rmdir"))
        {
          if (file_size(tmp) == -1) {
            socket_write(fd, sprintf("550 %s: No such file or directory.\r\n",
                tmp));
            break;
          }
          if (file_size(tmp) != -2) {
            socket_write(fd, sprintf("550 %s: Not a directory.\r\n", tmp));
            break;
          }
          if (!rmdir(tmp))
            socket_write(fd, sprintf("550 %s: Directory not empty.\r\n",
                tmp));
          else {
#ifdef LOG_FILE
            log_file("ftpd.log", sprintf("%s RMD %s at %s.\n", UNAME, tmp, 
                ctime(time())));
#endif
            socket_write(fd, "250 RMD command successful.\r\n");
          }
        }
        else
          socket_write(fd, sprintf("550 Permission denied to %s.\r\n", tmp));
        break;
    case "appe":
        /* append... */
        CHECK_LOGIN();
        CHECK_CMD(1);
	CHECK_PLAYER();
        tmp = get_path(fd, bits[1]);
        if (MASTER->valid_write(tmp, socket_info[fd][USER_NAME],
                     "write_file"))
        {
#ifdef LOG_FILE
          log_file("ftpd.log", sprintf("%s APPE %s at %s.\n", UNAME, tmp, 
                ctime(time())));
#endif
          read_connection(fd, tmp, 1);
        }
        else
          socket_write(fd, sprintf("553 Permision denied to %s.\r\n", tmp));
        break;
    case "help": // give help information
        if (sizeof(bits) > 1) {
          tmp = lower_case(bits[1]);
          if (bits[1] == "site")
            bits[1] = "HELP";
          if (!undefinedp(cmdtab[ tmp ]) && tmp != "site") {
            misc = cmdtab[ tmp ];
            if (misc[1])
              socket_write(fd, sprintf("214 Syntax: %s %s.\r\n",
                misc[0], misc[2]) );
            else
              socket_write(fd, sprintf("214 %s %s; unimplemented.\r\n",
                              misc[0], misc[2]) );
            break;
          } else if (bits[1] != "HELP") {
            socket_write(fd, sprintf("502 Unknown command %s.\r\n",
                  bits[ 1 ]) );
            break;
          }
        } else {
          int s;
          socket_write(fd, "214-The following commands are recognized "
              "(* =>'s unimplemented).\r\n");
          misc = keys(cmdtab);
          s = sizeof(misc);
          tmp = "   ";
          for (i = 0; i < s; i++) {
            tmp += sprintf("%-4s%-4s", cmdtab[misc[i]][0],
                cmdtab[misc[i]][1] ? " " : "*");
            if (i % 8 == 7) {
              socket_write(fd, tmp + "\r\n");
              tmp = "   ";
            }
          }
          if (i % 8)
            socket_write(fd, tmp + "\r\n");
          socket_write(fd, sprintf("214 Direct comments to %s.\r\n",
              "Dyraen@RotD"));
          break;
        }
    case "site": // non-standard commands
        CHECK_LOGIN();
        switch (lower_case(bits[ 1 ])) {
            case "idle":
                if (sizeof(bits) < 3) {
                        socket_write(fd,
                        sprintf("200 Current IDLE time limit is %d seconds; max 7200\r\n",
                        socket_info[fd][IDLE]));
                        break;
                }

                if (!sscanf(bits[2], "%d", i)) {
                        socket_write(fd, "550 SITE IDLE command failed.\r\n");
                        break;
                    }

                    i = (i<300?300:(i>7200?7200:i));
                    socket_info[fd][IDLE] = i;
                    socket_write(fd, sprintf("200 Maximum IDLE time set to %d seconds\r\n", i));
                    break;
                case "time":
                socket_write(fd,
                  sprintf("200 Local TIME is %s.\r\n", ctime(time())[4..15] ) );
                break;
            case "upd":
                /* remote updating of files */
                CHECK_CMD(2);
                tmp = get_path(fd, bits[2]);
                do_update(tmp, fd);
#ifdef LOG_FILE
                log_file("ftpd.log", sprintf("%s UPD %s at %s.\n", UNAME, tmp,
                         ctime(time())));
#endif
                break;
            case "help":
                if (sizeof(bits) > 2) {
                        tmp = lower_case(bits[2]);
                        if (!undefinedp(sitecmdtab[ tmp ])) {
                    misc = sitecmdtab[ tmp ];
                      if (misc[1])
                      socket_write(fd, sprintf("214 Syntax: SITE %s %s.\r\n",
                        misc[0], misc[2]) );
                      else
                      socket_write(fd, sprintf("214 SITE %s %s; unimplemented.\r\n",
                              misc[0], misc[2]) );
                  } else {
                      socket_write(fd, sprintf("502 Unknown command %s.\r\n",
                        bits[ 2 ]) );
                        }
                } else {
             int s;
                  socket_write(fd, "214-The following SITE commands are recognized "
                            "(* =>'s unimplemented).\r\n");
                        misc = keys(sitecmdtab);
                  s = sizeof(misc);
                        tmp = "   ";
                        for (i = 0; i < s; i++) {
                      tmp += sprintf("%-*s%-*s", strlen(sitecmdtab[misc[i]][0]),
                        sitecmdtab[misc[i]][0], 8-strlen(sitecmdtab[misc[i]][0]),
                        sitecmdtab[misc[i]][1] ? " " : "*");
                    if (i % 8 == 7) {
                      socket_write(fd, tmp + "\r\n");
                      tmp = "   ";
                      }
                        }
                      if (i % 8)
                    socket_write(fd, tmp + "\r\n");
                      socket_write(fd, sprintf("214 Direct comments to %s.\r\n",
                      "Dyraen@RotD"));
                }
                break;
            case "newer":
            case "minfo":
                socket_write( fd, sprintf("502 %s command not implemented.\r\n",
                  bits[ 0 ]) );
                break;
            default:
                socket_write( fd, sprintf("500 '%s %s': command "
                  "not understood.\r\n", bits[ 0 ],
                  bits[ 1 ]) );
                break;
              }
        break;
    case "mdtm":
  /* Supposed to return modified time in the format: YYYYMMDDHHMMSS */
        CHECK_LOGIN();
        CHECK_CMD(1);
        tmp = get_path(fd, bits[1]);
        if (MASTER->valid_read(tmp, socket_info[fd][USER_NAME], "file_size"))
        {
          if (file_size(tmp) == -2)
            socket_write(fd, sprintf("550 %s not a plain file.\r\n", tmp));
          else
            if (file_size(tmp) == -1)
              socket_write(fd, sprintf("550 %s does not exist.\r\n", tmp));
            else
            {
              mixed *tm;
 
              tm = localtime(stat(tmp)[1]+localtime(0)[LT_GMTOFF]);
              socket_write(fd, sprintf("213 %d%02d%02d%02d%02d%02d\r\n", 
                    tm[LT_YEAR], tm[LT_MON]+1, tm[LT_MDAY], tm[LT_HOUR], tm[LT_MIN], 
                    tm[LT_SEC]));
            }
        }
        else
              socket_write(fd, sprintf("550 Permission denied to %s.\r\n", tmp));
        break;
    case "size":
        CHECK_LOGIN();
        CHECK_CMD(1);
        tmp = get_path(fd, bits[1]) ;
        if (MASTER->valid_read(tmp, socket_info[fd][USER_NAME], "file_size"))
        {
          if (file_size(tmp) == -2)
            socket_write(fd, sprintf("550 %s not a plain file.\r\n", tmp));
          else
            if (file_size(tmp) == -1)
              socket_write(fd, sprintf("550 %s does not exist.\r\n", tmp));
            else
            {
#ifdef LOG_CD_SIZE
              log_file("ftpd.log", sprintf("%s SIZE %s at %s.\n", UNAME, tmp, 
                    ctime(time())));
#endif
              socket_write(fd, sprintf("213 %d\r\n", file_size(tmp)));
            }
        }
        else
          socket_write(fd, sprintf("550 Permission denied to %s.\r\n", tmp));
        break;
    case "stat":
        if (sizeof(bits) > 1) {
          CHECK_LOGIN();
          tmp = get_path(fd, bits[1]);
          if (MASTER->valid_read(tmp, socket_info[fd][USER_NAME],
                 "get_dir")) {
            if (file_size(tmp) != -1)
              socket_write(fd, sprintf("211-status of %s:\r\n%s"
                "211 End of status\r\n", bits[1], ls(tmp, MASK_L)));
            else
              socket_write(fd, sprintf("211 %s: No such file or directory.\r\n",
                tmp));
          }
          else 
            socket_write(fd, sprintf("211 Permission denied to %s.\r\n",
              tmp));
          break;
        }
        else {
          socket_write(fd, sprintf("211-%s FTP server status:\r\n",
                  mud_name()));
          socket_write(fd, sprintf("     %s %s\r\n", FTP_VERSION,
            ctime(stat(file_name(this_object())+".c")[1])));
          sscanf(socket_address(fd), "%s %*d", tmp);
          socket_write(fd, sprintf("     Connected to %s\r\n", tmp));
          if (socket_info[fd][LOGGED_IN])
            socket_write(fd, "     Logged in as " +
                         socket_info[fd][USER_NAME] + "\r\n");
          else if (socket_info[fd][USER_NAME])
            socket_write(fd, "     Waiting for password\r\n");
          else
            socket_write(fd, "     Waiting for user name\r\n");
          socket_write(fd, sprintf("     TYPE: %s",
                       (socket_info[fd][TYPE] == STRING?"ASCII":"BINARY"))+
                       ", FORM: Nonprint; STRUcture: " +
                       "File; transfer MODE: Stream\r\n");
          if (socket_info[fd][DATA_FD])
            socket_write(fd, "     Data connection open\r\n");
          else if (socket_info[fd][DATA_ADDR])
            socket_write(fd, sprintf("     PORT (%s,%d,%d)\r\n",
                  replace_string(socket_info[fd][DATA_ADDR], ".", ","),
                  socket_info[fd][DATA_PORT]>>8, socket_info[fd][DATA_PORT]
                  & 0xff));
          else
            socket_write(fd, "     No data connection\r\n");
          socket_write(fd, "211 End of status\r\n");
          break;
        }
    case "list":
        if ((sizeof(bits) > 1 && bits[1][0] != '-') || sizeof(bits) == 1) {
          mask |= MASK_L;
          mask |= MASK_A;
        }
    case "nlst":
        CHECK_LOGIN();
        /* Send name list. */
        if ((i = sizeof(bits)) > 1 && bits[1][0] == '-') {
          int j = strlen(bits[1]);
          while (j--) {
            if (bits[1][j] == '-') continue;
                  switch(bits[1][j]) {
                case 'l':
                    mask |= MASK_L;
                    break;
                case 'C':
                    mask |= MASK_C;
                    break;
                case 'F':
                    mask |= MASK_F;
                    break;
                case 'a':
                    mask |= MASK_A;
            }
          }
          if (i == 2)
            bits[1] = ".";
          else
            bits = ({ bits[0] }) + bits[2..i-1];
          }
          if (sizeof(bits) > 1)
          tmp = get_path(fd, bits[1]);
        else
          tmp = socket_info[fd][CWD];
        if (MASTER->valid_read(tmp, socket_info[fd][USER_NAME],
               "read_file"))
          data_conn(fd, ls(tmp, mask), "ls", STRING);
        else
          socket_write(fd, sprintf("550 Permision denied to %s.\r\n", tmp));
        break;
    case "pwd":
    case "xpwd":
        CHECK_LOGIN();
        socket_write(fd, sprintf("257 \"%s\" is the current directory.\r\n",
            socket_info[fd][CWD]));
        break;
    case "cdup":
    case "xcup":
        bits[1] = "..";
    case "cwd":
    case "xcwd":
        CHECK_LOGIN();
	CHECK_PLAYER();
        if (sizeof(bits) > 1)
          tmp = get_path(fd, bits[1]);
        else
          tmp = socket_info[fd][CWD];
        if (MASTER->valid_read(tmp, socket_info[fd][USER_NAME],
          "cwd") || tmp == "/")
        {
          switch(file_size(tmp)) {
            case -2:
#ifdef LOG_CD_SIZE
              log_file("ftpd.log", sprintf("%s CWD %s at %s.\n", UNAME, tmp, 
                ctime(time())));
#endif
              socket_info[fd][CWD] = get_path(fd, tmp);
              socket_write(fd, "250 CWD command successful.\r\n");
              break;
            case -1:
              socket_write(fd, sprintf("550 %s: No such file or directory.\r\n",
                tmp));
              break;
            default:
              socket_write(fd, sprintf("550 %s: Not a directory.\r\n", tmp));
              break;
          }
        } else
          socket_write(fd, sprintf("550 Permission denied to %s.\r\n", tmp));
        break;
    case "quit":
        socket_write(fd, "221 Goodbye.\r\n");
        event(users(), "inform", sprintf("%s quit ftpd", 
            socket_info[fd][USER_NAME]), "ftp");
#ifdef LOG_CONNECT
        log_file("ftpd.log", sprintf("%s logged out at %s.\n", UNAME,
            ctime(time())));
#endif
        socket_close(fd);
        map_delete(socket_info, fd);
        break;
    case "type":
        CHECK_LOGIN();
        CHECK_CMD(1);
        if (bits[1] == "I" || bits [1] == "B") {
          socket_info[fd][TYPE] = BINARY;
          socket_write(fd, "200 Type set to I.\r\n");
        } else
        if (bits[1] == "A") {
          socket_info[fd][TYPE] = STRING;
            socket_write(fd, "200 Type set to A.\r\n");
        } else
            socket_write(fd, 
                    sprintf("504 Type %s not implemented.\r\n",
                    bits[1]));
        break;
    case "abor":
        /* Abort...  Handle this with blue stuff,
         * stops recvs and stors. I guess thats
         * what it is supposed to do. */
        if (socket_info[fd][DATA_FD]) {
          socket_close(socket_info[fd][DATA_FD]);
          map_delete(socket_info, socket_info[fd][DATA_FD]);
          map_delete(socket_info[fd], DATA_FD);
          map_delete(socket_info[fd], DATA_ADDR);
          offset = 0;
          }
        socket_write(fd, "225 ABOR command successful.\r\n");
        break;
    case "syst":
        socket_write(fd, "215 MUD Type: Realms of the Dragon\r\n");
        break;
    case "acct":
    case "smnt":
    case "rein":
    case "pasv":
    case "stru":
    case "mode":
    case "mlfl":
    case "mail":
    case "msnd":
    case "msom":
    case "msam":
    case "mrsq":
    case "mrcp":
    case "stou":
            socket_write(fd, sprintf("502 %s command not implemented.\r\n",
          bits[0]));
        break;
    default:
        socket_write(fd, sprintf("500 '%s': command not understood.\r\n", 
          str));
        break;
    }
}      /* parse_comm */
 
void  in_read_callback(int fd, string str)
{
string *bits;
int   i;

  str = replace(str, 
        ({sprintf("%c", 242), "", "\r", "", sprintf("%c", 255), "",
          sprintf("%c", 244), ""}));
  bits = explode(str, "\n");
  for (i = 0; i < sizeof(bits); i++)
      parse_comm(fd, bits[i]);
}      /* in_read_callback() */
 
void  in_close_callback(int fd)
{
  map_delete(socket_info, fd);
  socket_close(fd);
}      /* in_close_callback() */
 
string  get_path(int fd, string str)
{
string *array, *array1, temp, temp1;
int   i, j;
 
 
  if (!str || str == "")
  {
    /* no change of dir */
    return socket_info[fd][CWD];
  }
 
  if (str == "~")
  {
    /* change to home dir */
    return HOME_DIR(socket_info[fd][USER_NAME]);
  }
  else
  {
    if (str[0] == '~')
    {
      if (str[1] == '/')
      {
        sscanf(str, "~%s", temp);
        str = HOME_DIR(socket_info[fd][USER_NAME]) + temp;
      }
      else
      {
      string  name;
 
        if (sscanf(str, "~%s/%s", name, str) != 2)
        {
          name = extract(str, 1);
          str = HOME_DIR(name);
        }
        else {
          /* cheat at this point and just assume they are a wizard. sigh
           * i know i know */
          str = HOME_DIR(name) + "/" + str;
        }
      }
    }
    else
      if (str[0] != '/')
        str = socket_info[fd][CWD] + "/" + str + "/";
  }
  if (str == "/")
    return "/";
  array = explode(str, "/") - ({ "" });
  for (i = 0; i < sizeof(array); i++) {
    if (array[i] == "..")
    {
      if (i < 1)
        return "/";
      if (i == 1)
        array1 = ({ "." });
      else
        array1 = array[0..i - 2];
      if (i + 1 <= sizeof(array) - 1)
        array1 += array[i + 1..sizeof(array) - 1];
      array = array1;
      i -= 2;
    }
    else
      if (array[i] == ".")
        array[i] = 0;
  }
  if (array)
    str = implode(array, "/");
  else
    str = "";
  return "/" + str;
}      /* get_path() */

string desc_object(mixed o){
  string str;

  if (!o) return "** Null-space **";
  if (!catch(str = (string)o->short()) && str) return str;
  if (!catch(str = (string)o->query_name()) && str) return str;
  return file_name(o);
} /* desc_object() */

string desc_f_object(object o) {
  string str, tmp;

  str = desc_object(o);
  if (o && str != file_name(o)) {
    if (tmp)
      str += " (" + tmp + ")";
    else
      str += " (" + file_name(o) + ")";
  }
  return str;
} /* desc_f_object() */

string get_cfile(string str) {
  if (sscanf(str, "%*s.%*s") != 2)
    str += ".c";
  return str;
} /* get_cfile() */

static void do_update(string name, int fd) {
   string pname, err;
   int i, j;
   object *invent, rsv, env, dup, loaded, ov;
   mixed static_arg, dynamic_arg;

   "room/void"->bingle_bingle();

   rsv = find_object("room/void");  /* RSV = Room Slash Void */
   if (!rsv) { /* Die in horror */
      socket_write(fd, "530 The void is lost!\r\n");
      return;
   }
   name = get_cfile(name);
   ov = find_object(name);
   if (!ov) {
     if(file_size(name) >= 0) {
       if (!(err = catch(name->bing_with_me())))
         socket_write(fd, sprintf("530 Loaded %s.\r\n", name));
       else
         socket_write(fd, sprintf("530 Failed to load %s, error: %s\r\n",
    name, err));
     }
     else
       socket_write(fd, sprintf("530 File %s does not exist.\r\n", name));
     return;
   }
   env = environment(ov);
   invent = all_inventory(ov);

   for (j = 0; j < sizeof(invent); j++) 
     invent[j]->move(rsv);

   pname = file_name(ov);
   if (sscanf(pname, "%s#%*d", pname) != 2) { /* a room ? */
     ov -> dest_me();
     if (ov) ov->dwep();
     if (ov) destruct(ov);
     file_size("/secure/master");
     if (!ov)
       ov = find_object(pname);
     call_other(pname, "??");
     ov = find_object(pname);
   } else {
     loaded = find_object(pname);
     static_arg = ov->query_static_auto_load();
     dynamic_arg = ov->query_dynamic_auto_load();
     if (loaded) loaded->dest_me();
     if (loaded) loaded->dwep();
     if (loaded) destruct(loaded);

     dup = clone_object(pname);
     if (dup && ov) {
       ov -> dest_me();
       if (ov) ov->dwep();
       if (ov) destruct(ov);
       ov = dup;
       if (static_arg)
         ov->init_static_arg(static_arg);
       if (dynamic_arg)
         ov->init_dynamic_arg(dynamic_arg);
     }
   }

   if (!ov) {
     socket_write(fd, "530 I seem to have lost your object.\r\n");
     return;
   }

   for (j = 0; j < sizeof(invent); j++)
     if (invent[j]) invent[j]->move(ov);

   if (env) ov->move(env);
   socket_write(fd, sprintf("530 Updated %s.\r\n", desc_f_object(ov)));
} /* do_update() */ 
 
void  check_connections()
{
  int *bits, i;

  bits = keys(socket_info);
  i = sizeof(bits);
  while (i--)
    if ((socket_info[bits[i]][LAST_DATA]+socket_info[bits[i]][IDLE]) <= time())
    {
      socket_write(bits[i], 
  sprintf("421 Timeout (%d seconds): closing control connection.\r\n",
  socket_info[bits[i]][IDLE]));
      socket_close(bits[i]);
      map_delete(socket_info, bits[i]);
    }
  call_out("check_connections", 5 * 60);
}      /* check_connections() */

int check_dots(mixed arg) {
  return (arg[0] != ".." && arg[0] != ".");
}

