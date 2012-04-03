// superforce.c
#include <ansi.h>
inherit SKILL;
inherit SSERVER;

int valid_enable(string usage) { return usage=="force"; }
int valid_learn(object me)
{
      
    if( me->query("max_force") < 1500 ) 
    {
        tell_object(me, "ÄãµÄÄÚÁ¦ÐÞÎª²»¹», ×îÉÙÒªÓÐÒ»Ç§Îå°Ùµã¡£\n");
        return 0;
    }

    if( !me->query("quests/white-crystal") ) 
    {
        tell_object(me, "ÄãÉÐÎ´µÃµ½»ëÌìË®¾§, Òò´ËÎÞ·¨´«ÊÚÓèÄã¡£\n");
        return 0;
    }

    // Ç°ËÄ²ãÃ»ÓÐÌØ¹¥, ¿öÇÒ±ØÐèÏÈ½â°×Ë®¾§Ö®ÄÑÌâ, Ó¦¿ª·Å.  by hana
    if( me->query("family/master_name") == "Ë¾Âí½õ" || me->query("family/master_name") == "¸ð»Ô" || me->query("family/master_name") == "Ë¾Í½ÈÙ" || me->query("family/master_name") == "Ë¾Í½Öª»ª" || me->query("family/master_name") == "ÖÜ¬Lò¯" || me->query("family/master_name") == "ÇØÒäÊ«" || me->query("family/master_name") == "¸ðÁºÇà") 
    {
      if( me->query_skill("superforce",1) < 40 )
      {
          return 1;
      }
      else
      {
          tell_object(me, "[36m¸ú°ËÎ»ÃÅÖ÷Ö»ÄÜ¹»Ñ§µ½[»ëÌì±¦¼ø]µÄµÚËÄ²ãÐÄ·¨¡£[0m\n");
          return 0;
      }
    }

    if( me->query("family/master_name") == "´«¹¦³¤ÀÏ" || me->query("family/master_name") == "Ö´·¨³¤ÀÏ" || me->query("family/master_name") == "½äÂÉ³¤ÀÏ" ) 
    {
      if( me->query_skill("superforce",1) <80)
      {
          return 1;
      }
      else
      {
          tell_object(me, "[36m¸úÈýÎ»»¤½Ì³¤ÀÏÖ»ÄÜ¹»Ñ§µ½[»ëÌì±¦¼ø]µÄµÚÎå²ãÐÄ·¨¡£[0m\n");
          return 0;
      }
    }

    if( me->query("family/master_name") == "ÂæÖ¥Ö¥" || me->query("family/master_name") == "³ÂÈÙÖÓ" || me->query("family/master_name") == "ÁÖºêÉý")
    return 1;

      //Èç¹û°ÝÍæ¼ÒÖ»ÄÜµ½80
      if( me->query_skill("superforce",1) < 100)
    {
        return 1;
    }
    else 
    {
        tell_object(me, "Ö»ÓÐ¸úÊ¥»ð½Ì½Ì»Ê»òÐÇ¾ýÑ§Ï°²ÅÄÜÑ§ÉÏÈ¥.\n");
        return 0;
    }
}

int practice_skill(object me)
{
    return notify_fail("»ëÌìÐÄ·¨Ö»ÄÜÓÃÑ§µÄ£¬»òÊÇ´Ó(exert)ÖÐ»ñµÄÊìÁ·¶È¡£\n");
}
string perform_action_file(string action)
{
    return CLASS_D("prayer")+"/superforce/"+action;
}
string exert_function_file(string func)
{
    return CLASS_D("prayer")+"/superforce/"+func;
}
string color(object me)
{
	int sk;
	sk = me->query_skill("superforce",1);
	if (sk < 31) return HIW"°×ÔÆÑÌ"NOR;
	if (sk < 41) return HIM"Ãµµ´Ï¼"NOR;
	if (sk < 51) return YEL"ÍÁÀ¥ÂØ"NOR;
	if (sk < 61) return HIC"±ÌÑ©±ù"NOR;
	if (sk < 81) return MAG"×ÏÐÇºÓ"NOR;
	if (sk < 111) return WHT"Ðþ»ìãç"NOR;
	if (sk < 151) return HIB"µå²Ôº£"NOR;
	if (sk <201 ) return HIY"½ð³¿êØ"NOR;
	if (sk <251 ) return HIR"Ñªñ·²Ô"NOR;
	return HIG"ÐþÓîÖæ"NOR;
}
