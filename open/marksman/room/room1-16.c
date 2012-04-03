// Room: /u/f/fire/room/room1-16.c
inherit ROOM;
#include <ansi.h>
#include <marksman.h>
void create ()
{
  set ("short", "[32m³¤É³µÀ[2;37;0m");
  set ("long", @LONG
´ËµØÁ½ÅÔÖÖÖ²ÁË¸ß´óµÄÊ÷Ä¾£¬ºÍĞíĞí¶à¶àÃÀÀöµÄ»¨²İ£¬Ğì·çÊ÷Òñ
£¬ÄñÓï»¨Ïã£¬ÈÃÄãÆÈ²»¼°´ıµØÏë×ß½øÈ¥¹äÒ»¹ä¡£±±±ßÒ»¼ä³¤É³³ÇÀï×î
ÓĞÃûÃûµÄ¿ÍÕ»ÌìÁú¿ÍÕ»¡£
LONG);

  set("objects", ([ /* sizeof() == 1 */
C_NPC"/boy" : 1,
]));
set("outdoors","/open");
  set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"room1-15.c",
  "north" : __DIR__"room1-17.c",
  "east" : __DIR__"room1-19.c",
]));

  setup();
}
