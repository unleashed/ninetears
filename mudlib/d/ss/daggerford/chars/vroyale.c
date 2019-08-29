/* Vroyale, a nice chap.
 * Will attack all newbiekillers.. 
 * not many will be able to kill this guy..
 * Baldrick, feb '95
 */

inherit "/obj/monster";

void setup() {    
   add_property("NO_BUDGE",1);
      set_name("vroyale");
      set_short("Vroyale");
      set_race("human");
      set_gender(1);
      set_class("cleric");
      set_move_after(30,30);
      add_move_zone("city");
    set_max_hp(300);
      set_hp(300,this_object());
   set_max_gp(1000);
   set_gp(1000);
      set_str(16);
      set_dex(12);
      set_con(18);
      set_int(7);
      set_wis(27);
      set_cha(5);
      set_level(60);
      set_thac0(0);
      set_long(
      "   Some say that a good man turned bad makes the worst enemy, "+
      
       "Vroyales face disabuses you of that notion, from what he wears "+
      "you can tell he's a Tymora priest, however he's obviously seen a lot of "+
      "pain, much of it, it would seem, from the giving not receiving end. "+
      "His eyes burn as he looks at you, and you shudder as he searches your soul. \n"+
      " ");
      adjust_money(random(20),"copper");
      load_chat(10, ({
      1,"'Be careful, or you'll end up like me, and shudders.\n",
      1,"'I woke up one day and realized that all my dreams were dust, and I'd destroyed all I loved.",
      1,"'Now I seek to right the wrongs I did in my youth.",
      1,"'Power , yes, I had power, and laughs hollowly.",
      }));
      load_a_chat(60, ({
        1, "'I'll destroy you and your dreams.",
      }));
      new("/std/spells/items/tymora_symbol.c")->move(this_object());
      new("/baseobs/armours/cloak")->move(this_object());
      new("/baseobs/armours/chainmail")->move(this_object());
      new("/baseobs/weapons/mace")->move(this_object());
      this_object()->init_equip();
} /* setup */

void init()
{
   ::init();
   add_attack_spell(30,"heal",({"/std/spells/cleric/heal","cast_spell",3}));
   add_attack_spell(30,"pacify",({"/std/spells/cleric/pacify","cast_spell",1}));
   add_attack_spell(30,"silence",({"/std/spells/cleric/silence","cast_spell",1}));
   add_attack_spell(30,"regeneration",({"/std/spells/cleric/regeneration","cast_spell",3}));
   add_attack_spell(30,"flamestrike",({"/std/spells/cleric/flamestrike","cast_spell",1}));
}
void event_fight_in_progress(object ob1, object ob2) 
  {
  int ob1_lvl, ob2_lvl;

  //if (!ob1->query_interactive() && !ob2->query_interactive())
  //  return;

  ob1_lvl = ob1->query_level();
  ob2_lvl = ob2->query_level();

  if (ob1_lvl < 5 && ob2_lvl > 5 && interactive(ob1))
    {
      tell_room(environment(this_object()),"Vroyale mutters: Unwise, most unwise.\n");
    attack_ob(ob2);    
    }

  /* The other way round: */
  if (ob2_lvl < 5 && ob1_lvl > 5 && interactive(ob2))
    {
      tell_room(environment(this_object()),"Vroyale mutters: Unwise, most unwise.\n");
    attack_ob(ob1);
    }

} /* fight in progress */

