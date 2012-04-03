// Room: /u/d/dhk/questsfan/rm10
inherit ROOM;
#include <ansi.h>
void create ()
{
  set ("short", "[1;33mÈÕÈÕ[1;32m¸ÊÁØ[0m");
  set ("long", @LONG
Õâ¶ùÊÇÒ»×ùÊ÷ÖÖ·±ÔÓ£¬¸ß´óµÄÊ÷ÁÖ¡£µ«ÊÇÕâ×ùÊ÷ÁÖ×î´óµÄÌØÉ«
È·ÊÇÃ»ÓÐÒ»¿ÌÍ£Ö¹µÄÐ¡Óê£¬ËùÒÔÕâ×ùÊ÷ÁÖµÄ±ð³Æ¾Í½Ð£¢ÈÕÈÕ¸ÊÁØ¡å
¡£´«ËµÕâ¶ùÈÕÈÕ²»Í£µÄÓêÊÇÒòÎªÓêÉñÓÐÒ»´ÎÔÚ´ËµØÐÝÏ¢£¬ÒòÎªÌ«ÈÈ
ËùÒÔÈÃ´ËµØÏÂÒ»³¡Ð¡Óê£¬µ«ÊÇËûÐÝÏ¢ÍêÈ´´Ò´ÒÀëÈ¥£¬¾¹Ã»ÓÐÈÃÕâ³¡
ÓêÍ£Ö¹¡£ËùÒÔ´Ó´ËÕâÀïµÄÓê±ãÃ»Í£¹ý¡£

LONG);

  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/man" : 2,
]));
  set("outdoors", "/u/d");
  set("exits", ([ /* sizeof() == 4 */
  "westdown" : __DIR__"rm10",
  "east" : __DIR__"rm25",
  "westup" : __DIR__"rm12",
  "west" : __DIR__"rm18",
]));

  setup();
}
void init()
{
    call_out("dhk",1,this_player());
}
void dhk(object who)
{
  if(who->query_temp("run")!=2 && who->query_temp("run")==1)
  {
   tell_object(who,""WHT"ÕâµÀºÚÉ«µÄÈËÓ°ÓÖ¿ìËÙÍùÎ÷±ßÀëÈ¥£¬ÉíÐÎÖ®¿ì·ËÒÄËùË¼¡£"NOR"\n");
   who->set_temp("run",2);
   remove_call_out("dhk");
  }
}

