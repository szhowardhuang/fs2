// Room: /u/b/blue/room/star1.c
#include <ansi.h>
inherit ROOM;

void create ()
{
  set ("short", "[1;36mÑş¹âÂ¥[2;37;0m");
  set ("long", @LONG
ÕâÊÇÆßĞÇËşÖĞµÄµÚÒ»²ãÂ¥, ËşÖĞ³ä³âÎŞÊıìÅÀöµÄ¹âÏß, 
ÁîÄã×ßµ½´ËÂ¥, Ë²¼äÑÛ¾¦Õö²»¿ªÀ´, ¹ıÁË²»¾Ã, ÑÛ¾¦½¥½¥
µÄÊÊÓ¦ÁËËÄÖÜµÄÁÁ¶È, Ö»¼ûÑÛÇ°Õ¾×ÅÒ»Î»ÍşÑÏµÄ½£Ê¿, Áî
ÄãĞÄÉúÎ·¾å, ÈÃÄãÓĞµã²»¸ÒÏòÇ°ÂõÈ¥£®
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "up" : __DIR__"room3.c",
  "out" : __DIR__"room2.c",
]));
  set("objects", ([ /* sizeof() == 1 */
  "/open/gsword/star/npc/star7.c" : 1,
]));
  set("light_up", 1);

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
