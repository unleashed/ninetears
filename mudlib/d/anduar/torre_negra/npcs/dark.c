inherit "obj/monster.c";

void init()
{
add_attack_spell(100,"cure serious wounds",({"std/spells/cleric/cure_sr.c","cast_spell", 3}) );
}
void setup()
 {
   set_name("khayhan");
   set_main_plural("khayhan");
   set_str(60);
   set_int(20);
   set_dex(20);
   set_con(30);
   set_cha(28);
   set_wis(40);
   set_long("Se trata de un enorme arbol totalmente seco, con unas ramas que "
   "alcanzan el altisimo techo de la biblioteca, en el retorcido tronco te "
   "parece observar una gigantesca cara que te mira con un odio sin par "
   "mientras, sus raices se hunden en las baldosas que componen el suelo del, "
   "edificio, parece dificil definir cual fue antes,, si el arbol o el "
   "edificio que lo rodea.\n");
   set_race("treemen");
   set_level(70);
   add_timed_property("fire",-15,9000000);
   adjust_tmp_damage_bon(45);
   set_gender(1);
   set_al(400);
   set_ac(-50);
}
void do_death(object ob)
{
    if(!random(2))
    new("/d/oficios/wizards/items/po_verde")->move(TO);
    write_file("/w/aokromes/khayhan.dead","khayhan matado por "+ob->query_name()+""+ctime(time())+"\n");
    return ::do_death(ob);
}
