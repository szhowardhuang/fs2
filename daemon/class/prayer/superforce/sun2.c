#include <ansi.h>                                                               
inherit F_FUNCTION;                                                             
inherit SSERVER;                                                                

int perform(object me, object target)                                           
{
    object ob;
    int age=me->query("age",1);
    int lv1=me->query("functions/goldsun/level");
    int lv=me->query_skill("superforce",1);
    int hurt_value=lv1*age/4+lv*age/10;
	if(me->query("class")!="prayer")
          return notify_fail("ƒ„µƒ÷∞“µŒﬁ∑® π”√¥Àººƒ‹°£\n");
    if( hurt_value > 900) hurt_value=900;
                                                                                
        if( !target ) target = offensive_target(me);                            
        if(!target) return notify_fail("ƒ„’“≤ªµΩµ–»À!!\n");
                                                                                
        if( lv1 < 60  )
            return notify_fail("ƒ„µƒ[33mΩ≥øÍÿ[0m¡∑µƒ≤ªπª¥ø Ï£¨Œﬁ∑®¥ﬂ‘À≥ˆ[33mΩ≥øÍÿ[0mµƒ∞‘∆¯£¨–Î60º∂°£\n");
        if( me->query_skill("superforce",1) < 170 )             
            return notify_fail("ƒ„ªÎÃÏ±¶º¯–ƒ∑®µƒª∫Ó…–Œ¥◊„πª£¨–Î170º∂°£\n");
                                                                                
        if(!(ob=me->query_temp("weapon")))
        {
            if(me->query_temp("secondary_weapon"))
            return notify_fail("ƒ„≤ªø’ ÷ «Œﬁ∑® π”√[33mÀ´–«∏œ‘¬[0mµƒ£°£°\n");
        }
        if(ob=me->query_temp("weapon"))                                         
        {                                                                       
            if((string)ob->query("skill_type") != "unarmed")
            return notify_fail("ƒ„≤ªø’ ÷ «Œﬁ∑® π”√[33mÀ´–«∏œ‘¬[0mµƒ!\n");
        }
        if(me->query("force")<400)                                            
            return notify_fail("ƒ„µƒƒ⁄¡¶≤ªπª°£\n");
        if(me->query("kee")<140)                                      
            return notify_fail("ƒ„µƒ∆¯≤ªπª°£\n");
                                                                                
        if(!me->is_fighting(target))        
        {                                                                       
            tell_object(me,"[33mÀ´–«∏œ‘¬[0mŒ®‘⁄’Ω∂∑÷–≤≈ƒ‹ π”√°£\n");
            return 1;
        }                                                                       
        message_vision("\t$N»´…Ì[33mΩπ‚…¡…¡[0m£¨π‚ª™∂·ƒø£¨[33mΩ…´µƒ’Ê∆¯[0m‘⁄…Ì≈‘–˝»∆£¨\n\t$N’˚∏ˆ»À∑……˝‘⁄ ˝’…∏ﬂµƒ∞Îø’÷–!!π‚√¢Àƒ…‰Õ»ÙΩæ—Ù!!\n\n",me,target);
        message_vision("$NÀ´»≠“ªŒ’£¨¡ΩÕ≈[33m“´—€Ωπ‚[0mª„æ€≥…«Ú£¨∫Ù–•∂¯≥ˆ£°¥À’–”–»ÁÀ´¡˙≥ˆ∫££¨Ωπ‚¥Ãƒø£¨÷±±∆µ–»À…œœ¬¡Ω¬∑£°\n",me,target);
                                                                                
        me->add("kee",-(hurt_value/20));
        me->add("force",-(hurt_value/4));
        if(80>random(100))
        {                                                                       
        message_vision("$nΩﬂ¡¶µ÷µ≤£¨»‘±ª’‚¡ΩÕ≈∆¯æ¢∫‰÷–£¨∂Ÿ ±…Ì ◊Œﬁ¥Ê£¨ ¨∫°±Èµÿ£°£°\n",me,target); 
        message_vision( NOR,me);                                        
        target->receive_damage("kee",hurt_value);
        target->add("force",-hurt_value/4);
        COMBAT_D->report_status(target);                                
        }                                                                       
        else                                                                    
        {                                                                         
        message_vision("$nΩﬂ¡¶…¡±‹£¨±‹ø™¡À[33mÀ´–«∏œ‘¬[0m’˝√Êµƒπ•ª˜£¨¡ΩÕ≈[33mΩπ‚[0m∫‰œÚµÿ√ÊΩ´µÿ√Ê’®¡Àø™¿¥°£\n",me,target);
        message_vision( NOR,me);                                        
        target->receive_damage("kee",hurt_value/12);
        target->add("force",-hurt_value/14);
        COMBAT_D->report_status(target);                                
        }                                                                        
        message_vision("[33m°∏À´–«∏œ‘¬°±[0m π≥ˆ∫Û£¨$N√Ê¬∂–¶»›£¨À∆∫ı∫‹¬˙“‚¥À’–µƒπ•ª˜ƒ‹¡¶",me,target); 
        me->start_busy(1);
        if(lv1 < 150) function_improved("goldsun",random(500));
        message_vision( NOR,me);                                                
        return 1;                                                               
}
                                                                             
