inherit NPC;

void create()
{
	set_name("蜜蜂", ({"bee"}));
	set("race", "野兽");
        set("age",2);
set("long","一只正在采蜜的蜜蜂\n");
        set("str",30);
      set("limbs", ({ "头部", "身体", "翅膀" }));
        set("verbs", ({ "bite"}));
		
        set("attitude","friendly");
	set("combat_exp",200);
        set_skill("dodge",5);
	setup();
}

