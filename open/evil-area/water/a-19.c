inherit ROOM;
#include <ansi.h>

void create ()
{
	set("short",HIC"çü Ñï ºş"NOR);
	set("long",@LONG
ÄñÌäÇå´àÇÒÏìÁÁ£¬ÕóÕóÅ¯·ç´µ·÷£¬¸Ğ¾õºÃ²»Í´¿ì¡«
LONG);
	set("evil_area",1);
	set("no_transmit",1);
	set("exits",([
"north":__DIR__"a-20",
"east":__DIR__"a-18",
]));
	setup();
}

 