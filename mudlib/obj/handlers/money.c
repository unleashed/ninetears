/*
   /obj/handlers/money.c
   Radix : April 30, 1997
*/
inherit "/std/object.c";

mapping pool;

create()
{
   ::create();
   pool = ([ ]);
}

void update_money(int amt, string type, object ob)
{
   string dom;
   if(!ob->query_npc() || !domain_origin(ob))
      return;
   dom = real_filename(ob);
   pool[dom][type] = pool[dom][type] + amt;
}

mapping query_money_dist() { return pool; }

// Called from /global/creator/cmds/info.c
void info_money(string str)
{
   int val1, val2, val3, val4, val5;
   string dom;
   if(!str)
   {
      notify_fail("Usage: info -m <domain>\n");
      return 0;
   }
   printf("%-40s %5s %5s %5s %5s %5s %7s\n",
         "Subdirs","C","S","E","G","P","Total");
   printf("%|*'-'s\n",this_player()->query_cols(),"-");
   foreach(dom in keys(pool))
      if(explode(dom,"/")[0] == str)
         printf("%-18s %8d %8d %8d %8d %8d %8d\n",
            dom[3..48],
            (val1 = pool[dom]["copper"]),
            (val2 = pool[dom]["silver"]*10)/10,
            (val3 = pool[dom]["electrum"]*50)/50,
            (val4 = pool[dom]["gold"]*100)/100,
            (val5 = pool[dom]["platinum"]*500)/500,
            val1 + val2 + val3 + val4 + val5);
   return;
}
