inherit ROOM;
#include <ansi.h>
#include <road.msg>

void create ()
{
	set("short",BBLU+YEL"震邪道"NOR);
	set("long",
(: print_road_msg :)
);
	set("no_transmit",1);
        set("light_up",-1);
	set("exits",([
"up":__DIR__"e20",
"west":__DIR__"e22",
]));
	set("objects",([
__DIR__"npc/evil-clever":2,
__DIR__"npc/spider-girl":1,
]));
	setup();
}

int valid_leave(object me,string dir)
{
	if(dir=="west")
	{
		if(present("evil-ghost",environment(me)) || present("evil-clever",environment(me)) || present("spider-girl",environment(me)))
			return notify_fail("在此地的邪灵们阻挡住了你的去路。\n");
	}
return 1;
}