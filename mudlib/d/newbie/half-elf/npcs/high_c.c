// modified by Ljen okt -96
// Coded By Joram 16  of  August '96

inherit "/obj/monster";
#include "path.h"


void setup()
{

   set_name("leesd");
   set_short("Leesd The Commander");
   set_long("Leesd The Commander is the one in charge of the security of "
            "the Keep, although he only has two soldier to command to.  He "
            "wears a chainmail and has a sword in its side ready to fight. "
            " Althought he has many years behind, he's proud of it and is one of "
            "those great warriors of the past which fought the evil forces in the "
            "Great Battles.\n");

   add_alias("leesd");
   add_alias("commander");

   set_main_plural("Leesds The Commanders");
   add_plural("leesds");
   add_plural("commanders");

   set_gender(1);
   set_level(7);
   set_max_hp(80);
   set_race("elf");
   set_guild("fighter");

   add_clone("/baseobs/weapons/broad_sword.c", 1);
   add_clone("/baseobs/armours/chainmail.c", 1);

   load_chat(60,({
      1,"'Have a nice day dear young, remember evil waits behind after every corner",
      1,"'Once your formation is complete you should go out and search your own destiny",
      1,"@stands proudly and honourably",
      1,"@looks for someone to teach", 
   }));

   load_a_chat(70,({
      1,"@yells: You are Doomed now, thought you could do it ?",
      1,"@whispers: It has been a long time since my last battle, but I am still ready for it",
      1,"'Don't think you'll do it lad, indeed you are dead already!",
   }));

}
   
