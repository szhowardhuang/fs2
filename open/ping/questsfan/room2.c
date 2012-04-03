// Room: /u/d/dhk/questsfan/room2
inherit ROOM;
#include <ansi.h>
void create ()
{
  set ("short", "[0;36mÃÜµÀ[0m");
  set ("long", @LONG
ËÄÖÜºÚ²»À­¼¸µÄÄã»Ğã±µÄ×ßÔÚ²»ÖªÓĞ¶à³¤µÄÍ¨µÀÖĞ£¬
¶øÇÒÃÖÂş×ÅÒ»¹ÉËÀÀÏÊóºÍ³æÊ¬µÄ¶ñ³ô£¬ÏÔÊ¾´ËµØÒÑĞí¾ÃÎ´
ÓĞÈËÍ¨ĞĞÁË¡£
LONG);

  set("no_transmit", 1);
  set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"room3",
  "east" : __DIR__"room1",
]));

  setup();
}
