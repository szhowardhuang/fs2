// ÂäÈÕ±Ş·¨ ------by rence
// by hana 1997/3/2
 
#include <combat.h>
#include <ansi.h>
inherit SKILL;
inherit SSERVER;
void hurt(object me, object victim, object weapon, int damage);
void bleed(object me, object victim, object weapon, int damage);
void conti(object me, object victim, object weapon, int damage);
int age = this_player()->query("age",1);
int lv  = this_player()->query_skill("sunwhip",1);

mapping *action = ({
        ([      "action":"\n$NÊ¹³öÂäÈÕ±Ş·¨µÚÒ»Ê½[33m¡¸ÈÕÂäÎ÷É½¡±[0m£¬ÊÖÖĞ$wºáÉ¨$nµÄ$l\n",
                "dodge":                -20,
                "damage":              30,
                "damage_type": "±ŞÉË",
        ]),

        ([      "action":"\n$NÊ¹³öÂäÈÕ±Ş·¨µÄµÚ¶şÊ½[33m¡¸ÈÕÏÂÎŞË«¡±[0m£¬ÊÖÖĞ$wÔÚ¿ÕÖĞÁ¬»®¼¸¸öÈ¦Ö®ºóÏò$n$lÅüÏÂ\n",
                "dodge":                -20,
                "damage":                   40,
                "damage_type":  "¸îÉË",
                "post_action": (: conti :),
        ]),

        ([      "action":"\n$NÒ»¸ö·ÉÉí, Èç´óÓ¥ÃÙÊ³, ÂäÈÕ±Ş·¨µÚÈıÊ½[33m¡¸¿ä¸¸×·ÈÕ¡±[0m£¬ÊÖÖĞ$w·÷Ïò$n$l\n",
                "dodge":                -30,
                "damage":              50,
                "damage_type":  "¸îÉË",
                "post_action": (: bleed :),
        ]),

        ([      "action":"\n$NÊÖÖĞ$wÅÌĞıÊıÈ¦£¬ÂäÈÕ±Ş·¨µÚËÄÊ½[33m¡¸ÈçÈÕÖĞÌì¡±[0m¶Ô×¼$n$lÓÉÏÂÍùÉÏÖ±ŞèÁË¹ıÈ¥\n",
                "dodge":                -40,
                "damage":              60,
                "damage_type":  "´ÌÉË",
                "post_action": (: hurt :),
        ]),

        ([      "action":"\n$N×İÉíÒ»Ô¾£¬ÊÖÖĞ$wÊ¹³öµÚÎåÊ½[33m¡¸ÈÕÉıÔÂºã¡±[0mÍù$n$lÖ±Ö±ÂäÏÂ\n",
                "dodge":                -40,
                "damage":              70,
                "damage_type":  "ÓÙÉË",
                "post_action": (: bleed :),
        ]),

        ([      "action":"\n$NµÄ$wÈç³¤ÉßÓÎÏ·Ò»°ã£¬»îÁé»îÏÖ, µÚÁùÊ½[33m¡¸·öÒ¡Ö±ÉÏ¡±[0m¹îÚÜµØÏò$nµÄ$l¾íÈ¥\n",
                "dodge":                -20,
                "damage":              80,
                "damage_type":  "´ÌÉË",
                "post_action": (: conti :),
        ]),

        ([      "action":"\n$NË«ÊÖÎÕ×¡$w£¬¾¢¹áÓÚÉÏ, Ê¹³öÂäÈÕ±Ş·¨µÚÆßÊ½[33m¡¸ÈÕÔÂÈçËó¡±[0m, ±ŞÎ²»¯³ÉÀû½£Ïò$n$l´ÌÈ¥\n",
                "dodge":                -20,
                "damage":              90,
                "damage_type":  "´ÌÉË",
                "post_action": (: hurt :),
        ]),

        ([      "action":"\n$N´óºğÒ»Éù£¬ÂäÈÕ±Ş·¨µÚ°ËÊ½[33m¡¸ÈÕÔÂÖØ¹â¡±[0mÔÚ°ë¿Õ»Ó³öÒ»µÀÔ²»¡ºó, Ğ±Ğ±É¨Ïò$n$l\n",
                "dodge":                -30,
                "damage":               100,
                "damage_type":  "¿³ÉË",
                "post_action": (: bleed :),
        ]),

        ([      "action":"\n$NÊ¹³öÂäÈÕ±Ş·¨µÚ¾ÅÊ½[33m¡¸ÈÕÂä¹éÑã¡±[0m£¬¾¢Í¸³¤±Ş, ÊÖÖĞ$wÈç½£Ò»°ã¼²µã$nµÄ$l\n",
                "dodge":                -30,
                "damage":              110,
                "damage_type":  "´ÌÉË",
                "post_action": (: hurt :),
        ]),

        ([      "action":"\n$NÉíĞÎÁ¬Ğø´ò×ª£¬Ê¹³ö±Ş·¨µÚÊ®Ê½[33m¡¸ÈÕÄºÍ¾Çî¡±[0m£¬$w»¯³É»¡¹â³åÏò$nµÄÍËÂ·\n",
                "dodge":                -30,
                "damage":              120,
                "damage_type":  "ğöÉË",
                "post_action": (: conti :),
        ]),

        ([      "action":"\n\t\t[36mÍ»È»¼ä·çÉù´ó×÷£¬ÈÕÔÂÎŞ¹â£¡$ÁìÎòÁËÂäÈÕ±Ş·¨Ö®×î¸ß¾³½ç£¡\n\n\t\t\t\t[35m¡¾ ºó ôà Éä ÈÕ ¡¿[0m\n\nÖ»¼ûÂúÌì±ŞÓ°ÃÜ²»Í¸·çµØÁıÕÖ×Å$n[0m\n",
                "dodge":                -30,
                "damage":              150,
                "damage_type":  "´ÌÉË",
                "post_action": (: hurt :),
        ]),
});

