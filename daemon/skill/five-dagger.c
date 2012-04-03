// five-dagger.c  .........Ãû×Ö´ıÕæ×ò
// ÎåÕĞ¾ÍºÃ..........:P

#include <ansi.h>
#include <combat.h>
inherit SKILL;
inherit SSERVER;

void bleed(object me, object victim, object weapon, int damage);
string *parry_msg=
    ({
   "$n½«ÉíÌå¿¿Ïò$N, Ò»ÕĞ¡® Õ´ÒÂÊ®°Ëµø ¡¯, ½«$Nğ¤ÔÚÔ­µØ, Ê¹²»¿ªÕĞÊ½!\n",
   "$n°ÑÊÖÖĞµÄ$wÎè³ÉÔ²»·, Ò»ÕĞ¡® ÔÆ»ØÔ²ÔÂ ¡¯, ½«$NµÄ¹¥ÊÆ¾¡Êıµ²ÁËÏÂÀ´¡£\n",
   "$nÒÔ¾²ÖÆ¶¯, ÊÖÖĞ$wÆ½¾ÙĞØÇ°, Ò»ÕĞ¡® Èç·âËÆ±Õ ¡¯, »¯½âÁË$NµÄ¹¥ÊÆ!\n",
    });

//unarmed, dagger_action

mapping *action = ({
([ "action":"$NÊ¹³ö¡® À¼»¨·÷Ñ¨ÊÖ ¡¯,Ö¸¼âÎ¢Î¢Ç°Ö¸,Ò»µÀÆø½£Ïò$nÉäÁËÈ¥!\n",
        "dodge": -10,
        "parry": -20,
        "damage": 250,
        "force":  240,
        "damage_type":  "Ñ¨µÀÊÜÖÆ",
]),

([ "action":"$NÒ»ÕĞ¡® Çå·ç·÷ĞäÕÆ ¡¯,Ë«ÊÖÒ»»Ó,Ïò$nÉ¨ÁËÒ»µÀÕÆ·ç!\n",
        "dodge": -20,
        "parry": -10,
        "damage": 260,
        "force": 230,
        "damage_type": "´ÌÉË",
]),

([ "action" : "$N¡®Çï·ç¿ñ¾í¡¯,×ª¶øÒ»Ê½¡®·É»¨ÂäÒ¶¡¯,ÉíÌåÈç·É»¨Ò¶Âä,Ïò$nÆËÁË¹ıÈ¥!\n",
        "dodge": -40,
        "parry": 10,
        "damage": 270,
        "force": 290,
        "damage_type": "ÕÆÉË",
]),

([ "action":"$N¡®ÔÆÎíÂşÂş¡¯Éí·¨ÃÔÃÉ,½ø¶øÒ»ÕĞ¡®·ÉÆÙ³¤ºç¡¯,ÉíÇûÏòÇ°Ò»Ô¾,´òÏò$n!\n",
        "dodge": 20,
        "parry": -10,
        "damage": 290,
        "force": 280,
        "damage_type": "´ÁÉË",
]),
([ "action" : "$NÒ»ÕĞ¡®¾øÔ¨·êÉú¡¯,ºöµØÒ»Ê½¡®¶´ÀïÇ¬À¤¡¯,$nÎóÈë$NµÄÏİ¾®!\n",
        "dodge": -20,
        "parry": 20,
        "damage": 300,
        "force": 280,
        "damage_type": "ÕÆÉË",
]),

//weapon_action

([ "action":"$NÊÖ³Ö$w,Ò»ÕĞ¡®´ä°ØÓ­ÈË¡¯,½ô¸úÒ»ÕĞ¡®¾£¼¬¾Ü¿Í¡¯,Ïò$nµÄË«±ÛÁ¬´ÌÊı»Ø!\n",
        "dodge": -20,
        "parry": -10,
        "damage": 240,
        "force":  60,
        "damage_type":  "´ÌÉË",
]),

([ "action":"$N°ÑÊÖÖĞ$wÎèÁË¿ª,¡®Ğş»ú°µ²Ø¡¯ÒıÓÕ$nÉÏµ±,ËæºóÒ»ÕĞ¡®¹ÈÀïÇ¬À¤¡¯´ÌÏò$n!\n",
        "dodge": 25,
        "parry": -10,
        "damage": 280,
        "force": 70,
        "damage_type": "´ÌÉË",
]),
([ "action":"$NÎè¶¯$wÒ»ÕĞ¡®¹ÈÀïÓö½Ù¡¯¼²Ïò$nµÄÑÊºí´ÌÈ¥,¶øºóÉíĞÎÍùÅÔÒ»×İ¡®¾øµØ·êÉú¡¯¿ìËÙµØ±Ü¿ª!\n",
        "dodge": -40,
        "parry": -20,
        "damage": 240,
        "force": 70,
        "damage_type": "´ÌÉË",
]),
([ "action":"$NºöµØÃæÂ¶Ï²É«,Ë«ÊÖ¼±Åõ,Ò»Ê½¡®ÉñÅ©ÒÅ¾­¡¯Ïò$nµİÁË¹ıÈ¥,Ù¿µØ$NË«ÊÖÒ»ÕÅ,´ó½ĞÒ»Éù¡®ÁğÁ§É¢êÍ¡¯!\n",
        "dodge": 20,
        "parry": -20,
        "damage": 260,
        "force": 80,
        "damage_type": "´ÌÉË",
]),
([ "action":"$NÕĞÊ½Ò»×ª,¡®¹ÅÄ¾²ÔÌì¡¯½ø¶ø´ó½ĞÒ»Éù¡®[1;33mÀ¼ÁêÆø½£¡«¡«[0m¡¯,ÊÖÖĞ$wÏò$nÈÎÂö´óÑ¨Éä³öÆßµÀÕæÆø!\n ",
        "dodge": 20,
        "parry": -20,
        "damage": 300,
        "force": 90,
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
          (int)me->query_skill("lan-dagger",1)/10));
          message_vision(sprintf("[1;33m$N¡® À¼ÁêÆø½£ ¡¯´ÌÍ¸ÁË$nÉíÉÏµÄÈÎÂö´óÑ¨, $nµÄÉíÉÏÑª°ßµãµã¡£[0m\n"),me,victim);
         }
}

mapping query_action(object me, object weapon)
{
        object wea=me->query_temp("weapon");
      if  (wea!=0)
            return action[random(5)+5];
      else
          return action[random(5)];
}

int valid_learn(object me)
{
        if(!me->query_temp("weapon"))
           tell_object(me,"Ã»ÓĞÕëÔõÃ´Á·\n");
return 1;

        if(me->query_skill("cure")*1<=me->query_skill("seven-needle",1))
return notify_fail("ÄãµÄÒ½ÁÆ¼¼ÄÜÌ«²îÁË°É! ÔõÃ´ÄÃ´ÌÈË! ÍòÒ»¸î´íÁËºÜÍ´µÄÄØ! \n");
       return 1;
}

int valid_enable(string usage)
{
/*      object me=this_player();
      object wea=find_object(me->query_temp("weapon"));
         {
          if(wea!=1)
          if(wea->query("skill_type")=="dagger")
           {
            me->map_skill("dagger","seven-dagger");
            me->map_skill("parry","seven-dagger");
            me->map_skill("unarmed",0);
            return (usage=="dagger")||(usage=="parry");
           }
          me->map_skill("unarmed","seven-dagger");
          me->map_skill("dagger",0);
          me->map_skill("parry",0);
          return (usage=="unarmed");
         }     */
        return (usage=="dagger");
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

string query_parry_msg(string limb)
{
        return parry_msg[random(sizeof(parry_msg))];
}
