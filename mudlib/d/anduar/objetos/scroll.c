#define PAUSE 10
inherit "/std/object";
string RAZA;

void query_value() { return 750000; }

void setup() 
{
  set_name("pergamino");
  add_alias("pergamino de teletransportacion");
  set_short("Pergamino de Teletransportacion");
  add_alias("pergamino");
  set_long("Se trata de un pergamino antiguo con runas de oro y mitril "
  "escritas en el. Un gran poder irradia en el.\n");
  set_weight(21);
  set_value(750000);
  set_main_plural("Pergaminos de Teletransportacion");
  add_plural("pergaminos");
  add_plural("pergaminos de teletransportacion");
  set_genero(0);
}

void init()
  {
  add_action("do_recite", "recitar");

  ::init();
}

int do_recite(string str)
{
        RAZA=this_player()->query_race();
        if(str=="pergamino de teletransportacion" || str ="pergamino")
        {
                call_out("delay",0);
                return(1);
        }
        else
        {
            write("Empiezas a recitar el cantico escrito en el pergamino.\n");
            return(1);
        }
}
        
void delay()
{
  this_player()->do_command("stop");
  say(environment(this_player()), this_player()->query_cap_name()+
    " empiaza a leer un pergamino.\n");
  write("\n\nPronuncias el cantico 'guldus axirm telem'.\n");
  this_player()->add_timed_property("nocast",100);
  this_player()->add_timed_property("noguild",100);
  call_out("delay_1",0);
  return;
}

int delay_1()
{
  say("De pronto un humo gris surge en la habitacion.\n");
  write("De pronto un humo gris surge en la habitacion.\n");
  call_out("delay_2",PAUSE);
  return(1);
}

int delay_2()
{
  say(environment(this_player()), this_player()->query_cap_name()+
  " grita el cantico 'guldus axirm telem' y desaparece.\n");
  write("Sientes como tu cuerpo comienza a desmaterializarse lentamente "
  "hasta desaparecer totalmente.\n");
  call_out("delay_3",PAUSE);
  return(1);
}


int delay_3()
{
  write("Sientes como tu cuerpo es teletransportado por medio de otra "
   "dimension a otro lugar.\nTe sientes terriblemente debilitado.\n");
   
  if (RAZA=="Elfo")
     TP->move("/d/orgoth/areas/arbre/rooms/c09");
call_out("dest_me",0);
  if (RAZA=="Drow")
     TP->move("/d/tzerneelledol/rooms/cavernas/p1");
call_out("dest_me",0);
  if (RAZA=="Hombre-Lagarto")
     TP->move("/d/zulk/rooms/bosque/b54.c");
call_out("dest_me",0);
  if (RAZA=="Medio-Elfo")
     TP->move("/d/orgoth/areas/arbre/rooms/c09");
call_out("dest_me",0);
  if (RAZA=="Orco")
     TP->move("/d/golthur/rooms/wasteland/estepa/o1717");
call_out("dest_me",0);
  if (RAZA=="Medio-Orco")
     TP->move("/d/golthur/rooms/wasteland/estepa/l1218");
call_out("dest_me",0);
  if (RAZA=="Duergar")
     TP->move("/d/bendorf/ciudad/s11");
call_out("dest_me",0);
  if (RAZA=="Enano")
     TP->move("/d/kd/kheleb-dum/rooms/nivel_c/banco");
call_out("dest_me",0);
  if (RAZA=="Halfling")
     TP->move("/d/anduar/laberinto/senda43");
call_out("dest_me",0);
  if (RAZA=="Goblin")
     TP->move("/d/golthur/rooms/wasteland/estepa/S0636");
call_out("dest_me",0);
  if (RAZA=="Gnomo")
     TP->move("/d/anduar/laberinto/senda63");
call_out("dest_me",0);
  if (RAZA=="Humano")
{
   int tipo;
    tipo=random(2);
    switch (tipo)
    {
     case 0: TP->move("/d/takome/r/camino/camino3");
     call_out("dest_me",0);
     break;
     case 1: TP->move("/d/dendara/rooms/nivel1/barrio/h3");
     call_out("dest_me",0);
     break;
     case 2: TP->move("/d/anduar/laberinto/senda22");
     call_out("dest_me",0);
     break;
    }
  call_out("dest_me",0);
  this_player()->set_gp(0);
  return(1);
}
}
void dodest()
{
  this_object()->dest_me();
  return;
}
