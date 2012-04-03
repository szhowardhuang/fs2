// Room: /u/f/fire/room/room1-7.c
inherit ROOM;
#include <ansi.h>
#include <marksman.h>
void create ()
{
  set ("short", "[32m³¤É³µÀ[2;37;0m");
  set ("long", @LONG
Äã×ßÔÚÕâ³¤³¤´ó´óµÄ³¤É³µÀÉÏ£¬Ö»¸Ğ¾õÕâµÄ·ç¾°Ê®·ÖÃÀÀö£¬·ç¶ù
ÇáÇáµÄÍùÄãµÄÁ³ÅÓ´µ¶¯£¬ËÆºõ°ÑÄãÎÚºÚµÄĞã·¢´µÉ¢¡£Äã¿´µ½³¤É³³ÇµÄ
ÃñÖÚÊÇ·ñ¶¼ÔÚÏĞ¹ä×Å£¬ÏÔÊ¾³öÃ»ÓĞÕ½ÕùµÄºÍÆ½³ÇÕò¡£
LONG);

  set("objects", ([ /* sizeof() == 1 */
C_NPC"/girl" : 1,
]));
  set("outdoors", "/u/f");
  set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"room1-4",
  "east" : __DIR__"room1-10.c",
]));

  setup();
}
