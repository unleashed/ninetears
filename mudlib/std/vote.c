/****************************************************************************
*		     	    Voting room					    *
*									    *
*		           Khelben, 1997			            *
*									    *
*****************************************************************************/			

/*
mapping vote_data
([ "subject" : limited,   //The vote is free (0) or I must choose btw some
			  //candidates(1)
	       info      //Some usefull info
            ({ candidate1: ({ votes }) , candidate2: ({ votes }) , ... }),
               flag1   //0 All the people 
               	      //1 Only some races
               	      //2 Only some groups
               	      //3 Only some race-groups
               ({ flag races, groups.... })
               flag2   //0 All the people can vote
               	       //1 Only people over 5 days old can vote
               	       //x Only people over level x can vote.
])

*/

inherit "/std/room.c";

#define LOGFILE "/save/vote_data"

#define TIME 432000  // 5 days of play

mapping vote_data;
string *vote_list = ({ });


int do_help(string str);
int have_power(object ob);
int dofinish(string str);
int result(string str);
int do_list(string str);
int can_vote(string str);
int vote(string str);
int get_vote(string str, mixed tmp);
int add_subject(string sub, int limited, string info, string *candidates,
                int flag1, string *whoflag1, int flag2);
void do_resume(string sub, int limited, string info, string *candidates, 
               int flag1, string *whoflag1, int flag2);




create()
{
   ::create();
   vote_data = ([ ]);
   restore_function();
}

void save_function() 
{
   if( sizeof(vote_data) )   
      save_object(LOGFILE);
}

void restore_function() 
{
   if( !sizeof(vote_data) )   
      restore_object(LOGFILE, 1);
}

dest_me()
{
   save_function();
   destruct(this_object());
}

void init()
{
   add_action("vote","vote");
   add_action("do_list","list");
   add_action("result","result");   
   add_action("dofinish","finish");
   add_action("do_help","help");
   add_action("new_votation","newvote");
   add_action("resume","resume");
   
   ::init();
}   

void event_enter(object who, string mess)
{
   int i;
   
   for( i=0; i<sizeof(vote_list); i++ )
   {
      if(who->query_property(vote_list[i]))   //Subjects removed from votations.
         who->remove_property(vote_list[i]);  //Removing properties.
   }
}

int do_help(string str)
{
string helpinmortal = "\n\n"
"**********************************************************************\n"+
"*                                                                    *\n"+
"*     This is a vote room. Available commands are:                   *\n"+
"*                                                                    *\n"+
"*          list            : For seeing all the actual votations.    *\n"+
"*          list <subject>  : Who can you vote.                       *\n"+
"*          vote <subject>  : You need help about this?.              *\n"+
"*          resume <subject>: Give information about a votation.      *\n"+
"*          result <subject>: See the actuals results.                *\n"+
"*          finish <subject>: Finish a votation and log it.           *\n"+
"*          newvote         : Runs a program for add a new votation.  *\n"+    
"*                                                                    *\n"+
"*              If you find any bug, mail Khelben.                    *\n"+
"*                                                                    *\n"+
"**********************************************************************\n\n";

string help = "\n\n"
"**********************************************************************\n"+
"*                                                                    *\n"+
"*     This is a vote room. Available commands are:                   *\n"+
"*                                                                    *\n"+
"*          list          : For seeing all the actual votations.      *\n"+
"*          list <subject>: Who can you vote.                         *\n"+
"*          vote <subject>: You need help about this?.                *\n"+
"*                                                                    *\n"+
"*              If you find any bug, mail Khelben.                    *\n"+
"*                                                                    *\n"+
"**********************************************************************\n\n";

   if(str != "vote")
      return 0;
   if(have_power(TP))
      write(helpinmortal);
   else
      write(help);   
   return 1;
}

int have_power(object ob)
{
   if( ob->query_lord() )
      return 1;
   if( (string)ob->query_name() == "khelben" )
      return 1;

   return 0;
}

