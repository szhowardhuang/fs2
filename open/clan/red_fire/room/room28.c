// Room : /open/clan/red_fire/room/room28.c
 inherit ROOM;

void create()
{
        seteuid(getuid());
	set( "short", "$HIM$● $HIR$教主 $HIY$研究室$HIM$ ●$NOR$" );
	set( "owner", "fsmud" );
	set( "exits", ([
		"east"      : "/open/clan/red_fire/room/room108",
		"west"      : "/open/clan/red_fire/room/room110.c",
	]) );
	set( "object", ([
		"amount5"  : 1,
		"file5"    : "/open/main/obj/bird_legging",
		"file3"    : "/open/gsword/obj1/bloodsword",
		"file10"   : "/open/gsword/npc2/sadsword",
		"file4"    : "/open/main/obj/firesword",
		"amount3"  : 1,
		"amount8"  : 1,
		"amount4"  : 1,
		"file8"    : "/open/gsword/obj1/karmband",
		"amount6"  : 1,
		"amount2"  : 1,
		"amount1"  : 1,
		"file6"    : "/open/main/obj/m_cloak",
		"file2"    : "/open/capital/guard/gring",
		"file7"    : "/open/gsword/obj1/khelmet",
		"file9"    : "/open/gsword/obj1/ring",
		"amount7"  : 1,
		"amount10" : 1,
		"file1"    : "/open/tendo/kunlun/obj/cloud-dragon-claw",
		"amount9"  : 1,
	]) );
	set( "build", 10040 );
	set( "no_transmit", 1 );
	set( "no_clean_up", 0 );
	set( "clan_room", "红莲教" );
	set( "light_up", 1 );
	set( "long", @LONG

1.红莲观世音菩萨下凡普渡众生所在之地。
2.第一代佛法传人创教，纪念观音之大德所称为红莲教。
  但是教主之名无人所知。
3.经过一次大灾难后，红莲教成为人间炼狱，面目全非。
4.数年之后一位小女孩的诞生，红莲观音显灵，
  替她取名叫......爱玫。
5.爱玫成年后，再度创教，红莲教重出，
  并且以扶助众人为教规。
6.创教不久，再次受到打击，全教被灭......。
7.之后爱玫教主与众人不负使命，再次重整红莲。
8.现在为人间仙境，众人所向往之世外桃源......。


LONG);
	set( "cmkroom", 1 );
	setup();

	}
