 inherit "/obj/monster";
object g1;
 void setup() {
       set_name("Guardian del camino");
       set_race("human");
       set_al(60);
       set_short("guardian");
       add_alias("guardian");
       set_main_plural("guardianes");
       add_plural("guardianes");
       set_level(35);
       set_wimpy(0);
       set_random_stats(20,22);
       set_str(22);
       set_long(
          "Es un guardian del camino, te mira con ansia y ganas de matarte."
    " Es  un hombre robusto de fantasticas cualidades atleticas."
    " Parece que no tiene muchas ganas de dejarte pasar.\n");
       
       adjust_money(random(10),"gold");
       load_chat(30,
          ({
           1,"'Me vas a pegar?\n",
           2,"'Si quieres pasar tendras que matarme.\n",
         }));
       if(random(2))
    
    add_clone("/baseobs/weapons/hacha_oneex.c",2);
    add_clone("/baseobs/shields/corporal.c",1);
       init_equip();
 
 } 

