

#include <standard.h>
#include <cmd.h>
inherit CMD_BASE;

int ex_spool(string yn,string file,int linum);
varargs wiz_present(string str,object ob,int internal);

void setup()
{
	position = 1;
}

static int cmd(string str, object me) 
{
   object *things;
   string * filenames;
   string s1;
   int egg;
   string spam;
   int i;
   if(str == 0 || str == "") return 0;
  /* dodgy idea, but allows 'ed here' or 'ed strawberry' */        
  if (sizeof(things =  me->wiz_present(str, me))) {
    spam = file_name(things[0]);
    sscanf(spam, "%s#%d", spam, egg);
    if (file_size(spam) < 0)
      filenames = ({ spam+".c" });
    else
      filenames = ({ spam });
  } else
    filenames = me->get_files(str);
  if (!sizeof(filenames)) { 
    str = me->get_path(str);
  } else {
    if (sizeof(filenames) > 0) {
      str = filenames[0];
      if (sizeof(filenames) > 1) {
        int loop;

        loop = 0;
        while(loop < sizeof(filenames) && file_size(filenames[loop]) < 0)
          loop++;
        if(loop >= sizeof(filenames)) {
          write("No such file.\n");
          return 0;
        }
        else {
          str = filenames[loop];
        } 
        write("Ambiguous, using : " + str + "\n");
      }
    }
  }
  if (file_size(str) == -2) {
    write("directory\n");
    return 1;
  }
   ex_spool("y",str,1);
   return 1;
}
int ex_spool(string yn,string fil,int linum)
{
   string s1;
   int i;
   mixed tnum;
   if(sscanf(yn,"%d",tnum) == 1)
   {
      linum = (int)tnum;
      if(linum < 1 ) linum = 1;
   }
   if( (yn == "Q") || (yn == "q") ) return 1;
   for(i = 0;i< 20; linum++)
   {
      i++;
      s1 = read_file(fil,linum,1);
      if( s1 == 0 )
      {
         write("\n");
         return(1);
      }
   write(s1);
   }
   printf("File %s Q to quit ",fil);
   input_to("ex_spool",0,fil,linum);
   return 1;
}
