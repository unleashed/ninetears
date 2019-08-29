inherit "/std/outside.c";

void setup()

{
    set_short("%^BOLD%^%^YELLOW%^Driade: %^RESET%^Plaza Central");
    set_long("%^BOLD%^%^YELLOW%^Driade: %^RESET%^Plaza Central\n\n" +
      "    Te encuentras en la plaza central de este pequenyo mud. Explora "+
      "los caminos de este mundo en miniatura, que a medida que pase el "+
      "tiempo ira creciendo. Tal vez algun dia hasta tenga un servidor, "+
      "nunca se sabe. Por el momento, se rumorea que las mas sangrientas "+
      "batallas entre los ases de la magia y los mas feroces guerreros "+
      "banyan esta plaza y los caminos colindantes con asiduidad. Puede "+
      "que tu mismo seas testigo de estas atroces peleas... o puede "+
      "que tengas que mover rapidito tu culo para no caer al suelo antes "+
      "de lo que te imaginas.\n\n");

    set_light(50);
add_item("hall","It's a hall, but your eyes are rather drawn to looking "+
   "at the sign.\n");
add_item("people","You see the people are examining the sign.\n");

//add_exit("valle","/w/jerkat/valle_dragon/room/valle_01","door");
add_exit("fficmud", "/room/entryroom", "door");
add_exit("hueco", "/w/xerxes/mago_ladron/guild_wizthief.c", "door");
add_clone("/baseobs/weapons/bastard_sword", 8);
add_clone("/baseobs/armours/fullplate", 14);
add_clone("/baseobs/weapons/hacha_oneex", 12);
}
