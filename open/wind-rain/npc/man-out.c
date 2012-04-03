inherit NPC;
#include <ansi.h>
#include "wind-rain.h"
void create()
{
        object ob;
	set_name("庭园侍从",({"man"}));
	set("long","
负责整理庭园中大小粗重工
作的长工, 他正在巡视庭园
是否有需要整修的地方.
");
	set("gender","男性");
	set("combat_exp",20000);
	set("attitude","peaceful");
	set("age",25);
	set("class","soldier");
	set("str",30);
        set("cor", 30);
	set("int", 30);
	set("con", 30);
	set("kar", 30);
        set("max_kee",1000);
	set_skill("unarmed",5);
	set_skill("dodge",5);
        set_skill("move",5);
/*
        set("chat_chance", 5);
	set("chat_msg", ({
	"\n庭园侍从说 : 齁齁。。。。。昨天晚上和一个小浪货。。。:D~~\n",
        "\n庭园侍从说 : 小兄弟，知道我为什么这么「勇”吗？因为我都喝「蛮牛”\n",
	}));
*/
	setup();
	add_money("silver",10);
}

