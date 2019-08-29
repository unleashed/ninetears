
inherit "/std/room.c";

int i;
object not;
void setup()
{
   set_short("Mazmorras de la Fortaleza");
   set_long("Mazmorras de la Fortaleza\n\n"
	    "	Te encuentras en una lugubre sala, construida en los s�tanos de la fortaleza. En una "
            "de las paredes puedes ver una puerta de madera con una ventanita, al mas puro estilo de "
            "las mazmorras de la edad media.\n\n");   
   add_item ("puerta","Una puerta de madera que, extra�amente, no parece cerrada con llave, tal vez podria abrirse.\n");
   add_exit("fuera","/w/karndaragh/entrada.c","door");
   

}

void init()
{
  ::init();
  add_action("abrir","abrir");
  }


int abrir(string str)
{
 if (str == "puerta")
    {
     switch (i)
     {
      case(1000):
        write("Intentas abrir la puerta pero esta ya estaba abierta.\n"
              "Dices: ains que tontitor soy :_(\n");
        say(TP->query_name()+" intenta, con una gran habilidad, abrir una puerta que ya estaba abierta.\n"
             +TP->query_name()+" dice: ains que tontitor soy :_(\n");
        break;      
      default:
        write("Abres la puerta y al instante una enorme bestia sale de ella .\n");
        say(TP->query_cap_name()+" abre la puerta y al instante sale una enorme bestia del interior.\n");
        add_clone("/w/karndaragh/bestia.c",1);
        i=1000;
        return 1;
        
        
    }
   }
 return notify_fail("Tal vez quieras abrir la puerta.\n");
}



