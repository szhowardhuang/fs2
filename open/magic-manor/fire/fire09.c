inherit ROOM;
#include <ansi.h>
#include <fire.msg>
#include <damage03.c>

string *exit = ({ __DIR__"fire09",__DIR__"fire10",__DIR__"fire11",__DIR__"fire12",});

void create()
{
        set("short","»ðÁéËþÈýÂ¥");
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

