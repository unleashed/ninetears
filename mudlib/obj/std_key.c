//  This is the standard key object.  Inherit but don't
//  rewrite it.  It should be functional for locks
//  as of 3.23.96.  [Piper]

inherit "/std/item.c";

mapping key_list;
object locd_ob;
int key_dest = 0;

varargs int unlock_box_part2(string chest, object ob2);
string real_filename(object ob);
int check_key_dest(object key);

void setup()
{
  set_name("key");
  set_main_plural("keys");
  set_short("Basic key");
  set_long("\n Basic Key\n\n"
     "     This is just an ordinary, simple metal key.\n\n");

  set_weight(1);
  set_value(100);
}

void init()
{
  add_action("do_unlock","unlock");
//  add_action("do_relock","relock");
  ::init();
}

//Need a method to unlock said doors and such... hmm bulky is this way...
//      This is the same method and design as pick_lock.c  [Piper]

int do_unlock(string locd_ob)
{
  int i;
  object ob = this_player();
  string *direcs = environment(ob)->query_direc();
  
  for(i=0; i<sizeof(direcs); i++)
  {
   if(locd_ob == direcs[i])
   {
    this_object()->unlock_door(locd_ob);
    return(1);
   }
  }
  this_object()->unlock_chest(locd_ob);
  return(1);
}

int set_key_id(string filename, mixed *direcs)
{
  int i;

  if((!filename)||(sizeof(direcs) == 0)) { return(0); }

  if(!mappingp(key_list)) { key_list = ([ ]); }

  key_list[filename] = direcs + ({ });

  return(1);
}


varargs int query_key_ident(string direc, object locd_ob)
{
  int index;
  string filename;
  mixed *key_id_list;
  object ob = this_player();


  if(!locd_ob)
    filename = real_filename(environment(ob));

  if(locd_ob)
    filename = real_filename(locd_ob);


  if(!key_list[filename]) { return(0); }

  key_id_list = key_list[filename];

  if(member_array(direc, key_id_list) == -1) { return(0); }
    
  return(1);
}

int unlock_door(string direc)
{
  int lock_str,lock_dir;
  string lock_type,key_ident;
  object ob;

  ob = this_player();
  lock_str = environment(ob)->query_lock_str(direc);
  lock_dir = environment(ob)->query_lock_dir(direc);
  lock_type = environment(ob)->query_lock_type(direc);
  key_ident = this_object()->query_key_ident(direc,environment(ob));

  if(lock_dir == 0)
  {
    tell_object(ob,"\n  The key doesn't seem to work very well"
                   " with that.\n\n");
    return(1);
  }
 
  if(((string)lock_type != "tumb")&&((string)lock_type != "tumb2"))
  {
    tell_object(ob,"\n  This lock doesn't seem to be designed to"
                   " be unlocked with a key.\n\n");
    return(1);
  }

  if(lock_str == 0)
  {
    tell_object(ob,"\n  Why unlock that which was never locked in"
                   " the first place.\n\n");
    return(1);
  }

  if(key_ident == 0)
  {
    tell_object(ob,"\n  You fumble around with the lock soon realizing"
                   " that this key was not meant for this lock.\n\n");
    return(1);
  }
  
  if((key_ident != 0) && (lock_dir != 0))
  {
    tell_object(ob,"\n  You deftly slip the key into the lock, clicking"
                   " it home, with a simple turn the lock is"
                   " vanquished.\n\n");
    environment(ob)->remove_lock(direc);
    check_key_dest(this_object());
    return(1);
  }

  tell_object(ob,"\n  What exactly are you trying to do?\n\n");
  return(1);
}

int unlock_chest(string chest)
{
  int i,j;
  object ob,*olist,*olist2;

  ob = this_player();
  olist = all_inventory(environment(ob));
  olist2 = all_inventory(ob);

  for(i=0; i<sizeof(olist); i++)
  {
   if((string)olist[i]->query_name() == chest)
   {
    if(olist[i]->check_lock(chest) == 0)
    {
     int k;
     int lnum = olist[i]->query_num_locks();
     mixed *lock_list = olist[i]->query_lock_list();

     printf("\n%s%d%s","  It seems that there are ",lnum," locks.");
     printf("\n%s","  Which lock do you want to pick:");
     for(k=0; k<sizeof(lock_list); k++)
     {
      printf("\n%s%s","       ",(string)lock_list[k]);
     }
     printf("\n%s\n","  Pick one of the above.  ");
     locd_ob = olist[i];
     input_to("unlock_box_part2");
     return(1);
    }
    unlock_box_part2(chest,olist[i]);
    return(1); 
   }
  }

  for(i=0; i<sizeof(olist); i++)
  {
   if((string)olist[i]->query_name() == chest)
   {
    if(olist2[i]->check_lock(chest) == 0)
    {
     int k;
     int lnum = olist2[i]->query_num_locks();
     mixed *lock_list = olist2[i]->query_lock_list();

     printf("\n%s%d%s","  It seems that there are ",lnum," locks.");
     printf("\n%s","  Which lock do you want to pick:");
     for(k=0; k<sizeof(lock_list); k++)
     {
      printf("\n%s%s","       ",(string)lock_list[k]);
     }
     printf("\n%s\n","  Pick one of the above.  ");
     locd_ob = olist2[i];
     input_to("unlock_box_part2");
     return(1);
    }
    unlock_box_part2(chest,olist2[i]);
    return(1); 
   }
  }
  unlock_box_part2(chest);
  return(1);
}


varargs int unlock_box_part2(string chest, object ob2)
{
  int lock_str,key_ident;
  string lock_type;
  object ob;

  ob = this_player();

  if((locd_ob)&&(!ob2)) { ob2 = locd_ob; }

  if((ob2) && (ob2->check_lock(chest) == 0))
  {
    tell_object(ob,"\n  The key doesn't seem to work very well"
                   " with that.\n\n");
    return(1);      
  }
 
  if((ob2) && (ob2->check_lock(chest) != 0))
  {
    lock_str = ob2->query_lock_str(chest);
    lock_type = ob2->query_ltype(chest);
    key_ident = query_key_ident(chest,ob2);
  }

  if((lock_type != "tumb")&&(lock_type != "tumb2"))
  {
    tell_object(ob,"\n  This lock doesn't seem to be designed to"
                   " be unlocked with a key.\n\n");
    return(1);
  }

  if(lock_str == 0)
  {
    tell_object(ob,"\n  Why unlock that which was never locked in"
                   " the first place.\n\n");
    return(1);
  }

  if(key_ident == 0)
  {
    tell_object(ob,"\n  You fumble around with the lock soon realizing"
                   " that this key was not meant for this lock.\n\n");
    return(1);
  }
  
  if((key_ident != 0) && (lock_str != 0))
  {
    tell_object(ob,"\n  You deftly slip the key into the lock, clicking"
                   " it home, with a simple turn the lock is"
                   " vanquished.\n\n");
    ob2->remove_lock(chest);
    check_key_dest(this_object());
    return(1);
  }

  tell_object(ob,"\n  What exactly are you trying to do?\n\n");
  return(1);
}   

string real_filename(object ob)
{
  string s;
  int i;

  if(sscanf(file_name(ob), "%s#%d",s,i) != 2)
    return file_name(ob);

  printf("%O",s);
  return s;
}

int check_key_dest(object key)
{
  if(key_dest == 0)
    return(1);
  else
  {
    key->dest_me();
    write("\n  The key breaks in your hand.\n\n");
    return(1);
  }
}

int dest_key()
{
  key_dest = 1;
  return(1);
}
