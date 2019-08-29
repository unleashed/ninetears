inherit "/std/room.c";
 void setup()
 {
 set_short("%^BOLD%^%^RED%^Sagrado %^CYAN%^Altar%^RESET%^");
 set_long("%^BOLD%^RED%^Sagrado %^CYAN%^Altar %^RESET%^\n\n Estas "
          " en un altar situado en el camino a una playa. Este altar "
          " esta hecho para los numerosos viajeros q pasan por este"
          " camino,en el altar hay unas runas.\n\n");
 set_light(50);
 set_zone("camino_playa");
 add_item("runas","Es raro ves las runas, aprecias algo especial en 
  ellas, te dan muchas ganas de tocarlas\n");
 add_clone("/w/bwamba/npcs/playero.c",2);
 add_exit("fuera","/w/bwamba/camino_playa/rooms/CP12.c","door");
 }
 void init()
 {
 ::init();
add_action("acariciar_runas","acariciar");
}
int acariciar_runas(string wis)
{
  if(wis=="runas")
  {
  write("sientes el poder de las runas que recuperan parte de tu energia\n");
  TP->adjust_hp(50);
say(this_player()->query_cap_name()+" acaricia las runas.\n");
  return(1);
  }
  notify_fail("acariciar que?.\n");
  return(0);
  }
  
                  