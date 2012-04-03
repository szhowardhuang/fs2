inherit ROOM;
#include <ansi.h>
#include <soil.msg>
#include <damage02.c>

string *exit = ({ __DIR__"soil05",__DIR__"soil06",__DIR__"soil07",__DIR__"soil08",});

void create()
{
        set("short","ÍÁÁéËþ¶þÂ¥");
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
