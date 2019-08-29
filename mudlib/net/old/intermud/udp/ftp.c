/*
 * WARNING: Be VERY careful with filenames and permissions in this module.
 *          Look out for filenames such as: "../secure/master.c"
 */

#include <newudp.h>

#ifdef CDLIB
#include <std.h>
#endif

#ifdef ZEBEDEE
#include <defs.h>
inherit "/sys/format";
#endif

#ifndef DATE
#define DATE		ctime(time())[4..15]
#endif

/* Define if you want to allow uploads to your site. */
#undef PUTFILE

#define FTP_ROOT_DIR	"/open/"
#define FTP_LOG_FILE	"FTP"

#define COMMAND		"cmd"
#define USER		"user"
#define REMOTE		"remote"
#define LOCAL		"local"

#ifndef COMPAT_FLAG
create() {
    seteuid(getuid());
}
#endif

string valid_file_name(string file) {
    /* Disallow filenames that contain ".."
     * This is a serious security risk. */
    if (stringp(file) && member_array("..", explode(file, "/")) == -1)
	return file;
}

void udp_ftp(mapping data) {
    mapping ret;
    string str;
    int i;

    if (!data[COMMAND])
	return;
    if (!data[REMOTE])
	data[REMOTE] = "";
    ret = ([
	REQUEST: REPLY,
	RECIPIENT: data[SENDER],
	ID: data[ID],
	USER: data[USER],
    ]);
    switch(data[COMMAND]) {
	case "dir":
	    ret[DATA] = "ftp@" + LOCAL_NAME +
	    ": Dir failed: illegal path.\n";
	    if (!(data[REMOTE] = valid_file_name(data[REMOTE])))
		break;
	    /* CD version. */
	    str = FTP_ROOT_DIR +
	    (data[REMOTE] == "" ? data[REMOTE] : data[REMOTE] + "/");
	    if (!pointerp(data[DATA] = get_dir(str + "*")))
		break;
	    data[DATA] -= ({ ".", ".." });
	    for(ret[DATA] = 0, i = sizeof(data[DATA]); i--; ) {
		if (ret[DATA])
		    ret[DATA] = data[DATA][i] + ":" +
		    file_size(str + data[DATA][i]) + ":" + ret[DATA];
		else
		    ret[DATA] = data[DATA][i] + ":" +
		    file_size(str + data[DATA][i]);
	    }
	    ret[COMMAND] = "dir";
	    ret[REMOTE] = data[REMOTE];
	    break;
	case "get":
	    if (!(data[REMOTE] = valid_file_name(data[REMOTE])) ||
	    file_size(FTP_ROOT_DIR + data[REMOTE]) < 0) {
		ret[DATA] = "ftp@" + LOCAL_NAME +
		": Get failed: Invalid filename.\n";
		break;
	    }
	    /* read_file() will typically read up to 50k in one go and
	     * intermud transfer is likely to be too unreliable to enable
	     * large transfers across any distance. */
	    ret[DATA] = read_file(FTP_ROOT_DIR + data[REMOTE]);
	    ret[LOCAL] = data[LOCAL];
	    ret[REMOTE] = data[REMOTE];
	    ret[COMMAND] = "get";
	    break;
#ifdef PUTFILE
	case "put":
	    /* We don't want anonymous puts. */
	    if (!data[SENDER] || !data[USER])
		return;
	    if (!(data[REMOTE] = valid_file_name(data[REMOTE])))
		ret[DATA] = "ftp@" + LOCAL_NAME +
		 ": Put failed: Illegal filename.\n";
	    if (!data[DATA])
		ret[DATA] = "ftp@" + LOCAL_NAME +
		 ": Put failed: No file.\n";
	    if (file_size(FTP_ROOT_DIR + data[REMOTE]) != -1)
		ret[DATA] = "ftp@" + LOCAL_NAME +
		 ": Put failed: File already exists: " + data[REMOTE] + "\n";
	    if (!write_file(FTP_ROOT_DIR + data[REMOTE], data[DATA]))
		ret[DATA] = "ftp@" + LOCAL_NAME +
		 ": Put failed: Error in writing file.\n";
	    else {
		ret[DATA] =
#ifdef ZEBEDEE
		wrap("ftp@" + LOCAL_NAME + ": Local file \"" +
		data[LOCAL] + "\" written to remote file \"" +
		data[REMOTE] + "\"", 1) + "\n";
#else
		sprintf("%-80=s", "ftp@ " + LOCAL_NAME + ": Local file \"" +
		data[LOCAL] + "\" written to remote file \"" +
		data[REMOTE] + "\"\n");
#endif
		log_file(FTP_LOG_FILE, DATE + ": " + FTP_ROOT_DIR +
		data[REMOTE] + " written by:\n" + data[USER] + " (" +
		data[SENDER] + ") @" + data[NAME] + "\n\n");
	    }
	    break;
#endif
	default:
	    ret[DATA] = "ftp@" + LOCAL_NAME + ": Unknown command: " +
	    data[COMMAND] + "\n";
	    break;
    }
    INETD->send_udp(data[NAME], ret);
}
