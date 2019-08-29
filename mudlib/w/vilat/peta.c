//Seregros 16.07.2002

// Este inherit se lo meto a object pq no se si se pueden meter mas funciones ademas del create() -en RL el setup()- a un item
inherit "/std/object";
// Generalmente me creo una hoja de definiciones aparte y despues hago la llamada desde el codigo, pero ahora no es momento de liar las cosas para un solo item
// Espero que las definiciones sean igual que en C


void setup()
{
   set_name("peta");
   set_short("Peta");
   add_alias(({"peta","porro","Porro"}));
   set_long("Se trata de un porro liado apresuradamente. Fumatelo rapido o se abrira.\n");
// Me hubiera gustado que de acuerdo con la descripcion el objeto se destruyese al cabo de un tiempo por si mismo o al dejarlo en el suelo, pero aun no se como hacer eso
   set_main_plural("Petas");
   add_plural(({"petas","porros","Porros"}));
   set_weight(5);
   set_value(0);
   }

void init()
{
   ::init();
   add_action("petafumado", "fumar");
}

int petafumado(string arg)
{
   if (!arg) return 0;
   if (arg!="peta") return 0;
   
   write("Te fumas el delicioso peta.\n");
   tell_room(environment(TP),TP->query_cap_name()+" se fuma un pedazo de estaca y no te da ni una sola calada.\n",({TP}));
// Los efectos ya se que son extra�os, pero el efecto de un peta siempre es impredecible... Tb me habria gustado que le metiese algun nivel de intoxicacion al propietario, pero no se como va eso en RL.
   TP->adjust_hp(5-random(20));
   TP->adjust_gp(random(20)-5);
// Es mas, si mas adelante creo una version mejorada de este item, pienso meterle un random con switch para diversos efectos (que cure o quite solo hps, gps, intoxicacion, varios de ellos... que los niveles sean mas o menos altos...)
   TO->dest_me();
   return 1;
}
// Finalmente, explicar que si hice este item era solo con fines de aprendizaje y que jamas meteria algo asi en el juego, ya que destrozaria su atmosfera epica.
// Por otro lado, para alguien que empieza, creo que asi resulta mas atractivo explorar el codigo del item y tratar de comprenderlo, en lugar de simplemete hacer copy&paste y cambiar los datos de las descripciones

// Este item ya esta... Como ya he dicho, me gustaria mejorarlo pero necesito saber como ajustar (set/adjust?) y conocer (query?) el nivel de intoxicacion del player. Para el switch/random creo que se como hacerlo sin demasiados problemas.
// En el futuro querria saber tambien como codificar items de tipo arma/armadura pero en RL no se que hay que meterle en inherit ni los comandos que usa
