// white1.c                                                                   

#include <ansi.h>                                                               
inherit F_FUNCTION;                                                             
inherit SSERVER;                                                                

int age=this_player()->query("age",1);
int lv1=this_player()->query_function("white1",1);
int lv=this_player()->query_skill("superforce",1);
int hurt_value=lv1*(age/4)+lv;


int perform(object me, object target)                                           
{    
        string msg;                                                             
        object ob;                                                              
        string *name;

      if( !target ) target = offensive_target(me);                            
                                                                               
      if(query_function("white") <= 20  )                                                                
          return notify_fail("ÄãµÄ°×·çÔÆÁ·µÄ²»¹»´¿Êì£¬ÎÞ·¨´ßÔË³ö·çÔÆ°ãÆ®ºö²»¶¨µÄäìÈ÷Æø¾¢¡£\n");      
      if( me->query_skill("superforce",1) < 50 )             
          return notify_fail("Äã»ëÌì±¦¼øÐÄ·¨µÄ»ðºîÉÐÎ´×ã¹»¡£\n");       
                                                                                
      if(!(ob=me->query_temp("weapon")))                                        
        { if(me->query_temp("secondary_weapon"))                                
                 return notify_fail("Äã²»¿ÕÊÖÊÇÎÞ·¨Ê¹ÓÃ[37;40m·çÙâÆÆµØ[0mµÄ£¡£¡\n");}                       
        if(ob=me->query_temp("weapon"))                                         
        {                                                                       
         if((string)ob->query("skill_type") != "unarmed")                       
                  return notify_fail("Äã²»¿ÕÊÖÊÇÎÞ·¨Ê¹ÓÃ[37;40m·çÙâÆÆµØ[0mµÄ!\n");                      
         }
          if(me->query("force")<150)                                            
                           return notify_fail("ÄãµÄÄÚÁ¦²»¹»¡£\n");              
                  if(me->query("kee")<100)                                      
                           return notify_fail("ÄãµÄÆø²»¹»¡£\n");                
                                                                                
        if(!me->is_fighting())                                                  
        {                                                                       
                tell_object(me,"[37;40m·çÙâÆÆµØ[0mÎ¨ÔÚÕ½¶·ÖÐ²ÅÄÜÊ¹ÓÃ¡£\n");              

                return 0;                                                       
        }                                                                       
        message_vision("\t\t$NÉíÉÏµÄÒÂÎï±»¹ÄÕÍµØÈçÍ¬ÆøÇòÒ»°ã£¬Æø¾¢ÈçÍ¬Çà·ç°×ÔÆ£¬$NÕû¸öÈËÂñÃ»ÔÚ\n
                ÕâÆ®ºöµÄÆø¾¢Ö®ÖÐ!!·çÉùÏôÏô!! \n\n",me,target);

        message_vision("\t\t$N×ó±§È­ÓÒ½£Ö¸£¬ÊýµÀÇ¿·ç´ÓÌìÉÏÏ®»÷¶øÏÂ£¬[37;40m·çÙâÆÆµØ[0mÓ¦Éù¶ø·¢£¡\n",me,target);                 
                                                                                
            me->add("kee",-(hurt_value/10));                                                 
            me->add("force",-(hurt_value/2));
        if(random(me->query_skill("superforce")+20)>random(target->query_skill("dodge")))                                                                          
        {                                                                       
                message_vision("\t\t$nµÄÑÛ¾¦±»Ç¿·ç¹ÎµÄÕÅ²»¿ªÀ´£¬[36m¾ÅÌìÖ®Æø[0mÖ»ÄÜÕÕµ¥È«ÊÕ£¬ÏÊÑª´¦´¦£¬ÉËºÛÀÛÀÛ£¡£¡\n",me,target);                                                                   
                message_vision( NOR,me);                                        
                target->receive_damage("kee",hurt_value);
                COMBAT_D->report_status(target);                                
        }                                                                       
        else                                                                    
      {                                                                         
                message_vision("$n½ßÁ¦ÉÁ¶ã£¬Ëä±Ü¿ªÁË[37;40m·çÙâÆÆµØ[0mÇ¿·çµÄ¹¥»÷£¬²»¹ýÈ´ÔÝÊ±ÎÞ·¨»Ö¸´ÊÓÁ¦¡£\n",me,target);
                message_vision( NOR,me);                                        
                target->start_busy(3);
                COMBAT_D->report_status(target);                                
       }                                                                        
        message_vision("[37;40m¡¸·çÙâÆÆµØ¡±[0mÊ¹³öºó£¬$NÐîÊÆ´ý·¢£¬·çÔÆÖ®ÄÚ¾¢ÃàÃà²»¾ø",me,target); 
        me->start_busy(1);                                                      
        function_improved("white1",random(me->query("force")/25));          
        message_vision( NOR,me);                                                
        return 1;                                                               
  }                                                                             
                                                                             
