#include <ansi.h>                                                               
inherit F_FUNCTION;                                                             
inherit SSERVER;                                                                
                                                                                
int perform(object me, object target)                                           
{
    object ob;
    int age=me->query("age",1);
    int lv1=me->query("functions/blood/level");
    int lv=me->query_skill("superforce",1);
    int hurt_value=lv1*age/4+lv*age/4;
	if(me->query("class")!="prayer")
          return notify_fail("ƒ„µƒ÷∞“µŒﬁ∑® π”√¥Àººƒ‹°£\n");
 if( hurt_value > 3000) hurt_value=3000;
                                                                                
        if( !target ) target = offensive_target(me);                            
      if(!target) return notify_fail("ƒ„’“≤ªµΩµ–»À!!\n");
                                                                                
        if( lv1 < 105  )
            return notify_fail("ƒ„µƒ[31m—™Ò∑≤‘[0m¡∑µƒ≤ªπª¥ø Ï£¨Œﬁ∑® π≥ˆ[31mÒ∑≤‘Œﬁª⁄[0m£¨–Î105º∂°£\n");      
        if( me->query_skill("superforce",1) < 250 )             
            return notify_fail("ƒ„ªÎÃÏ±¶º¯–ƒ∑®µƒª∫Ó…–Œ¥◊„πª£¨–Î250º∂°£\n");       
                                                                                
        if(!(ob=me->query_temp("weapon")))                                        
        { if(me->query_temp("secondary_weapon"))                                
            return notify_fail(" π”√[31mÒ∑≤‘Œﬁª⁄[0m «≤ª–Ë“™Œ‰∆˜µƒ!!\n");}                       
        if(ob=me->query_temp("weapon"))                                         
        {                                                                       
 if((string)ob->query("skill_type") != "unarmed")
            return   notify_fail(" π”√[31mÒ∑≤‘Œﬁª⁄[0m «–Ë“™»≠Ω≈π¶∑Úµƒ!!\n");                      
        }                                                                     
        if(me->query("force")<500)                                            
            return notify_fail("ƒ„µƒƒ⁄¡¶≤ªπª°£\n");              
        if(me->query("kee")<180)                                      
            return notify_fail("ƒ„µƒ∆¯≤ªπª°£\n");                
                                                                                
        if(!me->is_fighting(target))         
        {                                                                       
            tell_object(me,"[31mÒ∑≤‘Œﬁª⁄[0mŒ®‘⁄’Ω∂∑÷–≤≈ƒ‹ π”√°£\n");
            return 1;
        }                                                                       

        message_vision("\t$NŒµ¿∂µƒÃÏø’ø™ º±‰≥…—™∫Ï…´, ∑Ω‘≤ Æ¿Ô÷Æƒ⁄»ÁÕ¨µÙ»Î[31m∞¢–ﬁ¬ﬁµÿ”¸[0m∞„!!\n\t$NΩ¸À∆∑ËøÒµÿÜà◊≈ªÎÃÏ±¶º¯µƒ¡∑π¶ø⁄æ˜, ¬˙ÃÏµƒ[31m—™∫Ï∆¯æ¢[0m‘Ω¿¥‘Ω≈®”Ù!!\n\t[31m—™¡˙æÌ∑Á[0m”¶æ¢∂¯…˙¡À!!\n\n",me,target);
        message_vision("$N∫µ¿: «ƒ„±∆Œ“ π”√ [31mÒ∑≤‘Œﬁª⁄[0mµƒ!!»•º˚—÷Õı∞…!!\n\n",me,target);
        me->add("kee",-(hurt_value/20));
        me->add("force",-(hurt_value/4));
        if(70>random(100))
        {                                                                       
        message_vision("$n±‹Œﬁø…±‹£¨ˆÆ ±±ª∏ﬂÀŸ∂¯¿¥µƒ[31m—™¡˙æÌ∑Á[0mæÌ≥…“ªÕ≈£¨±ª–˝∑Á¿≠≥∂µƒÕ¥≥˛”–»ÁÀ∫∏Œ¡—∑Œ£°\n",me,target);                                                                   
        message_vision( NOR,me);                                        
  target->receive_damage("kee",hurt_value);
        target->add("force",-hurt_value/2);
        COMBAT_D->report_status(target);                                
        }                                                                       
        else                                                                    
        {                                                                         
        message_vision("$n‘Àπ¶µ÷”˘£¨À‰»ª“¿æ…±ª[31m—™¡˙æÌ∑Á[0mæÌ…Ì∂¯»Î£¨ø… «$nµƒƒ⁄π¶–ﬁŒ™≤ªÀ◊, À˘“‘»‘»ª «ºÒªÿ“ªÃı–°√¸!!°£\n",me,target);  
        target->receive_damage("kee",hurt_value/10);
        target->add("force",-hurt_value/10);
        COMBAT_D->report_status(target);                                
        }                                                                        
        message_vision("[31m°∏Ò∑≤‘Œﬁª⁄°±[0m π≥ˆ∫Û£¨$N¥Û∫ƒƒ⁄¡¶°¢[36mÃÏ„⁄—®[0m÷Ë»ªÃ€Õ¥£¨Õ«»ªπÚµπ‘⁄µÿ\n",me,target); 
   me->start_busy(1);
        if(lv1 < 150) function_improved("blood",random(500));
        message_vision( NOR,me);                                                
        return 1;                                                               
}                                                                               

