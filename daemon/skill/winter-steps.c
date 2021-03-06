// winter-steps.c
#include <combat.h>
#include <ansi.h>
inherit SKILL;

string *dodge_msg = ({

""HIW"$n展现"HIC"‘冬霜初降’"HIW"身形忽隐忽现，令$N捉摸不定，就轻易闪开"NOR"\n",

""HIW"$n使出"HIB"‘霜雪纷纷’"HIW"身形化为千影，迅速移位，残像遍布，顷刻如霜雪般在$N四周"NOR"\n",

""HIW"$n面对$N的攻势，任何一招都会令你受伤不轻，于是$n利用"HIC"‘霜雪难辨’"HIW"闪开"NOR"\n",

""HIW"$n使出"HIB"‘凝气成霜’"HIW"，瞬间四周的温度剧降，将$N定住不动！"NOR"\n",

""HIW"$n施展"HIB"‘冬霜冰雪步’"HIW"身法式"HIC"‘霜雪纷飞’"HIW"，身随意转，游走于$N四周，避开$N攻击"NOR"\n",

""HIW"$n展现"HIB"‘冬霜冰雪步’"HIW"拆卸式"HIC"‘霜融为水’"HIW"，身形如水般的转开，静观$N的弱点"NOR"\n",

""HIW"$n使出"HIB"‘冬霜冰雪步’"HIW"攻击式"HIC"‘暴风雪’"HIW"，绵绵不断向$N展开攻击"NOR"\n",

""HIW"$n打出"HIB"‘冬霜冰雪步’"HIW"困住式"HIC"‘霜雪急冻’"HIW"，霜雪不断凝聚在$N身边，将$N冻结"NOR"\n",
});

int valid_enable(string usage)
{
	return (usage=="dodge") || (usage=="move");
}

int valid_learn(object me)
{
     if(me->query_skill("literate",1) < 10)
           return notify_fail("你的读书识字不够，没办法领悟冬雪寒霜步。\n");

	return 1;
}

string query_dodge_msg(string limb)
{
	return dodge_msg[random(sizeof(dodge_msg))];
}

int practice_skill(object me)
{
              if((int)me->query("sen")<60)
                 return notify_fail("你的神不够不能练冬雪寒霜步。\n");
           me->receive_damage("sen",60);
           me->improve_skill("winter-steps",me->query_skill("literate")/10+1);
	return 1;
}
