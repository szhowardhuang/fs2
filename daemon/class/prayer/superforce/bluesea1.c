#include <ansi.h>                                                               
inherit F_FUNCTION;                                                             
inherit SSERVER;                                                                
int skill;
int perform(object me, object target)                                           
{                                                                               
    object ob;
                                                                                
skill=me->query("functions/bluesea/level");
        if( !target ) target = offensive_target(me);                            
                                                                                
        if(skill < 30  )
            return notify_fail("ÄãµÄ[34mµå²×º£[0mÁ·µÄ²»¹»´¿Êì£¬ÎÞ·¨´ßÔË³ö[34mÌÏÌìÊÆ[0m£¬ÐëÒª30¼¶¡£\n");      
        if( me->query_skill("superforce",1) < 110 )             
            return notify_fail("Äã»ëÌì±¦¼øÐÄ·¨µÄ»ðºîÉÐÎ´×ã¹»£¬ÐëÒª110¼¶¡£\n");
                                                                                
        if(!(ob=me->query_temp("weapon")))
        {
            if(me->query_temp("secondary_weapon"))
            return notify_fail("Äã²»¿ÕÊÖÊÇÎÞ·¨Ê¹ÓÃ[34mÌÏÌìÊÆ[0mµÄ£¡£¡\n");
        }
        if(ob=me->query_temp("weapon"))                                         
        {                                                                       
            if((string)ob->query("skill_type") != "unarmed")
            return notify_fail("Äã²»¿ÕÊÖÊÇÎÞ·¨Ê¹ÓÃ[34mÌÏÌìÊÆ[0mµÄ!\n");
        }

        if(me->query("force")<300)
            return notify_fail("ÄãµÄÄÚÁ¦²»¹»¡£\n");
        if(me->query("kee")<140)
            return notify_fail("ÄãµÄÆø²»¹»¡£\n");
                                                                                
        if(!me->is_fighting(target))    
        {                                                                       
            tell_object(me,"[34mÌÏÌìÊÆ[0mÎ¨ÔÚÕ½¶·ÖÐ²ÅÄÜÊ¹ÓÃ¡£\n");
            return 1;
        }
        if(target->is_busy())
        return notify_fail("µÐÈË busy ÖÐ£¬¿ì¹¥»÷°É¡£\n");     

        message_vision("$NÖÜÔâÅìÅÈµÄÆø¾¢Èç¼±Á÷Ò»°ãµØÁ÷´Ü£¬$NÒÀÕÕ»ëÌì±¦¼øËù¼ÇÔØµÄÁ·¹¦¿Ú¾÷,½«´ËÒ»Æø¾¢È«ÊýµØÊÕÄÉÆðÀ´ !!\n\n",me,target);
        message_vision("$N½«Õâ¹ÉÆø¾¢Éä³ö£¬ÓÐÈç[34mÀË³±ÌÏÌìµÄÆø¾¢[0mÍùµÐÈËÏÂ·½ÐÚÓ¿³åÍ»¶øÉÏ £¡\n",me,target);                 
                                                                                
        me->add("force",-skill*2);

if(80>random(100))
        {
                message_vision("$n±»Äã[34mÌÏÌìÊÆ[0mµÄÄÚ¾¢¸øÅ×ÉÏÁËÌì¿Õ£¬Õû¸öÈËÊ§È¥ÁËÖØÐÄ£¡£¡\n",me,target);                                                                   
                message_vision( NOR,me);                                        
                target->start_busy(2);
                COMBAT_D->report_status(target);                                
        }                                                                       
        else                                                                    
        {
                message_vision("$nÃ¦Ê¹³öÇ§½ï×¹£¬½«ÉíÐÎÎÈ×¡£¬»¯½âÁË[34mÌÏÌìÊÆ[0mÅ×¾íµÄÆø¾¢ .¡£\n",me,target);                                                                            
                message_vision( NOR,me);                                        
                COMBAT_D->report_status(target);                                
        }
        message_vision("[34m¡¸ÌÏÌìÊÆ¡±[0mÊ¹³öºó£¬$N¼±Ã¦ºôÏ¢µ÷Æø£¬ÖØ×éÕ½¶·Á¦",me,target); 
        me->start_busy(1);
        if(skill < 100) function_improved("bluesea",random(500));
        message_vision( NOR,me);                                                
        return 1;                                                               
}
                                                                             
