#include <combat.h>
#include <ansi.h>
inherit SKILL;
void hurt(object me, object victim, object weapon, int damage);
void block(object me, object victim, object weapon, int damage);
void conti(object me, object victim, object weapon, int damage);
void sp1(object me, object victim, object weapon, int damage);
void sp2(object me, object victim, object weapon, int damage);
void sp3(object me, object victim, object weapon, int damage);
void sp_attack(object me, object victim, object weapon, int damage);
void sp_attack1(object me, object victim, object weapon, int damage);
mapping sp_action(object me,object weapon);
string *sword_name=({
    "ÉÙÉÌ½£·¨",
    "ÉÌÑô½£·¨",
    "ÖĞ³å½£·¨",
    "¹Ø³å½£·¨",
    "ÉÙ³å½£·¨",
    "ÉÙÔó½£·¨",
});

string *attack =({
//ÉÙÉÌ½£·¨ 0~4
"$NÄ´Ö¸Ò»Äé£¬ÌåÄÚÕæÆøÁ÷×ª£¬Ê¹³ö"HIW"¡®ÉÙÉÌ½£¡¯"NOR"ÖĞµÄ"HIY"¡®´©ÔÆÁÑÊ¯¡¯"NOR"£¬ÆäĞÛ¾¢µÄ½£Â·£¬°ÔµÀµÄÏò$n¼¤Éä¶øÈ¥£¬ÆÄÓĞÊ¯ÆÆÌì¾ª£¬·çÓê´óÖÁÖ®ÊÆ",
"$N¾¢Í¸Ö¸¼â£¬Ê¹³öÒ»ÕĞ"HIG"¡®ÔÀÖÅÔ¨œs¡¯"NOR"£¬Ò»µÀĞÛ»ë½£ÆøÖ±´Ì$n£¬ÆäÑÏ½÷ÖĞÕıÖ®×Ë£¬Õı·ûºÏ"HIW"¡®ÉÙÉÌ½£¡¯"NOR"´ó¿ª´óãØ£¬ÆøÅÉĞÛÎ°µÄ½£Òâ",
"$NÄ´Ö¸Ğé»®£¬Ê¹³ö"HIR"¡®"HIY"ÔÆ¿ª¼ûÔÂ"HIR"¡¯"NOR", ÉíĞÎÒ»×ª,Ö¸¼âåÉÏò$n¼±µã¡£",
"$NÉíĞÎÌÚ¿Õ¶øÆğ, Ä´Ö¸Ö¸¼âÎ¢²ü,³¯$nµãÀ´, ÕıÊÇÒ»ÕĞ"HIG"¡®"HIC"òßòÑµãË®"HIG"¡¯"NOR"¡£",
"$NÄ´Ö¸½£ÆøºöÈ»¹âÃ¢ËÄÉä£¬ÉíĞÎ¼±×ª£¬Ê¹³öÒ»ÕĞ"HIR"¡®"HIY"Á÷ĞÇ×·ÔÂ"HIR"¡¯"NOR"£¬Íù$n¹¥È¥¡£",
//ÉÌÑô½£·¨ 5~9
"$NË«Ö¸Æë³ö£¬Á½¹ÉÎŞĞÎ½£Æø»¥Ïà¼¤µ´£¬Ö±±¼$n¶øÈ¥£¬ÕıÊÇ"HIW"¡®ÉÌÑô½£¡¯"NOR"ÖĞµÄ¾øÕĞ"HIR"¡®ÈÕÔÂÍ¬Ò«¡¯"NOR,
"$NÉíĞÎ¶·×ª£¬Ò»ÕĞ"HIC"¡®Îí¾íÔÆÓ¿¡¯"NOR"»Ã»¯³öÎŞÊıÉíÓ°£¬$n¶ÙÊ±ÁıÕÖÔÚ"HIW"¡®ÉÌÑô½£¡¯"NOR"ÎŞĞÎ½£ÆøÖ®ÏÂ",
"$NÆøÈôÄıÔ¨, »¯ÇÉÎª×¾,Ö¸¼âÍùÇ°Æ½Ö¸, Ê¹³öÁË"HIM"¡®ÅÌÁú³ö¹È¡¯"NOR"¡£",
"$N½£×ßÁéÇÉ, Éí·¨ºö±ä,Ò»ÕĞ[1;37m¡®[1;30mĞé¿ÕÒ¹[1;33mÔÂ[1;37m¡¯[0mÊ¹½«³öÀ´, ËÄÖÜ½ÔÊÇÉíÓ°¡£",
"$NÊ¹³ö[1;37m¡®[1;35m»³ÖĞ±§[1;33mÔÂ[1;37m¡¯[0m, ÊÖÖĞ½£¼âÎ¢²ü,Ğı¼´»Ã»¯³öÊı¶ä½£»¨, ½«$nÁıÕÖÔÚ½£ÓêÖ®ÏÂ¡£",
//ÖĞ³å½£·¨ 10~14
"$NÌ¹È»µØµ¯³öÖĞÖ¸£¬Ê¹³ö"HIC"¡®ÖĞ³å½£¡¯"NOR"ÖĞµÄ"CYN"¡®Ç§¹ÅÈËÁú¡¯"NOR"£¬Æä½£ÊÆ´ó¿ª´óãØ£¬ÓĞÈçÌìÍâ·ÉÁú°ã£¬½£ÆøÁèÀ÷µØ³¯Ïò$n¶øÈ¥",
"$NÉì³öÖĞÖ¸£¬Ò»ÕĞ"HIW"¡®ÖĞ³å½£¡¯"HIB"¡®À×Õğ¾ÅÖØÌì¡¯"NOR"ÉäÏò$n£¬ÆäÉùÊÆÈçÂäÀ×¾ªÌì£¬½ĞÈË²»¸Ò±ÆÊÓ",
"$N×óÊÖÄó¸ö½£¾÷, Æ½ÍÆ¶ø³ö,¾÷Ö¸ÉÏÑö, ÓÒÊÖÖĞÖ¸³¯Ìì²»¶¯,ÕıÊÇÒ»ÕĞ[1;37m¡®[1;34mÏÈÈËÖ¸Â·[1;37m¡¯[0m¡£",
"$NÃæÂ¶Î¢Ğ¦, ÑöÊÓ²ÔÌì,Ê¹³ö[1;37m¡®Äí[1;31m»¨[1;37mÎ¢Ğ¦¡¯[0m, µ«¼û½£¹âÉÁÉÁ£¬³¯$n¿ñ¹¥¶øÈ¥¡£",
"$N´éÖ¸³Éµ¶£¬ºöµØÒ»ÕĞ"+HIY+"¡¸ÁúĞ¥¾ÅÌì¡±"+NOR+", ÖĞÖ¸ÓÉÏÂ¶øÉÏµÄ¿³Ïò$n£¬Òò¿³Ï÷¿ÕÆøËùĞÎ³ÉµÃÂİäöÆøÁ÷Èç¿ñ·ç°ã¹¥Ïò$n¡£",
//¹Ø³å½£·¨ 15~19
"$N»º»ºµÄÉì³öÎŞÃûÖ¸£¬¡¸Ë¿Ë¿¡±ÉùÆğ£¬ÕıÊÇ"HIW"¡®¹Ø³å½£¡¯"NOR"ÖĞµÄ"HIY"¡®×³Ö¾ÁèÔÆ¡¯"NOR"£¬Æä×¾ÖÍ¹ÅÆÓµÄ½£ÊÆÁıÕÖ×¡$nÈ«Éí£¬Ö±Ö±µÄÍù$n×²È¥  ",
"$NÇ±ÔËÄÚÁ¦£¬ÒÔ¾²ÖÆ¶¯£¬Ò»ÕĞ"HIG"¡®Ê±Óê´º·ç¡¯"NOR"Ö¸Ïò$nÕıÃæÈıÊ®Áù´óÑ¨£¬ÆäÊÆ¹ÅÆÓ£¬ÕıÊÇ"HIW"¡®¹Ø³å½£¡¯"NOR"ÀïµÄ¸ßÕĞ",
"$NºöÈ»ÏòÇ°´ó¿çÒ»²½£¬Ò»¹ÉÅÓ´óµÄÉ±Æø´Ó$NÉíÉÏÓ¿³ö£¬$N´óºÈÒ»Éù"+HIR+"¡¸É±ÁúÇóµÀ¡±"+NOR+"£¬»ôµØĞıÉí¶øÆğ£¬ÆøËæÉí×ª£¬Ğı·ç°ã³¯$nÃÍ¹¥¡£",
"$N½«½£ÆøÑÓÉê²åÈëµØÃæ£¬ÉíĞÎ¼±×ª£¬´óºÈÒ»Éù"+HIY+"¡¸Ç±ÁúÉıÌì¡±"+NOR+"£¬ÎŞÃûÖ¸½£Æø´øÆğÁËÒ»ÕóÉÏÉıÆøÁ÷£¬·Â·ğÒª½«ËÄÖÜµÄÒ»ÇĞÈ«²¿¾íµ½¿ÕÖĞËÆµÄ",
"$N´óºÈÒ»ÉùÊ¹³ö"HIG"¡¸·å»ØÂ·×ª¡±"NOR"£¬ÎŞÃûÖ¸½£ÆøÈçÒ»ÌõÒøÉß°ã´ÌÏò$n",
//ÉÙ³å½£·¨ 20~24
"$NĞ¡Ö¸ÁéÇÉµÄ×ª¶¯£¬Ò»ÕĞ"HIW"¡®ÉÙ³å½£¡¯"HIR"¡®Ñ©Äàºè×¦¡¯"NOR"µó×êµÄ³¯$n·ÉÈ¥£¬ÆäÊÆ¹îÆæ£¬½ĞÈË×½Ä£²»¶¨",
"$NÒ»ÕĞ"HIW"¡®ÉÙ³å½£¡¯"NOR"´ÌÏò$nĞØ¿Ú£¬ÉĞÓĞĞí³ß£¬Ò»Ğ±Éí£¬Ğ¡Ö¸»Ø×ª£¬Ïò$nÏ÷Âä£¬ÕıÊÇÁùÂöÉñ½£ÀïµÄÃîÕĞ"HIM"¡®·Ö»¨·÷Áø¡¯"NOR,
"$NÉíĞÎÓĞÈçÍÓÂİ°ãĞı×ªÆğÀ´£¬Ò»ÕĞ"HIW"¡®ÉÙ³å½£¡¯"HIY"¡®ºéÁ÷ÎŞÏŞ¡¯"NOR"£¬½£ÆøÓĞÈç¼ı°á²»¶ÏµÄ³¯$n¹¥È¥¡£",
"$N½Å²ÈÆæ²½£¬ºöÈ»ÈÆµ½ÁË$nµÄ±³ºó£¬Ò»ÕĞ"HIW"¡®ÉÙ³å½£¡¯"HIG"¡®Áø°µ»¨Ã÷¡¯"NOR"Íù$n±³ĞÄ´óÑ¨¼±¹¥¶øÈ¥¡£",
"$NÑÛÉä¾«¹â£¬ÉíĞÎÒ»×ª¼±ÔËĞ¡Ö¸½£Æø£¬Ò»ÕĞ"HIW"¡®ÉÙ³å½£¡¯"HBRED+HIY"¡®¿Õ¹ÈÇïºç¡¯"NOR"»­³öÒ»µÀ¹â»¡Õ¶Ïò$n",
//ÉÙÔó½£·¨ 25~29
"$NÇáÇÉµÄ×ª¶¯Ğ¡Ö¸£¬Ê¹³öÒ»ÕĞ"HIC"¡®·ÉÑã»ØÏè¡¯"NOR"£¬Ö»¼û"HIY"¡®ÉÙÔó½£¡¯"NOR"ºöÀ´ºöÈ¥£¬ÓĞÈçÁéÉß°ãµÄĞ±Éä$n",
"$NÕ¹¿ª¼ÜÊ½£¬Éí·¨ÇáÁé£¬ÎŞĞÎ½£Æø×óÒ»¹Õ£¬ÓÒÒ»Íä£¬Ô½×ªÔ½¼±£¬ğÍÈ»¼äÒ»½£´ÌÏò$n£¬ÕıÊÇ"HIY"¡®ÉÙÔó½£¡¯"NOR"ÖĞµÄÆæÕĞ"HIW"¡®·Ç¼Ù·Ç¿Õ¡¯"NOR,
"$NÁ³É«ºö°×ºöºì£¬Ö»¼û$NĞ¡Ö¸½£ÆøÔ½À´Ô½ÁÁ£¬Ò»ÕĞ"HIY"¡®ÉÙÔó½£¡¯"HIY"¡®ÆøÓÎÌìµØ¡¯"NOR"£¬´ÌÏò$n¡£",
"$NĞ¡Ö¸Ğé»®Ê®×Ö£¬½«½£ÆøÄı¾ÛĞØÇ°£¬Ò»ÕĞ"HIY"¡®ÉÙÔó½£¡¯"BLINK+HIR"¡®Ê®·½¾ãÃğ¡¯"NOR"£¬½£ÆøÓĞÈçÅÅÉ½µ¹º£³¯$n¹¥È¥¡£",
"$NÌÚÉí¶øÆğ£¬Ğ¡Ö¸½£Æø¾Û¶ø²»É¢£¬Éí×ÓÓĞÈç¼ıÒ»°ãµÄ³¯$nÖ±Éä¶øÈ¥£¬ÕıÊÇ"HIY"¡®ÉÙÔó½£¡¯"NOR"Ö®"BLINK+HIC"¡®½ğ¹âĞ¹µØ¡¯"NOR,
});




