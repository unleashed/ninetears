inherit "/global/lord.c";

#define  O_TYPE "G"

string query_gtitle()
{
  string patronage;
  patronage = "/secure/gods"->query_boo(name);
  if(query_female()) return "la Diosa de"+patronage;
  return "el Dios de"+patronage;
    }

/* Maybe this shouldn't be here.. but I need it right now. Should make it
   unshadowable. Baldy.. */

nomask int query_god() {return 1;}
int query_lord() {return 1;}
int query_creator() {return 1;}
	    
string query_object_type() 
  {
  return O_TYPE;
  }  /* query_object_type() */

