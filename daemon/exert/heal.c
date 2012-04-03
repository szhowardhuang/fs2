// ¸ø»ù±¾ force
#define ALLOW ({"fighter","bonze","prayer","doctor"})
int exert(object me,object target)
{
	int power;
int max=me->query("max_kee",1);
int maxt;
if(target)
maxt=target->query("max_kee",1);
	if( (int)me->query("force") < 30 )
		return notify_fail("ÄãµÄÄÚÁ¦²»¹»¡£\n");
	if( me->is_fighting() || target->is_fighting() )
		return notify_fail("Õ½¶·ÖÐÎÞ·¨ÁÆÉË¡£\n");
    if( member_array(me->query("class"), ALLOW) == -1 && !wizardp(me))
		return notify_fail("ÄãµÄÖ°ÒµÎÞ·¨ÁÆÉË¡£\n");
if(me->query("eff_kee")==max && !target)
return notify_fail("ÄãÃ»ÓÐÊÜÉË¡£\n");
if(target)
  if(target->query("eff_kee") >= maxt)
    return notify_fail(target->query("name")+"Ã»ÓÐÊÜÉË\n");
      if(me->query_condition("mogi"))
        return notify_fail("[1;32mÉíÉÏµÄÈëÃðÖ®¶¾ºöÈ»·¢×÷,Ê¹ÄÚÏ¢ÊÜµ½Ó°ÏìÎÞ·¨ÔËÆøÁÆÉË[0m\n");
       if(target->query_condition("mogi"))
        return notify_fail("[1;32m¶Ô·½ÉíÉÏµÄÈëÃðÖ®¶¾,Ê¹ÄãÎÞ·¨°ïËûÔËÆøÁÆÉË[0m\n");
        power = 5 + (int)me->query_skill("force")/10;
	if( target==me ){
		message_vision("[36m$NÅÌÍÈÏ¯µØ¶ø×ø£¬ÔËÐÐÈ«ÉíÄÚÁ¦ÁÆÉË£¬Ò»Õó°×Æø´Ó$NÍ·¶¥Ã°³öºó, ÉËÊÆÒÑÂýÂý×ªºÃ¡£[0m\n", me);
	}
	else{
		message_vision("[36m$NÅÌÍÈÏ¯µØ¶ø×ø£¬ÔËÐÐÈ«ÉíÄÚÁ¦°ïÖú$nÁÆÉË, Ò»Õó°×Æø´ÓÍ·¶¥Ã°³öºó, $nÉËÊÆÒÑÂýÂý×ªºÃ¡£[0m\n", me, target);
                power = power/2;
	}
        me->receive_curing("kee", power );
    if(target)
      if(target != me) target->receive_curing("kee",power);
	me->add("force", -30);
	return 1;
}
