// Room: /open/gblade/port/room/p2-3.c
inherit ROOM;

void create ()
{
   set("short", "石板大道");
  set ("long", @LONG
这里是枫林港最繁荣的商业中心 , 一堆摊贩沿路兜售 , 璘琅满
目的货品 , 真是令人目不暇给 , 仔细看看 , 也许你会买到奇珍异
宝喔 , 走在这里 , 你要当心点 , 自己的荷包可要看紧啊 ! 西边是
一家宠物店 , 进去看看吧 ! 北边是皇帝最赏识的面包师退休后所开
的店 , 买几块面包捧捧场吧 !

LONG);

  set("light_up", 1);
  set("outdoors", "/open/gblade");
  set("exits", ([ /* sizeof() == 3 */
  "north" : __DIR__"p2-9.c",
  "west" : __DIR__"p2-4.c",
  "east" : __DIR__"p2-2",
]));
	set("objects",([
	"/open/gblade/port/npc/man":1,
	]));

  setup();
}
