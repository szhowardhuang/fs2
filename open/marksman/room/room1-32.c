// Room: /u/f/fire/room/room1-32.c
#include <ansi.h>
#include <marksman.h>
inherit ROOM;

void create ()
{
  set ("short", "[32mÃñ·¿[2;37;0m");
  set ("long", @LONG
ÕâÊÇÒ»¼ä³¤É³³ÇÀïµÄÃñÖÚËù¾Ó×¡µÄÃñ·¿£¬Äã¿´µ½Ò»¸ö¼òÂªµÄĞ¡´²
£¬Ò»ÕÅÄ¾¹¤Ôì³ÉµÄĞ¡ÒÎ×Ó£¬ËÄËÄ·½·½µÄ×À×Ó¡£×À×ÓÉÏ·Å×ÅÒ»Ğ©Ğ¡²èºø
£¬ÄãËÆºõ¿´µ½ÃñÖÚÕıÔÚ×ö¶«Î÷¡£
LONG);

  set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"room1-10",
]));
  set("objects", ([ /* sizeof() == 2 */
C_NPC"/woman" : 1,
C_NPC"/man" : 1,
]));

  setup();
}
