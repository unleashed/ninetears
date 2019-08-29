//Leviathan Mayo �02
inherit "/obj/shield";
 
void setup()  
  { 
 
  set_base_shield("escudo templanza");
  set_name("desplazador"); 
  set_short("%^BOLD%^WHITE%^Desplazador %^WHITE%^de %^CYAN%^Almas%^RESET%^"); 
  set_main_plural("%^BOLD%^WHITE%^Desplazadores %^WHITE%^de %^CYAN%^Almas%^RESET%^");
  add_alias("desplazador");
  add_plural("desplazadores");
  set_enchant(3);
  set_long("Desplazador De Almas.\n"
  	   "Es un gran escudo que cubre practicamente el cuerpo de un humano de talla grande, "
	   "forjado en un material extranyo, puesto que toda su zona interior resulta transparente "
	   "para permitir centrar el ataque y no perder de vista al enemigo, pero a su vez, "
	   "con una resistencia equivalente a mitrhil, material que compone el rico reborde del "
	   "escudo. Unos caracteres inversos se encuentran en el centro del mismo, "
	   "ardiendo en fuego al sentir la batalla, y marcando a los ememigos de por vida en "
	   "aquellos puntos donde son golpeados. Se dice de este escudo que cuando es usado por "
	   "un autentico %^BOLD%^WHITE%^Paladin del Bien%^RESET%^, el alma de su enemigo es enviada directamente a los "
	   "%^RED%^infiernos, donde es torturada por el resto de la eternidad.\n");
   add_property("guild", "paladin");
 }
