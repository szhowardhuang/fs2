// Room: /open/prayer/room/tanshu/6.c

inherit ROOM;

void create()
{
	set("short", "偏厅");
	set("long", @LONG

    在厅上有许多高职位的门徒,个个面目严肃站在那里,等候着向门
主报告份内的职责,以便门主能适时的处理掉棘手的问题,墙上是门主
所写的书法,字字挥洒的淋漓尽致.

LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "north" : __DIR__"5.c",
  "west" : __DIR__"3.c",
  "south" : __DIR__"9.c",
]));
	set("light_up", 1);
	set("no_clean_up", 0);
	set("short ", "偏厅");

	setup();
	}
