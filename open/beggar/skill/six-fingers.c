#include <combat.h>
#include <ansi.h>
inherit SKILL;
void hurt(object me, object victim, object weapon, int damage);
void block(object me, object victim, object weapon, int damage);
void conti(object me, object victim, object weapon, int damage);
void sp1(object me, object victim, object weapon, int damage);
void sp2(object me, object victim, object weapon, int damage);
void sp3(object me, object victim, object weapon, int damage);

mapping *action = ({

//1
([ "action":
"$NÄ´Ö¸Ò»Äé£¬ÌåÄÚÕæÆøÁ÷×ª£¬Ê¹³ö"HIW"¡®ÉÙÉÌ½£¡¯"NOR"ÖĞµÄ"HIY"¡®´©ÔÆÁÑÊ¯¡¯"NOR"£¬ÆäĞÛ¾¢µÄ½£Â·£¬°ÔµÀµÄÏò$n$l¼¤Éä¶øÈ¥£¬ÆÄÓĞÊ¯ÆÆÌì¾ª£¬·çÓê´óÖÁÖ®ÊÆ",
        "dodge": -30,
        "parry": -20,
        "damage": 100,
        "force":  50,
        "damage_type":  "´ÌÉË",
        "weapon": "Ä´Ö¸½£Æø",
]),

//2
([ "action":
"$N¾¢Í¸Ö¸¼â£¬Ê¹³öÒ»ÕĞ"HIG"¡®ÔÀÖÅÔ¨œs¡¯"NOR"£¬Ò»µÀĞÛ»ë½£ÆøÖ±´Ì$n$l£¬ÆäÑÏ½÷ÖĞÕıÖ®×Ë£¬Õı·ûºÏ"HIW"¡®ÉÙÉÌ½£¡¯"NOR"´ó¿ª´óãØ£¬ÆøÅÉĞÛÎ°µÄ½£Òâ",
        "dodge": -30,
        "parry": -20,
        "damage": 100,
        "force":  70,
        "damage_type":  "´ÌÉË",
        "weapon": "Ä´Ö¸½£Æø",
]),

//3
([ "action":
"$NË«Ö¸Æë³ö£¬Á½¹ÉÎŞĞÎ½£Æø»¥Ïà¼¤µ´£¬Ö±±¼$n$l¶øÈ¥£¬ÕıÊÇ"HIW"¡®ÉÌÑô½£¡¯"NOR"ÖĞµÄ¾øÕĞ"HIR"¡®ÈÕÔÂÍ¬Ò«¡¯"NOR,
        "dodge": -40,
        "parry": -15,
        "damage": 100,
        "force": 90,
        "damage_type": "´ÌÉË",
        "weapon": "Ê³Ö¸½£Æø",
]),

//4
([ "action":
"$NÉíĞÎ¶·×ª£¬Ò»ÕĞ"HIC"¡®Îí¾íÔÆÓ¿¡¯"NOR"»Ã»¯³öÎŞÊıÉíÓ°£¬$n¶ÙÊ±ÁıÕÖÔÚ"HIW"¡®ÉÌÑô½£¡¯"NOR"ÎŞĞÎ½£ÆøÖ®ÏÂ",
        "dodge": -40,
        "parry": -15,
        "damage": 200,
        "force": 120,
        "damage_type": "´ÌÉË",
        "weapon": "Ê³Ö¸½£Æø",
]),

//5
([ "action":
"$NÌ¹È»µØµ¯³öÖĞÖ¸£¬Ê¹³ö"HIW"¡®ÖĞ³å½£¡¯"NOR"ÖĞµÄ"CYN"¡®Ç§¹ÅÈËÁú¡¯"NOR"£¬Æä½£ÊÆ´ó¿ª´óãØ£¬ÓĞÈçÌìÍâ·ÉÁú°ã£¬½£ÆøÁèÀ÷µØ³¯Ïò$n$l¶øÈ¥",
        "dodge": -35,
        "parry": -20,
        "damage": 200,
        "force": 140,
        "damage_type": "´ÌÉË",
        "weapon": "ÖĞÖ¸½£Æø",
        "post_action": (: block :),
]),

//6
([ "action":
"$NÉì³öÖĞÖ¸£¬Ò»ÕĞ"HIW"¡®ÖĞ³å½£¡¯"BLU"¡®À×Õğ¾ÅÖØÌì¡¯"NOR"ÉäÏò$n$l£¬ÆäÉùÊÆÈçÂäÀ×¾ªÌì£¬½ĞÈË²»¸Ò±ÆÊÓ",
        "dodge": -35,
        "parry": -20,
        "damage": 200,
        "force": 160,
        "damage_type": "´ÌÉË",
        "weapon": "ÖĞÖ¸½£Æø",
        "post_action": (: block :),
]),

//7
([ "action":
"$N»º»ºµÄÉì³öÎŞÃûÖ¸£¬¡¸Ë¿Ë¿¡±ÉùÆğ£¬ÕıÊÇ"HIW"¡®¹Ø³å½£¡¯"NOR"ÖĞµÄ"HIY"¡®×³Ö¾ÁèÔÆ¡¯"NOR"£¬Æä×¾ÖÍ¹ÅÆÓµÄ½£ÊÆÁıÕÖ×¡$nÈ«Éí£¬Ö±Ö±µÄ×²ÏòÆä$l  ",
        "dodge": 25,
        "parry": 0,
        "damage": 200,
        "force": 180,
        "damage_type": "´ÌÉË",
        "weapon": "ÎŞÃûÖ¸½£Æø",
]),

//8
([ "action":
"$NÇ±ÔËÄÚÁ¦£¬ÒÔ¾²ÖÆ¶¯£¬Ò»ÕĞ"HIG"¡®Ê±Óê´º·ç¡¯"NOR"Ö¸Ïò$nÕıÃæÈıÊ®Áù´óÑ¨£¬ÆäÊÆ¹ÅÆÓ£¬ÕıÊÇ"HIW"¡®¹Ø³å½£¡¯"NOR"ÀïµÄ¸ßÕĞ",
        "dodge": 25,
        "parry": 0,
        "damage": 150,
          "force": 200,
        "damage_type": "´ÌÉË",
        "weapon": "ÎŞÃûÖ¸½£Æø",
]),

//9
([ "action":
"$NĞ¡Ö¸ÁéÇÉµÄ×ª¶¯£¬Ò»ÕĞ"HIW"¡®ÉÙ³å½£¡¯"HIR"¡®Ñ©Äàºè×¦¡¯"NOR"µó×êµÄ³¯$n$l·ÉÈ¥£¬ÆäÊÆ¹îÆæ£¬½ĞÈË×½Ä£²»¶¨",
        "dodge": -50,
        "parry": -20,
        "damage": 150,
        "force": 220,
        "damage_type": "´ÌÉË",
        "weapon": "Ğ¡Ö¸½£Æø",
        "post_action": (: hurt :),
]),

//10
([ "action":
"$NÒ»ÕĞ"HIW"¡®ÉÙ³å½£¡¯"NOR"´ÌÏò$nĞØ¿Ú£¬ÉĞÓĞĞí³ß£¬Ò»Ğ±Éí£¬Ğ¡Ö¸»Ø×ª£¬Ïò$n$lÏ÷Âä£¬ÕıÊÇÁùÂöÉñ½£ÀïµÄÃîÕĞ"HIM"¡®·Ö»¨·÷Áø¡¯"NOR,
        "dodge": -50,
        "parry": -20,
        "damage": 250,
        "force": 230,
        "damage_type": "¸îÉË",
        "weapon": "Ğ¡Ö¸½£Æø",
]),

//11
([ "action":
"$NÇáÇÉµÄ×ª¶¯Ğ¡Ö¸£¬Ê¹³öÒ»ÕĞ"HIC"¡®·ÉÑã»ØÏè¡¯"NOR"£¬Ö»¼û"HIW"¡®ÉÙÔó½£¡¯"NOR"ºöÀ´ºöÈ¥£¬ÓĞÈçÁéÉß°ãµÄĞ±Éä$n$l",
        "dodge": -50,
        "parry": -20,
        "damage": 250,
        "force": 250,
        "damage_type": "´ÌÉË",
        "weapon": "Ğ¡Ö¸½£Æø",
]),

//12
([ "action":
"$NÕ¹¿ª¼ÜÊ½£¬Éí·¨ÇáÁé£¬ÎŞĞÎ½£Æø×óÒ»¹Õ£¬ÓÒÒ»Íä£¬Ô½×ªÔ½¼±£¬ğÍÈ»¼äÒ»½£´ÌÏò$n$l£¬ÕıÊÇ"HIW"¡®ÉÙÔó½£¡¯"NOR"ÖĞµÄÆæÕĞ"HIW"¡®·Ç¼Ù·Ç¿Õ¡¯"NOR,
        "dodge": -50,
        "parry": -20,
        "damage": 300,
        "force": 250,
        "damage_type": "´ÌÉË",
        "weapon": "Ğ¡Ö¸½£Æø",
        "post_action": (: hurt :),
]),

//13
([ "action":
HIW"$N´óºÈÒ»Éù£¬¹Ä¶¯È«ÉíÕæÆø£¬ÄÚ¾¢Á÷×ª£¬Ë«ÊÖÁù½£Æë·¢£¬Ê®Ö¸·Öµ¯£¬ö®Ê±½£Æø×İºá£¬ËÆÓĞÎŞÊıÑ¸À×¼²·ç»¥³å¼¤µ´Ïò$n¶øÈ¥"NOR,
        "dodge": -50,
        "parry": -20,
        "damage": 300,
        "force": 250,
        "damage_type": "´ÌÉË",
        "weapon": "ÎŞĞÎ½£Æø",
        "post_action": (: conti :),
]),

//14°ÂÒå(Ò»)
([ "action":
HIY"\n$NÑÛÖĞ¾«¹â´óÊ¢£¬´óºÈ:\n\n"
HIW"             ¡®\n"
HIR"                ¶áÃü"HIW"¡«"HIG"Á¬»·"HIW"¡«"HIM"Áù¾ø½£"HIW"!!\n"
"                                     ¡¯\n"
"$NÍ»È»¼±ÔË¡®Ò»ÑôĞÄ·¨¡¯£¬Æø¾¢ÂúÓ¯£¬Ò»¸ö¼ı²½£¬Ïò$n×İÉí·ÉÈ¥\n"NOR,
        "dodge": 80,
        "parry": 50,
        "damage": 300,
        "force": 300,
        "damage_type": "´´ÉË",
        "post_action": (: sp1 :),
]),

//15°ÂÒå(¶ş)
([ "action":
HIY"\n$N»º»ºÄîµÀ:\n\n"NOR
GRN"                   ¡® Á½½ÅÌ¤·­³¾ÊÀÂ·£¬Ò»¼çµ£¾¡¹Å½ñ³î ¡¯\n\n"
HIW"ÅäºÏ¡®Áè²¨Î¢²½¡¯µÄ¾«Ãî²½·¨£¬»Ã»¯³ÉÎŞÊıÈËÓ°°üÎ§$n£¬Ë«ÊÖ¼²Éä£¬Áù½£Æë·¢£¬ö®Ê±
¼ä$nÏİÈëÎŞĞÎ½£ÆøµÄ¿ñÂÒ½£ÍøÖ®ÖĞ£¬½£Æø¼¤µ´£¬¾¹ÊÇÒª½«$nÈ«ÉíËºÁÑ£¬´ËÕĞÕıÊÇ
´óÀí¶ÎÊÏµÄ½ûÓÃÉ±ÕĞ\n\n"
"                         ¡« "HIY" ÎŞ"HIM" ³£"HIW" £®"RED" ºŞ"HIC" ²Ô"BLU" Ìì "HIW" ¡«\n\n"NOR,
        "dodge": 80,
        "parry": 50,
        "damage": 300,
          "force": 300,
        "damage_type": "´ÌÉË",
        "post_action": (: sp2 :),
]),


//16°ÂÒå(Èı)
([ "action":
HIY"\n$N»ØÉíÊÕ²½³¤Ò÷µÀ:\n\n"NOR
YEL"                   ¡® Ã÷ÔÂ¸¡ÔÆÏà°ëÑÚ£¬ÆßĞÇ²»ÂäÒ«³¤¿Õ ¡¯\n\n"
HIW"ºöÈ»¼ä¸ß¸ßÔ¾Æğ£¬ÉíĞÎÑÚ¿Õ£¬×óÕÆ¸§ĞØ£¬ÓÒÊÖÁ¬·¢ÆßµÀÎŞĞÎ½£Æø£¬¼²Ïò$nÖÜÉíÒªÑ¨¶ø
È¥£¬»è°µÖ®ÖĞ£¬Ö»¼ûÆßµÀ½£Ã¢½ğ¹âÒ«ÑÛ£¬ÄËÊÇ´óÀí¶ÎÊÏÁùÂöÉñ½£ÖĞµÄ¾øÑ§\n\n"
"                           ¡«"HIM" Æß"HIY" ĞÇ"HIC" Âä"HIG" ³¤"HIR" ¿Õ"HIW" ¡«\n\n"NOR,
        "dodge": 80,
        "parry": 50,
        "damage": 300,
          "force": 300,
        "damage_type": "´ÌÉË",
        "post_action": (: sp3 :),
]),
});

