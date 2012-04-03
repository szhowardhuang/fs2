// Room: /u/f/fire/room/room1-25.c
inherit ROOM;
#include <ansi.h>
#include <marksman.h>
void create ()
{
  set ("short", "[1;33mÇ¿ÕßÖ®µÀ[2;37;0m");
  set ("long", @LONG
ÁîÈË¸Ğ¾õÆøÊÆ·Ç·²µÄ½«¾ü¸®£¬Î§Ç½ÉÏÆ®Ñï×ÅºìÉ«µÄÆìÖÄ£¬´óÃÅÁ½
ÅÔÕ¾×ÅÉí´©À¶É«Åû·ç¡¢½à°×µÄîø¼×¡¢´÷×ÅºñÖØµÄÍ·¿ø£¬ÍşÎäÊ®×ãµÄÎä
Ê¿¡£îÎh¸ßÑÅµÄÊÌÅ®ÕıÀ´À´ÍùÍùµÄ¡£
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"room1-23",
  "north" : __DIR__"room1-27.c",
]));
  set("objects", ([ /* sizeof() == 1 */
C_NPC"/bowman" : 2,
]));

  setup();
}
