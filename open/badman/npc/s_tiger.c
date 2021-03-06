// s_tiger.c

#include </open/open.h>
#include <ansi.h>

inherit NPC;

void create()
{
	set_name("小老虎", ({ "small tiger", "tiger" }) );
        set("race", "野兽");
	set("age", 1);
	set("long", "一只可爱的小的老虎，看来好像还没有觅食的能力。\n");
	set("str", 30);
	set("cor", 30);
	set("max_kee", 100);
 	set("limbs", ({ "头部", "身体", "前脚" , "后脚" , "尾巴" }) );
	set("verbs", ({ "bite"}));
	set("combat_exp",620);
	set_temp("apply/armor", 20);
	set_temp("apply/attack", 20);
	setup();
}

void init()
{
	add_action("do_fight", "fight");
}

int do_fight(string arg)
{
	object who;
	who = this_player();

	if( !arg || (arg!="tiger" && arg!="small tiger") )
		return notify_fail("你想攻击谁？\n");
	else {
		kill_ob(who);
		accept_kill(who);
	}

        return 1;
}

int accept_kill(object who)
{
	object ob, tiger;
	ob = this_object();
   if(!ob->query_temp("my_mother")) {

	if( !present("big tiger", environment(ob)) ) {
	tell_room(environment(ob),HIW"\n突然，一只巨大的母老虎向你冲了过来！\n\n"NOR);
	tiger = new(BAD_NPC"tiger");
	tiger->move(environment(ob));
	tiger->kill_ob(who);
	}
    ob->set_temp("my_mother",1);
  } else
  {
   tell_room(environment(ob),HIR"\n只见小老虎全身发抖,爬在地下!!!!\n\n"NOR);
  }
	return 1;
}
