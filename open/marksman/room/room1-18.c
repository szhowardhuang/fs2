// Room: /u/f/fire/room/room1-18.c
inherit ROOM;
#include <ansi.h>
#include <marksman.h>

void create ()
{
  set ("short", "[1;37mÌìÁú¿ÍÕ»¶şÂ¥[2;37;0m");
  set ("long", @LONG
ÕâÀïÊÇÌìÁú¿ÍÕ»µÄ¶şÂ¥£¬¸ø¹ıÂ·µÄÂÃ¿ÍÃÇĞªĞª½ÅÓÃµÄ¡£ÔÚÕâÀïÄã
¿ÉÒÔÓöµ½ÎäÁÖÈËÊ¿¡£¿¿´°Ì¨µÄµØ·½°ÚÁËÔ¼ÄªÆß¡¢°Ë¸±×ÀÒÎ£¬²ÁµÃ¹âÁÁ
¼ø¡£
LONG);

  set("objects", ([ /* sizeof() == 1 */
  "/open/marksman/npc/small-two" : 1,
]));
  set("exits", ([ /* sizeof() == 2 */
  "down" : __DIR__"room1-17",
  "enter" : __DIR__"room3-1",
]));

  setup();
}
