// ironhand.c
#include <combat.h>
#include <ansi.h>
inherit SKILL;
inherit SSERVER;

mapping *action = ({
	([	"action":"    $N使出铁沙掌的第一式[33m「开门迎宾”[0m，通红的右掌向$n的$l直直而去\n",
		"dodge":    -20,
		"force":    20,
		"damage":   30,
		"damage_type":	"瘀伤"
	]),
	([	"action":"    $N使出铁沙掌第二式[33m「动如脱兔”[0m，左掌虚晃, 右掌趁势忽缓忽快地击向$n的
$l\n",
		"dodge":	-20,
                "force":        50,
		"damage":	40,
		"damage_type":	"瘀伤"
	]),
	([	"action":"    $N招式一变, 铁沙掌第三式[33m「左右不分”[0m，左掌与右掌化拳向$n攻去, 待接触
到敌人之前双拳陡地化为双掌, 顺势拍向$n的$l\n",
		"dodge":	-30,
                "force":        80,
		"damage":	55,
		"damage_type":	"瘀伤"
	]),
	([	"action":"    $N使出第四式--[33m「如影随行”[0m, 刹时掌影翻动, 一路对准$n的$l, 时机成熟后,
重击而下\n",
		"dodge":	-40,
                "force":        100,
		"damage":	75,
		"damage_type":	"瘀伤"
	]),
	([	"action":"    $N双掌使将开来, 掌气凌人，第五式[33m「千军万马”[0m一经施展, 掌风呼呼朝向$n的
$l不断地送出\n",
		"dodge":	-40,
                "force":        120,
		"damage":	90,
		"damage_type":	"瘀伤"
	]),
	([	"action":"    $N向前一扑，双臂平伸, 双掌向外, 待$n起掌来迎时, 猛然翻掌上下合击, 
来招乃是铁沙掌之第六式[33m「上下齐手”[0m, 掌劲直透$n的$l\n",
		"dodge":	-20,
                "force":        130,
		"damage":	105,
		"damage_type":	"瘀伤"
	]),
	([	"action":"    $N身形左右飘动，双掌蓄劲而出, 击在空中发出[轰轰]之声, 敌人之思绪受
扰, 趁此之时, 铁沙掌第七式[33m「鬼影幢幢”[0m 后发先至, 左掌从下三路朝$n$l一路直进\n",
		"dodge":	-20,
                "force":        180,
		"damage":	115,
		"damage_type":	"瘀伤"
	]),
	([	"action":"    $N马步稳扎，双腿前弓后箭, 气运双臂, 铁沙掌之第八式[33m「气势磅礴”[0m挟着
山河之势, 向$n袭卷而去, $n的$l登时被掌劲所笼罩\n",
		"dodge":	-30,
                "force":        250,
		"damage":	130,
		"damage_type":	"瘀伤"
	]),
        ([      "action": "    [1;33m由于敌人顽强抵抗，$N灵机一动, 将内力鼓催起来, 掌风呼啸, 气流飞涌, 铁沙掌之\n
\t\t\t\t‘[1;31m八式合一[1;33m’\n
\t$N化成一团红色光圈, 如同一头巨熊, 拔山倒树而来!!![0m\n",
                "parry":          -60,
                "dodge":          -60,
                "force":          350,
                "damage":         150,
                "damage_type":   "瘀伤"
         ]),
});

int valid_learn(object me)
{
	object ob;

	if( (int)me->query("max_force") < 50 )
		return notify_fail("你的内力不够，没有办法练铁沙掌法。\n");

	if( (string)me->query_skill_mapped("force")!= "fireforce")
		return notify_fail("铁沙掌法可以配合圣火内功一起修练。\n");

        if( me->query_temp("weapon") || me->query_temp("secondary_weapon") )
        return notify_fail("这是一套掌法又不是剑法或是刀法!!\n");

        if( me->query("family/master_name") != "司徒荣" && !me->query("study/ironhand",1)  )
        return notify_fail("没有司徒荣本人的教导要怎么练??\n");

	return 1;
}

int valid_enable(string usage)
{
	return usage=="unarmed" || usage=="parry";
}

mapping query_action(object me, object weapon)
{
int skill_level, limit;
        skill_level=(int)me->query_skill("ironhand", 1);
        limit= (int)(skill_level/9);
        if (limit < 1 )
                return action[random(1)];
        if (limit < 2 )
                return action[random(2)];
        if (limit < 3 )
                return action[random(3)];
        if (limit < 4 )
                return action[random(4)];
        if (limit < 5 )
                return action[random(4)+1];
        if (limit < 6 )
                return action[random(4)+2];
        if (limit < 8 )
                return action[random(4)+3];
        else if (limit < 10)
                return action[random(4)+4];
        else
                return action[random(sizeof(action))];
}

int practice_skill(object me)
{
	if( (int)me->query("kee") < 30
	||	(int)me->query("force") < 3 )
		return notify_fail("你的内力或气不够，没有办法练习铁沙掌法。\n");
	me->receive_damage("kee", 30);
	me->add("force", -3);
	write("你按着师父所授, 练了一遍铁沙掌法。\n");
	return 1;
}


