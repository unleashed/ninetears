#define YO "firehelp"

inherit "/std/room.c";

void setup () {

set_short("%^BOLD%^%^GREEN%^Cocina %^RESET%^de "+capitalize(YO));

set_long("Te encuentras en la gran cocina de "+capitalize(YO)+", puedes apreciar de la cocina esta muy limpia y muy ordenada casi perfecta. Al fondo puedes ver una mesa y a su lado una silla. La cocina tiene una peque�a ventana la cual tiene vista al mar. En la pared puedes ver una nota pegada con un clavo.\n\n");

add_item("mesa","Ves a la mesa y te das cuenta que es muy antigua, parece una reliquia.\n");

add_item("silla","Miras la silla y te das cuenta que es igual de antigua que la mesa.\n");

add_item("ventana","Te asomas por la ventana y sientes como la brisa pasa por tu nariz.\n");

add_item("nota","Cuando vas a mirar la nota ves que dice: 

Melon xD\n");

add_feel("nota","Tocas la nota y descubres que es un fino papel.\n");

add_feel(({"silla","mesa"}),"Sientes la finidad de este objeto.\n");

add_smell("habitacion","La habitacion huele a comida.\n");

add_exit("norte","/w/firehelp/workroom","door");

add_exit("oeste","/w/firehelp/ba�o","door");

add_exit("sur","/w/firehelp/pasillo","door");

}