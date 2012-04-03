
# include <ansi.h>
inherit NPC; 

void create()
{
	set_name("麻雀",({"sparrow"}) );
	set("long","
一只正在啄着地上谷\物的小麻雀，发觉你的靠近，牠惊慌的跳开，等跟你
保持一距离后，又低下头来继续啄牠的食物。\n");
	set("age",3);
	set("str",7);
	set("con",8);
	set("race","野兽");
	set("max_kee",70);
	set("max_gin",70);
	set("max_sen",70);
	set("limbs",({
	"头部","翅膀","身体","左脚","右脚","腹部"}) );
	set("verbs",({"claw","poke"}) );
	set("chat_chance", 4);
	set("chat_msg",({
	"麻雀啄了一口谷\物。\n",
}) );
	set("combat_exp",100);
	setup();
}

