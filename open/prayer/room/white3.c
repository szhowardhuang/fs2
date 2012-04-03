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
          return notify_fail("你的白风云练的不够纯熟，无法催运出风云般飘忽不定的潇洒气劲。\n");      
      if( me->query_skill("superforce",1) < 50 )             
          return notify_fail("你浑天宝鉴心法的火侯尚未足够。\n");       
                                                                                
      if(!(ob=me->query_temp("weapon")))                                        
        { if(me->query_temp("secondary_weapon"))                                
                 return notify_fail("你不空手是无法使用[37;40m风兮破地[0m的！！\n");}                       
        if(ob=me->query_temp("weapon"))                                         
        {                                                                       
         if((string)ob->query("skill_type") != "unarmed")                       
                  return notify_fail("你不空手是无法使用[37;40m风兮破地[0m的!\n");                      
         }
          if(me->query("force")<150)                                            
                           return notify_fail("你的内力不够。\n");              
                  if(me->query("kee")<100)                                      
                           return notify_fail("你的气不够。\n");                
                                                                                
        if(!me->is_fighting())                                                  
        {                                                                       
                tell_object(me,"[37;40m风兮破地[0m唯在战斗中才能使用。\n");              

                return 0;                                                       
        }                                                                       
        message_vision("\t\t$N身上的衣物被鼓胀地如同气球一般，气劲如同青风白云，$N整个人埋没在\n
                这飘忽的气劲之中!!风声萧萧!! \n\n",me,target);

        message_vision("\t\t$N左抱拳右剑指，数道强风从天上袭击而下，[37;40m风兮破地[0m应声而发！\n",me,target);                 
                                                                                
            me->add("kee",-(hurt_value/10));                                                 
            me->add("force",-(hurt_value/2));
        if(random(me->query_skill("superforce")+20)>random(target->query_skill("dodge")))                                                                          
        {                                                                       
                message_vision("\t\t$n的眼睛被强风刮的张不开来，[36m九天之气[0m只能照单全收，鲜血处处，伤痕累累！！\n",me,target);                                                                   
                message_vision( NOR,me);                                        
                target->receive_damage("kee",hurt_value);
                COMBAT_D->report_status(target);                                
        }                                                                       
        else                                                                    
      {                                                                         
                message_vision("$n竭力闪躲，虽避开了[37;40m风兮破地[0m强风的攻击，不过却暂时无法恢复视力。\n",me,target);
                message_vision( NOR,me);                                        
                target->start_busy(3);
                COMBAT_D->report_status(target);                                
       }                                                                        
        message_vision("[37;40m「风兮破地”[0m使出后，$N蓄势待发，风云之内劲绵绵不绝",me,target); 
        me->start_busy(1);                                                      
        function_improved("white1",random(me->query("force")/25));          
        message_vision( NOR,me);                                                
        return 1;                                                               
  }                                                                             
                                                                             
