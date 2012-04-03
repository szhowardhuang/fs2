//pd-staff.c editer.by Chan

#include <ansi.h>
#include <combat.h>
inherit SKILL;
inherit SSERVER;
void attack1(object me,object victim,object weapon,int damage);
void attack2(object me,object victim,object weapon,int damage);
void attack3(object me,object victim,object weapon,int damage);
void attack4(object me,object victim,object weapon,int damage);
void again1(object me,object victim,object weapon,int damage);
string *array_msg=
    ({
      "[1;33m$N´øÁì×Å´ó¼Ò£¬ÐÎ»¯ËÄÏó£¬¸´»¯°ËØÔÊ¹´ò¹·Õó·¨·¢»ÓÖÂ¼«µã¡£\n[0m",
      "[1;33mÖÚÈË·¢»Ó³öÕó·¨Ö®°ÂÃî±ä»¯£¬Ê¹µÐÈËÏÝÈë¾øÍûµÄÉîÔ¨¡£\n[0m",
      "[1;33m$NÖ¸»ÓÈô¶¨£¬ÖÚÈËÎä¹¦ÅäºÏµÄÌìÒÂÎÞ·ì£¬½«ÕÐÊ½µÝÏòµÐÈË¡£\n[0m",
      "[1;33mÖÚÈË·¢»Ó³öÕó·¨Ö®ÎÞÇî°ÂÒå£¬½«¶ÔµÐÈËµÄËðº¦·¢»Ó³ö×î´óµÄ¾³½ç\n[0m",
     });
