// Nuevo score
// Vilat 04.09.2002
    
#include <standard.h>
#include <cmd.h>
    
inherit CMD_BASE;
    
void setup() {
     position = 0;
     }
   
string query_usage() {
     return "score [verbose|brief]";
     }
   
   string query_short_help() {
     return "Muestra las estadisticas de vida, mana y energia del player, asi como la experiencia.";
     }
   
 
   int cmd (string str, object me) {
           int age, a, ajuste, xp;
     string *st;
     string buf;
   
     if (str) st = explode(str, " ");
     else st = ({ });
     
   
           if (me->query_dead()) return notify_fail("Eres un espiritu, no necesitas saber eso.\n");
   
     if ((me->query_verbose() && (member_array("brief", st) == -1)) || (member_array("verbose", st) != -1)) {
             tell_object(me,"Estado:\n");
             buf="";
             ajuste=me->query_hp()*20/me->query_max_hp();
             for (a=0;a<ajuste;a++) buf+="=";
             for (a=ajuste;a<20;a++) buf+=" ";
             ajuste*=5;
             tell_object(me,"Puntos de Vida        : ["+({"%^RED%^BOLD%^","%^ORANGE%^","%^YELLOW%^","%^GREEN%^BOLD%^","%^BOLD%^CYAN%^"})[ajuste/25]+buf+"%^RESET%^] "+sprintf("%3d",ajuste)+"% ("+me->query_hp()+"/"+me->query_max_hp()+")\n");
             buf="";
             ajuste=me->query_gp()*20/me->query_max_gp();
             for (a=0;a<ajuste;a++) buf+="=";
             for (a=ajuste;a<20;a++) buf+=" ";
             ajuste*=5;
   tell_object(me,"Puntos de Man�        : ["+({"%^RED%^BOLD%^","%^ORANGE%^","%^YELLOW%^","%^GREEN%^BOLD%^","%^BOLD%^CYAN%^"})[ajuste/25]+buf+"%^RESET%^] "+sprintf("%3d",ajuste)+"% ("+me->query_gp()+"/"+me->query_max_gp()+")\n");
             buf="";
             ajuste=me->query_ep()*20/me->query_max_ep();
             for (a=0;a<ajuste;a++) buf+="=";
             for (a=ajuste;a<20;a++) buf+=" ";
             ajuste*=5;
   tell_object(me,"Puntos de Energ�a     : ["+({"%^RED%^BOLD%^","%^ORANGE%^","%^YELLOW%^","%^GREEN%^BOLD%^","%^BOLD%^CYAN%^"})[ajuste/25]+buf+"%^RESET%^] "+sprintf("%3d",ajuste)+"% ("+me->query_ep()+"/"+me->query_max_ep()+")\n");
             buf="";
             ajuste=me->query_social_points()*20/me->query_max_social_points();
             for (a=0;a<ajuste;a++) buf+="=";
             for (a=ajuste;a<20;a++) buf+=" ";
             ajuste*=5;
   tell_object(me,"Puntos Sociales       : ["+({"%^RED%^BOLD%^","%^ORANGE%^","%^YELLOW%^","%^GREEN%^BOLD%^","%^BOLD%^CYAN%^"})[ajuste/25]+buf+"%^RESET%^] "+sprintf("%3d",ajuste)+"% ("+me->query_social_points()+"/"+me->query_max_social_points()+")\n");
             buf="";
             

             if (!me->query_guild_ob()) xp=2000;
             else xp=me->query_guild_ob()->query_xp_cost();
             xp=me->ajustar_xp_necesaria(xp,me->query_level());
             ajuste=me->query_xp()*20/xp;
             if (ajuste>20) ajuste=20;
             for (a=0;a<ajuste;a++) buf+="=";
             for (a=ajuste;a<20;a++) buf+=" ";
             ajuste*=5;
   tell_object(me,"Puntos de Experiencia : ["+({"%^RED%^BOLD%^","%^ORANGE%^","%^YELLOW%^","%^GREEN%^BOLD%^","%^BOLD%^CYAN%^"})[ajuste/25]+buf+"%^RESET%^] "+sprintf("%3d",ajuste)+"% ("+me->query_xp()+"/"+(string)xp+")\n");
   
             
             
             tell_object("Tu experiencia total es "+me->query_total_xp()+".\n");
             tell_object(me,"Tienes ");
             age = me->query_time_on();
             age = -age;
             if (age > 86400)
                     printf("%d dias, ", age/86400);
             if (age > 3600)
                     printf("%d horas, ", (age/3600)%24);
             if (age > 60)
                     printf("%d minutos y ", (age/60)%60);
             printf("%d segundos.\n", age % 60);
             if (me->query_wimpy())
                     write("Cobardia en "+me->query_wimpy()+"%\n");
             else
                     write("Estas en modo valiente.\n");
             return 1;
     }
     else tell_object(me,"Pv: "+me->query_hp()+" ("+me->query_max_hp()+")  Pm: "+me->query_gp()+" ("+me->query_max_gp()+")  Pe: "+me->query_ep()+" ("+me->query_max_ep()+")  Px: "+me->query_xp()+"  Psoc: "+me->query_social_points()+"\n");
     return 1;
     }
   
