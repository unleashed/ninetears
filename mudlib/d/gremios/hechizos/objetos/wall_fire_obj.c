/* 
 * Originalmente codificado por Wonderflug en March'95 en FR - MUD.
 * Adaptado por Paris en Nov'98 y remodelado.
 */
//Vaeleth was here potageando

#include <spells.h>
inherit BASES+"patch";
inherit "/std/object";

#define WALLFIRE_LEVELX 6
#define WALLFIRE_LOCKOUT 40
#define WALLFIRE_DURATION_LEVELX 2
#define WALLFIRE_FAIL_DAMAGE 20
#define WALLFIRE_SUCCESS_DAMAGE 40
#define WALLFIRE_GP 10

object mycaster = TO;
int mycount;
string myexit = "blah";
string myalias;
static int count;
object *pasador = ({ });       // El que puede pasar.
string habitacion;             // Donde va la salida eliminada.

void init()
{
  ::init();
  add_action("do_salir",myexit);
}

int tirada(object ob) {
	int tira = random(200);
	
  if (((random(mycaster->query_int()) < random(ob->query_int())) && (tira < 130)) || ob->query_creator())
	{
		return 1;
	}
	
return 0;

}

void event_enter(object ob, string mess) //usemos el ob que pa algo esta Vaeleth Sep-00
{
  int base=1;               // Para NPC's sin guild =)
  int tirada=random(200);
//  if(!ob->is_player()) npcs, items e inmortales pasan
//     return;     
/*  if (ob->query_guild_ob()) base=ob->query_guild_ob()->query_res_step();
  base*=ob->QL;
  base+=(ob->query_sphere("wizwar")-mycaster->query_sphere("wizwar"))*10;
             
  if (tirada>=(199-ob->query_cha()) || tirada<=base)*/
  if (((random(mycaster->query_int()) < random(ob->query_int())) && (tirada < 130)) || ob->query_creator())
  {
    tell_object(ob,"Una magnifica percepcion te permite observar que en "
                   "realidad hay una salida hacia "+myexit+" pero que "
                   "esta disimulada por una ilusion.\n");
    pasador += ({ ob });
    return 1;
  }
}
                   
int dispell_me()
{
  tell_room(ETO, "Repentinamente una salida en direccion "+myexit+" reaparece "
                 "en este lugar.\n",);
  environment(TO)->add_exit(myexit,habitacion,"path");
  environment(TO)->renew_exits();
  TO->dest_me();
  return 1;
}

string query_exit_wall()
{
  return myexit;
}


void set_spell(object ob, string exit)
{
  int i;
  mixed *donde;
	object *obs;
  
  mycaster = ob;
  mycount =(int) ob->QL * WALLFIRE_DURATION_LEVELX;
  myexit = exit;

  donde = environment(mycaster)->query_dest_dir();
  for(i=0;i<sizeof(donde);i++)
    if(donde[i] == exit)
      habitacion = donde[i+1]; 
      
  environment(mycaster)->remove_exit(exit);
  reset_get();
  set_heart_beat(1);
  pasador += ({ mycaster });
  obs = all_inventory(ETO);
  for(i=0;i<sizeof(obs);i++) {
  	if (obs[i] == mycaster)
  		continue;
  	if (tirada(obs[i])) {
  		pasador += ({ obs[i] });
    		tell_object(obs[i],"Una magnifica percepcion te permite observar que en "
                   "realidad hay una salida hacia "+myexit+" pero que "
                   "esta disimulada por una ilusion.\n");

  	}
  }
}

void setup()
{
  set_name("");
  set_short("");
  add_alias("");
  add_static_property("dead", 1);
  set_long("");
  add_property("no_destruible",1);
}

void heart_beat()
{
  if (count++ > mycount)
    dispell_me();
  set_heart_beat(1);
}

int existe(object ob)
{
  int i;
  for(i = 0;i<sizeof(pasador);i++)
    if(pasador[i] == ob) return 1;
  return 0;
}
    

int do_salir()
{
  object ob;
  
  if(existe(TP))
  {
    if(!ob=find_object(habitacion))
      ob=load_object(habitacion);
    TP->move(ob);    
    TP->look_me();
    return 1;
   }
  else return 0;
}