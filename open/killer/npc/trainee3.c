#include "/open/open.h"
inherit NPC;
void create()
{
	set_name("中级生", ({ "trainee" }) );
	set("title", "黑牙联");
	set("gender", "男性");
	set("long", "这是杀手的中级生。\n");
	set("age",12);
	set("attitude", "heroism");
	set("kee",500);
	set("max_kee",500);
	set("combat_exp",7000);
	setup();
}