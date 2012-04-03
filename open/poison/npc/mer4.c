
#include  <ansi.h>
inherit F_VENDOR;

void create()
{
	set_name("药铺老板",({"shop keeper","keeper"}) );
	set("long","
药铺的老板，他正微笑的对你颔首示意。\n");
	set("age",43);
	set("gender","男性");
	set("vendor_goods",({
	"/open/poison/obj/plaster.c",
	//"/open/poison/obj/ginseng.c",
	//"/open/poison/obj/mushroom.c",
	//"/open/poison/obj/tginseng.c",
	//"/open/poison/obj/tmushroom.c",
}) );
	set("no_kill", 1);
	setup();
	carry_object("/obj/cloth.c")->wear();
}

void greeting(object me)
{
	if (!me || environment(me) != environment()) return;
	{
	  command("pat "+me->query("id"));
	  command("say 你看起来很健康嘛。");
	} 
}
