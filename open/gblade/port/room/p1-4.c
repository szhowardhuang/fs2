// Room: /open/gblade/port/room/p1-4.c
inherit ROOM;

void create ()
{
  set ("short", "石板大道");
  set ("long", @LONG
这是一条石板铺成的大道 , 路上行人大都配戴着一把刀 ,
似乎人人都带着武功 , 看来你还是少在这儿惹事为妙 , 北边
一栋平房 , 一些刀客进进出出的 , 也许你该过去瞧瞧看 .

LONG);

  set("light_up", 1);
  set("outdoors", "/open/gblade");
  set("exits", ([ /* sizeof() == 3 */
  "north" : __DIR__"p1-5.c",
  "west" : __DIR__"p1-3",
  "east" : __DIR__"p1-7.c",
]));
	set("objects",([
	"/open/gblade/port/npc/blademan":1,
	]));

  setup();
}
