//kivara 26/10/2002

inherit "/std/tienda";

void setup(){
	set_short("%^CYAN%^Encantes%^RESET%^ de Kivara");
	set_long(query_short()+"\nTe encuentras en los famosos "
	"encantes de Kivara, famosa tienda conocida en todo driade "
	"por la calidad de sus articulos, aunque tambien por lo desorbitado "
	"de sus precios. Aqui podras encontrar de todo y tambien podras vender "
	"tus objetos, aunque es raro que vayas a hacer un gran negocio.\n\n");
	set_dependiente("/w/kivara/mustafa");
	set_dependiente("/w/kivara/mustafa.c");
	add_suministro("/baseobs/armours/helmet",2);	
	add_suministro("/baseobs/armours/cape",3);
	add_suministro("/baseobs/weapons/long_sword",random(5));
	add_suministro("/baseobs/shields/corporal",roll(1,3));
	add_ajuste("raza","Elfo",50);
	add_prohibido("raza","Orco");
	add_cartel("cartel");
	add_exit("taller","/w/kivara/workroom.c","door");
}

