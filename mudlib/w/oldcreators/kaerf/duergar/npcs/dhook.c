/*  File upgrade by Grimbrand 2-11-96                                   */

inherit "/obj/monster";

static int i = 0;
object cloak;
 
void setup() {
   set_name("hook horror");
   add_alias("hook");
   add_alias("horror");
   set_short("Hook Horror decrepito");
   set_long("   Frente a ti,jadeando, ves un Hook horror. Esta criatura "
            "inquietante puede cargar encima el peso tres duergar o mas, "
            "aunque este ejemplar apenas se puede mantener en pie.  Su "
            "exoesqueleto de duras placas, que forman una explendida "
            "armadura, parece ahora deteriorado e incluso ha perdido "
            "alguna placa. Es realmente un ejemplo muy pobre de una "
            "raza en extremo peligrosa."
	    "\n\n");
   set_main_plural("hook horrors");
   set_gender(1);
   adjust_gp(4);
   set_random_stats(6,18);
   set_str(12);
   set_level(8);
   set_max_hp(34);
   set_al(100+random(50));
   set_wimpy(0);        
   set_kill_xp(431);
   adjust_money(5,"oro");

} /* setup() */

#define AN attacker->query_cap_name()
#define DN defender->query_cap_name()
#define MAXDAMAGE 5
mapping valid_attack () {

  int GP,two,three,four,five;
  two=random(2);
  three=random(3);
  four=random(4);
  five=random(5);

   if(random(15))
     {
      GP = attacker->query_gp();
   
      if(GP>9)
        {
         if (i<2)
            say(AN+" lanza sus garras.\n");
            i = i +1;
         if(i>2)
           {
            i = 0;
            say(AN+" golpea a "+DN+" con sus garras!!!\n");
            defender->adjust_hp(-(random(MAXDAMAGE)), this_object());
           }
        }
     }
   return ([
   "punch"   :({ AN+" "+({"aranya a", "desgarra a",})[two]+" "+DN+" en "+
              ({"el brazo","el torso","la pierna","el culo",})[four]+".\n",
              "Golpeas a "+DN+".\n", AN+" "+({"te aranya", "te desgarra",})[two]+
              " en "+({"el brazo","el torso","la pierna","el culo",})[four]+".\n"}),
   
   "kick"      :({ AN+" "+({"aranya a", "desgarra a",})[two]+" "+DN+" en "+
              ({"el brazo","el torso","la pierna","el culo",})[four]+".\n",
              "Golpeas a "+DN+".\n", AN+" "+({"te aranya", "te desgarra",})[two]+
              " en "+({"el brazo","el torso","la pierna","el culo",})[four]+".\n"}),

   "knee"       :({ AN+" "+({"aranya a", "desgarra a",})[two]+" "+DN+" en "+
              ({"el brazo","el torso","la pierna","el culo",})[four]+".\n",
              "Golpeas a "+DN+".\n", AN+" "+({"te aranya", "te desgarra",})[two]+
              " en "+({"el brazo","el torso","la pierna","el culo",})[four]+".\n"}),
]);
}

