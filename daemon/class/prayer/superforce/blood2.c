#include <ansi.h>                                                               
inherit F_FUNCTION;                                                             
inherit SSERVER;                                                                
                                                                                
int perform(object me, object target)                                           
{
    object ob;
    int age=me->query("age",1);
    int lv1=me->query("functions/blood/level");
    int lv=me->query_skill("superforce",1);
    int hurt_value=lv1*age/4+lv*age/6;
  if( hurt_value > 2000) hurt_value=2000;
                                                                                
        if( !target ) target = offensive_target(me);                            
        if(!target) return notify_fail("ƒ„’“≤ªµΩµ–»À!!!\n");
                                                                                
        if( lv1 < 70 )
           return notify_fail("ƒ„µƒ[31m—™Ò∑≤‘[0m¡∑µƒ≤ªπª¥ø Ï£¨Œﬁ∑®¥ﬂ‘À≥ˆ[31mÒ∑≤‘—™«Ú[0m£¨–Î70º∂°£\n");      
        if( me->query_skill("superforce",1) < 220 )             
           return notify_fail("ƒ„ªÎÃÏ±¶º¯–ƒ∑®µƒª∫Ó…–Œ¥◊„πª£¨–Î220º∂°£\n");       
                                                                                
        if(!(ob=me->query_temp("weapon")))                                        
        {
            if(me->query_temp("secondary_weapon"))
            return   notify_fail("≤ªø’ ÷‘ı√¥Ω´[31mÒ∑≤‘—™«Ú[0mæ€”⁄ ÷…œ?\n");
        }
        if(ob=me->query_temp("weapon"))                                         
        {                                                                       
 if((string)ob->query("skill_type") != "unarmed")
            return   notify_fail("≤ªø’ ÷‘ı√¥Ω´[31mÒ∑≤‘—™«Ú[0mæ€”⁄ ÷…œ?\n");                      
        }                                                                     
        if(me->query("force")<500)                                            
            return notify_fail("ƒ„µƒƒ⁄¡¶≤ªπª°£\n");              
        if(me->query("kee")<180)                                      
            return notify_fail("ƒ„µƒ∆¯≤ªπª°£\n");
                                                                                
        if(!me->is_fighting(target))        
        {                                                                       
            tell_object(me,"[31mÒ∑≤‘—™«Ú[0mŒ®‘⁄’Ω∂∑÷–≤≈ƒ‹ π”√°£\n");
            return 1;
        }                                                                       
        message_vision("\t\t$NÃÂÕ‚[31m—™∫Ïµƒ∆¯æ¢[0mÀÊ“‚∂¯◊ﬂ,\n\t\t÷ªº˚$N…Ì≈‘µƒ[31m—™∫Ï…´’Ù∆¯[0m‘Ω¿¥‘Ω≈®∫Ò!!\n\t\t$N¥Û∫»“ª…˘,≈¨¡¶Ω´∆¯æ¢æ€”⁄ ÷’∆÷Æ…œ, –Œ≥…¡À“ªÕ≈\n\t\t÷±æ∂¥Á–Ìµƒ[31m—™«Ú[0m!!!\n\n",me,target);
        message_vision("$N‘Àæ¢”⁄À´’∆£¨ πæ¢“ªÕ∆,[31mÒ∑≤‘—™«Ú[0m≥Øµ–»ÀøÒ±º∂¯»•!\n",me,target);                 
                                                                                
        me->add("kee",-(hurt_value/20));
        me->add("force",-(hurt_value/4));
        if(70>random(100))
        {                                                                       
        message_vision("$n“ªº˚∂„±‹“—æ≠ŒﬁÕ˚£¨‘À∆ª§…Ì∆¯æ¢”≤Ω”œ¬’‚Õ≈[31m—™«Ú[0m£¨ŒﬁƒŒ[31m—™Ò∑≤‘∆¯æ¢[0mÃ´√Õ£¨ª§…Ì∆¯æ¢≤“‘‚’ÀÈ£¨ˆÆ ±∏ﬂ»»µƒ—™—Ê∑Ÿ…’$nµƒ»´…Ì£¨—™“∫∫√À∆±ª’Ù∑¢∂¯≥ˆ!\n",me,target);
        target->receive_damage("kee",hurt_value);
        target->add("force",-hurt_value/6);
        COMBAT_D->report_status(target);                                
        }                                                                       
        else                                                                    
        {                                                                         
        message_vision("$n“‘»´…Ìµƒƒ⁄¡¶◊È≥…∆¯«Ω£¨”Î[0m—™Ò∑≤‘∆¯æ¢[0mª•∂∑£¨[≈È]µƒ“ª…˘£¨±ª’ÕÀ ˝≤Ω£¨ø⁄Õ¬œ —™°£\n",me,target);                                                                            
        message_vision( NOR,me);                                        
        target->receive_damage("kee",hurt_value/10);
        target->add("force",-hurt_value/10);
        COMBAT_D->report_status(target);                                
        }                                                                        
        message_vision("[31m°∏Ò∑≤‘—™«Ú°±[0m π≥ˆ∫Û£¨$Nƒ⁄¡¶¥Û¡ø∫ƒÀ°¢[36m–ƒø≤—®[0m÷Ë»ªæÁÕ¥£¨$N˜ˆ»ªµ¯◊¯‘⁄µÿ\n",me,target); 
     me->start_busy(1);
        if(lv1 < 150) function_improved("blood",random(500));
        message_vision( NOR,me);                                                
        return 1;                                                               
}                                                                               
