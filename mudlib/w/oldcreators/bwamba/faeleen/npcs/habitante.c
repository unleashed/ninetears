 inherit "/obj/monster";
 
 void setup() {
       set_name("habitante");
       add_adjective("tough");
       set_race("human");
       set_al(30);
       set_short("habitante");
       set_main_plural("habitante");
       add_plural("habitante");
       set_level(10);
       set_wimpy(0);
       set_random_stats(14, 17);
       set_gender(1);
       set_str(17);
       set_dex(17);
       set_long(
          "Es un habitante del poblade de Grandhum, son muy tranquilos,"
    " su unico hobby son las telas, y los famosos campos con la planta,"
    "unica de estos campos, la Pretyus.\n");
       
       adjust_money(random(3),"gold");
       load_chat(30,
          ({
           1,"'Faeleen es muy tranquilo,te lo aconsejo para vivir.\n",
           1,"'No me gustan las guerras,me gustan las telas..\n",
         }));
       if(random(2))
    add_clone("/baseobs/weapons/daga.c",1);
       init_equip();
 } 