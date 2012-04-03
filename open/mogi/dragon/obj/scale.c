//by Casey

inherit ITEM;
#include <ansi.h>
inherit F_AUTOLOAD;
void create()
{
                set_name(HIY"魔龙鳞"NOR, ({ "dragon scale","scale",}) ); 
                set_weight(50);
                set("long",
 "黄金甲龙身上的鳞片 ,具有特殊的魔力
拿来使用可以将人瞬间传送到魔界(use scale),查看剩下次数(show scale).\n "

);
                if( clonep() )
                        set_default_object(__FILE__);
                else {
                        set("unit", "片");
                        set("value", 5000);
                        set("no_insert",1);
                        set("no_auc", 1);
                        set("no_sell",1);
                        set("no_out",1);


                }
}

void init()
{
      add_action("do_magic", "use");
      add_action("do_show", "show");
}
int do_magic(string str)
{
         object me,ob;
        me = this_player();

        if(!str || str != "scale")
            return notify_fail("你在作什么啊 ?\n");
      if( !objectp(ob = present(str,me)) )
    return notify_fail("你身上没有这样东西。\n");
	if( me->is_fighting() )
                return notify_fail("战斗中不能使用喔。\n");
if( environment(me)->query("no_scale") )
return notify_fail("在这不能用。\n");
if(me->query("ghost")==1)
return notify_fail("鬼魂没资格使用魔龙鳞。\n");
          message_vision( 
sprintf("一片"HIY"光幕"NOR"慢慢将$N笼罩住 ,传送回魔界的村庄。\n"), this_player() );

        me->move("/open/mogi/village/room/room-05.c");
        message_vision( 
sprintf("天边出现一道"HIY"闪光"NOR",只见$N飞来了这里。\n"),this_player());
   if(me->query_temp("use_scale_number") > 1)
     me->add_temp("use_scale_number",-1);
   else {
     write("\n"HIY"魔龙鳞"NOR"因法力耗尽而崩散成粉末。\n");
     destruct(ob);
     return 1;
   }
        return 1;
}
int do_show(string str)
{
        object me,ob;
        int number;
        me = this_player();

        if(!str || str != "scale")
            return notify_fail("你在做什么啊 ?\n");
      if( !objectp(ob = present(str,me)) )
    return notify_fail("你身上没有这样东西。\n");
   number = me->query_temp("use_scale_number");
   printf("\n魔龙鳞还能再使用 %d 次\n",number);
   return 1;
}

