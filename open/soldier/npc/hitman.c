#include "/open/open.h"
inherit NPC;
void create()
{
    set_name("打饭兵", ({ "hitman" }) );
    set("title", "反乱军");
	set("gender", "男性");
    set("long", "这是反乱军中蛮重要的职位,没有他们大家都没饭吃。\n");
    set("age",21);
	set("attitude", "heroism");
	set("kee",400);
	set("max_kee",400);
    set("combat_exp",800);
	setup();
}
