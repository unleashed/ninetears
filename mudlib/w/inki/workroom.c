#define CREATOR "inki"
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
   	set_short("Habitaci�n de "+capitalize(CREATOR));

	//  El  long  aparece  al  mirar  la  room  o  cuando  vamos  en verbose
	set_long(query_short()+"\n\nAl entrar en la habitaci�n de Inki el caos te invade, pues su principal "
	     "caracter�stica es el desorden. Se pueden contemplar montones de zapatos, "
	     "ropa, CDs, peluches, cuadernos y un sinf�n de objetos desperdigados a lo "
	     "largo y ancho del panorama. Se encuentra amueblada con dos armarios, varias "
	     "mesas y una litera, donde	parece descansar alguien en la cama inferior. "
	     "Adem�s de la puerta de salida, apreciamos otra que da a un peque�o cuarto "
	     "de ba�o. Destaca una ventana con vistas a una galer�a-tendedero, donde "
	     "comunmente ves transitar personas en una u otra direcci�n. Varios p�sters "
	     "adornan las puertas y paredes de la sala. Lo primero que se te pasa por la "
	     "cabeza es	intentar poner orden a tal desastre, pero acto seguido desistes, "
	     "pues tienes cosas mejores que hacer y tan siquiera sabes por d�nde empezar.\n");

   	//add_item() sirve para describir los objetos que aparecen en la descripcion. Sirve para anyadir detalles que dan mas
	//realismo a las salas asi que usa tantos como puedas
   	add_item(({"sala","habitacion","cuarto"}),"Se trata de una habitaci�n relativamente peque�a. Actualmente est� "
   	     "iluminada �nicamente por la escasa luz que proviene de la ventana.\n");

   	add_item(({"pared","paredes"}),"Destaca la pared principal con varias repisas repletas de CDs, DVDs y v�deos. "
   	     "Justo al lado hay un p�ster de Slipknot.\n");

   	add_item(({"puerta","puertas"}),"Las dos puertas est�n decoradas con p�sters del sistema solar.\n");

   	add_item(({"litera","cama"}),"Te acercas sigilosamente a la litera y descubres que es Sebas, hermano de Inki, "
   	     "quien reposa en la cama inferior. Ya hay una explicaci�n para los sonoros ronquidos que cre�as sentir.\n");
   	
   	add_item("techo","Diriges tu mirada al techo y divisas en �l un foco de tres bombillas apagado. Alrededor "
   	     "hay pegatinas de planetas y estrellas fosforescentes. Por un momento enciendes "
   	     "la luz, y aprecias que s�lo se ilumina una de las tres bombillas. Oyes murmullos "
   	     "que provienen de la cama, por lo que decides apagarla de nuevo.\n");
   	
   	add_item(({"ventana","galeria","tendedero"}),"Te acercas a la ventana y observas a trav�s de ella. En un corto espacio de tiempo has "
   	     "visto pasar a las dos Ana de la casa, madre y abuela de Inki. M�s all� del tendedero ves fincas que "
   	     "corresponden al vecindario. Te llama la atenci�n el vecino de al lado, el cual no deja de vigilarte, "
   	     "de ah� que sea conocido como el B�ho.\n");
   	     
   	add_item(({"armario","armarios"}),"Se trata de dos armarios de madera. Los abres y descubres que no contienen nada "
   	     "de inter�s. S�lo hay ropa.\n");
   	        	
   	add_item(({"mesa","mesas"}),"Hay un total de tres mesas. Dos de ellas dedicadas b�sicamente al equipo inform�tico, "
   	     "y la tercera, supuestamente de estudio, se halla repleta de ropa, peluches y revistas.\n");
   	
   	add_item(({"cd","cds","dvd","dvds"}),"Ves pilas de CDs y DVDs repartidas por distintas zonas del cuarto. La gran "
   	     "mayor�a corresponde a grupos de m�sica metal o rock alternativo. Entre los que no est�n apilados destaca un "
   	     "DVD de Slipknot, de gran valor sentimental para Inki.\n");
   	     
   	add_item(({"peluche","peluches"}),"Hay una cantidad innumerable de peluches, que van desde tortugas, cocodrilos "
   	     "a ranas, pasando por personajes de Barrio S�samo.\n");
   	
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
