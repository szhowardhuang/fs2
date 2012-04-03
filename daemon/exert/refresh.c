// refresh.c
// refix by chan
int exert(object me, object target)
{
 int force,max_force,limit_force,value;
 limit_force=(int)me->query("max_force")/100;
 limit_force=limit_force*5;
 if(limit_force > 125)
  limit_force=125;
 if(limit_force < 5)
  limit_force=5;
 if((int)me->query("force")<20) //ÖÁÉÙÒª20ÒÔÉÏ²ÅÄÜÓÃ°É.....by chan
  return notify_fail("ÄãµÄÄÚÁ¦²»¹»¡£\n");
 if((int)me->query("force")< limit_force)
  return notify_fail("ÄãµÄÄÚÁ¦²»¹»¡£\n");
 if( target != me ) return notify_fail("ÄãÖ»ÄÜÓÃÄÚ¹¦ÊÕša×Ô¼ºµÄÐÄÉñ¡£\n");
 value=(int)me->query("max_force")/4;
 if(value<50) //±£ÕÏÐÂÊÖÌõ¿î
   value=50;
 if(value>200) //Éè¶¨ÉÏÏÞ
   value=200;
//ÒÔÉÏÐÞÕýby chan
     me->add("force", -limit_force);
 me->receive_heal("sen",value);
//ÒÔÉÏfix  by chan
//        message_vision("[36m$NÂÔÒ»ÄýÉñ£¬ÎüÁË¿ÚÆø£¬¾«Éñ¿´ÆðÀ´ÇåÐÑ¶àÁË¡£[0m\n", me);
        if( me->is_fighting() ) me->start_busy(1);
        return 1;
}
