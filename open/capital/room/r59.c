// Room: /open/capital/room/r59.c

inherit ROOM;

void create ()
{
  set ("short", "云洋街口");
  set ("long", @LONG
这儿便是京城里达官贵人的住所, 平常人是不会到云洋大街这儿来
逗留的。在你的北方有一座高台, 是皇帝做为祭祀、昭告的所在, 平常的时
候也可以看到皇上登上高台, 眺望远景, 饮酒作诗。
    往南的中央大道正是京城最繁荣的地带，所有的商店均可由此街道
连接起来，如果你想好好的逛逛的话, 往南走就对了, 南方尽头处就是
镇南门。

LONG);

	set("objects", ([ /* sizeof()==1 */
	"/open/capital/npc/cleanman" : 1
]) );

  set("exits", ([ /* sizeof() == 5 */
  "west" : __DIR__"r58",
  "south" : __DIR__"r66",
  "north" : __DIR__"r74",
  "east" : __DIR__"r60",
  "northup" : __DIR__"tower",
]));
  set("outdoors", "/open/capital");

  setup();
}
