inherit NPC;

void create()
{
	set_name("狮子", ({"lion"}));
	set("race", "野兽");
        set("age",10);
	set("long", "万兽之王,狮子,如果你想活命的话,快逃吧.\n");
        set("str",40);
	set("con",50);
	set("limbs", ({ "头部", "身体", "前脚", "后脚", "尾巴" }) );
	set("verbs", ({ "bite", "claw" }) );
		
        set("attitude","aggressive");
	set("cpmbat_exp",480);
	set("kee",400);
	set("max_kee",400);
	setup();
}

