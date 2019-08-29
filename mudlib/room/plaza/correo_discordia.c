//Kryger 2003//
inherit "/std/room";
#include "mail.h";
#include "../path.h";
 
object sign;
 
void init()
{
   ::init();
   add_action("do_mail", "mail");
   add_action("do_mail", "leer");
}
 
void setup()
{
   set_short("%^BOLD%^BLUE%^Oficina de Correos%^RESET%^");
   set_long(query_short()+"\n\n Estamos en una oficina de correos de las muchas que hay por todo el reino "
   " esta llena de papeles y palomas, el servicio postal es una de las cosas m�s importantes.\n\n");

   sign=add_sign("Los comandos son:\n"
             "   mail <Nombre Pj>    se usa para mandar un mensaje\n"
             "   leer                se usa para leer los mensajes\n\n");
 
   set_light(80);
    
   add_exit("norte",ROOMRING"campo_discordia_16.c","door");  
   
}
 
int do_mail(string TO_WHOM)
{
   object ob;
   ob=clone_object("/obj/handlers/post");
   ob->move(this_player());
   ob->start_mail(TO_WHOM);
   return 1;
}
 
void send_message(string TO_WHOM)
{
   write("Has acabado.\n\n");
   
   say(this_player()->query_cap_name()+" terminas de mandar mails.\n\n");
   if(find_living(TO_WHOM))
      call_out("after_call", 5, TO_WHOM);
}
 
void after_call(string TO_WHOM)
{
   object TARGET;
   TARGET=find_living(TO_WHOM);
   if(!TARGET)
      return;
}
