// Lummen Oct'98
 
inherit "/obj/monster";
#define HAND "/d/oficios/clerigos/gestur/rooms/iglesia/hand_boda.c"
int casando = 0;
 
void setup() 
{
      set_name("clerigo");
      set_short("Clerigo");
      add_alias("clerigo");
      set_main_plural("Clerigos");
      set_long("Este clerigo dedica su vida al marivilloso arte de unir a "
      "las personas en matrimonio. Este acto sagrado le llena de jubilo y "
      "orgullo. Todo su conocimiento esta dedicado al completo a esta accion. "
      "Solo pide a cambio una pequenya suma de dinero para conservar el estado "
      "de esta antigua y majestuosa iglesia.\n");
      load_chat(10,
         ({
               1, ":te saluda cordialmente.",
               1, "'El matrimonio es un acto puro y maravilloso.",
               1, "'Si quieres casarte con alguien solo tienes que venir aqui "
                  "con dicha persona.",
               1, ":se rasca la barba.",
               1, ":coloca las cosas en su sitio.",
          }));
      set_race("Humano");
      set_race_ob("/std/races/human");
      set_guild_ob("/std/guilds/priests/gestur");
      set_random_stats(6, 15);
      set_level(random(2)+7);
      set_gender(1);
      adjust_money(13+random(6), "gold");
}
 
int adjust_hp(int i, object ob)
{
  if(casando)
  {
   tell_object(ob , "No puedes hacerle danyo mientras se esta consumando un "
   "matrimonio.\n");
   return 0;
  }
  else ::adjust_hp(i,ob);
}
 
void init()
{
   add_action("casar", "casarse");
  add_action("do_joya","comprar");
   ::init();
}
 
void do_joya(string str)
{
  object anillo;

         if (str!="joya" && str!="joya estrella")
         {
           notify_fail("Que quieres comprar?\n");
           return 0;
         }
         if (TP->query_race()!="Elfo")
         {
           notify_fail("Esta joya esta reservada solo para los elfos.\n");
           return 0;
         }


         if (!HAND->query_casado(TP))
         {

           notify_fail("Solo estando casado puedes comprar la joya elfica.\n");
           return 0;
         }
         

         if( 50000 > TP->query_value() )
         {
           notify_fail("No tienes dinero para comprar la joya, cuesta 100 platinos.\n");
           return 0;
         }

         TP->pay_money(({"copper", 50000}));

         anillo=new("/d/oficios/clerigos/gestur/obj/joya");
         anillo->add_property("dequien",TP->query_cap_name());
         anillo->add_property("paraquien",capitalize(HAND->query_casado_con(TP)));
         anillo->move(TP);
         tell_object(TP,"Compras la Joya Estrella por 100 platinos.\n");
         return 1;
}
void casar(string str)
{
   string *lista;
   object *quien, anillo;
   int ret;
   
   if(!str) return 0;
   lista = explode(str," ");
   if(sizeof(lista)!=2)
   {
     notify_fail("Faltan parametros.\n");
     return 0;
   }
   if( member_array("con" ,lista) != -1)
   {
      quien = find_match(lista[1], environment(TO));
      if(!sizeof(quien))
      {
        notify_fail("No hay nadie con ese nombre aqui.\n");
        return 0;
      }
      if(quien[0]->query_name() != lista[1])
      {
         notify_fail(capitalize(lista[1])+" no esta aqui para casarse contigo.\n");
         return 0;
      }
      else
      {
         if(lista[1] == this_player()->query_name())
         {
             notify_fail("No crees que te pasas un poco casandote contigo mismo?.\n");
             return 0;
         }
         if(TP->query_property("bando") != quien[0]->query_property("bando"))
          {
           notify_fail("No estan permitidas las bodas entre bandos enemigos.\n");
           return 0;
          }
         if(TP->query_race_name() == "Humano" || TP->query_race_name() == "Elfo" || TP->query_race_name() == "Medio-Elfo")
          {
           switch(quien[0]->query_race_name())
           {
           case "Gnomo":notify_fail("No estan permitidas las bodas interraciales.\n"); return 0;break;
           case "Drow":notify_fail("No estan permitidas las bodas interraciales.\n"); return 0;break;
           case "Orco":notify_fail("No estan permitidas las bodas interraciales.\n"); return 0;break;
           case "Medio-Orco":notify_fail("No estan permitidas las bodas interraciales.\n"); return 0;break;
           case "Lizard":notify_fail("No estan permitidas las bodas interraciales.\n"); return 0;break;
           case "Duergar":notify_fail("No estan permitidas las bodas interraciales.\n"); return 0;break;
           case "Enano":notify_fail("No estan permitidas las bodas interraciales.\n"); return 0;break;
           case "Goblin":notify_fail("No estan permitidas las bodas interraciales.\n"); return 0;break;
           case "Halfing":notify_fail("No estan permitidas las bodas interraciales.\n"); return 0;break;
          }
         }
         else
         {
          if(TP->query_race_name() != quien[0]->query_race_name())
          {
           notify_fail("No estan permitidas las bodas interraciales.\n");
           return 0;
          }
         }
         if(TP->query_gender() == quien[0]->query_gender())
         {
           notify_fail("No esta permitido casarse con gente de tu mismo sexo en "
           "este lugar.\n");
           return 0;
         }
         if( 150000 > TP->query_value() )
         {
           notify_fail("No tienes dinero para costear tu matrimonio.\n");
           return 0;
         }
         
         
         if(TP->query_gender() == 1)
           ret = HAND->casarse(TP, quien[0]);
         else
           ret = HAND->casarse(quien[0], TP);
         if(ret == 0)
         {
           notify_fail("Uno no se puede casar con alguien si se esta casado "
           "o este esta casado.\n");
           return 0;
         }
         casando=1;
         TP->pay_money(({"copper", 150000}));
         anillo=new("/d/oficios/clerigos/gestur/obj/anillo_boda");
         anillo->move(TP);
         anillo=new("/d/oficios/clerigos/gestur/obj/anillo_boda");
         anillo->move(quien[0]);
         tell_object(TP , "Arelias te entrega un anillo de bodas.\n");
         tell_object(quien[0] , "Clerigo te entrega un anillo de bodas.\n");
         tell_room(environment(TO), "\nClerigo dice: Nos encontramos aqui "
         "reunidos para conmemorar el matrimonio entre "+
         TP->query_cap_name()+" y "+quien[0]->query_cap_name()+".\n");
         call_out("mensajes", 3, TP, quien[0]);
         return 1; 
      }
    }
    else
    {
      notify_fail("Sintaxis: casarse con <persona>.\n");
      return 0;
    }
}
 
