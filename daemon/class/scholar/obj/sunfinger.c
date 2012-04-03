// made by onion
#include <ansi.h>
#include <weapon.h>
inherit STABBER;
void create()
{
        set_name("一阳气指",({"sunforce finger","finger"}) );
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
        set("long","以纯正内家罡\气化成的气指, 可由颜色来辨识威力的大小
可以炼化(addin)进入段家的武器「飘阳扇”中，以在战斗中作为致胜的利器。\n");
        set("unit","束");
        set("value", 0);
        set("material","force");
        set("no_drop",1);
 //       set("wield_msg","$N将$n从手指尖端激出, 幻化成一束光芒。\n");
        set("unwield_msg","$N将$n敛入手指内, 一点光芒消逝于指尖。\n");
        }
        init_stabber(1);
        setup();
}
void init()
{
        add_action("do_wield","wield");
//指令简化的结果，害我的action要特多
        add_action("do_wield","wi");
        add_action("do_wield","wie");
        add_action("do_wield","wiel");
        add_action("do_vanish","vanish");
        add_action("do_sp","addin");    //新增功能，经解迷可以炼化入飘阳扇
}
int do_wield(string arg)
{
        object me=this_player();
        object ob=this_object();

        if(!arg) return 1;
        if(arg!="all" && arg!="finger" && arg!="sunforce finger")
                return 1;

        if(me->query("family/family_name")!="段家")
        {
        message_vision("$N缓缓以内力运功, 而$n便神奇的自$N手上消失无踪。\n",me,ob);
        destruct(ob);
        }
        else
        {
        ::wield();
        message_vision("$N将$n从手指尖端激出, 幻化成一束光芒。\n",me,ob);
        }
        return 1;
}

int do_vanish(string str)
{
        object me=this_player();
        object ob=this_object();
        message_vision("$N缓缓以内力运功, 而$n便神奇的自$N手上消失无踪。\n",me,ob);
        me->add("force",1);
        destruct(ob);
        return 1;
}
int do_sp(string str)
{
        object me=this_player();
        object ob=this_object();
        int fun;

        if(!me->query("marks/fan-finger"))
                return 0;

        if(!str || str!="fan")
                return notify_fail(HIC"你要把一阳指气炼化到那里去阿??\n"NOR);

        if(!present("finger fan",me))
                return notify_fail(HIC"你的手中没有飘阳扇，再怎么炼化下去也没用!!\n"NOR);

        if(me->is_fighting())
                return notify_fail(HIG"战斗中是无法将一阳指气进行炼化的!!\n"NOR);

        fun=me->query("functions/fan-finger/level");
        switch(fun){
          case 0..10:
            fun=10;
            break;
          case 11..20:
            fun=20;
            break;
          case 21..30:
            fun=30;
            break;
          case 31..40:
            fun=40;
            break;
          case 41..50:
            fun=50;
            break;
          case 51..60:
            fun=60;
            break;
          case 61..70:
            fun=70;
            break;
          case 71..80:
            fun=80;
            break;
          case 81..90:
            fun=90;
            break;
          case 91..100:
            fun=100;
            break;
          case 101..110:
            fun=110;
            break;
          case 111..120:
            fun=120;
            break;
        }
        if(me->query_temp("fan-finger") >= fun)
          return notify_fail(HIM"你一次只可以炼化"+CHINESE_D->chinese_number(fun)+"束一阳指气进入飘阳扇中。\n"NOR);

        if(query("equipped"))
                return notify_fail(HIY"你现在正装备着一阳指气，所以无法将其炼化。\n"NOR);

        message_vision(HIC"
$N"HIC"将真气聚于手上，脸上的颜色由红转白，又由白转红，全身汗流夹背，
$N"HIC"忽然间眼放精光，手指窜出一道指气流入了飘阳扇中!!!\n

"HIR"$N"HIR"因为用劲过度，暂时无法行动。\n"NOR,me);

        me->start_busy(2);
        me->add_temp("fan-finger",fun/10);
        me->add("force",-100);
        me->set_temp("block_msg/all",1);
        call_out("delay",3,ob,me);
        return 1;
}
int delay(object ob,object me)
{
        me->set_temp("block_msg/all",0);
        destruct(ob);
        return 1;
}
