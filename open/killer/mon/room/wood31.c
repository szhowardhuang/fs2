//written by wataru...../open/killer/mon/room/wood31.c
inherit ROOM;

void create()
{
        set("short", "长绳");
        set("long", @LONG
	爬上了绳子之后，你发现这一棵树实在太高了.......
	想不到你爬了数十尺，居然还是没有看到绿云组所在处。
	无奈，只好尽力的往上爬.........

LONG
        );
   set("exits", ([ /* sizeof() == 1 */
       "up" : "/open/killer/mon/room/g1.c",
        "down" : "/open/killer/mon/room/wood20.c",
   ]));
        set("no_clean_up", 0);

        setup();
        }
