// Room: /u/f/fire/room/room1-28.c
inherit ROOM;
#include <ansi.h>
#include <marksman.h>
void create ()
{
  set ("short", "[1;33mÇ¿ÕßÖ®µÀ[2;37;0m");
  set ("long", @LONG
´ÓÕâÀï¿ÉÒÔ¸ü¼ÓµÄÇå³şµÄÒôÀÖ£¬²»Ö»¸ß¿ºµÄÇÙÉù£¬»¹ÓĞîÎhĞıÂÉ
¼òµ¥¶øÈáºÍµÄ¸ÖÇÙÉù¡£¸üÁîÈË×¢ÒâµÄÊÇÔÚÕâ¹¬µîµÄ¹ó×åËÆºõÊÇ¸ú×ÅÕâ
¸öÒôÀÖµÄ½ÚÅÄÔÚ×ß¶¯£¬¸÷¸÷Á³ÉÏÂ¶³öÒ»¸±¿ìÀÖµÄ±íÇé¡£
LONG);

  set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"room1-26.c",
  "north" : __DIR__"room1-30.c",
  "east" : __DIR__"room1-24",
]));
  set("objects", ([ /* sizeof() == 1 */
C_NPC"/bowman1.c" : 2,
]));

  setup();
}
