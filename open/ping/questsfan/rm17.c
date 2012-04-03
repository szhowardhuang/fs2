// Room: /u/d/dhk/questsfan/rm17
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

  set("exits", ([ /* sizeof() == 6 */
  "westup" : __DIR__"rm20",
  "westdown" : __DIR__"rm16",
  "southdown" : __DIR__"rm9",
  "northup" : __DIR__"rm19",
  "eastdown" : __DIR__"rm10",
  "eastup" : __DIR__"rm18",
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
  if(who->query_temp("run")!=4 && who->query_temp("run")==3)
  {
tell_object(who,""WHT"ÕâµÀºÚÉ«µÄÈËÓ°ÓÖ¿ìËÙÍùÎ÷±ßÉ½ÉÏ±¼È¥£¬ºÃÏñÓÐÒâÒªÓëÄãÍæ×½ÃÔ²Ø¡£"NOR"\n");
   who->set_temp("run",4);
   remove_call_out("dhk");
  }
}

