// fast-blade.c by konn
#include <ansi.h>
#include <combat.h>
inherit SKILL;

mapping *action = ({
([ "action" : HIG"$N身形灵动, 矮身低头, "+HIM+"幔罗千叶刀法第一式「旋风式”"+HIG+"使了出来, 手中的"+HIY+"$w"+HIG+"飞快的向$n直砍而下, 腿也朝$n下盘踢去, 快刀神腿, 逼的$n手忙脚乱。"NOR,
        "dodge":   -10,
        "parry":   -20,
        "damage":   20,
        "force":    60,
        "damage_type" : "砍伤",
]),

([ "action" : HIG"$N身子向后一倾, 顺势一招"+HIM+"幔罗千叶刀法第二式「龙翔凤舞”"+HIG+"向$n袭击而到, $N身形忽然飘荡, 忽东忽西, 手中"+HIY+"$w"+HIG+"飞快的舞着, 刀光残影, 只看的$n眼花了乱。"NOR,
        "dodge":   -20,
        "parry":   -10,
        "damage":   20,
        "force":    20,
        "damage_type" : "砍伤",
]),

([ "action" : HIG"$N忽然身形一变, 向后退了半步, 使出一招"+HIM+"幔罗千叶刀法第三式「退步斩马刀”"+HIG+", 手中"+HIY+"$w"+HIG+"横劈$n的大腿, 接着刀背一翻, 顺势向$n的腰际滑了过来, 狠斩$n的腰眼。"NOR,
        "dodge":   -30,
        "parry":    20,
        "damage":   20,
        "force":    40,
        "damage_type" : "砍伤",
]),

([ "action" : HIG"$N左手虚托, 身子略向左斜, 一刀飞出, 正是一式"+HIM+"幔罗千叶刀法第四式「抽梁换柱”"+HIG+"直向$n臂膀砍到, 刀锋飞快的从$n右臂扫过直飞向面门, 又往左臂砍到, $n惊慌的想要逃开。"NOR,
        "dodge":    20,
        "parry":    10,
        "damage":   30,
        "force":    30,
        "damage_type" : "砍伤",
]),

([ "action" : HIG"$N手中刀柄向上, 刀背向外, 身子向前微躬, 一式"+HIM+"幔罗千叶刀法第五式「参拜北斗”"+HIG+"向$n的胸前招呼了过来, 瞬间$N刀背一翻, 直砍$n的左臂, 逼的$n向后连退了三步。"NOR,
        "dodge":   -20,
        "parry":   -10,
        "damage":   30,
        "force":    40,
        "damage_type" : "砍伤",
]),

([ "action" : HIG"$N刀舞身转, 脚下不停的移动着, 绕着$n不停的寻找破绽, $N忽然使出一招"+HIM+"幔罗千叶刀法第六式「转身劈山”"+HIG+", 身子向右边一转, 斜刺刺一刀的向$n劈到, 待$n发觉时已不及反应了。"NOR,
        "dodge":   -30,
        "parry":   -10,
        "damage":   30,
        "force":    30,
        "damage_type" : "砍伤",
]),


([ "action" : HIG"$N身子向左滑了半步, 刀背略沉, 刀走中偏锋, 一招"+HIM+"幔罗千叶刀法第七式「横拦天门”"+HIG+"向$n斩了过来, $n急忙招架, $N又向左滑半步, 刀背上提, 刀锋直进, 向$n胸口砍了下来。"NOR,
        "dodge":   -35,
        "parry":   -20,
        "damage":   40,
        "force":    50,
        "damage_type" : "砍伤",
]),

([ "action" : HIG"$N手中的刀一个虚劈, 双腿蹲了个弓步, 忽然向$n飞奔而去, 手中的"+HIY+"$w"+HIG+"在身前交互着虚砍, 一招"+HIM+"幔罗千叶刀法第八式「雷电交作”"+HIG+"使了出来, 迅速的向$n的脑袋招呼了过来。"NOR,
        "dodge":   -40,
        "parry":   -20,
        "damage":   40,
        "force":    30,
        "damage_type" : "砍伤",
]),

([ "action" : HIG"$N运起全身内力, 真气从丹田中游走全身, 最后在手中食指的商阳穴会聚, 脚下使出「千斤坠”, 手中使出一招"+HIM+"幔罗千叶刀法第九式「独劈华山”"+HIG+"威猛的向$n急劈而下, 眼见$n就难已活命了。"NOR,
        "dodge":   -10,
        "parry":   -10,
        "damage":   50,
        "force":    10,
        "damage_type" : "砍伤",
]),

([ "action" : HIG"$N向后退了一步, 集精聚神的舞起千叶刀法的精要, 忽然讯捷的向$n发起"+HIM+"幔罗千叶刀法第十式「分花拂柳”"+HIG+"此招, 身形如行云流水般的飘荡, 东飘西荡, "+HIY+"$w"+HIG+"轻慢的向$n的小腹砍了下去, 柔中带钢, 钢中有柔。"NOR,
        "dodge":   -10,
        "parry":   -20,
        "damage":   50,
        "force":    30,
        "damage_type" : "砍伤",
]),

([ "action" : HIG"$N将"+HIY+"$w"+HIG+"舞得滴水不漏, 刀快如飞叶, 忽然转守为攻, 向$n施展起"+HIM+"幔罗千叶刀法第十一式「四雁南飞”"+HIG+", $N手中的"+HIY+"$w"+HIG+"快速的飞舞着, 分别以上、下、左、右四个门路向$n攻来, $n看来已无法招架了。"NOR,
        "dodge":   -20,
        "parry":   -20,
        "damage":   50,
        "force":    32,
        "damage_type" : "砍伤",
]),


([ "action" : HIG"$N蓄势待发, 忽然使出一招"+HIM+"幔罗千叶刀法第十二式「怀中抱月”"+HIG+", 身形如箭矢般飞快向前倾, 手中的"+HIY+"$w"+HIG+"则是舞动的飞快异常, 直进中宫, 忽的刀背一翻, 横劈$n的左肩, 此招变化之快, $n实是闪躲不易。"NOR, 
        "dodge":   -10,
        "parry":    20,
        "damage":   60,
        "force":    35,
        "damage_type" : "砍伤",
]),

([ "action" : HIG"$N在$n身边不停的移动, 一招"+HIM+"幔罗千业刀法第十三式「荆轲献图”"+HIG+"发将出来, 忽然将手中的"+HIY+"$w"+HIG+"腹向$n拍到, 接着又是刀柄一转, 向$n的小腹直搓而下, $N又舞着"+HIY+"$w"+HIG+"向$n的下盘斜劈了下去, $n慌忙的想避开这招。"NOR,
        "dodge":   -30,
        "parry":   -20,
        "damage":   60,
        "force":    20,
        "damage_type" : "砍伤",
]),

([ "action" : HIG"$N将手中的"+HIY+"$w"+HIG+"飞快的舞着, 一招"+HIM+"幔罗千叶刀法第十四式「流星赶月”"+HIG+", 刀锋直取$n的面门, 脚下踢着「连环十八腿”, 向$n的门户打了过来, 招式毒辣前所未见, 忽然刀背一转, 狠狠的向$n的右膀子砍了过来。"NOR,
        "dodge":   -10,
        "parry":   -20,
        "damage":   60,
        "force":    10,
        "damage_type" : "砍伤",
]),

([ "action" : HIG"$N提起真气狂舞"+HIY+"$w"+HIG+", 刀气环绕在$N的四周发出哔爆声, 一招"+HIM+"幔罗千叶刀法第十五式「谏果回甘”"+HIG+", 刀光残影, "+HIY+"$w"+HIG+"迅捷的在$N头顶上飞舞着, 忽然间猛烈的向$n迎面劈来, 只听到$n惨叫一声, 眼看$n已经不能活命了。"NOR,
        "dodge":   -10,
        "parry":   -30,
        "damage":   60,
        "force":    30,
        "damage_type" : "砍伤",
]),

([ "action" : HIG"$N把"+HIY+"$w"+HIG+"往腰际一收, 摆\了个「先礼后兵”, 随后身子旋转一圈, 手中的"+HIY+"$w"+HIG+"突然向$n急刺而出, 这正是一招"+HIM+"幔罗千叶刀法第十六式「藏刀式”"+HIG+", $N飞快的向$n砍了七七四十九刀, 刀刀致命, 招招狠毒, 
眼看$n就要不行了。"NOR,
        "dodge":    20,
        "parry":   -20,
        "damage":   70,
        "force":    30,
        "damage_type" : "砍伤",
]),


([ "action" : HIG"$N眼观六路, 耳听八方, 聚精会神的与$n缠斗着, $N将"+HIY+"$w"+HIG+"狂乱舞起, 使出"+HIM+"幔罗千叶刀法第十七式「阳关折柳”"+HIG+", 只见刀光闪闪, $N全身上下被刀气所拢罩着, 骤然将"+HIY+"$w"+HIG+"一变二, 二变四, 四变八, 分别及击向$n全身上下
八大要害。"NOR,
        "dodge":    30,
        "parry":   -20,
        "damage":   80,
        "force":    40,
        "damage_type" : "砍伤",
]),

([ "action" : HIG"$N形影飘荡, 若隐若现, 手中的"+HIY+"$w"+HIG+"诡异的飞舞着, 这正是"+HIM+"幔罗千叶刀法第十八式「恶虎拦路”"+HIG+", 待$n稍一分神, 立即一剁一砍, 向$n的周身大穴招呼而来, 刀刀命中要害, 令$n感到搏手搏脚, 毫无反击能力。"NOR,
        "dodge":   -30,
        "parry":   -10,
        "damage":   80,
        "force":    30,
        "damage_type" : "砍伤",
]),

([ "action" : HIG"$N运起六阳心法, 只见$N头顶冒出丝丝白烟, "+HIM+"幔罗千叶刀法第十九式「移转乾坤”"+HIG+"迅捷的使出, 四周突然天旋地转, 分不出东西南北, $n已感到头昏, $N瞬间欺进$n的身边, 举起"+HIY+"$w"+HIG+"便往$n脑袋砍下。"NOR,
        "dodge":    30,
        "parry":   -20,
        "damage":   90,
        "force":    15,
        "damage_type" : "砍伤",
]),

([ "action" : HIG"$N气沉丹田, 力贯刀锋, 身轻如燕, 一招"+HIM+"幔罗千叶刀法第二十式「上步劈山”"+HIG+"向$n招呼而来, $N手中的"+HIY+"$w"+HIG+"刀锋闪闪发光, 刀未至, 气先到, 一股深不可测的"+HIY+"$w"+HIG+"刀气向$n袭击而来, 逼的$n连连倒退, 接着强劲的"+HIY+"$w
"+HIG+"又跟着砍了过来, 有如猛虎下山之势。"NOR,
        "dodge":   -10,
        "parry":   -10,
        "damage":   90,
        "force":    20,
        "damage_type" : "砍伤",
]),

([ "action" : HIG"$N刀快似箭, 刀光闪闪, 片片燐光, 以一招"+HIM+"幔罗千叶刀法第二十一式「刀斩海龙王”"+HIG+"向$n袭掩而到, 急砍向$n的小腹、右臂、左肩等处, 接着臂转刀至, 刀转刀气横生, $N全身上下被笼照在刀气之下, 突然一股气又向$n击了过来,
直向$n脑门冲了过去。"NOR,
        "dodge":    30,
        "parry":   -30,
        "damage":  100,
        "force":    30,
        "damage_type" : "砍伤",
]),


([ "action" : HIG"$N左手一挥, 手中又多了一把"+HIY+"$w"+HIG+", 双刀其发, 如虎添翼, 刀气护身, 抵挡万敌, 一招"+HIM+"幔罗千叶刀法第二十二式「九龙游天”"+HIG+"使出, 有如盘古开天辟地般气象万千, 峰回路转, $N身形飘荡不定, 阴阳倒置, $n全身动弹不得, 刀气
如九龙腾出,分路向四面八方袭击而去。 "NOR,
        "dodge":    25,
        "parry":   -24,
        "damage":  110,
        "force":    43,
        "damage_type" : "砍伤",
]),
});

