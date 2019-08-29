inherit "/std/noncombat.c";
void setup()
{
   set_short("%^BOLD%^YELLOW%^Celda de Retencion Provisional%^RESET%^");
   set_long("Te encuentras en un cubo de cristal perdido en el espacio, nada "
   	"de lo que ves te es familiar, este es el sitio que Dagda utiliza como "
   	"zona de retencion temporal, seguramente has cometido un delito, o eres sospechoso "
   	"de haberlo cometido, y mientras se toma una decision, seras retenido aqui.\n\n"
   	"    En la pared ves un block de notas y un lapiz, y una ranura que pone 'MAIL' encima, "
   	"dirije una queja a tzarniss explicando tu situacion, y el se pondra en contacto "
   	"contigo cuando tenga tiempo..."
   	"si lo tiene....\n");
   
   set_light(50);
}
void init()
{
   ::init();
   add_action("mail", "leer");
   add_action("mail", "mail");
   add_action("trampa",({"gritar","chat","tell","tel","guild"}));
   add_action("trampados",({"finger","who"}));
}

int trampa()
{
  write("oyes resonar en tu mente... SIIIIIII!!!!! CHILLLAAAAA!!!! COMO ME GUSTAAAAAA!!!!!!!!.\n");
  return 1;
}

int trampados()
{
  write("oyes resonar en tu mente... que mas me da.. si no podre hablar con nadie?.\n");
  return 1;
}



int mail(string str)
{
object ob;
ob = clone_object("/obj/handlers/post");
ob->move(this_player());
ob->start_mail(str);
   return 1;
}
void send_message(string to)
{
   write("La ranura absorve el sobre con fuerza y este escapa de tus manos produciendote una quemadura.\n");
   TP->adjust_hp(0);
}


void event_enter(object pl, string mensaje, object donde)
{
	pl->set_no_heal();
}
 
void event_exit(object pl, string mensaje, object donde)
{
	pl->set_heal();
}
