// Spp Dic'97
#include "/w/barthleby/path.h"
#include "var.h"
inherit "/obj/monster";

void Crear();                   // Principal y necesario
void Nivel(int QueNivel);       // Nivel del personaje
//void Orden(string QueOrden);    // Orden
void Rango(string QueRango);    // Rango militar...
void Edad(int QueEdad);

int Nivel   = 20;
//int LOrden  = 0;
int LRango  = 0;
int LEdad   = 0;

//string Orden;
string Rango;
string Plural;
int    Edad;

void Nivel(int QueNivel){  Nivel = QueNivel;}
void Edad (int QueEdad){ Edad = QueEdad;}

/*void Orden (string QueOrden)
{
  switch(QueOrden)
    {
      case ("luna"):case("sol"):case("libra"):
      case ("tierra"):case("mente"):case("takome"):
       Orden = QueOrden;break;
      default: Orden = "sol";
    }
  LOrden = 1;
}*/

void Rango(string QueRango)
{
  int Valor=random(11);
  switch(QueRango)
  {
    case("soldado"):case("soldado jefe"):case("capitan"):case("general"):
     Rango = QueRango;break;
    default :
    switch(Valor)
    {
     case(0):case(1):case(2):case(3):case(4): Rango = "soldado"; break;
     case(5):case(6):case(7): Rango = "soldado jefe";break;
     case(8):case(9): Rango = "capitan"; break;
     case(10): Rango = "general"; break;
    }
  }
  LRango=1;
}

string Plural ()
{
  switch(Rango)
  {
    case("soldado"):     Plural = "soldados";      break;
    case("soldado jefe"):Plural = "soldados jefe"; break;
    case("capitan"):     Plural = "capitanes";     break;
    case("general"):        Plural = "generales";         break;
    default: Plural = "soldados";
  }
}

void Crear()
{
  if (!LRango)  Rango ("");
//  if (!LOrden)  Orden ("");
  if (!LEdad)   Edad(random(3));
  Plural();
  set_name(capitalize(Rango));
  add_alias(Rango);
//  add_alias(Orden);
  add_alias("humano");
  add_alias("soldado");
  add_alias("guardia");
  add_plural(Plural);
  add_plural("humanos");
  add_plural("soldados");
  add_plural("guardias");
  set_short(capitalize(Rango)+" de la guardia de Noella"/*+capitalize(Orden)*/);
  set_main_plural(Plural+" de la guardia de Noella"/*+capitalize(Orden)*/);
  set_long("Es un soldado de �lite de la guardia de Noella. "
           "Tiene una inmejorable formaci�n en combate cuerpo a cuerpo. No se f�a de nadie.\n"
           "Por las cicatrices de su cara supones que tiene una amplia experiencia en combate.\n");
  set_race("human");
  set_race_ob("/std/races/human");
  set_guild("figther");
  set_guild_ob("/std/guilds/warriors/fighter.c");
  set_random_stats(15, 18);
  set_cha(15+random(2));
  set_wimpy(0);
  set_aggressive(0);
/*  switch(Orden)
  {
        // Aunque dejo a tu eleccion el equipo, que no es mas indicado para alguien de
        // nivel 15 o superior (segun mi opinion, claro =) No estaria de mas que cada
        // uno tuviera mas posibilidades de tocar.
    case("sol")   :set_level(SOL);break;
    case("luna")  :set_level(LUNA);break;
    case("libra") :set_level(LIBRA);break;
    case("takome"):set_level(TAKOME);break;
    case("mente") :set_level(MENTE);break;
    case("tierra"):set_level(TIERRA);break;
    default:set_level(Nivel);
  }*/
// HECHO POR FLO
  switch(Rango)
  {
    case("general")   :set_level(20);break;
    case("capitan")  :set_level(15);break;
    case("soldado jefe") :set_level(10);break;
    case("soldado"):set_level(5);break;
    default:set_level(Nivel);
  }
  load_a_chat(50,
      ({
            1, "'Nadie osa atacar a la guardia de Noella.",
            1, "'Debiste pensar en tu familia antes de pedir la muerte.",
            1, "'Ahora pagar�s tu osad�a.",
       }));
  load_chat(100,
      ({
            1, ":te vigila con cara de pocos amigos.",
            1, "'Yo de ti no me meteria en problemas... Grrrrrr.",
       }));
  switch(Rango)
  {
    case("general"):
        new(ARMA+"daga")->move(this_object());
        new(ARMADURA+"manto")->move(this_object());
        adjust_money(random(1)+1,DINERO);
      break;
    case("soldado"):
        new(ARMA+"corta")->move(this_object());
        new(ARMA+"armadura_soldado")->move(this_object());
        adjust_money(random(3)+1,DINERO);
      break;
    case("soldado jefe"):
        new(ARMA+"larga")->move(this_object());
        new(ARMA+"armadura_jefe")->move(this_object());
        new(ARMA+"casco_jefe")->move(this_object());
        adjust_money(random(5)+1,DINERO);
      break;
    case("capitan"):
        new(ARMA+"espada_capitan")->move(this_object());
        new(ARMA+"armadura_capitan")->move(this_object());
        new(ARMA+"casco_capitan")->move(this_object());
        adjust_money(random(10)+1,DINERO);
      break;
    default:
  }
  this_object()->init_equip();
  add_move_zone("noella");
  adjust_money(4,"platinums");
  set_move_after(5,10);
}

/*void event_enter(object ob, string mess)
{
if (ob->query_player())
 {
  if (ob->query_property("bando") > 1 || ob->query_property("Renegado Takome"))
   if (ob->query_dead())
   {
     do_command("risa "+ob->query_name());
     ob->remove_property("castillo_takome");
   }
   else
   {
     do_command("say Muerte a todos los Enemigos del Bien!");
     this_object()->attack_ob(ob);
   }
}
  ::event_enter(ob, mess);
}

void init()
{
 ::init();
   add_attack_spell(5,"desarmar", ({"/std/commands/desarmar", "disarm", 0}));
}*/
