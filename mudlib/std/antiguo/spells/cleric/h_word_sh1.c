object my_player, shadow;
int level, save, roll, doomed;
string guild;

void setshadow(object ob, object caster)
{
  shadow(ob,1);
  my_player = ob;
  if(my_player == caster)
    return;
  level = (int)ob->query_level();
  guild = (string)ob->query_guild_name();
  save = 15 - (level / 3);
  roll = random(19) + 1;
  if(level < 13 && !(guild == "hokemj" || guild == "taniwha"))
     doomed = 1;
  else
  if(roll < save)
     doomed = 1;
}

void destruct_hw1_shadow()
{
  if(doomed)
  {
    switch(level)
    {
//      case 0..5:
      case 0..8:
        tell_object(my_player,
         "Estas todavia aturdido y confundido tras haber sido expuesto a "
         "tanto poder.\n");
        shadow = clone_object("/std/spells/cleric/h_word_sh3.c");
        shadow->setshadow(my_player);
        break;
/*      case 6..8:
        tell_object(my_player,
          "You are still dazed and confused after being exposed to such "
          "power.\n");
        shadow = clone_object("/std/spells/cleric/h_word_sh3.c");
        shadow->setshadow(my_player);
       break;*/
      case 9..12:
        tell_object(my_player,
         "As your head slowly begins to clear, you find yourself unable "
         "to hear the world around you.\n");
        shadow = clone_object("/std/spells/cleric/h_word_sh2.c");
        shadow->setshadow(my_player);
        break;
      default:
        tell_object(my_player, 
         "Estas todavia aturdido y confundido tras haber sido expuesto "
         "a tanto poder.\n");
        shadow = clone_object("/std/spells/cleric/h_word_sh3.c");
        shadow->setshadow(my_player);
        break;
    }
  }
  else
  {
    tell_object(my_player, 
      "Vuelves a pensar con claridad, sacudiendote las telaranyas despues de haber sido golpeado por tanto poder.\n");
  }
  destruct(this_object());
}

int action_check(string str)
{
  tell_object(my_player, "Estas demasiado aturdido para hacer algo.\n");
  return my_player->action_check("");
}
