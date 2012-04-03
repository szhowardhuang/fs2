// Room: /u/b/blue/room/star1.c
#include <ansi.h>
inherit ROOM;

void create ()
{
  set ("short", "[1;31m¿ªÑôÂ¥[2;37;0m");
  set ("long", @LONG
ÄãÒÑ¾­ÉíÔÚÆßĞÇËşÖĞµÄµÚÈı²ãÁË, ¶ÔÓÚÇ¿ÁÒµÄ¹âÏßÒÑ²»ÔÚ¶Ô
Äã²úÉúÓ°ÏìÁË, ÔÚÇ½±ß, Äã¿´µ½ÁËÒ»¸ö»ğÂ¯, ÓĞÎ»½£Ê¿Õı»Óº¹Èç
ÓêÕıÔÚ´òÔì×Å±øÆ÷, Ô­À´ÆßĞÇËşÖĞËùÓĞ½£Ê¿µÄ½£, ¶¼ÊÇÓÉËûÒ»ÈË
Ëù´òÔìµÄ, µ±ËûÒ»Íûµ½Äã, ÂíÉÏÄÃÆğ·ÅÔÚÒ»ÅÔµÄ½£, ÕòÊØµ½Â¥Ìİ
¿ÚµÄµØ·½, ²»ÈÃÄãÉÃÈë£®
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "up" : __DIR__"room7.c",
  "out" : __DIR__"room6.c",
]));
  set("light_up", 1);
  set("objects", ([ /* sizeof() == 1 */
  "/open/gsword/star/npc/star5.c" : 1,
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
