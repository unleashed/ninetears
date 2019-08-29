//Ljen nov -96

inherit "/obj/monster";
object key;

void setup()
{

  set_name("Tancren");  

  set_short("Tancren the half-elf");

  set_long("This creature may once have been a half-elf in his teens,"
           " before the drows captured him. Now he is only a shadow of"
           " his former self. His body is covered with various wounds,"
           " scraps, burnmarks and so on. There is not one spot with"
           " skin left! His eyes has a sad and desperate expression,"
           " with a touch of madness. You can see that it wont be long"
           " before he turns completely insane."
           " Your heart aces with pity for him, and you wish there was"
           " something you could do for him.\n");

  add_alias("tancren");

  add_clone("/d/newbie/half-elf/items/key.c", 1);

  add_alias("half-elf");

  add_plural("half-elves");

  set_race("half-elf");

  set_guild("ranger");

  set_gender(1);

  set_level(9);

  set_max_hp(100);

  load_chat(400,({
       1,":whispers painfully: please.... kill me.... end the pain..... \n",
       1,":bends over as a wave of pain overcomes him.",
       1,":looks at you with sad and suicidal eyes.",
       1,":moans silently: .. kill me... end it... ",
       }));

  load_a_chat(700,({
       1,":smiles weakly.",
       1,":says: At last! Someone to free me!,"
       }));

} 
       

void do_death()
{

  write("\n\nAs Tancren's spirit leaves his body, he smiles happily at you,"
        " telling you to take good care of the key he had."
	" 'It could be the way out' he whispers to you.\n\n");
  

  return ::do_death();
  

}
