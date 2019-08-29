//Vilat 20.07.2002
inherit "/std/room.c";

void setup() {
  set_short("%^CYAN%^Recibidor de la Torre de Vilat%^RESET%^");
  set_long("La Torre de Vilat es aun mas fascinante vista desde dentro que desde el exterior. Las paredes, el suelo y el lejano techo de hielo negro brillan ante la chisporroteante llama de las antorchas de fuego azul. La planta de la habitacion es hexagonal y en cada uno de los rincones observas extranyas runas que gotean sangre. Esta es recogida en unos canales incrustrados en el hielo que fluyen hasta el centro de la estancia, donde se recogen en una especie de piscina. Unas escaleras suben hacia la cuspide.\n");
  set_light(80);

  add_item(({"pared","suelo","hielo"}),"La estancia esta construida en frio hielo negro, finamente labrado. Las antorchas de fuego azul le arrancan caprichosos destellos.");
  add_item("planta","Al contrario de la irregular forma que presentaba la Torre desde fuera, el interior es un hexagono perfecto.");
  add_item(({"antorcha","antorchas"}),"Numerosas antorchas iluminan la estancia formando un estremecedor espectaculo. Curiosamente, el fuego es de un extranyo azul claro.");
  add_item(({"runa","runas"}),"Las runas del Odio, de la Sangre, de la Destruccion, de la Muerte, del Fin y del Rencor estan grabadas en cada uno de los vertices de la estancia y borbotean sangre. Su brillo anaranjado ofrece un curioso contraste con los tonos frios del resto de la habitacion.");
  add_item(({"sangre","canal","canales"}),"La sangre fluyendo a traves de los canales situados bajo el translucido hielo ofrece una vision conmovedora.");
  add_item("piscina","La piscina de sangre situada en el centro de la sala te produce repugnancia.");
  add_sound("habitacion","Escuchas el crepitar de las antorchas y el aterrador fluir de la sangre.");
  add_feel(({"antorcha","antorchas","fuego","llama","llamas"}),"El fuego azul de las antorchas no desprende calor alguno.");
  
  add_exit("fuera","/w/vilat/workroom","door");
  add_exit("arriba","/w/vilat/maijaus/lvl1","stair");
}

void init() {
  ::init();
  add_action("bucear",({"bucear","zambullirse"}));
  }
  
int bucear(string str)
{
  if(str=="piscina")
    {
      tell_object(TP,"Venciendo tu asco, te sumerges en la sanguinolenta piscina.\n");
      tell_room(TO,TP->query_cap_name()+" se lanza de cabeza a la piscina y bucea en ella. No puedes aguantar el asco y vomitas.\n",TP);
      TP->move("/w/vilat/maijaus/lvl-1",TP->query_cap_name()+" se lanza de cabeza a la piscina y bucea en ella. No puedes aguantar el asco y vomitas.\n",TP->query_cap_name()+" desciende a traves del chorro de sangre.\n");
      TP->look_me();
      return(1);
      }
  notify_fail("Imposible.\n");
  return(0);
}