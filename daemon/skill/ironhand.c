// ironhand.c
#include <combat.h>
#include <ansi.h>
inherit SKILL;
inherit SSERVER;

mapping *action = ({
	([	"action":"    $NÊ¹³öÌúÉ³ÕÆµÄµÚÒ»Ê½[33m¡¸¿ªÃÅÓ­±ö¡±[0m£¬Í¨ºìµÄÓÒÕÆÏò$nµÄ$lÖ±Ö±¶øÈ¥\n",
		"dodge":    -20,
		"force":    20,
		"damage":   30,
		"damage_type":	"ğöÉË"
	]),
	([	"action":"    $NÊ¹³öÌúÉ³ÕÆµÚ¶şÊ½[33m¡¸¶¯ÈçÍÑÍÃ¡±[0m£¬×óÕÆĞé»Î, ÓÒÕÆ³ÃÊÆºö»ººö¿ìµØ»÷Ïò$nµÄ
$l\n",
		"dodge":	-20,
                "force":        50,
		"damage":	40,
		"damage_type":	"ğöÉË"
	]),
	([	"action":"    $NÕĞÊ½Ò»±ä, ÌúÉ³ÕÆµÚÈıÊ½[33m¡¸×óÓÒ²»·Ö¡±[0m£¬×óÕÆÓëÓÒÕÆ»¯È­Ïò$n¹¥È¥, ´ı½Ó´¥
µ½µĞÈËÖ®Ç°Ë«È­¶¸µØ»¯ÎªË«ÕÆ, Ë³ÊÆÅÄÏò$nµÄ$l\n",
		"dodge":	-30,
                "force":        80,
		"damage":	55,
		"damage_type":	"ğöÉË"
	]),
	([	"action":"    $NÊ¹³öµÚËÄÊ½--[33m¡¸ÈçÓ°ËæĞĞ¡±[0m, É²Ê±ÕÆÓ°·­¶¯, Ò»Â·¶Ô×¼$nµÄ$l, Ê±»ú³ÉÊìºó,
ÖØ»÷¶øÏÂ\n",
		"dodge":	-40,
                "force":        100,
		"damage":	75,
		"damage_type":	"ğöÉË"
	]),
	([	"action":"    $NË«ÕÆÊ¹½«¿ªÀ´, ÕÆÆøÁèÈË£¬µÚÎåÊ½[33m¡¸Ç§¾üÍòÂí¡±[0mÒ»¾­Ê©Õ¹, ÕÆ·çºôºô³¯Ïò$nµÄ
$l²»¶ÏµØËÍ³ö\n",
		"dodge":	-40,
                "force":        120,
		"damage":	90,
		"damage_type":	"ğöÉË"
	]),
	([	"action":"    $NÏòÇ°Ò»ÆË£¬Ë«±ÛÆ½Éì, Ë«ÕÆÏòÍâ, ´ı$nÆğÕÆÀ´Ó­Ê±, ÃÍÈ»·­ÕÆÉÏÏÂºÏ»÷, 
À´ÕĞÄËÊÇÌúÉ³ÕÆÖ®µÚÁùÊ½[33m¡¸ÉÏÏÂÆëÊÖ¡±[0m, ÕÆ¾¢Ö±Í¸$nµÄ$l\n",
		"dodge":	-20,
                "force":        130,
		"damage":	105,
		"damage_type":	"ğöÉË"
	]),
	([	"action":"    $NÉíĞÎ×óÓÒÆ®¶¯£¬Ë«ÕÆĞî¾¢¶ø³ö, »÷ÔÚ¿ÕÖĞ·¢³ö[ºäºä]Ö®Éù, µĞÈËÖ®Ë¼Ğ÷ÊÜ
ÈÅ, ³Ã´ËÖ®Ê±, ÌúÉ³ÕÆµÚÆßÊ½[33m¡¸¹íÓ°´±´±¡±[0m ºó·¢ÏÈÖÁ, ×óÕÆ´ÓÏÂÈıÂ·³¯$n$lÒ»Â·Ö±½ø\n",
		"dodge":	-20,
                "force":        180,
		"damage":	115,
		"damage_type":	"ğöÉË"
	]),
	([	"action":"    $NÂí²½ÎÈÔú£¬Ë«ÍÈÇ°¹­ºó¼ı, ÆøÔËË«±Û, ÌúÉ³ÕÆÖ®µÚ°ËÊ½[33m¡¸ÆøÊÆ°õíç¡±[0mĞ®×Å
É½ºÓÖ®ÊÆ, Ïò$nÏ®¾í¶øÈ¥, $nµÄ$lµÇÊ±±»ÕÆ¾¢ËùÁıÕÖ\n",
		"dodge":	-30,
                "force":        250,
		"damage":	130,
		"damage_type":	"ğöÉË"
	]),
        ([      "action": "    [1;33mÓÉÓÚµĞÈËÍçÇ¿µÖ¿¹£¬$NÁé»úÒ»¶¯, ½«ÄÚÁ¦¹Ä´ßÆğÀ´, ÕÆ·çºôĞ¥, ÆøÁ÷·ÉÓ¿, ÌúÉ³ÕÆÖ®\n
\t\t\t\t¡®[1;31m°ËÊ½ºÏÒ»[1;33m¡¯\n
\t$N»¯³ÉÒ»ÍÅºìÉ«¹âÈ¦, ÈçÍ¬Ò»Í·¾ŞĞÜ, °ÎÉ½µ¹Ê÷¶øÀ´!!![0m\n",
                "parry":          -60,
                "dodge":          -60,
                "force":          350,
                "damage":         150,
                "damage_type":   "ğöÉË"
         ]),
});

int valid_learn(object me)
{
	object ob;

	if( (int)me->query("max_force") < 50 )
		return notify_fail("ÄãµÄÄÚÁ¦²»¹»£¬Ã»ÓĞ°ì·¨Á·ÌúÉ³ÕÆ·¨¡£\n");

	if( (string)me->query_skill_mapped("force")!= "fireforce")
		return notify_fail("ÌúÉ³ÕÆ·¨¿ÉÒÔÅäºÏÊ¥»ğÄÚ¹¦Ò»ÆğĞŞÁ·¡£\n");

        if( me->query_temp("weapon") || me->query_temp("secondary_weapon") )
        return notify_fail("ÕâÊÇÒ»Ì×ÕÆ·¨ÓÖ²»ÊÇ½£·¨»òÊÇµ¶·¨!!\n");

        if( me->query("family/master_name") != "Ë¾Í½ÈÙ" && !me->query("study/ironhand",1)  )
        return notify_fail("Ã»ÓĞË¾Í½ÈÙ±¾ÈËµÄ½Ìµ¼ÒªÔõÃ´Á·??\n");

	return 1;
}

int valid_enable(string usage)
{
	return usage=="unarmed" || usage=="parry";
}

mapping query_action(object me, object weapon)
{
int skill_level, limit;
        skill_level=(int)me->query_skill("ironhand", 1);
        limit= (int)(skill_level/9);
        if (limit < 1 )
                return action[random(1)];
        if (limit < 2 )
                return action[random(2)];
        if (limit < 3 )
                return action[random(3)];
        if (limit < 4 )
                return action[random(4)];
        if (limit < 5 )
                return action[random(4)+1];
        if (limit < 6 )
                return action[random(4)+2];
        if (limit < 8 )
                return action[random(4)+3];
        else if (limit < 10)
                return action[random(4)+4];
        else
                return action[random(sizeof(action))];
}

int practice_skill(object me)
{
	if( (int)me->query("kee") < 30
	||	(int)me->query("force") < 3 )
		return notify_fail("ÄãµÄÄÚÁ¦»òÆø²»¹»£¬Ã»ÓĞ°ì·¨Á·Ï°ÌúÉ³ÕÆ·¨¡£\n");
	me->receive_damage("kee", 30);
	me->add("force", -3);
	write("Äã°´×ÅÊ¦¸¸ËùÊÚ, Á·ÁËÒ»±éÌúÉ³ÕÆ·¨¡£\n");
	return 1;
}


