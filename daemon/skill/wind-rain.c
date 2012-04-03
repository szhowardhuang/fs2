//金风细雨楼skill 之不见风雨
//这是金风细雨楼npc的标志,使用这一个parry skill
#include <combat.h>
#include <ansi.h>
inherit SKILL;

string *parry_msg = ({
 "$n使出一式"HIY"‘熡羽飘金’"NOR"，由下倾上贯足全力直往$N的来势对峙，弹开了$N的攻击\n",
 "$n一式"HIC"‘纱卷天风’"NOR"回手振袖毫不犹豫地卷向$n的来袭，只在一扶一探之间已错换了两人的位置\n",
 "$n静步止身摒息而视，$N的一举一动尽在$n眼下，瞬间，$n飞对而冲使出"HIW"‘千粉渀细’"NOR"点开了$N的攻击\n",
 "$n飞身数丈瞬又旋回而坠使出"HIG"‘泓竹棻雨’"NOR"，如落雨千万点点指向$N分化了$N的力量\n",
 "$n元转双足使出一式"HIM"‘馥倾真楼’"NOR"，疾速回转，在身周织成一片光环成网，使$N的攻击尽化成灰\n",
});

int valid_enable(string usage)
{
	return (usage=="parry");
}


string query_parry_msg(string limb)
{
	return parry_msg[random(sizeof(parry_msg))];
}


