// lys-skill
//QC..OK..by Chan 8/29/98

inherit SKILL;


string *parry_msg=
    ({
      "$n»ØÉí³é±Þ£¬Ê¹³öÚ¤Éß±Þ·¨·ÀÓùÊ½£¬½«$NµÄ¹¥ÊÆÒ»Ò»»¯È¥\n",
      "Ö»¼û$nÉíÐÎÒ»×ª£¬Çá¶¶ÊÖÖÐ$l£¬È¦³öÒ»¸ö±Þ»¨£¬Íù$NµÄ$w¾íÈ¥\n",
      "$nÆøÔË$l£¬½«$lÎè³ÉÒ»¸öÈ¦È¦£¬»¤×¡ÉíÖÜÎå³ßÄÚ\n",
      "$n¼±Ã¦Ö®¼Ê£¬Ê¹³öÒ»ÕÐ¡®Î§Îº¾ÈÕÔ¡¯£¬½øÉíÖ±¹¥£¬±ÆµÄ$NÊÕÊÆ·ÀÊØ\n",
    });
mapping *action = ({
([ "action":"$NÊÖÖÐ$wÒ»»Ó£¬Ê¹³öÒ»ÕÐ[33m¡®½ðÉß³ö¶´¡¯[0m£¬ÆøÊÆ¾ªÈË£¬Ö±ÆË$n¶øÈ¥",
        "dodge": -20,
        "parry": 25,
        "damage": 50,
        "damage_type":  "±ÞÉË",
]),

([ "action":"$NÊ¹³öÒ»ÕÐ[35m¡®ÁéÉß°Ë·½¡¯[0m£¬$wËÆÁéÉß°ãÓÉËÄÃæ°Ë·½´òÏò$n",
        "dodge": -15,
        "parry": 35,
        "damage": 45,
        "damage_type":  "±ÞÉË",
]),

([ "action":"$NÊ¹³öÒ»ÕÐ[1;34m¡®ÁéÉßÕ§ÏÖ¡¯[0m£¬$wºöÒþºöÏÖ£¬ºö¶«ºöÎ÷£¬Áî$nÎÞ·¨×½Ãþ$NµÄ±ÞÂ·",
        "dodge": 10,
        "parry": 40,
        "damage": 40,
        "damage_type":  "±ÞÉË",
]),

([ "action":"$NÐîÊÆÒ»»Ó£¬Ê¹³öÒ»ÕÐ[31m¡®³àÁú·­½­¡¯[0m£¬ºôµÄÒ»Éù£¬ÊÖÖÐ$wÏò$nºáÉ¨¶øÈ¥",
        "dodge": -15,
        "parry": 25,
        "damage": 55,
        "damage_type":  "±ÞÉË",
]),

([ "action":"$N»Ó¶¯$w£¬Ê¹³öÒ»ÕÐ[1;33m¡®½ðÉßÍòµÀ¡¯[0m£¬ÈçÓÐÇ§°ÙÌõ½ðÉßÍ¬Ê±´ò³ö£¬Ö±ÆË$n¸÷´óÑ¨",
        "dodge": -10,
        "parry": 35,
        "damage": 60,
        "damage_type":  "±ÞÉË",
]),

([ "action":"$NÊÖÖÐ$wÒ»¶¶£¬È¦ÆðÒ»È¦È¦±Þ»¨£¬Ò»ÕÐ[1;32m¡®½ðÉß²øÉí¡¯[0m£¬Ïò$n¾íÈ¥",
	"dodge": 35,
        "parry": 50,
    "damage": 70,
        "damage_type":  "±ÞÉË",
]),

([ "action":"$NÉíÐÎÒ»Ð±£¬Ê¹³öÒ»ÕÐ[1;31m¡®Íò¹ÆÊ´ÐÄ¡¯[0m£¬¶ÙÊ±ÂúÌì±ÞÓ°£¬±ÞÊÆÐ®´øÒ»¹ÉÐÈ·çÏò$nÆËÖÁ",
        "dodge": 20,
        "parry": 45,
     "damage": 80,
        "damage_type":  "±ÞÉË",
]),

([ "action":"[1;35m$N$wÎ¢»Ó£¬Ê¹³öÒ»ÕÐ[1;36m¡®ÓÄÚ¤»Ã»¯¡¯[1;35m£¬
Ê¹±ÞÖ®¿ì²»¼û±ÞÓ°£¬Ö»ÎÅºôºôÉùÏì£¬Ð°·çÒõÉ·£¬Î§ÈÆ$nËÄÖÜ[0m",
        "dodge": 25,
        "parry": 50,
    "damage":80,
        "damage_type":  "±ÞÉË",
]),

});

int valid_enable(string usage)
{
        return usage=="whip" || usage=="parry";
}
string query_parry_msg(string limb)
{
  int parry_pow;
  object me;
  me=this_player();
  if(!me) return parry_msg[random(sizeof(parry_msg))];
        parry_pow = (int)( me->query_skill("ming-snake", 1)/10);
          if ( parry_pow < 3)
                return parry_msg[random(2)];
            else

                return parry_msg[random(sizeof(parry_msg))];
}
mapping query_action(object me, object weapon)
{
	int skill_level, limit;
	skill_level = (int)(me->query_skill("ming-snake",1));
	limit = (int)(skill_level/10);
	if(limit < 4)
		return action[random(3)];
	if(limit < 8)
		return action[random(limit)];
	else
		return action[random(sizeof(action))];
}
int vaid_learn(object me)
{
	object ob;
	if(!(ob=me->query_temp("weapon")) || (string)ob->query("skill_type")!="whip")
                return notify_fail("²»ÄÃ±ÞÔõÃ´Ñ§Ñ½!ÄãÓÐÃ»ÓÐ¸ã´í¡£\n");
	return 1;
}
int practice_skill(object me)
{
	object ob;
	if(!(ob=me->query_temp("weapon")) || (string)ob->query("skill_type")!="whip")
		return notify_fail("²»ÄÃ±ÞÈçºÎÁ·Ï°±Þ·¨¡£\n");
	if( (int)me->query("kee")< 40)
		return notify_fail("²»»áÀÛÂð? ÄãµÄÌåÁ¦²»¹»ÁË£¬»¹ÊÇÐÝÏ¢Ò»ÏÂÔÙÁ·°É¡£\n");
	if( (int)me->query("force")< 5 )
                return notify_fail("ÄãµÄÄÚÁ¦²»¹»ÁË£¬ÎÒ¿´Äã»¹ÊÇÐÝÏ¢Ò»ÏÂÔÙÁ·°É¡£\n");
	me->receive_damage("kee", 40);
	me->add("force",-5);
	return 1;
}
	
string perform_action_file(string action)
{
        return CLASS_D("poisoner")+"/ming-snake/"+action;
 }