int dofinish(string str)
{
   int i;
   mixed tmp;
   string list="", *key;

   restore_function();
   if(!have_power(TP))
   {
      write("Only immortals can finish the votations.\n");
      return 1;
   }
   if(!str)
   {
      write("The actual votings are:\n");
      key = keys(vote_data);
      write("\n");
      for (i=0; i<sizeof(key); i++)
      {
         list += key[i];
         list += " : ";
         list += vote_data[key[i]][1];
         list += ".\n";
      }
      list += "\n\nPLEASE, choose one of the above.\n";
      this_player()->more_string(list);
    }  
    else
    {
       tmp = vote_data[str];
       if(tmp)
       {
          list += "The results for '"+tmp[1]+"' are: \n\n";
          for(i=0;i<sizeof(tmp[2]); i++)
          {
             list += tmp[2][i][0]+" : ";
             list += tmp[2][i][1]+".\n";
          }
          list += "\nFinished by "+this_player()->query_cap_name();
          list += " at "+ctime(time())+".\n";
          log_file(str+"_VOTATION", list);
          write("Votation '"+str+"' finished and logged at /log/"+str+".\n");
          vote_list += ({ tmp[1] });
          map_delete(vote_data,str);
       }       
       else
       {
          write("We are not voting '"+str+"'.\n");
          return 1;
       }
    }
    save_function();
    return 1;
}    
    
int result(string str)
{
   int i;
   mixed tmp;
   string list="", *key;

   if(!have_power(TP))
   {
      write("Only immortals can see the results.\n");
      return 1;
   }

   if(!str)
   {
      write("The actual votings are:\n");
      key = keys(vote_data);
      write("\n");
      for (i=0; i<sizeof(key); i++)
      {
         list += key[i];
         list += " : ";
         list += vote_data[key[i]][1];
         list += ".\n";
      }
      list += "\n\nPLEASE, choose one of the above.\n";
    }  
    else
    {
       tmp = vote_data[str];
       if(tmp)
       {
          list += "The results for "+tmp[1]+" are: \n\n";
          for(i=0;i<sizeof(tmp[2]); i++)
          {
             list += tmp[2][i][0]+" : ";
             list += tmp[2][i][1]+".\n";
          }
       }       
       else
       {
          write("We are not voting '"+str+"'.\n");
          return 1;
       }
    }
    
    this_player()->more_string(list);
    return 1;
}

int do_list(string str)
{
   int i;
   mixed tmp;
   string list="", *key;

   if(!str)
   {
      write("The actual votings are:\n");
      key = keys(vote_data);
      write("\n");
      for (i=0; i<sizeof(key); i++)
      {
         list += key[i];
         list += " : ";
         list += vote_data[key[i]][1];
         list += ".\n";
      }
    }  
    else
    {
       tmp = vote_data[str];
       if(tmp && tmp[0]==1)
       {
          list += "The candidates for "+tmp[1]+" are: \n";
          for(i=0;i<sizeof(tmp[2]); i++)
             list += tmp[2][i][0]+".\n";
       }       
       else
          list += "You have free vote!.\n";
    }
    
    this_player()->more_string(list);
    return 1;
}


int can_vote(string str)
{
   mixed tmp;
   string aux;

   if( !vote_data[str] )
   {
      write("There is not any votation about '"+str+"'.\n");
      return 1;
   }
   tmp = allocate(6);
   tmp = vote_data[str];
   if( TP->query_property(str) )
   {
      write("You already voted about this!.\n");
      return 0;
   }
   if ( tmp[5] == 1 )
   {
      if( TP->query_time_on() < TIME )
      {
         write("Sorry, you must be over 5 days old for voting about "+
               str+".\n");
         return 0;
      }
   }
   if( tmp[5] > 1 )
   {
      if( TP->query_level() < tmp[5] )
      {
         write("Sorry, you must be over level "+tmp[5]+" for voting about "+
               str+".\n");
         return 0;
      }
   }
   switch(tmp[3])
   {
      case 1 :
                 aux = TP->query_race();
                 break;

      case 2:
      		 aux = TP->query_group();
      		 break;
      		
      case 3:
      		 aux = TP->query_race_group();
      		 break;
      
      default:
      		 aux = "";
      		 break;
   }
   if(aux != "")
   {
      if( member_array(aux, tmp[4]) == -1 )
      {
         write("Sorry, "+str+" votation is restricted. You cannot vote "+
               "about it.\n");
         return 0;
      }
   }
   
   return 1;
}

int vote(string str)
{
   mixed tmp;
   int i;
   string list;

   restore_function();
   
   if( !vote_data[str] )
   {
      write("There is not any votation about '"+str+"'.\n");
      return 1;
   }
   if( can_vote(str) )
   {
      write("Ok, voting about '"+str+"'.\n");
      tmp = allocate(6);
      tmp = vote_data[str];
      if( tmp[0] ==  1 )
         do_list(str);
      write("Type your vote: ");
      input_to("get_vote",0,tmp);
   }
   save_function();
   return 1;
}