//can learn

int valid_learn(object me)
{
        object weapon = me->query_temp("weapon");

        if( !weapon || weapon->query("skill_type") != "blade" ) {
            tell_object(me, "手中无刀怎么个练法呀?\n");
            return 0;
        }
        if( me->query("max_force") < 1500 ) {
            tell_object(me, "你的内力修为不够, 最少要有一千五百点。\n");
            return 0;
        }
        if( me->query("force") < 1000 ) {
            tell_object(me, "你目前的内力不到一千点, 无法练此刀法。\n");
            return 0;
        }
        if( me->query_skill("gold-blade", 1) < 90 ) {
            tell_object(me, "你的紫金六阳刀法不够纯熟, 最少需要九十级。\n");
            return 0;
        }
        if( (me->query("potential") - me->query("learned_points")) < 3 ) {
            tell_object(me, "你的潜能不到三点, 无法练此刀法。\n");
            return 0;
        }
	if( me->query_skill("fast-blade", 1)*20 > me->query("bellicosity") ) {
            tell_object(me, "你杀气太低, 以致无法领会幔罗千叶刀法的精要。\n");
            return 0;
        }

        tell_object(me, "学此刀法需扣潜能、精、气、神各三点。\n");
        me->add("gin", -3);
        me->add("kee", -3);
        me->add("sen", -3);
        me->add("potential", -3);
        return 1;
}

