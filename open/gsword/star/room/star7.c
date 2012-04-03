// Room: /u/b/blue/room/star1.c
#include <ansi.h>
inherit ROOM;

void create ()
{
  set ("short", "[1;37mÌìÊàÂ¥[2;37;0m");
  set ("long", @LONG
ÕâÊÇÆßĞÇËşÖĞµÄ×îºóÒ»²ã, ¿´ÁË¿´ËÄÖÜ, ĞÄÖĞÉî¸Ğ²»¿ÉË¼Òé, 
ÖÜÎ§¾¡ÊÇÒ»¶Ñ¶ÑµÄ°×¹Ç, °×¹ÇÅÔÉ¢Âä×ÅÒ»¶Ñ¶ÑµÄÎäÆ÷¼°×°±¸, Äã
Õı´òËã½«¹¦Á¦Äı¾Ûµ½Ê®³ÉÊ±, Â¥Ö÷ÒÑ¾­³åµ½ÄãµÄÉí±ß, ÒÔÏÂÁËÖØ
ÊÖ,ÁîÄã´ËÊ±²»ÖªËù´ë¡£
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "up" : "/open/gsword/room/g5-1.c",
  "out" : __DIR__"room14.c",
]));
  set("light_up", 1);
  set("objects", ([ /* sizeof() == 1 */
  "/open/gsword/star/npc/star2.c" : 1,
]));

  setup();
}
