//背水之计 by sueplan 辅助型
#include <ansi.h>
object me=this_player();
int perform(object me, object target)
{
        int sk;
        sk=me->query_skill("plan",1);
        if( target != me)   
        return notify_fail("此计只能对自己用。\n");
        if(me->query("family/family_name")!="儒门")
        return notify_fail("你不是儒门的不能用。\n");
        if( me->query("force") < 1000 )
        return notify_fail("你的内力不够。\n");
        if( me->is_fighting() )
        return notify_fail("战斗中不能使用。\n");
        if(me->query_temp("no-fear")== 1 )
        return notify_fail("你背水一战已提高士气了。\n");
message_vision(HIG"$N高声大喊，看破生死尽力一战。\n"NOR,me);
        me->set_temp("oldenforce",me->query("force_factor"));
        me->set("force_factor",10+5);
        me->add("force",-500);
        me->add_temp("apply/dodge",-20);
        me->add_temp("apply/move",-20);
        me->add_temp("apply/attack",sk);
        me->set_temp("no-fear",1);
        me->add("force",-500);
        me->add("bellicosity",-5);

        return 1;
}
