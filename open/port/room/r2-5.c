// Room: /open/gblade/port/room/p1-1.c
inherit ROOM;

void create ()
{
	set("short","客栈二楼");
  set ("long", @LONG
这里是清风楼客栈的二楼 . 西面和南面是挖空的 , 分别搭
了个阳台 . 你可以直接从这里看到海港 , 每到夏天 , 海风徐
徐吹来 , 在此小坐 , 甚为舒爽 . 城里的人最喜欢来此乘凉 .

LONG);

  set("light_up", 1);
  set("exits", ([ /* sizeof() == 2 */
	"down" : "/open/port/room/r2-4",
]));
	set("objects",([
	]));

  setup();
}
