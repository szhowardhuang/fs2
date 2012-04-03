// Room: /open/gblade/port/room/p1-1.c
inherit ROOM;

void create ()
{
	set("short","清风楼客栈");
	set( "build", 8 );
  set ("long", @LONG
这里是方圆百里内最负盛名的一家客栈 . 许多到枫林来的
商人 , 旅客 , 都指名要来此住宿 . 虽然这里的客房数量上百
间之多 , 却仍然一房难求 , 除非你能出的起更高的价钱 .

LONG);

  set("light_up", 1);
  set("exits", ([ /* sizeof() == 2 */
	"west" : "/open/port/room/r2-1",
	"up" : "/open/port/room/r2-5",
]));
	set("objects",([
	"/open/port/npc/keeper":1,
	]));

  setup();
}
