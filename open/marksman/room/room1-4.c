// Room: /u/f/fire/room/room1-4.c
inherit ROOM;
#include <ansi.h>
#include <marksman.h>
void create ()
{
  set ("short", "[32m³¤É³µÀ[2;37;0m");
  set ("long", @LONG
ÁãÁãÉ¢É¢µÄĞĞÈË£¬Ò²ĞíÕâÕıÊÇÏÔÊ¾³ö³¤É³³ÇµÄÆ½¾²°²ÄşµÄÆøÏó¡£
ÕâÃ´´óµÄÒ»Ìõ½Ö£¬ËÆºõ³ÉÁËÓÎÃñµÄ¾ÓËù¡£ÔÚ±±±ßÄã¿ÉÒÔ¿´µ½Ò»¼ÒÌúÆÌ
£¬ÄÏ±ßÔòÊÇÒ»¼ÒÉÌµê¡£
LONG);

  set("objects", ([ /* sizeof() == 1 */
C_NPC"/man" : 1,
]));
set("outdoors","/open/marksman");
  set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"room1-3.c",
  "south" : __DIR__"room1-6.c",
  "north" : __DIR__"room1-5.c",
  "east" : __DIR__"room1-7.c",
]));

  setup();
}
