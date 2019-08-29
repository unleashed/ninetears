#define CREATOR "niclaus"

inherit "/std/room.c";

void setup() {
	set_short("%^BOLD%^BLACK%^Celestial Fortaleza de Sakalzor: %^WHITE%^Entrada.\n ");
	set_long("   Te encuentras en la entrada de una hermosa fortaleza de muros "
   	"de puro %^BOLD%^BLACK%^Eog Negro%^RESET%^, sus muros brillan con tal fuerza que rodean toda "
   	"la fortaleza de un aura oscura. Esta fortaleza fue creada por %^RED%^Sakalzor%^%^RESET%^, "
   	"Gran Mago y Maestro de Armas que tomo a Niclaus como aprendiz al que cedio todos "
   	"sus conocimientos, antes de desaparecer en extranyas condiciones.\n");
   	add_item(({"muro","muros","eog"}),"  Los muros de la fortaleza estan rodeados de "
   	"un aura oscura que no te permite ver con claridad, sin embargo puedes diferenciar "
   	"un dibujo, parece un Latigo de Fuego.\n");
      	add_feel("muro"," Al tocar el muro sientes un gran dolor, el terror y el sufrimiento "
      	"se apoderan de ti, macabras imagenes de seres y lugares que jamas podrias haber "
      	"imaginado atraviesan tu mente dejandote exhausto.\n");
   	add_sound(({"lamentos","aire"})," Solo consigues oir el desgarrador gemido de las "
   	"miles de almas que han sido condenadas en esta fortaleza, los llantos y lamentos "
   	"cargan el aire impidiendote reaccionar.\n");
   	set_light(50);
	add_exit("comun","/w/common.c","door");
   	add_exit("dentro","/w/niclaus/workroom/fort001.c","door");
}
