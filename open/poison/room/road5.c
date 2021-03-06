// Room: /open/poison/room/road5
inherit ROOM;

void create ()
{
  set ("short", "瀑布");
  set ("long", @LONG
眼前有一道瀑布(waterfall) 由峰顶直泄而下，气势雷
廷万千，经由阳光照射，在瀑旁形成一道七彩虹桥，瀑水冲
击岩石，激起阵阵水花，附近水气弥漫，如梦如幻，如痴如
醉，婉如人间仙境般。
LONG);

  set("item_desc", ([ /* sizeof() == 1 */
  "waterfall" : "此道瀑布十分美丽壮观，在你眼前形成一道宽广的帘幕，瀑
旁岩石并没有生长青苔，看起来似乎是常有人行走的结果，
不知瀑布后是否别有洞天。
",
]));

  set("outdoors", "/open/poison");

  set("exits", ([ /* sizeof() == 1 */
  "east" : "/open/poison/room/road4",
]));

  setup();
}
void init()
{
	add_action("do_enter","enter");
}

int do_enter(string str)
{
	object me;
	me = this_player();
	
	if(!str || str != "waterfall")
		return notify_fail("你想进入哪里？\n");
	else {
		tell_object(me,"随身一转, 你轻巧地进入瀑布后的山洞。\n");
		me->move("/open/poison/room/room5");
	     }
	return 1;
}
