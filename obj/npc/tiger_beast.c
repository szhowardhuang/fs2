// garrison.c

#include <ansi.h>

inherit __DIR__"team";

string fight()
{
}
void create()
{
	set_name(HIY "天牙虎" NOR,({"tiger beast","beast"}));
	set("race","野兽");

	set("combat_exp",10000);
	set("chat_chance_combat", 15);
	set("chat_msg_combat", ({
		(: fight :),
	}) );
	set("verbs",({"bite","claw"}));
	set("limbs",({"头部","身体","脚部","尾巴"}));
	set_skill("unarmed",10);
	set_skill("parry",10);
	set_skill("dodge",10);

	setup();

}

