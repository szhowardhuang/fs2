#include <ansi.h>                                                               
inherit F_FUNCTION;                                                             
inherit SSERVER;                                                                
                                                                                
int perform(object me, object target)                                           
{
    object ob;
    int age=me->query("age",1);
    int lv1=me->query("functions/blood/level");
    int lv=me->query_skill("superforce",1);
    int hurt_value=lv1*age/4+lv*age/8;
    if( hurt_value > 1000) hurt_value=1000;
                                                                                
        if( !target ) target = offensive_target(me);                            
                                                                                
        if( lv1 < 35  )
            return notify_fail("ÄãµÄ[31mÑªñ·²Ô[0mÁ·µÄ²»¹»´¿Êì£¬ÎÞ·¨´ßÔË³ö[31mñ·²ÔÆø¾¢[0m£¬Ðë35¼¶¡£\n");      
        if( me->query_skill("superforce",1) < 200 )             
            return notify_fail("Äã»ëÌì±¦¼øÐÄ·¨µÄ»ðºîÉÐÎ´×ã¹»£¬Ðë200¼¶¡£\n");       
                                                                                
        if(!(ob=me->query_temp("weapon")))                                        
        {
            if(me->query_temp("secondary_weapon"))
            return   notify_fail("±ØÐè·ÅÆúÉíÉÏµÄÎäÆ÷²ÅÄÜ½«[31mñ·²ÔÆø¾¢[0m»¯Îª[31mÑªº£ÎÞÑÄ[0m!!\n");
        }
        if(ob=me->query_temp("weapon"))                                         
        {                                                                       
 if((string)ob->query("skill_type") != "unarmed")
            return   notify_fail("±ØÐè¿ÕÊÖ²ÅÄÜ½«[31mñ·²ÔÆø¾¢[0m¾ÛÓÚË«ÕÆÖ®ÉÏ!!\n");                      
        }                                                                     
        if(me->query("force")<500)                                            
            return notify_fail("ÄãµÄÄÚÁ¦²»¹»¡£\n");              
        if(me->query("kee")<180)                                      
            return notify_fail("ÄãµÄÆø²»¹»¡£\n");                
                                                                                
        if(!me->is_fighting(target))      
        {                                                                       
            tell_object(me,"[31mÑªº£ÎÞÑÄ[0mÎ¨ÔÚÕ½¶·ÖÐ²ÅÄÜÊ¹ÓÃ¡£\n");
            return 1;
        }                                                                       
        message_vision("\tÖ»¼û$NÉíÅÔµÄ[31mÑªºìÉ«ÕôÆø[0mÔ½À´Ô½Å¨ºñ!!\n\tÖ®ºó$N´óºÈÒ»Éù, [31mñ·²ÔÄÚ¾¢[0m»íÈ»¾ÛÓÚË«ÕÆÖ®ÉÏ!!\n\n",me,target);
        message_vision("$NË«ÕÆÒ»Á¬·¢³öÊýÕÐ[31m¡¸Ñªº£ÎÞÑÄ¡±[0m, ½«µÐÈËµÄÈ«ÉíÖÜÎ§²¼ÂúÁË[31mñ·²ÔÆø¾¢[0m£¡\n",me,target);                 
                                                                                
        me->add("kee",-(hurt_value/20));
        me->add("force",-(hurt_value/4));
        if(70>random(100))
        {                                                                       
        message_vision("$n½«È«ÉíÖÜÎ§ÊØµÄÃÜ²»Í¸·ç£¬ÆóÍ¼½ÓÏÂÕâÒ»»÷£¬ÎÞÄÎ[31mñ·²ÔÆø¾¢[0mËÆÓÐ»¹ÎÞ£¬ÈÔ±»ÅÄÖÐÊýÕÆ£¬ö®Ê±¸ßÈÈµÄÑªÑæ´ÜÁ÷$nµÄÈ«Éí£¡£¡\n",me,target);                                                                   
        message_vision( NOR,me);                                        
        target->receive_damage("kee",hurt_value);
        target->add("force",-hurt_value/5);
        COMBAT_D->report_status(target);                                
        }                                                                       
        else                                                                    
        {                                                                         
        message_vision("$nÒÔÈ«ÉíµÄÄÚÁ¦Óë[31mÑªñ·²ÔÆø¾¢[0m»¥¶·£¬¡±Åì¡±¡±Åé¡±Ö®Éù²»¾øÓÚ¶ú£¬½»ÊÖ¹ýºó$N±»ÕðµÄÊÜÁËÄÚÉË¡£\n",me,target);
        message_vision( NOR,me);                                        
        target->receive_damage("kee",hurt_value/10);
        target->add("force",-hurt_value/12);
        COMBAT_D->report_status(target);                                
        }                                                                        
        message_vision("[31m¡¸Ñªº£ÎÞÑÄ¡±[0mÊ¹³öºó£¬$NÄÚÁ¦´óÁ¿ºÄËð¡¢¾­Âö²»Ë³£¬$NÁ¢¿ÌÅÌ×øÔÚµØÔËÏ¢µ÷Àí\n",me,target); 
     me->start_busy(1);
        if(lv1 < 150) function_improved("blood",random(500));
        message_vision( NOR,me);                                                
        return 1;                                                               
}                                                                               
