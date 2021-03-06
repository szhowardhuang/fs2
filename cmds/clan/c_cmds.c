// clan_cmds.c by ACKY 04/04/00

#include <ansi.h>
void print_cmd( string cmd , int rank , string str );
mapping cmds = ([]);
int sum=0,i;
string str_cmds="";

int main( object me )
{
        int o=0;
        int len;
        mixed *file;
        string clan_name,clan_id,top,list,sort,*money,*members,*area;
        file = get_dir("/cmds/clan/",-1);
        sum = sizeof(file);
        for( i=0; i<sum; i++ )
                if( file[i][1]!=-2 )    {
                        len=sizeof(file[i][0]);
                        cmds[o] = file[i][0][0..len-3];
                        o++;
                }
        str_cmds += sprintf(HIM"\n      　　.__________"HIW"帮派指令集"HIM"__________.\n\n");

        str_cmds += sprintf(HIY"\n□ 一般 -\n"NOR);
	print_cmd( "c_goto"    , 3, "帮内瞬间移动" );
	print_cmd( "c_home"    , 4, "回到帮派总部" );
	print_cmd( "c_state"   , 5, "查询帮派状态" );
	print_cmd( "c_donate"  , 7, "帮派钱庄捐钱" );
	print_cmd( "c_deposit" , 7, "帮派钱庄存钱" );
	print_cmd( "c_withdraw", 7, "帮派钱庄领钱" );
	print_cmd( "c_in"      , 8, "进入帮派" );
	print_cmd( "c_out"     , 8, "离开帮派" );
	print_cmd( "c_cmds"    , 8, "帮派指令集" );
	print_cmd( "c_index"   , 8, "帮派说明文件" );
	print_cmd( "c_list"    , 8, "狂想空间帮派总览" );
	print_cmd( "c_view"    , 8, "查询线上帮派玩家" );

	str_cmds += sprintf( HIC"\n□ 区域维护 -\n"NOR );
	print_cmd( "c_board"    , 1, "处理布告栏" );
	print_cmd( "c_set"	, 2, "设定帮派区域" );
	print_cmd( "c_room_make", 3, "扩大帮派地盘" );
	print_cmd( "c_room_del" , 3, "删除帮派房间" );
	print_cmd( "c_room_link", 3, "设定区域连结" );
	print_cmd( "c_room_own" , 3, "设定专属区域" );
	print_cmd( "c_room_des" , 7, "设定区域叙述" );
	print_cmd( "c_room_att" , 7, "设定区域属性" );
	print_cmd( "c_room_item", 7, "设定景观叙述" );
	print_cmd( "c_build"    , 7, "建造区域" );
	print_cmd( "c_store"    , 7, "储存个人物品" );
	print_cmd( "c_take"     , 7, "取出个人物品" );

	str_cmds += sprintf( HIR"\n□ 内政外交 -\n"NOR );
	print_cmd( "c_passwd"   , 1, "设定帮派密码" );
	print_cmd( "c_doc"      , 1, "编写帮派说明" );
	print_cmd( "c_tax"      , 2, "设定帮派税率" );
	print_cmd( "c_gatetax"  , 2, "设定帮派关税" );
	print_cmd( "c_gate"     , 2, "设定闸门状态" );
	print_cmd( "c_alert"    , 3, "设定警戒状态" );
	print_cmd( "c_prestige" , 3, "设定威望经费" );
	print_cmd( "c_agree"    , 3, "接受求和" );
	print_cmd( "c_surrender", 3, "求和" );
	print_cmd( "c_war"      , 3, "宣战" );
	print_cmd( "c_ally"     , 3, "同盟" );
	print_cmd( "c_forgive"  , 3, "特赦令" );
	print_cmd( "c_arrest"   , 3, "帮派通缉令" );
	print_cmd( "c_who"      , 7, "查询帮派境内玩家" );

	str_cmds += sprintf( HIW"\n□ 人事处理 -\n"NOR );
	print_cmd( "c_inherit", 1, "帮主传位" );
	print_cmd( "c_title"  , 1, "更改称号" );
	print_cmd( "c_jail"   , 3, "监禁帮众" );
	print_cmd( "c_member" , 4, "帮众名单" );
	print_cmd( "c_appoint", 4, "任命某人的位阶及职衔" );
	print_cmd( "c_banish" , 4, "开除帮众" );
	print_cmd( "c_join"   , 4, "加入帮派" );
	print_cmd( "c_hire"   , 4, "招募帮派佣兵" );
	print_cmd( "c_obj"    , 4, "装备帮派佣兵" );
	print_cmd( "c_move"   , 4, "移动帮派佣兵" );
	print_cmd( "c_order"  , 6, "命令帮众" );

	if( wizardp(me) )       {
		str_cmds += sprintf( HIY"\n□ 尚未开放之指令 -\n"NOR );
		for( i=0; i<sum; i++ )  {
			if( cmds[i] )
				str_cmds+=sprintf("\t%s\n",cmds[i]);
		}
	}
	me->start_more(str_cmds);
	str_cmds="";
	return 1;
}

void print_cmd( string cmd , int rank , string str )
{
        string rank_str;
        for( i=0; i<sum; i++ )
                if( cmds[i]==cmd )      {
                        switch( rank ) {
                        case 1 : rank_str=HIW"■"NOR; break;
                        case 2 : rank_str=HIW"■"HIC+"■"NOR; break;
                        case 3 : rank_str=HIW"■"HIC+"■"HIY+"■"NOR; break;
                        case 4 : rank_str=HIW"■"HIC+"■"HIY+"■"HIG+"■"NOR; break;
                        case 5 : rank_str=HIW"■"HIC+"■"HIY+"■"HIG+"■"HIB+"■"NOR; break;
                        case 6 : rank_str=HIW"■"HIC+"■"HIY+"■"HIG+"■"HIB+"■"HIR+"■"NOR; break;
                        case 7 : rank_str=HIW"■"HIC+"■"HIY+"■"HIG+"■"HIB+"■"HIR+"■"HIM+"■"NOR; break;
                        case 8 : rank_str="无限制"; break;
                        }
                        str_cmds += sprintf("\t%-16s   %-22s   %-16s\n", cmd , str , rank_str );
                        map_delete( cmds , i );
                        break;
                }
}
