create() { seteuid(geteuid(this_player())); }
dest_me() { destruct(this_object()); }
do_call() {
for(int i=0;i<60;i++)clone_object("/obj/chars/zombie.c")->move(environment(find_living("kryger")),"Notas a Zombie moverse a tu alrededor.\n");
}
