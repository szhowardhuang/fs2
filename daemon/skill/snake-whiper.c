inherit SSERVER;
#include <ansi.h>
#include <combat.h>
inherit SKILL;
void whip(object me, object victim, object weapon, int damage);

string *parry_msg =
    ({
      "$n回身抽鞭，使出"+YEL+"〔"+MAG+"邪灵"+WHT+"。"+CYN+"蛇鞭"+YEL+"〕"+NOR+"防御式，将$N的攻势一一化去\n",
      "只见$n身形一转，轻抖手中$l，圈出一个鞭花，往$N的$w卷去\n",
      "$n气运$l，将$l舞成一个圈圈，护住身周五尺内\n",
      "$n急忙之际，使出一招‘灵蛇出洞’，进身直攻，逼的$N收势防守\n",
      "$n改守为攻，运气于$l，$l顿时坚硬无比，$n看准了$N的攻势，手持$l硬生生接下$N的招势\n",
    });

mapping *action = ({
([ "action":"$N轻挥手中的$w，$w仿佛脱手毒蛇般，快速的打向$n",

        "dodge"	:	-20,
        "parry"	:	-25,
        "damage":	300,
        "damage_type":	    "鞭伤",

]),

([ "action":"$N挑高$w握柄处，顺势下挥，$w上下起伏，令$n无法捉摸$N的鞭路",

        "dodge"	:	-50,
        "parry"	:	-50,
        "damage":	350,
        "damage_type":	    "鞭伤",

]),

([ "action":"$N将$w脱手抛于天空，使出"+YEL+"〔"+MAG+"邪灵"+WHT+"。"+CYN+"蛇鞭"+YEL+"〕"+NOR+"-毒牙，只见$w急势挥向$n",

        "dodge"	:	-50,
        "parry"	:	-50,
        "damage":	350,
        "damage_type":	    "鞭伤",
        "post_action":	(: whip :),

]),

([ "action":"$N挥动$w，一招"+YEL+"〔"+MAG+"邪灵"+WHT+"。"+CYN+"蛇鞭"+YEL+"〕"+NOR+"-捆兽术，$w在天空画出一道圆弧，直扑$n",

        "dodge"	:	-50,
        "parry"	:	-50,
        "damage":	400,
        "damage_type":	    "鞭伤",
        "post_action":	(: whip :),

]),

([ "action":"$N快速挥动$w，$w犹如数万条毒蛇爬行于地，一招"+YEL+"〔"+MAG+"邪灵"+WHT+"。"+CYN+"蛇鞭"+YEL+"〕"+NOR+"--群蛇鞭法直击$n各路穴道",

        "dodge"	:	-50,
        "parry"	:	-50,
        "damage":	450,
        "damage_type":	    "鞭伤",
        "post_action":	(: whip :),

]),

([ "action":"$N手一抖，一招"+YEL+"〔"+MAG+"邪灵"+WHT+"。"+CYN+"蛇鞭"+YEL+"〕"+NOR+"--幽雷暴雨，已经迅然直攻$n",

        "dodge"	:	-50,
        "parry"	:	-50,
        "damage":	500,
        "damage_type":	    "鞭伤",
        "post_action":	(: whip :),

]),

([ "action":"$N挥鞭并足，以脚技抢攻$n的下半身，又以$w使出"+YEL+"〔"+MAG+"邪灵"+WHT+"。"+CYN+"蛇鞭"+YEL+"〕"+NOR+"--"+HBWHT+HIR+"邪灵幻化"+NOR+"，直逼$n",

        "dodge"	:	-50,
        "parry"	:	-50,
        "damage":	550,
        "damage_type":	    "鞭伤",
        "post_action":	(: whip :),

]),

([ "action":"$N轻挥$w，一招"+YEL+"〔"+MAG+"邪灵"+WHT+"。"+CYN+"蛇鞭"+YEL+"〕"+NOR+"--"+HBWHT+"无招无势"+NOR+"，鞭子已经扑向$n",
 
        "dodge"	:	-50,
        "parry"	:	-50,
        "damage":	600,
        "damage_type":	    "鞭伤",
        "post_action":	(: whip :),

]),

});

void whip(object me,object victim,object weapon,int damage)
{
int i,j,k;

	i = (int)me->query_skill("whip");
	j = (int)victim->query_skill("dodge");

	if( i < random(j) )
	{
		message_vision(HIR+"$N"+HIR+"鞭法突然杂乱无章...$n"+HIR+"一个躲避不及～被鞭子划过了身旁～\n"NOR,me,victim);
		victim->receive_wound("kee",100);
		COMBAT_D->report_status(victim,1);
	}
	
	if( (int)victim->query_busy() < 2 && random(100) < 20 )
	{
		message_vision(HIY+"$N"+HIY+"的鞭法捆住了$n"+HIY+"，令$n"+HIY+"顿时无法动弹～\n"NOR,me,victim);
		victim->start_busy(1);
	}
}

int valid_enable(string usage)
{
        return usage=="whip" || usage=="parry";
}

string query_parry_msg(string limb)
{
	return parry_msg[random(sizeof(parry_msg))];
}

mapping query_action(object me, object weapon)
{
	return action[random(sizeof(action))];
}
