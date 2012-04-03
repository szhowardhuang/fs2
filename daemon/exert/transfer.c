// ´«ËÍÄÚÁ¦

int exert(object me, object target)
{
	if( target == me ) 
		return notify_fail("ÄãÖ»ÄÜ´«ÄÚÁ¦µÀ±ğÈËÉíÉÏ¡£\n");	
	if( !target->is_character() || !living(target) )
		return notify_fail("Õâ¶«Î÷²¢²»ÊÇ»îÎï¡£\n");
	if( target->query_skill_mapped("force") != me->query_skill_mapped("force") )
      if(!(target->query("class")=="doctor" && target->query_temp("saving_die")))
		return notify_fail("¶Ô·½ÄÚ¹¦µÄÖÖÀàÓëÄãÏàÒì, ÎŞ·¨ÊäËÍ¡£\n");
	if( target->is_fighting() || me->is_fighting() )
		return notify_fail("Õ½¶·ÖĞÎŞ·¨ÔË¹¦¡£\n");
	if( (int)me->query("force") < 100 )
		return notify_fail("ÄãµÄÄÚÁ¦²»¹»¡£\n");

	me->add("force", -100);
	target->add("force",60);
	if( target->query("force") > target->query("max_force") )
		target->set("force",target->query("max_force"));
	message_vision("[36m$N½«Ë«ÊÖÖÃÓÚ$n°Ù»áÓëëşÖĞÁ½´óÑ¨£¬Ò»¹ÉÄÚ¾¢ÓÉ$NµÄÊÖÕÆ×êÈë$nÌåÄÚ£¬Óë$n±¾ÉíÄÚÁ¦»¥ÏàÈÚºÏ¡£[0m\n", me, target);

	return 1;
}
