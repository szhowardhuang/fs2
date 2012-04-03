inherit ROOM;
#include <ansi.h>
#include <wood.msg>
#include <damage05.c>

string *exit = ({ __DIR__"wood17",__DIR__"wood18",__DIR__"wood19",__DIR__"wood20",});

void create()
{
        set("short","Ä¾ÁéËþÎåÂ¥");
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
