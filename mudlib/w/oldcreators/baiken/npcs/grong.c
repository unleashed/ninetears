// Paris Feb'99

inherit "/obj/monster";
#include "../path.h"


void setup()
{
   set_name("grong");
   set_short("Grong CimitarraSangrienta");
   set_main_plural("hermanos de grong?");
   
   add_plural("guerreros");
   add_plural("orcos");
   add_plural("hermanos");
   
   set_guild_ob("/std/guilds/warriors/barbarian");
   set_gender(1);

   set_str(28);
   set_cha(21);
   set_con(18);
   set_dex(17);
   set_int(10);
   set_wis(9);
   
   
   set_long("El sobrenombre del SupraHeavy se lo gano a pulso cuando decidio ponerse "
            "su primera cadena en el cuello. Ahora tiene tantaas que apenas si se "
            "le ven los pelos del pecho. En algunos casos las usa como armas "
            "arrojadizas, y es que son muy pesadas (aunque todas de metal barato). "
            "En cualquier caso es un experto guerrero y pocos son capaces de superar "
            "su habilidad con la cimitarra, tan solo Glonurg tendria alguna posibilidad "
            "en caso de un duelo a primera sangre.\n");
             
   add_clone("/baseobs/weapons/scimitar.c",2);
   add_clone(ITEMS"cadenas",1);

   this_object()->init_equip();
   set_level(41);
   set_max_hp(700);
    set_alignment(300);
   
   add_property("magical",20);
   add_property("air",20);
   add_property("fire",20);
   add_property("acid",20);
   add_property("cold",20);
   add_property("electrical",20);
}

void init()
{
   ::init();
   add_attack_spell(30, "berserk", ({"/std/commands/strike","strike", 0}));
   add_attack_spell(10, "jugadasucia", ({"/std/commands/dirtykick","dirtykick",0}));
}