void mensajes(object ob, object ob2)
{
    if(ob->query_gender() == 1)
    {
       tell_room(environment(TO), "Clerigo dice: Tu "+ob->query_cap_name()+
       " aceptas como esposa a "+ob2->query_cap_name()+" y prometes amarla "
       "y protegerla en enfermedad y en la pobreza hasta que la muerte os "
       "separe?.\n");
       call_out("mensajes2", 3, ob, ob2);
    }
    else
    {
      tell_room(environment(TO), "Clerigo dice: Tu "+ob2->query_cap_name()+
       " aceptas como esposa a "+ob->query_cap_name()+" y prometes amarla "
       "y protegerla en enfermedad y en la pobreza hasta que la muerte os "
       "separe?.\n");
       call_out("mensajes2", 3, ob2, ob);
    }
    return 1;
}
 
void mensajes2(object ob, object ob2)
{
       tell_room(environment(TO), ob->query_cap_name()+" dice: Si, prometo.\n", ob);
       tell_object(ob, "Dices: Si, prometo.\n");
       call_out("mensajes3", 3, ob, ob2);
       return 1;    
}
 
void mensajes3(object ob, object ob2)
{
       tell_room(environment(TO), "Clerigo dice: Tu "+ob2->query_cap_name()+
       " aceptas como esposo a "+ob->query_cap_name()+" y prometes amarlo "
       "y protegerlo en enfermedad y en la pobreza hasta que la muerte os "
       "separe?.\n");
       call_out("mensajes4", 3, ob, ob2);
       return 1;
}
 
void mensajes4(object ob, object ob2)
{
       tell_room(environment(TO), ob2->query_cap_name()+" dice: Si, prometo.\n", ob2);
       tell_object(ob2, "Dices: Si, prometo.\n");
       call_out("mensajes5", 3, ob, ob2);
       return 1;    
}
 
void mensajes5(object ob, object ob2)
{
       tell_room(environment(TO), "Clerigo dice: Entonces por la facultad "
       "que me han dado yo os declaro marido y mujer. Puedes besar a "
       "la novia.\n");
       call_out("mensajes6", 3, ob, ob2);
       return 1;    
}
 
void mensajes6(object ob, object ob2)
{
       tell_room(environment(TO), ob->query_cap_name()+" besa apasionadamente a "+
       ob2->query_cap_name()+".\n", ({ ob, ob2 }) );
       tell_object(ob, "Besas apasionadamente a "+ob2->query_cap_name()+".\n");
       
       tell_object(ob2, ob->query_cap_name()+" te besa apasionadamente.\n");
       casando = 0;
       return 1;    
}
