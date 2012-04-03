//ç­Ñ©Éñ½£ by bss
#include <ansi.h>
#include <combat.h>

void berserk2(object me, object victim, object  weapon, int damage);
void sp1(object me, object victim, object  weapon, int damage);
void sp2(object me, object victim, object  weapon, int damage);
void sp3(object me, object victim, object  weapon, int damage);
//void sp4(object me, object victim, object  weapon, int damage);
string *parry_msg=({
        "$nÊÖÖĞ$wºöÈ»ÍÑÊÖÒ»¶¶£¬ÕıÊÇÒ»ÕĞ"+HIY+"¡¸½£Á÷ĞÇ¡±"+NOR+"£¬Çê¿Ì¼ä½£ÈçÁ÷ĞÇÔË×ª£¬ÇÉ¾øÎŞ·½£¬½«$NµÄ¹¥ÊÆ¾¡Êıµ²ÁËÏÂÀ´¡£\n",
        "$nÉíÇûÒ»Òı, ÊÖÖĞ$w½«$NµÄ¹¥ÊÆ¾¡ÊıÒ·ÁË¿ªÈ¥¡£\n",
        "$n°ÑÊÖÖĞµÄ$wÎè³ÉÔ²»·, ½«$NµÄ¹¥ÊÆ¾¡Êıµ²ÁËÏÂÀ´¡£\n",
        "$nÒÔ¾²ÖÆ¶¯, Æ½¾ÙÊÖÖĞ$w, ÎŞÕĞÊ¤ÓĞÕĞ, »¯½âÁË$NµÄ¹¥ÊÆ!\n",
        });

