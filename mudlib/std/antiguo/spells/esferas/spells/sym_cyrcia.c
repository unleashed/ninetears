/*** Spider summoning -- for Cyrcia's Symbol spell ***/ 
/*** By Wonderflug ***/ 
/* Tweaked by Shaper to let players transform a corpse into a skull. 
Idea and presentation by Nebelhexa, code by Shaper, June 97  */ 
 
#define BASE_THACO 150 
#define HP_PER_LEVELX 6 
#define SKULL "/d/aprior/guilds/cyrcia/items/skull.c" 
#define NUMATTACKS 2 
#define CONSUME_COST 4 
#define ROUNDS_PER_LEVELX 20 
#define CYRCIA_SYMBOL "/std/spells/items/cyrcia_symbol.c" 
 
inherit "/obj/monster.c"; 
#include "unarmed_combat.h"; 
 
 
int base_hb; 
int end_hb; 
object myp; 
 
void setup() 
{ 
    set_name("giant spider"); 
    add_alias("spider"); 
    set_short("Giant Red Spider"); 
    set_long("Giant Red Spider\n\n" 
      "  This is a huge spider, almost as big as a small horse.  " 
      "Its body is shielded by a blood-red chitinous " 
      "shell, which seems hard and smooth as marble.  " 
      "Its legs, thick as a grown man's thigh each, are " 
      "covered in short, bristly red hairs, and end in " 
      "a single sharp claw, so it makes disturbing " 
      "clicking and scratching sounds as it moves. " 
      "Huge multifaceted glowing green eyes dominate the head, " 
      "but the seeming glimmer of intelligence there startles " 
      "you the most.  Of course, " 
      "those razor-sharp mandibles dripping with blood are " 
      "fairly startling too.\n\n"); 
    set_guild_ob("/std/guilds/priests/cyrcia.c"); 
    set_race("spider"); 
    add_attack_spell(20, "poison", ({"/std/spells/cleric/poison.c", 
        "cast_spell", 0, 1})); 
 
} 
 
