#define YO "firehelp"

inherit "/std/room.c";

void setup () {

set_short("%^BOLD%^%^BLACK%^Sotano %^RED%^Secreto");

set_long("Te encuentras en el sotano oculto de "+capitalize(YO)+", puedes ver que esta muy sucio como si nadien huviera entrado hace a�os, al fondo puedes ver un gran baul.\n\n");

add_item("baul","Esta lleno de telaranyas, esta medio abierto.");

add_exit("escaleras","/w/firehelp/habitacion","door");

}

void  init () {

::init();

add_action("abrir_baul","abrir");

}

int abrir_baul(string str) {
if(str == "baul") {
tell_object(TP,"Abres el baul y ves que esta vacio.\n");
tell_room(TO,this_player()->query_cap_name()+ " abre el baul.\n",TP);

return 1;

}

return notify_fail("Abrir que?\n");
}



