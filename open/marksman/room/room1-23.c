#include <room.h>
inherit ROOM;
#include <marksman.h>
#include <ansi.h>
#include <marksman.h>
void create ()
{
  set ("short", "[1;33mÇ¿ÕßÖ®µÀ[2;37;0m");
  set ("long", @LONG
ÄãÏÖÔÚÕıÕ¾ÔÚ½«¾ü¸®£¬´ËµØÆøÌ¬ÍòÇ§£¬Ô¶½ü¸ßµÍÍûÖ®£¬¶¼ÓĞ²»Í¬
µÄÆøÏó£¬ÆäÉè¼Æ¿ÉÎ½ÇÉ¶áÌì¹¤¡£ËùÓĞµñ¿ÌµÄÄñÊŞ²İÄ¾£¬¶¼ÊÇÔ¶´ÓÔ¶´¦
ÇëÀ´µÄ´óÊ¦Å»ĞÄÁ¤ÑªÖ®×÷£¬Õ¾ÔÚ´ËµØ£¬²»ÃâÒªÔŞÌ¾ÈËÀà¹¤¼£Ö®Î°´ó¡£
LONG);

  set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"room1-26.c",
  "north" : __DIR__"room1-24.c",
  "out" : __DIR__"room1-22.c",
  "east" : __DIR__"room1-25.c",
]));
  set("item_desc", ([ /* sizeof() == 1 */
  "out" : (: look_door,     "out" :),
]));
  set("objects", ([ /* sizeof() == 1 */
C_NPC"/marker" : 1,
]));
  set("light_up", 1);

  setup();
}
