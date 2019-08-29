#include <standard.h>
#include <cmd.h>
inherit CMD_BASE;

void setup()
{
position = 1;
}

int cmd(string arg, object me) {
  int tim,upt;
  string str;

  if( !arg || arg == "" ) {
    write("Se requiere argumento.\n");
    return 1;
  }
  if(!"/secure/master"->query_lord( geteuid(me ) ) ){
     upt= uptime();

// Comentado por MatatunoS, evita esperar 3 horas de uptime para tirar shutdown

//     if((upt/(60*60)%24) < 3) 
//     {
//      	write("Aun no han transcurrido 3 horas. Quizas debas esperar un poco.\n");
//  		return 0;
//     }
  }
  str = (string)me->QCN+" a las "+ctime(time());
  log_file("GAME_LOG", "Reiniciado por ");
  log_file("GAME_LOG", str);
/*
  log_file("GAME_LOG", ctime(time()));
  */
  log_file("GAME_LOG", " t.programado \n");
  log_file("GAME_LOG", arg);
  log_file("GAME_LOG"," (Uso de memoria: "+memory_info()+")");
  log_file("GAME_LOG", "\n\n");
  write("Ok... reiniciando el juego... \n");
  sscanf(arg, "%d %s", tim, arg);


// Evitamos que sea un creador de nivel alto el que tira el rebut, de esta forma
// se puede tirar diciendo el tiempo que queremos esperar para que se lanze
//   if (tim < 10 )&& !MASTER->high_programmer(geteuid(me)))
//    tim = 10;
  if (str[0..2] == "now" )//&& MASTER->high_programmer(geteuid(me)))
    tim = 0;
   if (!tim)
    "/obj/shut"->end_it_all();
  else
    "/obj/shut"->shut(tim);
    return 1;
} /* shutdown_game() */
 

