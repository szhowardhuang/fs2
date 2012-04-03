// hahaer.c by oda

#include <../badman.h>

inherit NPC;

void create()
{
	set_name("哈哈儿", ({ "ha ha er", "ha", "er" }) );
	set("nickname", "笑里藏刀笑弥陀");
	set("gender", "男性");
	set("age", 44);
	set("long", "你看到一个矮矮胖胖的圆脸胖子，脸上始终维持着一样的\n笑容，好像不会累似的。\n");
	set("attitude", "friendly");

	set("str", 25);
	set("cor", 25);
	set("int", 30);
	set("spi", 23);
	set("cps", 21);
	set("con", 25);
	set("per", 22);
	set("combat_exp", 2100);

	// set("chat_chance", 5);
	set("chat_msg", ({
		"农夫抬起头来擦擦额头上的汗水，又再弯下腰去努力的耕田。\n",
	}) );
	// set("chat_chance_combat", 50);
	set("chat_msg_combat", ({
		"农夫尖叫道：救命啊！有人杀人啊！\n",
		"农夫尖叫道：你要干什么？要钱也不用杀我吧！\n",
	}) );

	setup();
	// carry_object(S_OBJ"t_shirt")->wear();
}

int accept_fight(object me)
{
	return notify_fail("农夫笑着对你说：这位"+RANK_D->query_respect(me)+"别开玩笑了好吗?\n");
}
