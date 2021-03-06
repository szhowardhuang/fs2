#include <ansi.h>
#include "/open/open.h"

inherit NPC;

string do_ask ();

void create()
{
	seteuid(getuid());
set_name("燕南天",({"day-sky"}));
	set("nickname","天下第一神剑");
	set("gender", "男性" );
	set("age", 32);
	set_weight (500);
	set("long", @LONG
LONG);

	set("chat_chance", 3);
	set("chat_msg", ({
	}) );
	set("inquiry", ([
	    "哭枫坡":	"我来这儿是为了跟我义弟江枫碰头的。",
	    "水仙姑娘":	(: do_ask :),
	    "江枫":	(: do_ask :),
	]) );
	set("combat_exp",339);
	setup();
	carry_object(MAIN_OBJ"sword")->wield();
}

string do_ask ()
{
  object	me=this_player();
  int		query;

  query = me->query_temp("quests/help_water_god");
  if (query && query == 3) {
    me->set_temp("quests/help_water_god",4);
    call_out("gone", 1, me);
    return "啊，明明约好在这儿见面，难道出事了? " +
	"或者是...\n燕南天想了想, 说道: 我再去找他的书僮江琴问问看。";
  }
  else return "您有看到他们俩吗? 如果有的话麻烦您通知我一声。";
}

void gone(object me)
{
  tell_object(me, "燕南天告诉你: 我去找江琴的下落啰, bye bye.\n");
  destruct(this_object());
}

int accept_fight(object me)
{
  return notify_fail("燕南天说道: "+me->name()+
	"，我正在想办法解救我那义弟江枫，没空跟你啰唆。\n");
}

int accept_kill(object me)
{
  message_vision(HIR""+me->query("name")+"，这是你自找死路，可别怪我。\n"+
	"突然，燕南天拔出手中的长剑一挥，就在那一瞬间.....\n"+
	"$N感觉自己飞了起来，满天星空一片血红....\n"+
	"......那......不正是$N的身体吗?....\n"NOR, me);
  me->die();
  return notify_fail("");
}
