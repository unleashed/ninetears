#define CREATOR "Blastaar"
inherit "/std/room.c";
void setup() {
set_short("%^RED%^BOLD%^Mina%^RESET%^ de las%^GREEN%^BOLD%^ Montanyas%^RESET%^");
set_long("\n%^RED%^BOLD%^Mina%^RESET%^ de las%^GREEN%^BOLD%^ Montanyas%^RESET%^\n\n"
"Esta es la mina de donde se crean los entes del mal"
" Grandes demonios del averno i misteriosas criaturas surgiran"
" Grandes demonios del averno i misteriosas criaturas surgiran"
" Blastaar, el gran demonio del infierno.\n"
" El calor es sofocante i toda la estancia esta repleta de destellos rojizos"
" que crean un aura de caos i maldad, solo piensas en no"
" encontrarte al temido demonio de fuego que habita en su interior.\n\n");
set_light(80);
 add_exit("comun","/w/common","door");
add_exit("entrada","/room/entryroom.c","door");
add_exit("fuera","/w/blastaar/montanyas_salvajes/rooms/m1.c","door");
}
