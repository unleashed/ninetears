/*
 * this does an ls, now that get_dir has been written 
 * Modified by Turrican 13-7-95 with nicked code from TMI-2's ftpd.
 * - Added different options.
 * Modified by Dyraen@Rod, made external. 5-Nov-95
 */

#include <standard.h>
#include <cmd.h>
#include <ls.h>

#define FPERM "/secure/fperm"

#define CREATOR (master()->author_file(sprintf("%s/%s", str, direc[i][0]))? \
                master()->author_file(sprintf("%s/%s", str, direc[i][0])): \
                "Root")
#define DOMAIN  (master()->domain_file(sprintf("%s/%s", str, direc[i][0]))? \
                master()->domain_file(sprintf("%s/%s", str, direc[i][0])): \
                "Root")
#define CREATOR_D (master()->author_file(sprintf("%s/%s/.", str, direc[i][0]))? \
                master()->author_file(sprintf("%s/%s/.", str, direc[i][0])): \
                "Root")
#define DOMAIN_D (master()->domain_file(sprintf("%s/%s/.", str, direc[i][0]))? \
                master()->domain_file(sprintf("%s/%s/.", str, direc[i][0])): \
                "Root")

inherit CMD_BASE;

object tp;
 
void setup() {
  position = CREATOR_CMD;
}
 
string query_usage() {
  return "-acdflopCF [directory|filename]";
}
 
string query_short_help() {
  return "List files in current or specified directories";
}

string dir_entry(string path, string name, int mask, object me) {
  int size; 
  string *obs, tmp;

  size = file_size(me->get_path(path+name));
  if (size == -2) {
    obs = get_dir((tmp = me->get_path(path+name))+
          (tmp == "/"?"":"/"));
    if (!obs)
      size = -1;
    else
      size = sizeof(obs);
    if (mask & MASK_F)
      name += "/";
  } else {
    if (virtual_find_object(path+name)) {
      if (mask & MASK_F)
        name += "*";
    }
    size = (size / 1024) + 1;
  }
  if (size < 1000)
    return "    "[0..3-strlen(size+"")]+size+" "+name;
  return size+" "+name;
} /* dir_entry() */
 
