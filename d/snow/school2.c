// Room: /d/snow/school2.c

#include <room.h>

inherit ROOM;

void create ()
{
  set ("short", "[1;35m¹ıÈ¥Ê±¿Õ[0m ´¾·çÎä¹İ½ÌÁ·³¡");
  set ("long", @LONG
ÄãÏÖÔÚÕıÕ¾ÔÚÒ»¸ö¿í³¨µÄ½ÌÁ·³¡ÖĞ£¬µØÉÏÆÌ×Å»ÆÉ«µÄÏ¸É°£¬Ğí¶àÈË
ÕıÔÚÕâÀïÅ¬Á¦µØ²ÙÁ·×Å£¬±±±ßÊÇÒ»¼ä¸ß´óµÄ±øÆ÷Ìü£¬Íù¶«ÔòÊÇÎä¹İÊ¦¸¸
ÃÇĞİÏ¢µÄ´óÌü¡£
LONG);

  set("item_desc", ([ /* sizeof() == 1 */
  "west" : (: look_door,     "west" :),
]));
  set("objects", ([ /* sizeof() == 2 */
  __DIR__"npc/trainee" : 3,
  __DIR__"npc/fist_trainer" : 1,
]));
  set("outdoors", "snow");
  set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"school1",
  "north" : __DIR__"weapon_storage",
  "east" : __DIR__"schoolhall",
]));

  setup();
}
