// Room: /u/b/blue/room/star1.c
#include <ansi.h>
inherit ROOM;

void create ()
{
  set ("short", "[1;32mÌì»úÂ¥[2;37;0m");
  set ("long", @LONG
ÕâÊÇÆßĞÇËşÖĞµÄµÚÎå²ãÂ¥, ¸Õ²½Èë´ËµØ, Ò»Õó´Ì±ÇµÄÒ©Î¶³å
½øÁËÄãµÄ±Ç×Ó, ÁîÄãĞÄÖĞÓĞ¹É¶ñĞÄµÄ¸Ğ¾õ, ÄãÂíÉÏÏòËÄÖÜ¹ÛÍû,
·¢¾õËÄÖÜ°ÚÂúÁËÒ©²Ä, ¶øÔÚÂ¥ÖĞÑë·ÅÖÃ×Åµ¤Â¯, Ô­À´´ËÂ¥µÄÂ¥Ö÷
Ï²»¶ÑĞ¾¿Ò½Êõ, µ±Ëû¿´ÄãÒ»ÉÏÀ´, ÂíÉÏ¶ñºİºİµÄµÉ×ÅÄã, ÉîÅÂÄã
½«ËûÁ¶ÖÆµÄµ¤Ò©¸øÍµÁË¡£
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "up" : __DIR__"room11.c",
  "out" : __DIR__"room10.c",
]));
  set("light_up", 1);
  set("objects", ([ /* sizeof() == 1 */
  "/open/gsword/star/npc/star1.c" : 1,
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
