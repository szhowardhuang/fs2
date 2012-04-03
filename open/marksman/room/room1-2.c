// Room: /u/f/fire/room/room1-2.c
#include <ansi.h>
#include <marksman.h>
inherit ROOM;

void create ()
{
  set ("short", "[32m³¤É³µÀ[2;37;0m");
  set ("long", @LONG
ÄãÕı×ßÔÚÒ»ÌõÊ¯µÀÂ·ÉÏ£¬»Æ³¾¹ö¹öµÄµÀÂ·ÏòÄÏ±±·½ÏòÑÓÉì¶øÈ¥¡£
Â·ÅÔµÄ²İµØÉÏ³¤×ÅÒ»Ğ©²»ÖªÃûµÄÒ°»¨¼°Ò°²İ¡£Äã¿´µ½³¤É³³ÇÀïÈËÀ´ÈË
ÍùÊ®·ÖÈÈÁÒ¡£
LONG);

  set("exits", ([ /* sizeof() == 2 */
"north" : __DIR__"room1-3",
"south" : __DIR__"room1-1",
]));
set("outdoors","/open/marksman");

  setup();
}
