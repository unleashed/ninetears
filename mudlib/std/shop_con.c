/* 
 * Taniwha 1995
 * Special container for item-shops that things cannot be taken from
 *
 */
inherit "/std/container.c";

int test_remove(object ob,int flag)
{
   return 0;
}
