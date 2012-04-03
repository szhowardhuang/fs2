#include <combat.h>
#include <ansi.h>
inherit SKILL;


void sp2(object me, object victim, object  weapon, int damage);
void sp4(object me,object victim,object weapon,int damage);

mapping *action= ({
 (["action":"$NÊ¹³ö [0;1;36;45m¡õ[1mC[1m [1m¡õ[1m¡õ[1m [1m¡õ[1mW[1m [1m¡õ[1mQ[1m [1m¡õ[1m¡õ[0m  [0;1;33m¡õ[1m¡õ[1m [1m¡õ[1m¡õ[1m [1m¡õ[1m}[1m [1m¡õ[1m¡õ[0m

              [0;1;32m¡õ[1m¡õ[1m [1m¡õ[1ml[1m [1m¡õ[1m¡õ[1m [1m¡õ[1m¡õ[0m£¬[0;1;31m¡õ[1m¡õ[1m [1m¡õ[1m¡õ[1m [1m¡õ[1m¡õ[1m [1m¡õ[1m¡õ[0m£¬[0;1;35m¡õ[1m¡õ[1m [1m¡õ[1m¡õ[1m [1m¡õ[1m¡õ[1m [1m¡õ[1mz[0m

             $N¾ÙÆğ$w,Íù$nµÄ¸÷´óÑ¨µÀ¹¥È¥,\nÁî$nÉîÉîµÄ±»ÄãËùÉË",
    "dodge":-10,
    "parry":20,
    "damage":90,
    "force":45,
    "damage_type":"ğöÉË"
  ]),
 (["action":"$N¿ÚÖĞÒ»ÍÂÕæÆø£¬Ê¹ÓÃ [0;1;36;45m¡õ[1mC[1m [1m¡õ[1m¡õ[1m [1m¡õ[1mW[1m [1m¡õ[1mQ[1m [1m¡õ[1m¡õ[0m [0;1;33m¡õ[1m¡õ[1m [1m¡õ[1m¡õ[1m [1m¡õ[1mg[1m [1m¡õ[1m¡õ[0m

             ½«$wÈ­¶ËÔ²×ªÎªĞÎ£¬ÃàÃÜ¼û³¤£¬Ïò$n¹¥´ò¹ıÈ¥.",
    "dodge":40,
    "parry":50,
    "damage":100,
    "force":50,
    "damage_type":"ğöÉË"
  ]),
  (["action":"$NºöÈ»ÁìÎò"+HIC"Æßº£¶À°ÔÈ­"NOR"

                 µÚÈıÊ½"HIB"¡êÌìºä¶ñÀË ¡ê"NOR+"

              ´ÓÔÆÎíÖĞ±ä»¯³ö¸÷ÖÖ²ğÕĞÖ®È­ÕĞ£¬¼«¾¡¹îÆæÖ®ÄÜÊÂ,¶¯ÏòÎŞ¶¨£¬²»¿É×½Ãş,Ïò$nºÜºÜµÄ´ÌÁË¹ıÈ¥",
    "dodge":10,
    "parry":10,
    "damage":155,
    "force":80,
    "damage_type":"ğöÉË"
  ]),
  (["action":"$NÍ»È»½£·¨Ò»Õ¹,Ê¹³ö"+HIC"Æßº£¶À°ÔÈ­"NOR"

                  µÚËÄÊ½"BLU"¡ê°Ôº£ÑïÍş ¡ê"NOR+"

               Éí×ÓÍ»È»Ñ¸ËÙÌÚ¿Õ¶ø·É,ÊÖÖĞµÄÈ­ÆøËæ×ÅÉíÌåµÄĞı×ªÈç¿ñ·ç´óÓê,Ïò$n$1·É±¼¶øÈ¥....",
    "dodge":30,
    "parry":20,
    "damage":145,
    "force":70,
    "damage_type":HIB"ÆÆÌå"NOR"Ö®ÉË",
  ]),
  (["action":"$NÊ¹³ö"+HIC"Æßº£¶À°ÔÈ­"NOR"

                 µÚÎåÊ½"HIR"¡êÑªº£Ç±Áú ¡ê"NOR+"

              $NºöÈ»Ò»·ÖÎª¶ş,¶şÈËÍ¬Ê±Í¦$w¼±´ÌÏòÇ°£¬Í¬Ê±¼²´Ì$nÑÊºí£¬³öÕĞÑ¸¼²ÎŞ±È",
    "dodge":45,
    "parry":45,
    "damage":105,
    "force":100,
    "damage_type":"ğöÉË"
  ]),
  (["action":"$N´ó½Ğ"+HIC"Æßº£¶À°ÔÈ­"NOR"Ö®

                "HIW"¡ê¼«º£Áú¾í ¡ê"NOR+"

              Ë²¼äÁìÎòÆäÖĞÖ®¾«Ëè,Á¢¿Ì½«È­¿ìËÙÃÍ»÷,È­ÈçÁ÷ĞÇµÄºöÀ´ºöÈ¥$n$1µÄ¾±ÉÏ»®ÁË¸öÜ½ÈØ....",
    "dodge":45,
    "parry":45,
    "damage":170,
    "force":100,
    "damage_type":"ğöÉË"
  ]),
  (["action":"$N´óÉù¿ñº¿,Ê¹³ö"+HIC"Æßº£¶À°ÔÈ­"NOR"µÚÆßÊ½"HIM"¡ê»ğº£·ÙÌì ¡ê"NOR+",$NÉíÈçÏÉº×µÄ·ÉÏè,½èÖúÈçÏÉº×µÄÉñÁ¦,ÕĞÕĞ»÷ÖĞ$nÒªº¦,Ê¹µÄ$1ÊÜÉË²»Çá....",
    "dodge":45,
    "parry":55,
    "damage":165,
    "force":100,
    "damage_type":"ğöÉË"
  ]),
  (["action":"$NÓĞÈçÒ»Ö»Ò°Âí°ãµÄ±¼ÅÜ,Ê¹³ö"+HIC"Æßº£¶À°ÔÈ­"NOR"

                µÚ°ËÊ½"WHT"¡êÊ¯¹Ø»ØÂí ¡ê"NOR+"

              Á½ÊÖ½«$wÕ¹¿ª£¬Ë¢Ë¢ÊıÈ­£¬Ö»Ìı$n$1¼¸¡°°¡¡±µÄÒ»Éù´ó½Ğ!~~~~",
    "dodge":-45,
    "parry":55,
    "damage":130,
    "force":90,
    "damage_type":"ğöÉË"
  ]),
  (["action":"$N´óºÈÒ»Éù

               "+HIR"¡ê~Ñã~»Ø~×£~ÈÚ~ ¡ê"NOR"

               Ö®"HIC"³åÁé½£·¨"NOR+"µÚ¾ÅÊ½,$N¾Û¼¯ÌìµØ¼äµÄºÆÈ»ÕıÆø,ÌìµØÕıÆøÁ¢¼´³É·ïĞÎ°ãµÄ¾Û¼¯ÔÚ$wÖĞ,Ïò$n$1ÃÍ¹¥¶øÈ¥",
    "dodge":35,
    "parry":-55,
    "damage":160,
    "force":80,
    "damage_type":"ğöÉË"
   ]),
   (["action":"$NÊ¹³ö"+HIC"Æßº£¶À°ÔÈ­"NOR"

                 µÚÊ®Ê½"HBYEL"¡ê-Íò-ÔÀ-³¯-×Ú- ¡ê"NOR+"

               $NÍ»È»¼äÈ­ÆøÒ»ÍÂ£¬$w»¯×÷Ò»µÀ°×ºçÈçÇàÁú°ãµÄ£¬Ïò$n$1Ö±³å¹ıÈ¥....",
    "dodge":45,
    "parry":55,
    "damage":195,
    "force":180,
    "damage_type":"ğöÉË"
   ]),
   (["action":"$NÉî¸ĞÍòÄî¾ã»Ò,Ê¹³ö"+HIC"Æßº£¶À°ÔÈ­"NOR"ÖĞµÄ

               "HIB"¡ê±¯Í´ÄªÃû ¡ê"NOR+"

               ÔÚ±¯ÉËÏÂÔö¼ÓÄªÃûµÄÁ¦Á¿,ÉíÌåÒ»Ò«,È­È­´òÖĞ$nµÄÒªº¦....",
    "dodge":55,
    "parry":65,
    "damage":255,
    "force":110,
    "damage_type":"ğöÉË"
    ]),

});


void sp4(object me,object victim,object weapon,int damage)
{
   int i = me->query("unarmed")*10 + me->query_skill("seven-unarmed");
   if (me->query_skill_mapped("force") == "seven-unarmed" && random(400) < 10 )
   {       message_vision(HIW"$NÔËÆğ»ğº£·ÙÌì£¬°Ñ$nµÄÕæÆøµ¼Èë$NµÄÆøº£ÖĞ¡£\n"NOR,me,victim);
    victim->receive_damage("kee",random(i));
    me->add("kee",random(i));
   }
}
int valid_enable(string usage)
{
        return (usage=="unarmed"||usage=="parry");
}
mixed hit_ob(object me, object victim, int damage_bonus)
{
        if( damage_bonus < 100 ) return 0;

        if( random(damage_bonus/2) > victim->query_str() ) {
                victim->receive_wound("kee", (damage_bonus - 100) / 3 );
                switch(random(3)) {
                        case 0: return "ÄãÌıµ½¡¸¿¦À²¡±Ò»ÉùÇáÏì£¬¾¹ËÆÊÇ¹ÇËéµÄÉùÒô£¡\n";
                        case 1: return "$N¾¢Á¦Ò»ÍÂ£¬$nµÄ$l·¢³ö¡¸¿¦¡±µØÒ»Éù±¬Ïì£¡\n";
                        case 2: return "Ö»Ìı¼û$nµÄ$l¡¸¿¦¡±µØÒ»Éù ...\n";
                }
        }
}

