// recover.c

int exert(object me, object target)
{
        if(target!=me)
          return notify_fail("ÄãÖ»ÄÜÓÃÄÚ¹¦»Ö¸´×Ô¼ºµÄÁéÆø¡£\n");
        if(!me->query("sec_kee"))
	  return notify_fail("ÄãµÄÉíÉÏÃ»ÓÐÁéÆø¡£\n");
	if( (int)me->query("force") < 20 )
	  return notify_fail("ÄãµÄÄÚÁ¦²»¹»¡£\n");

        me->add("s_kee",1+(int)me->query_skill("force")/10);
        if(me->query("s_kee")>me->query("max_s_kee"))
          me->set("s_kee",me->query("max_s_kee"));
	me->add("force", -20);

//        message_vision("[36m$N½«ÌåÖÐµÄÄÚÁ¦»¯³ÉÁéÆø£¬Ê¹ÁéÆø×ªÇ¿¡£[0m\n",me);

	if( me->is_fighting() ) me->start_busy(1);

	return 1;
}
