#include <ansi.h>                                                               
inherit F_FUNCTION;                                                             
inherit SSERVER;                                                                
int skill;
int perform(object me, object target)                                           
{                                                                               
    object ob;
skill=this_player()->query("functions/bluesea/level");
        if( !target ) target = offensive_target(me);                            
        if(!target) return notify_fail("’“≤ªµΩµ–»À!!\n");
                                                                                
        if(skill < 60  )
            return notify_fail("ƒ„µƒ[34mµÂ≤◊∫£[0m¡∑µƒ≤ªπª¥ø Ï£¨Œﬁ∑®¥ﬂ‘À≥ˆ[34mºÎ¿ß ∆[0m£¨–Î“™60º∂°£\n");      
        if( me->query_skill("superforce",1) < 110 )             
            return notify_fail("ƒ„ªÎÃÏ±¶º¯–ƒ∑®µƒª∫Ó…–Œ¥◊„πª£¨–Î“™110º∂°£\n");
                                                                                
        if(!(ob=me->query_temp("weapon")))
        {
            if(me->query_temp("secondary_weapon"))
            return notify_fail("ƒ„≤ªø’ ÷ «Œﬁ∑® π”√[34mºÎ¿ß ∆[0mµƒ£°£°\n");
        }
        if(ob=me->query_temp("weapon"))                                         
        {                                                                       
            if((string)ob->query("skill_type") != "unarmed")
            return notify_fail("ƒ„≤ªø’ ÷ «Œﬁ∑® π”√[34mºÎ¿ß ∆[0mµƒ!\n");
        }
        if(me->query("force")<200)
           return notify_fail("ƒ„µƒƒ⁄¡¶≤ªπª°£\n");              
        if(me->query("kee")<140)                                      
           return notify_fail("ƒ„µƒ∆¯≤ªπª°£\n");                
                                                                                
        if(!me->is_fighting(target))                   
        {                                                                       
        tell_object(me,"[34mºÎ¿ß ∆[0mŒ®‘⁄’Ω∂∑÷–≤≈ƒ‹ π”√°£\n");              
        return 1;
        }                                                                       
        if(target->is_busy())
        return notify_fail("µ–»À busy ÷–£¨øÏπ•ª˜∞…°£\n");
        message_vision("$N÷‹‘‚≈Ï≈»µƒ∆¯æ¢»Á≥±ÀÆ∞„µÿøÏÀŸ±º◊ﬂ£¨$NΩ´¥À“ª∆¯æ¢‘Ω–˝‘ΩøÏ!!\n\n",me,target);
        message_vision("∫ˆ»ª$Nƒ⁄æ¢“ªÀÕ£¨’˚∏ˆ[34mºÎ¿ß ∆[0mµƒ∆¯æ¢‘Ω–˝‘ΩΩÙµÿœÚµ–»ÀœØæÌ∂¯œ¬ £°\n",me,target);
                                                                                
        me->add("force",-skill*3);

if(80>random(100))
        {                                                                       
        message_vision("$n±ªƒ„µƒ[34mºÎ¿ß ∆[0mƒ⁄æ¢∏¯ΩÙΩÙµƒ¿ß◊°£¨Œﬁ∑®∂ØµØ£°£°\n",me,target); 
        message_vision( NOR,me);                                        
        target->start_busy(3);
        COMBAT_D->report_status(target);                                
        }                                                                       
        else                                                                    
        {                                                                         
        message_vision("$nª§…Ì∆¯æ¢ ‹µΩ∏–”¶£¨π…µÿΩ´»´…Ìµƒƒ⁄æ¢±¨∑¢≥ˆ¿¥£¨ªØΩ‚¡À[34mºÎ¿ß ∆[0m÷œ∞≠µƒ∆¯¡˜ °£\n",me,target);                                                                            
        message_vision( NOR,me);                                        
        COMBAT_D->report_status(target);                                
        }
        message_vision("[34m°∏ºÎ¿ß ∆°±[0m π≥ˆ∫Û£¨$Nº±√¶∫Ùœ¢µ˜∆¯£¨÷ÿ◊È’Ω∂∑¡¶",me,target); 
        me->start_busy(1);
        if(skill < 100) function_improved("bluesea",random(500));
        message_vision( NOR,me);                                                
        return 1;                                                               
}
                                                                             
