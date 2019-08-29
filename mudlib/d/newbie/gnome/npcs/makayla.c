inherit "obj/monster.c";
#include "path.h"
object parch;
void setup()
{
    set_name("makayla");
    set_short("MaKayla");
    set_long("MaKayla is a very young female gnome.  Unlike most gnomes "
      "her age, she looks extremely sad for some reason.  "
      "Looking into her eyes, you can almost see a tear "
      "forming.\n");
    set_max_hp(1);
    set_str(2);
    set_dex(2);
    set_con(2);
    set_wis(2);
    set_int(2);
    set_cha(20);
    set_level(1);
    set_al(-100);
    set_gender(2);
    clone_object("/d/newbie/gnome/items/vase.c")->move(this_object());
    load_chat(60,
      ({
	1, "MaKayla pouts.",
	1, "Makayla wipes a tear from her eye.",
	1, "MaKayla wipes a tear from her eye.",
	1, "MaKayla says: I wish I had something to cheer me up."
      }));
}
void init()
{
    add_action("do_give","give");
    ::init();
}
int do_give(string str)
{
    call_out("quest_play",2,this_player());
    return 0;
}
int quest_play(object plyr)
{
    int i, maxi;
    object *olist=all_inventory(this_object());

    maxi = sizeof(olist);
    if(!maxi) return 1;
    for(i=0; i<maxi; i++)
	if((string)olist[i]->query_short() == "white rose")

	    olist[i]->dest_me();
    write("Makayla takes the rose and places it in her crystal vase. "
      "She thanks you with a sniffle and says 'Wait here for a second.'\n\n"
      "She returns with a small piece of parchment and gives it to you. "
      "She tells you that she found it in the woods and it was "
      "helpful.\n\nMakayla smiles and waves happily to you.\n\n");
    parch = new(MISC+"parchment");
    parch->move(plyr);
    return 1;
}

