// Rutic Manoslargas
// Ather '00
inherit "/obj/monster";
#define SOMBRA "/std/commands/shadows/hide.c"
object me;
int oculto;
object sombra;   	
object lastobject;
object room=load_object("/w/common.c");
object antesdebaul;
object baulroom;
int inicial;
int tiempobaul;
int inmochila;

string hora=ctime(time());
string ultimasalida;
string str;
int moveafter=7+random(2);


object *call_outed,*atts_list,target;
int pirandose,contador;
int tiempo,j;

void heart_beat()
{ 
// tell_room(ENV(TO),"."+tiempo+"\n");

tiempo++;
// tell_object(find_player("ather"),"Tiempo: "+tiempo+"\n");
if (tiempo>moveafter && !TO->query_property("robando"))
	{	
//	tell_object(find_player("ather"),"Rutic te dice: Me muevo!!\n");
//	 call_out("pirarse",1);
	       tiempo=0;
	       if (contador>2 && !TO->query_hide_shadow())
	       		{
	       		contador=0;
	       		call_out("esconderse",0);	       		
	       		//tell_room(ENV(TO),"Llamando a esconderse\n");
	       		}
	       	//tell_room(ENV(TO),"Contador pa esconderse: "+contador+"\n");
	       contador++;
	       

	}
 ::heart_beat(); 
 }


void setup()
{
me = this_player();	
   set_name("rutic");
   set_short("Rutic Manoslargas");
   set_long("Rutic es uno de los mas habiles halflings que hayas visto "
   	    "jamas. Es muy conocido por ayudar desinteresadamente a la "
   	    "gente que esta a punto de perder sus pertenencias, recogiendolas "
   	    "por ellos y guardandolas en un sitio seguro.\n");
   
   set_gender(1);

   set_race_ob("std/races/halfling");
   set_guild_ob("/std/guilds/rogues/thief");
   set_al(-900);

  add_timed_property("fire",50,900000000);
  add_timed_property("cold",50,900000000);
  add_timed_property("air",50,900000000);
  add_timed_property("poison",50,900000000);
  add_timed_property("electrical",50,900000000);
  add_timed_property("magical",50,900000000);
  add_timed_property("acid",50,900000000);
  add_timed_property("stone",50,900000000);
  add_property("no_destruible",1);
   set_main_plural("halflings");
   add_plural("halflings");
   set_level(35);
   set_int(10);
   set_wis(10);
   set_cha(20);
   set_str(17);
   set_dex(20);
   set_con(15);
   set_max_hp(300);
   set_wimpy(20);   
   set_kill_xp(0);

clone_object("/baseobs/armours/leather.c")->move(TO);
clone_object("/baseobs/weapons/dagger.c")->move(TO);
clone_object("/baseobs/weapons/dagger.c")->move(TO);
clone_object("/d/anduar/objetos/llave.c")->move(TO);
   init_equip();
   	              
   }

void init()
{
add_action("buscar","buscar");
  ::init();  
} 

int buscar()
{
call_out("huir",2);
return 0;
}


void datos(object ob)
{

        tell_object(ob,"\n-----------------------------------------------\n");        
        tell_object(ob,"Hora inicial: "+hora+"\n");
        tell_object(ob,"Hora actual: "+ctime(time())+"\n");
        tell_object(ob,"Path: "+file_name(ENV(TO))+"\n");
        tell_object(ob,"Room: "+ENV(TO)->query_short()+"\n");
        tell_object(ob,"Tiempo restante para guardar en baul: "+(1800-(tiempobaul*5))+"\n");
        tell_object(ob,"Inicial: "+inicial+"\n");
        tell_object(ob,"-----------------------------------------------\n");
	

}

