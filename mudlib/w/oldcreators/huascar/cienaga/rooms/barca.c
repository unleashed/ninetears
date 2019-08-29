/* diablo oct 01
 * Hacer notar que el NPC leviatan es el que indicara a la
 * room cuando ha muerto, de tal forma que sera el quien provoque
 * el final de los call_out de la habitacion.
 */

inherit "/std/room.c";
#include "../path.h"

int remando = 0;                     // Indica si se esta remando o quietos
int paso = 0;                        // Numero de atake por el que vamos
int combate_realizado = 0;           // Si hemos realizado el comabte con el lev
object leviatan ;                    // El objeto leviatan
#define MIN "/w/leviathan/"
#define NPCBO "/w/huascar/cienaga/npc/"
#define NUM_MAX_PASOS 5              // Numero maximo de pasadas de atakes
#define CASILLA_MUERTA MIN"baul.c"   // Indica donde "guardar" el leviatan

int query_combate_realizado(){ return combate_realizado; }
int query_paso(){ return paso; }


void setup()
{
  set_light(15);
  switch(paso)
  {
    case 0:
      set_short("Barca en el Lago - Buen Estado");
      set_long(" La ancha nave se mueve impulsada por los incansables remeros. "
	 "Las aguas estan calmadas y solo los gritos del capitan marcando el ritmo se "
	 "escucha a bordo. El cargamento de Mitrhil esta firmemente sujeto en la bodega "
 	 "y un putrefacto olor a agua estancada lo inunda todo. Sobre la calmada superficie "
	 "del lago subterraneo te parece ver una ola a lo lejos pero no le prestas mucha "
	 "atencion pues tienes entendido que ningun ser vive en tan oscuros fondos.\n");
    break;
    case 1:
      set_short("Barca en el Lago - Algo rota");
      set_long(" Numerosas vias de agua inundan la nave, los cadaveres de los remeros muertos "
	 "llenan la embarcacion y los que quedan vivos se reparten entre babor y estribor "
	 "para compensar la direccion de la misma. Algunos cuerpos han caido al agua y "
 	 "van desapareciendo uno a uno engullidos por la bestia.\n");
    break;
    case 2:
      set_short("Barca en el Lago - Rota");
      set_long(" La barcaza es un caos total. Solo dos remeros se mantienen con vida y presos "
	 "del panico son incapaces de manejar la embarcacion. Los bultos de carga que "
	 "antes estaban bien atados se mueven sin cesar una vez rotos los cabos que los "
	 "sujetaban. Alguno de ellos incluso ha aplastado a un miembro de la tripulacion. "
	 "La estabilidad de la cubierta es nula y te cuesta mantenerte en pie.\n");
    break;
    case 3:
      set_short("Barca en el Lago - Muy Rota");
      set_long(" La barcaza esta destrozada, a duras penas se mantiene a flote y la popa ha "
	 " desaparecido tras el ultimo brutal impacto. "
	 " Sin ningun miembro de la tripulacion vivo y con la carga cayendo al lago te "
	 " preguntas cuanto tiempo mas durara a flote. La quilla parece estar tambien "
	 " danyada y la embarcacion cruje sin parar. Numerosas astillas de madera flotan "
 	 " en el agua que poco a poco inunda la nave.\n");
    break;
    case 4:
      set_short("Barca en el Lago - Hundiendose");
      set_long(" Solo quedan unas cuadernas unidas por la crujia. La maltrecha estructura se "
	 " hunde por momentos. Los sollaos han quedado ahora al descubierto al salir "
	 " despedida la cubierta y los catres salen flotando al exterior. Las maderas "
	 " estan impregnadas por un liquido viscoso de color amarillo que mana de las "
	 " heridas del Leviathan a cada pasada que da. El atisbamiento de la orilla por "
	 " estribor tras unas rocas te da un soplo de esperanza. Quiza si logras llegar "
 	 " nadando a ella podrias escapar con vida.\n");
    break;
  }
  if(!paso && !remando)  add_exit("puerto",MIN"M0402.c","path");
}

void init()
{
  ::init();
  add_action("do_remar","remar");
}