void init() 
{ 
    ::init(); 
    add_action("do_dismiss", "dismiss"); 
    add_action("do_skull", "consume"); 
} 
 
 
int do_skull(string str) 
{ 
    object it, skull; 
 
    if(myp != this_player())  return 0; 
 
    it = present("corpse", environment(this_object())); 
    if(!it) { 
        write("The spider glances around the room, and can't seem to find 
anything.\n"); 
        return 1; 
    } 
    if(TP->query_gp() < CONSUME_COST)  { 
        write("You are currently to weak to command the spider.\n"); 
        return 1; 
    } 
 
    TP->adjust_gp(-CONSUME_COST); 
    skull = clone_object(SKULL); 
    skull->move(ETO); 
    skull->set_long("This horrid black skull seems to grin menacingly " 
      "at you.  You think back to the time when it " 
      "belonged to "+it->query_owner()+".\n\n"); 
    say("     The Spider spits poison on the corpse, and it begins " 
      "to glow with an unholy aura.  Slowly the corpse decays, " 
      "and all that remains is a small, blackened skull.  " 
      "This is truly a gift only a daughter of Cyrcia can " 
      "bestow upon her goddess.\n\n"); 
    write("     The Spider spits Cyrcia's unholy poison upon the " 
      "corpse, and you see her dark power take hold, " 
      "as the corpse is melted into nothingness.  " 
      "You smile, knowing that the black skull it left behind, " 
      "will make a wonderfully repulsive gift for your lady of " 
      "chaos.\n\n"); 
    it->dest_me(); 
    return 1; 
} 
 
 
int do_dismiss( string str ) 
{ 
    if ( this_player() != myp ) 
        return 0; 
    if ( str != "spider" ) 
        return 0; 
 
    do_command("drop all"); 
    tell_object(myp, "You dismiss the spider and it reverts back into a " 
      "Spider Medallion.\n"); 
    tell_room(environment(myp), myp->query_cap_name()+" gestures at " 
      "the "+this_object()->short()+" and it shimmers and morphs into " 
      "a small Spider Medallion.\n", myp); 
    clone_object(CYRCIA_SYMBOL)->move(myp); 
    call_out("dest_me",0); 
    return 1; 
} 
 
void setup_spell(object caster) 
{ 
    int level; 
 
    myp = caster; 
    level = (int)caster->query_level(); 
 
    set_level( level ); 
    set_max_hp(level*HP_PER_LEVELX); 
    set_hp(level*HP_PER_LEVELX, this_object()); 
    set_str((int)caster->query_str()); 
    set_dex((int)caster->query_dex()); 
    set_int((int)caster->query_int()); 
    set_wis((int)caster->query_wis()); 
    set_con((int)caster->query_con()); 
    set_thac0( BASE_THACO - (3 * level )); 
    set_ac(50 - level ); 
    base_hb = myp->query_hb_counter(); 
    end_hb = base_hb + ( level*ROUNDS_PER_LEVELX ); 
 
    this_object()->move(environment(myp)); 
    /* messages */ 
    tell_object(myp, "Suddenly Cyrcia's medallion starts to feel incredibly " 
      "hot, and \nyou drop it on the ground.\n"); 
    tell_room(environment(myp), myp->query_cap_name()+" drops a  " 
      "Spider Medallion and shakes "+myp->query_possessive()+ 
      " hand as if burned.\n", myp); 
    tell_room(environment(myp), "The Spider Medallion glows with an " 
      " evil red light, and suddenly the spider on it steps " 
      "off and grows enormously!\nThe Huge Red Spider clicks and " 
      "scuttles over to "+myp->query_cap_name()+".\n"); 
 
    do_command("protect "+myp->query_name()); 
    do_command("follow "+myp->query_name()); 
} 
 
void heart_beat() 
{ 
    if ( !myp ) 
    { 
        tell_room(environment(this_object()), "The spider clicks confusedly " 
          "and goes *pop* " 
          "into a zillion little bits.\n"); 
        call_out("dest_me",0); 
        return; 
    } 
    if ( (int)myp->query_hb_counter() >= end_hb ) 
    { 
        tell_object(myp, "The spider shimmers and reverts back into an " 
          "amulet.\n\n"); 
        do_command("drop all"); 
        clone_object(CYRCIA_SYMBOL)->move(myp); 
        tell_room(environment(myp), "The spider suddenly shimmers and " 
          "morphs into a Spider Medallion.\n", myp); 
        call_out("dest_me",0); 
    } 
 
    if(environment(myp) != environment(TO))  
        TO->move(environment(myp)); 
    ::heart_beat(); 
} 
 
int query_kill_xp() { return 0; } 
 
int unarmed_attack(object him, object me) 
{ 
    object* att; 
    object ob; 
    int i; 
 
    att = (object*)me->query_attacker_list(); 
    for(i=0; i<NUMATTACKS; i++) 
    { 
        ob = att[random(sizeof(att))]; 
        if(ob) monster::unarmed_attack(ob, me); 
    } 
} 
 
mixed valid_attack() { 
    return([ 
      "punch"  : ({ AN+" stabs at you with its legs.\n", 
        "You stab at "+DN+" with your legs.\n", 
        AN+" stabs at "+DN+" with its front two legs.\n" }), 
      "kick"  :  ({ AN+" crushes you with its pincers.\n", 
        "You crush "+DN+" with your pincers.\n", 
        AN+" crushes "+DN+" with its pincers.\n"}), 
      "knee" : ({ AN+" spits burning acid at you.\n", 
        "You spit burning acid at "+DN+".\n", 
        AN+" spits a stream of burning acid at "+DN+".\n"}), 
      "headbutt"  : ({ AN+" bites you viciously.\n", 
        "You bite "+DN+" viciously.\n", 
        AN+" bites "+DN+" viciously.\n" }), 
    ]); 
} 
 
