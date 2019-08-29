// Radix, July 1996
// Called from create() in /std/object.c
// if creator made me, tag their name to it

string get_create_me(string tmp)
{
   object *obj = previous_object(-1);
   int i;
   for(i=sizeof(obj)-1; i > -1; --i)
      if(obj[i]->query_creator())
         return geteuid(obj[i]);
   return tmp;
}