void hurt(object me, object victim, object weapon, int damage)
{
        int force;
        if( random(100)>50 && !me->query_temp("conti",1) && 
            me->query("family/family_name")=="¶Î¼Ò" )
        {
          force = me->query_skill("sunforce",1);
          if(force > 250) force=250;
          victim->receive_damage("kee", 50+force );
          message_vision(sprintf(HIM"$NÁùÂöÉñ½£¹îÒìµÄÆø¾¢×êÈë$nÌåÄÚ£¬$nÁ³ÉÏÍ»È»Ò»ÕóÇà°×£¬¿´À´ÒÑÊÜÁË²»Ğ¡µÄÄÚÉË¡£\n"NOR),me,victim);
          COMBAT_D->report_status(victim);
          me->add("force",-force);
        }

        else
        {
          message_vision(sprintf(HIW"$nÀÇ±·µØÉÁ¹ıÁË$NµÄ¹îÒìÆø¾¢, µ«ÒÑ´ó´ó³öôÜ¡£\n"NOR),me,victim);
        }
}
void block(object me, object victim, object weapon, int damage)
{
        if( random(100)>50 && !me->query_temp("conti",1) &&
            me->query("family/family_name")=="¶Î¼Ò" )
        {
          victim->apply_condition("blockade",3);
          message_vision(sprintf(HIY"$NÁùÂöÉñ½£°µ²ØÒ»ÑôÖ¸ÊÖ·¨£¬·´ÊÖµãÖĞ$nµÄëşÖĞ´óÑ¨¡£\n"NOR),me,victim);
          victim->start_busy(1);
          COMBAT_D->report_status(victim);
        }
        else
        {
          message_vision(sprintf(HIW"$NÊÔÍ¼ÒÔÒ»ÑôÖ¸·âËø$n, µ«ÊÇ±»$n¶ãÁË¿ªÀ´¡£\n"NOR),me,victim);
        }
}
void conti(object me, object victim, object weapon, int damage)
{
         int i,time = 3;
        if( me->query("force_factor") >= 10 && 
            me->query("family/family_name")=="¶Î¼Ò" && 70>random(100) )
        {
          if( me->query_temp("conti") == 0 )
          {
            me->delete_temp("super");
            me->set_temp("conti",1);
      message_vision(sprintf("\n[1;33m$NºöÈ»¶ÙÎòÁùÂöÉñ½£[1;5;36mÆøÓÎ°ÙÑ¨[0m¡¢[1;5;36mÁ¬Ãà²»¾ø[0m[1;33mµÄÒª¾÷, ½£Æø×ÔÈ»¶øÈ»µÄÆÆÌå¶ø³ö, Óû°Õ²»ÄÜ!![0m\n"),me);
              for(i=1;i<=time;i++)
              COMBAT_D->do_attack(me, victim, me->query_temp("weapon"), TYPE_QUICK);
            me->delete_temp("conti");
          }
        }
}

