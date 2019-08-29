inherit "/obj/monster";


void setup()
{
   set_name("kender");
   set_short("kender");
   set_long("Es un ser parecido a un halfling, pero hay un gesto aninyado en su "
   	    "cara y una aspecto de inocencia que te llama la atencion especialmente.\n");
   set_gender(1);
//   set_race_ob("std/races/kender");
/*   set_race_ob("std/races/halfling");
//   set_guild_ob("/std/guilds/rogues/thief");
   set_guild_ob("/std/guilds/warriors/battles");
   set_al(-900);

   set_main_plural("kenders");
   add_plural("kenders");
   set_level(35);
   set_int(10);
   set_wis(10);
   set_cha(20);
   set_str(17);
   set_dex(20);
   set_con(15);*/
   set_max_hp(300);   

clone_object("/baseobs/armours/leather.c")->move(TO);
clone_object("/baseobs/weapons/dagger.c")->move(TO);
clone_object("/baseobs/weapons/dagger.c")->move(TO);
   init_equip();
   	              
   }


 void event_enter(object target, string MESG, object FROM)
{
if (sizeof(TO->query_attacker_list())) 
        {
        TO->do_command("say Ayudame... por favor!! arbGH!!");        
	}
}

void attack_by(object atacante)
{
int frase;
if (random(3)==1)
	{
	frase=random(5)+1;
	if (frase==1){TO->do_command("say Socorro!!");}
	if (frase==2){TO->do_command("say Ayudame por favor!!");}
	if (frase==3){TO->do_command("say Aghghh!!");}
	if (frase==4){TO->do_command("say Si me ayudas te lo agradecere siempre!!");}
	if (frase==5){TO->do_command("say SOOOOCOOOORROOOOOO!!!!!!!");}
	}
::attack_by(atacante);
	
}


int salvado(object pj)
{
call_out("salvado2",2,pj);
}
int salvado2(object pj)
{
if (!sizeof(TO->query_attacker_list())) 
	{
	TO->do_command("say Oh gracias!!");
	TO->do_command("say Has sido muy amable, toma un regalo!!");	
	tell_object(pj,"El kender te da algo.\n");
	//tell_room(ENV(pj),"El kender le da algo a "+pj->query_cap_name()+".\n",pj);	
	clone_object("/d/anduar/rutic/amuleto.c")->move(pj);	
	write_file("/d/anduar/logs/amuleto.txt",""+pj->query_cap_name()+" // "+ctime(time())+".\n");    		
	call_out("pirarse",3,pj);
	}
}
int pirarse(object pj)
{
tell_room(ENV(TO),"Kender se va al sur.\n");
pj->remove_timed_property("SACO");
pj->add_property("amuleto_kender",1);	
destruct(TO);
return 1;
}
