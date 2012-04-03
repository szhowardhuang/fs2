// Room: /u/o/onion/room/r_room2.c

inherit ROOM;

void create()
{
	set("short", "镖局客房");
	set("long", @LONG
一间干干净净的客房,桌子上连一点灰尘都没有,可知打扫这里的仆人是多认真的了.
客房里还放着一张雕工精美的红桧大床,床头上雕着蟠龙浮云,床尾刻着水池青莲,你
心想着连客房都如此气派,想必此镖局的声势和威望有多高了...
    这个房间的角落里还放了一面古铜的镜子(mirror),隐隐泛出青光..
LONG
	);
set("item_desc", ([
	"mirror" : "
	你仔细的往镜中一瞧,才赫然发现自己长的实在是～有～够～丑～..
	你不禁悲从中来,嚎啕大哭..\n"
	]));

	set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"room3",
]));
	set("valid_startroom", "1");

	setup();
}
