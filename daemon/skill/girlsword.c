// girlsword.c
#include <combat.h>
#include <ansi.h>
inherit SKILL;
inherit SSERVER;

void berserk(object me,object victim,object weapon,int damage);

mapping *action = ({
        ([      "action":               "$NÊ¹Ò»ÕÐ[32m¡¸ÌìÅ®À¹»¨Åõ¡±[0m£¬ÊÖÖÐ$wÊ¹½«³öÀ´½£¹âÓÐÈçÒ»»¨Àº°ã, Ïò$nµÄ$l¼²³Û¶øÏÂ",
                "dodge":                -20,
                "damage":               30,
                "damage_type":  "´ÌÉË"
        ]),
        ([      "action":               "$NÊ¹³öÌìÅ®É¢»¨½£·¨ÖÐµÄ[32m¡¸ÌìÅ®àÓàÓ¡±[0m£¬½£¹â»ô»ô, ºö»ººö¿ìµØ´ÌÏò$nµÄ$l",
                "dodge":                -20,
                "damage":               40,
                "damage_type":  "¸îÉË"
        ]),
        ([      "action":               "$NÒ»ÕÐ[32m¡¸ÌìÅ®Ï×»¨¡±[0m£¬ÉíÐÎ¶¸È»¹òµ¹ÔÚµØ£¬ÊÖÖÐ$wË³ÊÆÕ¶Ïò$nµÄ$l",
                "dodge":                -30,
                "damage":               20,
                "damage_type":  "¸îÉË"
        ]),
        ([      "action":               "$NÊÖÖÐ$wÖÐ¹¬Ö±½ø£¬Ò»Ê½[32m¡¸Ç§½¿°ÙÃÄ¡±[0m¶Ô×¼$nµÄ$l´Ì³öÒ»½£",
                "dodge":                -40,
                "damage":               50,
                "damage_type":  "´ÌÉË"
        ]),
        ([      "action":               "$N×ÝÉíÒ»Ô¾£¬±ãÊÇÒ»ÕÐ[32m¡¸´º¹âÎÞÏÞ¡±[0m, $w¶Ô×¼$nµÄ$lËÍ³öÒ»½£",
                "dodge":                -40,
                "damage":               45,
                "damage_type":  "´ÌÉË"
        ]),
        ([      "action":               "$N½«ÊÖÉÏµÄ$wÅ×ÏòµØÉÏ£¬Ë«±Û»·±§$n, ´ý$wÒ»ÂäµØÆð½ÅÒ»Ì¤, À´ÕÐÄËÊÇ[32m¡¸æªÒâÈçÐ«¡±[0m, $wÖ±´Ì$nµÄ$l",
                "dodge":                -20,
                "damage":               50,
                "damage_type":  "´ÌÉË"
        ]),
        ([      "action":               "$NÊÖÖÐ$wÏòÍâÒ»·Ö£¬Ê¹Ò»ÕÐ[32m¡¸·´¸²ÎÞÇé¡±[0m·´ÊÖ¶Ô×¼$n$lÒ»½£´ÌÈ¥",
                "dodge":                -20,
                "damage":               55,
                "damage_type":  "´ÌÉË"
        ]),
        ([      "action":               "$Nºá½£ÉÏÇ°£¬ÉíÐÎÒ»×ªÊÖÖÐ$wÊ¹Ò»ÕÐ[0m¡¸É¢»¨ÈçÃÎ¡±[0m»­³öÒ»µÀ¹â»¡Õ¶Ïò$nµÄ$l",
                "dodge":                -30,
                "damage":               60,
                "damage_type":  "¸îÉË"
        ]),
        ([
                "action"     : "\t½»ÊÖÊýÊ®»ØºÏºó, $N½£·¨Ê¹µÄÔ½À´Ô½»ëºñÈçÒâ£¬¶Ô½£·¨µÄÁìÎòÒ²Ô½ÉÏÒ»²ã, \n
\tÖð²½½«[36m¡²ÓñÅ®½£·¨µÄ¾«Ëè¡³[0mÈÚ»á¹áÍ¨, ËùÒÔÒ»³öÊÖ¾ÍÊÇÁùÊ½»òÆßÊ½ºÏÒ»µÄÕÐÊ½, \n
\tÒ»ÕÐÒ»Ê½µÝÏò$n$l\n",
                "dodge"      :               -35,
                "parry"      :               -45,
                "damage"     :                90,
                "force"      :                220,
                "post_action":               (: berserk :),
                "damage_type":               "´ÌÉË"
        ]),
        ([      "action": "    [1;33mÓÉÓÚµÐÈËµÄÎäÑ§Ò²²»Èõ£¬¼±ÓÚÈ¡Ê¤µÄÐÄÀí×÷ÓÃÏÂ!$NÖ»ºÃÊ¹³öÓñÅ®½£·¨µÄ¸ß¼¶½£ÕÐ!\n
\t\t\t\t¡®[1;31mÉßÐ«ÃÀÈËÐÄ[1;33m¡¯\n
\t$N»Ã»¯³öÎÞÒ»Ê±Ö®¼ä, ½£¹â»ô»ô, ÈçÍ¬ÌìÅ®ÏÂ·²Ò»°ã, Áî$nÑÛ»¨ÁÃÂÒ!!![0m\n",
                "parry":             -60,
                "dodge":             -60,
                "force":          350,
                "damage":         150,
                "damage_type":   "´ÌÉË"
         ]),
});

int valid_learn(object me)
{
        object ob;

        if( (int)me->query("max_force") < 50 )
                return notify_fail("ÄãµÄÄÚÁ¦²»¹»£¬Ã»ÓÐ°ì·¨Á·ÌìÅ®É¢»¨½£·¨¡£\n");

        if( (string)me->query_skill_mapped("force")!= "fireforce")
                return notify_fail("ÌìÅ®É¢»¨½£·¨¿ÉÒÔÅäºÏÊ¥»ðÄÚ¹¦Ò»ÆðÐÞÁ·¡£\n");

        if( !(ob = me->query_temp("weapon"))
        ||      (string)ob->query("skill_type") != "sword" )
                return notify_fail("Äã±ØÐëÏÈÕÒÒ»°Ñ½£²ÅÄÜÁ·½£·¨¡£\n");

        return 1;
}

int valid_enable(string usage)
{
        return usage=="sword" || usage=="parry";
}

mapping query_action(object me, object weapon)
{
int skill_level, limit;
        skill_level=(int)me->query_skill("girlsword", 1);
        limit= (int)(skill_level/9);
        if (limit < 4 )
                return action[random(4)];
        if (limit < 8 )
                return action[random(limit)];
        else if (limit < 10)
                      return action[random(6)+2];
        else
                return action[random(sizeof(action))];
}

int practice_skill(object me)
{
        if( (int)me->query("kee") < 30
        ||      (int)me->query("force") < 3 )
                return notify_fail("ÄãµÄÄÚÁ¦»òÆø²»¹»£¬Ã»ÓÐ°ì·¨Á·Ï°ÌìÅ®É¢»¨½£·¨¡£\n");
        me->receive_damage("kee", 30);
        me->add("force", -3);
        write("Äã°´×ÅËùÑ§Á·ÁËÒ»±éÌìÅ®É¢»¨½£·¨¡£\n");
        return 1;
}

void berserk(object me, object victim, object  weapon, int damage)
{
    int lose, i, un,un1;
        un1 = 0;
        un  = 0;
        if(!me->query_temp("berserk" ))
        {
                lose = (int)(me->query_skill("girlsword", 1)/10 + 1);
                me->set_temp("berserk", 1);
                for(i = 0;i < lose; i++)
                {
                          un = random(10)+1;
                          un1 = un1+0.5*un;
                        me->set_temp("apply/attack", un1);
                        message_vision(HIC"$NËæÒâÊ¹À´¾ÍÊÇ¡²ÓñÅ®½£·¨¡³µÄÊýÊ½ºÏÒ»£¬ÂØ¿ìµÄ½£ÕÐ×óÆ®ÓÒµ´, ÈÃ$nÕÐ¼Ü²»ÒÑ¡£\n"NOR, me, victim);
                        victim->receive_damage("kee",2*un1);
                        me->add("force",-3);
           COMBAT_D->report_status(victim);
                }
                me->delete_temp("apply/attack");
                me->delete_temp("berserk");
                message_vision(HIW"Ê¹³öÊýÊ®ÕÐºó£¬$NÄÚÏ¢Ò»Ê±µ÷²»»ØÀ´£¬èÆ×Å½£Õ¾ÔÚÔ­µØÐÝÏ¢ÐÝÏ¢¡£\n"NOR,me);
                me->start_busy(2);
        }
}