mapping *action = ({
        ([
                "action"     :
"$NÊ©Õ¹³öä½»¨½£ÅÉ¾øÕĞ"HIY"¡¸µ¹·É½£¡±"NOR"£¬Í»È»¼ä×ª¹ıÉíÀ´£¬ÉíĞÎÌÚÆğ£¬à§µÄÒ»½££¬
Íù$nĞØÇ°Ö±´Ì£¬ËÙ¶È·É¿ì£¬ÑÛ¿´$n¾ÍÒªÖĞÕĞÁË¡£",
                "dodge"      :                -500,
                "damage"     :                750,
                "damage_type":               "´ÌÉË",
                "post_action":  (:call_other,__FILE__,"damage_weapon":),
        ]),
        ([
                "action"     :
"$N½£×÷µ¶Ê¹£¬ºöµØÒ»ÕĞ"+HIY+"¡¸ÁúĞ¥¾ÅÌì¡±"+NOR+", ÊÖÖĞ$wÓÉÏÂ¶øÉÏµÄ¿³Ïò$n£¬Òò¿³Ï÷¿ÕÆøËùĞÎ³ÉµÃÂİäöÆøÁ÷Èç¿ñ·ç°ã¹¥Ïò$n¡£",
                "dodge"      :                -500,
                "damage"     :                145,
                "damage_type":               "¿³ÉË",
                "post_action":  (:call_other,__FILE__,"damage_weapon":),
                "post_action":  (:sp1:),
        ]),
        ([
                "action"     :
"$NºöÈ»½«ÊÖÖĞ$w²ØÓÚ±³ºó£¬ÕıÊÇÒ»ÕĞ"+HIB+"¡¸ÎŞ½£ÊÆ¡±"+NOR+",Õıµ±$n¸ã²»Çå³ş×´¿öµÄÊ±ºó£¬$w\nºöÈ»ÓÉ$NµÄÑüÅÔ´Ì³ö£¬´ÌÏò$n¡£",
                "dodge"      :               -500,
                "damage"     :                165,
                "damage_type":               "´ÌÉË",
                "post_action":  (:call_other,__FILE__,"damage_weapon":),
        ]),
        ([
                "action"     :

"$N½«$wÅ×Ïò¿ÕÖĞ£¬$n¼û»ú²»¿ÉÊ§£¬Ñ¸ËÙµÄÏò$N½ø¹¥,$NºöÈ»ÑÛ·Å¾«¹â£¬¸ú×ÅÔ¾ÖÁ¿ÕÖĞ½Ó\n½££¬Ë³ÊÆÏÂÅü£¬ÕıÊÇÒ»ÕĞ"+HIC+"¡¸Å­Õ¶ÉñÖİ¡±"+NOR+" £¬Ç§ÍòµÀ½£ÆøËæ×Å½£ÊÆ¹¥Ïò$n¡£",
                "dodge"      :                -500,
                "damage"     :                200,
                "post_action":  (:call_other,__FILE__,"damage_weapon":),
                "post_action":                (: sp2 :),
                "damage_type":                "¿³ÉË",
         ]),
         ([
                "action"     :
"$NºöÈ»ÏòÇ°´ó¿çÒ»²½£¬Ò»¹ÉÅÓ´óµÄÉ±Æø´Ó$NÉíÉÏÓ¿³ö£¬$N´óºÈÒ»Éù"+HIR+"¡¸É±ÁúÇóµÀ¡±"+NOR+"£¬»ôµØĞıÉí¶øÆğ£¬½£ËæÉí×ª£¬Ğı·ç°ã³¯$nÃÍ¹¥¡£",
                "dodge"      :                -500,
                "damage"     :                220,
                "post_action":  (:call_other,__FILE__,"damage_weapon":),
                "damage_type":                "¸îÉË",
         ]),
         ([
                "action"     :
"$N½«$wĞ±²åÓÚµØ£¬ÉíĞÎ¼±×ª£¬´óºÈÒ»Éù"+HIY+"¡¸Ç±ÁúÉıÌì¡±"+NOR+"£¬ÊÖÖĞ$w´øÆğÁËÒ»ÕóÉÏÉıÆøÁ÷£¬·Â·ğÒª½«ËÄÖÜµÄÒ»ÇĞÈ«²¿¾íµ½¿ÕÖĞËÆµÄ",
                "dodge"      :                -500,
                "damage"     :                350,
                "post_action":  (:call_other,__FILE__,"damage_weapon":),
                "post_action":  (:sp3:),
                "damage_type":                "¸îÉË",
         ]),
         ([
                "action"     :
"$NÊÖÖĞ$w¼±¶¶£¬$wµÄ½£ÆøÓĞÈç±Ş×ÓÒ»°ã¾íÏò$n£¬½£ÆøËù´øÆğµÄÆøÁ÷ÀÎÀÎËø¶¨×Å$n£¬ÕıÊÇÄÜÊ¹½£ÓĞÈçÊ¹±ŞµÄ¾ø¼¼\n"+
"            "+HIY+"   ¡«¡«¡«¡¡½£     Á÷     ÔÆ  ¡«¡«¡« "+NOR+"¡¡¡¡",
                "dodge"      :                -500,
                "damage"     :                550,
                "post_action":  (:call_other,__FILE__,"damage_weapon":),
                "post_action":  (:sp2:),
                "damage_type":                "¸îÉË",

         ]),
        ([
                "action"     :
"Ö»Ìı$NÈç³ÁÀ×±©ºÈÒ»Éù£¬ÈËÒÑ¼ı²½¶øÉÏ£¬Çê¿Ì¼ä½£Æø±©·Å³ÉÍòµÀ½£¹â£¬»ëÈ»ÔÚ°ë¿ÕÖĞ´Ì³öÒ»¸ö¶·´óµÄ"+HIY+"¡¸½£¡±"+NOR+"×Ö£¬ÆÌÌì¸Ç\µØµÄÏò$nÑ¹È¥£¬ÕıÊÇÄÜÔÚĞé¿ÕÁôºÛµÄ---- \n"+
"            "+HIC+"   ¡«¡«¡«¡¡½£     Á÷     ºÛ  ¡«¡«¡« "+NOR+"¡¡¡¡",
                "dodge"      :                -500,
                "damage"     :                800,
                "post_action":  (:call_other,__FILE__,"damage_weapon":),
                "post_action":  (:sp2:),
                "damage_type":               "´ÌÉË",
        ]),
        ([
                "action"     :
"$N×óÊÖ³Ö½££¬ÓÒÊÖÄó¸ö½£¾÷£¬Ë«ÊÖ³É»·£¬»º»ºÌ§Æğ£¬ÕâÊÇ[1;37mĞşÁú½£·¨¾øÊ½[0mµÄÆğÊÖÊ½¡£",
                "dodge"      :                -500,
                "damage"     :                700,
                "damage_type":               "´ÌÉË",
                "post_action":  (:call_other,__FILE__,"damage_weapon":),
                "post_action":  (:berserk2:),
        ]),
        ([
                "action"     :
"$N¸ß¾ÙÊÖÖĞµÄ$w£¬Ñ¸ËÙµØÔÚÉíÇ°Ğé¿ÕÅüÁËÒ»¸öºÜ´óµÄ"+HIC+"°Ë"+NOR+"×Ö£¬ÕıÊÇÊ¥Áé½£·¨Ö®"+HIR+"¡¸½£°Ë¡±"+NOR+"£¬½£Æø²úÉúÁËºÜ´óµÄÆÆ¿ÕÉù£¬Ö±Ïò$n¶øÈ¥¡£",
                "dodge"      :                -500,
                "damage"     :                800,
                "damage_type":               "¿³ÉË",
                "post_action":  (:call_other,__FILE__,"damage_weapon":),
                "post_action":  (:sp1:),
        ]),
        ([
                "action"     :
"$NÊ©³ö¡¸ÎŞÃû½£·¨¡±ÖĞµÄ¼«ÖÂ"+HIR+"¡¸±¯Í´ÄªÃû¡±"+NOR+"£¬½£Íø½»Ö¯µÄÏò$n¹¥È¥£¬Ê¹µÃ$n²»½ûÎªÁË$N½£Ê½ÖĞÄÇ±¯ÉËµÄ½£ÒâËù¸Ğ¶¯¡£",
                "dodge"      :                -500,
                "damage"     :                700,
                "damage_type":               "´ÌÉË",
               "post_action":  (:call_other,__FILE__,"damage_weapon":),
                "post_action":  (:sp2:),
        ]),

});

