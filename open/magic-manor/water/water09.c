inherit ROOM;
#include <ansi.h>
#include <water.msg>
#include <damage03.c>

string *exit = ({ __DIR__"water09",__DIR__"water10",__DIR__"water11",__DIR__"water12",});

void create()
{
        set("short","Ë®ÁéËþÈýÂ¥");
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

