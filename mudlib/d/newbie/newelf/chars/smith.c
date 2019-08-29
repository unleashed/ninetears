
/* Coded by Darknight : Thane of Nothing, April 95 */

inherit "obj/monster";

void setup() {
    set_name("eldevan");
    add_plural("eldevans");
    set_main_plural("eldevans");
    add_alias("smith");
    add_alias("keeper");
    add_alias("shop keeper");
    set_short("Eldevan");
    set_long("This is Eldevan, he used to tend his shop all day before "
      "he passed it on to his son, Geldon, who shares his penchant "
      "in making good armours and weapons against the wood imps. "
      "Eldevan is sitting on a stump in this quiet area of the "
      "forest crying.\n\n");
    set_race("elf");
    set_guild("fighter");
    set_level(12);
    set_random_stats(12,18);
    set_dex(18);
    set_gender(1);
    set_wimpy(0);
    set_al(15);
    new("baseobs/armours/bronzeplate.c")->move(this_object());
    new("baseobs/weapons/scimitar.c")->move(this_object());
    init_equip();
    set_str(20);
    load_chat(50,({
	1,"'Hello there, Traveler. I would greet you with more enthusiasm, "
	"but my wife was slain by wood imps. You must understand my silence. "
	"I do not even have anything to remember her by.",
	1,"'I remember well the day I brought her the pendant from Arok. "
	"this was long before we lived here, when my son and I worked deep "
	"in the high forest."}));
}