int ls(string str, int mask, object me) {
  string *direc, *bit, *bing, bong, path;
  int i, j, k, size;
 
  seteuid(geteuid(me));
  path = str; 
  if (file_size(str) == -2 && str[strlen(str)-1] != '/' && !(mask & MASK_D))
    path += "/";
  if (mask & MASK_A)
    path += "*";
  direc = get_dir(path);
  if (!direc) {
    notify_fail("No files..\n");
    return 0;
  }
  if (!sizeof(direc)) {
    notify_fail("No files.\n");
    return 0;
  }
  if (file_size(path) == -2) {
    if (path[strlen(path)-1] != '/')
      path += "/";
  } else {
    bit = explode(path, "/");
    bit = bit[0..sizeof(bit)-2];
    path = "/"+implode(bit,"/")+"/";
  }
  if(path == "//")
    path = "/";
  write("Dir of: "+path+"\n");
  bing = allocate(sizeof(direc));
  j = sizeof(direc);
  if (!(mask & MASK_A))
    direc = filter_array(direc, "check_dots", this_object(), 0);
  if (!(mask & MASK_C) && !(mask & MASK_L)) {
    if (!(mask & MASK_F) && !(mask & MASK_O)) {
      bong = sprintf("%-=*s\n", me->query_cols(),
        implode(direc, "\n"));
      bing = explode(bong, "\n");
    }
    else for (i=0; i < j; i++) {
      if (file_size(path+direc[i]) == -2 || direc[i] == "..")
        if (mask & MASK_O)
          bing[i] = sprintf("%s%-=*s", "%^GREEN%^",
            (int)me->query_cols()+8, direc[i]+"%^RESET%^"+
            (mask & MASK_F?"/":""));
        else
          bing[i] = sprintf("%-=*s", me->query_cols(),
            direc[i]+"/");
      else if (virtual_find_object(path+direc[i]))
        if (mask & MASK_O)
          bing[i] = sprintf("%s%-=*s", "%^MAGENTA%^",
            (int)me->query_cols()-1, direc[i]+"%^RESET%^"+
            (mask & MASK_F?"*":""));
        else
          bing[i] = sprintf("%-=*s", me->query_cols(),
            direc[i]+"*");
      else
        bing[i] = sprintf("%-=*s", me->query_cols(), direc[i]);
    }
    bong = implode(bing, "\n");
  } else if (!(mask & MASK_L)) {
    j = sizeof(direc);     
    for ( i = 0; i < j; i++ ) {
      if ( strlen( direc[ i ] ) > 35 ) {
        write(dir_entry(path, direc[i], mask, me)+"\n");
        bing = delete(bing, i, 1);
        direc = delete(direc, i--, 1);
        j--;
        continue;
      } else 
        bing[i] = dir_entry(path, direc[i], mask, me)+"\n";
    }
    bong = sprintf( "%#-*s\n", me->query_cols(),
      implode(bing, ""));
    if (mask & MASK_O) {
/* Boy, it's hard to work with colors and sprintf. *sigh* 
   *especially* in column mode :-( */
      i = j;
      while (i--) {
        if (file_size(path+direc[i]) == -2 || direc[i] == "..")
          bong = replace_string(bong, " "+direc[i], 
            sprintf(" %s%s%s", "%^GREEN%^", direc[i], "%^RESET%^"));
        else if (virtual_find_object(path+direc[i]))
          bong = replace_string(bong, " "+direc[i], 
            sprintf(" %s%s%s", "%^MAGENTA%^", direc[i], "%^RESET%^"));
        else
/* Believe me, it's needed. */
          bong = replace_string(bong, " "+direc[i],
            sprintf(" %s%s", "%^WHITE%^", direc[i]));
      }
    }
  } else {
    string tmp, tmp2, fname;
    mixed *stats;
    int *count;
    object loaded;
    /* if path is a directory get contents */
    if ( file_size( str ) == -2 && !(mask & MASK_D)) {
        if ( str[ strlen( str ) - 1 ] == '/' )
            str += "*";
        else
            str += "/*";
    }
      /* begin long "list" */
    direc = get_dir( str, -1 );
    if (!(mask & MASK_A))
      direc = filter_array(direc, "check_dots", this_object(), 1);
    if (!direc || !(size = sizeof(direc)))
        return 0;

    bit = allocate(size);
    count = allocate(size);

    i = strsrch(str, '/', -1);
    if (i >= 0)
        str = str[0..i];

    for (i = 0; i < size; i++) {
      reset_eval_cost();
      /* process timestamp */
      tmp2 = ctime((direc[i])[2]); /* get last modified timestamp */
      if ((direc[i])[2] + (365 * 24 * 60 * 60) < time()) {
        /* MMM DD  YYYY */
        tmp = sprintf("%s  %s", tmp2[4..9], tmp2[20..23]);
      } else {
        /* MMM DD hh:mm */
        tmp = tmp2[4..15];
      }

      j = (direc[i])[1];   /* get filesize */
      if (j == -2) {
        count[i] = 1;
        /* directory */
        bit[i] = sprintf("%-=*s", (me->query_cols()+
          (mask & MASK_O?17:0)),
          sprintf("drwxr%cx%c%c%c %3d %-11.11s %-11.11s [%4d] %12s %s%s%s%s",
          (master()->valid_write(sprintf("%s%s/fl.uff",str,direc[i][0]),
          DOMAIN_D, "get_dir")?'w':'-'),
          (master()->valid_read(sprintf("%s%s",str,direc[i][0]),
          "NOBODY", "get_dir")?'r':'-'),
          (master()->valid_write(sprintf("%s%s/fl.uff",str,direc[i][0]),
          "NOBODY", "get_dir")?'w':'-'),
          (master()->valid_read(sprintf("%s%s",str,direc[i][0]),
          "NOBODY", "get_dir")?'x':'-'),
          sizeof(filter_array((get_dir(me->get_path(
          sprintf("%s%s/*", str, direc[i][0])))?get_dir(
          me->get_path(sprintf("%s%s/*", str, direc[i][0]))):({ })),
          "is_dir", this_object(),
          sprintf("%s%s", str, direc[i][0])))+(direc[i][0..1] == ".." &&
          str == "/"?2:0),
/*
          (FPERM->query_fperms(str+direc[i][0])?
          FPERM->query_fperms(str+direc[i][0])[0]:CREATOR_D), DOMAIN_D,
*/
          CREATOR,DOMAIN,
          sizeof(get_dir(me->get_path(sprintf("%s%s/*", str, direc[i][0])))),
          tmp, (mask & MASK_O?"%^GREEN%^":""),
          (direc[i][0]), (mask & MASK_O?"%^RESET%^":""),
          (mask & MASK_F?"/":"")));
      } else {
        /* file */
        count[i] = 0;
        fname = (""+direc[i][0])[0..19];
        loaded = virtual_find_object(str+direc[i][0]);
        bit[i] = sprintf("%-=*s", (me->query_cols()+
          ((mask & MASK_O) && loaded?19:0)), 
          sprintf("-rw%c%c%c-%c%c-   1 %-11.11s %-11.11s %6d %12s %s%s%s%s",
          (loaded ? 'x' : '-'),
          (master()->valid_read(sprintf("%s/%s",str,direc[i][0]),
          DOMAIN, "get_dir")?'r':'-'),
          (master()->valid_write(sprintf("%s/%s",str,direc[i][0]),
          DOMAIN, "get_dir")?'w':'-'),
          (master()->valid_read(sprintf("%s/%s",str,direc[i][0]),
          "NOBODY", "get_dir")?'r':'-'),
          (master()->valid_write(sprintf("%s/%s",str,direc[i][0]),
          "NOBODY", "get_dir")?'w':'-'),
/*
          (FPERM->query_fperms(str+direc[i][0])?
          FPERM->query_fperms(str+direc[i][0])[0]:CREATOR),DOMAIN, j, tmp, 
*/
          CREATOR,DOMAIN, j, tmp,
          ((mask & MASK_O) && loaded?"%^MAGENTA%^":""),
          fname, ((mask & MASK_O) && 
          loaded?"%^RESET%^":""),
          (loaded?(mask & MASK_F?"*":""):"")));
      }
      bong = implode(bit, "\n");
    }
  }
  if (mask & MASK_P)
    me->more_string( bong, str );
  else
    write(bong+"\n");
  return 1;
} /* ls() */

