// Room: /open/snow/room/godrom1.c
// ÌìÁé¹È
#include <room.h>
#include <ansi.h>
inherit ROOM;
void create ()
{
  set ("short", "[1;35mÌìÁé¹È[2;37;0m");
  set ("long", @LONG
ÕâÀï¾ÍÊÇ´«ËµÖĞµÄÌìÁé¹È£¬¹ÈÖĞ³¤ÂúÁËĞí¶à²»ÖªÃûµÄÆæÕäÒì²İÉ¢·¢³ö
µÄÏãÎ¶ÈÃÈËĞÄ¿õÉñâù£¬Ïû³ıÁËÄãÉíÉÏµÄÆ£¾ë£¬ÔÚ»¨²İÖ®ÖĞÓĞÒ»ÌõĞ¡Â·
ÏòÇ°·½¶øÈ¥¡£
LONG);

  set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"godrom2.c",
]));
  set("no_auc", 1);
  set("no_transmit", 1);

  setup();
}
