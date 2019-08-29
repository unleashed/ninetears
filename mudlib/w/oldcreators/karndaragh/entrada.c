inherit "/std/room.c";



void setup()
{
   set_short("Entrada a la %^BOLD%^Fortaleza%^RESET%^");

   set_long("Entrada a la %^BOLD%^Fortaleza%^RESET%^\n\n"
      "   Esta es la entrada a la fortaleza de Karn-Daragh, el Se�or de la Guerra."
      "Es una sala muy simple, en la que solo te destacan las escaleras que suben y las antorchas "
      "que iluminan la habitaci�n de fria piedra.\n\n");
   add_item("antorchas","Un total de cinco antorchas iluminan la habitaci�n, una de ellas te llama la atenci�n.\n");
   add_item("antorcha","Parece que est� suelta, como si se pudiera mover.\n");
   add_item("escaleras","Unas escaleras de piedra que llevan al piso superior.\n");
   add_exit("arriba","/w/karndaragh/templo.c","door");
   add_exit("fuera","/w/karndaragh/jardin.c","door");
        
}

void init()
{
   ::init();
   add_action("do_mover","mover");
}

int do_mover(string str)
{
   if(str == "antorcha")
   {
      write("Mueves la antorcha y una abertura aparece en la pared!\n");

      say(this_player()->query_cap_name()+" mueve una de las antorchas.\n");

      add_exit("abertura","/w/karndaragh/mazmorra.c","door");

      renew_exits();
      return(1);
   }
   return notify_fail("Mover que??\n");
   
}