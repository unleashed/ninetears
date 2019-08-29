inherit "/std/races/insect";

void setup()
{
    set_name("varniad");
    ::setup();
    set_long("A Varniad drone, the only kind of Varniad you are likely "
      "to see (and live). The race as a whole is reclusive, lawful and "
      "finds the Gods irrelevant. All unmated Varnaid drones "
      "are Paladins.\n");
}

void start_player(object player)
{
    object ob;
    player->set_gender(1);
    player->set_guild_ob("/std/guilds/warriors/paladin.c");
    ob = clone_object("/std/races/items/varntxt.c");
    if(ob) ob->move(player);
    player->remove_language("common");
    ::start_player(player);
}
void set_racial_bonuses()
{
   previous_object()->adjust_bonus_int(4);
   previous_object()->adjust_bonus_wis(-2);
   previous_object()->adjust_bonus_dex(-1);
   previous_object()->adjust_bonus_con(-1);
}
