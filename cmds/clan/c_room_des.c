// c_room_des.c by ACKY
inherit F_CLEAN_UP;

#include <clanf.h>

string filename, file;

void set_long( object me, string str );
int help( object me );

int main( object me, string arg )
{
	object env;
	seteuid(getuid());
	if( !me->query("clan") ) return 0;
	if( arg != "here" )      return help(me);
	if( !CLAN_D->is_clan_room(me) )
		return notify_fail( "此区域并非本帮所属地盘。\n" );
	env = environment(me);
	if( env->query("owner") != me->query("id") && me->query("clan/rank") > 3 )
		return notify_fail( "此处并非您的区域。\n" );
	filename = base_name(env) + ".c";
	file = read_file(filename);
	write( "是否更改短叙述? [N] : " );
	input_to( "ask_short", me );
	return 1;
}

void ask_short( string str, object me )
{
	if( !strlen(str) || ( str[0] != 'y' && str[0] != 'Y' ) ) {
		write( "是否更改长叙述? [N] : " );
		input_to( "ask_long", me );
		return;
	}
	write( "请输入短叙述: " );
	input_to( "set_short", me );
}

void set_short( string str, object me )
{
	string *strs;
	int i;

	if( !strlen(str) ) {
		write( "请输入短叙述: " );
		input_to( "set_short", me );
		return;
	}

	strs = explode( file, "\n" );
	for( i=0; i<sizeof(strs); i++ )
		if( strsrch( strs[i], "\"short\"") != -1 ) break;
	strs[i] = "\tset( \"short\", \"" + str + "\" );";
	file = implode( strs, "\n" ) + "\n";
	write( "是否更改长叙述? [N] : " );
	input_to( "ask_long", me );
}

void ask_long( string str, object me )
{
	if( !strlen(str) || ( str[0] != 'y' && str[0] != 'Y' ) ) {
		write_file( filename, file, 1 );
		C_ROOM->update_keep( filename );
		write( "OK.\n" );
		return ;
	}
	write( "请输入长叙述: " );
	me->edit( (: set_long, me :) );
}

void set_long( object me, string str )
{
	string *strs;
	int i, a, b;

	if( strlen(str) < 200 ) {
		write( "你输入的叙述太少了，再写多一点吧。\n" );
		write( "请输入长叙述:" );
		me->edit( (: set_long, me :) );
		return;
	}

	strs = explode( file, "\n" );
	for( i=0; i<sizeof(strs); i++ )
		if( strsrch( strs[i], "@LONG" ) != -1 ) a = i;
		else if( strsrch(strs[i], "LONG);" ) != -1 ) {
			b = i;
			break;
		}
	file = implode( strs[0..a], "\n" ) + "\n" + replace_string( str, "\"", " " ) + implode( strs[b..<0], "\n" ) + "\n";

	write_file( filename, file, 1 );
	C_ROOM->update_keep( filename );
	write( "OK.\n" );
}

int help( object me )
{
	write( @HELP
指令格式: c_room_des here
指令说明: 修改目前所处区域之叙述。
	  除了阶级三之外, 也可自行修改自己的区域。

						by ACKY 08/17/2000
HELP);
	return 1;
}
