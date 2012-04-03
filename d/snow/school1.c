// Room: /d/snow/school1.c

#include <room.h>

inherit ROOM;

void create ()
{
  set ("short", "[1;35m¹ıÈ¥Ê±¿Õ[0m ´¾·çÎä¹İ´óÃÅ");
  set ("long", @LONG
ÄãÏÖÔÚÕıÕ¾ÔÚÒ»¼ä´óÕ¬ÔºµÄÈë¿Ú£¬Á½Ö»¾Ş´óµÄÊ¯Ê¨ÕòÊØÔÚ´óÃÅµÄÁ½
²à£¬Ò»ÕóÕóßººÈÓëµ¶½£Åö×²µÄÉùÒô´ÓÔº×ÓÖĞ´«À´£¬Í¨¹ı´óÃÅÍù¶«¿ÉÒÔÍû
¼ûĞí¶àÉí´©»ÒÒÂµÄºº×ÓÕıÔÚ²ÙÁ·¡£
LONG);

  set("item_desc", ([ /* sizeof() == 1 */
  "east" : (: look_door,     "east" :),
]));
  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/guard" : 1,
]));
  set("outdoors", "snow");
  set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"mstreet1",
  "east" : __DIR__"school2",
]));

  setup();
}
