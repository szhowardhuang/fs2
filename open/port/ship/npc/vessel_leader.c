inherit NPC;

void create()
{
	set_name("幽冥船长",({"vessel leader","leader"}));
	set("long","你只能从这儿看到他的背部 , 你的直觉告诉你 , 他并不是人 !\n");
	set("gender","男性");
	set("combat_exp",3000);
        set("attitude","heroism");
	set("age",130);
	set("str",30);
        set("cor", 30);
	set("per", 25);
	set("int", 30);
	set("cps",20);
	set("con", 30);
	set("spi", 15);
	set("kar", 30);
	set_skill("unarmed",40);
	set_skill("dodge",30);
	set_skill("parry",30);
	set("chat_chance",20);
	set("chat_msg",({
	"一路上阴风惨惨 , 你的冷汗直冒 ! \n",
	"你觉得大地突然陷入一片死寂 , 你感到无比的恐惧 !\n",
	}));
	setup();
	add_money("silver",10);
}
 int accept_kill(object me)
 {
	return notify_fail("看到他你手都软了 , 更别说杀他了 !\n");
  }
 int accept_fight(object me)
 {
	return notify_fail("很奇怪 , 你就是没那个胆量向他挑战 !\n");
 }
