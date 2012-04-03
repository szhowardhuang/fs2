// Room: /u/f/fire/room/room1-33
#include <ansi.h>
#include <marksman.h>
inherit ROOM;

void create ()
{
  set ("short", "[32mÃñ·¿[2;37;0m");
  set ("long", @LONG
¼ò¼òÂªÂªµÄ×°äê£¬Æ½Æ½·²·²µÄĞ¡·¿Îİ¡£É¢·¢³öÆ½·²ºÍÆ½µÄÆøÏ¢£¬
¿ÉÇ×¿É°®µÄ³¤É³ÃñÖÚ£¬ÕıÔÚÅ¬Á¦µÄ´´ÔìÃÀºÃµÄ¼ÒÍ¥¡£ÀÏÆÅÆÅÕıÔÚ°ï×Å
Îª¼ÒÀïµÄÈËÖó¶«¶«¡£
LONG);

  set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"room1-10",
]));
  set("objects", ([ /* sizeof() == 2 */
C_NPC"/oldwoman" : 1,
C_NPC"/oldman" : 1,
]));

  setup();
}
