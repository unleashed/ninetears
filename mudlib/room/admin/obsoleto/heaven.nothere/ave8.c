1    �        }     
 
 
 
 
                                                                                                  #include "immortals.h"
#include "path.h"
inherit"/std/room.c";

void init() {
shield_it(SHIELDCITY,"/d/fr/daggerford/ladyluck");
::init();
}

void setup() {
set_long("You are on Immortal avenue.  You stand in the City of"
" the Immortals.  You stare in awe at the wondrous buildings around"
" you.  You feel the magic in the air, and feel at peace here. To"
" the west of you lies "+ IM8A + 
", while to the east of you lies "+ IM8B +".  To the south of you"
" lies a square.  In the center of the square lies three statues.\n");
set_short("Immortal square");
add_exit("north",ROOM+"ave7","road");
add_exit("south",ROOM+"ave9","road");
add_exit("west",ROOM+"ave11","road");
add_exit("east",ROOM+"ave14","road");
set_light(100);
}      

_li    }   w p �#�[7eD! [Me D!  +hp   �[�'  �2 [          @gF�� � +hF��#
\  O#Ri  4
W#  Ri   iVi�# \�	W#   '   �#7\� _#    +               �                                               '     j                       ^                             :         :   a     r     {     }                                   '     j                       ^                             :            0Courier New    Arial    while to the east of you lies "+ IM5B +".\n");
set_short("Immortal Avenue");
add_exit("north",ROO