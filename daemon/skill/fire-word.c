inherit SKILL;

#include <ansi.h>

string *dodge_msg = ({

"
        "HIW"$n口唸〔"HIR"火神防字诀"HIW"〕,以"HIG"《"HIY"柳"HIG"》"HIW"字为主
                底盘犹如柳树盘根,随风摇曳"NOR"

只见$N的攻势有如吹来的强风一般,$n仿佛柳树随风飘荡,丝毫不受影响。\n",
"
        "HIW"$n口唸〔"HIR"火神防字诀"HIW"〕,以"HIG"《"HIC"风"HIG"》"HIW"字为主
                身行如风,飘逸四处,动静自如"NOR"

$N来势汹汹的攻势,只穿过了$n的残影,并无击中$n。\n",
"
        "HIW"$n口唸〔"HIR"火神防字诀"HIW"〕,以"HIG"《"NOR+GRN"林"HIG"》"HIW"字为主
                脚踏幻影七星,幻化千身,$N犹如身处幻林之中"NOR"

$N慌张的乱了步伐,整个攻势就此瓦解。\n",
"
        "HIW"$n口唸〔"HIR"火神防字诀"HIW"〕,以"HIG"《"HIR"火"HIG"》"HIW"字为主
                突然身体冒出熊熊烈火,眼暴红光,口吐焰火"NOR"

$n将全身烈火聚集在双臂上,以本身的内力与火劲将$N的攻势给击退了。\n",
"
        "HIW"$n口唸〔"HIR"火神防字诀"HIW"〕,以"HIG"《"NOR+YEL"山"HIG"》"HIW"字为主
                聚气丹田,脚跨双星,不动如山"NOR"

$N的攻击仿佛击中一座山一般,无法动摇到$n分毫。\n",
});


int valid_enable(string usage){
        return ( usage=="dodge" || usage=="move" || usage=="parry");
}

int practice_skill(object me){
        return notify_fail(HIR"火神防字诀"NOR"无法自我练习增进。\n");
}

string query_dodge_msg(string limb){
        return dodge_msg[random(sizeof(dodge_msg))];
}
