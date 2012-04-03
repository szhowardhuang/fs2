// lonely-sword.c  ¶À¹Â¾Å½£
/*
#include <ansi.h>
*/
#include <combat.h>
inherit SKILL;
inherit SSERVER;

void berserk(object me, object victim, object  weapon, int damage);
void sp1(object me, object victim, object  weapon, int damage);
void sp2(object me, object victim, object  weapon, int damage);
void sp3(object me, object victim, object  weapon, int damage);
void sp4(object me, object victim, object  weapon, int damage);
string *parry_msg=({
        "$nÉíÇûÒ»Òı, ½«$NµÄ¹¥ÊÆ¾¡ÊıÒ·ÁË¿ªÈ¥¡£\n",
        "$n°ÑÊÖÖĞÎäÆ÷Îè³ÉÔ²»·, ½«$NµÄ¹¥ÊÆ¾¡Êıµ²ÁËÏÂÀ´¡£\n",
        "$nÒÔ¾²ÖÆ¶¯, Æ½¾ÙÊÖÖĞµÄ½£, ÎŞÕĞÊ¤ÓĞÕĞ, »¯½âÁË$NµÄ¹¥ÊÆ!\n",
        });
 string *array_msg=
    ({
      "[1;33m$N´óºÈÒ»Éù, ½ÅÌ¤ÆßĞÇ, ´øÁì×ÅÖÚ½£Ê¿,Õ¹¿ª¶À¹ÂÆÆĞ°½£Õó¡£\n[0m",
      "[1;33mÖÚÈË½Å²È°ËØÔ, ½£»¯Á½ÒÇ, ÍÅÍÅ½«µĞÈËÎ§×¡, ÁîµĞÈËÍûÖ®µ¨ÇÓ¡£\n[0m",
      "[1;33m$N¼±ÎüÒ»¿ÚÆø, ´øÁìÖÚÈË¼ÓËÙÔË×ª¶À¹ÂÕòĞ°½£Õó,´òµÄµĞÈËÊÖ×ãÎŞ´ë¡£\n[0m",
     }); 
mapping *action = ({
        ([
                "action"     :               "$N×óÊÖÄó¸ö½£¾÷, Æ½ÍÆ¶ø³ö,¾÷Ö¸ÉÏÑö, ÓÒÊÖ½£³¯Ìì²»¶¯, ÕıÊÇÒ»ÕĞ[1;37m¡®[1;34mÕğ½£ÊÆ[1;37m¡¯[0m",
                "dodge"      :                -20,
                "damage"     :                200,
                "post_action":                (: berserk :),
                "damage_type":                "¸îÉË",
         ]),
         ([
                "action"     :                "$NÃæÂ¶Î¢Ğ¦, ÑöÊÓ²ÔÌì,Ê¹³ö½£ÕĞÖ®¼«ÖÂ[1;37m¡®ÉÁ[1;31m½£[1;37mÊÆ¡¯[0m, µ«¼û½£¹âÉÁÉÁ",
                "dodge"      :                -10,
                "damage"     :                220,
                "post_action":                (: berserk :),
                "damage_type":                "¸îÉË",
         ]),
         ([
                "action"     :                "$NÉíĞÎÆ®ºö´óºÈÒ»Éù,$NÊ¹³ö¶À¹Â¾Å½£Ö®±ØÉ±¾øÕĞ\n"+"[1;32m¡«¡«[1;36mÆÆ£®Âä£®¶ş½£ºÏÒ»ÊÆ¡«¡«[0m\n"+
                                              "$NÔËÆğÄÚ¹¦ĞÄ·¨, Æø³Áµ¤Ìï,ÒÔÆøÓù½£, Ö»¼ûÊÖÖĞ$w»¯×÷Ò»µÀÒø¹â, ³¯$n¼±·É¶øÈ¥, µ«¼ûÒø¹âÒ»ÉÁ,",
                "dodge"      :                10,
                "damage"     :                350,
                "post_action":                (: sp3 :),
                "damage_type":                "´ÌÉË",
         ]),

         ([
                "action"     :                "$NÉíĞÎÆ®ºö´óºÈÒ»Éù,Ê¹³ö¶À¹Â½£Ê½Ö®±ØÉ±¾øÕĞ\n"+"[1;32m¡«¡«µ´£®ÁÃ£®¶ş½£ºÏÒ»ÊÆ¡«¡«[1;35m[0m\n"+
                                              "Ö»¼û$NÊÖÖĞ$w¼±»­Ò»¸öÔ², Ô½»­Ô½¿ì, $nÖ»¾õÖÜÉí´óÑ¨¾¡½ÔÁıÕÖÔÚ½£Ã¢Ö®ÏÂ, ¾ªº§Ö®Óà, Ò»¹É´óÁ¦Í»È»Ó¿À´,",
                "dodge"      :                10,
                "damage"     :                550,
                "post_action":                (: sp1 :),
                "damage_type":                "¿³ÉË",                                    
         ]),

        ([
                "action"     :               "$N×óÊÖ³Ö½£, ÓÒÊÖÄó¸ö½£¾÷,Ë«ÊÖ³É»·, »º»ºÌ§Æğ, ÕâÊÇ[1;37m¶À¹Â½£Ê½¾øÊ½[0mµÄÆğÊÖÊ½",
                "dodge"      :                -10,
                "damage"     :                700,
                "post_action":                (: sp2 :),
                "damage_type":               "´ÌÉË",
        ]),

        ([
                "action"     :
"$NÊ©Õ¹³ö[1;37m¶À¹Â¾Å½£[0mÖ®¾«Ãî¾øÕĞ\n½£ÕĞºö±ä, Æ®ÒİÎŞÂ×,ÍáÍáĞ±Ğ±µÄÊ¹³öÒ»ÕĞ[1;37m¡®Âä[1;36m½£[1;31mÊÆ[1;37m¡¯[0m",
                "dodge"      :                -10,
                "damage"     :                800,
                "damage_type":               "´ÌÉË",
        ]),
        ([
                "action"     :
"$NÊ©Õ¹³ö[1;37m¶À¹Â¾Å½£[0mÖ®¾«Ãî¾øÕĞ\n½£Ã¢ÍÌÍÂ, µçÉÁĞÇ·É,Ò»ÕĞ[1;37m¡®[1;35mĞı½£ÊÆ[1;37m¡¯[0m, ÍÆËÍ¶øÉÏ",
                "dodge"      :                -10,
                "damage"     :                700,
                "damage_type":               "´ÌÉË",
        ]),
        ([
                "action"     :
"$NÊ©Õ¹³ö[1;37m¶À¹Â¾Å½£[0mÖ®¾«Ãî¾øÕĞ\n$N$wÔ½Ê¹Ô½¿ì, Í»È»¼ä×ª¹ıÉíÀ´,Ò»ÉùºôºÈ,à§µÄÒ»½£, ÔÚ$nĞØÇ°¶Ô´©¶ø¹ı,ÕâÒ»ÕĞ[1;37m¡®[1;34mÀë[1;37m½£[1;34mÊÆ[1;37m¡¯[0m,ÕıÊÇ¾ø¸ßµÄ¾ø¼¼",
                "dodge"      :                -10,
                "damage"     :                750,
                "post_action":                (: sp4 :),
                "damage_type":               "´ÌÉË",
        ]),

});

