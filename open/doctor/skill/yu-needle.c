// yu-needle
// ÆßÆæÕë¾÷--- ÊÖæP(unarmed), ÕëæP(stabber)
// by adam..

#include <ansi.h>
#include <combat.h>
inherit SKILL;

void bleed(object me, object victim, object weapon, int damage);

string *parry_msg=
    ({
   "$nÉíÇûÒ»Òı£¬Ö¸¼ä$wÆ½Æ½´îÔÚ$NµÄÎäÆ÷ÉÏ£¬Ò»ÕĞ¡®"HIM" À¹È¸Î²"NOR" ¡¯½«$NµÄÎäÆ÷Ò·ÁË¿ªÈ¥¡£",
   "$n½«ÉíÌå¿¿Ïò$N£¬Ò»ÕĞ¡®"HIC" Õ´ÒÂÊ®°Ëµø "NOR"¡¯£¬½«$Nğ¤ÔÚÔ­µØ£¬Ê¹²»¿ªÕĞÊ½!",
   "$nÊÖÖĞ$wÉÏÏÂÎè¶¯£¬Ò»ÕĞ¡®"HIW" ·ÉÆÙ³¤ºç"NOR" ¡¯, ±ÆµÃ$N²»µÃ²»ÊØ×¡×ÔÉí!",
   "$n°ÑÊÖÖĞµÄ$wÎè³ÉÔ²»·Ò»ÕĞ¡®"HIB" ÔÆ»ØÔ²ÔÂ "NOR" ¡¯£¬½«$NµÄ¹¥ÊÆ¾¡Êıµ²ÁËÏÂÀ´¡£",
   "$nÒÔ¾²ÖÆ¶¯£¬ÊÖÖĞ$wÆ½¾ÙĞØÇ°£¬Ò»ÕĞ¡®"CYN" Èç·âËÆ±Õ"NOR" ¡¯£¬»¯½âÁË$NµÄ¹¥ÊÆ!",
    });

//unarmed, stabber_action

