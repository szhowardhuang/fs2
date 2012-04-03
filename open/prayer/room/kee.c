
// keng_kee.c

#include <ansi.h>
inherit F_FUNCTION;
inherit SSERVER;

int perform(object me, object target)
{
        string msg;
        object ob;
        string *name;

        if( !target ) target = offensive_target(me);

          if(me->query_skill("haoforce",1) < 100 - ( me->query("con") + me->query("cps")*1.2 ) )
             return notify_fail("ÄãµÄºÆÈÕÐÄ·¨²»¹»´¿Êì£¬ÎÞ·¨¾ÛÆøÖ¸¼â¡£\n");
        if( (string)me->query_skill_mapped("unarmed")!= "lungshan")
                return notify_fail("ºÆÈÕî¸Æø±ØÐëÅäºÏãñÉ½¾øÑ§²ÅÄÜÓÃ¡£\n");
         
      if(!(ob=me->query_temp("weapon"))) 
        { if(me->query_temp("secondary_weapon"))
          return   notify_fail("²»¿ÕÊÖÔõÃ´·¢ºÆÈÕ¾÷?\n");} 
        if(ob=me->query_temp("weapon")) 
        {
         if((string)ob->query("skill_type") != "unarmed") 
            return   notify_fail("²»¿ÕÊÖÔõÃ´·¢ºÆÈÕ¾÷?\n");
          }
          if(me->query("force")<250)
                           return notify_fail("ÄãµÄÄÚÁ¦²»¹»¡£\n");
                  if(me->query("kee")<180)
                           return notify_fail("ÄãµÄÆø²»¹»¡£\n");

        if(!me->is_fighting())  
        {
                tell_object(me,"ºÆÈÕî¸\ÆøÎ¨ÔÚÕ½¶·ÖÐ²ÅÄÜÊ¹ÓÃ¡£\n");
                return 0;
        }
        message_vision(
            "[1m$N¿ÚÖÐ†ˆ†ˆÓÐ´Ê£¬ÔËÆðºÆÈÕÐÄ·¨ÖÐµÄ¡¸[1;31mÁÒÈÕ¾÷[0m[1m¡±\n
               $Nö®Ê±Ò»¹ÉÖÁÑô¸ÕÁÒµÄÕæÆø³äÈû×Å$NÉíÅÔÖ»¼û$N\n
               È«Éí·¢¹âÖËÈÈ£¬Ö¸¼â¾Û¼¯Ò»¿ÅÃ÷ÁÁµÄ¹âÇò\n\n",me,target);

        {
        message_vision(
            "[1m$NÔË¾¢Ö¸¼â£¬Ò»µÀ¡¸ºÆÈÕî¸\Æø¡±ÉäÈ¥£¡[0m\n",me,target);

            me->add("kee",-50);
                  me->add("force",-(110 - ((int)me->query_skill("haoforce",1)))*3);
        if(random(me->query_skill("unarmed")+20)>random(target->query_skill("dodge")))
        {
                message_vision(
                    "\n$n¶ã±Ü²»¼°£¬±»î¸\Æø»÷ÖÐ£¬ö®Ê±ÁÒ»ðÁýÕÖ$nÈ«Éí£¬Ë»º¿²»¶Ï£¡\n",me,target);
                message_vision( NOR,me);
                target->apply_condition("burn",random(10) +((int)me->query_skill("haoforce", 1)/8 ));
                  target->receive_wound("kee",me->query_skill("haoforce",1)*4+random(me->query_skill("haoforce",1)*2));
                COMBAT_D->report_status(target);
        }
        else
      {
                message_vision(
                "$nÔË¹¦±Ü¿ª£¬µ«ÈÔÊÜî¸\Æø²Á¹ý£¬Ö»¼û$nµÄÉË¿Ú½¹ºÚÒ»¿é¡£\n",me,target);
                message_vision( NOR,me);
                target->apply_condition("burn",random(10) +((int)me->query_skill("haoforce", 1)/8 ));
                COMBAT_D->report_status(target);
       }
        message_vision(
            "¡¸ºÆÈÕî¸\Æø¡±Éä³öºó£¬$N´óºÄÄÚÁ¦¡¢ÆøÏ¢ÎÉÂÒ£¬ÎÞ·¨ÒÆ¶¯\n",me,target);
        me->start_busy(2);
        me->kill_ob(target);
          function_improved("kang_kee",random(me->query("force")/10));
        message_vision( NOR,me);
        return 1;
  }
}
