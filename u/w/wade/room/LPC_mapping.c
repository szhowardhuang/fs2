inherit ROOM;

#define WADE_HOME "/u/w/wade/workroom"

void create ()
{
  set ("short", "LPC 讲座 -- 对应");
  set ("long", @LONG
所谓的对应, 有点类似阵列, 是一种其它不常见的型态, 但是很好用,
宣告方式如右: mapping *dbs;
使用者蛮常见的有 dbs = player->query_entire_dbase();  传回整个
资料变数, 跟 data player 看到的很类似.
对应的初始值是 ([]), 通常要初始化, 还有一种方式是 allocate() 函数
这个在每个房间里几乎都看得到它的使用, 如:
  set("exits", ([ "east" : "/u/w/wade/workroom", ]) );
  set("object", ([ "xxxxxx" : 1, "####" : 1, ]) );
在增加一个对应时, 可以直接用: mapping ob = query("objects");
	ob["/u/w/wade/npc/test"] = 1;
这样就会多一个物件了, 如果原来已经有 "/u/w/wade/npc/test", 那就
是改变它的值成 1. 至于要删除的话, 可以用 map_delete() 函数.
    mapping map;
	map = ([ "gold": 20, "silver":30 ]);
	map = map + ([ "coin":100 ]);		// 变成 gold, silver, coin
	map["gold"] = map["gold"] + 100;	// map["gold"] == 120 啰
LONG);

  set("exits", ([
	"back"	:	__DIR__"lpc",
	"adv"	:	__DIR__"LPC_mapping1",
  ]) );

  setup();
}
