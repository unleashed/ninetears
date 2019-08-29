inherit "/std/sacroom";

void setup() {

   set_light(30);
  add_property("no_clean_up",1);

  set_short("%^BOLD%^BLACK%^Obsidian Tunnels : Shrine to Grimbrand%^RESET%^");

   set_long("%^BOLD%^BLACK%^Obsidian Tunnels : Shrine to Grimbrand\n\n%^RESET%^"
            "     Your first view of this area is darkness, pure and "
            "evil.  The darkness seems to have a life of its own, a "
            "will-power unseen but felt.  Cold stone, black as pitch, "
            "passes beneath your feet as you walk into the area.  "
            "Columns decorated with symbols and creatures are spaced "
            "throughout the hall.  The shadows seem to move with a "
            "savage and maleficent grace, fear chills you to the bone "
            "as you sense malevolent intelligence tempered with honor "
            "and fanatical loyalty.  Indeed, these very traits are "
            "depicted in the carvings and mosaics etched into the very "
            "stone of this Cathedral.  A massive altar, set into the "
            "stone heart of the hall, draws your attention subtly yet "
            "commandingly.\n"
            "\n");

   add_smell(({"hall", "area", "evil", "darkness"}),
             "   The hall smells musty and old, accentuated with the "
             "sharper scent of spices and the sweet metallic scent of "
             "freshly spilt blood.\n"
             "\n");

   add_feel(({"stone"}),
            "   The stone of the hall is cold to the touch.  You can "
            "actually -feel- hatred, revenge, and malevolent intent "
            "vibrating in the stone.  The raw power of this area feels "
            "like an oppresive weight crushing you to the floor.\n"
            "\n");

   add_feel(({"hatred", "revenge", "malevolent intent"}),
            "   Overpowering emotion eminates from the very rock of "
            "the Cathedral.  Hatred, revenge, war, destruction, and "
            "shockingly intelligent evil overwhelm you with a unique "
            "sense of dread.  You sense additionally a great sense of "
            "honor and fanatical loyalty underlying the entire "
            "sensation.\n"
            "\n");

   add_item(({"darkness", "shadow", "shadows"}),
            "   The darkness appears very much alive and moves with "
            "a savage and malefic grace.  It seems very threatening "
            "yet inviting enough to draw you in not unlike the "
            "hypnotic effect of something so horrifically terrible "
            "that you are unable to glance away.  Moving and swaying, "
            "the darkness seems to be engaged in some sort of arcane "
            "dance of worship to the God of Darkness and Evil, "
            "Grimbrand.\n"
            "\n");

   add_item(({"stone"}),
            "   The stone of the hall has been constructed of "
            "obsidian and is as black as pitch.  It seems to absorb "
            "all light with a voracious appetite creating an illusion "
            "of endlessness.  It feels bitterly cold and extremely "
            "hard.\n"
            "\n");

   add_item(({"columns"}),
            "   The columns are evenly spaced forming an oval around "
            "the altar.  Each column depicts different creatures "
            "chosen by Grimbrand himself as the patron idols of "
            "each of the seperate classes housed within the evil "
            "dominion.  One displays the image of the Jackel, another "
            "that of the King Cobra, and a third has a Fer-de-Lance "
            "Viper, each has been inlaid into the obsidian with the "
            "rare metal known as Electrum.\n"
            "\n");

   add_item(({"symbol", "symbols", "creature", "creatures"}),
            "   The inlaid electrum in the columns seem to eminate "
            "a soft glow of even darker darkness as if radiated by "
            "pure evil.  You can see a Jackel, a King Cobra, and a "
            "Fer-de-Lance Viper, each are depicted as foreground "
            "characters who are shadowed from behind by an incredibly "
            "powerful looking Siberian Tiger.  Each of the three "
            "foreground animals are in various acts of wanton "
            "destruction and slaying.\n"
            "\n");

  set_god_here("grimbrand");
  add_exit("south","/d/hoerk/werre/tunnel01.c","corridor");
}
