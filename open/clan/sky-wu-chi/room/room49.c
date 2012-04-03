// Room : /open/clan/sky-wu-chi/room/room49.c
 inherit ROOM;

void create()
{
        seteuid(getuid());
	set( "long", @LONG
    一走进房间,你隐约闻到一股奇怪的[0;1;31m□[1m□[1m□[1m□[1m□[1m□[0m,让你感到异常难受,
而在北面的墙上,刻着一行字 「[0;1;31m□[1mA[1m□[1m^[1m□[1m□[1m,[1m□[1mw[1m□[1mO[1m□[1m□[1m□[1m~[1m□[1m□[0m” 显现出主人深厚的功力
你的目光接着转向房间的右半边,你看到了许多[0;1;31m□[1mK[1m□[1mW[1m□[1m□[1m□[1m□[1m□[1m□[1m□[1m_[1m□[1mc[0m,
在你走近宝箱之时,忽然从房间一角射出一些暗器,赫然竟是「[0;1;31m□[1m□[1m□[1m□[1m□[1m□[1m□[1mw[0m”
你惊险的躲过暗器,也吓出一身冷汗,你心中只想着要赶紧离开这里.

LONG);
	set( "short", "幸运之间" );
	set( "build", 10010 );
	set( "light_up", 1 );
	set( "object", ([
		"file4"    : "/open/killer/obj/s_pill",
		"amount10" : 1,
		"file8"    : "/open/killer/obj/dagger",
		"file5"    : "/open/killer/headkill/obj/f_dag",
		"file10"   : "/obj/gift/hobowdan",
		"file3"    : "/open/mogi/dragon/obj/scale",
		"file9"    : "/open/clan/area/home/trap",
		"amount8"  : 1,
		"amount3"  : 1,
		"amount5"  : 1,
		"amount9"  : 1,
		"amount2"  : 57,
		"file2"    : "/open/killer/obj/black",
		"amount1"  : 1,
		"amount4"  : 95,
		"file1"    : "/open/killer/headkill/obj/world_dag",
	]) );
	set( "owner", "luckyneck" );
	set( "exits", ([
		"south"     : "/open/clan/sky-wu-chi/room/room56",
	]) );
	set( "no_clean_up", 0 );
	set( "clan_room", "天道无极" );
	set( "no_transmit", 1 );
	set( "cmkroom", 1 );
	setup();

	}
