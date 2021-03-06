// crazy_dog.c

inherit NPC;

void create()
{
	set_name("王安", ({ "wang ani", "wang" }) );
	set("title","仙剑派厨子");
	set("race", "人类");
	set("age", 53);
	set("long", "瞧他手执菜刀的姿势,便知道他是个一等一个大厨。\n");
	set("attitude", "peaceful");
	set("str", 17);
	set("cor", 15);
	set("force",200);
	set("max_force",200);
	set("force_factor",2);
	set_skill("blade",20);
	set("combat_exp",3000);
	set_skill("blade",20);
	set_skill("her-blade",20);
	set_skill("force",20);
	set_skill("oneforce",20);
	set_skill("dodge",20);
	set_skill("parry",20);
	map_skill("blade","her-blade");
	map_skill("force","oneforce");
	setup();
       add_money("coin",50);
	carry_object("/open/gsword/obj/knife")->wield();
	carry_object("/open/gsword/obj/dirty_cloth")->wear();
}
