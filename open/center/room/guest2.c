// Room: /u/l/lotus/girl/guest2.c
#include "/open/open.h"
inherit ROOM;

void create ()
{
  set ("short", "彩厅");
  set ("long", @LONG
一群年纪十四, 五岁的少女, 舞着凤阳花鼓, "咚咚咚", "咚咚咚
咚", 俏皮可爱. 这是舞孃表演舞蹈的地方, 客人们在此饮酒, 欣赏舞
蹈, 好不风流, 不一定什么时候,  以舞蹈闻名的彩蝶姑娘会下得楼来
舞一曲.
LONG);

  set("exits", ([ /* sizeof() == 3 */
  "north" : CENTER_ROOM"tin1.c",
  "south" : CENTER_ROOM"tin3.c",
  "east" : CENTER_ROOM"guest",
]));
  set("light_up", 1);
  set("file_name", CENTER_ROOM"guest2.c");

  setup();
}
