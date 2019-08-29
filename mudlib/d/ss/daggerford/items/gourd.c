inherit "/std/object";
 
#define PL_NAME this_player()->query_cap_name()
 
void init()
   {::init();
    add_action("do_break", "break");
   }
 
void setup()
   {set_name("gourd");
    add_alias("gourd");
    add_alias("husk");
    add_alias("sealed gourd");
    set_main_plural("sealed gourds");
    add_plural("gourds");
    set_short("Sealed Gourd");
    set_long("This is a small, dried husk of a squash-like vegetable.  "+
             "It appears that the top of the gourd has been severed, "+
             "though the opening has been sealed with a thick layer of "+
             "wax.  From within, it sounds as if the husk has been "+
             "filled with some sort of fine powder or liquid.  You "+
             "could probably 'break gourd' to release the contents.\n\n");
    set_weight(50);
    set_value(200);
   }
 
int do_break(string str)
   {object temp, *obs, *atts;
    int i, j;
    if(!str || str != "gourd")
      {write("To break open this item, use the following syntax:  "+
             "'break gourd'\n\n");
       return 1;
      }
    tell_object(this_player(), "You forcefully throw the gourd onto the "+
          "ground beneath your feet!  Almost immediately, the room area "+
          "surrounding you fills with a cloud of fine smoke, making "+
          "vision nearly impossible!\n\n");
    tell_room(environment(this_player()), PL_NAME+" throws a small gourd "+
          "onto the ground where it shatters into a million pieces!  "+
          "Instantly, the area fills with a billowing cloud of smoke, "+
          "making vision nearly impossible!\n\n", ({this_player()}));
    temp = clone_object("/d/ss/daggerford/items/smoke.c");
    temp->move(environment(this_player()));
    temp = clone_object("/d/ss/daggerford/items/delay.c");
    temp->move(this_player());
    obs = all_inventory(environment(this_player()));
    for(i=0; i < sizeof(obs); i++)
      {if((int)(obs[i]->query_level()) > 0)
         {atts=obs[i]->query_attacker_list();
          for(j=0; j < sizeof(atts); j++)
             {obs[i]->stop_fight(atts[j]);
              atts[j]->stop_fight(obs[i]);
             }
        }
      }
    this_object()->dest_me();
    return 1;
   }