mapping *action = ({
(["action":"$N½«ÊÖÖÐµÄ°ô×Ó,¼±»ÎÊýÏÂÊ¹³ö"HIW"¡¸°ô´òË«È®¡±"NOR",¶Ô×¼$nµÄ$l¡¸Ù¿¡±Ò»Éù~»÷ÏÂ",
"dodge":-60,
"parry":90,
"force":60,
"damage":60,
"damage_type" : "ðöÉË",
]),
(["action":"$NÊ¹³ö"HIW"¡¸°ô´ò¶ñÈ®¡±"NOR",ÊÖÖÐµÄ°ô×ÓËÆÓÐËÆÎÞ°ãµÄÏò$nµÄ$lØÝ³ö",
"dodge":-60,
"parry":90,
"force":70,
"damage":70,
"damage_type" : "´ÌÉË",
]),
(["action":"$N½«ÊÖÉÏµÄ°ô×Ó,¿´×¾ÊµÇÉÖ±Ö±ØÝÏò$nµÄ$lÕýÊÇÒ»ÕÐ"HIW"¡¸ÈôÒþÈôÏÖ¡±"NOR,
"dodge":-90,
"parry":110,
"force":100,
"damage":70,
"damage_type" : "ØÝÉË",
]),
(["action":"$NÔ¾ÖÁ°ë¿ÕÖÐ,¸ß¾ÙÊÖÖÐµÄ°ô×ÓÒ»ÕÐ"HIW"¡¸Á÷ÐÇ×¹µØ¡±"NOR"£¬ÈçÁ÷ÐÇ°ãÏò$nµÄ$l¼±Åü¶øÏÂ",
"dodge":-90,
"parry":110,
"force":100,
"damage":80,
"damage_type" : "¸îÉË",
]),
(["action":"$N½«ÊÖÖÐµÄ°ô×Ó,¼±»®È¦È¦Ò»ÕÐ"HIW"¡¸ÎÞÇîÎÞ¾¡¡±"NOR"£¬°ôÉÏµÄÄÚ¾¢Ïò$nµÄ$lÏ®È¥",
"dodge":-90,
"parry":110,
"force":100,
"damage":70,
"damage_type" : "ÄÚÉË",
]),
(["action":"$NÃæ¶Ô$nµÄ¹¥»÷Ê¹³ö"HIW"¡¸·â¹·ÔÚÍâ¡±"NOR"£¬½«¹¥»÷Ò»·â,ÀûÓÃ°ô×ÓÏò$nµÄ$lÒ»ØÝ",
"dodge":-90,
"parry":120,
"force":100,
"damage":80,
"damage_type" : "ðöÉË",
]),
(["action":"$N½«ÊÖÖÐµÄ°ô×Ó,ÓÉÏÂÍùÉÏÌôÆðÒ»ÕÐ"HIC"¡¸Ìô¹·ÔÚÌì¡±"NOR"Ê¹$n±»ÌôÖÁ¿ÕÖÐ²¢´ÓÅÔÏò$l»÷³ö",
"dodge":-100,
"parry":120,
"force":100,
"damage":80,
"damage_type" : "ðöÉË",
]),
(["action":"$N½«ÄÚ¾¢¹á×¢ÖÁ°ô×Ó,"HIC"¡¸¿ñ·ç×·Ñ©¡±"NOR"£¬°ô¾¢ËùÐÎ³ÉµÄº®·çÏò$nµÄ$lÏ®È¥",
"dodge":-100,
"parry":130,
"force":100,
"damage":85,
"damage_type" : "¶³ÉË",
]),
(["action":"$N¹Ä¾¡È«ÉíÄÚÁ¦,Ò»ÕÐ"HIC"¡¸ÂÒ°ô¿ñ»÷¡±"NOR"£¬ÊÖÖÐµÄ°ô×ÓÏò$nµÄ$lÂÒ»÷¶ø³ö",
"dodge":-100,
"parry":120,
"force":100,
"damage":90,
"damage_type" : "»÷ÉË",
]),
(["action":"$N¿ñºðÒ»Éù,ÄÚÁ¦É¢·¢Ê¹³ö¾ø¼¼"HIC"¡¸ÌìÏÂÎÞ¹·¡±"NOR"£¬ÂþÌìµÄ°ôÊÆÏò$nµÄ$l¿ñÏ®¶øÈ¥",
"dodge":-100,
"parry":120,
"force":110,
"damage":95,
"damage_type" : "´ÌÉË",
]),
(["action":"$NÁìÎò´ò¹·°ô·¨ËÄ´ó¾«ÒåÖ®"HIC"¡¸ÂÒ¡±"NOR"×Ö¾÷£¬ÊÖÖÐµÄ°ô×ÓÆäÊÆÎÞÇîÎÞ¾¡°ãÏò$nµÄ$l¿ñÉ¨¶øÈ¥",
"dodge":-100,
"parry":120,
"force":110,
"damage":100,
"post_action":  (: attack1 :),
"damage_type" : "ØÝÉË",
]),
(["action":"$NÁìÎò´ò¹·°ô·¨ËÄ´ó¾«ÒåÖ®"HIC"¡¸·â¡±"NOR"×Ö¾÷£¬ÊÖÖÐµÄ°ô×ÓÈçº£ÌìÒ»Ïß°ã·â×¡$nµÄ¹¥ÊÆ,ÊÖÖâÍ¬Ê±»÷È¥",
"dodge":-100,
"parry":120,
"force":110,
"damage":100,
"post_action":  (: attack2 :),
"damage_type" : "ðöÉË",
]),
(["action":"$NÁìÎò´ò¹·°ô·¨ËÄ´ó¾«ÒåÖ®"HIC"¡¸Åü¡±"NOR"×Ö¾÷£¬ÊÖÖÐµÄ°ô×ÓÈçÉÁµç°ã´ÓÉÏÏò$nµÄ$l¿ñÅü¶øÏÂ",
"dodge":-100,
"parry":110,
"force":110,
"damage":105,
"post_action":  (: attack3 :),
"damage_type" : "¿³ÉË",
]),
(["action":"$NÁìÎò´ò¹·°ô·¨ËÄ´ó¾«ÒåÖ®"HIC"¡¸Òý¡±"NOR"×Ö¾÷£¬ÊÖÖÐµÄ°ô×ÓÈçÇàÉß³ö¶´°ãÏò$nµÄ$l¿ñØÝ¶ø³ö",
"dodge":-100,
"parry":120,
"force":110,
"damage":105,
"post_action":  (: attack4 :),
"damage_type" : "ØÝÉË",
]),
(["action":HIR"$N½«¹È¾¡È«ÉíµÄÄÚÁ¦,Ê¹³ö´ò¹·°ô·¨ÖÐµÄ¡®ÂÒ»÷°ô·¨¡¯ÎÞÊý°ôÓ°ÆÌÌì¸ÇµØ°ãÏò$nÏ®È¥"NOR,
"dodge":-110,
"parry":150,
"force":150,
"damage":70,
"post_action":  (: again1 :),
"damage_type" : "ðöÉË",
]),
});

