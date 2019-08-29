#define CREATOR "testvilat"
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
   	set_short("Sala de trabajo de "+capitalize(CREATOR));

	// El long aparece al mirar la room o cuando vamos en verbose
   	set_long(query_short()+"\n   La habitacion donde te encuentras ha sido pintada recientemente. Unos pocos muebles adornan la habitacion, algunos todavia en sus embalajes. Los mas importantes son el escritorio y su silla, que parecen haber pasado antes por otras manos a juzgar por su deterioro. En mitad del techo, una lampara oscila dando a la sala una iluminacion bastante tenue. Sin lugar a dudas deberias reacondicionar este lugar pronto.\n\n");

   	//add_item() sirve para describir los objetos que aparecen en la descripcion. Sirve para anyadir detalles que dan mas
	//realismo a las salas asi que usa tantos como puedas
   	add_item("sala","La habitacion huele a pintura fresca. La luz tenue no llega a iluminar todos los rincones.\n");

   	add_item("pared","Las cuatro paredes parecen haber sido pintadas recientemente, aunque no con demasiado esmero.\n");

   	add_item("pintura","Alguien ha dado a toda la habitacion una mano de pintura, aunque no se ha debido de cansar mucho porque la capa no es uniforme y en algunos lugares se ve la pintura que habia antes...\n");

   	// Puedes dar a varios objetos la misma descripcion
   	add_item(({"mobiliario","escritorio","silla"}),"En la pared opuesta a la puerta hay un escritorio y una silla. Ambos tienen un aspecto desvencijado y sucio. La silla esta casi rota asi que seria mejor no sentarse en ella.\n");

   	add_item(({"techo","lampara"}),"Colgando del centro del techo hay una lampara de aceite, que ilumina tenuemente la habitacion.\n");

   	//Tambien podemos poner informacion para otros sentidos (olor, tacto, gusto y oido)
   	add_smell(({"habitacion","sala","aire"}),"La habitacion huele a pintura fresca.\n");

   	add_feel("escritorio","Sientes el tacto del roble al tocar el escritorio, si bien esta muy gastado.\n");

   	add_taste("pintura","Pasas el dedo por la pared y pruebas el sabor de la pintura... Para darte cuenta de que ni siquiera es pintura, sino que lo que han hecho es encalar la habitacion.\n");

   	add_sound(({"habitacion","sala","aire"}),"Escuchas un fuerte ruido que viene de debajo del pupitre.\n");

   	//Recuerda al hacer tus rooms darles todo el detalle posible para crear una atmosfera adecuada

   	//La siguiente funcion sirve para anyadir objetos a la room, que pueden sar tanto items, como armas, armaduras o npcs
	//El primer argumento es el objeto que queremos incluir, y el segundo el numero de estos objetos que deseamos
	add_clone("/obj/misc/button.c",1);

   	//Ahora vamos a anyadir las salidas de la habitacion. Sus parametros son, por orden:
   	//direccion - Lo que debemos escribir para ir en esa direccion
   	//destino - La room a la que iremos
   	//tipo - El tipo de salida. Si no ponemos este parametro la salida sera de tipo 'standard'
   	//Lee /doc/roomgen/exit_type_help o escribe 'man add_exit' para mas informacion (en ingles de momento)

   	add_exit("comun","/w/common","door");

   	//Esta linea es una llamada sobre otro objeto. En este caso estamos llamando sobre "/w/common" y anyadiendole una salida hacia aqu
   	"/w/common.c"->add_exit( CREATOR,"/w/"+CREATOR+"/workroom","door");
	}

// Aqui termina la documentacion basica de rooms. Si quieres saber mas puedes leer workroom2.c (en tu directorio).
// Ahi te explican como anyadir funciones especiales, pero intenta probar primero a hacer una room como esta.
// De momento workroom2.c esta en ingles
