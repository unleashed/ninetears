
// wimpy cmd from player.c, now external. Morgoth 7/Mar/95
// Changed: if you type "wimpy" without a number, or with an out of range
//          number, it will now show you the actual setting, without changing
//          it, after warning you. The old version would not show it in either
//          case, and would set it to 0 in the latter case.

#include <standard.h>
#include <cmd.h>
//#include <player.h>

inherit CMD_BASE;

int wimpy;

void setup()
{
        position = 0;
}

string query_usage()
{
        return "wimpy <num>";
}

string query_short_help()
{
        return "Saldr�s huyendo cuando tus HPs est�n por debajo del <num>%, y perder�s "+
               " el <num>% de la xp ganada.";
}

string wimpy_str(object me)
{
        return "Actualmente esta fijado en el "+me->query_wimpy()+"%.\n";
}

int cmd (string str, object me)
{
        if (!str)
        {
                notify_fail("Uso: "+query_usage()+". "+wimpy_str(me)+"\n");
                return 0;
        }
        else
        {
                if (sscanf(str, "%d", wimpy) != 1)
                {
                        notify_fail("Debes especificar un numero .\n");
                        return 0;
                }
                if (wimpy < 0 || wimpy > 100)
                {
                        notify_fail("El wimpy debe estar entre 0 y 100. "+
                                        wimpy_str(me)+"\n");
                        return 0;
                }
        }
        if (wimpy)
                tell_object (me, "Estas en modo cobarde, huir�s "+
                        "al "+wimpy+"% de tu maximo de HPs.\n");
        else
                tell_object (me, "Estas en modo valiente.\n");
        me->set_wimpy(wimpy);
        return 1;
}

