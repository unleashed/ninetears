inherit "/obj/weapon";

void setup()
{
  set_base_weapon("dirk");
  set_name("sai de flavia");
  set_short("%^BOLD%^%^BLACK%^Sai %^RESET%^de %^BOLD%^%^RED%^Flavia%^RESET%^");
  set_long("Este arma parece un pu�al,pero no llega a serlo, la empu�adura "
  	"esta cubierta de cuero negro para poder cogerla con m�s firmeza, "
  	"en el pomo de este arma hay unas runas grabadas en un idioma que "
  	"antes no hab�as visto, es dif�cil de descifrar. El gavil�n de este "
  	"pu�al es muy simple pero de los extremos salen dos filos paralelos "
  	"a la hoja, aunque mas peque�os, estos filos pueden utilizarse "
  	"para parar los ataques del enemigo e intentar as� destrozar su arma "
  	"largo que en otras armas,sirve para parar el ataque de otras espadas "
  	"La hoja es muy simple y fina pero tan afilada que podr�as cortar hasta "
  	"el aire, lleva grabado a lo largo del filo unas runas negras. Es un "
  	"arma de acabado perfecto como nunca antes hab�as visto.\n");
   
  set_main_plural("%^BOLD%^%^BLACK%^Sais %^RESET%^de %^BOLD%^%^RED%^Flavia%^RESET%^");
  add_alias("sai");
  add_plural("sais");
  set_enchant(3);
  
}