/* Algunas desc del atake del leviatan a la barca, para que no les llegue de sorpresa
 */
void desc_barca()
{
  tell_room(TO,"%^BOLD%^El leviatan golpea con furia desmedida la barca y esta cruje con "
               "violencia cuando la madera se astilla y se ve retorcida.%^RESET%^\n");
}
/* Funcion que controla los atakes del leviatan, le pegara a 
 * cada uno de los objetos livings de la room
 */
void atake()
{
   object *all = all_inventory(TO);
   object cow;
 
   leviatan->move(TO);
   foreach(cow in all)
     if(living(cow) && cow!=leviatan)
     {
       cow->attack_by(leviatan);
       leviatan->attack_by(cow);
     } 
   call_out("retirada",30);
   call_out("desc_barca",random(25));
}

/* Establece la cadencia con la que se va a realizar el atake, dando 
 * tiempo a los players a recuperar spells y comandos, asi como establecer
 * curas y tal
 */
void llega_leviatan(int i)
{
  switch(i)
  {
    case 1:
      tell_room(TO,"A lo lejos, en medio del lago, oyes como el rumor del "
                   "agua crece. Algo grande se acerca.\n");
      call_out("llega_leviatan",6,2);
    break;
    case 2:
      tell_room(TO,"El ruido es ensordecedor en este momento, tu cabeza "
                   "apenas puede aguantar la presion de las ondas sonoras. "
                   "Lo que viene hacia aqui esta ya muy cerca !.\n");
      call_out("llega_leviatan",6,3);
    break;
    case 3:
      tell_room(TO,"El Monstruo ha llegado !.Es un Leviatan y esta "
                   "_MUY_ furioso !!\n");
      call_out("atake",0);
    break;
  }
}


/* Funcion que desencadena el atake del leviatan, establece 
 * el combate, quita la variable de remado y pone a uno la variable
 * de control del combate: estamos peleando
 */
void iniciar_ataque()
{
  remando = 0;                   // Van a empezar los combates, dejamos de remar
  combate_realizado = 1;         // Entramos en combate
  call_out("llega_leviatan",0,1);
}


/* Establece la cadencia de remado.
 * El primer argumento indica la direccion:
 *  i = 0: Remando al centro del lago
 *  i = 1: Remando a la cosa
 * El segundo argumento indica el paso temporal por el que estamos
 */
void do_remando(int i, int j)
{
  switch(i)
  {
    case 0:
      switch(j)
      {
        case 0:
          tell_room(TO,"Vais moviendoos con suavidad por hacia el centro " 
                       "del lago. Algunos murcielagos vuelan a tu "
                       "alrededor cazando insectos. Despues de todo no es "
                       "un sitio tan inhospito.\n");
          call_out("do_remando",12,0,1);

	break;
	case 1:
	  tell_room(TO,"Abruptamente el aire parece enviciarse. La temperatura "
	               "baja bruscamente. Los murcielagos huyen desesperadamente "
		       "en todas direcciones. Algo malo esta pasando. Dejais "
		       "de remar para poder escuchar mejor.\n");
	   call_out("iniciar_ataque",0);
	   leviatan = clone_object(NPCBO"leviatan");
	break;
      }
    break;
    case 1:
      switch(j)
      {
        case 0:
	  tell_room(TO,"Una vez concluido el combate con el Leviatan la cueva "
	               "y el lago parecen recuperar actividad normal. El frio "
		       "desaparece poco a poco y te sientes mas euforico de lo "
		       "que puedes llegar a recordar. La barca empieza su mareante "
		       "viaje hasta la costa.\n");
	  call_out("do_remando",12+random(12),1,1);
        break;
	case 1:
	  tell_room(TO,"Vuestro viaje de vuelta practicamente ha concluido, "
	               "la felicidad os embarga, vuestra empresa ha sido "
		       "gloriosa.\n");
	  call_out("finalizar_viaje",random(30));
	break;
      }
    break;
  }
}      

/* La funcion que establece las remadas, hacia el lago y hacia la costa.
 * Controla que no intentes remar en un caso ilegal. 
 */