mapping *action = ({

//1
([ "action":
"$NÄ´Ö¸Ò»Äé£¬ÌåÄÚÕæÆøÁ÷×ª£¬Ê¹³ö"HIW"¡®ÉÙÉÌ½£¡¯"NOR"ÖĞµÄ"HIY"¡®´©ÔÆÁÑÊ¯¡¯"NOR"£¬ÆäĞÛ¾¢µÄ½£Â·£¬°ÔµÀµÄÏò$n$l¼¤Éä¶øÈ¥£¬ÆÄÓĞÊ¯ÆÆÌì¾ª£¬·çÓê´óÖÁÖ®ÊÆ",
        "dodge": -30,
        "parry": -20,
        "damage": 100,
        "force":  100,
        "damage_type":  "´ÌÉË",
        "weapon": "Ä´Ö¸½£Æø",
]),

//2
([ "action":
"$N¾¢Í¸Ö¸¼â£¬Ê¹³öÒ»ÕĞ"HIG"¡®ÔÀÖÅÔ¨œs¡¯"NOR"£¬Ò»µÀĞÛ»ë½£ÆøÖ±´Ì$n$l£¬ÆäÑÏ½÷ÖĞÕıÖ®×Ë£¬Õı·ûºÏ"HIW"¡®ÉÙÉÌ½£¡¯"NOR"´ó¿ª´óãØ£¬ÆøÅÉĞÛÎ°µÄ½£Òâ",
        "dodge": -30,
        "parry": -20,
        "damage": 100,
        "force":  100,
        "damage_type":  "´ÌÉË",
        "weapon": "Ä´Ö¸½£Æø",
]),

//3
([ "action":
"$NË«Ö¸Æë³ö£¬Á½¹ÉÎŞĞÎ½£Æø»¥Ïà¼¤µ´£¬Ö±±¼$n$l¶øÈ¥£¬ÕıÊÇ"HIW"¡®ÉÌÑô½£¡¯"NOR"ÖĞµÄ¾øÕĞ"HIR"¡®ÈÕÔÂÍ¬Ò«¡¯"NOR,
        "dodge": -40,
        "parry": -15,
        "damage": 150,
        "force": 150,
        "damage_type": "´ÌÉË",
        "weapon": "Ê³Ö¸½£Æø",
]),

//4
([ "action":
"$NÉíĞÎ¶·×ª£¬Ò»ÕĞ"HIC"¡®Îí¾íÔÆÓ¿¡¯"NOR"»Ã»¯³öÎŞÊıÉíÓ°£¬$n¶ÙÊ±ÁıÕÖÔÚ"HIW"¡®ÉÌÑô½£¡¯"NOR"ÎŞĞÎ½£ÆøÖ®ÏÂ",
        "dodge": -40,
        "parry": -15,
        "damage": 150,
        "force": 150,
        "damage_type": "´ÌÉË",
        "weapon": "Ê³Ö¸½£Æø",
]),

//5
([ "action":
"$NÌ¹È»µØµ¯³öÖĞÖ¸£¬Ê¹³ö"HIW"¡®ÖĞ³å½£¡¯"NOR"ÖĞµÄ"CYN"¡®Ç§¹ÅÈËÁú¡¯"NOR"£¬Æä½£ÊÆ´ó¿ª´óãØ£¬ÓĞÈçÌìÍâ·ÉÁú°ã£¬½£ÆøÁèÀ÷µØ³¯Ïò$n$l¶øÈ¥",
        "dodge": -35,
        "parry": -20,
        "damage": 200,
        "force": 200,
        "damage_type": "´ÌÉË",
        "weapon": "ÖĞÖ¸½£Æø",
        "post_action": (: block :),
]),

//6
([ "action":
"$NÉì³öÖĞÖ¸£¬Ò»ÕĞ"HIW"¡®ÖĞ³å½£¡¯"BLU"¡®À×Õğ¾ÅÖØÌì¡¯"NOR"ÉäÏò$n$l£¬ÆäÉùÊÆÈçÂäÀ×¾ªÌì£¬½ĞÈË²»¸Ò±ÆÊÓ",
        "dodge": -35,
        "parry": -20,
        "damage": 200,
        "force": 200,
        "damage_type": "´ÌÉË",
        "weapon": "ÖĞÖ¸½£Æø",
        "post_action": (: block :),
]),

//7
([ "action":
"$N»º»ºµÄÉì³öÎŞÃûÖ¸£¬¡¸Ë¿Ë¿¡±ÉùÆğ£¬ÕıÊÇ"HIW"¡®¹Ø³å½£¡¯"NOR"ÖĞµÄ"HIY"¡®×³Ö¾ÁèÔÆ¡¯"NOR"£¬Æä×¾ÖÍ¹ÅÆÓµÄ½£ÊÆÁıÕÖ×¡$nÈ«Éí£¬Ö±Ö±µÄ×²ÏòÆä$l  ",
        "dodge": 25,
        "parry": 0,
        "damage": 250,
        "force": 250,
        "damage_type": "´ÌÉË",
        "weapon": "ÎŞÃûÖ¸½£Æø",
]),

//8
([ "action":
"$NÇ±ÔËÄÚÁ¦£¬ÒÔ¾²ÖÆ¶¯£¬Ò»ÕĞ"HIG"¡®Ê±Óê´º·ç¡¯"NOR"Ö¸Ïò$nÕıÃæÈıÊ®Áù´óÑ¨£¬ÆäÊÆ¹ÅÆÓ£¬ÕıÊÇ"HIW"¡®¹Ø³å½£¡¯"NOR"ÀïµÄ¸ßÕĞ",
        "dodge": 25,
        "parry": 0,
        "damage": 250,
          "force": 250,
        "damage_type": "´ÌÉË",
        "weapon": "ÎŞÃûÖ¸½£Æø",
]),

//9
([ "action":
"$NĞ¡Ö¸ÁéÇÉµÄ×ª¶¯£¬Ò»ÕĞ"HIW"¡®ÉÙ³å½£¡¯"HIR"¡®Ñ©Äàºè×¦¡¯"NOR"µó×êµÄ³¯$n$l·ÉÈ¥£¬ÆäÊÆ¹îÆæ£¬½ĞÈË×½Ä£²»¶¨",
        "dodge": -50,
        "parry": -20,
        "damage": 300,
        "force": 300,
        "damage_type": "´ÌÉË",
        "weapon": "Ğ¡Ö¸½£Æø",
        "post_action": (: hurt :),
]),

//10
([ "action":
"$NÒ»ÕĞ"HIW"¡®ÉÙ³å½£¡¯"NOR"´ÌÏò$nĞØ¿Ú£¬ÉĞÓĞĞí³ß£¬Ò»Ğ±Éí£¬Ğ¡Ö¸»Ø×ª£¬Ïò$n$lÏ÷Âä£¬ÕıÊÇÁùÂöÉñ½£ÀïµÄÃîÕĞ"HIM"¡®·Ö»¨·÷Áø¡¯"NOR,
        "dodge": -50,
        "parry": -20,
        "damage": 300,
        "force": 300,
        "damage_type": "¸îÉË",
        "weapon": "Ğ¡Ö¸½£Æø",
]),

//11
([ "action":
"$NÇáÇÉµÄ×ª¶¯Ğ¡Ö¸£¬Ê¹³öÒ»ÕĞ"HIC"¡®·ÉÑã»ØÏè¡¯"NOR"£¬Ö»¼û"HIW"¡®ÉÙÔó½£¡¯"NOR"ºöÀ´ºöÈ¥£¬ÓĞÈçÁéÉß°ãµÄĞ±Éä$n$l",
        "dodge": -50,
        "parry": -20,
        "damage": 250,
        "force": 250,
        "damage_type": "´ÌÉË",
        "weapon": "Ğ¡Ö¸½£Æø",
]),

//12
([ "action":
"$NÕ¹¿ª¼ÜÊ½£¬Éí·¨ÇáÁé£¬ÎŞĞÎ½£Æø×óÒ»¹Õ£¬ÓÒÒ»Íä£¬Ô½×ªÔ½¼±£¬ğÍÈ»¼äÒ»½£´ÌÏò$n$l£¬ÕıÊÇ"HIW"¡®ÉÙÔó½£¡¯"NOR"ÖĞµÄÆæÕĞ"HIW"¡®·Ç¼Ù·Ç¿Õ¡¯"NOR,
        "dodge": -50,
        "parry": -20,
        "damage": 250,
        "force": 250,
        "damage_type": "´ÌÉË",
        "weapon": "Ğ¡Ö¸½£Æø",
        "post_action": (: hurt :),
]),

//13
([ "action":
HIW"$N´óºÈÒ»Éù£¬¹Ä¶¯È«ÉíÕæÆø£¬ÄÚ¾¢Á÷×ª£¬Ë«ÊÖÁù½£Æë·¢£¬Ê®Ö¸·Öµ¯£¬ö®Ê±½£Æø×İºá£¬ËÆÓĞÎŞÊıÑ¸À×¼²·ç»¥³å¼¤µ´Ïò$n¶øÈ¥"NOR,
        "dodge": -50,
        "parry": -20,
        "damage": 300,
        "force": 300,
        "damage_type": "´ÌÉË",
        "weapon": "ÎŞĞÎ½£Æø",
        "post_action": (: conti :),
]),

//14°ÂÒå(Ò»)
([ "action":
HIY"\n$NÑÛÖĞ¾«¹â´óÊ¢£¬´óºÈ:\n\n"
HIW"             ¡®\n"
HIR"                ¶áÃü"HIW"¡«"HIG"Á¬»·"HIW"¡«"HIM"Áù¾ø½£"HIW"!!\n"
"                                     ¡¯\n"
"$NÍ»È»¼±ÔË¡®Ò»ÑôĞÄ·¨¡¯£¬Æø¾¢ÂúÓ¯£¬Ò»¸ö¼ı²½£¬Ïò$n×İÉí·ÉÈ¥\n"NOR,
        "dodge": 80,
        "parry": 50,
        "damage": 300,
        "force": 300,
        "damage_type": "´´ÉË",
        "post_action": (: sp1 :),
]),

//15°ÂÒå(¶ş)
([ "action":
HIY"\n$N»º»ºÄîµÀ:\n\n"NOR
GRN"                   ¡® Á½½ÅÌ¤·­³¾ÊÀÂ·£¬Ò»¼çµ£¾¡¹Å½ñ³î ¡¯\n\n"
HIW"ÅäºÏ¡®Áè²¨Î¢²½¡¯µÄ¾«Ãî²½·¨£¬»Ã»¯³ÉÎŞÊıÈËÓ°°üÎ§$n£¬Ë«ÊÖ¼²Éä£¬Áù½£Æë·¢£¬ö®Ê±
¼ä$nÏİÈëÎŞĞÎ½£ÆøµÄ¿ñÂÒ½£ÍøÖ®ÖĞ£¬½£Æø¼¤µ´£¬¾¹ÊÇÒª½«$nÈ«ÉíËºÁÑ£¬´ËÕĞÕıÊÇ
´óÀí¶ÎÊÏµÄ½ûÓÃÉ±ÕĞ\n\n"
"                         ¡« "HIY" ÎŞ"HIM" ³£"HIW" £®"RED" ºŞ"HIC" ²Ô"BLU" Ìì "HIW" ¡«\n\n"NOR,
        "dodge": 80,
        "parry": 50,
        "damage": 300,
          "force": 300,
        "damage_type": "´ÌÉË",
        "post_action": (: sp2 :),
]),


//16°ÂÒå(Èı)
([ "action":
HIY"\n$N»ØÉíÊÕ²½³¤Ò÷µÀ:\n\n"NOR
YEL"                   ¡® Ã÷ÔÂ¸¡ÔÆÏà°ëÑÚ£¬ÆßĞÇ²»ÂäÒ«³¤¿Õ ¡¯\n\n"
HIW"ºöÈ»¼ä¸ß¸ßÔ¾Æğ£¬ÉíĞÎÑÚ¿Õ£¬×óÕÆ¸§ĞØ£¬ÓÒÊÖÁ¬·¢ÆßµÀÎŞĞÎ½£Æø£¬¼²Ïò$nÖÜÉíÒªÑ¨¶ø
È¥£¬»è°µÖ®ÖĞ£¬Ö»¼ûÆßµÀ½£Ã¢½ğ¹âÒ«ÑÛ£¬ÄËÊÇ´óÀí¶ÎÊÏÁùÂöÉñ½£ÖĞµÄ¾øÑ§\n\n"
"                           ¡«"HIM" Æß"HIY" ĞÇ"HIC" Âä"HIG" ³¤"HIR" ¿Õ"HIW" ¡«\n\n"NOR,
        "dodge": 80,
        "parry": 50,
        "damage": 300,
        "force": 300,
        "damage_type": "´ÌÉË",
        "post_action": (: sp3 :),
]),
//17ÉÙÉÌ½£·¨
([ "action":
"$N"HIR"Ê¹³öÁùÂöÉñ½£ÖĞµÄ¡®ÉÙÉÌ½£·¨ ¡¯£¬Ä´Ö¸½£ÆøÓĞÈçÊµÖÊ£¬Íù"NOR"$n"HIR"¹¥È¥¡£"NOR,
                "dodge"      :               -100,
                "parry"      :               -100,
                "damage"     :                330,
                "force"      :                330,
                "post_action":                (: sp_attack :),
                "damage_type":               "´ÌÉË"
]),
//18ÉÌÑô½£·¨
([ "action":
"$N"HIY"Ê¹³öÁùÂöÉñ½£ÖĞµÄ¡®ÉÌÑô½£·¨ ¡¯£¬Ê³Ö¸½£ÆøÓĞÈçÊµÖÊ£¬Íù"NOR"$n"HIY"¹¥È¥¡£"NOR,
                "dodge"      :               -100,
                "parry"      :               -100,
                "damage"     :                340,
                "force"      :                340,
                "post_action":                (: sp_attack :),
                "damage_type":               "´ÌÉË"
]),
//19ÖĞ³å½£·¨
([ "action":
"$N"HIC"Ê¹³öÁùÂöÉñ½£ÖĞµÄ¡®ÖĞ³å½£·¨ ¡¯£¬ÖĞÖ¸½£ÆøÓĞÈçÊµÖÊ£¬Íù"NOR"$n"HIC"¹¥È¥¡£"NOR,
                "dodge"      :               -100,
                "parry"      :               -100,
                "damage"     :                350,
                "force"      :                350,
                "post_action":                (: sp_attack :),
                "damage_type":               "´ÌÉË"
]),
//20¹Ø³å½£·¨
([ "action":
"$N"HIG"Ê¹³öÁùÂöÉñ½£ÖĞµÄ¡®¹Ø³å½£·¨ ¡¯£¬ÎŞÃûÖ¸½£ÆøÓĞÈçÊµÖÊ£¬Íù"NOR"$n"HIG"¹¥È¥¡£"NOR,
                "dodge"      :               -100,
                "parry"      :               -100,
                "damage"     :                360,
                "force"      :                360,
                "post_action":                (: sp_attack :),
                "damage_type":               "´ÌÉË"
]),
//21ÉÙ³å½£·¨
([ "action":
"$N"HIB"Ê¹³öÁùÂöÉñ½£ÖĞµÄ¡®ÉÙ³å½£·¨ ¡¯£¬Ğ¡Ö¸½£ÆøÓĞÈçÊµÖÊ£¬Íù"NOR"$n"HIB"¹¥È¥¡£"NOR,
                "dodge"      :               -100,
                "parry"      :               -100,
                "damage"     :                370,
                "force"      :                370,
                "post_action":                (: sp_attack :),
                "damage_type":               "´ÌÉË"
]),
//22ÉÙÔó½£·¨
([ "action":
"$N"HIM"Ê¹³öÁùÂöÉñ½£ÖĞµÄ¡®ÉÙÔó½£·¨ ¡¯£¬Ğ¡Ö¸½£ÆøÓĞÈçÊµÖÊ£¬Íù"NOR"$n"HIM"¹¥È¥¡£"NOR,
                "dodge"      :               -100,
                "parry"      :               -100,
                "damage"     :                380,
                "force"      :                380,
                "post_action":                (: sp_attack :),
                "damage_type":               "´ÌÉË"
]),
//23Áù½£ºÏÒ»
([ "action":
"$NÁìÎòµ½ÁùÂöÉñ½£"BLINK+HBRED+HIY"¡¸Ô²ÂúÈçÒâ£¬ÔË×ª²»Ï¢¡±"NOR"µÄÕæÒâ£¬½£ÆøÆä·¢£¬Íù$n¹¥È¥¡£",
                "dodge"      :               -100,
                "parry"      :               -100,
                "damage"     :                400,
                "force"      :                400,
                "post_action":                (: sp_attack1 :),
                "damage_type":               "´ÌÉË"
]),

});

