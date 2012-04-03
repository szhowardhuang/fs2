// Room: /u/f/fire/room/room1-26.c
inherit ROOM;
#include <ansi.h>
#include <marksman.h>
void create ()
{
  set ("short", "[1;33mÇ¿ÕßÖ®µÀ[2;37;0m");
  set ("long", @LONG
Ò»ÌõÓÃ½à°×ÈçÑ©µÄÊ¯×©ËùÆÌËùµÄ×ßµÀ£¬Á½ÅÔµÄ»¨Ô°£¬Ò»ÑÛÍûÈ¥½Ô
ÊÇ¶ä¶ä½¿ÀöµÄ»¨¶ù£¬±ÇÖĞËùÎÅµ½µÄ¾¡ÊÇ·Ò·¼µÄÆøÏ¢£¬×óÓÒÁ½ÅÔµÄÖù×Ó
µñ¿Ì×ÅÃÀÀöµÄÎÆÂ·£¬Î§ÈÆÖù×ÓµÄÇ¾Ş±¿ªÂúÁËîÎhµÄ»¨¶ä¡£
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"room1-28.c",
  "east" : __DIR__"room1-23",
]));
  set("objects", ([ /* sizeof() == 1 */
C_NPC"/bowman" : 2,
]));

  setup();
}