int get_vote(string str, mixed tmp)
{
   int i,enc=0;
   mixed tmpaux;

   while( i<sizeof(tmp[2]) && !enc)
   {
      if( tmp[2][i][0] == str )
      {
         tmp[2][i][1] += 1;
         enc = 1;
      }
      i += 1;
   }
   if( tmp[0] == 0 && !enc)
   {
      tmpaux = allocate(2);
      tmpaux[0] = str;
      tmpaux[1] = 0;
      tmp[2] += ({ tmpaux });
   }         
   if( tmp[0] == 1 && !enc)
   {
      write("Wrong vote! Try again.\n");
      return 0;
   }
   vote_data[tmp[1]] = tmp;
   TP->add_property(tmp[1],1);  //Mark him: he voted.
   return 1;
}         
                 
int add_subject(string sub, int limited, string info, string *candidates, 
		int flag1, string *whoflag1, int flag2)
{
   mixed tmp;
   mixed tmpaux;
   int i;
   
   restore_function();
   if( vote_data[sub] )
   { 
      write("That subject is already on votation.\n");
      return 1;
   }
   tmp = allocate(6);
   tmp[0] = limited;
   tmp[1] = info;
   
   if( limited == 1 )   //If there is a finite number of candidates      
   {
      if( !tmp[2] )
         tmp[2] = ({ });
      for (i=0; i<sizeof(candidates); i++)
      {
         tmpaux = allocate(2);
         tmpaux[0]=candidates[i];
         tmpaux[1]=10;
         tmp[2] += ({ tmpaux });
      }
   }
   else
   {
      tmp[2] = ({ });
   } 
   tmp[3] = flag1;
   tmp[4] = ({ });
   for(i=0;i<sizeof(whoflag1); i++)
      tmp[4] += ({ whoflag1[i] });   
   tmp[5] = flag2;      
          
   vote_data[sub] = tmp;      

   write("Added a votation.\n");
   save_function();
   return 1;
}         

int new_votation()
{
   
   string sub, info, *candidates, *whoflag1;
   int limited, flag1, flag2;  

   if(!have_power(TP))
   {
      write("Sorry, you cannot start a new votation.\n");
      return 1;
   }
   write("Introduce the subject of the votation (no whitespaces please): ");
   input_to("new1", sub, limited, info, candidates, flag1, whoflag1, flag2);
   return 1;
}

int new1(string str, string sub, int limited, string info, 
         string *candidates, int flag1, string *whoflag1, int flag2)
{
   if( vote_data[sub] )
   { 
      write("That subject is already on votation.\n");
      return 1;
   }   
   sub = str;
   write("Now you must introduce information about '"+str+"' votation. "+
         "For example: 'We are voting for choosing a guildmaster'.\n");
   write("Info: ");
   input_to("new2", sub, limited, info, candidates, flag1, whoflag1, flag2);
   return 1;
}

int new2(string str, string sub, int limited, string info, 
         string *candidates, int flag1, string *whoflag1, int flag2)
{
   info = str;
   input_to("new3", sub, limited, info, candidates, flag1, whoflag1, flag2);   
   write("Ok, now you must enter a number. Enter '0' if the vote is free, "+
         "or enter '1' if there are some candidates.\n");
   write("Enter the number: ");         
   input_to("new3", sub, limited, info, candidates, flag1, whoflag1, flag2);

   return 1;
}

int new3(string str, string sub, int limited, string info, 
         string *candidates, int flag1, string *whoflag1, int flag2)
{
   if(str != "0" && str != "1")
   {
      write("Sorry, you must enter '0' or '1'.\n");
      return 1;
   }
   limited = to_int(str);
   write("DEBUG: "+sub+"   "+info+"    lim = "+limited+".\n");
   if(limited == 0)
   {
      candidates = ({ });
      write("Now you must introduce another number:\n"+
            "0 -> all the people can vote\n"+
            "1 -> only some races can vote\n"+
            "2 -> only some groups can vote\n"+
            "3 -> only some race-groups can vote\n"+
            "Introduce your choose: ");
      input_to("new5", sub, limited, info, candidates, flag1, whoflag1, flag2);       
   }
   else
   {
      write("Now introduce the list of candidates. Finish with a "+
            "white line.\n");
      candidates = ({ });
      write("Candidate:   ");
      input_to("new4", sub, limited, info, candidates, flag1, whoflag1, flag2);
   }       
   
   return 1;
}

int new4(string str, string sub, int limited, string info, 
         string *candidates, int flag1, string *whoflag1, int flag2)
{   
   if(str == "")
   {
      write("Now you must introduce another number:\n"+
            "0 -> all the people can vote\n"+
            "1 -> only some races can vote\n"+
            "2 -> only some groups can vote\n"+
            "3 -> only some race-groups can vote\n"+
            "Introduce your choose: ");
      input_to("new5", sub, limited, info, candidates, flag1, whoflag1, flag2);         
   }      
   else
   {
      candidates += ({ str });
      write("Candidate:   ");
      input_to("new4", sub, limited, info, candidates, flag1, whoflag1, flag2);
   }
   return 1;
}

