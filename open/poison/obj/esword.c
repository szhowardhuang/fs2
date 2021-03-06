#include <weapon.h>
#include <ansi.h>
inherit BLADE;

void bleed(object me, object victim, object weapon, int damage);
void block(object me, object victim, object  weapon, int damage);
mapping *action = ({
([ "action":"$N使出‘雨流狂落斩’握着手中的$w全力冲去.随即身形一变,向前方斩了
数十刀",
	"dodge": 40,
	"parry": -50,
	"damage":210,
	"damage_type":"刀伤",
	"post_action" : (: call_other, __FILE__, "block" :),
]),
(["action":"$N使出‘五月花斩’,整个身子急速的旋转,手中的$w顺势化为一刀芒向前斩
去",
	"dodge": 50,

	"parry":-40,
	"damage":180,
	"damage_type":"刀伤",
	"post_action" : (: call_other, __FILE__, "bleed" :),
]),
});
void create()
{
	set_name(HIW"□NOR+WHT"W"NOR+HIW"□NOR+WHT"M"NOR+HIW"□NOR+WHT "□NOR+HIW"□NOR+WHT"B"NOR,({"blade"}) );

        set_weight(10000);
        if( clonep() )
		set_default_object(__FILE__);
	else{
		set("unit", "柄");
		set("long","
村雨是从源氏时代即流传下来的名刀，是称霸关东者的证明。相传其‘刀一
出鞘，连露珠都会滴下。’\n");

		set("value", 2000);
		set("material", "blacksteel");
		set("wield_msg","
$N缓缓地将$n从鞘中拔出，感到四周围的空气似乎因此而凝结了。\n");

		set("unwield_msg", "
$N将$n归还刀鞘。\n");

		init_blade(80, SECONDARY);
		set("actions", (: __FILE__, "query_action" :) );
 
		setup();
}
}
mapping query_action()
{
	return action[random(sizeof(action))];
}
void block(object me,object victim,object weapon,int damage)
{
	if(damage > 180)
{
	victim->start_busy( random((int)me->query_skill("blade", 1)/100 + 1 ));
	message_vision(HIW "名刀  村雨的刀身上泛来阵阵刀芒，光芒刺得$n的眼睛睁不开来，使得$n呆立原地，动弹不得!\n" NOR,me,victim);
}
}

void bleed(object me,object victim,object weapon,int damage)
{
	int cond;
	if(damage> 200)
{
	cond = victim->query_condition("bleeding");
	cond += random(me->query_skill("sword", 1)/100 );
	victim->apply_condition("bleeding", cond);
	message_vision(HIW "名刀  村雨的刀锋划破了$n的皮肤，使得$n大量失血，无法止住!\n" NOR,me,victim);
}
}
