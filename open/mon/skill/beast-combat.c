#include <ansi.h>
#include <combat.h>
inherit SKILL;
inherit SSERVER;

void bite(object me, object victim,object weapon, int damage);
void bite2(object me, object victim,object weapon, int damage);
void claw(object me, object victim,object weapon, int damage);
void kick(object me, object victim,object weapon, int damage);

mapping *action = ({
        ([      "action":               "$N扑了上来，以极快速的动作张嘴往$n的$l狠狠地一咬!!",
                "dodge":                -200,
                "parry":                -200,
                "force":                 250,
                "damage":                250,
		"post_action":                (: bite :),
                "damage_type":  "咬伤"
        ]),
        ([      "action":               "$N扑了上来，以极其巧妙的动作张开了$N的大嘴疯狂地往$n的$l狠狠地一咬!!",
                "dodge":                -200,
                "parry":                -200,
                "force":                 350,
                "damage":                350,
		"post_action":                (: bite2 :),
                "damage_type":  "咬伤"
        ]),
        ([      "action":               "$N扑了上来，用$N的前脚往$n的$l用力地一抓!!",
                "dodge":                -200,
                "parry":                -200,
                "force":                 400,
                "damage":                400,
		"post_action":                (: claw :),
                "damage_type":  "抓伤"
        ]),
        ([      "action":               "$N扑了上来，用$N强而有力的脚往$n的$l狠狠地一踢!!",
                "dodge":                -200,
                "parry":                -200,
                "force":                 500,
                "damage":                500,
		"post_action":                (: kick :),
                "damage_type":  "踢伤"
        ]),
});

void bite(object me, object victim,object weapon, int damage)
{
        message_vision(HIG"$N"HIG"再大力一咬，在$n"HIG"身上咬出了一个很大的齿痕!!\n"NOR,me,victim);
	victim->receive_damage("kee", random(300),me);
	victim->receive_damage("gin", random(50),me);
	victim->receive_damage("sen", random(50),me);

}

void bite2(object me, object victim,object weapon, int damage)
{
        message_vision(HIR"$N"HIR"狠狠用力的一咬，在$n"HIR"身上咬出了一个奇大无比的齿痕!!\n"NOR,me,victim);
	victim->receive_damage("kee", random(500),me);
	victim->receive_damage("gin", random(100),me);
	victim->receive_damage("sen", random(100),me);

}

void claw(object me, object victim,object weapon, int damage)
{
        message_vision(HIY"$N"HIY"朝$n"HIY"身上狠狠用力一抓，抓出了数条泛红的血爪痕!!\n"NOR,me,victim);
	victim->receive_damage("kee", random(700),me);
	victim->receive_damage("gin", random(150),me);
	victim->receive_damage("sen", random(150),me);
}

void kick(object me, object victim,object weapon, int damage)
{
        message_vision(HIC"$N"HIC"大力往$n"HIC"身上一踢，将$n"HIC"踢出个老远，痛的$n"HIC"哭天抢地的!!\n"NOR,me,victim);
	victim->receive_damage("kee", random(900),me);
	victim->receive_damage("gin", random(200),me);
	victim->receive_damage("sen", random(200),me);
}

int valid_learn(object me)
{
        return 1;
}

int valid_enable(string usage)
{
        return usage=="unarmed";
}

mapping query_action(object me, object weapon)
{
        return action[random(sizeof(action))];
}

int practice_skill(object me)
{
        return 1;
}
