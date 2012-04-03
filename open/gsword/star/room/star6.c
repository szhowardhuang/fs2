// Room: /u/b/blue/room/star1.c
#include <ansi.h>
inherit ROOM;

void create ()
{
  set ("short", "[1;35mÌìè¯Â¥[2;37;0m");
  set ("long", @LONG
ÕâÊÇÆßĞÇËşÖĞµÄµÚÁù²ãÂ¥, µ½´ïÕâÀï, ÄãÒ»¹É¾ëÒâÍ»È»ÆğÀ´,
ÁîÄãÓĞĞÄÓÚ¶øÁ¦²»×ãµÄ¸Ğ¾õ, ĞÄÖĞÓĞÒ»Ë¿Ë¿Ïë·ÅÆúµÄ¸Ğ¾õ, Í»È»
Ò»ÕóĞ¦Éù, Ô­À´ÊÇÂ¥Ö÷µÄĞ¦Éù, ÓÉÓÚËû¸ÕÁìÎòµ½¸üÒ»²ãµÄÎäÑ§,
¿´µ½ÄãÀ´µ½´ËµØ, ÂíÉÏÅÜµ½ÄãµÄÉí±ß, ÑûÄãÇĞ´è¡£
LONG);

  set("exits", ([ /* sizeof() == 2 */
     "up" : "/open/mogi/forest/entrance",
  "out" : __DIR__"room12.c",
]));
  set("light_up", 1);
  set("objects", ([ /* sizeof() == 1 */
  "/open/gsword/star/npc/star3.c" : 1,
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
