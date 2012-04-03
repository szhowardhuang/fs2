// thunder_9.c by ACKY

inherit ROOM;
#include <ansi.h>
#include <thunder.msg>

void create()
{
	set( "short", HIY"…dÑ¸À×·å…d"NOR );
	set( "long", (: print_msg :) );
	set( "no_transmit", 1 );
	set( "light_up", 1 );    
        set( "exits", ([ /* sizeof() == 2 */
		"north" : __DIR__"thunder_6",
		"west"  : __DIR__"thunder_8",
	]));
        setup();
}