mapping query_action(object me, object weapon)
{
   int skill_level, limit;
   skill_level = (int)(me->query_skill("bss-sword", 1));
   limit= (int)( skill_level/ 10);
      if (limit < 2 )
         return action[random(4 )];
      else if (limit < 3 )
         return action[random(5 )];
      else if (limit < 4 )
         return action[random(6 )];
      else if (limit < 5 )
         return action[random(7 )];
      else if (limit < 6 )
         return action[random(8 )];
      else if (limit < 7 )
         return action[random(9 )];
      else if (limit < 8 )
         return action[random(10 )];
         return action[random(11)];
}


void sp1(object me, object victim, object  weapon, int damage)
{
   int skill= me->query_skill("bss-sword", 1);
   message_vision("$NÊÜµ½ÂİĞı½£ÆøµÄÓ°Ïì£¬Á³ÉÏºöÇàºö°×£¬¿´À´ÊÇÊÜµ½ÁËÄÚÉËÁË\n",victim);
   victim->add("kee", -(skill* 3));
   victim->apply_condition("hart",random(5)+((int)me->query_skill("dragonsword",1)/5));
   COMBAT_D->report_status(victim, 1);
   victim->start_busy(1);
}
void sp2(object me, object victim, object  weapon, int damage)
{
   int skill = me->query_skill("bss-sword", 1);
   message_vision("$NµÄ½£ÆøÔÚ$nÌåÄÚËÄ´¦ÂÒ×²£¬Ôì³ÉÑÏÖØµÄÄÚÉË\n",weapon,victim);
   victim->add("kee",-(skill* 3));
   victim->apply_condition("hart",random(5)+((int)me->query_skill("dragonsword",1)/5));
   COMBAT_D->report_status(victim, 1);
   victim->start_busy(1);
}
void sp3(object me, object victim, object  weapon, int damage)
{
   int skill = me->query_skill("bss-sword", 1);
   message_vision("$N±»$nËù´øÆğµÄÉÏÉıÆøÁ÷£¬¾íÖÁ¿ÕÖĞ²¢±»ËºÁÑ¿ªÀ´\n",victim,weapon);
   victim->add("kee",-(skill* 3));
   COMBAT_D->report_status(victim, 1);
   victim->start_busy(1);
}


