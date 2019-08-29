#define CREATOR "thalos"

inherit "/std/room.c";


void setup()
{
   set_short("%^BOLD%^CYAN%^Salon de %^RED%^Thalos%^");
   
   set_long("\n%^BOLD%^CYAN%^Salon de %^RED%^THALOS%^RESET%^.\n\n"
   "Estas en el salon de Thalos, puedes observar que la decoracion es"
   " muy variopinta, con grandes montones de libros y papeles tirados"
   " desordenadamente, por el suelo, sillas y las diversas mesas que"
   " ocupan casi todo el espacio de la habitacion, en las paredes"
   " observas ricos cortinajes y tapices, en un rincon observas a un"
   " pequenyo goblin que avanza hacia ti""\n\n");
      
   set_light(60);

   add_item("mesa","Ves una mesa repleta de libros.\n");
   add_item("mesas","Ves varias mesas abarrotadas de libros.\n");
   add_item("sillas","Por mas que miras no encuentras ninguna silla vacia en la que sentarte.\n");
   add_item(({"cortina","cortinas"}),"Unas grandes y largas cortinas cuelgan de las paredes, ajadas y oscurecidas por el paso de los anyos\n");
   add_item(({"tapiz","tapices"}),"Mirando fijamente los tapices, te das cuenta que en realidad no son tapices, si no espejos en los cuales se pueden observar los acontecimientos que sucenden en el mundo\n");
   
   add_smell(({"salon","workroom","aire","habitacion","room"}),"Hueles a humedad y a libros enmoecidos.\n");

   add_sound(({"salon","workroom","aire","habitacion","room"}),"Escuchas los tenues pasos de Skurt a media que se pasea por la habitacion, intentado no provocar mas desorden del que hay.\n");
      
   add_clone("/obj/misc/button.c",1);
   
   add_exit("sur","/w/thalos/workroom.c","door");
   add_exit("este","/w/thalos/dormitorio.c","door");
   
   add_clone("w/thalos/skurt.c",1);

}

void init()
{
 ::init();
 add_action("apartar_tapiz","apartar");
}

int apartar_tapiz(string str)
{
  if(str=="tapiz")
  {
  write("Sueltas el tapiz de la pared y aparece una puerta oculta.\n");
  say(this_player()->query_cap_name()+" arranca el tapiz.\n");
  add_exit("puerta","/w/thalos/laboratorio.c","door");
  renew_exits();
  return(1);
  }
  notify_fail("Quitar que?.\n");
  return(0);

}