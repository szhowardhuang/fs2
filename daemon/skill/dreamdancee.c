// dreamdance.c//cgy

#include <combat.h>
#include <ansi.h>
inherit SKILL;
inherit SSERVER;

mapping *action = ({
        ([      
                "action"     :               "$NÊ¹³öÒ»ÕÐ[1;32m¡¸·ÉÑà°¿Ïè¡±[0m£¬Ë«ÍÈ³ÊÑàÎ²×´ÒÔÓÅÃÀµÄ×ËÌ¬Ïò×Å$n¼²·É¶øÖÁ",
                "dodge"      :                10,
                "parry"      :               -20,
                "damage"     :                30,
                "force"      :                20,
                "damage_type":               "ðöÉË"
        ]),
        ([     
                "action"     :               "$NÉíÐÎÙ¿È»Íò±ä£¬Ê¹³öÒ»ÕÐ[1;32m¡¸ÔÆÎíÆ®ç¿¡±[0m£¬³Ã×Å$n¾ªãµÖ®¼Ê£¬Ë«ÕÆÏò$nÅÄÈ¥",
                "dodge"      :               -5,
                "parry"      :               -30,
                "damage"     :                20,
                "force"      :                40,
                "damage_type":               "ðöÉË"
        ]),
        ([   
                "action"     :               "$NÉíÌåÏòÉÏÆ®Æð£¬Á½ÍÈÈçÂäÒ¶·É»¨°ã£¬Ïò×Å$nµ±Í·ÕÖÂä£¬ÕýÊÇÒ¹ÃÎÌìÎèÖÐµÄ[1;32m¡¸ÂäÓ¢çÍ·×¡±[0m",
                "dodge"      :                10,
                "parry"      :               -35,
                "damage"     :                60,
                "force"      :                80,
                "damage_type":               "ðöÉË"
        ]),
        ([  
                "action"     :               "$NË«ÍÈÏòÇ°µÅ³ö£¬ÉíÌå»¯ÎªÒ»µÀÃÀÀöµÄºç²Ê£¬Ê¹³öÒ»ÕÐ[1;32m¡¸·É»¨ÖðÔÂ¡±[0m»÷Ïò$n",
                "dodge"      :                15,
                "parry"      :               -25,
                "damage"     :                100,
                "force"      :                100,
                "damage_type":               "ðöÉË"
        ]),
        ([ 
                "action"     :               "$NË«ÊÖÈçÄñÒí°ãÏòÉÏÆ½¾Ù£¬Ê¹³öÒ»ÕÐ[1;32m¡¸°×º×ÂÓÒí¡±[0m£¬»÷Ïò$n",
                "dodge"      :               -15,
                "parry"      :                10,
                "damage"     :                120,
                "force"      :                150,
                "damage_type":               "ðöÉË"
        ]),
        ([
                "action"     :               "$NÈáÖ¸ÊæÕÅ£¬×ËÌ¬ÓÅÃÀ£¬ºöÈ»¶Ô×Å$nÈ«Éí´óÑ¨¼²µã£¬Áî$nÄÑÒÔÕÐ¼Ü£¬ÕýÊÇÒ¹ÃÎÌìÎèÖÐµÄ[1;32m¡¸ÌìÅ®É¢»¨¡±[0m",
                "dodge"      :               -25,
                "parry"      :               -15,
                "damage"     :                140,
                "force"      :                180,
                "damage_type":               "ðöÉË"
        ]),
        ([
                "action"     :               "$NÉíÌå¿ªÊ¼Ðý×ª£¬ÓÉ»º¶ø¼±£¬ÃÀÃîµÄÉíÐÎÈç·ï»Ë°ãÏò¿Õ·ÉÆð£¬ÉíÌåËÄÖÜÐÎ³ÉÒ»¹ÉÇ¿¾¢µÄÆøÁ÷»÷Ïò$n£¬ÕýÊÇÒ¹ÃÎÌìÎè×îÖÕ¾øÑ§[1;32m¡¸·ïÎè¾ÅÌì¡±[0m",
                "dodge"      :                40,
                "parry"      :                20,
                "damage"     :                170,
                "force"      :                250,
                "damage_type":               "ðöÉË"
        ]),
        ([
                 "action"     :               ""HIC"$NÅäºÏ×ÅÒ¹ÃÎÌìÎè Îè×ÅÆæÃîµÄ²½·¥, Îè×ËÖ®ÂüÃî ·ÂÈçõõ²õÔÙÊÀÁî$n¿´µÃÈëÉñ ºöµØ$N»Ã»¯³É³ãÈÈµÄ"HIR"ÖìÈ¸"NOR" ÎÞÇéµÄ×ÆÉË$n",
                "dodge"      :                45,
                "parry"      :                25,
                "damage"     :                140,
                "force"      :                200,
                "damage_type":               "ðöÉË"
        ]),
        ([
                "action"     :               ""HIG"$N¸ÐÊÜµ½ÍõÕÑ¾ýÏÂ¼ÞÐÙÅ«µÄÎÞÄÎ ÒýÆð$NµÄÉ±Òâ ¼±ËÙÐý×ª×ÔÉíÐÎ³ÉÒ»¹ÉÔ¹·ßÖ®·ç ÆËÉ±Ò»ÇÐ.."NOR"",
                "dodge"      :                45,
                "parry"      :                25,
                "damage"     :                160,
                "force"      :                230,
                "damage_type":               "ðöÉË"
        ]),
        ([
               "action"     :               ""HIY"ñ¼¶ðµÄÔ©ÇüÍ»ÈçÆäÀ´Ó¿Èë$NµÄÐÄÍ· Ò»Õó¿àÍ´¼¤Æð$NµÄÇ±ÄÜ ·¢»ÓÒ¹ÃÎ·¨¼øµÄ¼«ÖÂ"HIC" ÂúÌì·ÉÑ©"HIY"ÇÖÏ®$n...."NOR"",
                "dodge"      :                50,
                "parry"      :               35,
                "damage"     :                180,
                "force"      :                250,
                "damage_type":               "ðöÉË"
        ]),


});
int valid_learn(object me)
{
        if( me->query_temp("weapon") || me->query_temp("secondary_weapon") )
                           return   notify_fail("Ñ§Ò¹ÃÎÌìÎè±ØÐè¿ÕÊÖ¡£\n");
        if(me->query("max_force")<50)
                return notify_fail(" ¹ÔÍ½¶ù£¬ÄÚÁ¦ÉÏÏÞÒª 50 à¸£¬¶à¼ÓÓÍà¸!!\n");
        return 1;
}