int do_remar(string str)
{
  
  if(remando)
  {
     notify_fail("Ya estas remando.\n");
     return 0;
  }
  if(combate_realizado == 3)
  {
    notify_fail("Carece de interes el ir ahora al centro del lago.\n");
    return 0;
  }
  if(paso && combate_realizado == 1)
  {
    tell_object(TP,"Estas demasiado ocupado repeliendo los ataques del "
                   "leviatan e intentando acabar con �l como para dedicarte "
                   "ahora a estas cosas.\n");
    return 1;
  }
  remove_exit("puerto"); // Ya no estamos en el puerto, hay que quitar
  renew_exits();         // la salida
  switch(str)
  {
  case "al lago":
    if(!paso && !combate_realizado)
    {
      tell_room(TO,"Os poneis a remar hacia el centro del lago.\n");
      call_out("do_remando",8,0,0);
      remando = 1;
      return 1;
    }
    if(paso && combate_realizado == 2)
    {
      tell_object(TP,"Remar al lago ? Ya estas en el lago.\n");
      return 1;
    }
  break;
  case "a la costa":
    if(!paso && !combate_realizado)
    {
      tell_object(TP,"Ya estas en la cosa.\n");
      return 1;
    }
    if(paso && combate_realizado == 2)
    {
      tell_object(TP,"Por fin puedes remar de vuelta a la costa. Mirando "
                     "la barca ves que ha sido un milagro el poder volver.\n");
      tell_object(TO,"La barca se pone en marcha en direccion a la costa.\n");
      remando = 1;
      call_out("do_remando",8,1,0); 
      return 1;
    }
  break; 
  default: 
    tell_object(TP,"Remar\nUso: remar a la costa 'o' remar al lago\n");
    return 1;
  break;
  }
}


/* El parametro de entrada indica el tipo de finalizacion:
 * i = 1: Entonces el combate acaba por leviatan muerto
 * i = 0: Entonces el combate acaba por rounds 
 * Ponemos la variable del combate a 2, el combate a finalizado
 */
void finalizar_combate(int i)
{
  remove_call_out("desc_barca");
  if(combate_realizado < 2)
    if(i)
    {
      tell_room(TO,"Debido a las graves y cuantiosas heridas mortales "
                   "que ha sufrido el leviatan este muere sin remision, "
                   "hundiendose en el fondo del lago para siempre.\n");
      tell_room(TO,"La barca ha aguantado milagrosamente los embites "
                   "del enorme y maligno ser, ahora podeis remar hasta "
                   "la orilla del lago, eso si, con cuidado.\n");
    }
    else
    {
      tell_room(TO,"El casco de la barca comienza a resquebrajarse por todas "
                   "partes y rapidamente, debido a los fuertes embites del "
                   "agua embrabecida por el Leviatan, penetra en el interior "
                   "haciendo que esta se hunda.\n");
      tell_room(TO,"No teneis tiempo de salvaros y la barca se hunde con "
                   "vosotros.\n");
    }
  combate_realizado = 2;   // El combate ha concluido  y los chicos
                           // estan en mitad del lago, ya pueden volver
  if(leviatan)
    leviatan->dest_me();   // Hemos concluido, el leviatan nos sobra :)
}

/* Funcion que controla las retiradas del leviatan, si existe el
 * objeto, claro.
 */
void retirada()
{
  if(leviatan)
  {
    if(!find_object(CASILLA_MUERTA))
      load_object(CASILLA_MUERTA);
    leviatan->move(CASILLA_MUERTA);
    paso++;
    if(paso == NUM_MAX_PASOS)
      finalizar_combate(0);
    else
    {
       tell_room(TO,"El Leviatan se marcha rugiendo y resoplando de "
                 "frustracion, parece que no le ha gustado no poder "
                 "mataros. Seguro que volvera, pues son animales muy "
                 "fieros, salvajes y sanguinarios.\n");
       call_out("iniciar_ataque",17+random(7));
    }
    setup();              // Renovamos las descripciones de la barca
  }
}

void finalizar_viaje()
{
  combate_realizado = 3; // El combate acabo, volvimos a la playa,
                         // el leviatan esta muerto.
  add_exit("puerto",MIN"puerto","path");
  renew_exits();
}

