// lungshan.c
#include <combat.h>
inherit SKILL;
inherit SSERVER;

void berserk(object me,object victim,object weapon,int damage);


mapping *action = ({
        ([      
                "action"     :              
"$N´óº°ÂÀ¶´±ö:¡¸ÂÀ¶´±ö:×í¾ÆÌáºøÁ¦Ç§¾û¡±,$NÊÖ³ÉÌá¾Æ×´,Á½ÊÖÍù$nµÄË«¼çÒ»×½",
                "dodge"      :               -25,
                "parry"      :               -20,
                "damage"     :                30,
                "force"      :                50,
                "damage_type":               "×½ÉË"
        ]),
        ([     
                "action"     :              
"$N´óº°¡¸º«Ïæ×Ó:ÇÜÍó»÷ÐØ×í´µÏô¡±,$N×½×¡$nµÄÊÖ,ÍùËûµÄÐØ²¿ÃÍ×²",
                "dodge"      :               -50,
                "parry"      :               -10,
                "damage"     :                20,
                "force"      :                80,
                "damage_type":               "×²ÉË"
        ]),
        ([   
                "action"     :              
"$N´óº°¡¸ÕÅ¹ûÀÏ:×í¾ÆÅ×±­×íÁ¬»·¡±,$N³É×í²½×´,Ò¡Ò¡°Ú\°Ú\Íù$nÌßÈ¥",
                "dodge"      :               -10,
                "parry"      :               -25,
                "damage"     :                70,
                "force"      :                100,
                "damage_type":               "ÌßÉË"
        ]),
        ([  
                "action"     :              
"$N´óº°¡¸Àº²ÉºÍ:µ¥Ìá¾´¾ÆÀ¹ÑüÆÆ¡±,$N³É°ëÌÉ×´,ÊÖÍù$nµÄÑü²½Ò»¿Û",
                "dodge"      :               -30,
                "parry"      :               -5,
                "damage"     :                90,
                "force"      :                120,
                "damage_type":               "¿ÛÉË"
        ]),
        ([ 
                "action"     :               "$N×ÝÉíÒ»Ô¾£¬Ê¹³öãñÉ½È­°ÂÒå¡¸É½ÈªÈºÓ¿¡±£¬È­ÈçÁ¬Öé°ãÒ»Á¬ÊýÊ®È­»÷Ïò$n$l",
                "dodge"      :               -30,
                "parry"      :               -30,
                "damage"     :                170,
                "force"      :                150,
                "post_action":               (: berserk :),
                "damage_type":               "ðöÉË"
        ]),
        ([
                "action"     :              
"$N´óº°¡¸Ìú¹ÕÀî:ÐýÖâÏ¥×²×í»¹Õæ¡±,$NÊÕÆðÊÕÆðÒ»½Å,Ò¡Ò¡°Ú\°Ú\Ò»ÊÖÈ´½«$n¼Ð×¡",
                "dodge"      :               -20,
                "parry"      :               -45,
                "damage"     :                220,
                "force"      :                240,
                "damage_type":               "¼ÐÉË"
        ]),
        ([
                "action"     :              
"$N´óº°¡¸²Ü¹ú¾Ë:ÏÉÈË¾´¾ÆËøºí¿Û¡±,$NÊÖ³É³Ö±­×´,Íù$nµÄ²±×ÓÒ»×½",
                "dodge"      :               -50,
                "parry"      :               -50,
                "damage"     :                280,
                "force"      :                300,
                "damage_type":               "×½ÉË"
        ]),
        ([
                "action"     :
"$N´óº°¡¸ººïñÀë:×í²½±§Ì³ÎÑÐÄ¶¥¡±,$NÍ·Ò»Éì,Íù$nÒ»×²",
                "dodge"      :               -30,
                "parry"      :               -5,
                "damage"     :                90,
                "force"      :                120,
                "damage_type":  "×²ÉË"
       ]),
       ([
               "action"      :
"$N´óº°¡¸ºÎÏÉ¹Ã:µ¯Ñü¾´¾Æ×íµ´²½¡±,$NÑüÒ»Íä,Í»È»Ë«ÊÖÍù$nµÄÁ³²¿Ò»µ¯",
               "dodge"      :               -30,
               "parry"      :               -5,
               "damage"     :                90,
               "force"      :                120,
               "damage_type":  "µ¯ÉË"
       ]),
});

int valid_learn(object me)
{
        if( me->query_temp("weapon") || me->query_temp("secondary_weapon") )
        return   notify_fail("Ñ§×íÈ­±ØÐë¿ÕÊÖ¡£\n");
        return   1;
}

int valid_enable(string usage)
{
        return ( usage=="unarmed" );
}


mapping query_action(object me, object weapon)
{
int skill_level, limit;
        skill_level = (int)(me->query_skill("drunk", 1));
        limit= (int)(skill_level/10);
        if (limit < 4 )
                return action[random(4)];
        if (limit < 7 )
                return action[random(limit)];
        else if (limit < 9)
                return action[random(6)];
        else
                return action[random(sizeof(action))];
}

void berserk(object me, object victim, object  weapon, int damage)
{
    int lose, i, test,pow,pow1;
        pow1 = 0;
        pow  = 0;
        if(!me->query_temp("berserk" ))
        {
                lose = (int)(me->query_skill("drunk", 1)/20 + 1);
                me->set_temp("berserk", 1);
                for(i = 0;i < lose; i++)
                {
                        pow = random(6);
                        pow1 = pow1+pow;
                        me->set_temp("apply/attack", pow1);
                        message_vision(
                       
"[1;33m$NÊ¹³ö°ËÏÉÆëºØÊÙ,ÈçÉ½ÈªÓ¿³ö°ã´òÏò$n¸÷ÖÂÃüÈõµã¡£^[[0m\n" , me, victim);
                        COMBAT_D->do_attack(me, victim, me->query_temp("weapon"));
                }
                me->delete_temp("apply/attack");
                me->delete_temp("berserk");
        }
} 


int practice_skill(object me)
{
        if( (int)me->query("kee") < 40 )
                return notify_fail("ÄãµÄÌåÁ¦²»¹»ÁË£¬ÐÝÏ¢Ò»ÏÂÔÙÁ·°É¡£\n");
        if( (int)me->query("force") < 3 )
                return notify_fail("ÄãµÄÄÚÁ¦²»¹»ÁË£¬ÐÝÏ¢Ò»ÏÂÔÙÁ·°É¡£\n");
        if( (int)me->query_skill("literate") <= (
(int)(me->query_skill("drunk", 1)*0.75) ) )
                return
notify_fail("ÄãµÄÎäÑ§ÖªÊ¶²»×ã£¬ËÆºõÎÞ·¨²ÎÎò×íÈ­µÄ×î¸ß°ÂÃØ");
        me->receive_damage("kee", 40);
        me->add("force", -5);
        return 1;
}

string perform_action_file(string action)
{
        return CLASS_D("fighter")+"/drunk/"+action;
}

