inherit ROOM;
#include <ansi.h>
#include <wood.msg>
#include <damage06.c>

string *exit = ({ __DIR__"wood21",__DIR__"wood22",__DIR__"wood23",__DIR__"wood24",});

void create()
{
        set("short","Ä¾ÁéËþÁùÂ¥");
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
