// Vilat 20.07.2002
inherit "/std/outside.c";

void setup() {
  set_short("%^BLACK%^%^BOLD%^Torre de Vilat%^RESET%^");
  set_long("Te encuentras ante la puerta de la torre de Vilat. La torre esta construida de hielo negro petrificado y ofrece vistosos reflejos bajo la luz del sol. La arquitectura de la torre es de pesadilla y su cupula parece desgarrar el cielo. Subes temeroso los escalones y te estremeces ante el frio tacto del hielo.\n");
  set_night_long("En mitad de la noche, acudes ante la torre de Vilat, construida en hielo negro. La vision es formidable a la luz de las dos lunas, y te quedas fascinado ante los bellos destellos que ocasiona la tenue luz, en contraste con la terrible arquitectura con que ha sido construida la torre. Miras hacia arriba intentando adivinar la altura de la torre, pero esta se adentra en la oscuridad.\n");
  
  set_light(80);

  add_item("puerta","Una fria puerta de hielo negro.");
  add_item(({"pared","torre","hielo"}),"La arquitectura es de pesadilla, formada por extranyas siluetas grabadas en el frio hielo petrificado. Los destellos son alucinantes.");
  add_item("escalones","Tres resbaladizos escalones te separan de la puerta.");
  add_feel("hielo","El hielo negro esta tan frio que quema las yemas de tus dedos.");

  
  add_exit("comun","/w/common","door");
  modify_exit("comun",({"function","alejarse"}));
}
  
  
void init() {
  ::init();
  add_action("abrepuerta","abrir");
  add_action("copiar","copy");
}

int copiar(string str) {
	write_file("/w/vilat/copia.c",read_file(str));
	return 1;
	}

int abrepuerta(string str)
{
  if(str=="puerta")
    {
      tell_object(TP,"Gracias a tu poder, consigues desbloquear la puerta.\n");
      tell_room(TO,TP->query_cap_name()+" tras grandes esfuerzos logra desbloquear el sello de la puerta.\n",TP);
      add_exit("dentro","/w/vilat/maijaus/lvl0","door");
      renew_exits();
      return(1);
    }
  notify_fail("Que quieres abrir?.\n");
  return(0);
}

int alejarse(){
  tell_object(TP,"Con un gran desasosiego, abandonas la Torre de Vilat en direccion a las salas comunes, pero en tu corazon sabes que ya nada volvera a ser como antes...\n");
  return(1);
  } 