int new5(string str, string sub, int limited, string info, 
         string *candidates, int flag1, string *whoflag1, int flag2)
{
   string aux;
   
   flag1 = to_int(str);
   if (flag1 == 0)
   {
      write("\nWe are finishing. The last choose is: \n"+
            "0 -> All the people can vote.\n"+
            "1 -> Only people over 5 days can vote.\n"+
            "x -> Only people over level x can vote.\n"
            "Introduce your choose: ");
      input_to("new7", sub, limited, info, candidates, flag1, whoflag1, flag2);
   }      
   else
   {
      switch(aux)
      { 
         case 1:  aux="races";break;
         case 2:  aux="groups";break;
         default: aux="race-groups";break;
      }
      whoflag1 = ({ });
      write("Ok, you have limited the votation to some "+aux+" only. "+
            "Now you must introduce those "+aux+". Finish with a "+
            "white line.\n"+
            "Only can vote:  ");
      input_to("new6", sub, limited, info, candidates, flag1, whoflag1, flag2);            
   }
   return 1;
}

int new6(string str, string sub, int limited, string info, 
         string *candidates, int flag1, string *whoflag1, int flag2)
{   
   if(str == "")
   {
      write("\nWe are finishing. The last choose is: \n"+
            "0 -> All the people can vote.\n"+
            "1 -> Only people over 5 days can vote.\n"+
            "x -> Only people over level x can vote.\n"+
            "Introduce your choose: ");
      input_to("new7", sub, limited, info, candidates, flag1, whoflag1, flag2);   
   }      
   else
   {
      whoflag1 += ({ str });
      write("Only can vote:   ");
      input_to("new6", sub, limited, info, candidates, flag1, whoflag1, flag2);
   }
   return 1;
}

int new7(string str, string sub, int limited, string info, 
         string *candidates, int flag1, string *whoflag1, int flag2)
{
   flag2 = to_int(str);
   do_resume(sub, limited, info, candidates, flag1, whoflag1, flag2);
   write("Do you want add this votation? (y/n) ");
   input_to("new8", sub, limited, info, candidates, flag1, whoflag1, flag2);   
   return 1;
}

int new8(string str, string sub, int limited, string info, 
         string *candidates, int flag1, string *whoflag1, int flag2)
{
   if(str == "y")
   {
      add_subject(sub, limited, info, candidates, flag1, whoflag1, flag2);
      write("Ok, votation added.\n\n");
   }
   else
      write("Ok, votation not added.\n\n");
      
   return 1;
}

void do_resume(string sub, int limited, string info, string *candidates, 
               int flag1, string *whoflag1, int flag2)
{
   string str="";
   int i;
   
   str += "\n\n\nAdding ";
   str += sub;
   str += " votation \n";
   str += "Information: "+info+".\n";
   if ( limited == 0 )
      str +="Free candidates.\n";
   else
   {
      str +="The candidates are:\n";
      for(i=0;i<sizeof(candidates);i++)
         str += candidates[i]+"\n";
      str += "\n";
   }
   switch(flag1)
   {
      case 1:  str += "Only the following races can vote:\n";
               break;
      case 2:  str += "Only the following groups can vote:\n";
               break;
      case 3:  str += "Only the following race-groups can vote:\n";
               break;
      default: break;
   }
   if( flag1 > 0 )
   {
      for(i=0;i<sizeof(candidates);i++)
         str += whoflag1[i]+"\n";
      str += "\n";
   }
   switch(flag2)
   {
      case 0:  str += "All the people can vote.\n\n";
               break;
      case 1:  str += "Only people over 5 days can vote.\n\n";
      	       break;
      default: str += "Only people over level "+flag2+" can vote.\n\n";
               break;
   }
   tell_object(TP, str);
}

void resume(string str)
{
   mixed tmp;
   int i;
   string *candidates = ({ });
   
   tmp = allocate(6);
   
   tmp = vote_data[str];
   if(!tmp)
   {
      write("Not a valid votation.\n");
      return 1;
   }
   else
   {
      for(i=0;i<sizeof(tmp[2]);i++)
         candidates += ({ (string)tmp[2][i][0] });
      do_resume(str, tmp[0], tmp[1],candidates,tmp[3],tmp[4],tmp[5]);
   }
   return 1;
}
   
   
   
   
   
   



