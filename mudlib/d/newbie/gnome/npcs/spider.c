inherit "obj/monster.c";
void setup()
{
set_name("spider");
set_short("Spider");
set_long("This is a big, fat, hairy spider.  It is very black and seems "
   "to regard you rather intently.  Every now and again "
   "it will shif a leg slightly.\n\n");
set_level(1);
set_al(0);
set_gender(random(2)+1);
}

