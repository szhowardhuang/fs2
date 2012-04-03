// lum-steps.c
#include <ansi.h> 
inherit SKILL;
inherit SSERVER;          
string *dodge_msg = ({
"$nÃæÂ¶µ­µ­µÄÎ¢Ð¦£¬ÁøÑüÒ»×ª£¬Ò»ÕÐ[1;35m¡¸ÔÂ¶ùµ¹¹³¡±[0m£¬²»»Å²»Ã¦µÄÇáÇáÉÁ¹ý$NµÄÉ±×Å.\n",
"$n¿ÚÖÐÇá†ˆ[1;35m¡¸ÇáÎÊÇå·çÉù£¬ÎÅÉù²»¼ûÈË¡±[0m£¬Ò»Ë«½ðÁ«ÓÌÈç»Ã»¯Ç§°ÙË«£¬$NµÄÑÛÇ°Ë²¼ä³öÏÖºÃ
¼¸¸öÈËµÄÉíÓ°£¬²»ÖªµÀÄÄ¸ö²ÅÊÇÕæµÄ. \n",
"Ö»¼û$nÈ¹½ÇÒ»°Ú\£¬$nµÄÉíÓ°ÒÑ×ªµ½$NÉíºó£¬²¢¶Ô×Å$NÂ¶³öÇ³µÄÒ»Ð¦.\n",
"$nÇáÇáµÄÔ­µØÐý×ª£¬Îè³öÁË[1;35m¡¸Âä»¨É¢ÔÂ£¬Á÷Ë®Ò«ÐÇ¡±[0m£¬Éí×Óºö¿ìºöÂý£¬ºöÇ°ºöºó£¬ÊµÔÚÊÇÃÀ
²»Ê¤ÊÕ£¬Ö»¼û$N´ô´ôÕ¾Á¢£¬²»ÏþµÃÔÚÏëÊ²Ã´ .\n",
"$nÐä×ÓÇáÑÚ×ì½Ç£¬×óÊÖÇáÄí£¬Ò»ÕÐ[1;35m¡¸÷è÷ëÌìµØÐÐ£¬·ï»Ë¿ªÌì¼Ê¡±[0m£¬Îè³öÁËÔÂÓ°Î¢²½µÄ¾«Òå
£¬$nÉíÓ°ÇáÇáµØ´Ó$NµÄÉí±ßÆ®¹ý.\n",
"$µ«ÊÇ$n²»»Å²»Ã¦£¬×ó½ÅÇáÌ§£¬Ò»Ê½[1;35m¡¸ÌìÂí×·ÔÂ¡±[0m£¬$nµÄÉíÓ°ÒÑ³öÏÖÔÚ°ë¿ÕÖÐ£¬ÓÐÈçºûµû¡õ@°ã£¬ÇáÇáµÄÆ®ÂäÔÚ$NÉíÓ°µÄÒ»ÕÉÍâ.\n",
"ÔÂÓ°Î¢²½µÄ°ÂÒå£¬[1;35m¡¸ÐÐÕßÄª²»×¡Ò»½Å£¬Ìý¾ýÇá³ªÊËÅ®Òô¡±[0m£¬ÔÚ$nµÄÎè¶¯ÏÂ£¬ÓÐÈçÒ»¶äÊ¢¿ªµÄ
ÏÊ»¨£¬ÏÊÑÞµÄ²Êµû.\n"
});
 
int valid_skill_usage(string usage)
{
        return (usage=="dodge") || (usage=="move");
}
 int valid_enable(string usage)
 {
        return( usage=="dodge" || usage=="move") ;
 }
 
int valid_learn(object me)
{
        if( (int)me->query("max_force") < 10 )
                return notify_fail("ÄãµÄÄÚÁ¦²»¹»£¬Ã»ÓÐ°ì·¨ÐÞÁ¶ÔÂÓ°Î¢²½ .\n");
 
        return 1;
}
string perform_action_file(string action)
{
return CLASS_D("dancer")+"/paull-steps/"+action;
} 
string query_dodge_msg(string limb)
{
        return dodge_msg[random(sizeof(dodge_msg))];
}
 
int practice_skill(object me)
{
        if( (int)me->query("kee") < 30
        ||      (int)me->query("force") < 5 )
                return notify_fail("ÄãµÄÆø»òÄÚÁ¦²»¹»£¬²»ÄÜÁ·ÔÂÓ°Î¢²½ .\n");
        me->receive_damage("kee", 30);
        me->add("force", -3);
        return 1;
}
