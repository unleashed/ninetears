
#define DAY_TO_SEC 86400
#define DEFAULT_PROTECT 12  /* days */

  /* inheritance */
inherit "/d/ss/daggerford/thieves/vguild.c";

  /* global variables */
mixed *protect;

  /* function declarations */
void update_protect();

  /* function definitions */
void create() {
  protect = ({ });
  ::create();
}

mixed *query_protect() {
  load_it();
  update_protect();
  return protect;
}

int add_protect(string name, int days) {
  int until, i;

  update_protect();
  if (days < 1)
    days = DEFAULT_PROTECT;
  until = time() + (days * DAY_TO_SEC);
  name = lower_case(name);
  if ((i = member_array(name, protect)) != -1)
    protect[i+1] += days * DAY_TO_SEC;
  else
    protect += ({ name, until });
  ::save_it();
  return until;
}

int remove_protect(string name) {
  int i;

  name = lower_case(name);
  if ((i = member_array(name, protect)) == -1)
    return 0;
  protect -= ({ protect[i], protect[i+1] });
  ::save_it();
  return 1;
}

int set_protect(string name, int days) {
  int i;

  update_protect();
  name = lower_case(name);
  if ((i = member_array(name, protect)) == -1)
    return (add_protect(name, days));
  protect[i+1] = days * DAY_TO_SEC;
  ::save_it();
  return protect[i+1];
}

void update_protect() {
  int i, n, now;

  now = time();
  for (i = 0, n = sizeof(protect); i < n; i += 2)
    if (now > protect[i+1])
      remove_protect(protect[i]);
}

int add_seconds(string name, int secs)
{
  int i;

  name = lower_case(name);
  if ((i = member_array(name, protect)) != -1)
    protect[i+1] = time() + secs;
  else
    protect += ({ name, time() + secs });
  save_it();
  return 1;
}

