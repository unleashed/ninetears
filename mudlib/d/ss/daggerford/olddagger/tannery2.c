#include <path.h>

inherit "/std/room";

setup()
{
    set_light( 50 );
    set_short( "Vic's Living Room" );
    set_long( "Vic's living room is fairly small.  A fur covered sofa fills "
	    + "up most of the east wall and a simple table is pushed up "
	    + "against the north wall under a window.  An open door leads "
	    + "into another room on the west wall.  Simple wooden stairs "
	    + "lead down.\n" );

    add_exit( "west" , ROOM+"tannery3" , "door"  );
    add_exit( "down" , ROOM+"tannery"  , "stair" );

    add_item( "door"
	    , "A door in the west wall leads into another room.\n"
	    );
    add_item( ({ "fur" , "sofa" })
	    , "The sofa is covered with beautiful red fox fur.  It took the "
	    + "ultimate sacrifice of quite a few foxes to cover it.\n"
	    );
    add_item( "road"
	    , "It's the main east/west road through town.\n"
	    );
    add_item( "stair"
	    , "The wooden stairs lead down to the floor below.\n"
	    );
    add_item( "table"
			, "A simple table sits below the window.  It looks like a nice place "
	    + "to sit and watch passers-by.\n"
	    );
    add_item( "window"
	    , "The window looks out onto the road below.  A table stands in "
	    + "the light below it.\n"
	    );
}
