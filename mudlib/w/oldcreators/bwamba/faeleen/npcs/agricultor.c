inherit "/obj/monster";
 
 void setup() 
{
       set_name("agricultor");
       set_race("human");
       set_short("agricultor de  Grandhum");
       set_main_plural("agricultores");
       add_plural("agricultores");
       set_level(4+random(5));
       set_wimpy(0);
       set_random_stats(9, 15);
       set_str(15);
       set_gender(1);
      set_long(
          "Ves a un agricultor de  Grandhum, es bastante alto y es de una,"
    "edad intermedia, esta bastante sucio por el trabajo..\n");
       
       adjust_money(random(10),"silver");
       load_chat(30,
          ({
           1,"'Hay que trabajar las tierras si quieres ser algo en este pueblo.\n",
           1,"'Una dura jornada, me voy a descansar.\n",
         }));
       if(random(2))
    
    add_clone(/w/bwamba/faeleen/objetos/daga_afilada.c",1);
       init_equip();
 
 } 