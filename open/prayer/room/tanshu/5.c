// Room: /open/prayer/room/tanshu/5.c

inherit ROOM;

void create()
{
	set("short", "偏厅");
	set("long", @LONG

    你所站的位置是天枢门的偏厅,通常一般门徒都在这习武,如果你
是习武之人,可以和他们切搓武艺,角落摆了一个兵器架,有刀,剑,枪,
锤,戟...等各式兵器.

LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"4.c",
  "south" : __DIR__"6.c",
]));
	set("light_up", 1);
	set("objects", ([ /* sizeof() == 1 */
  "/open/prayer/npc/general-manager" : 1,
]));
	set("no_clean_up", 0);

	setup();
	}
