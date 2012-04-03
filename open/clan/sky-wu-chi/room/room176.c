inherit ROOM;
void create() {
	set( "short", "Ğ¡Ö¾µÄ·¿¼ä" );
	set( "object", ([
		"file1"    : "/open/sky/obj/lucky_grasslink",
		"amount1"  : 1,
	]) );
	set( "owner", "biwem" );
	set( "build", 10026 );
	set( "exits", ([
		"east"      : "/open/clan/sky-wu-chi/room/room357",
		"north"     : "/open/clan/sky-wu-chi/room/room210.c",
		"up"        : "/open/clan/sky-wu-chi/room/room175.c",
		"chome"     : "/open/clan/sky-wu-chi/room/hall.c",
	]) );
	set( "light_up", 1 );
	set( "long", @LONG
      ´Ë´¦µ½´¦²¼ÂúÁË½£Æø£¬ÔÚµØÉÏ³äÂúÁË½£ºÛ£¬ºÃÏñÓĞ
  ÈËÔÚÕâĞŞÁ·ÁËºÜ¾ÃµÄÑù×Ó£¬×ĞÏ¸Ò»¿´Ô­À´ÊÇÌìµÀÎŞ¼«µÄ
             [0;1;5;33m¡õ[1;5mu[1;5m¡õ[1;5mC[1;5m¡õ[1;5m¡õ[1;5m¡õ[1;5m¡õ[1;5m¡õ[1;5m¡õ[1;5m¡õ[1;5mv[1;5;36m¡õ[1;5mp[1;5m¡õ[1;5m¡õ[1;5m¡õ[1;5mM[1;5m¡õ[1;5m¡õ[1;5m¡õ[1;5m¡õ[1;5m¡õ[1;5m¡õ[0m
  ÔÚµØÉÏÓĞÒ»¿éÊ¯±®ÉÏÃæĞ´×Å£º
        ·ÇÇëÎğÈëÕß...Ö»ÓĞÒ»ÌõÂ·  
                 [0;1;5;31m¡õ[1;5my[1;5m¡õ[1;5m¡õ[1;5m¡õ[1;5mz[0m
        [0;1;5;36m [1;5m [1;5m [1;5m [1;5m [1;5m [1;5m*[1;5m^[1;5m_[1;5m^[1;5m*[1;5m.[1;5m.[1;5m¡õ[1;5mp[1;5m¡õ[1;5m¡õ[1;5m.[1;5m.[0m

LONG);
	setup();
	replace_program(ROOM);
}
