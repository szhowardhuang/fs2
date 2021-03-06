// by airke
#include <ansi.h>
inherit SKILL;
inherit SSERVER;

string reattack();

string *dodge_msg=({
      "$n使出追星步中的‘"HIW"乱心诀"NOR"’，幻化出数个残影。$N攻击尽数打在空气之中....\n",
      "$n步法交错，正是‘移星换位’，身形瞬时移动，避了开去。\n",
      "$n气游全身，身体飘如浮萍，‘天星换斗’斜斜地闪开攻击。\n",
"$n逆转真气，倒踩‘天罡\步法’，一瞬间已到了$N的背后。\n",
      "$n不慌不忙地使出‘"HIB"追月连星步"NOR"’一连跨出数步，早已离开$N的攻击范围。\n",
"$n使出‘"HIC"飞仙越浪"NOR"’罕世轻功，轻轻一跃闪过这记快招。\n",
// (: reattack :),
    });

string reattack()
{
	object me , target;
	int react;
	string msg;
	me=this_player();
        react = (me->query_skill("g-steps",1) / 4) +5;
	target = offensive_target(me);
	target->receive_damage("kee",react);
	msg = me->query("name") + "使出一招" + HIR "逆转乾坤" NOR + "将" +
	target->query("name") + "反击回去。\n";
	return msg;
}	

int valid_learn(object me)
{
	return 1;
}

string query_dodge_msg(string limb)
{
  return dodge_msg[random(sizeof(dodge_msg))];
}

int valid_enable(string usage) 
{
  return usage == "dodge" || usage == "move";
}


int practice_skill(object me)
{
	if( (int)me->query("gin") < 30 )
		return notify_fail("你的精不够，不能练追星步法。\n");
	me->receive_damage("gin", 30);
	return 1;
}

string perform_action_file(string action)
{
        return CLASS_D("taoist")+ "/g-steps/" +action;
}
