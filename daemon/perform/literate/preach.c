// preach.c by Onion
// ÖØÐÂQC¼°ÐÞÕýby chan
// By Swy ×îºóÐÞÕý QC 98/6/21
inherit SSERVER;
int perform(object me, object target)
{
	string *ATTACK_MSG=({
	"$N·¢»ÓÊéÉúµÄ±¾É«¿ªÊ¼¶Ô$nÑµÊ¾¡¸ÔøÊÏ¼ÒÑµ¡±µÄÒâÒå¡£",
	"$N¿ªÊ¼ÌÏÌÏ²»¾ø¶Ô$n½²½â¡¸Èý×Ö¾­¡±µÄ´óÒâ¡£",
	"$N·­¿ªËæÉíÐ¯´øµÄ¡¸ÂÛÓï¡±, ¶Ô$n½²Êö¿××ÓµÄÖ¾Ïò¡£",
	"$N¿à¿ÚÆÅÐÄµÄÈ°µ¼$nÒªÁ¢Ö¾ÏòÉÆ, ×ö´óÊÂ, ³É´óÒµ¡£",
	"$N´Ó±³ºóÌÍ³ö±Þ×Ó¶Ô$n¿ÖÏÅËµ: ²»Ìý»°Òª´¦ÒÔ¡¸ÔÝÊ±ÐÔÌÛÍ´¡±µÄ´¦·¨à¸¡£",
	"$N¿ªÊ¼¶Ô$nÀÊËÐ¡¸°Ù¼ÒÐÕ¡±¡¢¡¸Ç§×ÖÎÄ¡±¸÷Ò»±é¡£"
	});
	int action=random(sizeof(ATTACK_MSG));
	if( target == me )
	  return notify_fail("²»ÄÜ¶Ô¸¶×Ô¼ºÑ½!!\n");
	if( !target )
	if( !target = offensive_target(me) )
		return notify_fail("Ã»ÓÐÕâ¸ö¶ÔÏó¡£\n");
	if( target->query_temp("preach") )
	  return notify_fail("ÕâÕÐÃ»ÓÃÁË¡£\n");
if( me->query("water") < 20)
	  return notify_fail("ÄãµÄ'¿ÚË®'×¼±¸²»¹»à¸¡£\n");
	if( me->query("force") <= 0 )
	  return notify_fail("ÄãµÄÄÚÁ¦²»¹»¡£\n");
	if( !me->query_skill("literate") )
          return notify_fail("ÏÈÑ§µã»ù±¾µÄÑ§Ê¶¡£\n");
        if( !me->is_fighting() )
	  return notify_fail("Õ½¶·ÖÐÑµÊ¾¶Ô·½±È½ÏÓÐÐ§à¸¡£\n");
        message_vision("\n[36m"+ATTACK_MSG[action]+"[0m\n\n",me,target);
	target->set_temp("preach",1);
     if(target->is_busy())
       return notify_fail("µÐÈË²»ÄÜ¶¯¿ì¹¥»÷Å¶!!!\n");
	target->start_call_out( (: call_other, __FILE__, "do_result",me,target :),3);
	return 1;
}
void do_result(object me,object target)
{
	if( target->query("race") != "ÈËÀà" )
	  message_vision("$NµÉ×ÅÒ»Ë«´óÑÛ¾¦ºÃÆæµÄÍû×Å$n¡£\n",target,me);
	else
	  if( random(3) > 0 )
          {
	    message_vision("[1;36m$NË«ÊÖ±§×ÅÍ·´ó½Ð: °¢~~....ÏÔÈ»ÊÜ²»ÁË$nµÄÄ§Òô¡£\n[0m",target,me);
     target->start_busy(2);
	  }
	  else
	    message_vision("$NË¿ºÁ²»ÊÜÓ°Ïì..\n",target);
    me->start_busy(1);
}
