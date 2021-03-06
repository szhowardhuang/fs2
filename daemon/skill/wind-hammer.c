//金风细雨楼skill 之 风诀锤法
//这是金风细雨楼一般护卫的skill
#include <combat.h>
#include <ansi.h>
inherit SKILL;
mapping *action = ({
	([	"action":		"$N狂舞$w使出一式‘风迫苍岗’，迫起雷风轰隆，风压逼得$n动弹不得，$w直直往$n$l挥去"NOR,
		"damage":	90,
                "force":        90,
                "damage_type" : "锤伤"
	]),
	([	"action":		"$N浑力朝地一锤，一式‘风碎氤氲’激起碎石奔旋，风压急变蛇窜从四面八方卷向$n"NOR,
		"damage":	90,
                "force":        90,
                "damage_type" : "骨折"	
	]),
	([	"action":		"$N挥锤如双臂直捣$n怀里，使出了一式‘风煌钟烟’，似虚若幻化刚为柔地拍向$n身上各要穴"NOR,
		"damage":	90,
                "force":        90,
                "damage_type" : "内伤"	
	]),
	([	"action":		"$N飞步欠身低窜，一式‘风咬轰扬’卷舞碎砂扬尘，破风声如天崩地裂，挟万钧之势击向$n"NOR,
		"damage":	90,
                "force":        90,
                "damage_type" : "骨折"		
	]),
        ([      "action":              "$N一式‘风扫天魃’手里$w再次激起狂风呼啸，仿佛旋龙升天风虎长鸣直追$n的六大要处"NOR,
		"damage":	90,
                "force":        90,
                "damage_type" : "锤伤"             
        ]),
});



int valid_enable(string usage)
{
        return usage=="hammer" || usage=="parry";
}

mapping query_action(object me, object weapon)
{
	return action[random(sizeof(action))];
}

