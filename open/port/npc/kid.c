inherit NPC;

void create()
{
	set_name("小男孩",({"boy"}));
	set("long","一个活泼可爱的小男孩 , 白白胖胖的 .\n");
	set("gender","男性");
	set("combat_exp",500);
	set("attitude","peaceful");
	set("age",12);
	set_skill("unarmed",5);
	set_skill("parry",5);
	set_skill("dodge",5);
	set("chat_chance",10);
	set("chat_msg",({
	}));
	setup();
	add_money("coin",10);
}
