inherit "obj/monster.c";
void setup()
{
set_name("bat");
set_short("Bat");
set_long("This is an averaged size cave bat.  It is sort of a brownish color with darker wings. "
   "Right now it is "
   "hanging from the ceiling, quietly minding its own business, but "
   "you fear that if you make too much noise, it will awaken and "
   "fly at you screaming madly.\n\n");
set_level(3);
set_al(0);
set_gender(random(2)+1);
load_chat(40,({
   1, "The bat moves its wings slightly and makes a small peep, as it "
      "settles back into sleep.",
}));
}

