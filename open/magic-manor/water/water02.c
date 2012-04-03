inherit ROOM;
#include <ansi.h>
#include <water.msg>
#include <damage01.c>

string *exit = ({ __DIR__"water01",__DIR__"water02",__DIR__"water03",__DIR__"water04",});

void create()
{
        set("short","Ë®ÁéËþÒ»Â¥");
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
