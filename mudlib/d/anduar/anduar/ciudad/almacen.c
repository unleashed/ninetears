inherit "/std/storeroom";
#include "../path.h"
#define ARMAS "/baseobs/weapons/"
#define ARMAD "/baseobs/armours/"

setup()
{
        set_short("El almassen");
        set_long("Aqui e donde se guardan los objetos.\n");
        add_exit("south", ANDUAR+"tienda", "door");
        set_light(80);
}

void reset()
{
        call_out("af_reset", 0);
}

void af_reset()
{
   int i, j;
   object ob, torch;
        
   i = sizeof(find_match("monederos", this_object()));
   for (;i<3;i++)
   {
     ob = clone_object("/std/container");
     j = random(3);
     ob->set_max_volume(1000+j*2000);
     ob->set_max_weight(10+j*20);
     ob->set_name("bote");
     ob->set_short("bote "+({ "pequenyo", "mediano", "grande" })[j]);
     ob->set_main_plural("botes "+({ "pequenyos", "medianos", "grandes" })[j]);
     ob->add_adjective( ({ "pequenyo", "mediano", "grande" })[j]);
     ob->add_plural("botes");
     ob->set_value(60+j*23);
     ob->set_long("Un recipiente "+({ "pequenyo","mediano","grande"})[j]+
     ". Sirve para meter pequenyas cosas en el.\n");
     ob->move(this_object());
     ob->set_weight(4+j*3);
     ob->set_genero(0);
   }
   i = sizeof(find_match("torches", this_object()));
   for (;i<4;i++)
   {
   torch = clone_object("/obj/misc/torch");
   torch->move(this_object());
   }
   i = sizeof(find_match("quarterstaves", this_object()));
   for (;i<2;i++)
   {
   ob = clone_object("/baseobs/weapons/twohanded_staff");
   ob->move(this_object());
   }
   i=sizeof(find_match("cota de mallas", this_object()));
   for (;i<3;i++)
   {
      ob=new(ARMAD+"chainmail");
      ob->move(this_object());
      ob->set_value(80);
   }
   i=sizeof(find_match("armadura de cuero", this_object()));
   for (;i<2;i++)
   {
      ob=new(ARMAD+"leather");
      ob->move(this_object());
      ob->set_value(25);
   }
   i=sizeof(find_match("espada corta", this_object()));
   for (;i<2;i++)
   {
      ob=new(ARMAS+"short_sword");
      ob->move(this_object());
      ob->set_value(10);
   }
   i=sizeof(find_match("escudo medio", this_object()));
   for (;i<2;i++)
   {
      ob=new(ARMAD+"med_shield");
      ob->move(this_object());
      ob->set_value(5);
   }
   i=sizeof(find_match("daga", this_object()));
   for (;i<2;i++)
   {
      ob=new(ARMAS+"dagger");
      ob->move(this_object());
      ob->set_value(8);
   }
   i=sizeof(find_match("yelmo", this_object()));
   for (;i<5;i++)
   {
      ob=new(ARMAD+"helmet");
      ob->move(this_object());
      ob->set_value(4);
   }
/*   i=sizeof(find_match("cuerda", this_object()));
   for (;i<1;i++)
   {
      ob=new("/d/newbie/humana/items/cuerda.c");
      ob->move(this_object());
  }*/
}
