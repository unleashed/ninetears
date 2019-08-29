// Theden 03.09.2002 - Room de prueba
// Comentario exhaustivo por Vilat

// Lo primero el inherit. Como heredamos room.c la habitacion es de interior
inherit "/std/room.c";

// La funcion mas importante de cualquier room, item o npc es el setup()
// Rooms, Items y Npcs son objetos. Los objetos siempre deben llevar el setup()
void setup() {

// El set_short es la descripcion que sale cuando vamos en modo brief
// Esta funcion necesita un string (cadena de texto)
// Los string siempre han de ir entre comillas
	set_short ("Sala de justicia del Guild de los Clerigos de Lummen");
// set_long tambien necesita un string entre comillas. Es la descripcion que aparece en
// modo verbose, o si hacemos un look.
// Dentro de cualquier string podemos colocar \n que significa salto de linea
	set_long ("En esta habitacion los miembros del Guild discuten sobre la justicia e injusticia del mundo, buscan las posibles soluciones a ellas y donde juzgan a todos y cada uno de los miembros de las fuerzas de Jade. Puedes ver que hay una especie de sitial, y que junto a el, tanto a la izquierda como a la derecha hay sendas estatuas. Tambien ves unas especies de estrados. Uno para acusados, uno para los testigos y otros para los denunciantes, tambien ves un ventanal que da toda la iluminacion necesaria a la sala. En este lugar te da tranquilidad, y si eres una persona justa quizas algun dia puedas ser el juez de esta sala.\n");
// La luz es un elemento muy importante.
// En Ninetears este elemento sera eliminado, la luz sera determinada por el tipo de room,
// la hora y el clima. Pero de momento se pone
	set_light (50);
// La funcion add_item() nos permite anyadir detalles a nuestras rooms. Estos detalles no se
// pueden coger con "get" ni interactuar con ellos de otro modo que con "look".
// add_item() necesita dos parametros de tipo string, separados por comas. El primero sera
// el identificador y el segundo la descripcion, es decir, si ponemos look <primer parametro>
// nos aparecera como descripcion el segundo.
	add_item ("estatuas","Estas estatuas representan a Lummen y Paris, los dos Grandes Dioses de la Justicia y el Bien. Cuando las miras ves como el ojo derecho de las estatuas tienen un brillo especial.\n");
	add_item ("estrados","Los estrados estan fabricados de madera noble, parece ser de roble o nogal. Deben de costar una fortuna.\n");
	add_item ("sitial","Esta es lugar reservado para el Juez, no deberias sentarte aqui!!. Mejor ponte a mirar las estatuas.\n");
	add_item ("ventanal","Un precioso ventanal al estilo de las vidrieras con varios grabados de los Dioses de la Justicia y de los Clerigos mas famosos.\n");
	add_item ("ojos","Ves que los ojos derechos de las dos estatuas son dos grandes y preciosos rubies.\n");
// add_feel() permite anyadir detalles tactiles a las rooms
// funciona de manera similar a add_item(), pero para apreciar este detalle tendremos que
// usar "tocar" en lugar de "look"
	add_feel ("estatuas","Estas estatuas te infundan gran respeto y tranquilidad.\n");
// Cuando acaba el setup() o cualquier otra funcion no hay que olvidar cerrarla
	}

