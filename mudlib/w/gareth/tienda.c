#define CREATOR "Gareth
inherit "/std/tienda";

void setup() {
	set_short("%^BLACK%^%^BOLD%^Mazmorras de %^GREEN%^%^BOLD%^Gareth %^BLACK%^%^BOLD%^- Tienda%^RESET%^");
	set_long(query_short()+"\nLa Tienda solo esta separada de la herreria por una tapiz colgando, y asi Belor puede atender las dos. Aqui el sirviente de Gareth negocia con los objetos sobrantes de su senyor.\n");
	set_dependiente("/w/gareth/belor.c");
	
	add_suministro("/baseobs/armours/great_helm",5);
	add_suministro("/baseobs/armours/gauntlets",5);
	add_suministro("/baseobs/armours/completa",3);
	add_suministro("/baseobs/weapons/long_sword",5);
	add_suministro("/baseobs/weapons/oneex",3);
	add_suministro("/baseobs/weapons/twohandedaxe",3);
	add_suministro("/baseobs/weapons/twohandedsword",3);
	add_suministro("/baseobs/shields/corporal",roll(1,5));
	
	add_ajuste("raza","Inmortal",50);
	add_ajuste("clase","Bribon",150);
	add_prohibido("alineamiento","legal bueno");
	
	add_exit("mercado","/w/gareth/mercado","door");	
	add_cartel("cartel");
}

	