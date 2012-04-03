// Room: /open/gblade/port/room/p1-9.c
inherit ROOM;

void create ()
{
  set ("short", "石板大道");
  set ("long", @LONG
道路延伸到此已进入了城郊 , 路上行人也少了许多 , 只有
几个刀客在此行走着 , 与一般刀客不同的是 , 他们人人配戴着
一把黄金小刀 , 衣着华丽 , 看来 , 江湖三大门派之一的金刀门
必在附近 .

LONG);

  set("light_up", 1);
  set("outdoors", "/open/gblade");
  set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"p1-7",
  "east" : __DIR__"p1-10.c",
]));
set("objects",([
	"/open/gblade/port/npc/trainee":1,
	]));

  setup();
}