void event_person_tell(object ob, string start, string mess, string lang) 
{
if (ob->query_creator() && mess=="datos")
{
call_out("datos",1,TP);
}
if (ob->query_creator() && mess=="tiempo")
{
tiempobaul=360;
}
}

 void event_enter(object target, string MESG, object FROM)
{

  int i,i2,i3;
  int valor; 
  int robado;  
  object objeto;
  object *hab, *mochila;
  object *equipo;
  string donde;

  inicial++;
  if (inicial==1){
  	str="Nas chicos... ya estoy aqui de nuevo.";
"/global/do_chat"->do_channel("anduar",str,"%^BOLD%^Rutic%^RESET%^");   	
  	call_out("pirarse",1);
	}
  if (inicial==2){
  	call_out("baul",1);
  	}
  

  if (inicial<5){return 1;}
if (inicial==6){
	// tell_object(find_player("ather"),"Pillando cosas!\n");
  	call_out("pillarcosas",1);
  	}

/*
tell_object(find_player("ather"),target->query_name()+" es lo primero en event_enter!!!!!\n");
tell_object(find_player("ather"),"Empezando event enter.\n");
tell_object(find_player("ather"),"Comprobando properties.\n");

if (TO->query_property("huyendo"))
	{ return 1;}
	else {tell_object(find_player("ather"),"NO HUYENDO.\n");}
if (TO->query_property("robando")) 
	{ return 1;}
	else {tell_object(find_player("ather"),"NO ROBANDO.\n");}

// tell_room(ENV(TP),"Revisando la room: "+->query_short()+" pa ver q me pillo :)_\n");
*/
room=ENV(TO);
//tell_object(find_player("ather"),"La room es: "+room->query_short()+"\n");

hab = all_inventory(room);
  
  for (i=0;i<sizeof(hab);i++)
  {
  	//tell_object(find_player("ather"),"Comprobando: "+hab[i]->query_short()+"\n");
    if(hab[i]->is_player())     
    {   

// tell_object(find_player("ather"),"Mirandole el equipo a: "+hab[i]->query_cap_name()+"\n");    	

    	equipo = all_inventory(hab[i]);
inmochila=0;
for (i2=0;i2<sizeof(equipo);i2++)
    		{    		
	//tell_object(find_player("ather"),"Tiene: "+equipo[i2]->query_short()+"\n");
    		if (equipo[i2]->query_short()=="Mochila sin Fondo")   		
    			{
//  tell_object(find_player("ather"),"Tiene: "+equipo[i2]->query_short()+" <- Mochilaaa!!!\n");    				
			mochila = all_inventory(equipo[i2]);    				
			for (i3=0;i3<sizeof(mochila);i3++)    				
				{		
//	tell_object(find_player("ather"),"En mochila tiene: "+mochila[i3]->query_short()+" -> VALOR: "+mochila[i3]->query_value()+"\n");								
    					if (valor<(mochila[i3]->query_value()))    			
    					{    				
    					valor=mochila[i3]->query_value();
    					objeto=mochila[i3];
//    					tell_object(find_player("ather"),"En mochila intento robar: "+objeto->query_short()+"\n");								
    					inmochila=1;
    					}
				}
    			}
    		if (!equipo[i2]->query_in_use())
    			{    			
    			if (valor<(equipo[i2]->query_value()) && equipo[i2]->query_short()!="moneda" )    			
    			{    				
    			valor=equipo[i2]->query_value();
    			objeto=equipo[i2];
    			inmochila=0;
    			}
// tell_object(find_player("ather"),"Lo + caro de momento: "+objeto->query_short()+" -> "+valor+"\n");    	

    			}
    		}
    	
    		if (TO->query_property("robando")) return 1;    				
    		TO->add_timed_property("robando",1,20);
if (inmochila)
str="A ver si le robo "+objeto->query_short()+" a la mochila de "+hab[i]->query_short()+".";
else
str="A ver si le robo "+objeto->query_short()+" a "+hab[i]->query_short()+".";
"/global/do_chat"->do_channel("anduar",str,"%^BOLD%^Rutic%^RESET%^"); 

    				call_out("robar",5,objeto,hab[i],ENV(TO));
	
    		}
    		    
 
  }
}


int robar(object objeto,object quien,object room)
{
object *hab;
int i;
int peso;
int probabilidad;
 
hab = all_inventory(room);

  for (i=0;i<sizeof(hab);i++)
  {
    if(hab[i]==quien)     
    {   
    	peso=objeto->query_weight();
    	if (peso<300){probabilidad=random(20)-random(14);}
    	if (peso>300){probabilidad=random(20)-(peso/50);}
    	if (probabilidad>0)    	
    	{    	
	write_file("/d/anduar/logs/rutic.txt",""+quien->query_cap_name()+" // "+objeto->query_short()+" // "+ctime(time())+".\n");    		
str="Juas juas... soy un crack... se lo he robao!!";
"/global/do_chat"->do_channel("anduar",str,"%^BOLD%^Rutic%^RESET%^"); 

    	objeto->move(TO);	 
	lastobject=objeto;
    	do_command("equip");
	}
	if (probabilidad<0)    	
	{
	tell_object(quien,"Notas a Rutic hurgando en tu equipaje!!\n");
	tell_room(ENV(quien),quien->query_cap_name()+" pilla a Rutic hurgando en su equipaje.\nVaya pillada!!\n",quien);	

str="Q cabron... me ha pillao!! ";
"/global/do_chat"->do_channel("anduar",str,"%^BOLD%^Rutic%^RESET%^"); 
	
	quien->attack_ob(TO);
	call_out("huir",1);
	}		
    	TO->remove_timed_property("robando");
    	if (probabilidad>0)
	{call_out("reir",120,quien,objeto);}
    	return 1;
    }
  }	
  TO->remove_timed_property("robando");
  return 1;	
}



void huir(object atacante)
{
//tell_room(ENV(TP),"Yo me piro!!\n");	
do_command("perder all");
if (!pirandose) {
	call_out("pirarse",1);	
	call_out("pirarse",2);	
	call_out("pirarse",3);		
	call_out("esconderse",5,atacante);
	pirandose=1;}
}

