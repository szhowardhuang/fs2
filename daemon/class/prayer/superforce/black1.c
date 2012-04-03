#include <ansi.h>                                                               
inherit F_FUNCTION;                                                             
inherit SSERVER;                                                                

int perform(object me, object target)                                           
{
    object ob;
    int age=me->query("age",1);
    int lv1=me->query("functions/black/level");
    int lv=me->query_skill("superforce",1);
    int hurt_value=lv1*age/4+lv*age/18;
    if( hurt_value > 600) hurt_value=600;
                                                                                
        if( !target ) target = offensive_target(me);                            
                                                                                
        if(lv1<30)
  return notify_fail("ÄãµÄ[30mÐþ»ìãç[0mÁ·µÄ²»¹»´¿Êì£¬ÐëÒªÐþ»ìãç 30 ¼¶¡£\n");
        if( me->query_skill("superforce",1) < 80 )             
            return notify_fail("Äã»ëÌì±¦¼øÐÄ·¨µÄ»ðºîÉÐÎ´µ½¼Ò£¬ÐëÒª80¼¶¡£\n");                                                
        if(!(ob=me->query_temp("weapon")))                                        
        {
            if(me->query_temp("secondary_weapon"))
            return notify_fail("Äã²»¿ÕÊÖÊÇÎÞ·¨Ê¹ÓÃ»ìãçÌì±¬È­µÄ£¡£¡\n");
        }
        if(ob=me->query_temp("weapon"))                                         
        {                                                                       
            if((string)ob->query("skill_type") != "unarmed")
            return notify_fail("Äã²»¿ÕÊÖÊÇÎÞ·¨Ê¹ÓÃ[30m»ìãçÌì±¬È­[0mµÄ!\n");                      
        }
        if(me->query("force")<200)                                            
            return notify_fail("ÄãµÄÄÚÁ¦²»¹»¡£\n");              
        if(me->query("kee")<140)                                      
            return notify_fail("ÄãµÄÆø²»¹»¡£\n");                
                                                                                
        if(!me->is_fighting(target))
        {                                                                       
            tell_object(me,"[30m»ìãçÌì±¬È­[0mÎ¨ÔÚÕ½¶·ÖÐ²ÅÄÜÊ¹ÓÃ¡£\n");
            return 1;
        }                                                                       
        message_vision("\t$NÌåÄÚµÄÕæÆøÓÐÈçÅÌ¹Å¿ªÌìµØÒ»°ã£¬ÕæÆøÂÒ´Ü£¬\n\t$NÒÀÕÕ»ëÌì±¦¼øËù¼ÇÔØµÄÁ·¹¦¿Ú¾÷½«´ËÒ»Æø¾¢ÈÚÈë±¾ÉíµÄÄÚÁ¦ÐÞÎªÖ®ÖÐ!!\n\tÄÚ¹¦Ë²Ê±±©ÔöÁËÊýÊ®±¶!!\n",me,target);
        message_vision("$NÄÚ¾¢¿ñÍÂ£¬Ë«È­Âþ²¼»ìãçÆø¾¢£¬Ò»ÕÐ[30m»ìãçÌì±¬È­[0mË²Ê±ÏòËÄ·½Õ¨Éä¿ªÀ´ £¡\n",me,target);
                                                                                
        me->add("kee",-hurt_value/10);
        me->add("force",-hurt_value);
        if(80 > random(100))
        {                                                                       
        message_vision("$n±»ÄãµÄ[30m»ìãçÌì±¬È­[0mÔÒÖÐºó£¬$nÈ«ÉíµÄ¾­Âö±»»ìãçÄÚ¾¢ËùÉË£¬È­¾¢Í¸Éí¶ø³ö£¡£¡\n",me,target); 
        message_vision( NOR,me);                                        
        target->receive_damage("kee",hurt_value);
        target->add("force",-hurt_value/5);
        COMBAT_D->report_status(target);                                
        }                                                                       
        else                                                                    
        {                                                                         
        message_vision("$nÉíÐÎ¼±×ª£¬¾¡¹ÄÈ«ÉíÆø¾¢£¬»¯½âÁË[30m»ìãçÌì±¬È­[0mµÄ³å»÷Á¦ .¡£\n",me,target);
        message_vision( NOR,me);                                        
        target->receive_damage("kee",hurt_value/15);
        target->add("force",-hurt_value/20);
        COMBAT_D->report_status(target);                                
        }                                                                        
        message_vision("¡¸»ìãçÌì±¬È­¡±Ê¹³öºó£¬$NÁ¢¿Ì·­ÉíÏòºóÒ»Ô¾£¬ËÅ»ú¶ø¶¯",me,target); 
        me->start_busy(1);
        if(lv1 < 100) function_improved("black",random(500));
        message_vision( NOR,me);                                                
        return 1;                                                               
}
                                                                             
