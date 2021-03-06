//修罗之舞(Ashura-Dance) Edit by del, ACKY
#include <ansi.h>
inherit SKILL;

mapping *action = ({
        ([      "action":
"$N随意扬起衣袖，忽快忽慢的踏着舞步，正是"HIM"修罗之舞"NOR"中的"HIC"‘魅’"NOR"，"
"正当\n$n失神之际，$N雪白的双掌已经逼近$n的$l。",
                "damage": 220,
                "force" : 220,
                "damage_type": "瘀伤"
        ]),
        ([      "action":
"$N快速挥动手中的衣袖，使出"HIM"修罗之舞"NOR"中的"HIG"‘惑’"NOR"，身形飘忽，转眼"
"间已经到了\n$n的周围，翻身一掌打向$n的$l。",
                "damage": 240,
                "force" : 240,
                "damage_type": "瘀伤"
        ]),
        ([      "action":
"$N使出"HIM"修罗之舞"NOR"中的"HIB"‘诱’"NOR"，雪白的脸颊突然泛起两道红霞，羞怯的"
"望着\n$n的双眼，正当$n心神荡漾之际，$N的双掌已经抵在$n的背后。",
                "damage": 260,
                "force" : 260,
                "damage_type": "内伤"
        ]),

        ([      "action":
"$N缓缓的踏着舞步，随着节奏踏起"HIM"修罗之舞"NOR"中的"HIW"‘柔’"NOR"，脸上纯真的"
"脸庞让\n$n戒心全失，突然间节奏一换，$N的双手如天罗地网般将$n团团包围。",
                "damage": 280,
                "force" : 280,
                "damage_type": "内伤"
        ]),

        ([      "action":
HIM"随着周围传来的声乐，$N开始跳起修罗之舞中的"HIR"‘艳’"HIM"，只见$N将身"
"上的衣衫\n渐渐褪去，露出雪白的肌肤，看得$n内息翻腾无法抑制。"NOR,
                "damage" : 300,
                "force"  : 300,
                "damage_type" : "七孔流血"
        ]),

});

int valid_enable(string usage)
{
        return (usage=="unarmed") || (usage=="parry");
}

mapping query_action(object me, object weapon)
{
        return action[random(sizeof(action))];
}

