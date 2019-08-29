//Kryger 2003//
inherit "/std/hostal";


void setup() {
  	set_short("%^BOLD%^BLUE%^Taberna de %^YELLOW%^Turin%^RESET%^");
  	set_long(query_short()+"\n\n Estamos en la taberna del campo de la discordia, aqui es donde la gente "
	"viene tras la batalla, esta es la posada de Turin, aqui tiene trabajando un clon suyo, porque tiene "
	"más asuntos que atender, el negocio no suele ir bién porque a duras penas consigues terminarte tu plato "
	"antes de que vengan problemas, la posada esta decorada con restos de las mejores armaduras que acaban "
	"por el campo de la Discordia.\n");
  	add_item(({"pared","suelo",}),"La estancia esta construida en madera fuerte.");
	set_salida("/room/plaza/campo_discordia_11.c");
  	set_dependiente("/room/plaza/theden_discordia.c");
  	add_cartel(); 
    add_plato("/baseobs/platos/arroz.c");
	add_plato("/baseobs/platos/cervezaenana.c");
	add_plato("/baseobs/platos/chupito.c");
	add_plato("/baseobs/platos/entrecot.c");
	add_plato("/baseobs/platos/gazpacho.c");
	add_plato("/baseobs/platos/hervido.c");
	add_plato("/baseobs/platos/higado.c");
	add_plato("/baseobs/platos/huevos.c");
	add_plato("/baseobs/platos/judias.c");
	add_plato("/baseobs/platos/lechelagarta.c");
	add_plato("/baseobs/platos/licorpatata.c");
	add_plato("/baseobs/platos/macarrones.c");
	add_plato("/baseobs/platos/muslos.c");
	add_plato("/baseobs/platos/patatas.c");
	add_plato("/baseobs/platos/ron.c");
	add_plato("/baseobs/platos/sesos.c");
	add_plato("/baseobs/platos/sidra.c");
	add_plato("/baseobs/platos/spaguettis.c");
	add_plato("/baseobs/platos/tuttifrutti.c");
	add_plato("/baseobs/platos/whisky.c");
	add_plato("/baseobs/platos/zumomanzana.c");
	add_plato("/baseobs/platos/zumonaranja.c");
	set_calidad(3);
	}
