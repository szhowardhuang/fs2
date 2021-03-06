// alias.c

#include <action.h>
#include <ansi.h>
#include <dbase.h>
#include <login.h>
#include <msg.h>

#define MAX_ALIASES     40
#define MAX_CMDS        30
#define WARNING         20
#define MSG_BUSY        "你忙得晕头转向, 不知所措..."   // 出现相同叙述, 可以干扰 run tin

inherit F_SAVE;

mapping alias;

string replace_alias( string str )
{
        string  cmd, arg, *args;
        int     i;

        seteuid(getuid());

	if( str[0..2]=="go " || str[0..2]=="do " || str[0..3]=="ans " || str[0..3]=="gps " )
		return str;
	cmd = ALIAS_D->process_global_alias(str);

	if( mapp(alias) ) {
                if( sscanf( cmd, "%s %s", cmd, arg ) != 2 ) {
                        if( !undefinedp(alias[cmd]) )
                                cmd = replace_string( alias[cmd], "$*", "" );
                }
                else if( !undefinedp(alias[cmd]) ) {
                        cmd = replace_string( alias[cmd], "$*", arg );
                args = explode( arg, " " );
                for( i=0; i<sizeof(args); i++ )
                        cmd = replace_string( cmd, "$" + (i+1), args[i] );
                }
                else
                        cmd = cmd + " " + arg;
        }
        return cmd;
}

string process_input( string str )
{
	string	cmd, verb, arg;
	int	n;

	seteuid(getuid());
	notify_fail( "什么? " + str + "? 请用 help cmds 查询指令。\n" );

	if( in_edit(this_object()) || in_input(this_object()) )
		return "";

	// by babe
	if( !wizardp(this_object()) ) {
		if( query_temp("block_cmd/all") )
			return "";
		if( this_object()->is_busy() ) {
			if( this_object()->is_killing() || this_object()->is_fighting() )
				switch( random(4) ) {
				case  1 : arg = "气血逆行, 浑身麻木, 无法移动。"; break;
				case  2 : arg = "要害受创, 痛得无法移动。"; break;
				case  3 : arg = "心有杂念, 无法专心。"; break;
				default : arg = "体内真气耗尽, 无法移动。";
				}
			else
				arg = MSG_BUSY;
			write( arg + "\n" );
			return "";
		}
	}

	cmd = replace_alias( str );
	n = 1;
	if( cmd[0]=='!' ) {
                arg = query_temp("current_input");
                cmd = arg + cmd[1..<0];
        }
        else if( sscanf( cmd, "%d %s", n, verb ) == 2 && n > 0) {
                verb = replace_alias(verb);
                cmd  = sprintf( "%d %s", n, verb );
        }
	else n = 1;

	add_temp( "cmd_cnt", n );
	set_temp( "last_input", query_temp("current_input") );
	set_temp( "current_input", cmd );
//add by bss 记录下所有wiz所执行的指令, 似乎包括在物品上及房间的void init()
//再增加对可疑玩家的记录
//关起来by bss at 08302001
/*
        user_level=SECURITY_D->get_wiz_level(this_object());
        if((user_level && user_level!=0 && user_level<6) ||
           getuid(this_object())=="ashuar" ||
           query_ip_name(this_object())[0..10]=="140.127.149")
        {
        if(environment(this_object())) place=file_name(environment(this_object()));
        else place="虚无空间";
        record="";
        record=sprintf("%s(%s)于%s做%s在%s\n",
                this_object()->query("name"),this_object()->query("id"),place,cmd,ctime(time()));
        if(user_level>0)
          file="/u/b/bss/record/wiz/"+getuid(this_object());
        else
          file="/u/b/bss/record/ppl/"+getuid(this_object());
        CBIP_D->record(record,file);
        }
*/
	n = query_temp("cmd_cnt");
	if( n>WARNING ) {
		write( "小心喔, 不要一次下太多指令了...\n" );
		add_temp( "WARNING", 1 );
	}
	if( query_temp( "WARNING" ) > 100 ) {
		if( query_temp("robot_room") ) {
			if( query_temp("robot_room")==base_name(environment()) ) {
				delete_temp("msg_buffer");
				set( "startroom", ROBOT_CHECK );
                                tell_object( this_object(),
                                	HIB"侮天鬼王的身影突然出现在一阵烟雾之中。\n"
                                	HIM"侮天鬼王喝道: 哼! 最看不惯机器人了, 在我还没发火之前快滚吧!\n"
                                	HIR"一股令人窒息的可怕杀气正压得你几乎喘不过气来,\n"
                                	"你的心里似乎有一个声音在告诉你:「 快 逃! ”\n"NOR );
                                return "quit";
                        }
                }
		if( environment() ) {
			set_temp( "robot_room", base_name(environment()) );
			set_temp( "WARNING", 80 );
                }
	}
/*
	n = query_temp("cmd_cnt");
        if( n>WARNING ) {
                write( "小心喔, 不要一次下太多指令了...\n" );
                add_temp( "WARNING", 1 );
        }
        if( query_temp( "WARNING" ) > 100 )
                if( ((time()+28800)%86400) > 28800 ) {
                        if( query_temp("robot_room") )
                                if( query_temp("robot_room")==base_name(environment(this_object())) ) {
                                        delete_temp("msg_buffer");
                                        set( "startroom", ROBOT_CHECK );
					this_object()->set_temp("must_be_quit",1);
                                        tell_object( this_object(),
                                             HIB"侮天鬼王的身影突然出现在一阵烟雾之中。\n"
                                             HIM"侮天鬼王喝道: 哼! 最看不惯机器人了, 在我还没发火之前快滚吧!\n"
                                             HIR"一股令人窒息的可怕杀气正压得你几乎喘不过气来,\n"
                                                "你的心里似乎有一个声音在告诉你:「 快 逃! ”\n"NOR );
                                        return "quit";
                                }
                        if( environment(this_object()) ) {
                                set_temp( "robot_room", base_name(environment(this_object())) );
                                set_temp( "WARNING", 80 );
                        }
                }
                else {
                        write( MSG_BUSY );
                         if(!this_object()->is_fighting())
                        start_busy( random(query("age"))/2 );
                        set_temp( "WARNING", 0 );
                }

*/
	if( n>MAX_CMDS ) {
                write( MSG_BUSY );
                set( "startroom", ROBOT_CHECK );
                if( !this_object()->is_fighting() )
			start_busy( random(query("age")) );
        }
        return cmd;
}

int set_alias(string verb, string replace)
{
        if( !replace ) {
                if( mapp(alias) ) map_delete(alias, verb);
                return 1;
        } else {
                if( !mapp(alias) ) alias = ([ verb:replace ]);
                else if( sizeof(alias) > MAX_ALIASES )
                        return notify_fail("您设定的 alias 太多了，请先删掉一些不常用的。\n");
                else alias[verb] = replace;
                return 1;
        }
}

mapping query_all_alias()
{
        return alias;
}