void hurt(object me, object victim, object weapon, int damage)
{
        int force;
        if( random(100)>50 && !me->query_temp("conti",1) &&
            me->query("family/family_name")=="¶Î¼Ò" )
        {
          force = me->query_skill("sunforce",1);
          if(force > 250) force=250;
          victim->receive_damage("kee", 50+force );
          message_vision(sprintf(HIM"$NÁùÂöÉñ½£¹îÒìµÄÆø¾¢×êÈë$nÌåÄÚ£¬$nÁ³ÉÏÍ»È»Ò»ÕóÇà°×£¬¿´À´ÒÑÊÜÁË²»Ğ¡µÄÄÚÉË¡£\n"NOR),me,victim);
          COMBAT_D->report_status(victim);
          me->add("force",-force);
        }

        else
        {
          message_vision(sprintf(HIW"$nÀÇ±·µØÉÁ¹ıÁË$NµÄ¹îÒìÆø¾¢, µ«ÒÑ´ó´ó³öôÜ¡£\n"NOR),me,victim);
        }
}
void block(object me, object victim, object weapon, int damage)
{
        if( random(100)>50 && !me->query_temp("conti",1) &&
            me->query("family/family_name")=="¶Î¼Ò" )
        {
          victim->apply_condition("blockade",3);
          message_vision(sprintf(HIY"$NÁùÂöÉñ½£°µ²ØÒ»ÑôÖ¸ÊÖ·¨£¬·´ÊÖµãÖĞ$nµÄëşÖĞ´óÑ¨¡£\n"NOR),me,victim);
          victim->start_busy(1);
          COMBAT_D->report_status(victim);
        }
        else
        {
          message_vision(sprintf(HIW"$NÊÔÍ¼ÒÔÒ»ÑôÖ¸·âËø$n, µ«ÊÇ±»$n¶ãÁË¿ªÀ´¡£\n"NOR),me,victim);
        }
}
void conti(object me, object victim, object weapon, int damage)
{
         int i,time = 3;
        if( me->query("force_factor") >= 10 &&
            me->query("family/family_name")=="¶Î¼Ò" && 70>random(100) )
        {
          if( me->query_temp("conti") == 0 )
          {
            me->delete_temp("super");
            me->set_temp("conti",1);
      message_vision(sprintf("\n[1;33m$NºöÈ»¶ÙÎòÁùÂöÉñ½£[1;5;36mÆøÓÎ°ÙÑ¨[0m¡¢[1;5;36mÁ¬Ãà²»¾ø[0m[1;33mµÄÒª¾÷, ½£Æø×ÔÈ»¶øÈ»µÄÆÆÌå¶ø³ö, Óû°Õ²»ÄÜ!![0m\n"),me);
              for(i=1;i<=time;i++)
              COMBAT_D->do_attack(me, victim, me->query_temp("weapon"), TYPE_QUICK);
            me->delete_temp("conti");
          }
        }
}

