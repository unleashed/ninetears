inherit "/obj/monster.c";
object jugador;

void setup()
{
  set_name("Viejo indio");
  set_short("\nViejo indio\n");
  set_long("Un antiguo indio, venido en un barco de otro continente. Posee "
           "los conocimientos de su tribu y posee una gran inteligencia y "
           " destreza .\n\n");
  add_alias("indio");
  add_alias("humano");
  set_main_plural("Viejos indios");
  add_plural("viejos");
  add_plural("indios");
  set_hide(1);
  set_race_ob("/std/races/human.c");
  set_gender(1);
  set_level(32);
  set_str(28);
  set_cha(25);
  set_int(18);
  set_wis(18);
  set_dex(20);
  set_con(17);
  set_max_hp(200);
  set_hp(200);
  set_max_gp(225);
  set_gp(225);
  load_chat(70,
           ({  1,":se pone pinturas de guerra.",
               1,"'Hola , viejo guerrero, que te trae por aqui?....",
               1,"'Que hambre tengo!...me comeria un buey entero!."
             }));
  load_a_chat(90,
             ({ 1,"'Te crees que puedes ganarme?.",
                1,"'Vas a ver lo que es sufrir.",
                1,":te reta a una lucha.",
              }));
  add_clone("/baseobs/weapons/two_handed_staff",2);
  add_clone("/baseobs/armours/leather",1);
  TO->init_equip();
}

void init()
{
 ::init();
  add_action("dar",({"dar","entregar"}));
}


void dar(string str)
{
  object carne;
   
//   tell_room(ETO,str+".\n");
   
   if(str !="asado a indio") return 0;
   carne=find_match("buey asado",this_player());

   if (!sizeof(carne))
   {
    write("Indio te dice: no...esto no lo queria yo. \n");
    return 1;
   }


     if (TP->query_level() >= 15)
     {
        write("Indio te dice: Gracias por la carne!! A cambio te ensenyare una cosa \n");
      carne->dest_me();
        call_out("texto1",6,1);
        return 1;
     }
    else
    {
    tell_object(TP,"Indio te dice: Te lo agradezco mucho, de veras, pero aun estas verde para poder aprender aquello que puedo ensenyarte.\n");
    return 1;
    }
}
void texto1()
{
 write("Indio dice: cuando estaba en mi tribu, aprendi un viejo arte que me "
       "ensenyaron los guerreros mas despiadados de mi tribu ...  \n");
 call_out("texto2",3,1);
 return 1;
}       

void texto2()
{
  write("Indio dice: Aprendi a arrancarle la cabellera a los cadaveres y asi tener "
        "un recuerdo de mis victimas...pero para esto se necesitaba un "
        "cuchillo Afilado por que si no destrozarias sus cabelleras.\n");
  call_out("texto3",5,1);
  return 1; 
}
 
void texto3()
{
  write("Indio dice: A cambio del delicioso manjar que me has traido te "
       "ensenyo este arte y te doy el cuchillo para que puedas realizar lo"
       " que yo hacia en mis anyos de juventud. \n");
  call_out("texto4",2,1);
  return 1;
}
  
void texto4()
{      
  write("El indio pone sus manos en tu frente y notas como se incrementan tus"
        " poderes .");
  call_out("texto5",3,1);
}
  
void texto5()
{
  object cuchillo;
  
  cuchillo=new("/d/anduar/anduar/quest/cuchillo");
  cuchillo->move(TP);
 
  write("El indio te da un cuchillo y dice: ya estas preparado... y recuerda"
        " que sin el arma adecuada no podras realizar este arte...Buen viaje.\n");      

//  tell_room(ETO,"JUG: "+TP->query_cap_name()+".\n");
  TP->add_known_command("descabellar");
  TP->look_me();
  return 1;
}
