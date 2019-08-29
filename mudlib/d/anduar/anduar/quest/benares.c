inherit "/obj/monster.c";

#define SOMBRA "/std/commands/shadows/hide.c"
object sombra;

void setup()
{
  set_name("Benares");
  set_short("\nBenares\n");
  set_long("Es un antiguo guerrero drow, conocido por sus grandes combates y sus"
           " desalmados actos contra enanos. Lucho hace mucho tiempo en antiguas"
           "incursiones drows y demostro con su astucia el valor de su raza.\n\n");
  add_alias("benares");
  add_alias("drow");
  set_main_plural("Benares");
  add_plural("drows");
  add_plural("Benares");
  set_hide(1);
  set_race_ob("/std/races/drow.c");
  set_guild_ob("/std/guilds/warriors/drowwarrior.c");
  set_gender(1);
  set_level(32);
  set_str(28);
  set_cha(25);
  set_int(18);
  set_wis(18);
  set_dex(20);
  set_con(17);
  set_max_hp(372);
  set_hp(372);
  set_max_gp(225);
  set_gp(225);
  load_a_chat(90,
             ({ 1,"'Te crees que puedes ganarme?.",
                1,"'Vas a ver lo que es sufrir.",
                1,":recuerda viejas batallas.",
              }));
  add_clone("/baseobs/weapons/bastard_sword",2);
  add_clone("/baseobs/armours/chainmail",1);
  TO->init_equip();
  
  sombra=clone_object(SOMBRA)->setup_shadow(this_object());
  
 
}

void heart_beat()
{
  if(!TO->query_hide_shadow())
    if(!random(25))
      switch(random(3))
      {
        case 1: tell_room(ETO,TO->query_short()+" mueve con rapidez sus armas.\n"); break;
        case 2: tell_room(ETO,TO->query_short()+" dice: Ojala tuviera mi cuchillo!. Lo hecho tanto de menos....\n"); break;
        case 3: tell_room(ETO,TO->query_short()+" dice: Si me lo traes te contare algo que te puede interesar.\n"); break;
      }
  ::heart_beat();
}
   
void init()
{
 ::init();
  add_action("dar",({"dar","entregar"}));
  add_attack_spell(90, "slice", ({"std/commands/guerreros/drow/rebanar", "rebanar",0}));
  add_attack_spell(90, "surge", ({"std/commands/surge", "surge",3}));
  add_known_command("esconderse");
  "/std/commands/shadows/hide"->move(TO);
}


void dar(string str)
{
  object cuchillo;
  
  if(TO->query_hide_shadow()>0)
  {
    notify_fail("Perdon ?.\n");
    return 0;
  }
  if (str == "cuchillo a benares" )
  {
   cuchillo=find_match("cuchillo",this_player());
  
   if (!sizeof(cuchillo))
   {
    write("Benares te dice: Me intentas tomar el pelo??!!.\n");
    return 1;   
   }
   
   write("Gracias, pero este cuchillo no es el que necesito.\n");
   return 1;
  }
  
  if (str != "cuchillo curvo a benares" )
  {
    notify_fail("Que querias dar o a quien??\n");
    return 0;
  }
  
   cuchillo=find_match("cuchillo curvo",this_player());

   if (!sizeof(cuchillo))
   {
    write("Benares dice: Por que quieres darme algo que no tienes?? \n");
    return 1;
   }

    cuchillo->dest_me();

     if (TP->query_level() >= 15)
     {
        write("Benares dice: Gracias por traerme el cuchillo, a cambio te contare "
           "una historia ... \n");
        call_out("texto1",6,1);
        return 1;
     }

     if (TP->query_level() < 15)
     {
      write("Benares dice: Gracias por traerme el cuchillo, pero considero que no "
          "necesitas saber nada, dado que a tu nivel no lo podras usar. \n");
      return 1;
     }
 
  return 1;
} 

void texto1()
{
 write("Benares dice: Hace muchos anyos, en una de tantas incursiones... "
       "de camino hacia dendara, a la altura del Camino Real"
       " me tropece y cai en una cueva completamente oculta.\n");
        
 call_out("texto2",6,1);
 return 1;
}       

void texto2()
{
  write("Benares dice: Alli encontre a un viejo indio....\n");
  call_out("texto3",4,1);
  return 1; 
}
 
void texto3()
{
 write("Benares dice: Este viejo indio me ensenyo un viejo arte... que requiere"
       " precision y cuidado... bueno...ya te he dicho bastante...\n");
  call_out("texto4",4,1);
  return 1;
}
  
void texto4()
{      
  write("Benares se despide de ti y vuelve a sus pensamientos.\n");
  return 1;
}
