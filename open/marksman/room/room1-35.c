 // Room: /u/f/fire/room/room1-35.c
inherit ROOM;
#include <ansi.h>
#include <marksman.h>
void create ()
{
  set ("short", "[32m³¤É³µÀ[2;37;0m");
  set ("long", @LONG
ÈÈÄÖµÄ½ÖÍ·£¬ÔÓÂÒµÄÉùÒô£¬ÏÔÊ¾³ö³¤É³³Ç¸»Ô£µÄÆøÏ¢¡£Ğ¡··ÕıÔÚ
Îª×Ô¼ºµÄ¶«Î÷£¬´óÉùêÑ½Ğ×ÅÂò¶«Î÷¡£Äş¾²µÄÆø·Õ£¬³¤É³³ÇµÄÃñÖÚ¶¼´ø
×ÅÒ»¸½Î¢Ğ¦ÏòÄã×ß¹ı¡£
LONG);

  set("objects", ([ /* sizeof() == 2 */
C_NPC"/girl" : 1,
C_NPC"/oldman" : 1,
]));
  set("outdoors", "/u/f");
  set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"room1-36.c",
  "east" : __DIR__"room1-34.c",
]));

  setup();
}