void berserk2(object me, object victim, object  weapon, int damage)
{
 int skill_level=me->query_skill("bss-sword",1),bound;
 bound = victim->query("max_kee");
 bound = (bound/100)*5;
  if( random(170) > 27 && me->query("force",1) > 100 )
  {
    if(!me->query_temp("berserk2"))
    {
    if(weapon->query("id")=="dragon sword")
     {
       message_vision(
         sprintf(HIW"\n$NºöÈ»ÑÛ·Å¾«¹â£¬´óºÈÒ»Éù¡¸·çÔÆÁ¬Ğø½£¡±£¬É²ÄÇ¼äËÄÖÜÓ¿ÆğÒ»µÀºÚÔÆ£¬Ê¹$nÍêÈ«Ê§È¥$NµÄ×ÙÓ°!!\n\n"NOR),me ,victim);
       message_vision(
         sprintf(HIW"\n$NÒÔ´«ÒôÖ®Êõ¶Ô$nËµµ½:¡¸½ÓÕĞ°É¡±£¬ÕĞÊ½Èç¿ñ·ç°ã³¯$nÏ®ÖÁ!!\n\n"NOR),me ,victim);
       message_vision(
 sprintf(HIW"\n·çÔÆÁ¬Ğø½£µÚÒ»Ê½"HIB"¡®ĞĞÔÆÁ÷Ë®¡¯"HIW"£¬"HIY"ÉñÁú½£"HIW"ÓĞÈçÁ÷Ë®°ã³¯$n¹¥È¥£¬Ê¹ÈËÄ¿²»Ï¾¼º\n"NOR),me ,victim,weapon);
         victim->receive_wound("kee",bound,me);
         COMBAT_D->report_status(victim, 1);
       message_vision(
 sprintf(HIW"\n·çÔÆÁ¬Ğø½£µÚ¶şÊ½"HIB"¡®ÅûĞÇ´÷ÔÂ¡¯"HIW"£¬"HIY"ÉñÁú½£"HIW"ºöÈ»³¯$nÖ±´Ì¹ıÈ¥£¬´ÌÖĞÁË$nÉíÉÏ¼¸´óÒªÑ¨\n"NOR), me ,victim,weapon);
         victim->receive_wound("kee",bound,me);
         COMBAT_D->report_status(victim, 1);
       message_vision(
 sprintf(HIW"\n·çÔÆÁ¬Ğø½£µÚÈıÊ½"HIB"¡®·­ÔÆ¸²Óê¡¯"HIW"£¬"HIY"ÉñÁú½£"HIW"Èç·ç³µ°ãÔÚ$NÉíÅÔ×ªÁËÆğÀ´£¬$n±»½£ÕĞËù²úÉúµÄ\n\nÂİäöÆøÁ÷ËùÇÖ£¬ÊÜÁËÖØÉË\n"NOR), me ,victim,weapon);
         victim->receive_wound("kee",bound,me);
         COMBAT_D->report_status(victim, 1);
       message_vision(
 sprintf(HIW"\n·çÔÆÁ¬Ğø½£µÚËÄÊ½"HIB"¡®ÅÅÉ½µ¹º£¡¯"HIW"£¬$N½«"HIY"ÉñÁú½£"HIW"²åÈëÍÁµØ£¬¸ú×ÅÓÃÁ¦°ÎÆğ£¬Ëæ"HIY"ÉñÁú½£"HIW"¶ø·ÉÆğµÄÍÁÊ¯\n\n»÷ÖĞÁË$n\n"NOR), me ,victim,weapon);
         victim->receive_wound("kee",bound,me);
         COMBAT_D->report_status(victim, 1);
       message_vision(
 sprintf(HIW"\n·çÔÆÁ¬Ğø½£µÚÎåÊ½"HIB"¡®ÖØÔÆÉîËø¡¯"HIW"£¬$NÓÃÊÖÖĞ"HIY"ÉñÁú½£"HIW"ÔÚ$nÉíÉÏ»­ÁËÊ®¼¸¸öĞ¡Ô²È¦£¬$n\n\nºöÈ»ÉíÌåÒ»Õğ£¬¶¯µ¯²»µÃ\n\n"NOR), me ,victim,weapon);
         victim->receive_wound("kee",bound,me);
         COMBAT_D->report_status(victim, 1);
      message_vision(
 sprintf(HIW"\n·çÔÆÁ¬Ğø½£µÚÁùÊ½"HIB"¡®·ç¾í²ĞÂ¥¡¯"HIW"£¬$N°ÎÉí¶øÆğ£¬½£ËæÉí×ª£¬ÈçÒ»µÀÁú¾í·ç°ã³¯$n¹¥È¥\n"NOR), me ,victim,weapon);
         victim->receive_wound("kee",bound,me);
         COMBAT_D->report_status(victim, 1);
       message_vision(
 sprintf(HIW"\n·çÔÆÁ¬Ğø½£µÚÆßÊ½"HIB"¡®¿ñ·ç±©Óê¡¯"HIW"£¬½£ÕĞÁ¬Ãà²»¾øµÄ³¯$n¹¥È¥£¬Ê¹$nÉíÊÜÖØ´´\n"NOR), me ,victim,weapon);
         victim->receive_wound("kee",bound,me);
         COMBAT_D->report_status(victim, 1);
       message_vision(
 sprintf(HIW"\n·çÔÆÁ¬Ğø½£µÚ°ËÊ½"HIB"¡®Éñ·çÅ­º¿¡¯"HIW"£¬"HIY"ÉñÁú½£"HIW"ÔÚ¿Õ¼äÖĞ¿ìËÙµÄ¿³Åü£¬Ê¹ËÄÖÜ²úÉúÁË¾Ş´óµÄÆÆ¿ÕÉù\n"NOR), me ,victim,weapon);
         victim->receive_wound("kee",bound,me);
         COMBAT_D->report_status(victim, 1);
       message_vision(
 sprintf(HIW"\n·çÔÆÁ¬Ğø½£µÚ¾ÅÊ½"HIB"¡®ËºÌìÅÅÔÆ¡¯"HIW"£¬"HIY"ÉñÁú½£"HIW"Ñ¸ËÙµÄÏò×óÓÒ¸÷ÅüÁËÁ½ÏÂ£¬½£Æø¿ìËÙµØ¹¥Ïò$n\n"NOR), me ,victim,weapon);
 victim->receive_wound("kee",bound,me);
         COMBAT_D->report_status(victim, 1);
       message_vision(
 sprintf(HIW"\n·çÔÆÁ¬Ğø½£µÚÊ®Ê½"HIB"¡®ÔÆº£²¨ÌÎ¡¯"HIW"£¬½£ÆøÈç¾ŞÀË¿ñÓ¿¶øÖÁ£¬$nÁ¬ÉÁ±ÜµÄ»ú»áÒ²Ã»ÓĞ\n"NOR), me ,victim,weapon);
         victim->receive_wound("kee",bound,me);
         COMBAT_D->report_status(victim, 1);
       message_vision(
 sprintf(HIW"\n·çÔÆÁ¬Ğø½£µÚÊ®Ò»Ê½"HIB"¡®ÑêÔÆÌìç­¡¯"HIW"£¬$NÔ¾ÖÁ¿ÕÖĞ£¬ÊÖÖĞ"HIY"ÉñÁú½£"HIW"³¯$nÖ±Åü¶øÈ¥£¬½£Æø³ä³â×ÅÕâÕû¸ö¿Õ¼ä\n"NOR), me ,victim,weapon);
         victim->receive_wound("kee",bound,me);
         COMBAT_D->report_status(victim, 1);
     message_vision(
 sprintf(HIW"\n$NÊ¹Íê½£·¨Ò»Ê®Ò»Ê½ºó£¬ÖÜÎ§µÄºÚÔÆ½¥½¥µØÏûÉ¢ÁË¡£\n\n"NOR), me ,victim);

}
}
}
}
int valid_learn(object me)
{
   object ob;
//   if( !(ob = me->query_temp("weapon")) || (string)ob->query("skill_type") !="sword")
//      return   notify_fail("ÉÙÁË°Ñ½£Á·ÆğÀ´¹Ö²»Ë³ÊÖµÄ, »¹ÊÇÄÃ°Ñ½£ÔÙÀ´Á·°É¡£\n");
   return   1;
}

