/* Display various information about the mud's status.

   File taken from the VikingMUD lib.  Written by Kniggit 930525

   Hamlet tweaked me some, May 1997.
*/
 
/* Add named_livings() when we go to v22 */

#include <standard.h>
#include <cmd.h>

#ifndef __COMPILER__
#define __COMPILER__ "probably gcc"
#endif

inherit CMD_BASE;

void setup()
{
  position = 0;
  dodest = 1;
}

#define PAD(x,y,z)      sprintf("%-*s: %s\n",z,x,"" + y)

int cmd(string str, object me)
{
   mapping r;
   float cpu;
   string mach, vers, name, up, cc, loadav, tmp;
   int obs, memory, callouts, width;
   
   r = rusage();
   obs = sizeof( objects() );
   mach = __ARCH__;
#ifndef MSDOS
   cc = __COMPILER__;
#else
   cc = "GCC probably, but who knows.";
#endif
   name = capitalize(mud_name()) + "   (" + query_host_name() + " " + 
          __PORT__ + ")";
   vers = __VERSION__;
   cpu = ((r["utime"] + r["stime"]) / uptime() / 10.0);
   width = 20;
   memory = memory_info();
   up = pretty_time(uptime(), 4);
   loadav = query_load_average();
   callouts = sizeof(call_out_info());
   
   tmp = "%^BOLD%^-- %^GREEN%^Informacion para %^YELLOW%^" + mud_name() + " %^RESET%^BOLD%^----------\n";
   tmp += PAD("Nombre..............", name, width) +
         PAD("Driver..............", vers, width) +
         PAD("Arquitectura........", mach, width) +
         PAD("Compilador..........", cc, width) +
         PAD("Tiempo activo.......", up, width) +
         PAD("Uso de CPU..........", sprintf("%4.2f%%", cpu), width) +
         PAD("Carga media.........", loadav, width) +
         PAD("No. de usuarios.....", sizeof(users()), width) +
         PAD("Objetos.............", obs + " cargados.", width) +
         PAD("Llamadas............", callouts + " pendientes.", width) +
         PAD("Uso de memoria......", memory, width);
   tmp+="%^BOLD%^-------------------------------------%^RESET%^\n";
   tell_object(me,sprintf("\n%-*#s\n", 80, tmp));
   return 1;
}

/*short_help() { 
  return "Show some information about the mud's system usage.\n"; 
}
*
* */
