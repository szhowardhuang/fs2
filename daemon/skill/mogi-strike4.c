// mogi npc skill 之 穴杀鬼蜂
#include <combat.h>
#include <ansi.h>
inherit SKILL;
void throw_weapon(object,object,object,int);
mapping *action = ({
	([	"action":		"$N绕圆快速地移动使出了一式"HIR"‘奔舞’"NOR"，手中$w以巧妙的时间差毫无空隙地飞向$n的眉心",
		"dodge":        -40,
		"damage":	250,
                "force":        250,
		"parry":	-30,
		"post_action":  (: throw_weapon :),
	]),
	([	"action":		"$N一式穴杀鬼蜂中的"HIR"‘惨影’"NOR"激起阵阵阴气，$w犹如流影飞星，虚幻若隐地疾",
		"dodge":	-30,
		"damage":	250,
                "force":        250,
		"parry":	-20,
		"post_action":	(: throw_weapon :),
	]),
	([	"action":		"$N向天飞手一掷立时飞身与$n缠斗，就在$n专心应战之际，$N瞬间向后一跃，$w如暴雨骤落直刺向$n，此式便是穴杀鬼蜂中的"HIR"‘灭绝’"NOR,
		"dodge":	-40,
		"damage":	250,
                "force":        250,
		"parry":	-30,
		"post_action":	(: throw_weapon :),
	]),
	([	"action":		"$N踏天飞纵使出了穴杀鬼蜂中的一式"HIR"‘鬼哭’"NOR"，刹那间鬼影幢幢，$w划破空气发出妖吼奔窜$n的胸腹要穴",
		"dodge":	-30,
		"damage":	250,
                "force":        250,
		"parry":	-20,
		"post_action":	(: throw_weapon :),
	]),
        ([      "action":              "$N迅雷不及掩耳地将手里的$w向$n的咽喉直掷，$n急速回手一挡，却不知影子里竟藏着另一枚$w直指$n心窝",
                "dodge":        -25,
                "damage":       250,
                "force":        250,
                "parry":        -10,
                "post_action":  (: throw_weapon :),
        ]),
});



int valid_enable(string usage)
{
        return usage=="throwing" || usage=="parry";
}

mapping query_action(object me, object weapon)
{
	return action[random(sizeof(action))];
}
void throw_weapon(object me, object victim, object weapon, int damage)
{
        if( objectp(weapon) ) {
                if( (int)weapon->query_amount()==1 ) {
                        weapon->unequip();
             tell_object(me, "\n你的" + weapon->query("name") + "用完了！\n\n");
                }
                weapon->add_amount(-1);
        }
}
