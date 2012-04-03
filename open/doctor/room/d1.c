#include <room.h>
#include <ansi.h>
inherit ROOM;
void create ()
{
        set("short","µÀÂ·");
  set ("long", @LONG
ÄãÕı×ßÔÚÕâÌõµÀÂ·ÉÏ£¬Ò»Â·×ßÀ´£¬ÈËÑÌÔ½À´Ô½Ï¡ÉÙ£¬³æÉùÄñÃùÇå´àÔÃ¶ú£¬
Â·±ß³¤ÂúÁËĞí¶àÕä¹óµÄ²İÒ©£¬×ĞÏ¸Íù±±Ì÷Íû£¬ÒÀÏ¡¿ÉÒÔ¿´µ½[1;33m¡¾ÒøÕëÃÅ¡¿[0mÈı¸ö´ó
×Ö ¡£

LONG);

  set("light_up", 1);
        set("outdoors", 1);
        set("objects",([
        ]));
  set("exits", ([ /* sizeof() == 2 */
      "north" : __DIR__"d2",
      "south" :"/open/port/room/r3-4.c",
      ]));
  setup();
}


