inherit ROOM;
#include <ansi.h>
#include <gold.msg>
#include <damage05.c>

string *exit = ({ __DIR__"gold17",__DIR__"gold18",__DIR__"gold19",__DIR__"gold20",});

void create()
{
        set("short","½ğÁéËşÎåÂ¥");
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

