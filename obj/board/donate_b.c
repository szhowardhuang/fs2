#include <ansi.h>

inherit BULLETIN_BOARD;

void create()
{
	set_name( YEL"Ê¯±Ú"NOR, ({ "wall", "board" }) );
	set( "location", "/open/wiz/donate" );
	set( "board_id", "donate_b" );
	set( "capacity", 100 );
	setup();
}
