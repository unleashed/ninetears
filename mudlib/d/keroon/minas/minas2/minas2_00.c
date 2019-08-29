// Made by valar  12/07/02

inherit "/std/suboscuridad";
#include "/d/keroon/path.h"

void setup() 
{

   set_zone("minas2");
   set_exit_color("yellow");
   set_light(20);
   set_short("%^BOLD%^BLACK%^Minas de Keeroon: %^RESET%^Nivel 2");
   set_long("\n%^BOLD%^BLACK%^Minas de Keeroon: %^RESET%^Nivel 2.\n\n"
   " Entras en el segundo nivel de la mina, aqui ves como abundan los mineros y los "
   "cascotes por el suelo, deberias llevar cuidado de no tropezar. Puedes ver las "
   "vetas de cobre sobresalir de las paredes y los mineros trabajando sin descanso "
   "para sacar la mayor cantidad posible. El aire es irrespirable, notas como a tus "
   "pulmones te duelen al respirar. No deberias permanecer aqui mucho tiempo.""\n\n");

add_item(({"cascotes"}),"Son cascotes desprendidos de las paredes en construcciones, que han sido arrastrados por los esclavos en su transito por las minas.\n"); 
add_item(({"filon","filones","cobre"}),"Son varios filones de cobre. En esta zona de la mina es donde mas abunda.\n");

add_clone(NPCSMINAS+"bixos_minas2.c",random(6));

//Salidas disponibles
add_exit("sur","d/keroon/minas/minas2/minas2_09.c","standard");

modify_exit("sur",({"function","trampa_de_vapor"}));
 }
  
  
	int trampa_de_vapor()
{
  	
  	int tokado;
  
  	tokado=random((this_player()->query_dex())*10);
 	if (tokado<100)
{
	tell_object(TP, "Al avanzar por la zona una nube de vapor surge repentinamente de \n"+
  	"una grieta en el suelo quemandote la cara y produciendo un dolor \n"+
  	"indescriptible...\n");
  	tell_room(ENV(TP), TP->QCN+"Un chorro de vapor surge del suelo vaporizando a "+
  	this_player()->_query_cap_name()+" y dejandole unas muy feas "+
  	"quemaduras.\n",TP);
	this_player()->adjust_hp(-(random(20)+10));
	return 1;
 }
	else
{
	return 1;
 }
}