mapping query_action(object me, object weapon)
{
   int skill_level, limit;
   skill_level = (int)(me->query_skill("lonely-sword", 1));
   limit= (int)( skill_level/ 10);
   if( me->query_temp("use_form", 1))
      message_vision( array_msg[ random( sizeof( array_msg))], me); 
   if( me->query("quest/lonely-sword"))
   {
      if (limit < 1 )
         return action[random(6 )];
      else if (limit < 2 )
         return action[random(7 )];
      else if (limit < 3 )
         return action[random(8 )];
      else if (limit < 4 )
         return action[random(9 )];
      else if (limit < 5 )
         return action[random(9 )+1];
      else if (limit < 6 )
         return action[random(9 )+2];
      else if (limit < 7 )
         return action[random(9 )+3];
      else if (limit < 8 )
         return action[random(9 )+4];
      else if (limit < 9 )
         return action[random(9 )+5];
         return action[random(9 )+6];
   }
   else
   {
      if (limit < 1 )
         return action[random(1)];
      else if (limit < 2 )
         return action[random(2)];
      else if (limit < 3 )
         return action[random(3)];
      else if (limit < 4 )
         return action[random(4)];
      else if (limit < 5 )
         return action[random(4)+1];
      else if (limit < 6 )
         return action[random(4)+2];
      else if (limit < 7 )
         return action[random(4)+3];
      else if (limit < 8 )
         return action[random(4)+4];
      else if (limit < 9 )
         return action[random(4)+5];
         return action[random(4)+6];
   }
}

