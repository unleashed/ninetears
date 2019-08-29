/* Armadin, Master de Asesinos */
/* Ahora se puede mandar un tel a armadin para saber los contratos activos 
   by Iolo 5-2000 */
#include "path.h"

inherit NPCS+"asesinos";

#define CONTROL "/d/oficios/asesinos/contracts/contract_room.c"

void setup()
{ 
  set_name("armadin");
  set_short("Armadin");
  set_long("Conocido y temido alla por donde iba, Armadin fue hace ya "
     "bastante tiempo un Asesino despiadado. No mataba por dinero, sino por "
     "placer, la sangre era su diversion favorita. A medida que se hizo "
     "viejo, su corazon se ablando y empezo a soportar a sus companyeros de "
     "gremio y finalmente se convirtio en el Gran Maestro de los Asesinos. "
     "Aun siendo ya mayor para su raza, Armadin es sin duda un rival temible "
     "no solo para sus aprendices. Sus certeras emboscadas pueden acabar con "
     "el mas grande de los guerreros que ose entrar en la guarida de los "
     "Asesinos.\n");
  set_gender(1);
  set_al(1000);
  set_con(25);
  set_str(30);
  set_dex(25);
  set_int(25);
  set_wis(25);
  set_cha(25);
  set_ac(50);
  set_level(95);
  set_race("Goblin");
  set_race_ob("/std/races/goblin");
  set_guild_ob("/std/guilds/rogues/assassin");
/* 
  load_chat(20,
  ({
    1,"'MEJOR no seas uno de esos miembros de algun clan, o ALGO PARECIDO!",
  }));
*/
  add_clone(ITEMS+"yelmo_erdzham",1);
  add_clone(ITEMS+"cota_erdzham",1);
  add_clone(ITEMS+"capa_erdzham",1);
  add_clone("/baseobs/weapons/bastard_sword",2);
  init_equip();
}


/* todo esto es para listar los contratos via armadin */

void event_person_tell(object ob, string start, string mess, string lang, int speaker)
{
  if ( ( (ob->query_guild_name()=="Asesino") ||
         (ob->query_creator()) ) &&
       (mess=="contratos") )
     call_out("lista",4,ob);
}

void lista(object ob)
{
  mapping contratos;
  object hand;
  int i;
  string mess;
  string *aux;
  
  hand = find_object(CONTROL)->query_handler();
  if (!hand) {
    load_object(CONTROL);
    hand = find_object(CONTROL)->query_handler();
  }
  contratos = hand->query_contract_data();
  

  if (!sizeof(contratos)) {
    tell_object(ob,"Armadin te dice: No hay contratos activos... Parece que "
     "es temporada baja.\n");
    return;
  }
 
  aux = keys(contratos);

  if (sizeof(aux)==1) { 
    tell_object(ob,"Armadin te dice: La unica persona contratada es: "
    +capitalize(aux[0])+".\n");
    return;
  }

  mess = "";
  for (i=0;i<sizeof(aux);i++) {
    mess = mess+capitalize(aux[i]);
    
    if ( (i+2)==sizeof(aux) ) mess = mess+" y ";
    else if ((i+1) < sizeof(aux)) mess = mess+", ";
  }

  tell_object(ob,"Armadin te dice: Las futuras victimas contratadas "
   "en este momento son: "+mess+".\n");
}

