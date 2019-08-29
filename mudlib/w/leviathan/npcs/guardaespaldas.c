inherit "/obj/monster";

object myp;
void init()
{
 ::init();
add_attack_spell(70,"slice",({"std/commands/slice.c","slice",1}));
add_attack_spell(50,"proy_magico_mayor", ({"/d/gremios/hechizos/escuelas/invocacion/","proy_magico_mayor"
,1}));
}

void setup()
 {
 set_name("%^BOLD%^BLACK%^Glerich%^RESET%^");
 add_alias("glerich");
 set_cha(18);
 set_race("human");
 set_short("%^BOLD%^BLACK%^Glerich%^RESET%^");
 add_language("grunt");
 set_language("grunt");
 set_long("Es un fornido humano que se gana la vida trabajando practicamente gratis para "
	"su amo y senyor %^BOLD%^RED%^Leviathan%^RESET%^.\n");
 set_align(0);
 set_gender(0);
 add_property("magical",75);
 add_property("nodisarm",1);
 //messin("$N llega nerviosamente desde el $F");

 load_chat(50,
            ({
              1,":camina arrogantemente junto a su amo.\n",
              1,":te mira con cara de desconfianza.\n",
              1,":mira hacia todas partes con cara de preocupado.\n",
             }));
 set_max_hp(100000000);
 set_hp(100000000);
 set_level(51);
 add_clone("/baseobs/armours/platemail.c",1);
 add_clone("/baseobs/armours/great_helm.c",1);
 add_clone("/baseobs/weapons/bastard_sword.c",1);
 add_clone("/baseobs/weapons/bastard_sword.c",1);

  this_object()->init_equip();
  add_known_command("slice");
  add_known_command("surge");

 }

int adjust_hp(int i, object hp_remover,mixed type) 
{
 if(hp_remover && hp_remover != TO) 
 	{
	tell_object(hp_remover,"No mataras a mi senyor mientras yo viva!\n");
	}
return ::adjust_hp(i,hp_remover,type);
}

int attack_by()
 {
	return 0;
 }
void  do_death()
 {
	TO->set_hp(TO->query_max_hp()); 
 }
 int attack_ob()
 {
	return 0;
 }


void event_person_say(object ob, string start, string mess, string lang, int speaker)
{
   if (this_player()->query_name() != "leviathan" && this_player()->query_name() != "hunther") 
	{
	     write ("Solo hare caso a mi amo y senyor!!!\n");
	     return 0;
	}
   if (lang != "grunt")
     return 0;
   switch (mess)
   {
   case("protegeme"):
            do_command("proteger " + this_player()->query_name());
            break;
   case("sigueme"):
            do_command("seguir " + this_player()->query_name());                        break;
   case("sigueme y protegeme"):
            do_command("proteger " + this_player()->query_name());
            do_command("seguir " + this_player()->query_name());
            break;
   default:return 0;
   }
}

