inherit "/std/underground";

void eco(string mensaje)
{
   tell_room(this_object(), "\nOyes por el oeste "+mensaje+"\n", 0);
   return 1;
}
void raweco(string mensaje)
{
   tell_room(this_object(), "\n"+mensaje+"\n", 0);
   return 1;
}
