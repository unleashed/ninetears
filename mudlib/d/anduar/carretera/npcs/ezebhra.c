// Sinister. 10-05-00

inherit "/obj/monster";
#define ACIDA "/std/spells/wizard/acid_cloud.c"
#define PROYEC "/std/spells/wizard/mmmissile.c"
#define CONO "/std/spells/wizard/conecold.c"
#define STUNN "/std/spells/esferas/combate/palabra_sagrada.c"
#define ESP "/std/spells/wizard/mirror.c"

static int ene=0;

object ob;

void setup()
{
       set_name("ezebhra");
        add_alias("ezebhra");
        add_alias("nigromante");
        add_alias("Ezebhra");
        set_main_plural("ezebhras");
         
        set_short("Ezebhra, La Nigromante");
        set_long("Ante ti esta una de las Ultimas Nigromantes de esta "
        "tierra, mira con sus ojos vidriosos, recelosa de que alguien "
        "le robe sus hechizos, guardiana de lo innombrable, hechizera "
        "entre hechizeras.\n"
        "Ezebhra fue una de las mas grandes Nigromantes que poblo la "
        "faz de la tierra, junto con su hermano Arhamon, sembraron el "
        "caos y la destruccion en cada pueblo, ciudad, isla que pisaban "
        "y que sometian a sus mas oskuros designios. Te das cuenta que "
        "algo oculta en su morada, y que para descubrirlo tendras que "
        "matarla, cosa que supones, no sera muy facil.\n");

        set_ac(-100);
        set_thac0(-45);
        set_level(55);
        set_join_fight_mess("Ezebhra chilla: "+
        "Nunca debiste atacarme, ahora descubriras "+
        "mil maneras de morir!!!!.\n");

        set_str(90);
set_guild_ob("/std/guilds/wizards/general_mage");
        set_con(90);
        set_dex(100);
        set_int(100);
        set_wis(80);
        set_cha(70);
        set_max_hp(3500);
        set_hp(3500);
        set_max_gp(3000);
        set_gp(3000);
        set_aggressive(0);
        set_alignment(1500);

        add_clone("/d/anduar/objetos/amul_horror.c",1);
add_clone("/d/anduar/objetos/baston_destruccion.c",1);
        add_clone("/baseobs/armours/boots.c",1);
        add_clone("/baseobs/armours/cape.c",1);
        init_equip();
add_clone("/d/anduar/objetos/tunica_dolor.c",1);
        
        add_property("magic", 50);
        add_property("poison", 50);
add_property("no_pobredumbre",100);
        add_property("acid", 50);
        add_property("fire", 50);
        add_property("cold", 50);
        add_property("stone", 50);
        add_property("no_fear", 100);
        add_property("nodisarm", 100);

        add_loved("player", ({"sinister","aokromes","oskuro"}));
        
        load_chat(10,({
                1, ":pregunta: Quien os ha llevado hasta mi morada?",
                1, ":mira a su alrededor recelosa.",
                1, ":dice: nunca descubriras mis secretos!.",
                }));    

        load_a_chat(10,({ 
        1, ":exclama: Serviras de desayuno a los siervos de Oskuro!!!",
        1, ":dice: Ningun mortal se ha atrevido jamas a atacarme.",
        1, ":dice: Si quieres descubrir lo que hay aqui, matame!.",
        }));

        }
        void init()
        {
        ::init();
        add_attack_spell(60, "tormenta acida", ({ACIDA,"cast_spell", 2}));
add_attack_spell(60, "proyectil magico mayor", ({PROYEC,"cast_spell",2}));
add_attack_spell(60, "cono de frio", ({CONO,"cast_spell", 2}));
add_attack_spell(80, "palabra sagrada", ({STUNN, "cast_spell", 2}));
        add_attack_spell(50, "espejos", ({ESP, "cast_spell", 3}));
}

void do_death(object ob)
{
object *snarf; 
int i; 
snarf=query_attacker_list(); 
for(i=0;i<sizeof(snarf);i++) 
{ 
write_file("/d/anduar/logs/ezebhra", snarf[i]->query_name()+ 
" ha matado a ezebhra: "+ctime(time())+".\n"); 
} 
   ::do_death(ob);
}

void event_enter(object ob, string mess)
{
  string raza  = ob->query_race();
  string guild = ob->query_guild_name();
  
  if (((raza == "Elfo" || raza == "Enano" || raza == "Halfling" || 
  guild  == "paladin" || guild == "Clerigo de Lummen" || guild == "Asesino" )))
   {
     do_command("say Por la gloria de Oskuro!! moriras!!!!!!");
     this_object()->attack_ob(ob);       
   }
   else
   {
  if (((raza == "Drow" || raza == "Duergar" || raza == "Goblin" || 
  guild == "Cleriga de Lloth")))
  {
  do_command("say Saludo a su malignidad!!!!!!");
  }
  else
  {
    if (((guild == "Antipaladin")))
    {
    do_command("say Encantada de tener a un fiel sirviente de Oskuro en mi humilde morada.");
    }
  }
   }
  ::event_enter(ob, mess);
}
