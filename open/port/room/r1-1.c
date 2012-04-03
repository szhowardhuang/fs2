// Room: /open/gblade/port/room/p1-1.c
inherit ROOM;

void create ()
{
	set("short","枫林港北门");
  set ("long", @LONG
这里是枫林港的北门 . 这是一栋两层的楼台 , 高百尺 , 门
是大红朱漆 , 配上金钉 , 屋顶是用琉璃瓦来盖成 , 整座楼都是
朱栏彩槛 , 异常华丽 . 大门旁站着两个守卫 , 注视着来来往往
的行人 .

LONG);

  set("light_up", 1);
  set("outdoors", "/open/gblade");
  set("exits", ([ /* sizeof() == 2 */
	"north": "/open/main/room/s38",
	"south" : "/open/port/room/r1-2",
]));
	set("objects",([
	"/open/port/npc/guard":2,
	]));

  setup();
}
