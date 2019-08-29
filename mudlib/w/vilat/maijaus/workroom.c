#define CREATOR "vilat"
/**
 * Workroom para inmortales sin experiencia.  Aqui intentare que 
 * podais encontrar las cosas mas basicas que se pueden hacer con una
 * room.  Tambien incluye algunas cosas un poco mas avanzadas.
 * Fairiel : 7 agosto, 2000 
 */


/**
 * Para hacer una room, siempre tienes que heredar de otro archivo.
 * Segun el tipo de room que quieras, deberas heredar de un archivo
 * o de otro.Los archivos de los cuales puedes heredar se encuentran
 * en /std/ , y son:
 * room.c        -> para hacer habitaciones de interior.
 * outside.c     -> para hacer habitaciones en el exterior.
 * forest.c      -> para hacer habitaciones que se encuentran en un bosque
 *                  o similar (pantano, etc).
 * underground.c -> para hacer habitaciones que se encuentren en
 *                  la suboscuridad.
 * uwater.c      -> para hacer habitaciones que se encuentran debajo del
 *                  agua.
 */
inherit "/std/room.c";

void setup()
{
  set_short("Habitacion de Trabajo de "+CREATOR);
  
  set_long("   Esta es la habitacion donde realizas aquellas actividades de "
	   "creacion basicas de un inmortal. Puedes ver un viejo sillon al "
	   "fondo de la habitacion junto a una enorme mesa. Una pequenya "
	   "lampara proporciona luz a la habitacion, momento en el cual te "
	   "das cuenta de que tal vez necesite una limpieza.\n\n");
  
  
  /**
   * Selecciona el nivel de luz en la habitacion. ("help light") 
   * para mas detalles.
   */
  set_light(80);
  
  
  /**
   * add_item() es usado para describir todos los objetos que aparecen en
   * tu descripcion.
   */
  add_item("habitacion","La habitacion desprende un olor que te envuelve "
	   "y te hace sentir extranyo. Los muros parecen estar recien pintados.\n");
  
  add_item("pared","Los cuatro muros de color blanco estan sin decorar "
	   "todavia.\n");
  add_item("pintura","Hace pocas horas que los muros han sido pintados de "
	   "blanco por lo que mejor no arrimarse a ellos.\n");
  
  /** Puedes darle a varios objetos la misma descripcion */
  add_item(({"mesa","sillon"}),"Medio tapado con un trapo para que "
	   "no se manche mientras se pinto la habitacion da una la sensacion "
	   "de soledad y misterio.\n");
  
  add_item(({"lampara","lampara pequenya"}),
	   "En el centro de la habitacion hay una lampara que cuelga. Esta prende "
	   "continuamente aceite con lo que consigue emitir un radio de luz "
	   "considerable.\n");
  
  
  /** Anyade caracteristicas reales a tu habitacion */
  add_smell(({"habitacion","aire"}),"Puedes oler la pintura recien "
	    "usada en las pareces.\n");
  
  add_feel("mesa","Sientes la suavidad del fantastico roble con el que "
	   "han hecho la mesa.\n");
  
  add_sound("habitacion","El unico sonido que llega hasta tus oidos es "
	    "el latido de tu corazon.\n");
  
  //En el futuro, tus habitaciones deben de poseer descripciones completas
  //sin que puedan quedarse a medias... 
  
  /**
   * Para incluir objetos en las habitaciones se usara la funcion add_clone(), 
   * para mas detalles man add_clone..
   * Estos objetos pueden ser armas, npcs o cualquier otro objeto.
   * En general se encontraran en ficheros diferentes a los que hacemos una
   * llamada con la funcion add_clone(dir,num).
   */
  add_clone("/obj/misc/button.c",1);
  
  /**
   * Aqui se describe las salidas que pudiera tener tu habitcion
   * add_exit(direccion, destino, tipo)
   * direccion: Sera lo que aparezca en el rotulo de direcciones
   * destino: Direccion donde te movera esa salida
   * tipo: El tipo de salida tiene que ver con una escalera, puerta, etc..
   * Leer /doc/roomgen/exit_type_help para mas informacion, o mirad
   * man add_exits. Aqui vienen muy bien detalladas.
   * Las salidas comunes (norte, sur, etc) deben ponerse en castellano.
   */  
  add_exit("comun","/w/common","door");
  //Esto es necesario para anyadir la salida de common a tu habitacion
  "/w/common.c"->add_exit( CREATOR,"/w/"+CREATOR+"/workroom","door");
  "/w/common.c"->renew_exits();
}