// perform blade.fast-dest && perform blade.fast-die

string perform_action_file(string action)
{
        return CLASS_D("blademan")+"/fast-blade/"+action;
}

// can enable

int valid_enable(string usage)
{
        return ( usage == "blade" );
}

// action message

mapping query_action(object me, object weapon)
{
        mapping do_action;
        object *enemy, weaponn;
        string actionn;
        int i, j, k, level, kee;

	level = me->query_skill("fast-blade", 1);
        level = (int) level / 10;
        if( level*10 > me->query_skill("fast-blade", 1) )
        level --;
    if(me->query("family/family_name")=="金刀门")
{
        if( random(5) == 0 && me->query("sen") > 15 ) {
            enemy = me->query_enemy();
            for(i=0; i<sizeof(enemy); i++) {
                for(j=0; j<level+4; j++) {
                    k = level;
                    if( level > 10 ) k = 10;
                    k = (k+1) * 2;
                    do_action = action[random(k)];
                    actionn = "\n";
                    actionn += do_action["action"];
		    if( weaponn=me->query_temp("weapon") )
                        actionn = replace_string(actionn, "$w", weaponn->name());
                    message_vision(actionn, me, enemy[i]);
                    if( random(me->query("combat_exp")) >
                        random(enemy[i]->query("combat_exp"))/5 ) {
                        kee = enemy[i]->query("eff_kee");
                        enemy[i]->add("eff_kee", (int) -kee/20);
                        kee = enemy[i]->query("kee");
                        enemy[i]->add("kee", (int) -kee/20);
                        message_vision(HIC "\n$N闪躲不及, 被这一刀砍中了要害。\n" NOR, enemy[i]);
                        COMBAT_D->report_status(enemy[i]);
                    }

                    else message_vision(HIC "\n$N人比刀快, 惊险地闪过了这一刀。\n" NOR, enemy[i]);
                }
            }
}
            if( random(me->query("cps")) < 10 ) {
                me->add("sen", -10);
                me->add("kee", -30);
                tell_object(me,
                     "\n你使了快刀斩后, 由于定力不够, 以致于精神无法集中。\n\n");
            }
        }
        if( level > 10 ) level = 10;
        i = (level+1) * 2;
        if( i == 21 ) {
            enemy = me->query_enemy();
            for(j=0; j<sizeof(enemy); j++)
                enemy[j]->start_busy(3);
        }
        return action[random(i)];
}

