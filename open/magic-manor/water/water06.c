inherit ROOM;
#include <ansi.h>
#include <water.msg>
#include <damage02.c>

string *exit = ({ __DIR__"water05",__DIR__"water06",__DIR__"water07",__DIR__"water08",});

void create()
{
        set("short","Ë®ÁéËþ¶þÂ¥");
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

