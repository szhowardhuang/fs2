inherit NPC;

void create()
{
 	set_name("吸血蝙蝠", ({"blood bat","bat"}));
	set("race", "野兽");
        set("age",2);
set("long", "模样恐怖的吸血蝙蝠,无情的攻击任何人.\n");
        set("str",30);
      set("limbs", ({ "头部", "身体", "翅膀" }));
        set("verbs", ({ "bite"}));
		
        set("attitude","aggressive");
	set("combat_exp",220);
        set_skill("dodge",5);
	set_temp("apply/attack",10);
	setup();
}

