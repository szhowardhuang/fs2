// Room : /open/clan/ou-cloud-club/room/room106.c
 inherit ROOM;

void create()
{
        seteuid(getuid());
	set( "long", @LONG
这里的水深长达五六公尺,再往后的深度恐怕有过之而无
不及,看来只能以游泳的方式前进了,在这种不知道水面下有
什么生物的情况下游泳而过,真是令人胆战心惊啊,不过大家
心知肚明,既然武功高强,唯一会令你烦恼的,只不过是会弄湿
身上的华丽衣饰吧 :p
LONG);
	set( "cmkroom", 1 );
	set( "clan_room", "傲云山庄" );
	set( "short", "$HIW$恶魔城$HIR$地下水脉$NOR$" );
	set( "owner", "bbsboss" );
	set( "object", ([
		"file4"    : "/open/magic-manor/obj/evil-gwe-blade",
		"file5"    : "/open/magic-manor/obj/evil-gwe-blade",
		"amount1"  : 1,
		"amount5"  : 1,
		"file1"    : "/open/magic-manor/obj/evil-gwe-blade",
		"file2"    : "/open/magic-manor/obj/evil-gwe-blade",
		"amount2"  : 1,
		"amount4"  : 1,
	]) );
	set( "light_up", 1 );
	set( "build", 10894 );
	set( "exits", ([ /* sizeof() == 2 */
  "east" : "/open/clan/ou-cloud-club/room/room110.c",
  "west" : "/open/clan/ou-cloud-club/room/room105",
]) );
	set( "no_clean_up", 0 );
	set( "no_transmit", 1 );
	setup();

	}
