// septiembre del 99 Drakull version 2.21

#define SLICE   "/std/commands/slice.c"

inherit "/obj/monster";

static int ene=0;
object ob;

void event_enter(object ob, string mensaje, object donde)
{
this_object()->attack_ob(ob);
  if(((int)this_player()->query_living(""))==1)
  {
  do_command("say Mortal vas a conocer lo que es el verdadero terror, yo soy "
  "poder, la muerte se arrodilla ante mi la muerte me venera, ya que soy su "
  "mas fiel ayudante, su forma de supervivencia, su hermano de sangre, soy "
  "aquel al cual los mas poderosos no muertos temen, y los vivos procuran "
  "estar lejos de mi, ahora tu seras parte de mi.\n");
  ::event_enter(ob, mensaje, donde);
  }
}/*event_enter*/

void setup() {
  set_name("drakull el vampiro");
  add_alias("drakull");
  add_alias("vampiro");
  set_al(10000);
  set_short("Drakull el vampiro");
  set_race("human");
  set_language("common");
  set_level(70+random(5));
  set_max_hp(5000);
  set_max_gp(1000);
  set_max_sp(100000);
  set_sp(100000);
  set_random_stats(46, 48);
  set_ac(0);
  set_thac0(75);
  set_gender(1);
  add_alias("guardian");
  set_long("Ante ti observas, impotente una colosal criatura, lo menos 2 "
  "metros y cuarto de altura, unas garras, de un aspecto tan terrorifico que "
  "tienen aspecto de poder cortar el mejor acero, unos colmillos tan largos "
  "que podrian atravesarte la mano, unos ojos tan misteriosos que podrian "
  "desnudarte el alma.\n");
  adjust_money(50,"platinum");
   add_clone("/baseobs/armours/platemail",1);
add_clone("/baseobs/weapons/bastard_sword",2);
//  add_clone("/d/anduar/drakull/objetos/placa",1);
// add_clone("/d/anduar/drakull/objetos/great_twohanded_sword.c",2);
  init_equip();
  set_join_fight_mess("Observas como a drakull se le empiezan a ver las venas "
  "sus ojos se vuelven rojos, como crece hasta los dos metros y medio.\n");
} /* setup() */

void init()
{
  ::init();
  add_attack_spell(5, "lightning bolt", ({"/std/spells/wizard/lightning.c","cast_spell", 0}));
   add_attack_spell(50, "vampiric touch",({"/std/spells/wizard/vamp_touch.c","cast_spell", 0}));
}

void attack_by(object atacante)
{
   ene++;
   SLICE->slice(atacante->query_name(),TO);
::attack_by(atacante);
}

void do_death(object ob)
{
  object *snarf; 
        int i; 
 
        snarf=query_attacker_list(); 
 
        for(i=0;i<sizeof(snarf);i++) 
        { 
          write_file("/d/anduar/logs/drakull", snarf[i]->query_name()+ 
          " ha matado a drakull: "+ctime(time())+".\n"); 
        } 
  ::do_death(ob);
}
