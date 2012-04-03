inherit ROOM;
#include <ansi.h>
#include <wood.msg>
#include <damage04.c>

string *exit = ({ __DIR__"wood13",__DIR__"wood14",__DIR__"wood15",__DIR__"wood16",});

void create()
{
        set("short","Ä¾ÁéËþËÄÂ¥");
        set("long", (: printf_msg :) );
        set("exits", ([
	"south"	: exit[random(sizeof(exit))],
	"north"	: exit[random(sizeof(exit))],
	"east"	: exit[random(sizeof(exit))],
	"west"	: exit[random(sizeof(exit))],
        ]));
        set("light", 1);
	set("no_auc", 1);
	set("no_transmit",1);
        setup();

}