void sp1(object me, object victim, object weapon, int damage)
{
int i;
if(me->query("env/Áù¾ø½£","YES")&&!me->query_temp("conti",1))
{
  for(i=1;i<=6;i++)
  {
    switch(i)
    {
     case 1:
message_vision(sprintf("$NÁìÎòÁË"HIW"¡®ÉÙÉÌ½£¡¯"HIY"¡®ÆøÓ¿ÈçÉ½£¬Ï¯¾íÌìÏÂ¡¯"NOR"µÄÕæÒâ£¬Ïò$nµ±Í·Õ¶ÏÂ!\n"),me,victim);
     break;
     case 2:
message_vision(sprintf("\n$NÁìÎòÁË"HIW"¡®ÉÌÑô½£¡¯"HIG"¡®ÉíĞÎÁé¶¯£¬ÊÆÈôÁ÷ÔÆ¡¯"NOR"µÄÕæÒâ£¬¶Ô$nËÄÖ«¿³Âä!\n"),me,victim);
     break;
     case 3:
message_vision(sprintf("\n$NÁìÎòÁË"HIW"¡®ÖĞ³å½£¡¯"HIC"¡®½£Æø³åÌì£¬Ó¯²»¿É¾Ã¡¯"NOR"µÄÕæÒâ£¬Íù$nĞØÇ°¼²´Ì!\n"),me,victim);
     break;
     case 4:
message_vision(sprintf("\n$NÁìÎòÁË"HIW"¡®¹Ø³å½£¡¯"HIM"¡®ÆøÄıµ¤Ìï£¬ÒÔ¾²ÖÆ¶¯¡¯"NOR"µÄÕæÒâ£¬ğÍÈ»¼ä´ÌÏò$n!\n"),me,victim);
     break;
     case 5:
message_vision(sprintf("\n$NÁìÎòÁË"HIW"¡®ÉÙ³å½£¡¯"CYN"¡®Ó¦×óÔòÓÒ£¬Ğé»Ã²»¶¨¡¯"NOR"µÄÕæÒâ£¬½£Ó°°üÎ§×¡$n!\n"),me,victim);
     break;
     case 6:
message_vision(sprintf("\n$NÁìÎòÁË"HIW"¡®ÉÙÔó½£¡¯"BLU"¡®ÔÆÚÜ²¨¹î£¬Òà»ÃÒàÕæ¡¯"NOR"µÄÕæÒâ£¬½£Æø¼²ÉäÏò$n!\n"),me,victim);
     break;
     }
message_vision(sprintf(HIR"$NÈ·ÊµÃüÖĞ$nÒªº¦£¬$n¶ÙÊ±ÑªÁ÷ÂúµØ¡£\n"NOR),me,victim);
          victim->receive_damage("kee",150);
          COMBAT_D->report_status(victim);
          me->add("force",-20);
   }
message_vision(sprintf(HIW"\nÄãÊ¹Á¦¹ı¶È,Ò»Ê±Ö®¼äÎŞÁ¦ÔÙÕ½!\n"NOR),me,victim);
if(!me->query_temp("weapon")){
me->start_busy(1);
}
else
{
weapon=me->query_temp("weapon");
if(weapon->query("six_no_delay") && me->query("family/family_name")=="¶Î¼Ò")
{
message_vision("¿ÉÊÇ$NÊÖÖĞµÄ$nÈ´·¢³öÁËµ­µ­À¶¹â£¬ÈÃ$NµÄÁ¦Æø»Ø¸´£¬ËæÊ±¿ÉÒÔÕ½¶·!!\n",me,weapon);
me->add("force",-20);
}
else
{
me->start_busy(1);
}
}
 }
}
void sp2(object me, object victim, object weapon, int damage)
{
if(!me->query_temp("conti",1)) {
        int six, force;
        six = me->query_skill("six-fingers",1);
        force = me->query_skill("sunforce",1);
        if(force>250) force=250;
          message_vision(sprintf(HIG"$N×İÉù³¤Ğ¥£¬Ë«ÊÖ»ìÔª¹éÒ»ÖĞ¹¬Ö±Èë£¬ÎŞÊıµÀ½£ÆøÔÚ$nÉíÉÏ¶Ô´©¶ø¹ı!!\n"NOR),me,victim);
          victim->receive_damage("kee",six+force);
          victim->apply_condition("bleeding",5);
          COMBAT_D->report_status(victim);
}
}
void sp3(object me, object victim, object weapon, int damage)
{
if(!me->query_temp("conti",1)) {
        int force;
        force = me->query_skill("sunforce",1);
        if(force > 350) force=350;
          message_vision(sprintf(HIC"$nÏÈÇ°ÄÚÉËÊÜµ½$NÎŞĞÎ½£ÆøÇ£Òı£¬$nµÄÉËÊÆ¸ü¼ÓÖØÁË!!\n"NOR),me,victim);
          victim->receive_damage("kee",force);
          victim->start_busy(1);
          COMBAT_D->report_status(victim);
}
}
void sp_attack(object me, object victim, object weapon, int damage)
{
    int i,sklv,str,range;
    string sp_name;
    if(!me || !victim) return ;
    if(!damage) return ;
    if(me->query("force") < 200) return ;
    sklv=me->query_skill("six-fingers",1);
    if(sklv > 120 && userp(me) && !wizardp(me)) sklv=120;
    str=victim->query("str");
    if(str > 35 ) str=35;
    sklv*=(5+random(3));
    str*=(6+random(5));
    range=me->query_temp("skills/six-fingers");
    if(!range) return;
    range*=5;
    switch(random(5))
    {
      case 0..3:
        i=range+random(4);
        message_vision(attack[i],me,victim);
        if(random(me->query("combat_exp")) >
           random(victim->query("combat_exp"))/6){
          message_vision("\n$NÉÁ¶ã²»¼°£¬ÉíÉÏ¶ÙÊ±¶à³öÁËÒ»µÀÑªÁÜÁÜµÄ½£ºÛ¡£\n" , victim);
          victim->set_temp("no_armor_effect",1);
          victim->receive_damage("kee",sklv-str,me);
          COMBAT_D->report_status(victim);
          if(range==10)
            block(me,victim,weapon,damage);
          if(range==20)
            hurt(me,victim,weapon,damage);
        }
        else{
          message_vision("\n$NÉíĞÎÒ»ÉÁ, ¾ªÏÕµØÉÁ¹ıÁËÕâÒ»ÕĞ¡£\n" , victim);
        }
        break;
      case 4:
       for(i=range;i<(range+5);i++){
        if(i >=sizeof(attack)) continue;
        message_vision(attack[i],me,victim);
        if(random(me->query("combat_exp")) >
           random(victim->query("combat_exp"))/6){
          message_vision("\n$NÉÁ¶ã²»¼°£¬ÉíÉÏ¶ÙÊ±¶à³öÁËÒ»µÀÑªÁÜÁÜµÄ½£ºÛ¡£\n" , victim);
          me->add("force",-30);
          victim->set_temp("no_armor_effect",1);
          victim->receive_damage("kee",(sklv-str)*2,me);
          COMBAT_D->report_status(victim);
          if(range==20)
            hurt(me,victim,weapon,damage);
        }
        else{
          message_vision("\n$NÉíĞÎÒ»ÉÁ, ¾ªÏÕµØÉÁ¹ıÁËÕâÒ»ÕĞ¡£\n" , victim);
        }
       }
       if( random(me->query("cps")) < 4 ) {
          me->add("force",-100);
          range/=5;
          sp_name=sword_name[range];
          message_vision("\n$NÊ¹Íê"HIY"¡®"+sp_name+"¡¯"NOR"ºó£¬ÓÉÓÚ¶¨Á¦²»×ã£¬ÌåÄÚÕæÆøÒ»Ê±ÎŞÒÔÎª¼Ì\n",me);
          me->start_busy(1);
       }
       break;
    }
}
void sp_attack1(object me, object victim, object weapon, int damage)
{
    int i,sklv,str,limit;
    if(!me || !victim) return ;
    if(!damage) return ;
    if(me->query("force") < 1000)
      return notify_fail("ÄãµÄÕæÆø²»×ã£¬ÎŞ·¨Ê¹³öÁùÂöÉñ½£Á¬Ğø¼¼!!\n");
    sklv=me->query_skill("six-fingers",1);
    if(sklv > 120 && userp(me) && !wizardp(me)) sklv=120;
    str=victim->query("str");
    sklv*=(5+random(3));
    str*=(6+random(5));
    switch(me->query("combat_exp")){
      case 2000000..5000000:
        limit=3;
        break;
      case 5000001..8000000:
        limit=2;
        break;
      case 8000001..32000000:
        limit=1;
        break;
      default:
        tell_object(me,"Äã¸Ğµ½Í·ÄÔ»è»è³Á³Á£¬ÎŞ·¨Ê¹³öÁ¬Ğø¼¼!!\n");
        return ;
        break ;
    }
    if(wizardp(me) && me->query("env/³¬¼¶Á¬»÷")) limit=0;
    for(i=0;i<sizeof(attack);i++){
     if(i % 5 >= (5-limit)) continue;
     message_vision(attack[i],me,victim);
     if(random(me->query("combat_exp")) >
        random(victim->query("combat_exp"))/6){
       message_vision("\n$NÉÁ¶ã²»¼°£¬ÉíÉÏ¶ÙÊ±¶à³öÁËÒ»µÀÑªÁÜÁÜµÄ½£ºÛ¡£\n" , victim);
       me->add("force",-30);
       victim->receive_damage("kee",(sklv-str)*2,me);
       COMBAT_D->report_status(victim);
     }
     else{
       message_vision("\n$NÉíĞÎÒ»ÉÁ, ¾ªÏÕµØÉÁ¹ıÁËÕâÒ»ÕĞ¡£\n" , victim);
     }
    }
    if( random(me->query("cps")) < 4 ) {
       me->add("force",-100);
       message_vision("\n$NÊ¹Íê"HIY"¡®ÁùÂö°ÂÒåÁ¬Ğø¼¼¡¯"NOR"ºó£¬ÓÉÓÚ¶¨Á¦²»×ã£¬ÌåÄÚÕæÆøÒ»Ê±ÎŞÒÔÎª¼Ì\n",me);
       me->start_busy(1);
    }
}
mapping sp_action(object me,object weapon)
{
        int level=(int)(me->query_skill("six-fingers",1));
        int plus,value;

        if(level/2 > random(100) && me->query_temp("super")){
          me->delete_temp("super");
          me->set_temp("skills/six-fingers",6);
          return action[22];
        }
        value=random(2100);
        if(value > 2000) return action[22];
        else{
          plus=(int)(value/200);
          if(plus==10) plus--;
          if(plus-4>=0)
            me->set_temp("skills/six-fingers",plus-4);
          return action[12+plus];
        }
}
mapping query_action(object me, object weapon)
{
        int level=(int)(me->query_skill("six-fingers",1));

        if(me->query("marks/six-fingers")==3 && level >=100 && !me->query_temp("conti"))
          return sp_action(me,weapon);

        if ( level < 10 )
           return action [random(3)];
        else if ( level < 20 )
           return action [random(5)];
        else if ( level < 30 )
           return action [random(7)];
        else if ( level < 40 )
           return action [random(9)];
        else if ( level < 50 )
           return action [random(11)];
        else if ( level < 60 )
           return action [random(13)];
        else if ( level < 70 )
           return action [random(9)+4];
        else if ( level >= 70 && me->query_temp("super",1))
           return action [12];
        else if ( level >= 100 && me->query("marks/six_sp")==3 &&
                  me->query("family/family_name") == "¶Î¼Ò")
           return action [random(12)+4];
        else
           return action [random(8)+5];
}

