// Room: /u/f/fire/room/room1-29.c
inherit ROOM;
#include <ansi.h>
#include <marksman.h>
void create ()
{
  set ("short", "[1;33mÇ¿ÕßÖ®µÀ[2;37;0m");
  set ("long", @LONG
´ÓÕâÀï¿ÉÒÔ¸ü¼ÓµÄÇå³şµÄÒôÀÖ£¬²»Ö»¸ß¿ºµÄÇÙÉù£¬»¹ÓĞîÎhĞıÂÉ
¼òµ¥¶øÈáºÍµÄ¸ÖÇÙÉù¡£¸üÁîÈË×¢ÒâµÄÊÇÔÚÕâËÆºõÊÇ¸ú×ÅÕâ¸öÒôÀÖµÄ½Ú
ÅÄÔÚ×ß¶¯£¬¸÷¸÷Á³ÉÏÂ¶³öÒ»¸±¿ìÀÖµÄ±íÇé¡£
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"room1-31",
  "south" : __DIR__"room1-27.c",
]));
  set("objects", ([ /* sizeof() == 1 */
C_NPC"/wu-mon.c" : 1,
]));

set("light_up",1);
  setup();
}
