// cold.c Desigh by Chan
#include <combat.h>
inherit F_CLEAN_UP;
int update_condition(object me, int duration)
{
  if( !living(me) )
   {
     message("vision", me->name() + "[1;36mÉíÉÏËùÊÜ¶³ÉËÉÐÎ´È¬Óú, Ê¹º®ÆøÔÚÉíÌåÖ®ÖÐÎÞ·¨Çý³öÁË!![0m\n",
     environment(me), me);
   }
  else
  if( duration > 10)
   {
     tell_object(me, "[1;37mÄãÊÜµÄ¶³ÉËÊ®·ÖÑÏÖØ, Ê¹´«µ¼Éñ¾­ÊÜ×èÈÃËÄÖ«Ã»ÓÐÈÎºÎÖª¾õ.[0m\n");
     message("vision", me->name() + "[36mÈ«ÉíÊÜµ½º®ÆøËùÇÖ,º®°ßµãµã,Ê¹Ö®µ¤ÌïÄÚµÄÄÚÏ¢ÎÞ·¨ÔË×ªÈç³£.[0m \n",
     environment(me), me);
     me->receive_wound("kee", 300);
     me->receive_damage("kee", 300);
     if(me->is_fighting())
     me->start_busy(1);
     if( (int)me->query("food")>=50 )
     me->add("food", -50);
     else
     me->set("food", 0);
    }
    else
    if( duration > 5 )
     {
      tell_object(me, "[1;37mÄãÄ¬ÔËÄÚ¹¦½«º®ÆøÂýÂý±Æ³ö,¸Ð¾õÉíÉÏµÄ¶³ÉË¼õÇá²»ÉÙ,Ò²ÂýÂýÓÐÑªÉ«ÁË.[0m \n");
      message("vision", me->name() + "[1;36mËäÈ»È«ÉíËÄÖ«ÈÔÎÞÖª¾õ,µ«ÄÚÏ¢¼ºÂýÂýÄÜÔË×ªÈç³£[0m\n",
      environment(me), me);
      if(me->is_fighting())
      me->start_busy(1);
      me->receive_wound("kee", 200);
      me->receive_damage("kee",200);
      if( (int)me->query("food")>=30 )
      me->add("food", -30);
      else
      me->set("food", 0);
      }
      else
      if( duration > 1 )
      {
       tell_object(me, "[1;37mÄãÔËÆðÄÚ¹¦½«ÄãÉíÉÏµÄº®ÆøÍêÈ«Ïû³ýÁË,ÄÚÏ¢»Ö¸´³ÉÍù³£Ò»ÑùÁË[0m. \n");
       message("vision", me->name() + "[36mËäÈ»º®ÆøÏû³ýÁË,µ«ÉíÉÏ»¹ÁôÏÂº®ÆøËùÇÖµÄºÛ¼£[0m. \n",
       environment(me), me);
       me->receive_wound("kee", 100);
       me->receive_damage("kee", 100);
       if( (int)me->query("food")>=10 )
       me->add("food", -10);
       else
       me->set("food", 0);
      }
  me->apply_condition("cold", duration - 1);
  COMBAT_D->report_status(me);
  if( duration < 1 )
  return 0;
  return 1;
}
