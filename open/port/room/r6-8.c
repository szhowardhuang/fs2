// Room: /open/gblade/port/room/p1-1.c
inherit ROOM;

void create ()
{
	set("short","了望台顶");
  set ("long", @LONG
登上了了望台 , 视野异常辽阔 , 往南方望去 , 整个城市尽
收眼底 . 枫林除了面临海洋外 , 东西两面分别连着栖凰岭和六
阳山 , 北边隔着城墙与平原相接 . 整个枫林港则犹如一个大工
地 , 到处兴建中的房舍 , 道路 , 让你又一次的体验到这里的
生命力 . 如果说新京是个壮年人 , 蜀中就是个白发苍苍的老年
人 , 而枫林则像个精力旺盛的青少年 , 正准备在自己的人生舞
台上大放异彩 .

LONG);

  set("light_up", 1);
	set("outdoors", "/open/port");
  set("exits", ([ /* sizeof() == 2 */
	"down" : "/open/port/room/r6-7",
]));
	set("objects",([
	"/open/port/npc/guard3":2,
	"/open/port/npc/vice-leader":1,
	]));

  setup();
}