void sp1(object me, object victim, object weapon, int damage)
{
int i;
if(me->query("env/Áù¾ø½£","YES")&&!me->query_temp("conti",1))
{
  for(i=1;i<=6;i++)
  {
    switch(i)
    {
     case 1:
message_vision(sprintf("$NÁìÎòÁË"HIW"¡®ÉÙÉÌ½£¡¯"HIY"¡®ÆøÓ¿ÈçÉ½£¬Ï¯¾íÌìÏÂ¡¯"NOR"µÄÕæÒâ£¬Ïò$nµ±Í·Õ¶ÏÂ!\n"),me,victim);
     break;
     case 2:
message_vision(sprintf("\n$NÁìÎòÁË"HIW"¡®ÉÌÑô½£¡¯"HIG"¡®ÉíĞÎÁé¶¯£¬ÊÆÈôÁ÷ÔÆ¡¯"NOR"µÄÕæÒâ£¬¶Ô$nËÄÖ«¿³Âä!\n"),me,victim);
     break;
     case 3:
message_vision(sprintf("\n$NÁìÎòÁË"HIW"¡®ÖĞ³å½£¡¯"HIC"¡®½£Æø³åÌì£¬Ó¯²»¿É¾Ã¡¯"NOR"µÄÕæÒâ£¬Íù$nĞØÇ°¼²´Ì!\n"),me,victim);
     break;
     case 4:
message_vision(sprintf("\n$NÁìÎòÁË"HIW"¡®¹Ø³å½£¡¯"HIM"¡®ÆøÄıµ¤Ìï£¬ÒÔ¾²ÖÆ¶¯¡¯"NOR"µÄÕæÒâ£¬ğÍÈ»¼ä´ÌÏò$n!\n"),me,victim);
     break;
     case 5:
message_vision(sprintf("\n$NÁìÎòÁË"HIW"¡®ÉÙ³å½£¡¯"NOR""CYN"¡®Ó¦×óÔòÓÒ£¬Ğé»Ã²»¶¨¡¯"NOR"µÄÕæÒâ£¬½£Ó°°üÎ§×¡$n!\n"),me,victim);
     break;
     case 6:
message_vision(sprintf("\n$NÁìÎòÁË"HIW"¡®ÉÙÔó½£¡¯"BLU"¡®ÔÆÚÜ²¨¹î£¬Òà»ÃÒàÕæ¡¯"NOR"µÄÕæÒâ£¬½£Æø¼²ÉäÏò$n!\n"),me,victim);
     break;
     }
message_vision(sprintf(HIR"$NÈ·ÊµÃüÖĞ$nÒªº¦£¬$n¶ÙÊ±ÑªÁ÷ÂúµØ¡£\n"NOR),me,victim);
          victim->receive_damage("kee",110);
          COMBAT_D->report_status(victim, 1);
          me->add("force",-20);
   }
message_vision(sprintf(HIW"\nÄãÊ¹Á¦¹ı¶È,Ò»Ê±Ö®¼äÎŞÁ¦ÔÙÕ½!\n"NOR),me,victim);
me->start_busy(1);
 }
}
void sp2(object me, object victim, object weapon, int damage)
{
if(!me->query_temp("conti",1)) {
        int six, force;
        six = me->query_skill("six-fingers",1);
        force = me->query_skill("sunforce",1);
        if(force>200) force=200;
          message_vision(sprintf(HIG"$N×İÉù³¤Ğ¥£¬Ë«ÊÖ»ìÔª¹éÒ»ÖĞ¹¬Ö±Èë£¬ÎŞÊıµÀ½£ÆøÔÚ$nÉíÉÏ¶Ô´©¶ø¹ı!!\n"NOR),me,victim);
          victim->receive_damage("kee",six+force);
          victim->apply_condition("bleeding",5);
          COMBAT_D->report_status(victim);
}
}
void sp3(object me, object victim, object weapon, int damage)
{
if(!me->query_temp("conti",1)) {
        int force;
        force = me->query_skill("sunforce",1);
        if(force > 300) force=300;
          message_vision(sprintf(HIC"$nÏÈÇ°ÄÚÉËÊÜµ½$NÎŞĞÎ½£ÆøÇ£Òı£¬$nµÄÉËÊÆ¸ü¼ÓÖØÁË!!\n"NOR),me,victim);
          victim->receive_damage("kee",force);
          victim->start_busy(1);
          COMBAT_D->report_status(victim);
}
}

