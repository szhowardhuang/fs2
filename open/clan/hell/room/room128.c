inherit ROOM;
void create() {
	set( "short", "$HIW$你丢下一把唤云扇。$BLK$" );
	set( "exits", ([
		"down"      : "/open/clan/hell/room/room130",
	]) );
	set( "long", @LONG

$HIB$  ╓──╖╓──╖╓─╖╖╓╥─╖╓──╖╓──╖╓    ╖
$BLU$  ╟──╖╟──╢║  ║║  ║    ╟──╢╙──╖║    ║
$HIC$  ║      ║    ║║  ║║  ║    ║    ║      ║╙─╥╜
$CYN$  ╙      ╙    ╜╙  ╙╜  ╨    ╙    ╜╙──╜  ─╨  
$HIB$                                  ╓──╖╓──╮╓──╖╓──╖╓──╖
$BLU$                                  ╙──╖║    ║╟──╢║      ╟──╖
$CYN$                                        ║╟──╜║    ║║      ║      
$HIC$◆$HIW$────────────────$CYN$╙──╜╙      ╙    ╜╙──╜╙──╜$HIW$─$HIC$◆
$CYN$
由于你对真实世界的牵挂, 你将回到原来的世界。
但是, 希望你不要忘了自己的使命和你对这狂想空间伙伴们的承诺。
你离开狂想空间了。$NOR$

LONG);
	setup();
	replace_program(ROOM);
}
