#include <path.h>

inherit "/std/room";

object vic;
setup()
{
   set_light( 50 );
   set_short( "Tannery" );
   set_long( "You're standing in a fairly large room.  It seems to consume "
      + "the entire first floor of this small house.  There is a "
      + "stairway leading up on the back wall.  Racks around the room "
      + "are strewn with hides of many kinds of animals.  The smell of "
      + "these tannin cured hides is nearly intoxicating.\n" );
   
   add_exit( "east" , ROOM+"tanner3" , "door"  );
   add_exit( "up"    , ROOM+"tannery2" , "stair" );
   
   add_alias( "hides"  , "hide"  );
   add_alias( "racks"  , "rack"  );
   add_alias( "skin"   , "hide"  );
   add_alias( "skins"  , "hide"  );
   add_alias( "stairs" , "stair" );
   
   add_item( "hide"
      , "Hides from all sorts of animals are strewn about the room.\n"
   );
   add_item( "rack"
      , "The room is filled with crudely-made racks.  Animal skins are "
      + "drying on the racks.\n"
   );
   add_item( "stair"
      , "The wooden stairs lead up to the second floor.\n"
   );
}

void
reset()
{
   if ( !vic )
      {
      vic = clone_object("/obj/monster");
      vic->set_name("vic");
      vic->add_property("determinate","");
      vic->set_short("Vic");
      vic->set_main_plural("persons looking like Vic");
      vic->add_alias("tanner");
      vic->add_plural("vics");
      vic->add_adjective("big");
      vic->add_adjective("strong");
      vic->set_long("Vic is a big, strong man.  His forearms have been "+
         "strengthened by working hides and his blonde hair "+
         "keeps falling down into his eyes.\n");
      vic->set_race("human");
      vic->set_gender(1);
      vic->set_al(100);
      vic->set_level(3+random(2));
      vic->set_aggressive(0);
      vic->adjust_money(random(50), "copper");
      vic->load_chat(40 ,
         ({
               1 , "Vic says: Hello stranger, can I help ya?" ,
               1 , "Vic says: Have any pelts ya'd like tanned?  I do good "
               + "work.  Best tanner around." ,
               1 , "Vic rubs tannin into what looks like a wolf hide." ,
               1 , "Vic asks: Are ya from the city?  What's it like there "
               + "now-a-days?" ,
               1 , ":smiles warmly as he stretches out some hide."
          }) );
      vic->load_a_chat(200 ,
         ({
               1 , "Vic exclaims: Hey!  Leave me alone!" ,
               1 , "Vic shouts: Help!  Help!" ,
               1 , "Vic looks for something to defend himself." ,
               1 , "Vic asks: What's wrong with you?  I'm just a simple "
               + "craftsman."
          }) );
      vic->move( this_object() );
   }
}

void
dest_me()
{
   if (vic)  
      vic->dest_me();
   
   ::dest_me();
}
