// Original from who knows.
// Fixed various logic bugs and some output quarks : Radix - Mar 16, 97

nomask varargs string pretty_time(int tim, int len)
{
  int num;
  string *bits;
  string tmp;

  if(!len)
    len = 99999;

  bits = ({ });
  if (tim >= 60*60*24 && sizeof(bits) < len)
    bits += ({ (num=tim/(60*60*24))+" day"+(num==1?"":"s") });
  if (tim >= 60*60 && tim%(60*60*24) && sizeof(bits) < len)
    bits += ({ (num=(tim/(60*60))%24)+" hour"+(num==1?"":"s") });
  if (tim >= 60 && tim%(60*60) && sizeof(bits) <len)
    bits += ({ (num=(tim/60)%60)+" minute"+(num==1?"":"s") });
  if (tim%60 && sizeof(bits) <len)
    bits += ({ (num=tim%60)+" second"+(num==1?"":"s") });

  for(len =0; len<sizeof(bits); len++)
    if(sscanf(bits[len],"%d %s", num, tmp) == 2 && num == 0)
       bits[len] = 0;

  return implode(bits, ", ");
}
