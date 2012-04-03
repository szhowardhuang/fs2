inherit ROOM;
#include <ansi.h>
#include <wood.msg>
#include <damage02.c>

string *exit = ({ __DIR__"wood05",__DIR__"wood06",__DIR__"wood07",__DIR__"wood08",});

void create()
{
        set("short","Ä¾ÁéËþ¶þÂ¥");
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
