inherit "std/pub";
#include "pub.h"
#include "path.h"

#define T_P this_player()
object ghoul, vampire, assasin;
object globe;
object bard;
object board;

void clean_up(int i) { }


void makeghoul()
{

   if(!ghoul) 
      {
      ghoul = clone_object(NPCS+"dghoul");
      ghoul->set_long((string)ghoul->query_long()+
      "Eric the ghoul also happens to be the bartender and cook in "
      "this fine establishment.\n");
      ghoul->set_short("Eric");
      ghoul->add_alias("eric");
      ghoul->set_aggressive(0);
      ghoul->set_zone("pub");
      ghoul->move(this_object());
      ghoul->set_max_hp(ghoul->query_hp()+100);
   }

}
void reset() 
{
   makeghoul();
   if(!vampire) 
      {
      vampire = clone_object(NPCS+"dvampyre");
      vampire->set_short("sylvania");
      vampire->add_alias("sylvania");
      // vampire->set_aggressive(0);
	//  Is this really necessary? ~Dwim (just asking =))
      vampire->set_zone("pub");
      vampire->move(this_object());
   }
/*
   if(!bard) 
      {
      bard = clone_object(NPCS+"bard");
      bard->set_short("fred");
      bard->add_alias("fred");
      bard->set_aggressive(0);
      bard->set_zone("pub");
      bard->move(this_object());
   }
   if(!assasin) 
      {
      assasin = clone_object(NPCS+"assasin");
      assasin->move(this_object());
   }
   */
}

