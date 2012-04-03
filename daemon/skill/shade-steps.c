// shade-steps.c

inherit SKILL;

string *dodge_msg = ({
    "$nÉíÓ°Î¢¶¯,ÒÑ¾­½åÒ»ÕÐ¡¸[35mÐÇ¹âËÄÉ¢[0m¡±ÈÆµ½$NËÄÖÜÐÎ³ÉËÄ¸ö»ÃÓ°¡£\n",
    "$nÉíÐÎÒ»×ªÊ¹³ö¡¸[35mºìð½ÐÇ¶¯[0m¡±Ë²Ê±ÈËÀëÔ­Î»¶ø±ÜÁË¿ªÈ¥,$N»÷ÖÐÁË»ÃÓ°¡£\n",
    "Ö»¼û$nÉíÓ°Ò»»Î¼´Ê§,Ò»Ê½¡¸[35mÁ÷ÐÇ¸ÏÔÂ[0m¡±ÒÑ»Ã»¯ÔÚÈýÕÉÖ®Íâ¡£\n",
    "$nÊ¹³ö¡¸[35m¶·×ªÐÇÒÆ[0m¡±,$NÖ®¹¥ÊÆË²¼ä±»»¯½â,$n´ÓÈÝ²»ÆÈµØÉÁ¹ý¡£\n",
    "µ«$nÊ¹³öÒ»ÕÐ¡¸[35mÐÇËæÆø×ª[0m¡±,Éí×ÓËæ$N¹¥»÷Ö®ÆøÁ÷ÇáÇáÆ®ÁË¿ªÈ¥¡£\n",
    "$nÉíÐÎÎ¢»Îºö³ÉÆß¸ö»ÃÓ°,$NÀ§»ó²»ÒÑ¶ø¹¥»÷Ê§Îó,ÕýÊÇÒ»ÕÐ¡¸[35m»Ã»¯ÆßÐÇ[0m¡±¡£\n",
     "$nÈËÓ°ºöÃð,Í»¼ûÎÞÊýÐÇÃ¢»·ÈÆÔÚ$NÖÜÎ§,Ê¹$NÄ¿µÉ¿Ú´ô,²»ÖªËù´ë,ÕâÕýÊÇ »ÃÐÇ²½ ¾«»ª²½·¨-¡¸[35mÐÇÂÞÆå²¼[0m¡±¡£\n",

});

int valid_enable(string usage)
{
	return (usage=="dodge") || (usage=="move");
}

int valid_learn(object me)
{

	return 1;
}

string query_dodge_msg(string limb)
{
	return dodge_msg[random(sizeof(dodge_msg))];
}

int practice_skill(object me)
{
	if(me->query("kee") < 30 )
		return notify_fail("ÄãµÄÆø²»¹»£¬Ã»°ì·¨Á·»ÃÐÇ²½¡£\n");
	me->receive_damage("kee", 30);
	return 1;
}
