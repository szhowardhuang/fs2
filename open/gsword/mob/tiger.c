inherit NPC;

void create()
{
        set_name("老虎", ({"tiger"}));
	set("race", "野兽");
        set("age",20);
set("long", "一头凶猛的老虎,不过它似乎惧怕什么似的,对于你的出现完全不理会\n");
        set("str",30);
	set("limbs", ({ "头部", "身体", "前脚", "后脚", "尾巴" }) );
	set("verbs", ({ "bite", "claw" }) );
		
        set("attitude","friendly");
        set("kee",400);
	set("combat_exp",220);
        set("max_kee",400);
	setup();
}

