inherit "/std/item";
#define BRIGHTNESS 50 

int amount_of_fuel;
status is_lighted;
 
void setup() {
  amount_of_fuel = 2000; 
  set_name("torch"); 
  set_main_plural("torches");
  set_short("Torch");
  set_long("A small torch.\n");
  is_lighted = 0;
  set_weight(50);
  set_value(50);
}

int query_holdable() {return 1;}
int query_hands_needed() { return 1; }

string short(int i) {
    if (is_lighted)
        return ::short(0) + " (lit)";
    return ::short(0);
    }
 
string pretty_plural() {
  if (is_lighted)
    return ::pretty_plural() + " (lit)";
  return ::pretty_plural();
}

void set_fuel(int f) { amount_of_fuel = f; }
 
void init() {
  this_player()->add_command("light", this_object());
  this_player()->add_command("extinguish", this_object());
}
 

/* This function will only be called as a result of the add_command(), that
is, it will only be called by the living object that has this torch in 
inventory.  If we want for any other object to be able to cause the torch
to light, I have to write another function. */

int do_light(object *indir, int s1, int s2, mixed *prep) {
  string mess;
  if (!query_in_use())
    mess = "it must be held first (try \"hold torch\")";
  else if (is_lighted)
    mess = "it's already lit";
  else if (amount_of_fuel <= 0)
    mess = "it's burnt out";
  if (mess) {
    tell_room(environment(),environment()->query_cap_name()+" tries to light"
      " a torch, but "+mess+"!\n",environment());
    tell_object(environment(), "You try to light a torch, but "+mess+"!\n");
    return 0;
  }
  is_lighted = 1;
  call_out("out_of_fuel", amount_of_fuel * 2);
  amount_of_fuel = 0;
  set_light(BRIGHTNESS);
  return 1;
}
 
void out_of_fuel() {
  is_lighted = 0;
  set_light(0);
  tell_room(environment(),"The " + short(0) + " goes out.\n",environment());
  tell_object(environment(), "The " + short(0) + " goes out.\n");
}

void set_held(int i) {
  // ::set_held(i);
  if (i==0 && is_lighted)
    out_of_fuel();      /* it's not really out of fuel */
}

int do_extinguish(object *indir, string s1, string s2, string prep) {
  int i;
  if (!is_lighted) {
    tell_room(environment(),environment()->query_cap_name()+" tries to "
      "extinguish a torch, but it's not lit!\n",environment());
    tell_object(environment(), "You try to extinguish the torch, but"
      " it's not lit!\n");
    return 0;
  }
  i = remove_call_out("out_of_fuel");
  amount_of_fuel = i/2;
  is_lighted = 0;
  set_light(0);
  return 1;
} 

void dest_me()
{
  set_light(0);
  ::dest_me();
}
