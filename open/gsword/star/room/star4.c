// Room: /u/b/blue/room/star1.c
#include <ansi.h>
inherit ROOM;

void create ()
{
  set ("short", "[1;34mÌìÈ¨Â¥[2;37;0m");
  set ("long", @LONG
ÕâÊÇÆßĞÇËşµÄµÚËÄ²ã, µ±Äã¸Õ×ßµ½´ËÂ¥, Í»È»ÓĞÑÛ¾¦¸Ğµ½Ò»Õó
´ÌÍ´, Ô­À´ÊÇ´Ë´¦µÄ¹âÏß¸ü¼ÓµÄÇ¿ÁÒ, ÁîÄãÔÚ´ËµÄĞİÏ¢ÁËÒ»»á²ÅÂı
ÂıµÄºÃ×ªÆğÀ´, ´ËÊ±ÄãÁ¢¿ÌÍûÏòËÄÖÜ, ¶øÕâµÄÉè¼Æ¸úµÚÈı²ãÂ¥Ò»Ñù
, Ö»²»¹ıÖÜÎ§°Ú·Å×ÅĞÇÖ®×°±¸, Ô­À´ËùÓĞÆßĞÇËşÖĞµÄ×°±¸, ÊÇ´ÓÕâ
Éú²ú³öÀ´µÄ, ¶øÂ¥Ìİ¿ÚÅÔÕ¾µ½Â¥Ö÷, Â¥Ö÷Á³ÉÏ³äÂú×Å¾ëÌ¬, Ô­À´Ëû
¸ÕÔÚĞİÏ¢¾Í±»ÄãµÄ½Å²½Éù³³ĞÑÁË¡£
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "up" : __DIR__"room9.c",
  "out" : __DIR__"room8.c",
]));
  set("light_up", 1);
  set("objects", ([ /* sizeof() == 1 */
  "/open/gsword/star/npc/star4.c" : 1,
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
