inherit "/std/room";

// Vilat 06.12.2002 - El trasteo del driver me ha traido aqui... Siempre dije que odiaba los pinguinos!!!!
void do_update(string str) {
   int i;
   object *all = all_inventory(this_object());
   if(!stringp(str) || str == "here") {
      //load destinations
      "/w/common"->BAH();
      "/room/entryroom"->BAH();
      for(i=0; i<sizeof(all); i++)
         if(interactive(all[i]))
         {
            if(!all[i]->query_creator())
            {
               tell_object(all[i],"Sacandote de la Nada...\n");
               all[i]->move("/room/entryroom");
            }
            if(all[i]->query_creator())
            {
               tell_object(all[i],"De regreso al Paraiso...\n");
               all[i]->move("/w/common");
               tell_room(find_object("/w/common"),all[i]->query_short()+" aparece de la nada.\n",all[i]);
            }
         }
         else
            all[i]->dest_me();     // dest those NPCs and weapons
   }
}


void setup() {
     set_light(40);
     set_short("La Nada");
     set_long(query_short()+"\nTe encuentras flotando en mitad de ninguna parte, todo esta oscuro a tu alrededor. Puede que no lo creas pero esta es la room m�s importante del MUD, ademas de la Sala de Trabajo de Turin.\n");
}
void init()
{
   add_action("do_update","update");
   room::init();
}

