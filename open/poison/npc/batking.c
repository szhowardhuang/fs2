inherit NPC;

void create()
{
	set_name("蝙蝠王",( {"king bat","bat"}));
	set("race", "野兽");
	set("age",100);
	set("str",45);
      set("limbs", ({ "头部", "身体", "翅膀" }));
        set("verbs", ({ "bite"}));
		
        set("attitude","friendly");
	set("combat_exp",689);
	set_skill("dodge",30);
	setup();
}

