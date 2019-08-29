#include "/w/barthleby/path.h"

inherit "/std/room.c";


void setup()

{
    set_short("%^BOLD%^%^RED%^Palacio de Mu-Bai%^RESET%^");
     set_long("%^BOLD%^%^RED%^Palacio de Mu-Bai%^RESET%^\n\n"+
      "Has alcanzado la sala principal, aqu� es donde el gobernador de Noella se reune con el " +
      "senado en torno a la mesa con forma de media luna a la que conduce la gran alfombra " +
      "roja que tienes bajo tus pies.\n\n");

    set_light(70);

add_item("mesa", "Esta es una gran mesa de roble en forma de media luna con tres poderosos " +
        "pies tallados.\n");

add_item("alfombra", "La alfombra roja va desde la entrada de la sala hasta la gran mesa y " +
        "rodeando esta �ltima. Tiene unos extra�os dibujos bordados en oro.\n");

//add_clone(NPC+"guardia_noella", 4);

add_exit("fuera", PRINCIPALES+"trono2","road");
}
