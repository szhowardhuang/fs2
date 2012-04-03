inherit ITEM;
#include <ansi.h>
void create()
{
        set_name(HIY"旋音笛"NOR, ({ "whirl sound flute","flute"}) );
	if( clonep() )
        set_default_object(__FILE__);
        else {
        set("unit", "枝");
        set("long", "这是一个亮黄色的长笛，传说中在死灵幽谷中使用(g-use)，可以割破
空间。\n");
        set_weight(100);
        set("value",0);
	     }
}

void init()
{
add_action("do_use","g-use");
}

int do_use(string arg)
{
object me=this_player();
object ob=this_object();
object room=environment(me);
if(!arg||arg!="flute")
return notify_fail("你要使用什么东西？\n"); 
if(!room->query("ghost-hole/can_use_flute"))
return notify_fail(HIW"此笛子只能在死灵幽谷的白洞使用。\n"NOR);
if(!me->query_temp("ghost-hole/evil-ghost-flute"))
{
message_vision(HIR"$N吹奏出十分难听的声音，旋音笛没多久就断裂了！！\n"NOR,me);
destruct(ob);
return 1;
}
message_vision(HIY"$N突感杀戮之苦、分离之痛，笛声高底起伏不已，瞬间笛声割破了空间，一
下子$N被吸了进去！！\n"NOR,me);
me->move("/open/ghost-hole/g-r01");
message_vision(HIW"一到凄凉的笛声传至，空间突然出现了一道裂痕，$N从空间的裂缝中走了出
来！！\n"NOR,me);
message_vision(HIR"$N手上的"HIY"旋音笛"HIR"由于耗费了极大的能源，渐渐的化成了一推废灰了...\n"NOR,me);
destruct(ob);
return 1;
}