int valid_enable(string usage)
{
   return ( usage=="sword") || ( usage=="parry" );
}

int practice_skill(object me)
{
  if( (int)me->query("kee") < 25 )
     return notify_fail("ÄãµÄÌåÁ¦²»¹»ÁË£¬ĞİÏ¢Ò»ÏÂÔÙÁ·°É¡£\n");
  if( (int)me->query("gin") < 5 )
     return notify_fail("ÄãµÄ¾«Á¦²»¹»ÁË£¬ĞİÏ¢Ò»ÏÂÔÙÁ·°É¡£\n");
  if( (int)me->query("force") < 1 )
     return notify_fail("ÄãµÄÄÚÁ¦²»¹»ÁË£¬ĞİÏ¢Ò»ÏÂÔÙÁ·°É¡£\n");
  me->receive_damage("kee", 25);
  me->receive_damage("gin", 5);
  me->add("force", -1);
  return 1;
}

string perform_action_file(string action)
{
   return CLASS_D("swordsman")+"/dragonsword/"+action;
}

string query_parry_msg(string limb)
{
   return parry_msg[ random( sizeof( parry_msg))];
}

void skill_improved(object me)
{
tell_object(me,"[1;34mÓÉÓÚÄãÇ±ĞÄÑ§Ï°£¬ÄãµÄĞşÁú½£·¨¸ü¼Ó´¿ÊìÁË£¡£¡[0m\n");
}




