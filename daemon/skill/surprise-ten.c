//¾ªÌìÊ®Ê½
// by dhk 2000.5.5
#include <combat.h>
#include <ansi.h>
inherit SSERVER;
inherit SKILL;
void hurt(object me, object victim, object weapon, int damage);
void block(object me, object victim, object weapon, int damage);
void conti(object me, object victim, object weapon, int damage);
void sp1(object me, object victim, object weapon, int damage);
void sp2(object me, object victim, object weapon, int damage);
void sp3(object me, object victim, object weapon, int damage);
void kee(object me, object victim, object weapon, int damage);

mapping *action = ({

//ÌìµØË«ØÔ....(1)
([ "action":
         "$NË«×ãÒ»¿ç£¬ÌåÄÚÕæÆøÁ÷×ª£¬Á¢¼´°Ú\³ö"BLINK+HIW"¡®¾ªÌìÊ®Ê½¡¯"NOR"ÖĞµÄ"HIY"¡®ÌìµØË«ØÔ¡¯"NOR"£¬ÆäÕĞÊ½ÖĞÔÌº¬ÌìµØÍò»¯µÄÉñÆæØÔÏó\n"
      NOR"£¬°ÔµÀµÄÏò$n$lÖ±±Æ¶øÈ¥£¬ÆÄÓĞÊ¯ÆÆÌì¾ª¡¢·ÉÉ³×ßÊ¯Ö®ÊÆ¡£ \n"
      NOR"                                                                     \n"
BLINK+HIY"                                          ¡®  Ìì  µØ  Ë«  ØÔ  ¡¯"NOR"\n"
      NOR"                                                                     ",
        "dodge": 50,
        "parry": 50,
        "damage": 2000,
        "force":  5000,
        "damage_type":  "ÕğÉË",
        "weapon": "×ó×ãÓÒÕÆ",
        "post_action": (: hurt :),
]),

//´©É½Ö¸....(2-1)
([ "action":
         "$N¾¢Í¸Ö¸¼â£¬Ê¹³öÒ»ÕĞ"BLINK+HIW"¡®¾ªÌìÊ®Ê½¡¯"NOR"ÖĞµÄ¾øÕĞ"HIR"¡®´©É½Ö¸¡¯"NOR"£¬Ò»µÀĞÛ»ëÖ¸ÆøÖ±½ø$n$l£¬ÆäÆÆ¿ÕÖ®ÊÆÖĞ¼Ğ´ø‹ü\n"
      NOR"ÈáÆ®Ë·Ö®¾¢£¬ÍşÁ¦×ãÒÔÕğÆÆÃûÉ½¾ŞÔÀ¡£\n"
      NOR"                                                                   \n"
BLINK+HIR"                                            ¡®  ´©  É½  ÆÆ  ¡¯"NOR"\n"
      NOR"                                                                   ",
        "dodge": 200,
        "parry": 200,
        "damage": 600,
        "force":  1000,
        "damage_type":  "´ÌÉË",
        "weapon": "»¥ÏâÖĞÖ¸",
]),

//µ¹ĞĞãç²¨....(3)
([ "action":
NOR"$N»º»ºÔËÆøÉÏ¼ç£¬Ë«ÊÖ¸ß¾Ù¡¢Ë«ÑÛÍûÌì£¬²»Ò»»á$NÉîÉîµÄÎüÒ»¿ÚÆø£¬È»ËÄÖÜºöÈ»\n"
NOR"ĞıÆğÇ¿ÁÒµÄÆøÎĞ¡£ÕıÊÇ"BLINK+HIW"¡®¾ªÌìÊ®Ê½¡¯"NOR"ÖĞµÄ¾øÕĞ"HIM"¡®µ¹ĞĞãç²¨¡¯"NOR"£¬ĞĞÕĞÖ®Ê±ËÄÖÜ´óÆøÄæĞĞ\n\n"

BLINK+HIM"                         ¡®  µ¹  ĞĞ  ãç  ²¨  ¡¯"NOR"\n\n"

HIM"$n±»µ¹ĞĞãç²¨Ç¿¾¢µÄÆøÑ¹Ó°ÏìÏÂ£¬ÉíÊÜÕæÆøÄæĞĞµÄÍ´¿à"NOR"¡£\n",
        "dodge": 70,
        "parry": 70,
        "damage": 840,
        "force": 7000,
        "damage_type": "ÖÍÉË",
        "weapon": "ÕÆÆø",
        "post_action": (: hurt :),
]),

//ÎüĞÇ¾÷....(4)
([ "action":
NOR"$NÉíĞÎ¶·×ª²¢ÉîÉîµÄÍÂ³öÒ»¿ÚÕæÆø¡¢Ì§Í·ÑöÌì´óºÈÒ»Éù\n"
NOR"£¬Ò»ÕĞ"HIG"¡®"HIY" Îü"HIC" ĞÇ"HIM" ¾÷"HIG" ¡¯"NOR"Ê¹ÖÜÎ§Ê±¿Õ»Ã»¯³öÎŞÊı$NµÄÉíÓ°£¬¶ÙÊ±ÈÕÔÂÊ§É«¶ÀÌìĞÇÉÁÒ«¡£\n"
NOR"´ıÒ»ÇĞ»Ø¹éÆ½¾²Ö®Ê±£¬Ö»¼û$NÉí·º½ğÉ«¹âÃ¢£¬ÄÚÏ¢³äÓ¯¡¢²»ÍÂ²»¿ì¡£\n",
        "dodge": 100,
        "parry": 100,
        "damage": 100,
        "force": 2000,
        "damage_type": "ÆÈÉË",
        "weapon": "ĞÇ¹âÆÇÆø",
        "post_action": (: kee :),
]),

//ÈÕÔÂ²¢ĞĞ....(5-1)
([ "action":
"$NË«Ä¿»º±ÕÆøÔËË«ÑÛ£¬ºöÈ»Õö¿ª×óÑÛÊ¹³ö"HIB"¡®ÈÕÔÂ²¢ĞĞ¡¯"NOR"ÖĞµÄ"HIM"¡®ê»ÈÕ¾çÉı¡¯"NOR"£¬Ò»µÀ¹â²Ê¶áÄ¿µÄºì¹âÍÑÑÛ¶ø³ö\n"
"¡¢µç¹â×ßÊ¯°ã°ÔµÀµØ³¯Ïò$n$l¶øÈ¥¡£\n",
        "dodge": 60,
        "parry": 60,
        "damage": 1500,
        "force": 1000,
        "damage_type": "´´ÉË",
        "weapon": "×óÑÛÕæÆø",
        "post_action": (: hurt :),
]),

//¼±´µ·ç....(6)
([ "action":
   "$NÄıÆø¶¨Éñ£¬Í»È»ËæÊÖÒ»»Î£¬±ã¼´Ê¹³ö"BLINK+HIW"¡®¾ªÌìÊ®Ê½¡¯"NOR"ÖĞµÄ"BLU"¡®¼±´µ·ç¡¯"NOR"£¬ÄªÃûµÄ²úÉúÒ»¹ÉÇ¿¾¢ÎŞÆ¥µÄ¿ñ·ç£¬·ç×ª¼±ËÙ¡£"NOR"\n",
        "dodge": 20,
        "parry": 20,
        "damage": 100,
        "force": 1000,
        "damage_type": "ÕòÉË",
        "weapon": "Ç¿´óÆøÑ¹",
        "post_action": (: block :),
]),

//ÈÕÔÂ²¢ĞĞ....(5-2)
([ "action":
"$NË«Ä¿»º±ÕÆøÔËË«ÑÛ£¬ºöÈ»Õö¿ªÓÒÑÛÊ¹³ö"HIB"¡®ÈÕÔÂ²¢ĞĞ¡¯"NOR"ÖĞµÄ"HIC"¡®ÓñÍÃ±¼Ìì¡¯"NOR"£¬Ò»µÀ¹â²Ê¶áÄ¿µÄ°×¹âÍÑÑÛ¶ø³ö\n"
"¡¢ÒÔ·ïÎè¾ÅÌìÖ®ÊÆµØ³¯Ïò$n$l¶øÈ¥¡£\n",
        "dodge": 60,
        "parry": 60,
        "damage": 1500,
        "force": 1000,
        "damage_type": "´´ÉË",
        "weapon": "ÓÒÑÛÕæÆø",
        "post_action": (: hurt :),
]),

//Ç¿Á¦-´©É½Ö¸....(2-2)
([ "action":
HIR"$NĞÄÈçÖ¹Ë®£¬²»¶¯ÈçÉ½£¬ÄÚÁ¦¼±¾çÉÏÉı¡£ºöÈ»$NÒÔÑ¸À×Ö®ËÙ£¬¿ìËÙÆÛÏò$n"HIR"¶ø\n"
HIR"È¥¡£´ËÊ±$N"HIR"ÒÑ¾­ÔÚÓÒÊÖÖĞÖ¸Äı¾ÛÇ¿´óÂúÓ¯µÄÕæÆø¡¢Á¦Á¿£¬µ±À´µ½$n"HIR"ÉíÅÔÖ®Ê±"NOR"\n"
HIY"Ê¹³ö"BLINK+HIW"¡®¾ªÌìÊ®Ê½¡¯"NOR+HIY"ÖĞµÄ¾øÕĞ\n"
NOR"\n"
BLINK+HIC"                               ¡®  "HIR"´©  É½  Ö¸ "HIC" ¡¯"NOR"\n"
NOR"\n"
HIG"¾¢Á¦Ò»ÍÂ£¬ÓĞÈçÉ½±ÀµØÁÑ¡¢ÆÆÉ½¡¢´©É½Ö®ÊÆÖ±´Ì$n¶øÀ´¡£\n"
HIR"$n±»´©É½Ö¸»÷ÖĞ£¬ÄÚ¸­ÊÜ´´ÉõÉî£¬ÒÑÆøÈçÓÎË¿"NOR"¡£\n",
        "dodge": 10,
        "parry": 10,
        "damage": 4000,
        "force": 2400,
        "damage_type": "´ÌÉË",
        "weapon": "»¥ÏâÖĞÖ¸",
]),

//Å­Ê½ÌìÃ¢´Ì....(7)
([ "action":
HIW"$NÉ±ÄîÒ»¶¯£¬Á³É«Öè±ä¡£ÓÒÊÖÒ»³öÁ¢¼´°Ú\³ö"BLINK+HIW"¡®¾ªÌìÊ®Ê½¡¯"NOR"ÖĞµÄ"HIC"¡®Å­Ê½ÌìÃ¢´Ì¡¯"NOR"µÄÆğÊÖÊ½¡£Ö»¼û$NÅ­ÆøÉÏÉı£¬ÓÒÊÖ½¥½¥Äı³öÇàÑÕÉ«½£Ã¢£¬ö®Ê±¹âÃ¢ÁÁÈç°×Öç¡£\n"
"$nµÄÑÛ¾¦±»¹âÃ¢ËùÉË£¬ÉÁ±Ü²»¼°£¬ÉíÌåÒÑ±»ÌìÃ¢´Ì½£ÆøËùÖØ´´¡£\n",
        "dodge": 10,
        "parry": 10,
        "damage": 1400,
        "force": 1000,
        "damage_type": "´ÌÉË",
        "weapon": "ÎŞĞÎ½£Æø",
        "post_action": (: conti :),
]),

//°ÂÒå(Ò»)....(8)
([ "action":
HIY"\n$NÑÛÖĞ¾«¹â´óÊ¢£¬´óºÈ:\n\n"
HIW"             ¡®\n"
HIY"                  Ìì»Ê"HIW"ÌìÊ½"HIC"¡«"HIM"¸²Ìì"HIR"ÈıÑô"NOR"\n"
"                                       ¡¯\n"
"$NÍ»È»¼±ÔË¡®"HIY"ÓùÌì»ÊÆø"NOR"¡¯£¬Æø¾¢ÂúÓ¯£¬Ò»¸ö¼ı²½£¬Ïò$n×İÉí·ÉÈ¥\n"NOR,
        "dodge": 80,
        "parry": 50,
        "damage": 7000,
        "force": 7000,
        "damage_type": "´´ÉË",
        "post_action": (: sp1 :),
]),

//°ÂÒå(¶ş)....(9)
([ "action":
HIW"Ö»¼û$NÕæÆøÒ»Ìá£¬ö®ÄÇÌì¼Ê·¢ÉúÆæÃîµÄ±ä»¯£¬¶ÙÊ±ÂşÌìº®Ñ©£¬ÆøÎÂ¾ç½µ¡£\n\n"
HIY"\n$N´óºÈÒ»Éù:\n\n"NOR
   "
                      "GRN"¡®      "HIC"¼±¶³"HIM"Ã·»¨"HIY"¡«"NOR+WHT"Ñ©Àï²»µò"NOR"      "GRN" ¡¯"NOR"\n\n"
HIW"$NË«ÕÆÄı¾ÛÉîºñµÄº®¾¢£¬·ÜÁ¦ÍÆ³öÕÆ¾¢Ëùµ½Ö®´¦£¬Ò»´¥¼´¶³¡£Ò»µÀÇ¿Á¦Ã·»¨ĞÎ±ùÖùÕæÆøÖ±ÆË$n¶øÈ¥¡£\n\n"NOR
"                         ¡« "HIW" ÂşÌì"HIW" º®Ñ©"HIC"£®"HIM"Ã·»¨"HIW" ²»"RED"µò "HIW" ¡«\n\n
                                          ¨x¨y¨z
                                      £¯£ş£ş¨„£ş¨v
                                     ©¦     ¨‡  ¨Š
                                  ¨z £ü         ¨Š
       "HIC"£ü"NOR"                       £¯¨ƒ¨v¨v        £¯£¯£ş¨v
       "HIC"£ü"NOR"                     £¯  ¨…  ¦å        ¦å      ¨v
     "HIC"£­"HIY"¡Ñ"HIC"£­"NOR"                  £ü   ¨‡       "HIY"¡£"NOR"            £ü
       "HIC"£ü"NOR"                    £ü          "HIM"¨v£ü£¯"NOR"           ¨„
       "HIC"£ü"NOR"                     ¨v       "HIY"¡£"HIM"©¤"HIC"¡ñ"HIM"©¤"HIY"¡£"NOR"       £¯¨†
                                £ş£¾     "HIM"£¯£ü¨v"NOR"     £¼£ş  ¨‡
          ¨                  ¨x£¯         "HIY"¡£"NOR"         ¨v
        ¨Š £ü ¨z¨{¨y        £¯£ş¦ô                     £ü        "HIC"£ü"NOR"
        £¯  £ş£ş£ş£ş¨v¨z¨y¨u¨u£ş¨v        ¨u¨v        ¨u         "HIC"£ü"NOR"
      £¯¨u£ş¨¨£ş£ş¨v£ş£ş  ¨v    ¨v¨y£ß¨u    ¨v£ß£ß¨u         "HIC"£­"HIY"¡Ñ"HIC"£­"NOR"
    ¨u¨u    ¨„        £ş£ş£ş¨v¨…    ¨…            ¨             "HIC"£ü"NOR"
            ¨‡                ¨†    ¨‡             ¨…            "HIC"£ü"NOR"
                              ¨‡                   ¨‡



"HIC"$nÊÜµ½ÕâÒ»ÕÆÕÆÆøËùÉË£¬ÌåÎÂÖè½µ¡¢ÕæÆøÄıÖÍ£¬ÊÜÉË³ÁÖØ¡£\n"NOR,
        "dodge": 80,
        "parry": 50,
        "damage": 6600,
        "force": 5600,
        "damage_type": "¶³ÉË",
        "post_action": (: sp2 :),

]),

//°ÂÒå(Èı)....(10)
([ "action":
HIY"\n$NÊÕÉí»Ø²½³¤Ò÷µÀ:\n\n"NOR
   "                   "YEL"¡® "HIC"ÓÒ¿ªÌì "NOR+GRN"×ó±ÙµØ "HIB"¿ªÌì±ÙµØ"HIR"Ò»¹á³¤ºç"NOR" "YEL"¡¯"NOR"\n\n"
HIC"Ö»¼û$NÊ×ÏÈÏòÌì¼ÊÓë´óµØ¸÷»÷³öÒ»ÕÆ£¬½«ÉíÉÏÊ£ÓàµÄÕæÆøĞûĞ¹¶ø³ö£¬ÉíÓÚ¿Õµ´Ö®×´Ì¬¡£"NOR"\n"
GRN"È»ºó½ô½Ó×ÅÓÖ¼û$NË«×ãÔË¾¢£¬½ô½ôµÄÎüÔÚµØÃæÉÏ¡£Ë«ÊÖÆ½°Ú\ÄÉÌìµØÖ®ÆøÓÚÒ»Éí¡£ËæºóË«\n"
HIB"½ÅÈçÉñ¼ıÀëÏÒ£¬ÍÑ×ã³¤Ô¾¡£ÓÚ¸ß¿ÕÖ®ÖĞ´óºÈ£º                                \n\n"
NOR"                           ¡«"HIM" Ò»"HIY" ¹á"HIC" Ìì"HIG" ³¤"HIR" ºç"HIW" ¡«\n\n"NOR""
HIR"Ë«ÕÆÏàºÏÖ±Åü¶øÏÂ£¬·²»®ÆÆµÄ¿Õ¼ä·º³öÆß²Ê°ãµÄ¹â»ª£¬ÊÆÈçÂäÀ×"NOR"¡£\n",
        "dodge": 80,
        "parry": 50,
        "damage": 8500,
        "force": 8500,
        "damage_type": "´ÌÉË",
        "post_action": (: sp3 :),
]),
});

void hurt(object me, object victim, object weapon, int damage)
{
        int force;
        if( me->query("force_factor") > 10 )
        if( random(500) < me->query_skill("force")+me->query_skill("surprise-ten",1))
        {
          force = me->query_skill("sunforce");
          victim->receive_damage("kee", 7*me->query("force_factor")+2*force );
          message_vision(sprintf(""HIB"$NÊ¹³ö¾ªÌìÊ®Ê½ÖĞ°õíçµÄÆø¾¢ÕòÉã"HIB"$nµÄËÄÖÜ£¬"HIB"$n±»´ËÇ¿´óµÄÆøÊÆËùÒı¶¯£¬¿´À´ÒÑÊÜµ½ÉîÖØµÄÄÚÉË¡£\n"NOR),me,victim);
          if(damage <=0 )
          COMBAT_D->report_status(victim);
          me->add("force",-force);
        }
}
void block(object me, object victim, object weapon, int damage)
{
        int force;
        if(damage > 700)
        {
          force = (int)(me->query_skill("sunforce"));
          force = random(force/3);
          victim->apply_condition("blockade",
          random( me->query_skill("sunforce")+me->query_skill("surprise-ten") )/20 );

          message_vision(sprintf(""HIY"$nÊÜµ½¾ªÌìÊ®Ê½Ö®"HIB"¼±´µ·ç"HIY"µÄ¿ñÏ®$n"HIY"Éí²»ÓÉ¼ºµÄËæ·çËÄ°Ú\£¬¶¯µ¯²»µÃ¡£\n"NOR),me,victim);
          victim->start_busy(6);
          COMBAT_D->report_status(victim);
        }
}
void conti(object me, object victim, object weapon, int damage)
{
        int i,time = random(3);
        if( me->query("force_factor") >= 10 )//&& me->query("family/family_name") == "¶Î¼Ò")
        {
          if( me->query_temp("conti") == 0 )
          {
            me->set_temp("conti",1);
      message_vision(sprintf("\n[1;36m$NºöÈ»¶ÙÎò¾ªÌìÊ®Ê½[1;5;33mÆø³å°Ù»ã[0m¡¢[1;5;33m½£ÂäÌì³Ø[0m[1;36mµÄÒª¾÷£¬½£Æø×ÔÈ»¶øÈ»µÄËæ½£¶ø³ö£¬ÃÜÈçÂäÓê!![0m\n"),me);
              for(i=0;i<=time;i++)
              COMBAT_D->do_attack(me, victim, me->query_temp("weapon"), TYPE_QUICK);
            me->delete_temp("conti");
          }
        }
}

//ÎüĞÇ¾÷--´óÁ¿»Ø¸´ÆøÓëÄÚÁ¦
void kee(object me, object victim, object weapon, int damage)
{
        int force;
        if( me->query("force_factor") > 10 )
        {
          message_vision(sprintf(""HIY"$NÉí·º½ğÉ«¹âÃ¢£¬ÉíÉÏµÄÉËºÛ½¥½¥ÏûÊ§£¬ÄÚÏ¢³äÓ¯¡¢²»ÍÂ²»¿ì"NOR"¡£\n"),me);
          me->add("kee",2000);
          me->add("force",4000);
          me->start_busy(1);
        }
}

void sp1(object me, object victim, object weapon, int damage)
{
int i,vic_kee;
vic_kee = victim->query("kee")/500; //keeÎª±ÈÀı¼ÆËã
if(me->query("force") > 2000 && me->query("force_factor"))
{
  for(i=1;i<=9;i++)
  {
    switch(i)
    {
     case 1:
message_vision(sprintf("$N»áÒâÁË"HIW"¡®Ìì»ÊÌìÊ½¡¯ÖĞ"HIR"¡®ĞñÈÕ¶«Éı£¬¸²Ìì¼«Ñô¡¯"NOR"µÄÕæÒâ£¬Ïò$nµ±Í·Õ¶ÏÂ!\n"),me,victim);
     break;
     case 2:
message_vision(sprintf("\n$N»áÒâÁË"HIW"¡®Ìì»ÊÌìÊ½¡¯ÖĞ"HIG"¡®Ë«ÈÕìÏÁÖ£¬ÕğÌì¼«Ñô¡¯"NOR"µÄÕæÒâ£¬¶Ô$nËÄÖ«¿³Âä!\n"),me,victim);
     break;
     case 3:
message_vision(sprintf("\n$N»áÒâÁË"HIW"¡®Ìì»ÊÌìÊ½¡¯ÖĞ"HIC"¡®ÈıÈÕÆÆĞÇ£¬ÆÆÌì¼«Ñô¡¯"NOR"µÄÕæÒâ£¬Íù$nĞØÇ°¼²´Ì!\n"),me,victim);
     break;
     case 4:
message_vision(sprintf("\n$N»áÒâÁË"HIW"¡®Ìì»ÊÌìÊ½¡¯ÖĞ"HIM"¡®ËÄÑô×ªÃü£¬¸²ÌìÔªÑô¡¯"NOR"µÄÕæÒâ£¬ğÍÈ»ÃüĞĞËÄ×ª¿³Ïò$n!\n"),me,victim);
     break;
     case 5:
message_vision(sprintf("\n$N»áÒâÁË"HIW"¡®Ìì»ÊÌìÊ½¡¯ÖĞ"HIY"¡®Ç¬À¤ÎåÑô£¬ÕğÌìÔªÑô¡¯"NOR"µÄÕæÒâ£¬Ç¬À¤µ¶Ó°°üÎ§×¡$n!\n"),me,victim);
     break;
     case 6:
message_vision(sprintf("\n$N»áÒâÁË"HIW"¡®Ìì»ÊÌìÊ½¡¯ÖĞ"NOR""WHT"¡®ÑôÁùºÏÃ÷£¬ÆÆÌìÔªÑô¡¯"NOR"µÄÕæÒâ£¬ÁùµÀµ¶¾¢¼²ÉäÏò$n!\n"),me,victim);
     break;
     case 7:
message_vision(sprintf("\n$N»áÒâÁË"HIW"¡®Ìì»ÊÌìÊ½¡¯ÖĞ"NOR""BLU"¡®Æßâ¹°ÈÕ£¬¸²ÌìÕæÑô¡¯"NOR"µÄÕæÒâ£¬ºáµ¶¿ñÎèÔË»¯Æß½ı¹¥Ïò$n!\n"),me,victim);
     break;
     case 8:
message_vision(sprintf("\n$N»áÒâÁË"HIW"¡®Ìì»ÊÌìÊ½¡¯ÖĞ"NOR""CYN"¡®Ñô¸ñ°ËÃù£¬ÕğÌìÕæÑô¡¯"NOR"µÄÕæÒâ£¬µ¶Ó°³¯°Ë·½µãÂä°üÎ§×¡$n!\n"),me,victim);
     break;
     case 9:
message_vision(sprintf("\n$N»áÒâÁË"HIW"¡®Ìì»ÊÌìÊ½¡¯ÖĞ"NOR""MAG"¡®¾Å¾ÅĞşÑô£¬ÆÆÌìÕæÑô¡¯"NOR"µÄÕæÒâ£¬µ¶Æø¼²×ß¾Å¹¬¼¯ÖĞÉäÏò$n!\n"),me,victim);
     break;
     }
if(me->query_skill("sunforce")+me->query_skill("surprise-ten") > random(180))
     {
message_vision(sprintf(HIR"$NÈ·ÊµÃüÖĞ$nÒªº¦£¬$n¶ÙÊ±ÑªÁ÷ÂúµØ¡£\n"NOR),me,victim);
          victim->receive_wound("kee",vic_kee);
          victim->apply_condition("burn",random(45)+((int)me->query_skill("sunforce", 1)/10));//×ÆÉË
          COMBAT_D->report_status(victim);
          me->add("force",-1000);
      }
       else
      {
message_vision(sprintf("½á¹û$nÑ¸ËÙµØ±Ü¿ªÕâÕĞ¡£\n"),me,victim);
      }
   }
  }
}
void sp2(object me, object victim, object weapon, int damage)
{
        int ten, force;
        ten = me->query_skill("surprise-ten");
        force = me->query_skill("sunforce");
        if( random( force ) > random( ten ) )
        {
          message_vision(sprintf(""HIC"$NÇá°Ú\ÒÂĞä£¬ÕæÆø»ìÔª¹éÒ»£¬ÆÅæ¶äìÈ÷µÄÉí·¨¡¢±ùÀäµÄÈ­¾¢Óë$n"HIC"½»´í¶ø¹ı!!!\n"NOR),me,victim);
          victim->receive_damage("kee",ten*9/2);
          victim->apply_condition("cold",random(45)+((int)me->query_skill("sunforce", 1)/10));//¶³ÉË
          COMBAT_D->report_status(victim);
        }
}

void sp3(object me, object victim, object weapon, int damage)
{
        int force;
        force = me->query_skill("sunforce");
        if( me->query("force_factor") >= 10 && victim->query_condition("blockade"))
        {
          message_vision(sprintf(""HIC"$nµÖµ²²»µĞ£¬±»$NÁ¬¾¢ÅüÖĞ£¬ÉíĞÎ¾ŞÕğ¡£$nÄÚÁ¦Í»È»ÆÆÌåĞûĞ¹¶ø³ö£¬¿à²»¿°ÑÔ!!\n"NOR),me,victim);
          victim->receive_damage("kee",force*6/5);
          victim->apply_condition("hart",random(45)+((int)me->query_skill("sunforce",1)/10));//ÄÚÉË
          victim->start_busy(random(3));
          COMBAT_D->report_status(victim);
        }
}


mapping query_action(object me, object weapon)
{
        int level=(int)(me->query_skill("surprise-ten",1));

        if ( level < 10 )
           return action [random(3)];
        else if ( level < 30 )
           return action [random(6)];
        else if ( level < 60 )
           return action [random(7)];
        else if ( level < 80 )
           return action [random(8)];
        else if ( level < 90 )
           return action [random(9)];
        else if ( level < 95 )
           return action [random(9)+1];
        else if ( level < 100 && me->query_temp("super",1))
           return action [random(9)+2];
        else if ( level >= 100 && me->query("marks/six_sp") ==3)
           return action [random(9)+3];
        else
           return action [random(9)];
}

int valid_learn(object me)
{
        if( me->query_temp("weapon") || me->query_temp("secondary_weapon") )
          return notify_fail("Á·¾ªÌìÊ®Ê½ÊÇÒª¿ÕÊÖ°É....\n");
        if(me->query_skill("force")*3<=me->query_skill("surprise-ten",1))
          return notify_fail("ÄãµÄ»ù±¾ÄÚÁ¦¼¼ÄÜ²»×ã, ÎŞ·¨Á·¾ªÌìÊ®Ê½¡£\n");
        if(me->query_skill("literate")*3<=me->query_skill("surprise-ten",1))
          return notify_fail("ÄãµÄÖªÊ¶²»×ã£¬ÎŞ·¨Ìå»á¾ªÌìÊ®Ê½ÕæÇĞµÄÒªÀí£¬È«Éí¾­ÂöÕæÆøÔËĞĞÖ®µÀµÄ¾«Ãî±ä»¯¡£\n");
        return 1;
}

int valid_enable(string usage)
{
      if(this_player()->query_skill("surprise-ten",1) >= 70)
         {
            return (usage=="unarmed")||(usage=="parry");
         }
          return (usage=="unarmed");
}

int practice_skill(object me)
{
        if( me->query_temp("weapon") || me->query_temp("secondary_weapon") )
          return notify_fail("Á·¾ªÌìÊ®Ê½ÊÇÒª¿ÕÊÖ°É....\n");
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
        return "/daemon/class/scholar/"+action;
}

