inherit "std/outside";
#include "path.h"
inherit "/d/hoerk/belaern/s_jung/city/shops/restock.c";

object *animal;

void reset()
{
int k;
int j;
int p;
	p==j + 1;
	for(k=0;k<j;k++)
	{
	if(!animal[k]){
	int i;
	i=random(7);
	if(i == 1) {
		animal[k]=clone_object(CHAR+"rabbit");
		}
	if(i == 0) {
		animal[k]=clone_object(CHAR+"squirrel");
		}
	if(i == 2) {
		animal[k]=clone_object(CHAR+"birdie");
		}
	if(i == 3) {
		animal[k]=clone_object(CHAR+"deer");
		}
	if(i == 4) {
		animal[k]=clone_object(CHAR+"boar");
		}
   if(i == 5) {
            animal[k]=clone_object(char+"sprite");
             }
    if(i == 6)  {
            animal[k]=clone_object(char+"forlarren");
                }
	animal[k]->move(this_object());
	}
	}

}

void dest_me()
{
	for(t=0;t<5;t++)
	{
		if(animal[p]) {
			animal[p]->dest_me();
		}
	}
}

