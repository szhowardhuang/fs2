inherit NPC;

void create()
{
	set_name("白虎", ({"white tiger","tiger"})) ;
	set("race", "野兽");
	set("age",20);
set("long","白年难得一见的白虎,有着白雪一般的毛色,它正安祥的躺在地上,对于你
的出现,并不住太注意,也许,甚少有人敢向它挑战吧!\n");
	set("str",60);
	set("con",50);
	set("limbs", ({ "头部", "身体", "前脚", "后脚", "尾巴" }) );
	set("verbs", ({ "bite", "claw" }) );
		
        set("attitude","friendly");
	set("kee",600);
	set("combat_exp",41280);
	set("max_kee",600);
	set_temp("apply/armor",40);
	set_temp("apply/dodge",40);
	set_temp("apply/attack",40);
	setup();
}