mapping *action = ({
([ "action":"$NÒ»ÕĞ¡®"HIW" °×ÉßÍÂĞÅ"NOR" ¡¯£¬ÏÂÉíÉÔÇú£¬²½ÂÄÇ°¿ç£¬Ë«ÕÆÎ¢·Ö£¬ÊÖÖ¸¼âÍù$nµÄĞØÇ°¡®"BLINK+HIC" ğ¯Î²Ñ¨"NOR" ¡¯ÓÃÁ¦´ÁÁËÈ¥!",
        "dodge": -10,
        "parry": -20,
        "damage": 30,
        "force":  50,
        "damage_type":  "´ÌÉË",
]),

([ "action":"$NÊÖÕÆÒ»ÕÅ£¬Ò»Ê½¡®"HIR" ¶ñ»¢ÆËÑò"NOR" ¡¯£¬×İÉíÒ»Ìø£¬ÓÉÉÏÍùÏÂÏò$nµÄÍ·¶¥¡®"BLINK+HIY" °Ù»áÑ¨"NOR" ¡¯ÆËÁËÈ¥!",
        "dodge": -20,
        "parry": -10,
        "damage": 40,
        "force": 130,
        "damage_type": "´ÌÉË",
]),

([ "action":"$NË«ÊÖÒ»À­Ò»°´Ò»Ñ¹£¬½«$nµÄ×óÊÖ±³¡®"BLINK+MAG" ºÏ¹ÈÑ¨"NOR" ¡¯ÖÆ×¡£¬ÍùÍâ»Ø×ªÒ»È¦£¬ÓÃÁ¦µØ½«$nÅ×ÁË¿ªÈ¥!",
        "dodge": -30,
        "parry": 20,
        "damage": 50,
        "force": 180,
        "damage_type": "Ë¤ÉË",
]),
([ "action" : "$NŞÖÏ¥Î¢¶×£¬Ù¿µØÉíÇûÒ»×ª£¬ÈÆµ½ÁË$nµÄ±³ºó£¬ÖĞÖ¸Ïò$n±³ºó¡®"BLINK+HIW" ÃüÃÅÑ¨"NOR"¡¯´ÁÁËÈ¥!",
        "dodge": -30,
        "parry": -10,
        "damage": 90,
        "force": 240,
        "damage_type": "´ÌÉË",
]),
([ "action" : "$NÉíĞĞÍ»È»µØÍùºóÍËÁËÊı²½£¬$n¸ú½ø£¬ºöÈ»$NÉíĞĞÁ¢Í££¬ÊÖÖâÒ»Çú£¬×ªÍËÎª½ø£¬Öâ¼âÍù$n¸¹²¿¡®"BLINK+HIR" ÆøÑªÑ¨"NOR" ¡¯¼±¶¥¶øÈ¥!",
        "dodge": -40,
        "parry": 10,
        "damage": 110,
        "force": 300,
        "damage_type": "´ÌÉË",
]),

([ "action":"$NºôĞ¥Ò»Éù£¬Éí·¨ÇáÁéµØÍù$n±³ºó×İÁËÈ¥£¬Ë«ÊÖÒ»´òÒ»´Á£¬Ïò$nµÄ×ó±ß¡®"BLINK+HIY" Ì«ÑôÑ¨"NOR" ¡¯£¬ºóÄÔ¡®"BLINK+HIG" ·ç¸®Ñ¨"NOR" ¡¯¹¥»÷!",
        "dodge": 20,
        "parry": -10,
        "damage": 100,
        "force": 280,
        "damage_type": "´ÌÉË",
]),
([ "action" : "$NÒ»ÕĞ¡®"HIM" ×ªÉíÁùºÏ"NOR" ¡¯£¬ÉíĞÎÇáÇá×óÓÒÒ¡°Ú£¬Ë«ÊÖÉÏÏÂ·­¶¯£¬¼±ËÙµØÏò×Å$n»òÅÄ´ò£¬»òÇÜÄÃ£¬Íù$nµÄÈ«Éí¸÷´óÒªÑ¨ÕĞºô!",
        "dodge": 20,
        "parry": 10,
        "damage": 70,
        "force": 220,
        "damage_type": "´ÌÉË",
]),

//weapon_action

([ "action":"$N×óÊÖÒ»»Ó£¬ÓÒÊÖÒ»¹´£¬Ò»ÕĞ¡®"HIG" ·É»¨ÂäÒ¶"NOR"  ¡¯£¬°ÑÊÖÖĞ$wÎèÏò$nµÄË«±Û¡®"BLINK+HIG" ³ßÔóÑ¨"NOR" ¡¯!",
        "dodge": -20,
        "parry": -10,
        "damage": 60,
        "force":  140,
        "damage_type":  "´ÌÉË",
]),

([ "action":"$NÔËÊ¹$w, ×óÓÒ¿ª¹­, ÃàÃà²»¾¡, ´ÁÏò$nµÄĞØÇ°¡®"BLINK+HIM" ëşÖĞÑ¨"NOR" ¡¯, ±³ºó¡®"BLINK+HIR" ÉöÄÚÑ¨"NOR" ¡¯",
        "dodge": -30,
        "parry": -10,
        "damage": 260,
        "force": 30,
        "damage_type": "´ÌÉË",
]),

([ "action":"$NÉíÇûÒ»¶×£¬Ë«ÊÖÆş$w£¬Æ½Æ½ÍùÇ°Ö±´Ì£¬Ò»ÕĞ¡®"HIC" º£µ×·­»¨"NOR" ¡¯ĞîÊÆ´ı·¢£¬Ó­Ïò$nµÄ½Åµ×¡®"BLINK+HIC" Ó¿ÈªÑ¨ "NOR"¡¯",
        "dodge": -35,
        "parry": -20,
        "damage": 120,
        "force": 270,
        "damage_type": "´ÌÉË",
]),
([ "action":"$NÉí·¨ÇáÁé£¬Ò»ÕĞ¡®"HIY" ·É²½ŞÖğ½"NOR" ¡¯£¬ÇáÉíÒ»Ô¾£¬$w´ÌÏò$n¼çëÎ¡®"BLINK+HIW" ÔÆÃÅÑ¨"NOR"¡¯£¬¼ç¶¥¡®"BLINK+WHT" ¼ç½ºÑ¨"NOR" ¡¯",
        "dodge": 25,
        "parry": -10,
        "damage": 90,
        "force": 240,
        "damage_type": "´ÌÉË",
]),
([ "action":"$NË«±ÛÏòÍâÒ»ÕÅ£¬Ò»Ê½¡®"HIC" ´óÅôÕ¹³á"NOR" ¡¯£¬½ô¸úÒ»ÕĞ¡®"HIM" Æ½É³ÂäÑã"NOR" ¡¯£¬ÊÖÖĞ$w¼²Ïò$nµÄÑÊºí¡®"BLINK+HIB" ÌìÍ»Ñ¨"NOR" ¡¯´ÌÈ¥!\n",
        "dodge": -40,
        "parry": -20,
        "damage": 60,
        "force": 230,
        "damage_type": "´ÌÉË",
]),
([ "action":"$NÉíĞÎÒ»×ª£¬Ò»Ê½¡®"HIM" ×ªÉíÁùºÏ"NOR" ¡¯£¬½«ÊÖÖĞ$wÎè³ÉÒ»¹ÉÆøÁ÷£¬»ØĞıÔÚ$nËÄÖÜ£¬Ù¿µØÒ»ÕĞ¡®"HIY" »ØÍû´ºÔÂ"NOR" ¡¯£¬½«$w´ÌÏò$nÄÔÃÅ¡®"BLINK+WHT" ÌìÖùÑ¨"NOR" ¡¯£¬¡®"BLINK+HIC" ÑÆÃÅÑ¨"NOR" ¡¯",
        "dodge": 20,
        "parry": -20,
        "damage": 50,
        "force": 130,
        "damage_type": "´ÌÉË",
]),
([ "action":"$N´óºÈÒ»Éù¡®[1;33m ¾øÃüÆßÕë[0m ¡¯£¬¹Ä¶¯È«ÉíÄÚ¾¢£¬ÊÖÖĞ$wÎè³ÉÆßµã¹âµã£¬·Ö±ğ

Ïò$nµÄ¡®"BLINK+HIR" °Ù»áÑ¨"NOR" ¡¯£¬¡®"BLINK+WHT" Ó¡ÌÃÑ¨"NOR" ¡¯£¬¡®"BLINK+HIC" ÌìÍ»Ñ¨"NOR" ¡¯£¬¡®"BLINK+HIM" ëşÖĞÑ¨"NOR" ¡¯£¬¡®"BLINK+HIY" ÖĞëäÑ¨"NOR" ¡¯£¬¡õ
¡®"BLINK+MAG" ğ¯Î²Ñ¨"NOR" ¡¯£¬¡®"BLINK+HIR" Æøº£Ñ¨"NOR" ¡¯£¬¼±¼±Í»´Ì!",
        "dodge": -30,
        "parry": -20,
        "damage": 190,
        "force":350,
        "damage_type":"´ÌÉË",
        "post_action": (: bleed :),
]),
});