// La funcion init() en general no hay que incluirla, solo como en este caso para anyadir una
// accion
void init() {
// Dentro del init no hay que olvidar jamas ejecutarlo. Para ejecutar una funcion se escribe
// "::<nombre>();"
	::init();        
// add_action() permite a los jugadores interactuar con la room.
// Lleva dos parametros de tipo string
// El segundo es lo que el player ha de escribir en su linea de comandos para interactuar con
// la room. No olvidar que va entre comillas.
// Si el jugador escribe en su linea de comandos algo que comience por lo que se especifica como
// segundo parametro, se ejecutara una funcion. Esta funcion ha de ir incluida en la room,
// ya sea por herencia o por estar en el mismo archivo. Casi nunca suele ir por herencia, asi
// q tendremos que definirla mas adelanta. El nombre de la funcion a ejecutar se especifica 
// mediante el primer parametro de add_action(), como se ha dicho antes de tipo string y entre
// comillas
// En el ejemplo la funcion es "arrancar_rubies_de_estatuas" y el desencadenante es
// "arrancar". Asi pues, siempre que el player escriba "arrancar <algo>" estando en nuestra
// room, la funcion "arrancar_rubies_de_estatuas" sera ejecutada.
	add_action("arrancar_rubies_de_estatuas","arrancar");
// Cerramos el init
	}