int check_dots(mixed arg, int flag) {
  if (flag)
    return (arg[0][0..0] != "." );
  return (arg[0..0] != "." );
}

int is_dir(mixed arg, string path) {
  if (!tp)
    return (file_size(this_player()->get_path(sprintf("%s/%s", path, arg))) 
            == -2);
  else
    return (file_size(tp->get_path(sprintf("%s/%s", path, arg))) == -2);
}

static int cmd(string str, object me) {
string flags;
int mask, i;

  tp = me;
  if (!str) str = "";
  if ( (sscanf(str,"-%s %s",flags,str) == 2) ||
       (sscanf(str,"-%s", flags) == 1) )
    for (i=0;i<strlen(flags);i++)
      switch(flags[i..i]) {
        case "a": mask |= MASK_A;
                  break;
        case "C":
        case "c": mask |= MASK_C;
                  break;
        case "d": mask |= MASK_D;
                  break;
        case "F":
        case "f": mask |= MASK_F;
                  break;
        case "l": mask |= MASK_L;
                  break;
        case "o": mask |= MASK_O;
                  break;
        case "p": mask |= MASK_P;
                  break;
        default:
      }
  if (!mask) mask = 42;
  if (str[0..0] == "-") str = "";
  str = me->get_path(str);
  return ls(str, mask, me);
} /* cmd() */
