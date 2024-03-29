/* The first attempt on a Retire command.
 * It will make the players able to delete their own charachters.
 * Baldrick march '94
 * Put it in /secure/master and add it to master.c (#include).
 * Add an add_action and a call in player.c (test on force!)
 */
#define MAX_RETRYS 1
#define BANK_HANDLER "/obj/handlers/bank_handler"
#define POSTAL_D "/obj/handlers/postal_d"

string password;
int no_times;

int put_password(string str);
int do_retirejob(mixed name);

int try_retire() 
  {
  if(this_player()->query_creator())
    {
    notify_fail("Los Inmortales no pueden retirarse sin el permiso de un Dios o Administrador.\n");
    return 0;
    }
  write("Esto borra la ficha que estas jugando. Mejor que estes seguro de " +
	"lo que haces. No insertes tu password si te arrepientes.\n\n");
  write("Inserta tu password: ");
  input_to("put_password");
  } /* logon() */
 
int test_password(string name, string pass) 
  {
  string tmp;

  if (!stringp(name) || strlen(name) < 2 || sscanf(name, "%s %s", tmp, tmp)
      || name[0] == '.' || sscanf(name, "%s..%s", tmp,tmp))
    return 0;
  if(!restore_object("/players/"+name[0..0]+"/"+name,1))
    return 0;
  return crypt(pass, password) == password;
} /* test_password() */

int put_password(mixed str)
  {
  string playername;

  playername = this_player(1)->query_name();
  write("\n");
  if (!str)
    {
    write("No password, no retire!\n");
    return 0;
    } /* if str == "" */
  if (!test_password(playername, str))
    {
    write("Password incorrecto, no retirado.\n");
    return 0;
    } /* if (password .. */
  do_retirejob(playername);
  return 1;
} /* put_password() */

/* The deleting of the player. */
/* have to get root access to be able to do the RM of the file. */
/* Done by putting the whole thingie in the master. */

/*
 * Made this puppy static before someone else finds it!
 *  -- Wahooka
 */

int do_retirejob(string name)
  {
  // write ("You made it !" + name + "\n");
  this_player()->add_property("guest",1);

  rename("/players/"+name[0..0]+"/"+name+".o","/players/oldplayers/"+name+".o."+time());

  /* remove the mails */
  /* May make problem if the player don't have a mail.o file.. */
  // rm ("/save/post/" + name + ".o");

   // Maybe THIS will work, and actually free the disk space - Radix
   POSTAL_D->retire_user(name);

  /* Hmm.. should add a delete of bank accounts, think i have some code. */
  /* WHY does the BANK_HANDLER thingie work here and not in bank.c ? */
  // BANK_HANDLER->refresh_account(name);

  write ("Ahora eres un invitado. Sal para olvidarte de tu ficha.\n");
  /* Wonerflug1997, adding a log til someone fixes the bug */
  log_file("RETIRAR", this_player()->query_cap_name()+" se ha retirado en "+ctime(time())+".\n");
  return 0;

} /* do_retire */

int query_prevent_shadow() { return 1; }

