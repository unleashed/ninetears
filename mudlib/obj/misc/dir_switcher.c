/*
 * coded by Raskolnikov to remove the inertia that might keep
 * Thanes from using the iou_shop...Oct 96
 *
 */

inherit "/std/item.c";

string old_path, new_path;

void setup() {
    set_name("switcher");
    add_alias("switch");
    set_main_plural("Switchers");
    set_short("Thane Directory Switch Indicator");
    set_long("Thane Directory Switch Indicator\n\n"
      "A small pendant carried around to aid in IOU recovery.\n");
    set_read_mess("Please use this device to indicate when "
      "directory contents have been moved so that IOU reclaiming "
      "for the affected directories can be done by the players.\n\n"
      "To use type 'switch <old_path> <new_path>'\n\n");
    reset_drop();
}

void init() {
    ::init();
    add_action("do_switch", "switch");
}

void do_switch(string str) {
    int check;

    check = sscanf(str, "%s %s", old_path, new_path);
    if(check != 2) {
	notify_fail("Usage: switch <old_path> <new_path>\n");
	return 0;
    }
    tell_object(this_player(), "Have you entered the paths "
      "correctly?\nOld path: "+old_path+"\nNew path: "+new_path+"\n");
    input_to("path_check");
    return 1;
}

void path_check(string str) {
    switch(str) {
    case "y":
    case "yes":
   write_file("/open/SWITCHED_DIRS",
	  old_path+" "+new_path+"\n", 0);
	tell_object(this_player(), "Ok.\n");
	break;
    default:
	tell_object(this_player(), "Error:  Switch not entered.\n");
	break;
    }
    return 1;
}
