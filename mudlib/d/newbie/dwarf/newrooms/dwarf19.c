//  Dwarven Newbie Area:  Created By Mist   Fall 1994
#include "path.h"
inherit ROOM+"baseroom.c";

int rings = random(4)+1;
int m;
object bat;

void setup ()   { my_setup();
    set_short("Realm of the Dwarf:  Large Room");
    set_light(50);
    set_long("\n   Realm of the Dwarf:  Large Room\n\n"
      "     This is a very large room with a ceiling that you "
      "can barely make out.  Upon a closer inspection, "
      "is looks as if the ceiling is alive and moving.  "
      "The floor here is covered with a slimy substance "
      "that gives off a horrible smell.  "
      "There are a number of candles in small "
      "recesses in the walls.  There is also a small bell "
      "hanging from one of the walls.  The only obvious "
      "exit is the small hole in the southwestern wall.  "
      "\n\n");
    add_item(({"bell","small bell"}),"This is a small brass bell "
      "hanging from the wall. \n\n");
    add_item(({"ceiling"}),"Looking closer, you see that "
      "the ceiling is covered with hundreds of bats.  "
      "It might be wise to quietly leave and not disturb "
      "them."
      "\n\n");
    add_item(({"candle"}),"These brightly lit candles are sitting in "
      "the small holes in the wall.  "
      "\n\n");
    add_item(({"recess","hole","recesses"}),"The holes in the wall serve "
      "no purpose, except as a holder for the dozens of "
      "candles that light the room.  "      
      "\n\n");
    add_item(({"substance"}),"This is the stuff that is giving "
      "off this awful smell.  It looks like bat guano.  "
      "\n\n");
    add_item("guano","The guano covers the floor here.  It must "
      "have taken hundreds of bats to cover the floor this "
      "deep.\n\n");
    add_smell(({"substance","guano"}),"Yep, you were right.  "
      "Now you are sure that this is the stuff that is "
      "giving off that terrible smell.  Better not breathe "
      "this stuff for too long.  "
      "\n\n");
    add_taste(({"substance","guano"}),"Your nose takes control "
      "of your mind and does not allow you to put that "
      "stuff in your mouth.  You probably didn't need to "
      "taste it anyway.  "
      "\n\n");
    add_exit("southwest",ROOM+"dwarf23","path");
}

void init()
{  ::init();
    add_action("do_bell","ring");
    add_action("do_bell","hit");
    add_action("do_bell","strike");
}

int do_bell(string xxx)
{
    int i;
    int many = random(3) + 1;
    int num_bats;
    if(this_object()->query_property("bats") >= 5)
    {
        write("\n   You attempt to ring the bell but it makes"
          " a muffle clink sound... it must be broken"
          " now.\n\n");
        return(1);
    }

    if(!xxx) { write("Do what to the bell.\n\n"); return(1); }
    if(xxx == "bell")
    {
        if(m < rings)
            write("The sound of the bell seems to have disturbed some "
              "of the sleeping bats.  They are flying down towards "
              "you, ready to attack.  "
              "\n\n");
        num_bats = this_object()->query_property("bats");
        num_bats = num_bats + many;
        this_object()->add_property("bats",num_bats);
        {
            for(i=1; i<=many; i++)
            {
                bat = clone_object(CHAR+"bat.c");
                bat->move(this_object());
            }
            m++;
            return(1);
        }
        return(0);
    }
}
