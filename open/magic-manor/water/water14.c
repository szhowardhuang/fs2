inherit ROOM;
#include <ansi.h>
#include <water.msg>
#include <damage04.c>

string *exit = ({ __DIR__"water13",__DIR__"water14",__DIR__"water15",__DIR__"water16",});

void create()
{
        set("short","Ë®ÁéËþËÄÂ¥");
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

