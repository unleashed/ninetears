 inherit "/obj/monster";
 
 void setup() 
{
       set_name("agricultora");
       add_adjective("tough");
       set_race("human");
       set_al(30);
       set_short("agricultora");
       set_main_plural("agricultoras");
       add_plural("agricultoras");
       set_level(7);
       set_wimpy(0);
       set_random_stats(9, 15);
       set_str(15);
       set_gender(2);
set_long(
          "Es un agricultor de las zonas de Faeleen, tiene las caracteristicas,"
    " de todo el que vive por estas zonas. Es bastante alto para ser un humano,"
    "pero solo es ta hecho para trabajar en el campo.\n");
       
       adjust_money(random(10),"silver");
       load_chat(30,
          ({
           1,"'Hay que trabajar las tierras si quieres ser algo en este pueblo.\n",
           1,"'Una dura jornada, me voy a descansar.\n",
         }));
       if(random(2))
    
    add_clone("/w/bwamba/faeleen/objetos/rastrillo.c",1);
       init_equip();
 
 } 