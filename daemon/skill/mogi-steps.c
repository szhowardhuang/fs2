// mogi npc dodge 之 劫夜走天步
#include <ansi.h>
inherit SKILL;

string *dodge_msg = ({
"$n飘散如雾，走地无迹使出一式"HIM"‘幽影无踪’"NOR"在被击中的瞬间化实为虚，避开了$N的攻击\n",
"$n一式"HIM"‘劫影无魂’"NOR"，身影如幽灵化幻，$N猛烈一击却只是打中了\n",
"$n踏天而行使出一式"HIM"‘夜影无痕’"NOR"，化身为尘，如尘舞风，任$N怎么攻也迫不进$n身周\n",
"$n魔气挥散使出一式"HIM"‘魔影无灭’"NOR"，魔气在$n身周形成一膜护身气劲，滑过了$N的攻势\n",
"$n柳步轻移，身影摇曳生姿，使出了一式"HIM"‘倩影无丽’"NOR"，闪出了些微的空间恰巧躲过$N的攻击",
});

int valid_skill_usage(string usage)
{
	return (usage=="dodge") || (usage=="move");
}
 int valid_enable(string usage)
 {
        return( usage=="dodge" || usage=="move") ;
 }

string query_dodge_msg(string limb)
{
	return dodge_msg[random(sizeof(dodge_msg))];
}
