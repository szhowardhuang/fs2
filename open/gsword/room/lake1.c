// Room: /open/gsword/room/lake1.c

inherit ROOM;

void create ()
{
  set ("short", "昆明湖北");
  set ("long", @LONG
你眼前一片湖光荡漾,昆明湖由此远望,浩浩漡漡,向南延伸一片,
垂柳与画眉的对话,画舫与湖光的相映. 烟波,水气,交织成这蜀 	
州名景昆明湖.
LONG);

  set("objects", ([ /* sizeof() == 1 */
  "/open/gsword/mob/visitor" : 1,
]));

  set("outdoors", "/open/gsword");

  set("exits", ([ /* sizeof() == 3 */
  "southeast" : "/open/gsword/room/lake2.c",
  "north" : "/open/gsword/room/froad0.c",
  "southwest" : "/open/gsword/room/lake0.c",
]));

  set ("资源/液体", ([
       "种类" : "水",
       "名称" : "清水",
       "止渴" : 30
  ]) );

  setup();
}
