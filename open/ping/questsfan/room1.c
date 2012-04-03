// Room: /u/d/dhk/questsfan/room1
inherit ROOM;
#include <ansi.h>
void create ()
{
  set ("short", "[1;36m¶ÎÍõ¸®[0;36mÃÜµÀ[0m");
  set ("long", @LONG
ÕâÌõÃÜµÀÓÖ³±Êª¡¢ÓÖ°µ¡£´«ÎÅÕâÌõÃÜµÀÊÇÀú´úÆ½ÄÏÍõ
¸®½«¾üÎª·ÀÖ¹´Ë³Ç±»µĞ¾ü¹¥ÆÆÊ±¸øÓè½«¾üÌÓÃüÓÃµÄ£¬ÕâÌõ
ÃÜµÀÓ¦¸ÃÍ¨ÍùºóÉ½°É£¿µ«ÊÇÄã¶¨ÏÂĞÄÒ»¿´£¬´ËµØÈ·Ïñ±»·Ï
Æú²»ÓÃÁË¡­
LONG);

  set("no_transmit", 1);
  set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"room2",
  "out" : "open/ping/room/np25",
]));

  setup();
}
