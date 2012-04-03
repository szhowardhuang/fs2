// pkr8.c by konn
inherit ROOM;

void create()
{
        set("short","µÚÒ»ÎäµÀ¹Ý");
	set( "build", 85 );
        set("long", @LONG



LONG);
        set("exits", ([ /* sizeof == 3 */
            "north" : __DIR__"pkr5",
            "east"  : __DIR__"pkr9",
            "west"  : __DIR__"pkr7",
      ]));
set("no_scale",1);
        set("no_transmit", 1);
        set("light_up", 1);
        setup();
}

