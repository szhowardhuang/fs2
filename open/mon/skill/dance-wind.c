#include <ansi.h>
#include <combat.h>
inherit SKILL;
inherit SSERVER;

void dance(object me, object victim,object weapon, int damage);

mapping *action = ({
//1
	([	"action"     :    HIW"$N双手一扬"HIY"‘"HIC"天集云涌"HIY"～◎～"HIC"万风具灭"HIY"’"HIW"，刹那间天地云气狂涌，$n"HIW"已被重重的云气所包围！"NOR,
		"dodge"      :   -35,
		"parry"      :	 -35,
		"damage"     :    80,
		"force"      :    80,
		"post_action":   (: dance :),
		"damage_type":   "天伤",
	]),
//2
	([	"action"     :    HIW"$N轻声随唤"HIY"‘"HIC"妖身不灭"HIY"～◎～"HIC"凌霄虚空"HIY"’"HIW"，以无比的力量向$n"HIW"冲飞而至！"NOR,
		"dodge"      :   -35,
		"parry"      :   -35,
		"damage"     :    70,
		"force"      :    70,
		"post_action":   (: dance :),
		"damage_type":   "妖伤",
	]),
//3
	([	"action"     :    HIW"$N轻巧的使出"HIY"‘"HIC"此消彼长"HIY"～◎～"HIC"魔性横生"HIY"’"HIW"，魔性愈发之下，聚集所有的能量向$n"HIW"重重轰去！"NOR,
		"dodge"      :   -35,
		"parry"      :   -35,
		"damage"     :    120,
		"force"      :    80,
		"post_action":   (: dance :),
		"damage_type":   "魔伤",
	]),
//4
	([	"action"     :    HIW"$N叹道："HIY"‘"HIC"人心不古"HIY"～◎～"HIC"哀莫心死"HIY"’"HIW"，招式似有似无的向$n"HIW"飘忽而至吓得$n"HIW"无法招架！"NOR,
		"dodge"      :   -35,
		"parry"      :   -35,
		"damage"     :    70,
		"force"      :    90,
		"post_action":   (: dance :),
		"damage_type":   "心伤",
	]),
//5
	([	"action"     :    HIW"$N杀的性起，使出一式"HIY"‘"HIC"劫空无我"HIY"～◎～"HIC"忘情随风"HIY"’"HIW"，瞬间已经到达忘我之境，杀的$n"HIW"遍体鳞伤！"NOR,
		"dodge"      :   -35,
		"parry"      :   -35,
                "damage"     :    80,
                "force"      :    90,
		"post_action":   (: dance :),
                "damage_type":   "情伤",
	]),
//6
	([	"action"     :    HIW"$N一声招唤，"HIY"‘"HIC"千妖狂飞"HIY"～◎～"HIC"万魔舞动"HIY"’"HIW"，千妖万魔已向$n"HIW"齐攻而去！"NOR,
		"dodge"      :   -35,
		"parry"      :   -35,
		"damage"     :    130,
		"force"      :    130,
		"post_action":   (: dance :),
		"damage_type":   "压伤",
	]),
//7
	([	"action"     :    HIW"$N身形着地，脚踏两地使出"HIY"‘"HIC"地动天光"HIY"～◎～"HIC"回影残声"HIY"’"HIW"，刹时间天摇地动，$n"HIW"渐渐受不了这样的压力！"NOR,
		"dodge"      :   -35,
		"parry"      :   -35,
		"damage"     :    100,
		"force"      :    105,
		"post_action":   (: dance :),
		"damage_type":   "地伤",
	]),
//8
	([	"action"     :     HIW"$N用生命领悟了天地的奥秘，左手狂龙，右手天凤，对$n"HIW"使出了"HIY"‘"HIC"天翔凤舞"HIY"～◎～"HIC"狂龙啸天"HIY"’"NOR"！"NOR,
		"dodge"      :    40,
		"parry"      :   -50,
		"damage"     :    100,
		"force"      :    100,
		"post_action":   (: dance :),
		"damage_type":   "吼伤",
	]),
//9
	([	"action"     :   HIW"四周一股香味飘散开来，$N袭出一式"HIC"【"HIM"花香处处"HIY"～◎～"HIM"迎风飘散"HIC"】"HIW"飘向$n"HIW"之要害!!"NOR,
                "dodge"      :    35,
                "parry"      :    60,
                "damage"     :    90,
                "force"      :    70,
                "damage_type":   "花伤",
	]),
//10
	([	"action"     :   HIW"$N喃喃道：诗有可解不可解"HIC"【"HIM"镜花水月"HIY"～◎～"HIM"如梦一场"HIC"】"HIW"勿泥其迹可也!!"NOR,
                "dodge"      :    75,
                "parry"      :   -95,
                "damage"     :    40,
                "force"      :    90,
                "damage_type":   "镜伤",
	]),
//11
	([	"action"     :   HIW"$N有感而发"HIC"【"HIM"稍踪即逝"HIY"～◎～"HIM"昙花一现"HIC"】"HIW"片片的花瓣渐渐杀向$n"HIW"!!"NOR,
                "dodge"      :   -65,
                "parry"      :    95,
                "damage"     :    60,
                "force"      :    90,
                "damage_type":   "昙伤",
	]),
//12
	([	"action"     :   HIW"$N吟道："HIC"【"HIM"锦上添花"HIY"～◎～"HIM"多此一举"HIC"】"HIW"只见漫天的花叶夹着几许的杀伤力，袭向$n"HIW"!!"NOR,
                "dodge"      :    135,
                "parry"      :    65,
                "damage"     :    70,
                "force"      :    90,
                "damage_type":   "锦伤",
	]),
//13
	([	"action"     :   HIW"$N轻然飘起，"HIC"【"HIM"山洪花海"HIY"～◎～"HIM"竞走一瞬"HIC"】"HIW"，瞬间已经带着山洪般的力量击向$n"HIW"!!"NOR,
                "dodge"      :    65,
                "parry"      :    75,
                "damage"     :    110,
                "force"      :    110,
                "damage_type":   "情伤",
	]),
//14
	([	"action"     :   HIW"$N轻吟一唤，"HIC"【"HIM"凝香冰雨"HIY"～◎～"HIM"春寒一步"HIC"】"HIW"，轻盈的身形已攻至$n"HIW"的近身处!!"NOR,
                "dodge"      :    65,
                "parry"      :   -85,
                "damage"     :    100,
                "force"      :    110,
                "damage_type":   "压伤",
	]),
//15
	([	"action"     :   HIW"$N身形飘转，随着心境一转而使出"HIC"【"HIM"花雨缤纷"HIY"～◎～"HIM"封灵一动"HIC"】"HIW"，$n"HIW"渐渐迷失在花雨的幻境中!!"NOR,
                "dodge"      :   -65,
                "parry"      :    75,
                "damage"     :    110,
                "force"      :    80,
                "damage_type":   "地伤",
	]),
//16
	([	"action"     :    HIW"$N随身扬起无数花瓣，激起一式"HIC"【"HIM"天花漫舞"HIY"～◎～"HIM"飘摇之间"HIC"】"HIW"散落$n"HIW"周身!!"NOR,
                "dodge"      :    40,
                "parry"      :   -50,
                "damage"     :    90,
                "force"      :    90,
                "damage_type":   "吼伤",
	]),
});

int valid_learn(object me)
{
        return 1;
}

int valid_enable(string usage)
{
	return ( usage=="unarmed" || usage=="parry" );
}

mapping query_action(object me, object weapon)
{
	if( me->query("id")=="dance wind")
	{
	return action[random(8)];
	}
	else if( me->query("id")=="tzan yuo")
	{
	return action[random(16)-8];
	}
	else
	{
        return action[random(sizeof(action))];
	}
}

int practice_skill(object me)
{
        return 1;
}

void dance(object me, object victim,object weapon, int damage)
{
	object room;
        room = environment(me);
        message_vision("$N藉由本身的力量吸引了长白山上的一股妖力往$n攻去!!\n",me,victim);
        victim->receive_damage("kee", random(300));
        victim->receive_damage("gin", random(50));
        victim->receive_damage("sen", random(50));
        if(!room->query_temp("dance"))
        {
             room->add("long",HIC"\n\n\n..........一股妖气缓缓的濔漫在这附近..........\n"NOR);
             room->add_temp("dance",1);
        }

}
