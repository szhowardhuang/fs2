// Room: /u/f/fire/room/room1-10.c
inherit ROOM;
#include <ansi.h>
#include <marksman.h>
void create ()
{
  set ("short", "[32m³¤É³µÀ[2;37;0m");
  set ("long", @LONG
ÕâÊÇÒ»¸öÈÈÄÖµÄ½Ö¿Ú£¬µ½´¦¶¼ÊÇ³¤É³µÄÃñÖÚ¡£³µÂíÔÓí³£¬ÈËÓïĞú
ÌÚ¡£ÄãÔÚ»ìÂÒÖ®ÖĞ£¬ËÆºõºÜÄÑÈÏ³ö³ö·½Ïò¡£Äã¿´µ½ÕâÀïËÆºõ¶¼Ò»Ğ©ºÀ
ÃÅµÄ×¡Õ¬¡£
LONG);

  set("objects", ([ /* sizeof() == 1 */
C_NPC"/boy" : 1,
]));
set("outdoors","/open/marksman");
  set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"room1-7",
  "north" : __DIR__"room1-32.c",
]));

  setup();
}
