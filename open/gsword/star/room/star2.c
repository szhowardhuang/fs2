// Room: /u/b/blue/room/star1.c
#include <ansi.h>
inherit ROOM;

void create ()
{
  set ("short", "[1;33mÓñºâÂ¥[2;37;0m");
  set ("long", @LONG
ÄãÒÑ¾­µ½´ïµÚ¶ş²ã, ¶øËşÖĞµÄÁÁ¶ÈÒÑ¾­Ó°Ïì²»µ½ÄãÁË, 
ÍùÖÜÎ§Ò»Íû, ²Å·¢¾õµ½ÕâÀïµÄ°ÚÉèÊ®·ÖµÄÆ¯ÁÁ, °ÚÖÃ×ÅĞíĞí
¶à¶àµÄÎäÆ÷, ÒÔ¼°Ğí¶àµÄ»¨Æ¿¼°°ÚÊÎ, ¶øÂ¥Ö÷ÕıÕ¾ÔÚÏòÉÏµÄ
Â¥Ìİ¿ÚÇ°, ¾²¾²µÄÖ´ĞĞ×Ô¼ºµÄÖ°Îñ, µ«ÑÛÖĞÈÔÓĞ×ÅÒ»¹ÉÄ®Âä
µÄ±íÇé, ¿ÉÄÜÓÉÓÚ³¤ÄêÖ»ÄÜ´ôÔÚÕâ°É¡£
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "up" : __DIR__"room5.c",
  "out" : __DIR__"room4.c",
]));
  set("light_up", 1);
  set("objects", ([ /* sizeof() == 1 */
  "/open/gsword/star/npc/star6.c" : 1,
]));

  setup();
}
int valid_leave(object me, string dir)
{
if( dir=="up" && present("starman",environment(me)))
    if(!me->query_temp("allow_read",1))
   return notify_fail("ÄãÒÔÎªÄãÄÜ»îµÃ¹ıÈ¥Âğ??"
+RANK_D->query_respect(me)+"ÄãÈ¥ËÀ°É!\n");
return ::valid_leave(me,dir);
}
