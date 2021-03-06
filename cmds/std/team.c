// team.c

#include <ansi.h>

inherit F_CLEAN_UP;
mapping level = ([
	0:BLU "【 Ｆ 】" NOR,
	1:HIB "【 Ｅ 】" NOR,
	2:MAG "【 Ｄ 】" NOR,
	3:CYN "【 Ｃ 】" NOR,
	4:HIC "【 Ｂ 】" NOR,
	5:HIW "【 Ａ 】" NOR,
	6:HIR "【 Ｓ 】" NOR,
	]);

int count_total_power_lv(object leader);
int count_lv(int power);
int main(object me, string arg)
{
        mapping map;
	object *t;
	string team_name;
	object team_leader;
	object ob1;
	object leader;
	object *member;
	object *mmm;
	string str;
	string targ;
	object *list;
	int team_cnt=0;
	int i,z;
       seteuid(getuid());

	if( !arg ) {
		if( !pointerp(t = me->query_team()) )
			return notify_fail("你现在并没有参加任何队伍。\n");
		team_leader=me->query_temp("leader");
		team_name=team_leader->query_temp("team_name");
		write("队名："+team_name+"\n");
		write("领队："+team_leader->name()+"\n");
		write("你现在队伍中的成员有：\t气\t关系\n");
		for( i=0; i<sizeof(t); i++ )
			write("  " + "\t"+ t[i]->name(1) + "\t\t"+t[i]->query("kee") +"\t" + me->query("人际关系/"+t[i]->query("id")) + "\n");
		return 1;
	}
	if( arg=="query" )
	{
		str="◎ 狂想空间\n";
		str+=sprintf("%-20s%-20s%-20s%-10s\n","队名","领队","队员人数","强度等级");
		str+="───────────────────────────────────\n";
		list=users();
		for(i=0;i<sizeof(list);i++)
			if(list[i]->is_team_leader())
			{
				team_cnt++;
				leader=list[i];
				str+=sprintf(HIY+"%-20s"+HIC+"%-20s"+HIW+"%-20d"+"%-20s",list[i]->query_temp("team_name"),list[i]->name(),sizeof(list[i]->query_team()),level[count_lv(count_total_power_lv(leader))]);
			str+="\n";
			}
		str+="───────────────────────────────────\n";
		str+=sprintf("目前狂想空间共有 %d 支队伍。\n",team_cnt);
		if(team_cnt>0)
		write(str);
		else write("目前狂想空间没有任何队伍。\n");
		return 1;
	}
	if( arg=="dismiss" ) {
		if(me->query_temp("use_form")==1)
			return notify_fail("你的伙伴们现在正在集合力量，你忍心脱离 ?\n");
		if( !pointerp(t = me->query_team()) )
			return notify_fail("你现在并没有参加任何队伍。\n");
		if( me->is_team_leader() ) {
			message("team", me->name(1) + "将队伍解散了。\n", t, me);
			write("你将队伍解散了。\n");
		} else {
			message("team", me->name(1) + "决定脱离队伍。\n", t, me);
			write("你脱离了你的队伍。\n");
		}
		team_leader=me->query_temp("leader");
                if(sizeof(team_leader->query_team())==2 && !me->is_team_leader()) //判断队伍中是否剩下自己与队长两人
                  {                  	
                  	team_leader->dismiss_team();
                  	tell_object (team_leader,HIY"你的队伍成员全数脱离队伍，队伍解散了!!\n"NOR);
                  }else
		me->dismiss_team();
		return 1;
	}
	if( sscanf(arg, "name %s", arg)==1) {
		if(!me->is_team_leader())	return notify_fail("只有领队可以设定队名。\n");
		me->set_temp("team_name",arg);
		write("设定队名为"+arg+"\n");
		return 1;
	}
	if( sscanf(arg, "with %s", arg)==1 ) {
		object ob;

		if( !(ob = present(arg, environment(me)))
		||	!living(ob)
		||	!ob->is_character()
		||	ob==me )
			return notify_fail("你想和谁成为伙伴？\n");

		if( !pointerp(me->query_team()) || me->is_team_leader() ) {
			if( me==(object)ob->query_temp("pending/team") ) {
				if( !pointerp(me->query_team()) ) {
					ob->add_team_member(me);
					message_vision("$N决定加入$n的队伍。\n", me, ob);
					ob->set_temp("leader",ob);
					me->set_temp("leader",ob);
					me->set_leader(ob);
					if(!ob->query_temp("team_name")) 
						ob->set_temp("team_name","未定");
				} else {
					me->add_team_member(ob);
					ob->set_temp("leader",me);
					ob->set_leader(me);
					me->set_temp("leader",me);
					if(!me->query_temp("team_name"))
						me->set_temp("team_name","未定");
					message_vision("$N决定让$n加入队伍。\n", me, ob);
				}
				ob->delete_temp("pending/team");
				return 1;
			} else {
				message_vision("$N邀请$n加入$P的队伍。\n", me, ob);
				tell_object(ob, YEL "如果你愿意加入，请用 team with " + me->query("id") + "。\n" NOR);
				me->set_temp("pending/team", ob);
				return 1;
			}
		} else
			return notify_fail("只有队伍领袖可以邀请别人加入。\n");
	}
	if( sscanf(arg, "talk %s", arg)==1 ) {
		if( !pointerp(t=me->query_team()) )
			return notify_fail("你现在并没有和别人组成队伍。\n");
		message("team", HIW "【队伍】" + me->name(1) + "：" + arg + "\n" NOR, t);
		return 1;
	}
	if( sscanf( arg, "form %s at %s", arg, targ ) == 2 ) {
            object obj1;
		map = me->query_skill_map();
		if( undefinedp(map["array"]) )
			return notify_fail( "你目前并无使用阵法。\n" );
		if( map["array"] == "bad-array" && me->query("family/family_name") != "恶人谷" )
			return notify_fail( "你无法使用恶人邪阵。\n" );
		if( map["array"] == "sha-array" && me->query("family/family_name") != "仙剑派" )
			return notify_fail( "你无法使用仙剑剑阵。\n" );

		if( !pointerp( t=me->query_team() ) || !me->is_team_leader() )
			return notify_fail( "你必须是一个队伍的领袖才能组织阵形。\n" );
		if( !me->query_skill( arg, 1 ) )
			return notify_fail( "这种阵形你没学过。\n" );
		mmm=me->query_team();
		targ = lower_case(targ);
                ob1 = present( targ, environment(me) );
    if(!ob1) return notify_fail("找不到"+targ+"!!\n");
  if( !ob1->is_character() || ob1->is_corpse() )
    return notify_fail("看清楚一点，那并不是活物。\n");
		message_vision( "$N所领的队伍摆\开阵式对$n展开攻击!\n", me, ob1 );
		me->set_temp("arrayp",1);          //不管leader是何门何派,使用阵法就有5 sec无法使用特功
                call_out("remove_arrayp",5,me);    //因为有这个所以取消下面对仙剑的限制
		for( z=0; z<sizeof(me->query_team()); z++ )
			mmm[z]->kill_ob(ob1);
		return SKILL_D(arg)->form_array(me);
 
              
// appo 对shasword leader 所加上的限制..避免用hsa_kee
//         if( leader->query("family/family_name") != "仙剑派")
//{
//   leader->set_temp("no_power",1);
//   leader->apply_condition("no_power",1);
//}
	}
}

