// exercise.c
// spi < skill数量时加的熟练值只有1
// 圣火的弟子superforce lv在100之前都没有熟练值
//
// refix by chan

#include <skill.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
        int kee_cost, force_gain,spi,sk_mount,con;
        string ena_force;
        seteuid(getuid());
        if(me->query_condition("ff_poison"))
          return notify_fail("你气血失调，无法运气。\n");
        if(me->query_temp("saving_die"))
          return notify_fail("你正在救人, 没有办法运气!!!\n");
        if( me->is_fighting() )
                return notify_fail("战斗中不能练内功，会走火入魔。\n");
        ena_force = me->query_skill_mapped("force");
        if( !stringp(ena_force) )
                return notify_fail("你必须先用 enable 选择你要用的内功心法。\n");

        if( !arg ) kee_cost = 30;
        else if (!sscanf(arg, "%d", kee_cost))
                return notify_fail("你要花多少气练功？\n");

        if( kee_cost < 10 ) return notify_fail("你最少要花 10 点「气”才能练功。\n");

        if( (int)me->query("kee") < kee_cost )
                return notify_fail("你现在的气太少了，无法产生内息运行全身经脉。\n");

        if( (int)me->query("sen") * 100 / (int)me->query("max_sen") < 70 )
                return notify_fail("你现在精神状况太差了，无法凝神专一！\n");

        if( (int)me->query("gin") * 100 / (int)me->query("max_gin") < 70 )
                return notify_fail("你现在精力不够，无法控制内息的流动！\n");

        write("你坐下来运气用功，一股内息开始在体内流动。\n");

        me->add("kee", -kee_cost);

        // This function ranged from 1 to 15 when kee_cost = 30
        // 运功跟根骨(con)有关
force_gain=kee_cost*(me->query("max_force")+me->query("con")*2)/2000;
if(me->query("class")=="fighter") force_gain=force_gain*1.2;
//原来的if(me->query("class")=="fighter") force_gain=force_gain*1.5;

// 98/6/4 ppl 反应以这种方法无法增加max_force
//经检查结果 swordsman force lv 50 ,max_force ==250, kee 166
//如果一次exercise kee 160 ,force_gain~=160(250+40)/2000=23 难怪有人叫swordsman 去死
//这种情况想不出怎么解决....其它force低的class大概也一样
//不过我和chan认为不要让ppl知道有改exercise...不然系统大乱,tintin开始出现
//so 我先加上这行,然后再进行讨论解决的方法....:) ...Roger
/*取消......
if(me->query("class")=="swordsman" || me->query("class")=="poisoner"
|| me->query("class")=="taoist" || me->query("class")=="dancer")
force_gain=force_gain*1.2; //这是因为 lv 50 下 max_force only 250
                          //这样一来若一次运完所有kee,force_gain~=46
                            //奇怪又被改了...太扯了....我修正回来:by chan
        // 请问这可能吗?  ask by wade..

*/
        if( force_gain < 1 ) {
                write("但是当你行功完毕，只觉得全身痠麻。\n");
                return 1;
        }

        // me->add("force", force_gain );
        // 增加乱数
        me->add("force",force_gain);

        if( (int)me->query("force") > (int)me->query("max_force") * 2) {
                if( (int)me->query("max_force") >= 
                ((int)me->query_skill("force",1)/5 +
         me->query_skill("force") ) *10
                  )
                {
                        write("当你的内息遍布全身经脉时却没有功力提升的迹象，似乎内力修为已经遇到了瓶颈。\n");
                } else {
                        write("你的内力增强了！\n");
                        me->add("max_force", 1);
                }
                me->set("force", me->query("max_force"));
        }        
        if((random(me->query_skill("force",1))*4+me->query_skill("force",1))<
            random(me->query_skill(me->query_skill_mapped("force"),1))
           )
        {
          tell_object(me,
            "你的内力的功力跟练功根基不够，强练内力，导致气血失调。\n");
          me->apply_condition("ff_poison",(30-random(me->query("con")))/2);
        }
if(me->query("class")=="prayer"&&(ena_force=="superforce"))
if(me->query_skill("superforce",1) < 100) //浑天心法在lv 100之前没有熟练值
     return 1;
con=me->query("con"); //加入体质的限制
con=con*6+20;
if(con < 100) //保证至少有一百
   con = 100;
if(me->query("class")=="fighter") //武者放宽一点二倍
  con=con*1.2;
if(me->query_skill(ena_force,1) > con)  
     return 1;
spi=me->query("spi");
sk_mount=me->query_skills();
sk_mount=sizeof(sk_mount);
if(spi > sk_mount)
me->improve_skill(ena_force,5);
else
me->improve_skill(ena_force,1);
        return 1;
}

int help(object me)
{
        write(@HELP
指令格式 : exercise [<耗费「气”的量，预设值 30>]
指令说明 :
           运气练功，控制体内的气在各经脉间流动，藉以
         训练人体肌肉骨骼的耐力、爆发力，并且用内力的
         形式将能量储备下来。
其他参考 :
           help stats
HELP
        );
        return 1;
}
