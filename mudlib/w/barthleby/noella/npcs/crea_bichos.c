//Barthleby 2002. Ultima updateada-> 2003
//pretenden ser bichos estandar pa bosques y tal, si alguien cree que estan mu dopados que avise y lo corrijo
inherit "/obj/monster";

void setup() {
      set_race("monster");
      set_long("Es solamente un animal.\n");
      switch(random(6))
      {
        case 0:
         set_name("serpiente");
         set_short("serpiente");
         add_alias("bicho");
         set_main_plural("serpientes");
         set_gender(0);
         set_level(5);
         break;
        case 1:
         set_name("buho");
         set_short("buho");
         add_alias("bicho");
         set_main_plural("buhos");
         set_gender(0);
         set_level(7);
         break;
        case 2:
         set_name("topo");
         set_short("topo");
         add_alias("bicho");
         set_main_plural("topos");
         set_gender(0);
         set_level(5);
         break;
        case 3:
         set_name("ara�a gigante");
         set_short("una ara�a gigante");
         add_alias("ara�a");
         add_alias("aranya");
         add_alias("bicho");
         set_main_plural("ara�as gigantes");
         set_gender(0);
         set_level(15);
         break;
        case 4:
         set_name("jabali");
         set_short("jabal�");
         add_alias("bicho");
         set_main_plural("jabal�s");
         set_gender(0);
         set_level(15);
         break;
        case 5:
         set_name("ciervo");
         set_short("ciervo");
         add_alias("bicho");
         set_main_plural("ciervos");
         set_gender(0);
         set_level(10);
         break;

        }
      set_max_hp(query_level() * 8);
      set_wimpy(0);
      set_long("Es solamente un animal.\n");
      set_random_stats(6, 18);

}
