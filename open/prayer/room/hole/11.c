///open/prayer/room/hole/11.c

inherit ROOM;

void create()
{
	set("short", "洞穴");
	set("long", @LONG

	浓雾逐渐散去后, 你赫然发现地上有无数的虫蚁在爬行!!角落有一
	团黑黑的物体....... 走近一看, 竟是一只双头的响尾蛇!!它正露
	出贪婪的眼光, 直盯着你瞧......可恶的怪兽!!跟你拼了!!

LONG	);
    set("objects", ([ /* sizeof() == 1 */
  "/open/prayer/npc/ditail-snake" : 1,		//双头响尾蛇
]));
	set("exits", ([ /* sizeof() == 4 */
  "east" : __DIR__"13",
  "south" : __DIR__"2",
  "west" : __DIR__"6",
  "north":__DIR__"9",
]));
        set("evil",1);
        set("no_auc",1);
        set("no_transmit",1);
	setup();
}