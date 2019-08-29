inherit "/obj/armour"; 

void setup()  
  { 
  set_base_armour("anillo");
  set_name("anillo");
  add_alias("illita");
  set_short("Anillo del Illita");
  set_main_plural("Anillos del Illita");
  set_long("Es un pequenyo anillo de madera, con unas inscripciones "
           "en su interior. En ellas se puede leer:\n\n     "
           "Para invocar al desollador, solo has de desearlo.\n");
  set_enchant(6);
}

void init() {
  ::init();
  add_action("do_invocation","invocar");
}

int do_invocation() {
  write("\n%^BOLD%^Un desollador se materializa ante tus ojos!\n\n%^RESET%^");
  new("/w/xerxes/methil.c")->move(environment(this_player()));
  return 1;
}
