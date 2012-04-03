#include <ansi.h>
inherit F_FUNCTION;
inherit SSERVER;
int perform(object me, object target)
{
  int value,k_level,unit=1,much;
  int kangfun=me->query("functions/kang-power/level");
  string msg;
  object ob;
  string *name;
  if( !target ) target = offensive_target(me);
  if(me->query_skill("haoforce",1) < 100 - ( me->query("con") + me->query("cps")*1.2 ) )
   return notify_fail("ÄãµÄºÆÈÕÐÄ·¨²»¹»´¿Êì£¬ÎÞ·¨¾ÛÆøÖ¸¼â¡£\n");
  if( (string)me->query_skill_mapped("unarmed")!= "lungshan")
return notify_fail("ºÆÈÕî¸\Æø±ØÐëÅäºÏãñÉ½¾øÑ§²ÅÄÜÓÃ¡£\n");
  if( me->query("family/family_name") != "ãñÉ½ÅÉ" )
return notify_fail("ºÆÈÕî¸\ÆøÖ»ÓÐãñÉ½ÅÉµÄÃÅÈË²Å¿ÉÒÔÊ¹ÓÃ¡£\n");
  if(!(ob=me->query_temp("weapon")))
  {
   if(me->query_temp("secondary_weapon"))
    return notify_fail("²»¿ÕÊÖÔõÃ´·¢ºÆÈÕ¾÷?\n");}
   if(ob=me->query_temp("weapon"))
    {
     if((string)ob->query("skill_type") != "unarmed")
      return   notify_fail("²»¿ÕÊÖÔõÃ´·¢ºÆÈÕ¾÷?\n");
    }
   if(me->query("force")<400)
     return notify_fail("ÄãµÄÄÚÁ¦²»¹»¡£\n");
   if(me->query("kee")<250)
     return notify_fail("ÄãµÄÆø²»¹»¡£\n");
   if(!me->is_fighting(target))
    {
     tell_object(me,"ºÆÈÕî¸\ÆøÎ¨ÔÚÕ½¶·ÖÐ²ÅÄÜÊ¹ÓÃ¡£\n");
     return 0;
    }
    value = me->query("functions/kang_kee/level");
    value=value+((int)me->query_skill("haoforce",1) / 2);

    k_level = value;

    if(!target) return notify_fail("ÄãÕÒ²»µ½µÐÈËÔÚÄÇ!!\n");
   if ( (k_level > 110) && (me->query_skill("fire-kee",1) > 60))
   {
    message_vision(
       "[1m$NË«ÊÖºÏÊ®ÏòÇ°Ö¸È¥£¬Ê¹³öºÆÈÕî¸\ÆøÖÐµÄ±ØÉ±°ÂÒå¡ï¡ï--[1;31mÁÒÈÕ¾÷[0m[1m--¡ï¡ï\n
          ö®Ê±¼ä$NµÄÁÒÈÕ»¤ÉíÆø¾¢ÄæÁ÷£¬Ò»¹ÉÖÁÑô¸ÕÁÒµÄÕæÆø³ä³âÔÚ$NµÄÊÖÉÏ\n
          $NµÄË«ÕÆÉ¢·¢³öÖËÈÈµÄ¹âÃ¢£¬Ö¸¼â¾Û¼¯ÁËÎÞÊý¿ÅµÄÃ÷ÁÁµÄ¹âÇò\n\n",me,target);
    message_vision(
       "[1m$N¿ñºðÒ»Éù£¬ÎÞÊýµÄ¡¸ÁÒÈÕî¸\Æø¡±Ïò$nÉäÈ¥£¡[1;31m\n
          -------------------------------------------------------------*
          -------------------------------------------------------------*
          -------------------------------------------------------------*
          -------------------------------------------------------------*
          -------------------------------------------------------------*
    [0m\n",me,target);
    me->add("kee",-70);
    me->add("force",-(k_level*4));
   }else
   if ( (k_level > 90) && (me->query_skill("fire-kee",1) > 30))
   {
    message_vision(
       "[1m$N½«Ë«ÕÆ³É»¢ÐÎ£¬Ê¹³öºÆÈÕî¸\ÆøÖÐµÄ±ØÉ±¼¼¡î¡î--[1;31mºÆÈÕ¾÷[0m[1m--¡î¡î\n
          $N½«Ê®³ßÄÚµÄÈÈÆø¼¯ÖÐÔÚË«ÕÆÖ®ÄÚ£¬Ö»¼û$NµÄË«ÕÆ·¢³öÕóÕóÃÆÈÈµÄÆø¾¢\n
          $NË«ÕÆ·¢¹âÖËÈÈ£¬ÕÆÖÐ¾Û¼¯Ò»¿ÅÃ÷ÁÁµÄ¹âÇò\n\n",me,target);
    message_vision(
       "[1m$NË«ÕÆÏòÇ°Ò»ÍÆ£¬ÕÆÖÐµÄ¡¸ºÆÈÕî¸\Æø¡±Ïò$nÉä³ö£¡[1;31m\n
          -------------------------------------------------------------*
          =============================================================***
          -------------------------------------------------------------*
    [0m\n",me,target);
    me->add("kee",-50);
    me->add("force",-(k_level*3));
   }else
   if ( k_level > 70)
   {
    message_vision(
       "[1m$N½«ÊÖÏòÌìÒ»Ö¸£¬ÔËÆðºÆÈÕî¸\ÆøÖÐµÄ¡¸[1;33m³àÈÕ¾÷[0m[1m¡±\n
          $N°ÑÌ«ÑôµÄ¹âÏß¼¯ÖÐÔÚÊÖÖÐ£¬Ò»¹ÉÖÁÑô¸ÕÁÒµÄÄÚ¾¢´Óµ¤ÌïÉýÆð£¬\n
          $NÈ«Éí·¢¹âÖËÈÈ£¬Ö¸¼â¾Û¼¯Ò»¿ÅÃ÷ÁÁµÄ¹âÇò\n\n",me,target);
    message_vision(
       "[1m$NÔË¾¢Ö¸¼â£¬Ò»µÀ¡¸³àÈÕî¸\Æø¡±Ïò$nÉäÈ¥£¡[1;33m\n
                                                             * *
         =====================================================* *
                                                             * *
       [0m\n",me,target);
    me->add("kee",-40);
    me->add("force",-(k_level*2));
   }else
   {
    message_vision(
       "[1m$NµÍºðÒ»Éù!!Ô¾ÖÁ¿ÕÖÐÊ¹³öºÆÈÕî¸\ÆøÖÐµÄ¡¸[1;33mÐñÈÕ¾÷[0m[1m¡±\n
          $NÔÚ°ë¿ÕÈçÌ«Ñô°ãÉ¢³öÖÁÑô¸ÕÁÒµÄÕæÆø£¬$N½«ÕæÆø¾ÛÔÚÕÆÉÏ\n
          ÕæÆøµÄ¾Û¼¯Ê¹$NµÄË«ÕÆÖËÈÈÍ¨ºì£¬·¢³ö»ÔÑÛ¹âÃ¢!!\n\n",me,target);
    message_vision(
       "[1m$NÔË¾¢ÒÔ×ã£¬½«¡¸ÐñÈÕî¸\Æø¡±´ÓÌì¿ÕÏò$nÉäÈ¥£¡[0m\n",me,target);
    me->add("kee",-30);
    me->add("force",-(k_level));
   }
if(80>random(100))
    {
     message_vision(
     "\n[1;31m$n¶ã±Ü²»¼°£¬±»î¸\Æø»÷ÖÐ£¬ö®Ê±ÁÒ»ðÁýÕÖ$nÈ«Éí£¬Ë»º¿²»¶Ï£¡\n[0m",me,target);
     message_vision( NOR,me);

if(me->query_temp("kang-power")&&me->query("id")==("master jen")) {
message_vision(HIW"$NÉíÉÏµÄ¡®ÁÒÑæºÆÆø¡¯Óë¡®ºÆÈÕî¸\Æø¡¯Ïà¸¨Ïà³ÉÌáÉýÁËÍþÁ¦ÖØ´´ÁË$n¡£"NOR,me,target);
message_vision("\n",me);
target->receive_wound("kee",4000);
}

     target->apply_condition("burn",random(15)+1);
     target->receive_wound("kee",(k_level*4)+200);
     COMBAT_D->report_status(target);
    }
   else
    {
     if (((string)target->query_skill_mapped("parry") == "fire-kee") &&
         (random(target->query_skill("fire-kee")) > 40))
      {
       message_vision(
"[1;37m\n$nÊ¹³öºÆÈÕ»¤ÉíÆø¾¢Ö®ÖÕ¼«¾øÕÐ¡¾[1;33m--ÁÒ--»ð--ÎÞ--ÏÞ--[1;37m¡¿\n
Ö»¼û$NµÄî¸\ÆøºÍ$n»¤ÉíÆø¾¢Ïà×²£¬ºä¡«¡«Ò»Éù¶þÈËËÄÖÜ·¢³öÂþÌìÖËÈÈÆø¾¢¡£[0m\n",me,target);
       message_vision( NOR,me);
      }
     else
     if (((string)target->query_skill_mapped("parry") == "snow-kee") &&
         (random(target->query_skill("snow-kee")) > 50))
      {
       message_vision(
      "[1;36m\n$nÊ¹³öÑ©²Ôº®¾¢Ö®ÖÕ¼«¾øÕÐ¡¾[1;37m--±ù--·ç--Ñ©--±©--[1;36m¡¿\n
Ö»¼û$NµÄî¸\nÆøºÍ$n»¤Éíº®¾¢Ïà×²£¬ºä¡«¡«Ò»ÉùËÄÖÜÉ¢³öÎíÆø¡£[0m\n",me,target);
       message_vision( NOR,me);
      }
     else
      {
       message_vision(
       "[31m$nÔË¹¦±Ü¿ª£¬µ«ÈÔÊÜî¸\ÆøÇÖÏ®£¬Ö»¼û$nµÄÉË¿Ú½¹ºÚÒ»¿é¡£[0m\n",me,target);
       message_vision( NOR,me);
       target->apply_condition("burn",random(15)+1);
       COMBAT_D->report_status(target);
      }
    }
    message_vision(
    "¡¸ºÆÈÕî¸\Æø¡±Éä³öºó£¬$N´óºÄÄÚÁ¦¡¢¸Ï½ô³Ã»úµ÷Ï¢ÄÚÏ¢\n",me,target);
    me->start_busy(1);
    if(me->query("functions/kang_kee/level") < 100)
    function_improved("kang_kee",random(me->query("max_force")/10));
    message_vision( NOR,me);
    return 1;
  }
