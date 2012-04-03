#include <ansi.h>                                                               
inherit F_FUNCTION;                                                             
inherit SSERVER;                                                                

int perform(object me, object target)                                           
{
    object ob;
    int age=me->query("age",1);
    int lv1=me->query("functions/goldsun/level");
    int lv=me->query_skill("superforce",1);
    int hurt_value=lv1*age/4+lv*age/12;
    if( hurt_value > 800) hurt_value=800;
                                                                                
        if( !target ) target = offensive_target(me);                            
        if( !target ) return notify_fail("ƒ„’“≤ªµΩµ–»À!!\n");
        if( lv1 < 30  )
            return notify_fail("ƒ„µƒ[33mΩ≥øÍÿ[0m¡∑µƒ≤ªπª¥ø Ï£¨Œﬁ∑®¥ﬂ‘À≥ˆ[33mΩ≥øÍÿ[0mµƒ∞‘∆¯£¨–Î30º∂°£\n");      
        if( me->query_skill("superforce",1) < 150 )             
            return notify_fail("ƒ„ªÎÃÏ±¶º¯–ƒ∑®µƒª∫Ó…–Œ¥◊„πª£¨–Î150º∂°£\n");       
                                                                                
        if(!(ob=me->query_temp("weapon")))                                        
        {
            if(me->query_temp("secondary_weapon"))
            return notify_fail("ƒ„≤ªø’ ÷ «Œﬁ∑® π”√[33mΩΩ£¥©‘∆[0mµƒ£°£°\n");
        }
        if(ob=me->query_temp("weapon"))                                         
        {                                                                       
        if((string)ob->query("skill_type") != "unarmed")                       
            return notify_fail("ƒ„≤ªø’ ÷ «Œﬁ∑® π”√[33mΩΩ£¥©‘∆[0mµƒ!\n");                      
        }
        if(me->query("force")<400)                                            
            return notify_fail("ƒ„µƒƒ⁄¡¶≤ªπª°£\n");              
        if(me->query("kee")<140)                                      
            return notify_fail("ƒ„µƒ∆¯≤ªπª°£\n");                
                                                                                
        if(!me->is_fighting(target))    
        {                                                                       
            tell_object(me,"[33mΩΩ£¥©‘∆[0mŒ®‘⁄’Ω∂∑÷–≤≈ƒ‹ π”√°£\n");
            return 1;
        }                                                                       
        message_vision("\t$N»´…Ì[33mΩπ‚…¡…¡[0m£¨π‚ª™∂·ƒø£¨[33mΩ…´µƒ’Ê∆¯[0m‘⁄…Ì≈‘–˝»∆£¨\n\t$N’˚∏ˆ»À∑……˝‘⁄ ˝’…∏ﬂµƒ∞Îø’÷–!!π‚√¢Àƒ…‰Õ»ÙΩæ—Ù!! \n\n",me,target);
        message_vision("$Nµ• ÷“ª÷∏£¨“ªµ¿“´—€Ωπ‚º§…‰∂¯≥ˆ£¨’˝ «∞‘’–[33mΩΩ£¥©‘∆[0m£°¥À’–”–»Á∑…¡˙∆À»’£¨∫¿π‚ÕÚ«ß£°\n",me,target);                 
                                                                                
        me->add("kee",-(hurt_value/20));
        me->add("force",-(hurt_value/4));
        if(80>random(100))
        {                                                                       
        message_vision("$nΩﬂ¡¶µ÷µ≤£¨»‘±ª∞‘µ¿µƒ[33mΩ≥øÍÿƒ⁄æ¢[0m…‰÷–£¨∂Ÿ ±[33mΩπ‚±¨ÃÂ[0m£¨œÚÀƒ∑Ω¬“…‰£°£°\n",me,target); 
        message_vision( NOR,me);                                        
        target->receive_damage("kee",hurt_value);
        target->add("force",-hurt_value/4);
        COMBAT_D->report_status(target);                                
        }                                                                       
        else                                                                    
        {                                                                         
        message_vision("$nΩﬂ¡¶µ÷µ≤£¨À‰±‹ø™¡À[33mΩΩ£¥©‘∆[0m’˝√Êµƒπ•ª˜£¨≤ªπ˝”“ ÷»¥ªπ «±ª…‰¥©¡À°£\n",me,target); 
        message_vision( NOR,me);                                        
                target->receive_damage("kee",hurt_value/13);
                target->add("force",-hurt_value/16);
        COMBAT_D->report_status(target);                                
        }                                                                        
        message_vision("[33m°∏ΩΩ£¥©‘∆°±[0m π≥ˆ∫Û£¨$N√Ê¬∂–¶»›£¨‘⁄∞Îø’÷–Ÿ¬Ì˛◊≈$n",me,target); 
        me->start_busy(1);
        if(lv1 < 150) function_improved("goldsun",random(500));
        message_vision( NOR,me);                                                
        return 1;                                                               
}
                                                                             
