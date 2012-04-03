// henma-steps.c
#include <ansi.h>
inherit SKILL;

string *dodge_msg = 
({
      

"$n使出"HIW"‘草上飞’"NOR",身形像蜻蜓般的轻巧，避开$N的攻击。\n",

"$n踩出"HIW"‘飞鹤冲天’"NOR",身体化成一只火鹤直奔天空而去，消失在$N之前。\n",

"$n斜踩"HIW"‘气定形转’"NOR",不慌不忙的气息一定，$n身上发出一阵烟雾将自己遮蔽住了，在$N面前消失。\n",

"$n使用"HIW"‘迷波幻影’"NOR",形体万千、充斥天地，将$N逼到角落去!\n",

"$n踏出"HIW"‘天地无极’"NOR",身形一转，便无声无息的出现在$N的身后，准备使出致命一击。\n",

});

int valid_enable(string usage) 
{
        return (usage=="dodge")||(usage=="move");
}

string query_dodge_msg(string limb)
{
  int dodge_pow;
  object me=this_player();

    if(!me) return "";
        dodge_pow = (int)(me->query_skill("rain-steps", 1)/10);
        if ( dodge_pow <= 6)
              return dodge_msg[random(4)];
        else
              return dodge_msg[random(sizeof(dodge_msg))];
}

int valid_learn(object me)
{
if(me->query("combat_exp")<(me->query_skill("rain-steps",1)*5))
      
   return notify_fail("你的战斗经验不足，无法体会雾雨迷踪其中的精义。\n");
        return 1;
}


int practice_skill(object me)
{
        if((int)me->query("kee")<5)
                return notify_fail("你的气不够，不能练雾雨迷踪。\n");
        me->receive_wound("kee",5);
        return 1;
}