void attack_by(object atacante)
{
//tell_room(ENV(TP),"Yo me piro!!\n");		
do_command("perder all");
if (!pirandose) {
	call_out("pirarse",1);	
	call_out("pirarse",2);	
	call_out("pirarse",3);		
	call_out("esconderse",5,atacante);
	pirandose=1;}
}

int contrario(string ultimasalida,string actual)
{
if (ultimasalida=="este" && actual=="oeste") 
	return 1;
if (ultimasalida=="oeste" && actual=="este") 
	return 1;
if (ultimasalida=="norte" && actual=="sur") 
	return 1;
if (ultimasalida=="sur" && actual=="norte") 
	return 1;
if (ultimasalida=="noroeste" && actual=="sudeste") 
	return 1;
if (ultimasalida=="noreste" && actual=="sudoeste") 
	return 1;
if (ultimasalida=="sudoeste" && actual=="noreste") 
	return 1;
if (ultimasalida=="sudeste" && actual=="noroeste") 
	return 1;
if (ultimasalida=="fuera" && actual=="dentro") 
	return 1;
if (ultimasalida=="dentro" && actual=="fuera") 
	return 1;
if (ultimasalida=="arriba" && actual=="abajo") 
	return 1;
if (ultimasalida=="abajo" && actual=="arriba") 
	return 1;
return 0;
}

void pirarse()
{
int d;
int i;
    object tmp;
    object *atks;
    mixed *dest_dir;

//tell_room(ENV(TP),"A ver pa onde tiro... Umm xD\n");	

if (TO->query_property("robando")) return 1;
    
dest_dir = (mixed *)environment(me)->query_dest_dir();
d=(random(sizeof(dest_dir))/2)*2+1;
if (sizeof(dest_dir)>2)
	{

	 while (contrario(ultimasalida,dest_dir[d-1]))
		{
		 
		d=(random(sizeof(dest_dir))/2)*2+1;
		}
	}


this_object()->move(dest_dir[d]);
ultimasalida=dest_dir[d-1];
 call_out("pirarse",moveafter);
}


void esconderse(object atacante)
{
//tell_room(ENV(TP),"Q me escondo!!\n");		
	
if( !me->query_hide_shadow())
  {
    atts_list = me->query_attacker_list();
    for (j=0;j<sizeof(atts_list);j++)
      if(atts_list[j])
      {
        me->stop_fight(atts_list[j]);
        atts_list[j]->stop_fight(me);
      }

    call_outed = me->query_call_outed();
    for (j=0;j<sizeof(call_outed);j++)
      if(call_outed[j])
      {
        me->stop_fight(call_outed[j]);
        call_outed[j]->stop_fight(me);
      }

    tell_room(environment(me),(string)me->query_cap_name()+
      " sale corriendo rapidamente y desaparece!\n",({me}));      
      sombra=clone_object(SOMBRA)->setup_shadow(this_object());
      add_property("oculto",1);      
}
pirandose=0;
call_out("pirarse",1);
}

void do_death(object ob)
{
ob = this_player();
str="Ma matao el mamon de "+ob->query_cap_name()+".";
"/global/do_chat"->do_channel("anduar",str,"%^BOLD%^Rutic%^RESET%^"); 

write_file("/d/anduar/logs/matar_rutic.txt",""+ob->query_cap_name()+" ha matado a Rutic: "+ctime(time())+".\n");
    return(::do_death());
}

int baul()
{

tiempobaul++;
//tell_object(find_player("ather"),"TiempoBaul: "+tiempobaul+".\n");
if (tiempobaul>360)
// CAMBIAR A 360
{
antesdebaul=ENV(TO);
tiempobaul=0;
// baulroom=load_object("/w/ather/baul.c");
// tell_object(find_player("ather"),"Voy pal baul.\n");
TO->add_property("no_destruible",0);
TO->move(baulroom);
TO->add_property("no_destruible",1);
// tell_object(find_player("ather"),"Toy en baul.\n");
// Rutic se clona... hay q arreglarlo

do_command("soltar");
do_command("pillar armadura");
do_command("pillar daga");
do_command("pillar daga");
do_command("equip");

call_out("volver",12);

}	

call_out("baul",5);
}


int pillarcosas()
{
antesdebaul=ENV(TO);
baulroom=load_object("/w/ather/baul.c");
TO->move(baulroom);
do_command("risa");
do_command("risa");
do_command("pillar all");
do_command("equip");
call_out("volver",12);	
}

int volver()
{	
	TO->add_property("no_destruible",0);
	TO->move(antesdebaul);
	TO->add_property("no_destruible",1);
}

int reir(object quien, object objeto)
{
tell_object(quien,"Rutic te dice: Jeje, gracias por tu "+objeto->query_short()+" me viene muy bien.\n");
do_command("sonreir "+quien->query_name()+"");
}

/*
void dest_me()
{
if (TO->query_hp()>0)
	{	
	call_out("mover",3,ENV(TO));
	TO->move("/w/ather/work.c");
	}

}
int mover(object destino)
{
TO->move(destino);
return 1;
}
*/