/* Massive security hole.  filled by Hamlet. */
int exec(object dest, object source) {
  string fname;
  int obnum;

  sscanf(file_name(previous_object()),"%s#%d",fname,obnum);

  if(fname != "/secure/login")
    return 0;

  return efun::exec(dest,source);
}
