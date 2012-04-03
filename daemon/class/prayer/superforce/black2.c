#include <ansi.h>                                                               
inherit F_FUNCTION;                                                             
inherit SSERVER;
                                                                
int perform(object me, object target)                                           
{
    object ob;
    int age=me->query("age",1);
    int lv1=me->query("functions/black/level");
    int lv=me->query_skill("superforce",1);
    int hurt_value=lv1*age/4+lv*age/16;
	if(me->query("class")!="prayer")
          return notify_fail("ƒ„µƒ÷∞“µŒﬁ∑® π”√¥Àººƒ‹°£\n");
    if( hurt_value > 700) hurt_value=700;
                                                                                
        if( !target ) target = offensive_target(me);                            
        if( !target ) return notify_fail("ƒ„’“≤ªµΩµ–»À!!\n");
                                                                                
        if( lv1 < 60  )
        return notify_fail("ƒ„µƒ[30m–˛ªÏ„Á[0m¡∑µƒ≤ªπª¥ø Ï£¨–Î“™–˛ªÏ„Á 60 º∂°£\n");      
        if( me->query_skill("superforce",1) < 90 )             
        return notify_fail("ƒ„ªÎÃÏ±¶º¯–ƒ∑®µƒª∫Ó…–Œ¥◊„πª£¨–Î“™90º∂°£\n");       
                                                                                
        if(!(ob=me->query_temp("weapon")))                                        
        {
            if(me->query_temp("secondary_weapon"))
            return notify_fail("ƒ„≤ªø’ ÷ «Œﬁ∑® π”√[30mªÏ„Áµÿ¡—’∆[0mµƒ£°£°\n");
        }
        if(ob=me->query_temp("weapon"))                                         
        {                                                                       
            if((string)ob->query("skill_type") != "unarmed")
            return notify_fail("ƒ„≤ªø’ ÷ «Œﬁ∑® π”√[30mªÏ„Áµÿ¡—’∆[0mµƒ!\n");                      
        }
        if(me->query("force")<200)                                            
            return notify_fail("ƒ„µƒƒ⁄¡¶≤ªπª°£\n");              
        if(me->query("kee")<140)                                      
            return notify_fail("ƒ„µƒ∆¯≤ªπª°£\n");                
                                                                                
        if(!me->is_fighting(target))                                                  
        {                                                                       
            tell_object(me,"[30mªÏ„Áµÿ¡—’∆[0mŒ®‘⁄’Ω∂∑÷–≤≈ƒ‹ π”√°£\n");
            return 1;
        }                                                                       
        message_vision("\t$NÃÂƒ⁄µƒ’Ê∆¯”–»Á≈Ãπ≈ø™ÃÏµÿ“ª∞„£¨’Ê∆¯¬“¥‹£¨\n\tÀ∆∫ıæÕ“™±¨ÃÂ∂¯≥ˆ, ÷ª”–Ω´¥À“ª∆¯æ¢‘À ‰µΩƒ„µƒÀ´’∆º‰÷–!!\n\t÷ªº˚ƒ„À´ ÷µƒΩÓ»‚±©’«¡À ˝±∂÷Æ∂‡!!\n",me,target);
        message_vision("$NÀ´»≠¬˛≤ºªÏ„Á∆¯æ¢£¨÷ªæı≤ªÕ¬≤ªøÏ£¨«ø’–[30mªÏ„Áµÿ¡—’∆[0m–Æ◊≈∫‰»ª÷Æ ∆œÚµ–»À∂¯»• .[0m£°\n",me,target);
                                                                                
        me->add("kee",-hurt_value/10);
        me->add("force",-hurt_value);
        if(80 > random(100))
        {                                                                       
        message_vision("$nµƒÀ´’∆”Î[30mªÏ„Áµÿ¡—’∆[0mœ‡ΩªΩœæ¢£¨»¥≤“‘‚–€ªÎµƒªÏ„Áƒ⁄æ¢’∂œÀ´±€£¨’∆æ¢¥•ÃÂ∫Û¡Ìƒ„¬Ì…œø™≥¶∆∆∂«£°£°\n",me,target);                                   
        message_vision( NOR,me);                                        
        target->receive_damage("kee",hurt_value);
        target->add("force",-hurt_value/10);
        COMBAT_D->report_status(target);                                
        }                                                                       
        else                                                                    
        {                                                                         
        message_vision("$n∑‹¡¶œÚ∫Û“ª‘æ£¨…¡±‹¡À[30mªÏ„Áµÿ¡—’∆[0mµƒø™…Ω¡—±Æµƒ…±…À¡¶°£\n",me,target); 
        message_vision( NOR,me);                                        
        target->receive_damage("kee",hurt_value/14);
        target->add("force",-hurt_value/18);
        COMBAT_D->report_status(target);                                
        }                                                                        
        message_vision("[34m°∏ªÏ„Áµÿ¡—’∆°±[0m π≥ˆ∫Û£¨$N¡¢øÃ◊›…Ì∆ÀΩ¯$n£¨ºÃ–¯«¿π•",me,target); 
        me->start_busy(1);
        if(lv1 < 100) function_improved("black",random(500));
        message_vision( NOR,me);                                                
        return 1;                                                               
}
                                                                             
