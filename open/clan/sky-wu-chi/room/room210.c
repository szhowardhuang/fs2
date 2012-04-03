inherit ROOM;
void create() {
	set( "short", "$HIW$¸ß¼¶Á·Îä³¡$HIW$" );
	set( "owner", "biwem" );
	set( "object", ([
		"amount4"  : 1,
		"amount2"  : 1,
		"amount8"  : 1,
		"amount3"  : 1,
		"file6"    : "/open/ping/obj/cloud_fan",
		"file4"    : "/open/magic-manor/obj/evil-gwe-blade",
		"file5"    : "/open/mon/obj/ghost-legging",
		"amount5"  : 1,
		"amount7"  : 1,
		"file1"    : "/open/capital/obj/blade2",
		"amount1"  : 1,
		"file2"    : "/open/magic-manor/obj/lin-cloud-fan",
		"file3"    : "/open/mon/obj/ghost-claw",
		"file7"    : "/open/magic-manor/obj/fon-sky-sword",
		"file8"    : "/open/capital/obj/blade2",
		"amount6"  : 1,
	]) );
	set( "build", 10061 );
	set( "exits", ([
		"west"      : "/open/clan/sky-wu-chi/room/room121",
		"south"     : "/open/clan/sky-wu-chi/room/room176.c",
	]) );
	set( "light_up", 1 );
	set( "long", @LONG
       ÕâÀïµ½´¦²¼ÂúÁË[0;1;5;31m¡õ[1;5m¡õ[1;5m¡õ[1;5m¡õ[0m£¬ÔÚ¿ÕÆøÖÐÓÖ´ø×Å[0;1;5;35m¡õ[1;5mC[1;5m¡õ[1;5m¡õ[0m£¬¸Ð¾õ
   ¾ÍºÃÏñµ½ÁËÒ»´¦½£Ê¿µÄÐÞÁ·Çø£¬ÔÚÔ¶´¦ÓÐÒ»µÀ¸ß´óµÄÈË
   Ó°£¬×ÐÏ¸Ò»¿´Ô­À´ÊÇ[0;1;5;36m¡õ[1;5mp[1;5m¡õ[1;5m¡õ[0mÔÚÄÇÀïÐÝÏ¢£¬Ô­À´ÕâÀïÊÇ[0;1;5;36m¡õ[1;5mp[1;5m¡õ[1;5m¡õ[0m
   µÄ[0;1;5;32m¡õ[1;5mm[1;5m¡õ[1;5m\[1;5m¡õ[1;5m¡õ[1;5m¡õ[1;5mM[1;5m¡õ[1;5m¡õ[1;5m¡õ[1;5m¡õ[1;5m¡õ[1;5m¡õ[0m¡£

LONG);
	setup();
	replace_program(ROOM);
}
