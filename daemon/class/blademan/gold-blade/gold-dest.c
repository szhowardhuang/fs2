#include <combat.h>
#include <ansi.h>
inherit SSERVER;
inherit F_FUNCTION;
int perform(object me, object target)
{
        object *enemy,ob;          
        int damage,i,fun;
        enemy=me->query_enemy();
        i=sizeof(enemy);
        fun=me->query("functions/gold-dest/level");
        if(!(ob=me->query_temp("weapon")) ||
           (string)ob->query("skill_type") != "blade")
              return notify_fail("要有刀才能使出千人斩。\n");
        if(me->query_skill("gold-blade",1)<60)
           return notify_fail("你的紫金六阳刀法根基不够，"+
                              "没办法使出万人斩。\n");
if(me->query("family/family_name") != "金刀门")
return notify_fail("非金刀门徒不能用！！\n");
if(!me->is_fighting())
           return notify_fail("万人斩只能在战斗中使用。\n");
        if(me->query("force") < 50)
           return notify_fail("你的内力不够。\n");
if(fun==100) {
message_vision(HIC"$N大喝一声发出所有刀劲!!!\n\n"HIB"一招"HIR"万人斩"HIW"终极式"HIY"---"HIG"‘"HIR"破"HIY"邪"HIM"惊天斩"HIG"’!!!\n\n"NOR,me);
damage=me->query_skill("blade")*8;
} else if(fun<=20) {
message_vision(HIR"$N虎吼一声，使出金刀绝学「个人斩”"+
                               "，刀气分击各敌！\n"NOR,me);
damage=me->query_skill("gold-blade",1)*3;
} else if(fun<=40&&fun>=21) {
message_vision(HIG"$N虎吼一声，使出金刀绝学「十人斩”"+
                               "，刀气分击各敌！\n"NOR,me);
damage=me->query_skill("gold-blade",1)*4;
} else if(fun<=60&&fun>=41) {
message_vision(HIY"$N虎吼一声，使出金刀绝学「百人斩”"+
                               "，刀气分击各敌！\n"NOR,me);
damage=me->query_skill("gold-blade",1)*5;
} else if(fun<=80&&fun>=61) {
message_vision(HIB"$N虎吼一声，使出金刀绝学「千人斩”"+
                               "，刀气分击各敌！\n"NOR,me);
damage=me->query_skill("gold-blade",1)*7;
} else if(fun>=81&&fun<=99) {
message_vision(HIC"$N虎吼一声，使出金刀绝学「万人斩”"+
                               "，刀气分击各敌！\n"NOR,me);
damage=me->query_skill("gold-blade",1)*9;
}
        me->add("force",-50);
        me->start_busy(1);
        while(i--) {
if(!me || !enemy[i]) continue;
if(environment(me)!=environment(enemy[i])) continue;
if(random(100) > 20) {
              enemy[i]->receive_wound("kee",damage);
message_vision(HIR"$N闪躲不及，刀气从胸膛贯穿而过！\n"NOR,enemy[i]);
              COMBAT_D->report_status(enemy[i],1);
          }
          else message_vision(YEL"$N机灵的躲过了刀气！\n"NOR,enemy[i]);
        }
if(fun<100) { function_improved("gold-dest",random(300)); }
        return 1;
}       
