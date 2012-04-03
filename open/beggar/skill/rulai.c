// ÈçÀ´ÉñÕÆ  by weiwei and smooth
#include <combat.h>
inherit SKILL;

void ru10(object me, object victim, object weapon, int damage);
void conti(object me, object victim, object weapon, int damage);

mapping *action = ({
([ "action" : "$NÍÂÆøÑïÃ¼,ÉíĞÎÒ»¶Ù,Ò»µÀ[1;33m½ğ¹â[0m×ÔÓÒÕÆÖĞ¸¡³ö,ÕıÊÇÒ»ÕĞ[5;1;33m ¡®·ğ¹â³õÏÖ¡¯[0m¡£",
                "dodge"      :   -30,
                "parry"      :   -20,
                "damage"     :    50,
                "force"      :    50,
                "damage_type":   "ğöÉË",
           ]),
([ "action" : "$N±ÕÄ¿[1mºÏÃ¼[0m,Ë«ÕÆºÏÊ²,Ù¿È»ÆÛÉí¶øÉÏ,Ò»ÕĞ [5;1;33m ¡®½ğ¶¥·ğµÆ¡¯[0m,$nÒÑÁıÕÖ$nÖÜÉíÆßÊ®¶ş´óÑ¨¡£",
                "dodge"      :    -30,
                "parry"      :    -20,
                "damage"     :     60,
                "force"      :     60,
                "damage_type":   "ğöÉË",
           ]),
([ "action" : "$N´óºÈÒ»Éù,Æø³åµ¤Ìï,Ò»ÕĞ[5;1;33m ¡®·ğ¶¯É½ºÓ¡¯[0mË³ÊÆ¶ø³ö,Ö»¼ûÕÆÓ°Æ®Æ®,µ±ÕæÓĞ¿ªÉ½ÅüÊ¯Ö®ÊÆ¡£",
                "dodge"      :   -30,
                "parry"      :   -20,
                "damage"     :    70,
                "force"      :    70,
                "damage_type":   "ğöÉË",
             ]),
([ "action" : "$NÆøÄıµ¤Ìï,ÄÉÆø»ØÉí,ÕÆÔµÎ¢Î¢ÉÏÑï,[5;1;33m ¡®·ğÎÊåÈÂŞ¡¯[0mÁèÀ÷µÄÕÆÆøÒÑÊ¹$nµ²ÎŞ¿Éµ²,±ÜÎŞ¿É±Ü¡£",
                "dodge"      :   -50,
                "parry"      :   -30,
                "damage"     :    80,
                "force"      :    80,
                "damage_type":   "ğöÉË",
           ]),
([ "action" : "$NĞÄÖĞÒ»¶¯,»ÓÕÆÅ¡Éí,Í»µØÏò$nÓÒ¼ç[1m¡®¼ç¾®¡¯[0mÑ¨ÅÄÏÂ,Ö»¼û$nÒ»¸ö[1;32mğÎ×Ó·­Éí[0m,¸ß¸ßÔ¾Æğ,$NÉíËæÒâ¶¯,ÕÆÓ°Ë³ÊÆÉÏÑï,Ò»ÕĞ[5;1;33m ¡®Ó­·ğÎ÷Ìì¡¯[0m ,±ãÏò$n³åÈ¥¡£",
                "dodge"      :   -50,
                "parry"      :   -20,
                "damage"     :    90,
                "force"      :    90,
                "damage_type":   "ğöÉË",
           ]),
([ "action" : "$NÉíĞÎËÆ¼ı,×ã²»×ÅµØ,ÕÆÔµÒşÒşÓĞ[1m·ğ¹âÎ§ÈÆ[0m,ö®Ê±Ò»ÕĞÊ§´«ÒÑ¾ÃµÄ[5;1;33m[·ğ¹âÆÕÕÕ][0m ,×ÔÕÆÖĞ·¢³ö,[1;31m¾ªÀ×[0m°ãµÄÏò$nÖ±Éä¶øÈ¥¡£",
                "dodge"      :   -60,
                "parry"      :   -20,
                "damage"     :    100,
                "force"      :    100,
                "damage_type":   "ğöÉË",
           ]),
([ "action" : "$NË«Ï¥ÅÌºÏ,Á½ÕÆ³ÁµØ,ÉíĞÎÈ½È½ÏòÉÏ¸¡Æğ¡£[5;1;33m ¡®Ìì·ğ½µÊÀ¡¯[0mĞ®×Å·ÉÉ°×ßÊ¯,À×öªÍò¾ûÖ®ÊÆÆËÃæÓ­Ïò$n¡£",
                "dodge"      :    -50,
                "parry"      :    -20,
                "damage"     :    110,
                "force"      :    110,
                "damage_type":   "ğöÉË",
           ]),
([ "action" : "$N[1m×óÊÖ[1;36mÀë»ğ[0m,[1mÓÒÊÖ[31mĞş±ù[0m,[1mÁ³É«[1;36mºöÇà[0m[1;31mºöºì[0m,ºÕÈ»±ãÊÇ[1mÈçÀ´ÃØ¼¼Ö®[5;1;33m ¡®Íò·ğ³¯×Ú¡¯[0m ,É·Ê±¼äÌìµØ±äÉ«,·ğÓ°Æ®È»,Ö»¼û$nµÍÏÂ¶·´óµÄº¹Öé,[1mÈç×¹[31mÁ¶Óü[0m,[1mÈç¶é[36m±ù¿ß[0m¡£",
                "dodge"      :    -50,
                "parry"      :    -20,
                "damage"     :    120,
                "force"      :    120,
                "damage_type":   "ğöÉË",
           ]),
([ "action" : "$N[1mĞÄÈçÖ¹Ë®,ÄéÒ¶Î¢Ğ¦[0m¡£µÍËĞÒ»Éù[5;1;33m ¡® ·ğ ·¨ ÎŞ ±ß ¡¯[0m,Ö»¼û$N[1;33m·ğ¹â¾Û¶¥,ÏéÈğÖ®Æø»·Éí[0m¡£±ã
ÔÚ´ËÊ±,$nµ¨²ü¾ª½Ğ[1m¡®ÈçÀ´..ÈçÀ´ÔÙÏÖ¡¯[0m,ö®Ê±$NË«ÑÛ¾«¹â±©Éä,ºÈµÀ:[1;32m¡®°ËÊ½Æë·¢,»ÙÌìÃğµØ¡¯[0m,»ëÉí·ğÓ°´±´±,ÕæÆø×ÔÕÆÖĞ¼¤Éä¶ø³ö¡£",
                "dodge"      :    -50,
                "parry"      :    -20,
                "damage"     :    130,
                "force"      :    130,
                "damage_type":   "ğöÉË",
                "post_action": (: conti :),
           ]),
  });

void conti(object me, object victim, object weapon, int damage)
{
        int i;
        int level=(int)(me->query_skill("rulai",1)/10);
        if (level > 6)
        {
  if( me->query_temp("rulai") == 0 && me->query("class")=="bonze" )
          {
              me->set_temp("rulai",1);
              message_vision(sprintf("\n[35;1m$NÒ»ÊÖÖ¸Ìì£¬Ò»ÊÖÖ¸µØ£¬´óºÈÒ»Éù[5;37m ¡® ÉÏÌìÏÂµØ£¬Î¨ÎÒ¶À×ğ£¡ ¡¯[0m\n"),me);
              for(i=1;i<=10;i++)
        COMBAT_D->do_attack(me, victim, me->query_temp("weapon"), TYPE_QUICK);
              me->delete_temp("rulai");
             me->start_busy(1);
          }
        } 
}
mapping query_action(object me,object weapon)
{
int skill_level, limit;
        skill_level = (int)(me->query_skill("rulai", 1));
        limit= (int)(skill_level/10);
        if (limit < 4 )
                return action[random(4)];
        if (limit < 7 )
                return action[random(limit)];
        else
                    return action[random(4)+5];
}

int valid_enable(string usage) 
{
       return (usage=="unarmed")||(usage=="parry");
}
int valid_learn(object me)
{
     return 1;
}
int practice_skill(object me)
{
        if( me->query_temp("weapon") || me->query_temp("secondary_weapon") )
          return notify_fail("Á·ÈçÀ´ÉñÕÆ»¹ÊÇÒª¿ÕÊÖ°É....\n");
        if( (int)me->query("gin") < 5 )
          return notify_fail("ÄãµÄ¾«²»¹»£¬ÎŞ·¨Á·Ï°¡£\n");
        if( (int)me->query("force") < 1 )
          return notify_fail("Ä¿Ç°ÄÚÁ¦²»×ã,ĞİÏ¢Ò»»á¶ùÔÙÁ·°É.\n");
        if( me->query("max_force") < 3000 )
          return notify_fail("ÄãµÄÄÚÁ¦²»¹»¸ß,Ç¿¼ÓÁ·Ï°½«»á×ß»ğÈëÄ§¡£\n");
         if( me->query_skill("literate",1) < me->query_skill("rulai",1) )
          return notify_fail("ÄãµÄÖªÊ¶²»×ãÒÔÌå»áÈçÀ´ÉñÕÆµÄ¸ßÉî¡£\n");
        me->receive_damage("gin", 5);
        me->add("force", -1);
        return 1;
}


