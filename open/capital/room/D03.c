// Room: /open/capital/room/D03.c
#include </open/capital/capital.h>

inherit ROOM;

void create ()
{
  set ("short", "ÕòÄÏÃÅ");
  set ("long", @LONG
ÕâÀïÊÇ¾©³ÇµÄÈı¸ö³öÈë¿ÚÖ®Ò»¡¸ÕòÄÏÃÅ¡±, ÓÉÓÚ¾©³ÇÄËÊÇÍõ³¯µÄÖĞ
ĞÄ, Ê¥ÉÏµÄ×¡ËùËùÔÚ£¬ËùÒÔÊØÎÀµÄÅÌ²éÒ²ÌØ±ğÑÏ¸ñ£¬Èç¹ûËæ±ãÈÃÉí·İ²»
Ã÷µÄÈË½ø³ÇÄÖÊÂ£¬ÄÇ¿ÉÊÇ³Ô²»Íæ¶µ×Å×ßÁË¡£

LONG);

  set("objects", ([ /* sizeof() == 1 */
  "/open/capital/npc/gate_soldier" : 1,
]));

  set("outdoors", "/open/capital");

  set("exits", ([ /* sizeof() == 2 */
  "south" : "/open/main/room/s17",
  "north" : "/open/capital/room/r35",
]));

  setup();
}

int valid_leave(object me, string dir)
{
        object guard;

        if (!objectp (guard=present ("gate soldier",this_object())))
	  return 1;

        if (dir=="north" && !me->query_temp("ÓĞÏò³ÇÃÅÊØÎÀ±¨¸æ"))
	 if(!guard->query_temp("unconcious"))
          if(!wizardp(me))
           return notify_fail("³ÇÃÅÎÀ¾üÉìÊÖÀ¹×ÅÄãËµ£º[1;31mÍê³ÉÉí·İÈ·ÈÏ²Å¿ÉÒÔ½ø³Ç¡£[0m\n");

	return 1;
}
