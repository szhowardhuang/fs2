// Room: /u/f/fire/room/room1-34.c
#include <ansi.h>
#include <marksman.h>
inherit ROOM;

void create ()
{
  set ("short", "[32m³¤É³µÀ[2;37;0m");
  set ("long", @LONG
ÎÂÅ¯µÄ·ç¶ùÏò×ÅÎÒµÄÁ³¼Õ´µÆğ£¬³¤É³³ÇÀïµÄÈËÃÇËÆºõÔÚÅ¬Á¦Ã¦Âµ
×Å¹¤×÷¡£Äã¿´µ½Ò»ÈºÎäÁÖÈËÊ¿ÔÚ³¤É³³ÇÄÚËÄ´¦×ß¶¯£¬ºÍÆ½µÄ³¤É³³ÇËÆ
ºõÃ»ÓĞÈÎºÎ±©Á¦µÄĞĞ¶¯³öÏÖ¡£
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"room1-35.c",
  "east" : __DIR__"room1-3",
]));
set("outdoors","/open/marksman");

  setup();
}