mapping query_action(object me, object weapon)
{
int skill;
   skill=me->query_skill("pd-staff", 1);
   if( me->query_temp("use_form",1))
     message_vision( array_msg[random(sizeof(array_msg))],me );
   if( skill < 50)
      return action[random(7)];
   else if( skill < 60)
      return action[random(7)+2];
   else if( skill < 70)
      return action[random(7)+3];
   else if( skill < 80)
      return action[random(7)+5];
   else if( skill < 90)
      return action[random(7)+7];
   else
      return action[random(7)+8];
}
void attack1(object me, object victim, object weapon, int damage)
{
 int att_value,skill;
 skill=me->query_skill("pd-staff", 1);
 att_value = skill * 12;
 if((me->query_skill_mapped("force")=="siseforce")&&(me->query("force_factor") >= 1 ))
  {
   message_vision(HIR"$N½«´ò¹·°ô·¨½áºÏÏ´Ëè¾­ÖÐµÄ°µ¾¢ÕðÉË$nÈ«ÉíÑªÂö\n"NOR,me,victim);
   victim->add("force",-att_value);
   COMBAT_D->report_status(victim, 1);
  }
}
void attack2(object me, object victim, object weapon, int damage)
{
 int busy_value,skill;
 skill=me->query_skill("pd-staff", 1);
// busy_value = skill / 2;
 if((me->query_skill_mapped("force")=="siseforce")&&(me->query("force_factor") >= 1 ))
  {
   message_vision(HIW"$N½«´ò¹·°ô·¨ÖÐ·â×Ö¾÷ºÍ½µÁú¾¢ÅäºÏ·â×¡$nµÄËÄÖ«°Ùº¡\n"NOR,me,victim);
   victim->start_busy( 1 );
   COMBAT_D->report_status(victim, 1);
  }
}
void attack3(object me, object victim, object weapon, int damage)
{
 int att_value,skill;
 skill=me->query_skill("pd-staff", 1);
 att_value = skill * 14;
 if((me->query_skill_mapped("force")=="siseforce")&&(me->query("force_factor") >= 1 ))
  {
   message_vision(HIB"$N½«´ò¹·°ô·¨ÖÐ×ª×Ö¾÷×¢Èë½µÁú¾¢ÐÎ³ÉÁú¾í·çÏ®Ïò$n\n"NOR,me,victim);
   victim->add("kee",-att_value);
   COMBAT_D->report_status(victim, 1);
  }
}
void attack4(object me, object victim, object weapon, int damage)
{
 int att_value,skill;
 skill=me->query_skill("pd-staff", 1);
 att_value = skill * 14;
 if((me->query_skill_mapped("force")=="siseforce")&&(me->query("force_factor") >= 1 ))
  {
   message_vision(HIG"$N½«½µÁú¾¢ÅäºÏ´ò¹·°ô·¨µÄÒý×Ö¾÷,ÆäÎÞÇîµÄÆø¾¢ØÝÉË$n\n"NOR,me,victim);
   victim->add("kee",-att_value);
   COMBAT_D->report_status(victim, 1);
  }
}

void again1(object me, object victim, object weapon, int damage)
{
        int i,time;
        int level=(int)(me->query_skill("pd-staff",1)/10);
	time=level+2;
        if (level > 6)
        {
  if( me->query_temp("pd-staff") == 0 && me->query("class")=="beggar" )
          {
              me->set_temp("pd-staff",1);
              message_vision(HIW"$NÊ¹³ö´ò¹·°ô·¨Ö®¡¸ÂÒÈ¡Ö®¼¼¡±,ÎÞÊýµÄ°ôÓ°Ïò$n¿ñÉ¨¶øÈ¥¡£\n"NOR, me, victim);
              for(i=1;i<=time;i++)
        COMBAT_D->do_attack(me, victim, me->query_temp("weapon"), TYPE_QUICK);
              me->delete_temp("pd-staff");
             me->start_busy(1);
          }
        } 

}

int practice_skill(object me)
{
  if ((int) me->query("max_force")<10000)
  return notify_fail("ÄãÎäÑ§ÖªÊ¶²»×ã£¬ÎÞ·¨²ÎÍ¸´ò¹·°ô·¨µÄ¾«ÃîÖ®´¦\n");
}

string perform_action_file(string action)
{
          return CLASS_D("beggar")+"/pd-staff/"+action;
}
int valid_learn(object me)
    {
        object weapon = me->query_temp("weapon");
        if( me->query("max_force") < 1000 ) {
            tell_object(me, "ÄãµÄÄÚÁ¦ÐÞÎª²»¹», ×îÉÙÒªÓÐÒ»Ç§µã¡£\n");
            return 0;
        }
        if(!(me->query("class") == "beggar")) {
            tell_object(me, "Ö»ÓÐØ¤°ïµÜ×Ó²ÅÄÜÑ§´ò¹·°ô·¨¡£\n");
            return 0;
        }
        if( me->query("str") >= 20 ) {
            tell_object(me, "ÄãµÄ±ÛÁ¦¹ý´óÎÞ·¨Ñ§´ò¹·°ô·¨¡£\n");
            return 0;
        }
        if(!(me->query("beggar/quests 10") == 1 )) {
            tell_object(me, "Ø¤°ïµÜ×ÓÒªÍê³ÉÈÎÎñÊ®²ÅÄÜÑ§¡£\n");
            return 0;
        }
        if( me->query("force") < 500 ) {
            tell_object(me, "ÄãÄ¿Ç°µÄÄÚÁ¦²»µ½Îå°Ùµã, ÎÞ·¨Á·´Ë¾øÑ§¡£\n");
            return 0;
        }
        if( (me->query("potential") - me->query("learned_points")) < 2 ) {
            tell_object(me, "ÄãµÄÇ±ÄÜ²»µ½¶þµã, ÎÞ·¨Á·´Ë¾øÑ§¡£\n");
            return 0;
        }
        if( !weapon || weapon->query("skill_type") != "staff" ) {
            tell_object(me, "ÊÖÖÐÎÞ°ôÔõÃ´¸öÁ··¨Ñ½?\n");
            return 0;
        }

        tell_object(me, "Ñ§´Ë¾øÑ§Ðè¿ÛÇ±ÄÜ¶þµã¡£\n");
        me->add("potential", -2);
        return 1;
}
int valid_enable(string usage)
{        return ( usage=="staff" )||(usage=="parry");
}
