// Room : /open/clan/red_fire/room/room49.c
 inherit ROOM;

void create()
{
        seteuid(getuid());
	set( "short", "$HIW$【$HIC$护城河$HIW$】$NOR$" );
	set( "object", ([
		"amount1"  : 2,
		"amount6"  : 1,
		"file2"    : "/open/killer/headkill/obj/world_dag",
		"amount2"  : 1,
		"file3"    : "/open/killer/obj/k_ring",
		"file5"    : "/open/love/obj/cloth1",
		"file1"    : "/open/killer/headkill/obj/bluekill",
		"file9"    : "/open/mogi/dragon/obj/key",
		"file7"    : "/open/ping/obj/chilin_legging",
		"file4"    : "/open/port/obj/wolf_ring",
		"amount7"  : 1,
		"file8"    : "/open/badman/obj/badhelmet",
		"amount5"  : 1,
		"amount3"  : 1,
		"amount8"  : 1,
		"amount9"  : 1,
		"amount4"  : 1,
		"file6"    : "/open/wu/npc/obj/armband",
	]) );
	set( "build", 10040 );
	set( "no_transmit", 1 );
	set( "no_clean_up", 0 );
	set( "light_up", 0 );
	set( "long", @LONG

               $HIC$ ╮  ╮  ╮  ╮
                ╰╮╰╮╰╮╰╮
                  ╰╮╰╮╰╮╰╮
                    ╰╮╰╮╰╮╰╮
                      ╰╮╰╮╰╮╰╮
                        ╰╮╰╮╰╮╰╮
                          ╰  ╰  ╰  ╰
                         
                        $HIY$寻情记           

                    $HIM$欲寻知己无处寻，
                    只求真情无地求，
                    如今空待佳人音；
                    春去秋来心已殆。  $HIR$爱玫 $HIW$笔$NOR$


LONG);
	set( "cmkroom", 1 );
	set( "exits", ([ /* sizeof() == 2 */
		"south"     : "/open/clan/red_fire/room/room51.c",
		"north"     : "/open/clan/red_fire/room/room52.c",
]) );
	setup();

	}
