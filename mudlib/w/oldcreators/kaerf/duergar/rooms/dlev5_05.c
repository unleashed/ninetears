/*  Text alterations and additions by Grimbrand 2-11-96                 */

#include "path.h"
inherit "/std/underground";

object *npcs;

static int islocked = 1;

void reset() {
    int i;
    for(i=0;i<sizeof(npcs);i++) {
        if(!npcs[i]) {
            npcs[i]=clone_object(DNPC+"dgoblin");
            npcs[i]->move(this_object());
        }
    }
}

void init() {
    ::init();
    add_action("unlockit","desbloquear");
}

void setup() {
    add_property("no_undead",1); set_light(10);
    npcs = allocate(1);
   set_short("Reinado Duergar:  Entrenamientos con razas");

   set_long("\n   Reinado Duergar:  Entrenamientos con razas.\n\n"
	    "     Este cuarto esta totalmente desnudo y sencillo.  Solo "
	    "ves unas manchas en el suelo y marcas estriadas en las paredes "
	    ", ves tambien un gran charco de sangre en el suelo."
	    "\n\n");

   add_item(({"suelo", "mancha", "manchas"}),
	    "   Examinando el suelo ves que la piedra esta manchada por la "
	    "sangre de muchas batallas pasadas, y las que pasaran, imaginas."
	    "  Ves tambien un charco de sangre que se coagula poco a poco "
            "en el frio suelo."
	    "\n\n");

   add_item(({"sangre", "charco", "charco de sangre"}),
	    "   Es un charco de sangre aun fresca, parece que la batalla se "
	    "produjo hace poco, se esta empezando a coagular lentamente "
	    "en el frio y humedo suelo."
	    "\n\n");

   add_item(({"muro", "pared", "paredes"}),
	    "   Las paredes tienen varias marcas, dejadas por distintas "
	    "armas, en las luchas que suelen tener lugar en esta zona."
	    "\n\n");

 
    add_exit("norte",NEWBIE+"dlev5_12","door");
    modify_exit("norte", ({"function", "do_door"}));
    add_exit("sur",NEWBIE+"dlev5_04","path");
    add_exit("este",NEWBIE+"dlev5_06","path");
    add_exit("oeste",NEWBIE+"dlev5_09","path");
    add_exit("noreste", NEWBIE+"dlev5_18", "path");
    add_exit("noroeste", NEWBIE+"dlev5_17", "path");
}
void dest_me() {
    int i;
    for(i=0;i<sizeof(npcs);i++)
        if(npcs[i]) npcs[i]->dest_me();

    ::dest_me();
}

int do_door() {
    if(islocked==1) 
    {
        notify_fail("   Al intentar abrir la puerta te das cuenta "
          "que esta bloqueada con un fuerte cerrojo.\n\n");
        return 0;
    }
    islocked = 1;
    return 1;
}

int unlockit(string str) {
    object it;

    if(str=="puerta") 
    {
        if(present("llave newbie",this_player())) 
        {
            write("   Estupendo! la llave encaja en el cerrojo! "
              "Das un rapido giro a la llave y oyes el click "
              "al desbloquearse la cerradura."
              "\n\n");
            tell_room(environment(this_player()), 
              this_player()->query_cap_name() +
              " inserta la llave en el cerrojo, da una rapido "
              "giro y la cerradura se abre.\n\n"
              "CLICK!\n\n", ( this_player()));
            it=find_match("newbie_key", this_player());
            it->dest_me();
            islocked = 0;
            return 1;
        }
        else
        { 
            write("   Necesitas una llave para desbloquearla!\n\n");
            return 1;
        }
    }
    return 0;
}

