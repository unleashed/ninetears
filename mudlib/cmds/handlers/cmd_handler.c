// /global/cmd/cmd_handler.c  -- Object based command handler
/* Removed the #ifdefs (don't ask me why.
 * Added verb
 * Baldrick, dec '97
 */

#include <standard.h>
#include <cmd.h>

int cmd_make_hash(int i);

static mapping cmd_dirs =
([
	"/cmds/player/":		({0,		"Player"}),
	"/cmds/creator/":		({BUILDER_CMD,	"Builder"}),
	"/cmds/patron/":		({PATRON_CMD,	"Patron"}),
	"/cmds/thane/":			({THANE_CMD,	"Thane"}),
	"/cmds/demi/":			({DEMI_CMD,"Demi-God"}),
	"/cmds/god/":			({GOD_CMD,"God"}),
	"/net/cmds/":			({0,		"InterMUD network"}),
	"/cmds/handler/cmds/":		({0,		"Command handler"}),
]);

static mapping cmd_hash = ([ ]);  	// For commands and their objects
static mapping cmd_aliases = ([ ]);	// For command aliases
static string last_dir = "";      	// Last directory a command was found
static string current_verb;		// Used by query_verb() efun

void create()
{
	seteuid(getuid());
	current_verb = 0;
	cmd_make_hash(0);
}

void dest_me()
{
	destruct(TO);
}

int clean_up()
{
	return 0;
}

// The simul for query_verb() queries this if efun::query_verb() == 0
string query_current_verb() { return current_verb; }

// The real code :)

string find_cmd(string verb)
{
	// Try to find the command for 'verb', or return 0
	// if not found. Remember it's location..

	string s, *dirs;
	int i;

	if(cmd_hash[verb])
	{
		last_dir = cmd_hash[verb]["dir"];
		return cmd_hash[verb]["file"];
	}

	dirs = m_indices(cmd_dirs);

	for(i=0; i<sizeof(dirs); i++)
	{
		s = dirs[i] + verb;
		if(file_size(s+".c") > 0)
		{
			last_dir = dirs[i];
			cmd_hash[verb] = ([ "file" : s, "count" : 0 ]);
			cmd_hash[verb]["dir"] = last_dir;
			return s;
		}
	}
	return 0;
}

int cmd(string verb, string tail, object thisob)
{
	object ob;
	string s, euid;
	int ret;
        string orig_verb = verb;

	seteuid("Root");
	euid = geteuid(thisob);

	s = cmd_aliases[verb];
	if(stringp(s) && s!=0)
		verb = s;

	s = find_cmd(verb);

	if(!s)
          return 0;       

	// Check their position now...
	switch(cmd_dirs[last_dir][0])
	{
	case GOD_CMD:
               if(!MASTER->high_programmer(euid))
			return 0;
		break;

	case DEMI_CMD:
               if(!MASTER->query_lord(euid))
			return 0;
		break;

	case THANE_CMD:
		if(!thisob->query_thane())
			return 0;
		break;

	case PATRON_CMD:
		if(!thisob->query_patron())
			return 0;
		break;

	case BUILDER_CMD:
		if(!thisob->query_creator())
			return 0;
		break;
	}

	cmd_hash[verb]["count"]++;

	if(!(ob = find_object(s)))
	{
		catch(s->FORCE_LOAD());
		ob = find_object(s);
	}
	if(!ob)
	{
		notify_fail("Error loading command.\n");
		return 0;
	}

	if(ob->_query_doclone())
		ob = clone_object(s);

	seteuid("CMD");
	current_verb = verb;
	//ret = (int)ob->_cmd(tail, thisob);
	ret = (int)ob->_cmd(tail, thisob, orig_verb);
	current_verb = 0;

	if(ob->_query_dodest() || ob->_query_doclone())
		ob->dest_me();

	return ret;
}

int cmd_make_hash(int verbose)
{
	/* This goes and finds _all_ the valid commands in the listed
	 * paths, and also works out the command aliases from the 
	 * _CMD_ALIASES file in each directory.
	 */
	string *paths, *files, s, *a;
	int i, j, k, l, count;

	seteuid("Root");
	cmd_hash = ([ ]);
        cmd_aliases = ([ ]);
	count = 0;

	paths = keys(cmd_dirs);
	for(i=0; i<sizeof(paths); i++)
	{
		if(verbose) write("Scanning directory: "+paths[i]+"\n");
		files = get_dir(paths[i]+"/*.c");

		for(j=0; j<sizeof(files); j++)
		{
			a = explode(files[j], ".");
                        s=implode(a[0..sizeof(a)-1], ".");
			if(verbose) write("    Command: "+s+"\n");
			cmd_hash[s] = 
			([
				"file":		paths[i]+s,
				"count":	0,
				"dir":		paths[i],
			]);
			count++;
		}

		s = read_file(paths[i]+"/_CMD_ALIASES");
		if(stringp(s) && s!=0 && s!="")
		{
			a = explode(s, "\n");
			for(j=0; j<sizeof(a); j++)
			{
				k = 0;
				files = explode(replace(a[j],"\t", " "), " ");
				if(sizeof(files) && files[0] == "alias") k++;
				if(sizeof(files) > k)
				{
					for(l=k+1; l<sizeof(files); l++)
					if(files[l] != files[k])
					{
						if(verbose) write("    Alias "+
							files[l]+" to "+
							files[k]+"\n");
						cmd_aliases[files[l]]= files[k];
					}
				}
			}
		}
	}
	seteuid("CMD");
	return count;
}

////

mapping query_cmds() { return cmd_dirs; }
mapping query_hash() { return cmd_hash; }
string query_last_dir() { return last_dir; }
mapping query_aliases() { return cmd_aliases; }
string query_alias(string verb) { return cmd_aliases[verb]; }

