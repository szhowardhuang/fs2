// Room: /open/gblade/port/room/port.c
//by wugi
inherit ROOM;

void create()
{  
   
   set("short","枫林港港口");
   set ("long", @LONG
这里是枫林港港口 , 你看到大大小小的商船 , 渡船进进
出出 , 非常的繁忙 , 港边立了个告示牌(board) , 说明枫林港
目前通航的地区及时刻 , 价钱等讯息 .

LONG);
   set("light_up", 1);
	set_heart_beat(1);
  set("outdoors", "/open/gblade");
  set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"p3-3",
]));
  	
	set("item_desc",
	(["board":
"公告:
本港开幕大喜 , 所有乘客一律免费 

现在通航的地点有 :
镜月岛 : 一个时辰一班次
冥魔岛 : 三刻钟一班次
东瀛岛 : 谈航权中 , 敬请期待 , 哇 , 谈判大使 wugi 回家了 , 有的等啰

"]));

 setup();
}
 init()
{
	add_action("board_ship","board");
	do_start_ship();
	
}
 
//下面这个动作是用来将被记忆体清掉的船再呼叫出来
void do_start_ship()
{
	object ob1,ob2;
	if(!find_object("ship leader"))
	{
	ob1=new("/open/gblade/port/npc/ship_leader");
	 ob1->move("/open/gblade/port/room/ship");
	destruct(ob1);
	}
	if(!find_object("vessel leader"))
	{
	ob2=new("/open/gblade/port/npc/vessel_leader");
	ob2->move("/open/gblade/port/room/vessel");
	destruct(ob2);
	}
}
int board_ship(string str)
{
	object ob;
 	if(!str)
	return notify_fail("你要搭什么?\n");	
	if(!objectp(ob=present(str,environment(this_player()))))
        return notify_fail("看清楚点 , 有那种船吗 ?\n");
//下面这段 , 我的写法有个大麻烦之处
//每只船都要不同 id 才能处理 , 看那位能帮忙矫正矫正 
//hmm , 不过船应该也不多吧 , 英文的船名应该也不少了 , 呵
        if(str=="ship") 
	{
	message_vision("$N走到岸边 , 搭上了渡船 !\n",this_player());
	this_player()->move("/open/gblade/port/room/ship");
	return 1;
	}
	if(str=="vessel")
	{
	message_vision("$N走到岸边 , 搭上了幽冥魔船 !\n",this_player());
	this_player()->move("/open/gblade/port/room/vessel");
	return 1;
	}
	
return 0;
}	