int valid_learn(object me)
{
        if( me->query_temp("weapon") || me->query_temp("secondary_weapon") )
          return notify_fail("Á·ÁùÂöÉñ½£»¹ÊÇÒª¿ÕÊÖ°É....\n");
        if(me->query_skill("force")*3<=me->query_skill("six-fingers",1))
          return notify_fail("ÄãµÄ»ù±¾ÄÚÁ¦¼¼ÄÜ²»×ã, ÎŞ·¨Á·ÁùÂöÉñ½£¡£\n");
        if(me->query_skill("literate")*3<=me->query_skill("six-fingers",1))
          return notify_fail("ÄãµÄÖªÊ¶²»×ã£¬ÎŞ·¨Ìå»áÁùÂöÉñ½£Àï£¬È«Éí¾­ÂöÔËĞĞÖ®µÀµÄ¾«Òª±ä»¯¡£\n");
        return 1;
}

int valid_enable(string usage)
{
      if(this_player()->query_skill("six-fingers",1) >= 45)
         {
            return (usage=="unarmed"||usage=="stabber")||(usage=="parry");
         }
          return (usage=="unarmed");
}

int practice_skill(object me)
{
        if( me->query_temp("weapon") || me->query_temp("secondary_weapon") )
          return notify_fail("Á·ÁùÂöÉñ½£»¹ÊÇÒª¿ÕÊÖ°É....\n");
        if( (int)me->query("gin") < 5 )
          return notify_fail("ÄãµÄ¾«²»¹»£¬ÎŞ·¨Á·Ï°¡£\n");
        if( (int)me->query("kee") < 30 )
          return notify_fail("ÌåÁ¦²»¹»†ª,ĞİÏ¢Ò»ÏÂÔÙ¼ÌĞøÁ·°É.\n");
        if( (int)me->query("force") < 1 )
          return notify_fail("Ä¿Ç°ÄÚÁ¦²»×ã,ĞİÏ¢Ò»»á¶ùÔÙÁ·°É.\n");
        me->receive_damage("gin", 5);
        me->receive_damage("kee", 30);
        me->add("force", -1);
        return 1;
}
string perform_action_file(string action)
{
        return CLASS_D("scholar")+"/six-fingers/"+action;
}
