// regenerate.c
// ÖØÐÂÐÞÕý by chan
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
 if( target != me ) return notify_fail("ÄãÖ»ÄÜÓÃÄÚ¹¦ÌáÕñ×Ô¼ºµÄ¾«Á¦¡£\n");
   value=(int)me->query("max_force")/4;
   if(value<50) //±£ÕÏÐÂÊÖÌõ¿î
    value=50;
   if(value>200) //Éè¶¨ÉÏÏÞ
    value=200;
     me->receive_heal("gin",value);
//ÒÔÉÏÐÞÕýby chan
     me->add("force", -limit_force);
//        message_vision("[36m$NÉîÉîÎüÁË¿ÚÆø£¬ÊÖ½Å»î¶¯ÁË¼¸ÏÂ£¬Õû¸öÈË¿´ÆðÀ´ÓÐ»îÁ¦¶àÁË¡£[0m\n", me);
   if( me->is_fighting() ) me->start_busy(1);
    return 1;
}