//³¬Ç¿¹¥»÷

void bleed(object me, object victim, object weapon, int damage)
{
        if(damage > 40)
         {
          victim->apply_condition("bleeding", random((int)damage / 10 +
          (int)me->query_skill("yu-needle",1)/10));
          message_vision(sprintf("[1;31m$N¡® ¾øÃüÆßÕë ¡¯´ÌÍ¸ÁË$nÉíÉÏµÄÈÎÂö´óÑ¨, $nµÄÉíÉÏÑª°ßµãµã¡£[0m\n"),me,victim);
         }
}

mapping query_action(object me, object weapon)
{

        object wea=me->query_temp("weapon");

        if( wea!=0)
            return action[random(7)+7];
        else
          return action[random(7)];
}
                                        

int valid_enable(string usage)
{
        object me=this_player();
        object wea=me->query_temp("weapon");
         {
          if(wea!=0)
          if(wea->query("skill_type")=="stabber")
           {
//ÕâÒ»ĞĞ±íÊ¾ÓĞÄÃ needle
            me->map_skill("stabber","yu-needle");
            me->map_skill("parry","yu-needle");
            me->map_skill("unarmed",0);
            return (usage=="stabber")||(usage=="parry");
           }
//´ËĞĞÒÔÏÂ±í¿ÕÊÖ
          me->map_skill("unarmed","yu-needle");
          me->map_skill("stabber",0);
          me->map_skill("parry",0);
          return (usage=="unarmed");
         }
        return (usage=="unarmed");
}

int practice_skill(object me)
{
        if(!me->query_temp("weapon") || !me->query_temp("secondary_weapon") )
          return notify_fail("Á·ÆßÆæÖËÕë¾÷»¹ÊÇÒªÄÃ¸ùÕë°É!....\n");
        if( (int)me->query("gin") < 5 )
          return notify_fail("ÄãµÄ¾«²»¹»£¬ÎŞ·¨Á·Ï°¡£\n");
        if( (int)me->query("kee") < 30 )
          return notify_fail("ÌåÁ¦²»¹»†ª! ĞİÏ¢Ò»ÏÂÔÙ¼ÌĞøÁ·°É.\n");
        if( (int)me->query("force") < 1 )
          return notify_fail("Ä¿Ç°ÄÚÁ¦²»×ã,ĞİÏ¢Ò»»á¶ùÔÙÁ·°É.\n");
        me->receive_damage("gin", 5);
        me->receive_damage("kee", 30);
        me->add("force", -1);
        return 1;
}

//parry_action_randon

int query_parry_msg(string limb)
{
//                return parry_msg[random(sizeof(parry_msg))];
return 1;
}
