inherit "obj/monster.c";
void setup()
{
set_name("snake");
set_short("Snake");
set_long("This is a long emerald green snake.  It slithers along "
   "lazily as if it has not a care in the world.  Every now and "
   "then you will see its red forked tongue dart out "
   "of its mouth.\n\n");
set_level(1);
set_al(0);
set_gender(random(2)+1);
load_chat(40,({
  1, "The snake makes a hissing sound as it flicks its forked "
          "tongue in and out of its mouth.",
}));
}

