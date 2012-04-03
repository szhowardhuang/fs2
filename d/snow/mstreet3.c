// Room: /d/snow/mstreet3.c

#include <room.h>

inherit ROOM;

void create ()
{
  set ("short", "[1;35m¹ıÈ¥Ê±¿Õ[0m Ñ©Í¤Õò½ÖµÀ");
  set ("long", @LONG
ÕâÀïÊÇÑ©Í¤ÕòµÄ´ó½Ö£¬¶«±ßÓĞÒ»¶°³Â¾ÉµÄ½¨Öş£¬¿´ÆğÀ´ÏñÊÇÊ²Ã´µê
ÆÌ£¬µ«ÊÇ²¢Ã»ÓĞÈÎºÎÕĞÅÆ£¬Ö»ÓĞÒ»ÉÈÃÅ(door)ÉÏÃæĞ´×ÅÒ»¸ö´ó´óµÄ¡¸µ±
¡±×Ö£¬ÍùÎ÷ÊÇÒ»¼äÒ©ÆÌ£¬´ó½ÖÍùÄÏ±±Á½¸ö·½ÏòÑÓÉì¡£
LONG);

  set("item_desc", ([ /* sizeof() == 1 */
  "east" : (: look_door,     "east" :),
]));
  set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"herbshop",
  "north" : __DIR__"mstreet4",
  "south" : __DIR__"mstreet2",
  "east" : __DIR__"hockshop",
]));
  set("outdoors", "snow");

  setup();
}
