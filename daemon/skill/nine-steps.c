// nine-steps.c

inherit SKILL;

string *dodge_msg = ({

"\n$nÕ¹ÏÖ¡®[1;31mÒÆÐÎ»ÃÓ°[0m¡¯ËÆÕæËÆ»Ã£¬ËÆ»ÃËÆÕæ£¬ÈÃ$N×½Ãþ²»¶¨,ºöÈ»Ò»¸ö×ªÉí,¾ÍÇáÒ×ÉÁ¿ª\n",

"\n$nÊ¹³ö¡®[1;32m¹í÷ÈÉí·¨[0m¡¯ÓÌÈçÒ»ÐÎÊ®Ó°£¬×··çÖðµç£¬Ñ¸ËÙÒÆÎ»£¬Çê¿ÌÈç¹í÷È°ã·Éµ½$NÉíÅÔ\n",

"\nÃæ¶Ô$NµÄ¹¥»÷£¬Ö»ÒªÖÐÈÎºÎÒ»ÕÐ£¬±ã»á½îËé¹Ç¶Ï£¬ÓÚÊÇ$nÀûÓÃ¡®[1;33m½ð²õÍÑ¿Ç[0m¡¯ÉÁ¿ª\n",

"\n$nÄýÉñÈë¶¨£¬¿ÚÖÐ†ˆ†ˆÓÐ´Ê£¬Ë²¼äÉìÊÖÒ»Ö¸·¢³ö¡®[1;34m¶¨Éí·¨[0m¡¯³¢ÊÔ°Ñ$N¸ø¶¨×¡²»¶¯£¡\n",

"\n$nÊ©Õ¹¡®[1;33m¾ÅÌìÁéÓ°Éí·¨[0m¡¯Éí·¨Ê½¡®[1;35mÓãÓÎÉí·¨[0m¡¯£¬ÉíËæÒâÐÐ£¬ËÄ·½ÓÎ×ß£¬±Ü¿ª$N¹¥»÷\n",

"\n$nÕ¹ÏÖ¡®[1;33m¾ÅÌìÁéÓ°Éí·¨[0m¡¯²ðÐ¶Ê½¡®[1;36m»³ÖÐ±§ÔÂ[0m¡¯£¬¼ûÕÐ²ðÕÐ£¬¼ûÊ½ÆÆÊ½£¬¾²¹Û$NµÄÈõµã\n",

"\n$nÊ¹³ö¡®[1;33m¾ÅÌìÁéÓ°Éí·¨[0m¡¯¹¥»÷Ê½¡®[1;31m°Ë±ÛÐ°Éñ[0m¡¯£¬Èç¿ñ·ç±©ÓêÃàÃà²»¶Ï¹¥»÷$NÓÀ²»Í£Ï¢\n",

"\n$n´ò³ö¡®[1;33m¾ÅÌìÁéÓ°Éí·¨[0m¡¯À§×¡Ê½¡®[1;35mÑÖÂÞÕÙ»½[0m¡¯£¬³öÏÖ¹í»ê£¬Éñ³ö¹íÃ»ÆËµ½$NµÄÉíºó\n",
});

int valid_enable(string usage) {
	return (usage=="dodge")||(usage=="move");

}

int valid_learn(object me)
{
	return 1;
}
string perform_action_file(string action)
{
return CLASS_D("poisoner")+"/nine-steps/"+action;
} 
string query_dodge_msg(string limb)
{
	return dodge_msg[random(sizeof(dodge_msg))];
}

int practice_skill(object me)
{
	if((int)me->query("kee")<5)
		return notify_fail("ÄãµÄÆø²»¹»£¬²»ÄÜÁ·¾ÅÌìÁéÓ°²½¡£\n");
	me->receive_wound("kee",5);
	return 1;
}
