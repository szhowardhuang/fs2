// mogi npc skill 之 龙罗刀法
#include <combat.h>
#include <ansi.h>
inherit SKILL;
mapping *action = ({
	([	"action":		"$N使出一式"HIY"‘逆鳞龙胆’"NOR"，毫无掩饰的杀气如雷骤落，一列刀气朝着$n狂卷而去",
		"dodge":        -40,
		"damage":	250,
                "force":        250,
		"parry":	-30,
                "damage_type" : "砍伤"
	]),
	([	"action":		"$N一气三化使出了一式"HIY"‘龙爪崩山’"NOR"，在激出三道刀气的同时，$N踱步前跃追着刀气而去，往$n$l猛烈砍杀",
		"dodge":	-30,
		"damage":	250,
                "force":        250,
		"parry":	-20,
                "damage_type" : "砍伤"	
	]),
	([	"action":		"$N拔身高跃追向$n，一式"HIY"‘赤烈崩林’"NOR"卷起强烈的风压，直逼$n追去",
		"dodge":	-40,
		"damage":	250,
                "force":        250,
		"parry":	-30,
                "damage_type" : "砍伤"	
	]),
	([	"action":		"$N飞身数丈欲采以高压低之势使出一式"HIY"‘空天座架’"NOR"，魔之炎灼之气如横风纵雨笔直窜进$n怀里",
		"dodge":	-30,
		"damage":	250,
                "force":        250,
		"parry":	-20,
                "damage_type" : "劈伤"		
	]),
        ([      "action":              "$N放出焰焰血气，双手反握$w穷全身之力使出一式"HIY"‘霸袭龙尾’"NOR"，破天撼地的威力轰然迫近$n",
                "dodge":        -25,
                "damage":       250,
                "force":        250,
                "parry":        -10,
                "damage_type" : "劈伤"             
        ]),
});



int valid_enable(string usage)
{
        return usage=="blade" || usage=="parry";
}

mapping query_action(object me, object weapon)
{
	return action[random(sizeof(action))];
}

