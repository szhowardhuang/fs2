// c_room_make.c by ACKY

inherit F_CLEAN_UP;

string get_file_name(string dir);
void create_room(string file);

int help( object me )
{
	write(
"\n\tc_room_make: 扩张帮派地盘。
\n\t帮内人数(c_join)愈多, 帮派威望(c_prestige)愈高, 能占领的地盘愈大。\n\n"
	);
	return 1;
}

int main( object me )
{
	string	code, dir, file, clan;
	object	room;

	if( !me->query("clan") )
                return 0;
        if( me->query("clan/rank") > 3 )
                return notify_fail( "无权使用此指令。\n" );
	if( !CLAN_D->is_clan_room(me) )
		return notify_fail( "此区域并非本帮所属地盘。\n" );
	clan = me->query("clan/id");
	if( CLAN_D->clan_query( clan, "gold" ) < 1000 )
		return notify_fail( "帮派存款不足。\n" );
	if( sizeof(get_dir("/open/clan/" + clan + "/room/")) >
		CLAN_D->clan_query( clan , "develop" )/100 + sizeof(CLAN_D->clan_query( clan, "members" )) )
		return notify_fail( "帮派区域扩张已达上限。\n" );

	dir = CLAN_D->get_clan_dir(me);
	file = dir + get_file_name(dir);

	code = @CODE
inherit ROOM;
void create() {
	set( "short", "新区域" );
	set( "long", @LONG
此地初建, 空无一物。
LONG);
	setup();
	replace_program(ROOM);
}
CODE;

	write_file( file, code, 1 );
	if( !room = load_object(file) )
		return notify_fail( "建造新区域失败。\n" );
	else
		write( "花了壹千两黄金建造新区域。\n" );
	if( wizardp(me) )
		write( "新建的档案名称为: " + file + "\n" );
	CLAN_D->add_money( me->query("clan/id"), -1000 );
	return 1;
}

string get_file_name( string dir )
{
        int i;
	i = 1;
        while(i++)
		if( file_size( dir+"room/room"+i+".c" ) == -1 )
			return "room/room"+i+".c";
}