// Aqui se define la funcion "arrancar_rubies_de_estatuas" que sera llamada cada vez
// que un player escriba "arrancar", tal y como hemos definido en el add_action()
// La ponemos como uno funcion de tipo int (entero). El tipo de funcion es importante
// para el return: como es de tipo int hemos de devolver un numero entero.
// Se suele utilizar 0 para indicar que no se ha llevado a cabo con exito, y 1 para
// indicar que si (en el return). Ademas aparece como algo nuevo que la funcion no acaba
// en (), sino en (string str). Esto significa que a la funcion hay que pasarle un string
// que internamente llamaremos str, igual que podriamos haberlo llamado pepito por ejemplo
int arrancar_rubies_de_estatuas(string str) {
// Ahora tenemos que comprobar varias cosas: que se haya pasado el string, que el
// string sea "rubies de estatuas", que el jugador no se haya llevado ya los rubies hace
// poco y que los rubies esten realmente alli, es decir, que no se le haya adelantado nadie.
// Si alguna de estas condiciones no se cumple, el player no obtendra sus preciados rubies.

// Por cierto, el string (que nombramos str) que se pasa a la funcion es todo lo que haya
// despues de "arrancar" en la linea de comandos. Asi, si pusiesemos solo "arrancar", str seria
// nulo, y si ponemos "arrancar la cabeza de theden" str seria "la cabeza de theden"

// Primero vamos a comprobar que str no es nulo:
	if (!str) return notify_fail("Arrancar que?\n");
// ! es un negador, es decir, indica lo contrario. Si hubiesemos puesto "if (str) ..." querria
// decir "si hay str". Como le hemos puesto el negador, lo que quiere decir es "si no hay str"
// y si no hay str es porque str es nulo que es lo que queriamos comprobar.

// Ahora comprobamos que str sea "rubies de estatuas", pues no hay otra cosa que arrancar en
// nuestra room
	if (str!="rubies de estatuas") return notify_fail("Arrancar que?\n");
// != significa "diferente" (estamos negando el igual). La linea significaria "si str es 
// diferente de rubies de estatuas"
// El return notify_fail de esta linea y de la anterior significan que algo no ha ocurrido como
// es debido, asi que interrumpimos las comprobaciones y le damos el mensaje de error al
// player. notify_fail() debe llevar un string que sera el mensaje de error que se mostrara al
// jugador.
// He dicho antes que como la funcion es de tipo int el return debia llevar un numero, y aqui
// lleva notify_fail(). No es nada extranyo, pues notify_fail() equivale a un 0

// Ahora comprobaremos que en la room haya rubies, si no los hay pq ya se los ha llevado alguien
// no tiene sentido que pueda seguir robandolos.
	if (TO->query_property("rubies_cogidos")) return notify_fail("Algun ladron se te ha adelantado.\n");
// TO es una abreviacion de this_object(). Como este archivo es de una room, TO se refiere a la
// room. La flecha indica que query_property() se comprobara sobre TO. query_property() ha de
// llevar un string que es el nombre de la propiedad y devuelve el valor que lleve esa propiedad
// asociado en el objeto. Si el objeto no tiene la propiedad devuelve 0.
// Asi que nuestra linea significaria "si esta room tiene la propiedad rubies_cogidos..." y
// si se cumple devuelve el notify_fail correspondiente.

// Por ultimo comprobamos que el jugador no haya robado ya unos rubies hace poco
	if (TP->query_timed_property("get_rubies")) return notify_fail ("La codicia te acabara matando. Huye con dos rubies y date por contento!!!\n");
// TP es la abreviacion de this_player(), que es el jugador que ha puesto lo de "arrancar ..."
// query_timed_property() es igual que query_property() pero se refiere a propiedades temporales
// La linea significaria "si este jugador tiene la propiedad temporal get_rubies..." y si es asi
// da el error correspondiente

// Si el programa ha llegado hasta aqui es que se han cumplido todos los requisitos necesarios,
// asi que le damos al jugador sus dos rubies
	clone_object("/w/vilat/peta.c")->move(TP);
	clone_object("/w/vilat/peta.c")->move(TP);

// Ya tiene sus rubies, pero no lo vamos a dejar asi. Primero le damos al jugador la property
// temporal de que ya ha mangado los rubies
	TP->add_timed_property("get_rubies",1,20);
// add_timed_property() se usa para anyadir propiedades temporales. Lleva tres parametros
// El primero es el nombre de la propiedad, el segundo el valor asociado a dicha propiedad
// (como dije antes, 1 significa verdadero), y el tercer valor es el tiempo en JB que durara
// la propiedad. Cuando pasen todos esos JBs la propiedad se eliminara

// Tambien tenemos que modificar la room convenientemente para indicar que los rubies han sido
// robados
	modify_item("estatuas","Las estatuas no tienen ojos derechos!!!\n");
// modify_item() es igual que add_item(), solo que modifica la descripcion de un elemento que ya 
// se habia creado antes.

// Y hay que marcar la room convenientemente para que hasta el proximo reset nadie robe mas 
// rubies
	TO->add_property("rubies_cogidos",1);
// add_property() es como add_timed_property() pero permanente (en el caso de las rooms hasta el
// proximo reset). Los dos parametros de add_property() son iguales que los dos primeros de 
// add_timed_property()

// Finalmente damos los mensajes al jugador y a la room de que los rubies han sido mangados:
	tell_object(TP,"Coges dos inmensos rubies de las estatuas.\n");
// tell_object() lleva dos parametros: el primero es el objeto al que se le ha de decir el
// mensaje y el segundo un string, el mensaje.
	tell_room(TO,TP->query_cap_name()+" coge dos rubies inmensos de las estatuas.\n",TP);
// tell_room() manda un mensaje a la room, lleva 3 parametros:
// 1.- Un objeto, que es la room donde se envia el mensaje. En nuestro ejemplo es TO.
// 2.- Un string, que es el mensaje. En nuestro ejemplo es:
//    TP->query_cap_name()+" coge dos rubies inmensos de las estatuas.\n"
// Eso necesita mayor explicacion: podemos sumar dos string, seria como juntarlos. Si sumasemos
// "limpia"+"brisas" nos daria "limpiabrisas", sencillo no?
// TP->query_cap_name() aunque no va entre comillas es un string, que guarda el nombre 
// capitalizado de TP, es decir, si el nombre de TP es "chepamon", TP->query_cap_name()
// significaria "Chepamon" (capitalizar es poner la primera letra en mayuscula). Asi, el
// mensaje seria "Chepamon coge dos rubies inmensos de las estatuas.\n"
// 3.- Un objeto o conjunto de ellos: Estos objetos no veran el mensaje, bien pq no queramos, 
// bien pq ya se les ha dado el suyo propio. Como TP ya ha tenido su propio mensaje, pues le
// ponemos aqui y asi no recibe este mensaje.

// La funcion se ha cumplido con exito
	return 1;
// Cerramos la funcion
	}