void sp1(object me, object victim, object  weapon, int damage)
{
   int skill= me->query_skill("lonely-sword", 1);
   message_vision("[1;37m$N[1;37m³¤Ğ¥µÀ:¡®½£ĞıÀëÉí£¬½£Ğ¥ÕğÉ½ºÓ¡¯, Ë²¼ä½£Ã¢´ó×÷,³¯$n[1;37m¼¤Éä¶øÖÁ[0m\n",me,victim);
   victim->add("kee", -(skill* 2));
   COMBAT_D->report_status(victim, 1);
   victim->start_busy(1);
}
void sp2(object me, object victim, object  weapon, int damage)
{
   int skill= me->query_skill("lonely-sword", 1);
   message_vision("[1;37m$N[1;37mÍ»È»Îò³ö¡®Á·¾«»¯Æø, Á·Æø»¯Éñ, Á·Éñ»¹Ğé¡¯Ö®ÕæÀí, ÊÖÖĞ³¤½£Í»È»ÏûÊ§, ÒÑ³¯$n[1;37m·ÉÖÁ[0m\n",me,victim);
   victim->add("kee",-(skill* 2));
   COMBAT_D->report_status(victim, 1);
   victim->start_busy(1);
}
void sp3(object me, object victim, object  weapon, int damage)
{
   int skill= me->query_skill("lonely-sword", 1);
   message_vision("[1;37mÕâÆğÊÖÊ½Ò»Õ¹,¸ú×Å½£ÆøÍ»±¬¡®µ´½££®ÁÃ½££®¹ı½££®´ì½££®Àë½££®Âä½££®Ğı½££®Å²½£¡¯,×îºóË«ÊÖÍ¬Ê±»­Ô², ¸´³É³Ö½£¹éÔ­Ö®×Ë[0m\n",me,victim);
   victim->add("kee",-(skill* 2));
   COMBAT_D->report_status(victim, 1);
   victim->start_busy(1);
}
void sp4(object me, object victim, object  weapon, int damage)
{
   int i, loop;
   int skill= me->query_skill("lonely-sword", 1);
   loop= random( skill/ 10)+ 3;
   if( !me->query("berserk") && random(me->query("combat_exp")) > random(victim->query("combat_exp")))
   {
      me->set_temp("berserk", 1);
      message_vision("[1;37m$N[1;37mÁËÎòÁË¡®½£ÔÚÉñÏÈ, ÃàÃà²»¾ø¡¯Ö®ÕæÒâ, ½£¼âË²¼ä±¬³öÎŞÊı´ó´óĞ¡Ğ¡, Õı·´Ğ±Ö±¸÷ÖÖ¸÷ÑùµÄÔ²È¦, ³¯$n[1;37mÖ±ÆË¶øÀ´[0m\n",me,victim);
      for( i= 0; i< loop; i++)
      {
         message_vision("[1;34m$N[1;34m´óÉùºÈµÀ¡®½£ÔÚÉñÏÈ, ÃàÃà²»¾ø¡¯, ½£ÕĞÁ¬Ãà²»¾øµÄ³¯$n[1;34m¹¥È¥[0m\n", me, victim);
         victim->add("kee", -( random( skill)));
         COMBAT_D->report_status(victim, 1);
      }
      me->delete_temp("berserk");
      message_vision("[1;31mÒ»ÕóÁ¬»÷¹¥Ö®ºó, $N[1;31mÎ¢¸ĞÄÚÏ¢²»Ë³,¸Ï½ô³Ã»úµ÷Ï¢¡£[0m\n",me);
      me->start_busy(1);
      me->add("force", -skill);
   }
}

void berserk(object me, object victim, object  weapon, int damage)
{ 
   if( random(8) > 3 )
   {
      if( (int)me->query_skill("lonely-sword",1) > random(60)+35 &&me->query("force_factor")>= random(5) && me->query("force")>30)
      {
         if(!me->query_temp("berserk" ))
         {
            me->set_temp("berserk", 1);
            if(me->query("family/family_name") == "¶À¹Â´«ÈË")
            {
               message_vision( sprintf("\n[1;37m$N[1;37mÍ»È»¶ÙÎòÁË¡®ÉñÓëÒâºÏ, ÒâÓëÉñÊØ¡¯Ö®Òâ¾³"+
               "Ê¹³ö¶À¹Â¾Å½£ÖÁ¼«Ö®½£Êõ[31m¡® µ´½£Æğ¡«ÁÃ½£ÆÆ¡«Ğı½£ÎŞ¼«¡¯[37m!!![0m\n"),me ,victim);
               message_vision(sprintf("\n[1;34m$N[1;34mÉ²ÄÇ¼äÕû¸öÈËÍÑÌ¥»»¹Ç±äµÃÍşÃÍÎŞÂ×, "+
               "¿ç¿ª´ó²½, ³¤½£¸ß¾Ù¹ıÍ·, Íù$n^[[1;34mÆÈÈ¥\nÌìµØÕğ¶¯, ÓîÖæ·­ÌÚ, $n±»Õâ¹ÉÆøÊÆÕğÏÅ×¡, "+
               "Ö»¾õÑÛÇ°½£Ã¢Ò»ÉÁ¡£[0m\n "), me ,victim);
               victim->start_busy(1);
               victim->receive_wound("kee",100+random(100),me);
               me->add("force",-60);
            }
            me->delete_temp("berserk");
         }
      }
   }
}

int valid_learn(object me)
{
   object ob;
   if( !(ob = me->query_temp("weapon")) || (string)ob->query("skill_type") !="sword")
      return   notify_fail("ÉÙÁË°Ñ½£Á·ÆğÀ´¹Ö²»Ë³ÊÖµÄ, »¹ÊÇÄÃ°Ñ½£ÔÙÀ´Á·°É¡£\n");
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
   return CLASS_D("swordsman")+"/lonely-sword/"+action;
}

string query_parry_msg(string limb)
{
   return parry_msg[ random( sizeof( parry_msg))];
}

void skill_improved(object me)
{
tell_object(me,"[1;34mÓÉÓÚÄãÇ±ĞÄÑ§Ï°£¬ÄãµÄ¶À¹Â¾Å½£¸ü¼Ó´¿ÊìÁË£¡£¡[0m\n");
}
