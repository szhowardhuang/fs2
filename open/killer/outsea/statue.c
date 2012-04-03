inherit NPC;
#include <ansi.h>
string trouble();
void create()
{
set_name("海坊老",({"sea-god man","man","god"}));
set("long","管理着通往东瀛的海神，老态龙锺，一脸忧郁的样子，
看来似乎遇到了一些麻烦。");
set("age",1000);
set("inquiry",([
"麻烦":(:trouble:),
]));
setup();
}
int accept_fight(object me)
{
me=this_player();
command("pat "+me->query("id"));
command("say 孩子，不要这么冲动，你杀了我，你就出不去了。");
command("smile");
return 0;
}
int accept_kill(object me)
{
me=this_player();
command("pat "+me->query("id"));
command("say 孩子，不要这么冲动，你杀了我，你就出不去了。");
command("smile");
return 0;
}
string trouble()
{
object me;
me=this_player();
if(me->query_temp("put_water")!=1)
{
command("sigh");
call_out("help01",1,me);
return "其实是这样的....\n";
}
else
{
command("smile");
command("say 谢谢你把定水珠找回来。");
message_vision("海坊老手一挥，$N从这间房间消失了。\n",me);
me->move(__DIR__"sea01");
return HIY"呵呵...我会用定水珠的能力保护你的\n"NOR;
}
}
int help01(object me)
{
command("say 在前几天，我不小心把雕像的定水珠搞丢了...唉唉...\n");
return 1;
}
int accept_object(object me,object ob)
{
me=this_player();
if(ob->query("id")!="static_water")
command("say 我要的是定水珠....@#$%");
else
{
command("say 真是太好了！谢谢你把定水珠找回来。");
call_out("help02",1,me);
}
}
int help02(object me)
{
message_vision("海坊老缓缓的走向雕像。\n",me);
call_out("help03",3,me);
return 1;
}
int help03(object me)
{
message_vision("海坊老拿起了$N给的定水珠，把定水珠装进了雕像内。\n",me);
message_vision("紧接着一阵晃动，$N从这间房间消失了。\n",me);
me->move(__DIR__"sea01");
tell_object(me,HIY"海坊老用千里传音跟你说：呵呵...我会用定水珠的能力保护你的\n"NOR);
call_out("time",1,me);
return 1;
}
int time(object me)
{
me->set_temp("put_water",1);
message_vision(HIB"$N的体内似乎散发着蓝光。\n"NOR,me);
tell_object(me,HIW"(你有十分钟的时间受到定水珠的保护。)\n"NOR);
call_out("timeout",600,me);
return 1;
}
int timeout(object me)
{
me->delete_temp("put_water");
tell_object(me,HIW"定水珠的能力失效了。"NOR);
message_vision(HIR"$N身体上的蓝光渐渐退去。\n"NOR,me);
return 1;
}
