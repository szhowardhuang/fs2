inherit ROOM;
void create() {
	set( "short", "$HIC$ÐÀ$HIR$¡õ$HIY$²Øµ¶ÃÅ$NOR$" );
	set( "owner", "lts" );
	set( "light_up", 1 );
	set( "build", 10787 );
	set( "object", ([
		"amount1"  : 1,
		"file1"    : "/daemon/class/blademan/obj/iceblade",
		"file9"    : "/open/ping/obj/cloud_fan",
		"amount2"  : 1,
		"amount3"  : 1,
		"amount7"  : 1,
		"file10"   : "/open/capital/obj/blade2",
		"amount6"  : 1,
		"amount9"  : 1,
		"file2"    : "/open/magic-manor/obj/hwa-je-icer",
		"file7"    : "/open/wind-rain/obj/sun_red_cloth",
		"file3"    : "/daemon/class/blademan/obj/iceblade",
		"file4"    : "/daemon/class/blademan/obj/ublade",
		"file8"    : "/daemon/class/blademan/obj/ublade",
		"amount8"  : 1,
		"amount4"  : 1,
		"amount5"  : 1,
		"file6"    : "/daemon/class/blademan/obj/gold-blade",
		"amount10" : 1,
		"file5"    : "/open/ping/obj/cloud_fan",
	]) );
	set( "exits", ([
		"east"      : "/open/clan/sky-wu-chi/room/room72.c",
		"west"      : "/open/clan/sky-wu-chi/room/room131",
	]) );
	set( "long", @LONG
ÕâÀïÊÇ[0;1;5;36m¡õ[1;5m][1;5m¡õ[1;5m¡õ[1;5m¡õ[1;5mU[1;5m¡õ[1;5m¡õ[1;5m¡õ[1;5mY[0mÖ®²Øµ¶·¿...Ö»¼ûÎªÊ×µÄ[0;1;5;31m¡õ[1;5mQ[1;5m¡õ[1;5m¡õ[1;5;33m¡õ[1;5m¡õ[1;5m¡õ[1;5mM[0;1;32m([1ms[1mu[1mn[0m[0;1;32m_[1mm[1mo[1mo[1mn[1m [1mb[1ml[1ma[1md[1me[1m)[1m [0mÉÁÉÁ·¢ÁÁ
Ò»Ö§Ö§[0;1;31m¡õ[1mQ[1m¡õ[1m¡õ[1;33m¡õ[1m¡õ[1m¡õ[1mM[0m¾®È»ÓÐÐòµÄÅÅÁÐÔÚÇ½ÉÏ,Í¬Ê±..............[0;1;31m¡õ[1mQ[1m¡õ[1m¡õ[1;33m¡õ[1m¡õ[1m¡õ[1mM[0m
Ëù·¢³öÀ´µÄ¹âÃ¢Ò²Ê¹ÄãµÄÑÛ¾¦¶ÙÊ±ÏÝÈëÒ»Æ¬[0;1;5;33m¡õ[1;5m¡õ[1;5m¡õ[1;5m¡õ[1;5m¡õ[1;5m¡õ[1;5m¡õ[1;5m¡õ[1;5m¡õ[1;5m¡õ[1;5m¡õ[1;5m~[0m[0;1;5;33m.[1;5m.[1;5m.[1;5m.[1;5m.[1;5m.[1;5m.[1;5m.[1;5m.[1;5m.[1;5m.[0m
¶øÉîÂñµ×µØÏÂµÄ[0;1;35m¡õ[1m¡õ[1m¡õ[1mM[0mÒ²Ê¹Äã¸Ð¾õµ½ÕóÕóµÃÐ°ÆøÖ±ÆË¶øÀ´[0;1;5;35m.[1;5m.[1;5m.[0m[0;1;5;35m.[1;5m.[1;5m.[1;5m.[1;5m.[1;5m.[1;5m.[1;5m.[1;5m.[1;5m.[1;5m.[1;5m.[1;5m.[1;5m.[0m


[0;1;31m¡õ[1mA[1m¡õ[1m¡õ[1m¡õ[1mF[0m
LONG);
	setup();
	replace_program(ROOM);
}
