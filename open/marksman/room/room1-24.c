// Room: /u/f/fire/room/room1-24.c
inherit ROOM;
#include <ansi.h>
#include <marksman.h>
void create ()
{
  set ("short", "[1;33mÇ¿ÕßÖ®µÀ[2;37;0m");
  set ("long", @LONG
ÔÚÀúÊ·ÓÆ¾ÃĞÛÎ°ºñÖØµÄ´óÃÅÉÏÏâ×Å±ßÔµÓÉ»Æ½ğ´òÔì¡¢ÖĞÑëµñ¿Ì×Å
Àî¹ã´óÈËÔÚÕ½³¡ÉÏÉ±µĞµÄĞÛÎ°£¬Á÷Â¶³ö»ÆÖÒ´óÈËµÄÓ¢ÓÂ£¬Ì§Í·ÍùÉÏÒ»
¿´ÊÇÒ»×ù½à°×µÄ½¨ÖşÎï£¬ÔÚÑô¹âµÄÕÕÉäÏÂ¸üÏÔµÃËü¸ßÑÅÎŞ±È¡£
LONG);

  set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"room1-23",
  "west" : __DIR__"room1-28.c",
  "north" : __DIR__"room1-31.c",
  "east" : __DIR__"room1-27.c",
]));

set("light_up",1);
  setup();
}
