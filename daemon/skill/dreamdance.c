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
                 "action"     :               ""HIR"¡î¡î¡î¡î¡î"HIC"ÅäºÏ×ÅÒ¹ÃÎÌìÎè Îè×ÅÆæÃîµÄ²½·¥, Îè×ËÖ®ÂüÃî·ÂÈçõõ²õÔÙÊÀ"HIR"¡î¡î¡î¡î¡î
¡¡¡¡¡¡¡¡"HIC"Áî$n¿´µÃÈëÉñ ºöµØ$N»Ã»¯³É³ãÈÈµÄ"HIR"ÖìÈ¸"HIC" ÎÞÇéµÄ×ÆÉË$n"NOR"",
                "dodge"      :                45,
                "parry"      :                25,
                "damage"     :                200,
                "force"      :                200,
                "damage_type":               "ðöÉË"
        ]),
        ([
                "action"     :               ""HIW"¡ò¡ò¡ò¡ò¡ò"HIG"$N¸ÐÊÜµ½ÍõÕÑ¾ýÏÂ¼ÞÐÙÅ«µÄÎÞÄÎ ÒýÆð$NµÄÉ±Òâ"HIW"¡ò¡ò¡ò¡ò¡ò
¡¡¡¡¡¡¡¡¡¡"HIG" ¼±ËÙÐý×ª×ÔÉíÐÎ³ÉÒ»¹ÉÔ¹·ßÖ®·ç ÆËÉ±Ò»ÇÐ.."NOR"",
                "dodge"      :                45,
                "parry"      :                25,
                "damage"     :                220,
                "force"      :                230,
                "damage_type":               "ðöÉË"
        ]),
        ([
               "action"     :               ""HIM"¡ù¡ù¡ù¡ù¡ù"HIY"ñ¼¶ðµÄÔ©ÇüÍ»ÈçÆäÀ´Ó¿Èë$NµÄÐÄÍ· Ò»Õó¿àÍ´¼¤Æð$N"HIM"¡ù¡ù¡ù¡ù¡ù
¡¡¡¡¡¡¡¡¡¡   "HIY"µÄÇ±ÄÜ·¢»ÓÒ¹ÃÎ·¨¼øµÄ¼«ÖÂ"HIC" ÂúÌì·ÉÑ©"HIY"ÇÖÏ®$n...."NOR"",
                "dodge"      :                50,
                "parry"      :               35,
                "damage"     :                240,
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
        int skill_level, limit,k,i,kee;
                object victim,*enemy;
        victim = offensive_target(me);
        if(!victim) return action[random(10)];
        skill_level = (int)(me->query_skill("dreamdance", 1));
        limit= skill_level;
                k = random(100);
if(me->query_temp("weapon"))
{
 weapon=me->query_temp("weapon");  //¿Û×Ô¼ºforce 200
if((me->query("class")=="dancer")&&(weapon->query("id")=="maple ribbon"))
  {
if(me->query("id")==("cgy"))
{
message_vision(HIY"\n  $NÊÖÉÏµÄ"HIW "·ã"HIG"Ö®"HIM"Îè"HIY"ºÍ$N²úÉú¸ÐÓ¦,É²ÄÇ¼ä$NÁìÎòÁËÒ¹ÃÎÌìÎèµÄ°ÂÃØ!!\n"NOR,me,victim);
message_vision(HIY"Ê¹³öÁË¾¿¼«°ÂÒå"HIR" Çï "HIW" ·ç "HIG" É¨ "HIC" Âä "HIM" Ò¶ "HIY"$NÊÖÉÏµÄ"HIW "·ã"HIG"Ö®"HIM"Îè"HIY"Ïò×Å$n¼±ËÙÏ¯¾í²øÈÆ¶øÈ¥!!\n\n"NOR,me,victim);
message_vision(HIR"        £ª         "HIY"        £ª         "HIC"        £ª         "HIG"        £ª        \n"NOR,me,victim);
message_vision(HIR"      £ª£ª£ª       "HIY"      £ª£ª£ª       "HIC"      £ª£ª£ª       "HIG"      £ª£ª£ª      \n"NOR,me,victim);
message_vision(HIR"  £ª  £ª£ª£ª  £ª   "HIY"  £ª  £ª£ª£ª  £ª   "HIC"  £ª  £ª£ª£ª  £ª   "HIG"  £ª  £ª£ª£ª  £ª  \n"NOR,me,victim);
message_vision(HIR"£ª£ª£ª £ª£ª £ª£ª£ª "HIY"£ª£ª£ª £ª£ª £ª£ª£ª "HIC"£ª£ª£ª £ª£ª £ª£ª£ª "HIG"£ª£ª£ª £ª£ª £ª£ª£ª\n"NOR,me,victim);
message_vision(HIR" £ª£ª£ª£ª£ª£ª£ª£ª  "HIY" £ª£ª£ª£ª£ª£ª£ª£ª  "HIC" £ª£ª£ª£ª£ª£ª£ª£ª  "HIG" £ª£ª£ª£ª£ª£ª£ª£ª \n"NOR,me,victim);
message_vision(HIR"   £ª£ª£ª£ª£ª£ª    "HIY"   £ª£ª£ª£ª£ª£ª    "HIC"   £ª£ª£ª£ª£ª£ª    "HIG"   £ª£ª£ª£ª£ª£ª   \n"NOR,me,victim);
message_vision(HIR"      £ª£ª£ª       "HIY"      £ª£ª£ª       "HIC"      £ª£ª£ª       "HIG"      £ª£ª£ª      \n\n"NOR,me,victim);
 for(i=0;i<10;i++)
 {
message_vision(HIR"$nµ«¾õÑÛÇ°Ëù¼û¾¡ÊÇÎÞÇîÎÞ¾¡µÄ·ãÒ¶·ÉÎè,Ë²Ê±$n±»»ðºìµÄ·ãÒ¶ËùÏ¯¾í,È«ÉíÍ´¿à²»¼º¡£\n"NOR,me,victim);
victim->receive_damage("kee",10000,me);
victim->apply_condition("burn",random(10));
COMBAT_D->report_status(victim);
  }
message_vision(HIY"$NÊÖÉÏµÄ"HIW "·ã"HIG"Ö®"HIM"Îè"HIY"»Ø¸´ÁËÔ­×´²øÈÆÓÚ$NÊÖÉÏ¡£\n"NOR,me);
me->add("force",-200);
}
else if((k>80)&&(skill_level>80))
{
message_vision(HIY"\n  $NÊÖÉÏµÄ"HIW "·ã"HIG"Ö®"HIM"Îè"HIY"ºÍ$N²úÉú¸ÐÓ¦,É²ÄÇ¼ä$NÁìÎòÁËÒ¹ÃÎÌìÎèµÄ°ÂÃØ!!\n"NOR,me,victim);
message_vision(HIY"Ê¹³öÁË¾¿¼«°ÂÒå"HIR" Çï "HIW" ·ç "HIG" É¨ "HIC" Âä "HIM" Ò¶ "HIY"$NÊÖÉÏµÄ"HIW "·ã"HIG"Ö®"HIM"Îè"HIY"Ïò×Å$n¼±ËÙÏ¯¾í²øÈÆ¶øÈ¥!!\n\n"NOR,me,victim);
message_vision(RED"        £ª         "YEL"        £ª         "RED"        £ª         "YEL"        £ª        \n"NOR,me,victim);
message_vision(RED"      £ª£ª£ª       "YEL"      £ª£ª£ª       "RED"      £ª£ª£ª       "YEL"      £ª£ª£ª      \n"NOR,me,victim);
message_vision(RED"  £ª  £ª£ª£ª  £ª   "YEL"  £ª  £ª£ª£ª  £ª   "RED"  £ª  £ª£ª£ª  £ª   "YEL"  £ª  £ª£ª£ª  £ª  \n"NOR,me,victim);
message_vision(RED"£ª£ª£ª £ª£ª £ª£ª£ª "YEL"£ª£ª£ª £ª£ª £ª£ª£ª "RED"£ª£ª£ª £ª£ª £ª£ª£ª "YEL"£ª£ª£ª £ª£ª £ª£ª£ª\n"NOR,me,victim);
message_vision(RED" £ª£ª£ª£ª£ª£ª£ª£ª  "YEL" £ª£ª£ª£ª£ª£ª£ª£ª  "RED" £ª£ª£ª£ª£ª£ª£ª£ª  "YEL" £ª£ª£ª£ª£ª£ª£ª£ª \n"NOR,me,victim);
message_vision(RED"   £ª£ª£ª£ª£ª£ª    "YEL"   £ª£ª£ª£ª£ª£ª    "RED"   £ª£ª£ª£ª£ª£ª    "YEL"   £ª£ª£ª£ª£ª£ª   \n"NOR,me,victim);
message_vision(RED"      £ª£ª£ª       "YEL"      £ª£ª£ª       "RED"      £ª£ª£ª       "YEL"      £ª£ª£ª      \n\n"NOR,me,victim);

 for(i=0;i<5;i++)
 {
message_vision(HIR"$nµ«¾õÑÛÇ°Ëù¼û¾¡ÊÇÎÞÇîÎÞ¾¡µÄ·ãÒ¶·ÉÎè,Ë²Ê±$n±»»ðºìµÄ·ãÒ¶ËùÏ¯¾í,È«ÉíÍ´¿à²»¼º¡£\n"NOR,me,victim);
victim->receive_damage("kee", 100,me);
victim->apply_condition("burn",random(10));
COMBAT_D->report_status(victim);
  }
message_vision(HIY"$NÊÖÉÏµÄ"HIW "·ã"HIG"Ö®"HIM"Îè"HIY"»Ø¸´ÁËÔ­×´²øÈÆÓÚ$NÊÖÉÏ¡£\n"NOR,me);
me->add("force",-200);
}
}
}
 if((me->query("get_dan_sp",1))&&(me->query("family/family_name")=="Ò¹ÃÎÐ¡Öþ"))
 {      if (limit < 28 )
                return action[random(2)];
        if (limit < 56 )
                return action[random(4)];
        if (limit < 84)
                return action[random(4)+2];
         if (limit < 90)
           return action[random(7)+1];
        else if(limit<95)
           return action[random(7)+2];
        else
          return action[random(7)+3];
        }

else
 {     if (limit < 28 )
                return action[random(2)];
        if (limit < 56 )
                return action[random(4)];
        if (limit < 84)
                return action[random(4)+2];
        else
                return action[random(4)+3];
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
