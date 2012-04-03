// Room: /open/capital/room/D02.c
#include </open/capital/capital.h>
#include <ansi.h>


inherit ROOM;

void create ()
{
  set ("short", "º³¶«ÃÅ");
  set ("long", @LONG
ÕâÀïÊÇ¾©³ÇµÄÈı¸ö³öÈë¿ÚÖ®Ò»£¬ÓÉÓÚÕâÀïÄËÊÇÍõ³¯µÄÖĞĞÄ, Ê¥ÉÏµÄ
×¡ËùËùÔÚ£¬ËùÒÔÊØÎÀµÄÅÌ²éÒ²ÌØ±ğÑÏ¸ñ£¬Èç¹ûËæ±ãÈÃÉí·İ²»Ã÷µÄÈË½ø³Ç
ÄÖÊÂ£¬ÄÇ¿ÉÊÇ³Ô²»Íæ¶µ×Å×ßÁË¡£

LONG);

  set("objects", ([ /* sizeof() == 1 */
  "/open/capital/npc/gate_soldier" : 1,
]));

  set("outdoors", "/open/capital");

  set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"r15",
  "east" : "/open/main/room/r16",
]));

  setup();
}

int valid_leave(object me , string dir)
{
        object guard;
        guard=present("gate soldier",this_object());
        if( dir=="north" && objectp(guard) && !me->query_temp("ÓĞÏò³ÇÃÅÊØÎÀ±¨¸æ") )
         if(!guard->query_temp("unconcious"))
          if(!wizardp(me))
           return notify_fail("½üÎÀ¾üÉìÊÖÀ¹×ÅÄãËµ£º[1;31mÍê³ÉÉí·İÈ·ÈÏ²Å¿ÉÒÔ½ø³Ç¡£[0m\n");
        return ::valid_leave(me,dir);
}
