#include <ansi.h>
inherit ROOM;
void create ()
{
  set ("short", "[0;1;31m¡õ[1m¡õ[1m¡õ[1ms[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1mt[0m");
	set( "build", 18 );
  set ("long", @LONG
ÕâÀïÊÇ½á½çµÄ±ßÔµ, ÕâÀïµÄÄ§·¨Á¦¾ÍÃ»ÄÇÃ´µÄÇ¿ÁÒÁË, ÌìºòÎÂ¶È¸úÆ½
³£Ò»Ñù, µ«»¹Î´Àë¿ª»Ã½çµÄ¿ØÖÆ·¶Î§, ÕâÀïÓĞÒ»¸ùÖ±´ïÔÆ¼Ê, Ê®·ÖÆæ¹ÖµÄ
¾ŞÊ¯, Õâ¸öÒ²ÊÇÄÃÀ´¹®¹Ì½á½çÓÃµÄ°É! 
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "southeast" : __DIR__"f-15.c",
  "east" : __DIR__"f-13.c",
]));
  set("objects", ([ /* sizeof() == 1 */
  "/open/fire-hole/npc/fire-turtle.c" : 1,
]));
  set("outdoors", 1);

  setup();
}