mapping query_action(object me, object weapon)
{
        int level=(int)(me->query_skill("six-fingers",1));

        if ( level < 10 )
           return action [random(3)];
        else if ( level < 20 )
           return action [random(5)];
        else if ( level < 30 )
           return action [random(7)];
        else if ( level < 40 )
           return action [random(9)];
        else if ( level < 50 )
           return action [random(11)];
        else if ( level < 60 )
           return action [random(13)];
        else if ( level < 70 )
           return action [random(9)+4];
        else if ( level >= 70 && me->query_temp("super",1))
           return action [12];
        else if ( level == 100 && me->query("marks/six_sp")==3 &&
                  me->query("family/family_name") == "¶Î¼Ò")
           return action [random(12)+4];
        else
           return action [random(8)+5];
}

int vlid_learn(object me)
{
        if( me->query_temp("weapon") || me->query_temp("secondary_weapon") )
          return notify_fail("Á·ÁùÂöÉñ½£»¹ÊÇÒª¿ÕÊÖ°É....\n");
        if(me->query_skill("force")*3<=me->query_skill("six-fingers",1))
          return notify_fail("ÄãµÄ»ù±¾ÄÚÁ¦¼¼ÄÜ²»×ã, ÎŞ·¨Á·ÁùÂöÉñ½£¡£\n");
        if(me->query_skill("literate")*3<=me->query_skill("six-fingers",1))
          return notify_fail("ÄãµÄÖªÊ¶²»×ã£¬ÎŞ·¨Ìå»áÁùÂöÉñ½£Àï£¬È«Éí¾­ÂöÔËĞĞÖ®µÀµÄ¾«Òª±ä»¯¡£\n");
        return 1;
}

