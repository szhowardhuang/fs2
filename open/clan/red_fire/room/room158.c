inherit ROOM;
void create() {
	set( "short", "$HIY$※$NOR$$HIC$惊$NOR$$HIM$芸$NOR$的$HIC$惊$NOR$$HIM$芸$NOR$$HIR$宝殿$NOR$$HIY$※$NOR$" );
	set( "owner", "seiko" );
	set( "build", 4008 );
	set( "light_up", 1 );
	set( "exits", ([
		"west"      : "/open/clan/red_fire/room/room77",
	]) );
	set( "long", @LONG

一座雄伟壮观的$HIB$寺院$NOR$映入眼帘，抬头一看，门顶挂了一块木造的匾额，
上面$HIB$蓝$NOR$底$HIR$红字$NOR$写着「$HIR$惊芸宝殿$NOR$”四个大字。此四字写得甚是苍劲有力，
看得你慑定入神，心想：「提此四字的人，定是文武全才的大高人。”
眼前伫立着一块六人长，二人高的$YEL$石碑$NOR$，碑上刻着五个大字：

                    $HIG$天下$NOR$$HIM$第一$NOR$$HIR$宝殿$NOR$


LONG);
	setup();
	replace_program(ROOM);
}
