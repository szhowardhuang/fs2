// Room: /u/r/ranko/room/f1.c
inherit ROOM;

void create ()
{
  set ("short", "农田");
  set ("long", @LONG
一大片绿油油的田地横亘在你面前，丰满的稻穗几乎将稻子压
的贴近地面。不远处正有许多农民正忙着收割，看来今年似乎是个
丰年。许多顽童正在收割过的田地上跑来跑去，玩的不亦乐乎，附
近不时飞过几只白鹭鸶，传来几声嘶鸣声。这里有着一间以茅草搭
盖成的茅屋(hut)。
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"f4.c",
  "east" : __DIR__"f6.c",
]));
	set("item_desc", ([ /* sizeof() == 1 */
	"hut" : "一间小茅屋。\n",
]));
  set("outdoors", "/open/poison");

  setup();
}
void init()
{
	add_action("do_enter","enter");
}

int do_enter(string str)
{
	object me;
	me=this_player();
	if( !str || str!="hut")
		return notify_fail("你想进入那里呀?\n");
	message_vision("$N钻入了茅屋中。\n",me);
	me->move(__DIR__"hut.c");
	return 1;
}

