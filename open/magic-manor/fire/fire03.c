inherit ROOM;
#include <ansi.h>
#include <fire.msg>
#include <damage01.c>

string *exit = ({ __DIR__"fire01",__DIR__"fire02",__DIR__"fire03",__DIR__"fire04",});

void create()
{
        set("short","»ðÁéËþÒ»Â¥");
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