int valid_enable(string usage)
{
      if(this_player()->query_skill("six-fingers",1) >= 45)
         {
            return (usage=="unarmed"||usage=="stabber")||(usage=="parry");
         }
          return (usage=="unarmed");
}

int practice_skill(object me)
{
        if( me->query_temp("weapon") || me->query_temp("secondary_weapon") )
          return notify_fail("Á·ÁùÂöÉñ½£»¹ÊÇÒª¿ÕÊÖ°É....\n");
        if( (int)me->query("gin") < 5 )
          return notify_fail("ÄãµÄ¾«²»¹»£¬ÎŞ·¨Á·Ï°¡£\n");
        if( (int)me->query("kee") < 30 )
          return notify_fail("ÌåÁ¦²»¹»†ª,ĞİÏ¢Ò»ÏÂÔÙ¼ÌĞøÁ·°É.\n");
        if( (int)me->query("force") < 1 )
          return notify_fail("Ä¿Ç°ÄÚÁ¦²»×ã,ĞİÏ¢Ò»»á¶ùÔÙÁ·°É.\n");
        me->receive_damage("gin", 5);
        me->receive_damage("kee", 30);
        me->add("force", -1);
        return 1;
}
string perform_action_file(string action)
{
        return CLASS_D("scholar")+"/six-fingers/"+action;
}
