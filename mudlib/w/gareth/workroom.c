#define CREATOR "Gareth"
/* Probablemente esta sera la primera room que tengas que editar, asi que intentare explicarlo con detalle - Vilat 20.10.2002 */

// Mas arriba aparecia una linea tal que asi:
// #define CREATOR <tu_nombre>
// Los defines nos sirven para reemplazar cosas en el archivo, asi que cada vez que escribas CREATOR sera reemplazado por tu nombre
// Esto nos permite anyadir portabilidad a las rooms, de modo que podemos cambiar cosas globalmente, no una a una
// Pronto aprenderas que la mejor herramienta para la portabilidad es el #include . Pregunta a otro Inmortal para que te lo explique

inherit "/std/room.c";
// Toda room debe heredar (inherit) o bien /std/room.c o bien una especializacion.
// La mas importante de estas especializacioneses /std/outside.c , que anyade a la room basica ajustes relativos al clima y similares.
// Generalmente cuando hagas una room de interior tendras que heredar /std/room.c , pero si se trata de una room de suboscuridad
// tendras que heredar /std/suboscuridad.c
// El problema viene al hacer rooms de exterior, donde hay muchisima mas variedad:
// /std/artico.c : Para rooms de clima muy frio. Estas rooms kitan vida al player si no va correctamente ekipado
// /std/bosque.c : Las rooms de bosque deben heredar esto.
// /std/ciudad.c : Para las rooms de ciudad.
// /std/desierto.c : Las rooms de extremo calor tienen que heredar esto. El player pierde vida en estas rooms si no va bien ekipado.
// /std/jungla.c : Es como el bosque pero con un clima mas calido
// /std/llanura.c : Hay que utilizar esto en rooms completamente al aire libre, como los caminos.
// /std/muralla.c : Es una especializacion de la ciudad, obviamente se usa en las murallas y permite a los players escalarlas.
// /std/pantano.c : Para esas rooms con un aire tetrico xD El clima es mas frio y humedo en estas rooms
// Hay muchas mas especializaciones, como tabernas, bancos... pero estos son los que mas usaras generalmente.

void setup() {
	// El short es lo que aparece como titulo del long, y cuando vamos en modo brief
   	set_short("%^BLACK%^%^BOLD%^Mazmorras de %^GREEN%^%^BOLD%^Gareth %^BLACK%^%^BOLD%^- Recibidor%^RESET%^");

	// El long aparece al mirar la room o cuando vamos en verbose
   	set_long(query_short()+"\n Te encuentras en la entrada de las Mazmorras.\nEstas en el centro de una sala grande y de forma circular. Las paredes son de color negro, y tienen un brillo que te atrae la mirada. Ves cuatro escaleras que descienden, cada una en direccion a uno de los puntos cardinales. Las escaleras bajan y bajan, parece que no tengan fin....\n\n");

   	//add_item() sirve para describir los objetos que aparecen en la descripcion. Sirve para anyadir detalles que dan mas
	//realismo a las salas asi que usa tantos como puedas
   	add_item("sala","La sala esta construida con piedra lisa como el marmol. Est� pobremente iluminada por unas antorchas colgadas en la pared.\n");
	add_item("escaleras","Las escaleras son del mismo color y material que el resto de la sala, y descienden en direccion al resto de habitaciones.\n");
   	add_item("pared","Las paredes parecen de piedra. Tienen un color negro.\n");
   	
   	// Puedes dar a varios objetos la misma descripcion
   	
   	add_item("antorcha","Hay una antorcha colgada encima de cada escalera, con unas misteriosas inscripciones debajo.\n");

   	//Tambien podemos poner informacion para otros sentidos (olor, tacto, gusto y oido)
   	add_smell(({"habitacion","sala","aire"}),"No notas olor ninguno en la sala, pero el aire que entra por tu nariz esta muy frio.\n");
   	add_taste("piedra","Pasas tu mano sobre la piedra de paredes y suelo y notas que esta muy lisa, sin ninguna imperfeccion.\n");
   	add_sound(({"habitacion","sala","aire"}),"La sala esta en completo silencio, excepto el crepitar del fuego en las antorchas.\n");

   	//Recuerda al hacer tus rooms darles todo el detalle posible para crear una atmosfera adecuada

   	//La siguiente funcion sirve para anyadir objetos a la room, que pueden sar tanto items, como armas, armaduras o npcs
	//El primer argumento es el objeto que queremos incluir, y el segundo el numero de estos objetos que deseamos
	
   	//Ahora vamos a anyadir las salidas de la habitacion. Sus parametros son, por orden:
   	//direccion - Lo que debemos escribir para ir en esa direccion
   	//destino - La room a la que iremos
   	//tipo - El tipo de salida. Si no ponemos este parametro la salida sera de tipo 'standard'
   	//Lee /doc/roomgen/exit_type_help o escribe 'man add_exit' para mas informacion (en ingles de momento)

	add_sign("Una inscripcion grabada en la piedra de la pared.\n"," Norte -> Galeria de Arte\n Sur   -> ?\n Este  -> Sala de Estudio\n Oeste -> Almacen\n","inscripcion","inscripcion");
   	add_exit("comun","/w/common","door");
   	add_exit("norte","/w/gareth/norte","corridor");
   	add_exit("sur","/w/gareth/workroom","corridor");
   	modify_exit("sur",({"function","sur"}));
   	add_exit("este","/w/gareth/este","corridor");
   	add_exit("oeste","/w/gareth/oeste","corridor");
   	add_exit("tienda","/w/gareth/mercado","door");
}

// Aqui termina la documentacion basica de rooms. Si quieres saber mas puedes leer workroom2.c (en tu directorio).
// Ahi te explican como anyadir funciones especiales, pero intenta probar primero a hacer una room como esta.
// De momento workroom2.c esta en ingles



void init() {
	::init(); {
	add_action("tocar_runas","tocar");
	}
	}
int sur(string str) 
	{
   		tell_object(TP,"Al caminar hacia las escaleras del sur te das cuenta de que estan rotas y es imposible bajar.\n");
   		tell_room(TO,this_player()->query_cap_name()+" va hacia el sur, pero el camino esta destruido.\n",TP);
   		return notify_fail("");
	}
	
int tocar_runas(string str) {
   	if(str == "runas") {
	tell_object(TP,"Pulsas cada una de las runas y una trampilla se descubre en el techo.\n");
	tell_room(TO,this_player()->query_cap_name()+" pulsa las runas y se abre una trampilla.\n",TP);
	add_exit("trampilla","/w/gareth/trampilla.c","door");
	renew_exits();
      		return 1;
   		}
		}