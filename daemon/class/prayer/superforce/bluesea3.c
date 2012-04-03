#include <ansi.h>                                                               
inherit F_FUNCTION;                                                             
inherit SSERVER;                                                                
int skill;
int perform(object me, object target)                                           
{                                                                               
    object ob;
if(!this_player()) return 0;
skill=this_player()->query("functions/bluesea/level");
        if( !target ) target = offensive_target(me);                            
                                                                                
        if(!target) return notify_fail("ƒ„’“≤ªµΩµ–»À!!\n");
        if(skill < 90  )
            return notify_fail("ƒ„µƒ[34mµÂ≤◊∫£[0m¡∑µƒ≤ªπª¥ø Ï£¨Œﬁ∑®¥ﬂ‘À≥ˆ[34mæ®ÕÃ ∆[0m£¨–Î90º∂°£\n");      
        if( me->query_skill("superforce",1) < 110 )             
            return notify_fail("ƒ„ªÎÃÏ±¶º¯–ƒ∑®µƒª∫Ó…–Œ¥◊„πª£¨–Î110º∂°£\n");       
                                                                                
        if(!(ob=me->query_temp("weapon")))
        {
            if(me->query_temp("secondary_weapon"))
            return notify_fail("ƒ„≤ªø’ ÷ «Œﬁ∑® π”√[34mæ®ÕÃ ∆[0mµƒ£°£°\n");
        }
        if(ob=me->query_temp("weapon"))                                         
        {                                                                       
            if((string)ob->query("skill_type") != "unarmed")
            return notify_fail("ƒ„≤ªø’ ÷ «Œﬁ∑® π”√[34mæ®ÕÃ ∆[0mµƒ!\n");                      
        }
        if(me->query("force")<300)                                            
            return notify_fail("ƒ„µƒƒ⁄¡¶≤ªπª°£\n");              
        if(me->query("kee")<140)                                      
            return notify_fail("ƒ„µƒ∆¯≤ªπª°£\n");                
                                                                                
        if(!me->is_fighting(target))          
        {                                                                       
        tell_object(me,"[34mæ®ÕÃ ∆[0mŒ®‘⁄’Ω∂∑÷–≤≈ƒ‹ π”√°£\n");              
        return 1;
        }                         
        if(target->is_busy())
        return notify_fail("µ–»À busy ÷–£¨øÏπ•ª˜∞…°£\n");                                              
        message_vision("$N÷‹‘‚≈Ï≈»µƒ∆¯æ¢»Á∫£÷–æ®”„––Ω¯ ±µƒ∆¯ ∆∞ıÌÁ£¨$N“¿’’ªÎÃÏ±¶º¯À˘º«‘ÿµƒ¡∑π¶ø⁄æ˜,Ω´¥À∆¯æ¢∑¢ª”µƒ¡‹¿Ïæ°÷¬ !!\n\n",me,target);
        message_vision("$NÀ´±€“ªª”£¨[34mæ®ÕÃ ∆[0mµƒ∆¯æ¢»ÁÕ¨∫£¿À“ª∞„¡˝’÷∂¯œ¬ £°\n",me,target);                 
                                                                                
        me->add("force",-skill*4);

if(80>random(100))
        {                                                                       
                message_vision("$n±ªƒ„µƒƒ⁄æ¢∏¯ÕÃ …◊°£¨Àø∫¡Œﬁ∑®∂ØµØ£°\n",me,target);                                                                   
                message_vision( NOR,me);                                        
             target->start_busy(4);
                COMBAT_D->report_status(target);                                
        }                                                                       
        else                                                                    
        {                                                                         
                message_vision("$nº±÷–…˙÷«£¨Ω´[34mæ®ÕÃ ∆[0mµƒƒ⁄æ¢ºØ÷–‘⁄ ÷…œ∫Û£¨æ°–∫”⁄µÿ °£∑¥∂¯ πµ√$N ß»•¡À◊≈¡¶µ„£¨…• ß¡À∆Ω∫‚∏–!!\n",me,target);
                COMBAT_D->report_status(target);                                
        }                                                                        
        message_vision("[34m°∏æ®ÕÃ ∆°±[0m π≥ˆ∫Û£¨$Nº±√¶∫Ùœ¢µ˜∆¯£¨÷ÿ◊È’Ω∂∑¡¶",me,target); 
        me->start_busy(1);
        if(skill < 100) function_improved("bluesea",random(500));
        message_vision( NOR,me);                                                
        return 1;                                                               
}
                                                                             
