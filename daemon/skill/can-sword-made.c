// can-sword-made.c
#include <ansi.h>
inherit SKILL;

mapping make = ([
	"can-sword" : ([ 
		1:"gold stone",
		2:"flower iron",
		3:"green stone",
		]),
	]);
mapping make_name = ([
	"can-sword": "干将之剑",
	]);
mapping make_need_lv = ([
	"can-sword": 100,
	]);
int valid_enable(string usage) { return usage=="make"; }

int valid_learn(object me) { return 1; }

int practice_skill(object me)
{
	return notify_fail("干将造剑术只能用学的。\n");
}

int make(object me,string name)
{
	object weapon;
	int i;
	mapping dict;
	string pstr="";
	if(!make[name])
		return notify_fail("干将造剑术没有制造这种武器的技术。\n");
	dict=make[name];
	for(i=1;i<=sizeof(dict);i++)
	{
		if(!present(dict[i],me))
			return notify_fail("你的材料不够，无法制造"+make_name[name]+"\n");
		weapon=present(dict[i],me);
		pstr+="("+weapon->name()+")";
		if(!present(dict[i],me))
			return notify_fail("你的材料不够，无法制造"+make_name[name]+"\n");
	}
	message_vision(
	"$N用"+pstr+"打造"+make_name[name]+"。\n",me);
	for(i=1;i<=sizeof(dict);i++)
		destruct(present(dict[i],me));
	if(random(me->query_skill("make"))<make_need_lv[name])
	{
		message_vision(
			"$N制造失败了。\n",me);
		return 1;
	}
		weapon = new("/obj/weapon/"+name);
		weapon->move(me);
	message("system",
	HIC "\n\n一代工匠"+me->name()+"打造出一把绝世兵器"+HIY+"「"+make_name[name]+"”\n\n" NOR,users());
	return 1;
}
