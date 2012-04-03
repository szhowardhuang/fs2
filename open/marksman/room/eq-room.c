// Room: /open/marksman/room/eq-room.c
inherit ROOM;
#include <ansi.h>

void create ()
{
  set ("short", "[1;33mÉäÊÖEQÊÒ[2;37;0m");
  set ("long", @LONG
ÕâÊÇÒ»¼äÊ¦ĞÖ½ãÒª¸øĞÂ¼ÓÈëÃÅÅÉµÄÊ¦µÜÃÃEQÊ±£¬¶¼»á·ÅÔÚÕâÀï
¸øºó½øµÄµÜ×ÓÃÇÊ¹ÓÃ£¬µ±È»ºó½øµÄµÜ×Ó¿ÉÒªÇÚÁ·¹¦²ÅĞĞ£¬²»¹Ã¸º´ó
¼ÒµÄÆÚĞí¡£

LONG);

  set("no_fight", 1);
  set("exits", ([ /* sizeof() == 1 */
  "down" : __DIR__"room1-31",
]));
  set("light_up", 1);

  setup();
}