setup()
{
   add_menu_item("Boneyard Beer", ALCOHOL, 10, 2, 10, 10,
      "slurp down your beer", "hurls down a pint of beer");
   add_menu_item("Guiness", ALCOHOL, 50, 3, 50, 50,
      "drink a meal of thick black beer", "drinks a Guiness");
   add_menu_item("Malt whisky", ALCOHOL, 150, 6, 100, 100,
      "feel a gentle burning down your throat", "drinks a shot of whisky" );
   add_menu_item("Bloody Mary",ALCOHOL, 300, 20, 200, 200,
      "drinks the Bloody Mary in a delicate and refined manner, suddenly it "
      "stops in your throat, then gathers speed and shoots into your stomach",
      "drinks a Bloody Mary, stops momentarily to spit out a lumpy bit, then chugs the dregs");
   add_menu_item("Chili nuts", FOOD, 50, 1, 20, 0,
      "eat some very strong chili nuts", "eats some red peanuts");
   add_menu_item("Ribs", FOOD, 300, 5, 150, 0,
      "eat a thankfully unspecified rib","eats an unspecified rib");
   add_menu_item("Devilled Kidneys",FOOD,2200,3,240,0,
   "munch some hot kidneys","munches through a platefull of kidneys");
   add_menu_item("Meat Patties", FOOD, 200, 4, 100, 0,
      "eat some slightly undercooked meat patties","eats some slightly undercooked meat patties");

   add_menu_item("sweetbreads", FOOD, 2000, 4, 100, 0,
   "choke down some sweetbreads. ","eats a platefull of brains");
   add_menu_item("tripe", FOOD, 2000, 4, 100,0,
   "slurp down the tripe.","chomps through somethings guts");
   add_menu_item("prairie oysters", FOOD, 1000,4, 100,0,
   "delicately nibble a prairie oyster or two","bolts a matched pair of prairie oysters");
   add_menu_item("Haggis",FOOD,800,4,100,0,
   "wonder what to do with a haggis, and finally eat it.","puzzles over a Haggis, and in desparation finally eats it. ");
   add_menu_item("liver",FOOD,1750,4,100,0,
   "eat a liver","eats a liver with gusto");
   add_menu_alias("rib","Ribs");
   add_menu_alias("ribs","Ribs");
   add_menu_alias("kidneys","Devilled Kidneys");
   add_menu_alias("beer", "Boneyard Beer");
   add_menu_alias("house beer", "Boneyard Beer");
   add_menu_alias("house", "Beer");
   add_menu_alias("stout", "Guiness");
	add_menu_alias("black beer", "Stout");
   add_menu_alias("whisky", "Malt whisky");
   add_menu_alias("malt", "Malt whisky");
   add_menu_alias("malt whisky", "Malt whisky");
   add_menu_alias("mary", "Bloody Mary");
   add_menu_alias("bloody mary", "Bloody Mary");
   add_menu_alias("dwarven spirits", "Dwarven spirits");
   add_menu_alias("axereaver", "Axereaver");
   add_menu_alias("reaver", "Axereaver");
   add_menu_alias("chili", "Chili nuts");
   add_menu_alias("chili nuts", "Chili nuts");
   add_menu_alias("toast", "Toast");
   add_menu_alias("patties", "Meat Patties");
   add_menu_alias("meat patties", "Meat Patties");
   
   set_short("Isle of Belaern : Dead Man's Tavern");
   set_long(
   "\n%^BOLD%^RED%^Isle of Belaern : Dead Man's Tavern%^RESET%^\n\n"
   "This scummy little hole in the wall serves as a meeting place for the "
   "dwellers of this place, and any adventurers stupid enough to make it "
   "this far. The decor is strictly early crypt, and you don't really "
   "want to know where the supplies come from or whats in them. "
   "However, despite the fashionably low light levels for the "
   "benefit of the more discerning clientele, this does seem a safe place "
   "to rest and relax. "
   "In fact this place is really hopping, and looking at the people here "
   "maybe rest isn't such a good word. "
   "There is a menu here, you may wish to read it. "
   "\n\n");
   
   add_exit("south", HERE+"bsand14.c", "door"); 
   
   set_light(40);
   set_zone("pub");
   
   add_item(({"column", "stone", "stone column"}),
      "On it are inscribed the unique symbols of patrons who have died "
      "in a battle or disappeared while adventuring. Any toast given in "
      "the tavern must include a libation to: those who have fallen "
      "before us. When do we eat ?.\n");
   add_item(({"people", "patrons"}),
      "Clients would be a better word, people barely describe them. "
      "Some of them are drinking alcohol though. "
   "\n");
   add_item("bar",
      "The bar is made of wood and has lots of patrons hanging over it, "
      "trying to get the attention of Eric, the bar-keeper.\n");
   add_item("weapons",
      "They're all mounted into the walls. Seems impossible to remove them "
      "There are four longswords, a whip and a double-edged huge battle-axe.\n");
   add_item("armor",
      "The different pieces of armor are mounted securely to the wall. "
      "You couldn't remove them even if you wanted to. There are 16 "
      "pieces of armor all-in-all. Most probably every single piece will "
      "fit on some bodypart on some kind of creature. Not all are easy to "
      "figure out where might fit however.\n");
   add_item("trophies",
      "Disappointedly the trophies seem to be just junk. Leave it!\n");
}
int do_order(string str)
{
   if(ghoul)
   {
   tell_room(this_object(),"Eric wanders into the back room to prepare an "
   "order.\nThere's a short, sharp scream.\nEric returns.\n",
   ({ }) );
   if(str == "Devilled Kidneys")
   {
      if(T_P->query_tmp_wis() < 0) T_P->adjust_tmp_wis(1);
      this_player()->adjust_tmp_wis(-(int)this_player()->query_tmp_wis());
   }
   if(str == "tripe")
   {
      if(T_P->query_tmp_con() < 0) T_P->adjust_tmp_con(1);
   }
   if(str == "sweetbreads")
   {
      if(T_P->query_tmp_int() < 0) T_P->adjust_tmp_int(1);
   }
   if(str == "prairie oysters")
   {
      if(T_P->query_tmp_dex() < 0) T_P->adjust_tmp_dex(1);
   }
   if(str == "liver")
   {
      if(T_P->query_tmp_str() < 0) T_P->adjust_tmp_str(1);
   }
   if(str == "Haggis")
   {
      if(T_P->query_tmp_cha() < 0) T_P->adjust_tmp_cha(1);
   }
   return 0;
   }
   else
   {
   tell_room(this_object(),"Eric the barkeep doesn't appear to be here.\n",({ }) );
   return 1;
   }
}
void init()
{
   ::init();
   add_action("do_order","buy");
   add_action("do_order","order");
}

dest_me()
{
   if(board)
      board->dest_me();
   if (vampire)
      vampire->dest_me();
   if (ghoul)
      ghoul->dest_me();
   if (assasin)
      assasin->dest_me();
   if(bard)
      bard->dest_me();
   if (globe)
	globe->dest_me();
   ::dest_me();
}

void event_enter(object ob, string mess)
{
   if(interactive(ob))
      tell_room(environment(this_player()),
         ob->query_cap_name()+" arrives from somewhere.\n",
         ob);
}
