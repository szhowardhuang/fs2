// Room: /u/f/fire/room/room1-15.c
inherit ROOM;
#include <ansi.h>
#include <marksman.h>
void create ()
{
  set ("short", "[32m³¤É³µÀ[2;37;0m");
  set ("long", @LONG
¿´×Å¹ÅÉ«¹ÅÏãµÄ³¤É³½ÖµÀ£¬ÕûÌõ½ÖµÀÈ«ÊÇÓÉ´óÇàÊ¯»¨ÎÆ°åËùÆÌ³É
£¬Ïàµ±Æ½ÕûÇÒ¿í³¨£¬½ÖÍ·ÈËÀ´ÈËÍùºÃ²»ÈÈÄÖ£¬Á½ÅÔµÄµêÆÌ£¬Ğ¡··½ĞÂô
ÉùÒô¸üÊÇÎªÕâ½ÖµÀÔöÌí²»ÉÙ»îÁ¦¡£
LONG);

  set("objects", ([ /* sizeof() == 1 */
C_NPC"/woman" : 1,
]));
set("outdoors","/open/marksman");
  set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"room1-9",
  "east" : __DIR__"room1-16.c",
]));

  setup();
}
