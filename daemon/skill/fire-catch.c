// fire-catch.c
#include <combat.h>
inherit SKILL;
inherit SSERVER;

mapping *action = ({
        ([      "action":               "$NÊ¹³öÊ¥»ðÆæ¹¦[1;37m¡®[31m°í[37m¡¯[0m×Ö¾÷£¬ÊÖÖÐ$wÑ¸ËÙ¿ñÉ¨Ïò$nÏÂÅÌ£¡",
                "damage":               50,
                "force":            50,
	    "dodge":		-40,
	    "parry":		-40,
	    "damage_type":	"×²ÉË"
	]),
        ([      "action":               "$NÊ¹³öÊ¥»ðÆæ¹¦[1;37m¡®[31mÅü[37m¡¯[0m×Ö¾÷£¬ÊÖÖÐ$w´Ó¿ÕÍùÏÂºÝÅüÏò$nµÄ$l£¡",
                "damage":               70,
                "force":            70,
	    "dodge":		-50,
                "parry":                    -50,
	    "damage_type":	"´¸ÉË"
	]),
        ([      "action":               "$N×ª¶¯ÊÖÖÐ$w£¬ö®Ê±[1;37m¡®[31m×ª[37m¡¯[0m×Ö¾÷Ëæ¹÷¶ø³öÉÁµç°ã»÷Ïò$nµÄ$l£¡",
                "damage":               90,
                "force":            90,
	    "dodge":		-35,
	    "parry":		-35,
	    "damage_type":	"»÷ÉË"
	]),
        ([      "action":               "$N»Ó¶¯$wÊ¹³öÊ¥»ðÆæ¹¦[1;37m¡®[31m·â[37m¡¯[0m×Ö¾÷£¬ö®Ê±Ò»Õó¹÷Óê·É»÷$nµÄ$l£¡",
                 "damage":               100,
	                "force":            100,
     "dodge":		-30,
	     "parry":		-30,
	     "damage_type":	"»÷ÉË"
        ]),
        ([      "action":               "$NÍ»È»ÉíÓ°»Î¶¯£¬Ê¹³ö[1;37m¡®[31mÌô[37m¡¯[0m×Ö¾÷£¬ÊÖÖÐ$wÓÉÏÂÍùÉÏ¶¶Ïò$nµÄ$l£¡",
                "damage":               110,
                "force":            110,
                "dodge":                -30,
                "parry":                 -30,
                "damage_type":  "´¸ÉË"
        ]),
        ([      "action":               "$NÊ¹³ö[1;37m¡®[31m´Á[37m¡¯[0m×Ö¾÷£¬Ö»¼ûÊÖÖÐ$w»¯³ÉÍÅ±ÌÓ°£¬¹÷ÓêÃÍ´ÁÏò$nµÄ$l£¡",
                "damage":               120,
                "force":            120,
                "dodge":                -25,
                "parry":                  -25,
	    "damage_type":	"×²ÉË"
        ]),
        ([      "action":               "$NÎÕ×¡$w£¬Ê¹³ö[1;37m¡®[31mÒý[37m¡¯[0m×Ö¾÷£¬¹÷Ëæ$nµÄ¹¥»÷Ë³¶øµãÍù$nµÄ$l£¡",
                "force":            150,
                "damage":               150,
                "dodge":                -20,
                "parry":                  -20,
	    "damage_type":	"×²ÉË"
        ]),
        ([      "action":               "$NÎè¶¯$wÊ¹³ö[1;37m¡®[31m²ø[37m¡¯[0m×Ö¾÷£¬Ñ¸ËÙÊ¹³öÒ»Õó¹÷ÍøÃÍ»÷$nµÄ$l£¡",
                "damage":              180,
                "force":            180,
                "dodge":                -20,
                "parry":                  -20,
                "damage_type":  "»÷ÉË"
        ]),
        ([      "action":               "$NÊÖÖÐ$wÒ»¾Ù£¬Ê¹³öÁË[1;37m¡®[31mÅ­»ð¾ÅÖØÌì[37m¡¯[0mÃàÑÓ²»¶ÏµÄÊ¹³ö¹¥Ïò$nµÄ$l",
                "damage":              200,
                "force":            200,
                "dodge":                -10,
                "parry":                  -10,
                "damage_type":  "»÷ÉË"
        ]),
});

int valid_learn(object me)
{
	if((int)me->query("str") + (int)me->query("max_force") / 5 <50)
		return notify_fail("ÄãµÄëöÁ¦»¹²»¹»£¬Ò²Ðí¸ÃÁ·Ò»Á·ÄÚÁ¦À´ÔöÇ¿Á¦Á¿¡£\n");
	return 1;
}

int valid_enable(string usage)
{
	return (usage=="stick") || (usage=="parry");
}

mapping query_action(object me, object weapon)
{
int skill_level, limit;
        skill_level=(int)me->query_skill("fire-catch", 1);
        limit=(int)skill_level/10;
        if (limit < 10)
                return action[random(limit)];
        else
                return action[random(sizeof(action))];
}

int practice_skill(object me)
{
	object weapon;
	if( !objectp(weapon = me->query_temp("weapon"))
	||	(string)weapon->query("skill_type") != "stick" )
                return notify_fail("Äã±ØÐëÊ¹ÓÃÊ¥»ð½ÌµÄÁîÅÆ»òÊÇ¡²Ê¥»ðÁî¡³£¬²ÅÄÜÊ¹ÓÃÊ¥»ðÆæ¹¦¡£\n");
	if(me->query_skill("force")*3<=me->query_skill("fire-catch",1))
          return notify_fail("ÄãµÄÄÚÁ¦¸ù»ù²»¹», ²»ÄÜÓÃÁ·Ê¥»ðÆæ¹¦ÁË¡£\n");
	if(me->query_skill("literate")*2<=me->query_skill("fire-catch",1))
          return notify_fail("ÄãµÄÖªÊ¶²»×ã£¬ÎÞ·¨½â¶ÁÊ¥»ðÁîÉÏµÄÆæÃîÎäÑ§¡£\n");
	return 1;
	if( (int)me->query("kee") < 60 )
                return notify_fail("ÄãµÄÌåÁ¦²»¹»Á·¡²Ê¥»ðÆæ¹¦¡³£¬»¹ÊÇÏÈÐÝÏ¢ÐÝÏ¢°É¡£\n");
	me->receive_damage("kee", 60);
	return 1;
}
string perform_action_file(string action)
{
        return CLASS_D("prayer")+"/fire-catch/"+action;
}
