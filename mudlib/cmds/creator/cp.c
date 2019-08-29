#include <standard.h>
#include <cmd.h>
inherit CMD_BASE;

void setup(){

position = 1;
}



static int cmd(string str, object me) {
  string *filenames, text, dest, *fnames;
  int loop, fs;

  if (this_player(1) != this_player()) return 0;

  if(!str) {
    notify_fail("Usage : cp file [file|dir...]\n");
    return 0;
  }
  fnames = explode(str, " ");
  filenames = this_player()->get_files(implode(fnames[0..sizeof(fnames) -2], "/"));
  if(!sizeof(filenames)) {
    notify_fail("Usage : cp file [file|dir...]\n");
    return 0;
  }
  dest = fnames[sizeof(fnames) - 1];
  dest = this_player()->get_path(dest);
   if(!dest) {
    tell_object(this_player(),"No destination\n");
    return 1;
  }
  for(loop = 0; loop < sizeof(filenames); loop++) {
    str = filenames[loop];
    text = read_file(str);
    if(!text) {
      tell_object(this_player(),"No such file : " + str + "\n");
      continue;
    }
    fs = file_size(dest);
    if(fs == -2) {
      string *names;

      names = explode(str, "/");
      fs = file_size(dest + "/" + names[sizeof(names) - 1]);
      if(fs != -1) {
        tell_object(this_player(),"file exists " + dest + "/" + names[sizeof(names) - 1] + "\n");
        continue;
      }
      write_file(dest + "/" + names[sizeof(names) - 1], text);
    }
    else {
      if(fs != -1) {
        tell_object(this_player(),"File exists : " + dest + "\n");
        continue;
      }
      write_file(dest, text);
    }
  }
  tell_object(this_player(),"Ok.\n");
  return 1;
} /* cp_file() */


