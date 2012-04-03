inherit ROOM;
void create() {
	set( "short", "$HIM$※$HIR$神秘$HIY$密道$HIM$※$NOR$" );
	set( "build", 70 );
	set( "exits", ([
		"up"        : "/open/clan/red_fire/room/hall.c",
		"bor"       : "/open/clan/red_fire/room/room102.c",
		"pipi"      : "/open/clan/red_fire/room/room133",
		"boy"       : "/open/clan/red_fire/room/room111.c",
		"borcc"     : "/open/clan/red_fire/room/room174",
		"welo"      : "/open/clan/red_fire/room/room68",
	]) );
	set( "long", @LONG
此处在$HIR$红莲$NOR$初创时就已存在了，没有人知道$HIM$初代帮主$NOR$兴建这条$HIY$密道$NOR$有
何用意。而这个密秘相传也只有$HIC$帮主$NOR$才知晓。一般帮众若无$HIC$帮主$NOR$同意擅闯
此地，就会受到帮规最严厉的处分。


LONG);
	setup();
	replace_program(ROOM);
}