/**
 * La funcion init se llama automaticamente cuando se carga
 * en memoria el objeto (room, npc o lo que sea)
 * Aqui es donde tienes que definir las funciones extra.
 * man init para mas ayuda.
 */
void init()
{
  /**
   * Muy importante esta linea. Aqui llamais al init()
   * del archivo del que heredamos, y es importante.
   * No os olvideis de esta linea.
   */
  ::init();
  /**
   * La funcion add_action ata un comando verbal a una 
   * funcion local, definida en la room. El primer
   * parametro es el nombre de la funcion local, 
   * y el segundo el nombre del comando verbal.
   * man add_action para mas ayuda.
   * Se pueden definir tantas funciones locales como se 
   * deseen.
   */
  add_action("limpiar_mesa","limpiar");
  add_action("mover_mesa","mover");
}

/**
 * Funcion local. El int delante indica que hemos de
 * devolver un entero.
 * El string str que se le pasa, es lo que escribimos
 * despues del comando verbal
 */
int limpiar_mesa(string str)
{
  if(str=="mesa")
    {
      /**
       * Jugamos con las propiedades. Le preguntamos si ya 
       * hemos limpiado la mesa
       */
      if( this_object()->query_timed_property("LIMPIA")==0 ){
	/**
	 * Cuando limpiamos la mesa, le anyadimos
	 * una timed property para que le de tiempo
	 * a ensuciarse y no estar limpiandola todo 
	 * el rato XD joer, que somos inmortales :P
	 * Para mas ayuda:
	 * man add_timed_property, query_timed_property
	 * man add_property, query_property
	 * man add_static_property, query_static_property
	 */
	this_object()->add_timed_property("LIMPIA",1,1000);
	/**
	 * Con esta funcion modificamos la descripcion de un item 
	 * ya existente.
	 * man modify_item
	 */
	modify_item("mesa","La mesa parece haber sido limpiada recientemente.\n");
	tell_object(this_player(),"Empiezas a limpiar la mesa y "
		    "encuentras un papel en ella.\n");
	tell_room(this_object(),this_player()->query_cap_name()+" limpia la mesa "
		  "encontrando en ella un papel.\n",this_player());
	/**
	 * Aqui usa una funcion distina para clonar cosas.
	 * Clone object solo clona el objeto.  Para que salga aqui lo
	 * tienes que traer con el  ->move(this_object())
	 */
	clone_object("/obj/misc/newcreator_paper.c")->move(this_object());
	/**
	 * Devolvemos 1 porque la accion ha sido hecha con exito
	 */
	return(1);
      }
      /**
       * Lo que sale cuando ya has limpiado la mesa una vez
       */
      tell_object(this_player(),"Ya has limpiado la mesa.\n");
      return(1);
    }
  /**
   * Los mensajes de error siempre se dan con notify_fail
   */
  notify_fail("Nada en esta habitacion necesita limpiarse excepto la mesa.\n");
  /**
   * Devolvemos 0 por que no hemos realizado la accion que
   * deseabamos
   */
  return(0);
}

int mover_mesa(string str)
{
  if(str=="mesa")
    {
      tell_object(this_player(),"Mueves la mesa descubriendo una "
		  "trampilla debajo de esta.\n");
      tell_room(this_object(),this_player()->query_cap_name()+" mueve la mesa.\n",
		this_player());
      add_exit("trampilla","/room/void.c","door");
      /**
       * Como modificamos las salidas en una room ya cargada
       * hay que actualizar las salidas. Se hace con renew_exits()
       * man renew_exits para mas ayuda
       */
      renew_exits();
      /**
       * Introduccion para impedir el paso en salidas.
       * La funcion encargada de esto es modify_exit
       * En este caso, le indicamos que queremos
       * modificar la salida "trampilla" con una funcion
       * "function" que se llama "permiso" y que debemos
       * definir. Si devuelve 0, impide el paso.  En caso
       * contrario deja pasar. La funcion modify_exit
       * tiene muchas mas utilidades. Para verlas con mas 
       * detalle, man modify_exit
       */
      modify_exit("trampilla",({"function","permiso"}));
      return(1);
    }
  notify_fail("Mover que?.\n");
  return(0);
}

/**
 * Funcion definida para ver quien puede pasar.
 * Solo si eres inmortal te deja pasar XD
 */
int permiso(){
  if(this_player()->query_creator()){
    tell_object(this_player(),"Pasa, Oh inmortal!\n");
    return(1);
  }
  notify_fail("Un mortal no puede entrar aqui!!!!\n");
  return(0);
}
