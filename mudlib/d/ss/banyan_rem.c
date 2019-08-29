/* swamp:  banyan */

#define AT attacker->query_cap_name()
#define DF defender->query_cap_name()
inherit "obj/monster";

void setup() {
     set_name("Banyan tree");
     add_alias("banyan tree");
     add_alias("banyan");
     add_alias("tree");
     set_main_plural("Banyan trees");
     add_alias("banyan trees");
     add_alias("banyans");
     add_alias("trees");
     add_adjective("large");
     set_race("monster");
     set_al(50);
     set_gender(0);
     set_random_stats(12,20);
     set_str(20);
     set_level(30);
     set_aggressive(0);
     set_wimpy(0);
     set_short("Banyan tree");
     set_long("This is an ancient Banyan tree and it is approximately " +
        "twenty feet tall.  It seems to be watching your every move " +
        "and its branches are ready to tear you apart if it needs " +
        "to.   Its huge thick roots sink deep into the swamp, " +
        "draining the life of the area into itself.\n");
     }
/* void set_up ends */

/*
int unarmed_attack(object target, object me)
{
    int i;
    object *att;
    att = (object *)me->query_attacker_list();
   for(i=1;i<=2;i++)
	monster::unarmed_attack(att[random(sizeof(att))], me);
clone_object("/d/ss/swamp2/chars/pacifist_shadow.c")->start(att);
}
*/

valid_attack() {
     return ([
        "punch":({AT + " smacks " + DF + " with " + AT->
                query_possessive() + " branches.\n",
                "You smack " + DF + " with your branches.\n",
                AT + " smacks you with " + AT->query_possessive() +
                " branches.\n"}),
        "kick":({AT + " strangles " + DF + " as " + AT->
               query_pronoun() + " wraps a branch around " + DF->
               query_possessive() + " neck.\n",
               "You strangle " + DF + " with your branch.\n",
               AT + " strangles you as " + AT->query_pronoun() +
               " wraps a branch around your neck.\n"})]);
     }
/* valid_attack ends */
