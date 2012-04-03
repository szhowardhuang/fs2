inherit ROOM;
#include <ansi.h>
#include <water.msg>
#include <damage05.c>

string *exit = ({ __DIR__"water17",__DIR__"water18",__DIR__"water19",__DIR__"water20",});

void create()
{
        set("short","Ë®ÁéËþÎåÂ¥");
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

