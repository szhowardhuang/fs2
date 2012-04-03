
#include <ansi.h>
inherit F_VENDOR;
      

void create()
{
	set_name("杂货店老板",({"shop keeper","keeper"}) );
	set("long","
杂货店的老板，他正舒舒服服的躺在藤椅上悠闲地抽着手上的烟管，似乎
不因你的到来而感到惊讶。他以手势示意要你自己到处看看需要甚么再告
诉他。\n");
		set("age",33);
		set("gender","男性");
		set("str",25);
		set("no_kill",1);
 
		set("attitude","friendly");
		set("vendor_goods",({
		"/open/poison/obj/lamp.c",
		"/open/poison/obj/carver.c",
		"/open/poison/obj/broom.c",
	//	"/open/poison/obj/axe.c",
		"/open/poison/obj/rope.c",
		"/open/poison/obj/pipe.c",
		"/open/poison/obj/rain.c",
		"/open/poison/obj/hat.c",
		"/obj/example/wineskin.c",
	                           
	}) );
		set("max_kee",500);
		setup();
		carry_object("/obj/cloth.c")->wear();
		carry_object("/open/poison/obj/pipe.c")->wield();
 
}

void greeting(object me)
{
	if (!me || environment(me)!=environment()) return;
	{
	  command("yawn "+me->query("id"));
	  command("say 你好呀..要甚自己看看吧。");
	}
}
