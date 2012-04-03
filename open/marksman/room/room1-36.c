// Room: /u/f/fire/room/room1-36.c
inherit ROOM;
#include <ansi.h>
#include <marksman.h>

void create ()
{
  set ("short", "[32mÃñ·¿[2;37;0m");
  set ("long", @LONG
ÕâÒ»¼äÃñ·¿ºÍÆäËûµÄ·¿×Ó²¢Ã»ÓĞÊ²Ã´²»Í¬µÄµØ·½¡£ÄãËÆºõ¿ÉÒÔ¸Ğ
¾õµ½·¿¼äÀï¶¼³äÂú×ÅÊ³ÎïµÄÏãÎ¶£¬Ê¹Äã²»½ûÁ÷ÏÂÒ»µÎµÎµÄ¿ÚË®£¬¸Ğ¾õ
ºÃ¶ñĞÄ¡£
LONG);

  set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"room1-35",
]));
  set("objects", ([ /* sizeof() == 2 */
C_NPC"/woman" : 1,
C_NPC"/oldwoman" : 1,
]));

  setup();
}
