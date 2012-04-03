// Room: /open/ping/room/road5.c
inherit ROOM;

void create ()
{
  set ("short", "石板大道");
	set( "build", 44 );
  set ("long", @LONG
这里是平南城的西区,每次苗人的进犯,这儿都是首当其冲,
然而这里的百性似忽已习惯刀枪下过日子, 依然悠闲的作生意
,往南边走就是平南城的驿站.
LONG);

  set("objects", ([ /* sizeof() == 1 */
  "/open/ping/npc/man" : 1,
]));
  set("outdoors", "/open/ping");
  set("exits", ([ /* sizeof() == 3 */
  "north" : __DIR__"pingsteal",
  "west" : __DIR__"road6.c",
  "east" : __DIR__"road4",
  "south" : "/open/trans/room/room3",
]));

  setup();
}
