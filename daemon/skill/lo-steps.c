//金风细雨楼skill 之楼诀身法
//这是金风细雨楼npc的标志,使用这一个dodge skill
#include <combat.h>
#include <ansi.h>
inherit SKILL;

string *dodge_msg = ({
 "$n步踩莲花身形飘晃地踏出一式"HIC"‘楼步莲车’"NOR"，眼光犀利地读出$N的攻势，不多不少的闪出一个空隙闪过了$N攻击\n",
 "眼看$N的攻击无法退闪，$n索性应前突进，使出一式"HIR"‘楼侵火华’"NOR"，直接踏着$N的攻击飞空而过\n",
 "$n不急不徐地转身踮步，使出一式"HIB"‘楼转天涡’"NOR"，以极快的速度踏天奔走，$N根本无法追击\n",
 "$n使出一式"HIW"‘楼珀双彗’"NOR"，躲跃如流风，任$N的攻势再激烈也伤不到$n一根汗毛\n",
 "$n跃如莺燕使出了一式"HIG"‘楼尾追鸠’"NOR"，身形矫若禽鸟乱飞乱舞，不费吹灰之力的闪过了$N的攻击\n",
});

int valid_enable(string usage)
{
	return (usage=="dodge")||(usage=="move");
}


string query_dodge_msg(string limb)
{
	return dodge_msg[random(sizeof(dodge_msg))];
}


