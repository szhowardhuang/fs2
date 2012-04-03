// Room: /u/d/dhk/questsfan/rm12
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
  "westup" : __DIR__"rm13",
  "southdown" : __DIR__"rm18",
  "westdown" : __DIR__"rm19",
  "eastdown" : __DIR__"rm11",
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
  if(who->query_temp("run")!=1 && who->query_temp("run")==8)
  {
   tell_object(who,""WHT"ÕâµÀºÚÉ«µÄÈËÓ°Õâ´ÎÓÖ¼Ó¿ìËÙ¶È³¯¶«±ßÉ½ÏÂ±¼È¥£¬»¹ÊÇ×·°É¡£"NOR"\n");
   who->set_temp("run",1);
   remove_call_out("dhk");
  }
}

