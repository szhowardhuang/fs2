// Room: /u/f/fire/room/room1-11.c
inherit ROOM;
#include <ansi.h>
#include <marksman.h>
void create ()
{
  set ("short", "[32m³¤É³µÀ[2;37;0m");
  set ("long", @LONG
ĞúÈÂµÄÈËÉù£¬Ò²½ÏÎªÆ½Ï¢ÁË¡£Í»È»¼ä£¬ÄãÎÅµ½Ò»¹ÉÅ¨ÙıµÄÒ©Ïã£¬
²»¶ÏµÄ³¯ÄãÆ®¹ıÀ´¡£Äã×ĞÏ¸µÄ·Ö±æÒ»ÏÂ·½Î»£¬ËÆºõÊÇ´Ó±±±ßµÄµêÆÌ´«
³öÀ´µÄ£¬Ó¦¸ÃÊÇÒ»¼äÒ©µê¡£
LONG);

  set("outdoors", "/open/marksman");
  set("exits", ([ /* sizeof() == 3 */
  "east" : __DIR__"room1-9",
//  "north" : __DIR__"room1-12.c",
]));
  set("objects", ([ /* sizeof() == 1 */
  "/open/marksman/npc/oldman" : 1,
]));

  setup();
}
