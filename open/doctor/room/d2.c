#include <ansi.h>
inherit ROOM;
void create ()
{
        set("short","µÀÂ·");
  set ("long", @LONG
ÄãÕı×ßÔÚÕâÌõµÀÂ·ÉÏ£¬Ò»Â·×ßÀ´£¬Ö»ÓĞ¿´µ½¼¸¸öéÔ·ò£¬±³×ÅÒ»µ£µ£µÄ¸É
²Ä£¬²½ĞĞ¶ø¹ı¡£Â·±ß³¤ÂúÁËĞí¶àÕä¹óµÄ²İÒ©£¬[1;33m¡¾ ÒøÕëÃÅ ¡¿[0mÈı¸ö´ó×ÖÔ½À´Ô½
Ã÷ÏÔ£¬ÓÉÓÚÇóÒ½ĞÄÇĞ£¬ÄãµÄ½Å²½ÓÖ²»Öª²»¾õµØ¼Ó¿ìÁË¡£

LONG);

  set("light_up", 1);
        set("outdoors", 1);
        set("objects",([
        ]));
  set("exits", ([ /* sizeof() == 2 */
      "south" : __DIR__"d1",
      "north" : __DIR__"d3",
      ]));
  setup();
}