int valid_enable(string usage)
{
        return ( usage=="unarmed" || usage=="parry" );
}


mapping query_action(object me, object weapon)
{
        int skill_level, limit;
        skill_level = (int)(me->query_skill("dreamdance", 1));
        limit= skill_level;
 if(!me->query("get_dan_sp",1))
  {     if (limit < 28 )
                return action[random(2)];
        if (limit < 56 )
                return action[random(4)];
        if (limit < 84)
                return action[random(6)];
        else    
                return action[random(7)];
   }

else
{       
         if (limit < 90)
           return action[random(1)+7];
        else if(limit<95)
           return action[random(2)+7];
        else       
          return action[random(3)+7];
        } 
}

int practice_skill(object me)
{
        if( (int)me->query("kee") < 40 )
                return notify_fail("ÄãµÄÌåÁ¦²»¹»ÁË£¬ÐÝÏ¢Ò»ÏÂÔÙÁ·°É¡£\n");
        if( (int)me->query("force") < 5 )
                return notify_fail("ÄãµÄÄÚÁ¦²»¹»ÁË£¬ÐÝÏ¢Ò»ÏÂÔÙÁ·°É¡£\n");
        me->receive_damage("kee", 40);
        me->add("force", -5);
        return 1;
}

/*
string perform_action_file(string action)
{
        return CLASS_D("dancer")+"/dreamdance/"+action;
}
*/
