// land_8.c by ACKY

inherit ROOM;
#include <ansi.h>
#include <land.msg>

void create()
{
	set( "short", HIG"������ԭ��"NOR );
	set( "long", (: print_msg :) );
	set( "no_transmit", 1 );
	set( "light_up", 1 );    
        set( "exits", ([ /* sizeof() == 2 */
		"north" : __DIR__"land_5",
		"west"  : __DIR__"land_7",
		"east"  : __DIR__"land_9",
	]));
        setup();
}

