// Room: /open/prayer/room/tanshu/18.c

inherit ROOM;

void create()
{
	set("short", "后院");
	set("long", @LONG

    阵阵花香朝你扑鼻而来，美丽的花蝴蝶在花丛中，舞出曼丽的舞
姿，黄莺在枝头上唱着清脆嘹亮的歌声，正是鸟语花香的净地，令你
想不到一代莽夫也能有此雅兴，往北是间茅厕，东边是柴房。

LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "north" : __DIR__"19.c",
  "west" : __DIR__"17.c",
  "east" : __DIR__"20.c",
]));
	set("no_clean_up", 0);

	setup();
	}
