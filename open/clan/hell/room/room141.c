inherit ROOM;
void create() {
	set( "short", "防风林缺口" );
	set( "exits", ([
		"north"     : "/open/clan/hell/room/room134",
		"east"      : "/open/clan/hell/room/room138.c",
		"west"      : "/open/clan/hell/room/room144.c",
	]) );
	set( "long", @LONG
沿着沙滩飞掠至此,发现北面的防风林在此似乎有个缺口,地上也开始混杂了
一些泥土,而不是柔软的沙粒,往北面防风林附近仔细的观察了一下,果然发现地
上有一些隐隐约约的足迹,看来此地当可寻得岛上的道路,你抱着寻得人烟的喜
悦,提起身法,往林中投去.

LONG);
	setup();
	replace_program(ROOM);
}
