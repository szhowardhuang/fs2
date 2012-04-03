// Room: /u/d/dhk/questsfan/rm14
inherit ROOM;
#include <ansi.h>
void create ()
{
  set ("short", "[0;32mÔÆÎíËÉÁÖ[2;37;0m");
  set ("long", @LONG
ËÉÁÖ±ÎÈÕ¡¢ÔÆÎíÃÔÃÉ¡¢ËÉ¹ûÂúµØ£¬Õâ¶ù×îÆæ¹ÖµÄÊÇÒ»Æ¬´óËÉÁÖ
¾¹Ã»¿´µ½°ëÖê¾¥¸É£¬¸ñÍâÌØ±ð¡£²»Ê±ÓÐ¼¸Ö»º±¼ûµÄÁùÎ²ËÉÊó¿ñ±¼¶ø
¹ý£¬²»È»¾ÍÊÇÀ¥³æµÄÃù½ÐÉù£¬ÌØ±ðµÄÊÇ ­ÃÇµÄÒ»ÆðÍ»È»µÄ´óÃù£¬È»
ºóÔÙÒ»ÆðµÄ°²¾²£¬ÄÇÒ»ÆðÍ»·¢µÄÃù½ÐÉùÕæÊÇÏàµ±ÁîÈËÕðº³µÄ¡£

LONG);

  set("exits", ([ /* sizeof() == 4 */
  "westdown" : __DIR__"rm15",
  "southdown" : __DIR__"rm20",
  "eastdown" : __DIR__"rm19",
  "eastup" : __DIR__"rm13",
]));
  set("outdoors", "/u/d");

  setup();
}
void init()
{
    call_out("dhk",1,this_player());
}
void dhk(object who)
{
  if(who->query_temp("run")!=7 && who->query_temp("run")==6)
  {
   tell_object(who,""WHT"×·ÁËÕâÃ´¾ÃÖÕÓÚÈÏ³ö´ËÈËÉí·¨¾¹ÊÇ"HIY"Áè²¨Î¢²½"NOR+WHT"£¬ÕâµÀºÚÉ«µÄÈËÓ°Õâ´ÎÓÖ³¯¶«±ßÉ½ÉÏ±¼È¥£¬»¹ÊÇ×·°É¡£"NOR"\n");
   who->set_temp("run",7);
   remove_call_out("dhk");
  }
}