void hurt(object me, object victim, object weapon, int damage)
{
        if( me->query("force_factor") > 5 )
        if( random(150) < random(lv))
        {
          victim->receive_damage("kee",lv*age/30);
          message_vision(HIM"$N½«ÕæÆø¹àÈë±ŞÖĞÉäÏò$n£¬$nÒ»Õó°§º¿£¬ÏÔÈ»ÊÜÁË²»Ğ¡µÄÄÚÉË¡£\n"NOR,me,victim);
          COMBAT_D->report_status(victim);
        }
}
void bleed(object me, object victim, object weapon, int damage)
{
        if(damage > 40)
        {
          victim->apply_condition("bleeding", random(lv*age)/100);
          message_vision("[1;36m$NÂäÈÕ±Ş·¨µÄÆø¾¢¹á´©$n£¬ÆÆÌå¶ø³ö£¡[0m\n",me,victim);
        }
}

void conti(object me, object victim, object weapon, int damage)
{
        int i;
        int lv1 = victim->query_skill("dodge",1);
        if( me->query("force_factor") >= 10 )
        {
          if( random(lv) > random(lv1) && me->query_temp("conti") == 0 )
            {
            me->set_temp("conti",1);
            message_vision("\n[1;33m$NºöÈ»¶ÙÎòÂäÈÕ±Ş·¨[1;33mµÄÒª¾÷£¬ÊÖÖĞ$wÃÍÍù$nÉíÉÏÕĞºô!![0m\n" ,me);
            for(i=0;  i <=   age/5  ;  i++)
            COMBAT_D->do_attack(me, victim, me->query_temp("weapon"), TYPE_QUICK);
            me->delete_temp("conti");
            }
        }
}
int valid_learn(object me)
{
        object ob;
        //±Ş·¨ÊÇµÚ¶ş×¨³¤, ½«ÄÚÁ¦ÏŞÖÆÔÚ50ÒÔÉÏ²ÅÄÜÑ§  by hana
        if( (int)me->query("max_force") < 50 )
                return notify_fail("ÄãµÄÄÚÁ¦²»¹»£¬Ã»ÓĞ°ì·¨Á·\n");

        if( !(ob = me->query_temp("weapon"))
        ||      (string)ob->query("skill_type") != "whip" )
                return notify_fail("Äã±ØĞëÏÈ×°±¸±ŞÀàÎäÆ÷²ÅĞĞ¡£\n");
        return 1;
}

int valid_enable(string usage)
{
        return usage=="whip" || usage=="parry";
}

mapping query_action(object me, object weapon)
{
int skill_level, limit;
        skill_level=(int)me->query_skill("sunwhip", 1);
        limit= (int)(skill_level/9);
        if (limit < 1 )
                return action[random(1)];
        if (limit < 2 )
                return action[random(2)];
        if (limit < 3 )
                return action[random(3)];
        if (limit < 4 )
                return action[random(4)];
        if (limit < 5 )
                return action[random(4)+1];
        if (limit < 6 )
                return action[random(4)+2];
        if (limit < 8 )
                return action[random(4)+3];
        else if (limit < 10)
                return action[random(4)+4];
        else
                return action[random(sizeof(action))];
}

int practice_skill(object me)
{
        //±Ş·¨²»ÊÇÊ¥»ğµÚÒ»×¨³¤, ¹ÊÆøÓëÄÚÁ¦ÏŞÖÆ²»±ØÌ«ÑÏ  by hana
        if ((int)me->query("kee") < 10)
        {
            return notify_fail("ÄãµÄÆø²»×ã£¬ÎŞ·¨Á·Ï°ÂäÈÕ±Ş·¨¡£\n");
        } else if ((int)me->query("force") < 10)
        {
            return notify_fail("ÄãµÄÄÚÁ¦²»¹»£¬ÎŞ·¨Á·Ï°ÂäÈÕ±Ş·¨¡£\n");
        }
        me->receive_damage("kee", 10);
        me->add("force", -10);
        write("Äã°´×ÅËùÑ§Á·ÁËÒ»±éÂäÈÕ±Ş·¨¡£\n");
        return 1;
}

