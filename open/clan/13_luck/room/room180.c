inherit ROOM;
void create() {
	set( "short", "ÍòÀï³¤Õ÷Â¥" );
	set( "owner", "adeyzit" );
	set( "object", ([
		"amount2"  : 1,
		"file1"    : "/open/prayer/obj/crystal2",
		"amount1"  : 1,
		"file2"    : "/open/prayer/obj/crystal1",
	]) );
	set( "build", 10068 );
	set( "light_up", 1 );
	set( "exits", ([
		"down"      : "/open/clan/13_luck/room/room181",
		"up"        : "/open/clan/13_luck/room/room246",
	]) );
	set( "long", @LONG

¡¡¡¡´ËÂ¥Îª¼ÇÂ¼×ÅĞ¡¶«Ğ°¡¢¿ñÓ°¶ş´ú°ïÖ÷¡¢¿ñÁú¡¢·çÄ§ÀË×Ó¡¢´ËËÄÈË
µÄÓ¢ÓÂÊÂ¼££¬[0;1;36m¡õ[1mF[1m¡õ[1m¡õ[1m¡õ[1mD[1m¡õ[1m¡õ[1;37m¡õ[1mB[1;32m¡õ[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1mB[1;37m¡õ[1mB[1;35m¡õ[1mn[1m¡õ[1mQ[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1;37m¡õ[1mB[1;31m¡õ[1m_[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1;37m¡õ[1mB[1;33m¡õ[1mo[1m¡õ[1ms[1m¡õ[1m¡õ[1;37m¡õ[1mB[0m
[0;1;34m¡õ[1m¡õ[1m¡õ[1mB[1m¡õ[1m¡õ[0m¡¢[45mÕ¶Ìì×Ó[0m¡¢[0;1;33;46m¡õ[1mD[1m¡õ[1mZ[1m¡õ[1mt[0m¡¢[30;47mÈ¡µÄ¹íÍõÍ·[0m¡¢[41m¿­ĞıÊ¤Àû¹é[0m¡£Ö®ºó´ËËÄÈË¾Í
³ÉÎª°ïÅÉµÄÖØÒª½ÇÉ«¡¢Ò²±»¹éÎª[0;1;31m¡õ[1mN[1m¡õ[1m¡õ[1m¡õ[1mK[1m¡õ[1m¡õ[0mÖĞ¡£ 

LONG);
	setup();
	replace_program(ROOM);
}
