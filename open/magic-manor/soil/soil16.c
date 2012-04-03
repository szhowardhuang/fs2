inherit ROOM;
#include <ansi.h>
#include <soil.msg>
#include <damage04.c>

string *exit = ({ __DIR__"soil13",__DIR__"soil14",__DIR__"soil15",__DIR__"soil16",});

void create()
{
        set("short","Õ¡¡ÈÀ˛Àƒ¬•");
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