int help(object me)
{
	write(@HELP
队伍指令使用方法:

team name <名称>           - 设定队伍名称。
team with <某人>           - 跟某人组成队伍。必须要双方都同意加入才会生效。
team dismiss               - 离开队伍。若下此指令的是领队，则整个队伍会解散。
team talk <讯息>           - 跟队伍里其他的人谈话，可以用 tt <讯息> 替代。
team form <阵法> at <目标> - 如果队伍的领队学过阵法的话，可以将队伍中的成员组织成
                             某种阵形，组成阵形的状态只要领袖一移动就会解除。
team query                 - 查询目前有那些玩者组成的队伍。

直接下 team 指令时则会显示你目前是否有加入队伍及队员名单。
HELP
	);
	return 1;
}
int count_total_power_lv(object leader)
{
	int total=0;
	object *member;
	int i;
	member=leader->query_team();
	for(i=0;i<sizeof(member);i++)
		total+="/daemon/skill/array"->get_attack_skill_lv(member[i])+member[i]->query_temp("apply/attack");
	return total;
}
int count_lv(int power)
{
	if(power<30) return 0;
	if(power<300) return power/50;
	return 6;
}
int remove_arrayp(object me)
{
   if(me)
   me->delete_temp("arrayp",1);
   return 1;
}


