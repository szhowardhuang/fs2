// cloud-sword for ÔÆÁúÌì¹¬ by nike...02/03/2002
#include <combat.h>
#include <ansi.h>
inherit SSERVER;
inherit SKILL;

void super(object me,object target,object weapon,int damage);
void busy(object me,object target,object weapon,int damage);
void delbusy(object me,object target,object weapon,int damage);
void attack(object me,object target,object weapon,int damage);
void damage(object me,object target,object weapon,int damage);
void recover(object me, object target, object weapon, int damage);
void att1(object me, object target, object weapon, int damage);

mapping *action = ({
    ([
        "action"     : HIC"$N¼À³ö"HBBLU+HIW"¦ÆÔÆÁú½£¾÷¦Æ"NOR+HIG"¡ò ÆğÊÖÊ½ ¡ò"HIY"¡¶ ÔÆÓê²ÔÃ£ ¡·"HIC"£¬$NÊÖÖĞ$w"HIC"ÃÍ¶¶£¬
½ÅÌ¤Ææ²½£¬$w"HIC"µÇÊ±Ó¿ÆğÁİÙı½£Æø£¬Ò£Ö¸Ïò$n£¬Ò»ÕĞ¹¥È¥£¬ËÆ¹¥·ÇÊØ£¬ËÆÊØ·Ç¹¥¡£"NOR,
        "damage"     : 105,
        "dodge"      : -45,
        "parry"      : -45,
        "force"      :  25,
        "post_action": (: att1 :),
    ]),
    ([
        "action"     : HIG"$NÊ¹³ö"HBBLU+HIW"¦ÆÔÆÁú½£¾÷¦Æ"NOR+HIC"¡ò ±¼Ô¾Ê½ ¡ò"HIB"¡¶ ·çÆğÔÆÓ¿ ¡·"HIG"£¬Ö»¼û$NÎèÆğ$w"HIG"£¬
Ê±¶øÂú³¡½£¹â£¬Ê±¶ø¾¢ÆøÊÕÁ²£¬$NÒ»Ê±ÉíËæ½£×ß£¬½£¾¢»¯×÷³¤ºç£¬Ö±³¯$nÉäÈ¥¡£\n"NOR,
        "damage"     : 70,
        "dodge"      : -32,
        "parry"      : -32,
        "force"      : 30,
        "post_action": (: attack :),
    ]),
    ([
        "action"     : HIW"$NÊ¹À´"HBBLU+HIW"¦ÆÔÆÁú½£¾÷¦Æ"NOR+HIR"¡ò ¼±¹¥Ê½ ¡ò"NOR+WHT"¡¶ °Ë·½ÔÆ¶¯ ¡·"HIW"£¬$NÊ×½«¼ºÉí´¦ÓÚµØÀûÖ®ÖĞ£¬
ÔÙÒÔ$w"HIW"ÎèÆğ°Ë·½»ÃÓ°£¬½«½£Ó°»¯³ÉÎŞĞÎ½£Õó£¬²¢½«$nÀ§ÓÚ½£ÕóÖ®ÖĞ¡£\n"NOR,
        "damage"     : 50,
        "dodge"      : -27,
        "parry"      : -27,
        "force"      : 30,
        "post_action": (: busy :),
    ]),
    ([
        "action"     : HIY"$N¿ñÎè$w"HIY"£¬Ö»¼ûÂú³¡$w"HIY"½£Ã¢Æø¾¢£¬ĞéÔòÊµÖ®£¬ÊµÔòĞéÖ®£¬Áî$nÑÛ»¨ÁÃÂÒ£¬
²¢½«$nÁıÕÖÔÚ½£Ó°Ö®ÖĞ£¬´ËÕĞÕıÊÇ"HBBLU+HIW"¦ÆÔÆÁú½£¾÷¦Æ"NOR+HIW"¡ò ÆøÍÌÊ½ ¡ò"HIC"¡¶ ÔÆÓÎ°ÙÉ½ ¡·"HIY"¡£\n",
        "damage"     : 80,
        "dodge"      : -18,
        "parry"      : -18,
        "force"      : 20,
        "post_action": (: att1 :),
    ]),
    ([
        "action"     : HIC"ºöÈ»Ò»Õó½£¹âÉÁÒ«£¬Ô­ÊÇ$N»ı¾Û½£·æÖ®Æø¾¢£¬ÈçÉ½ºé°ãÒ»Ğ¹¶ø³ö£¬ĞÎ³ÉÒ»
²¨ÓÖÒ»²¨µÄ½£ÀË£¬Ö±Ïò$nÓ¿È¥£¬ÕıÎª"HBBLU+HIW"¦ÆÔÆÁú½£¾÷¦Æ"NOR+HIG"¡ò ¾ªÌÎÊ½ ¡ò"HIM"¡¶ ¸²Óê·­ÔÆ ¡·"HIC"¡£\n"NOR,
        "damage"     : 115,
        "dodge"      : -9,
        "parry"      : -9,
        "force"      : 15,
        "post_action": (: att1 :),
    ]),
    ([
        "action"     : HIW"Í»È»$N½£·æÒ»×ª£¬Ê¹À´"HBBLU+HIW"¦ÆÔÆÁú½£¾÷¦Æ"NOR+HIY"¡ò Ğé²ØÊ½ ¡ò"HIG"¡¶ ÔÆ³öÎŞĞÄ ¡·"NOR"£¬ËÆÒÔ½£ÆøÎª
ÊØ£¬ÊµÒÔ½£¾¢Îª¹¥£¬Í»È»Ò»µÀ½£ÆøÍ»È»´Ó$w"HIW"½£·æ¼±±¼¶ø³ö£¬Ö±³åÏò$n¡£\n"NOR,
        "damage"     : 230,
        "dodge"      : 0,
        "parry"      : 0,
        "force"      : 25,
        "post_action": (: delbusy :),
    ]),
    ([
        "action"     : HIG"$NÊÖÖĞÖ®$w"HIG"ºöÈ»÷öµ­ÎŞ¹â£¬ËÆÈôÆø¾¢ÒÑĞé£¬¶ø$nÕı´ıÇÀ¹¥£¬È´±»$NÒÔÒ»ÕĞ
"HBBLU+HIW"¦ÆÔÆÁú½£¾÷¦Æ"NOR+HIM"¡ò ÆæÏ®Ê½ ¡ò"HIR"¡¶ ·üÔÆ°µÕİ ¡·"HIG"ÇÀ³ö£¬ÕıÊÇ¹¥Æä²»±¸£¬Õ¼µÃÏÈ»ú¡£\n"NOR,
        "damage"     : 150,
        "dodge"      : 8,
        "parry"      : 8,
        "force"      : 10,
        "post_action": (: damage :),
    ]),
    ([
        "action"     : HIY"$N½«ÕæÆø»¯ÎªÒõÑôÁ½¾¢£¬²¢¹á¾¢ÓÚ½£·æ£¬Ë³¶øÊ¹³ö"HBBLU+HIW"¦ÆÔÆÁú½£¾÷¦Æ"NOR+HIC"¡ò ÆÆ¿ÕÊ½ ¡ò
"HIG"¡¶ ËÉ°Ø¸¡ÔÆ ¡·"HIY"£¬Ö»¼û½£Æø»¯ÎªËÉ°ØÁ½ÖùĞÎ×Ô½£·æÆÆ³ö£¬ÒÔ²»Í¬·½Ïò»÷Ïò$n¡£\n"NOR,
        "damage"     : 170,
        "dodge"      : 18,
        "parry"      : 18,
        "force"      : 20,
        "post_action": (: att1 :),
    ]),
    ([
        "action"     : HIC"$NÕæÆøÓÎ×ßÈ«Éí£¬Ê¹³ö"HBBLU+HIW"¦ÆÔÆÁú½£¾÷¦Æ"NOR+YEL"¡ò »¤ÌåÊ½ ¡ò"HIW"¡¶ ÌìµØÔÆÁú ¡·"HIC"£¬½«ÕæÆø»¯Îª
ÎŞĞÎ½£ÍøÔÚÖÜÉí²úÉúÃàÃÜµÄ±£»¤²ã£¬Ê¹µÃ$nÎŞ·¨½Ó½ü£¬Éõ¶øÑÛ»¨ÁÃÂÒÖ®¡£\n"NOR,
        "damage"     : 90,
        "dodge"      : 25,
        "parry"      : 25,
        "force"      : 20,
        "post_action": (: att1 :),
    ]),
    ([
        "action"     : HIY"$N¾¢Í¸½£¼â£¬Ê¹³öÒ»ÕĞ"HBBLU+HIW"¦ÆÔÆÁú½£¾÷¦Æ"NOR+HIB"¡ò ºäÌìÊ½ ¡ò"HIR"¡¶ ÔÆÆÆÉ½ºÓ ¡·"HIY"£¬Ò»µÀĞÛ»ë½£
ÆøÖ±È¡$nÑÊºí£¬ÆäÆÆ¿ÕÖ®ÊÆÖĞ¼Ğ´ø‹üÈáÆ®Ë·Ö®¾¢£¬ÍşÁ¦×ãÒÔÕğÆÆÃûÉ½¾ŞÔÀ¡£\n"NOR,
        "damage"     : 210,
        "dodge"      : 31,
        "parry"      : 31,
        "force"      : 20,
        "post_action": (: super :),
    ]),
    ([
        "action"     : HIG"Ö»¼û$NË«×ãÒ»¿ç£¬ÌåÄÚÕæÆøÁ÷×ª£¬Ëæ¼´Ê¹ÉÏ"HBBLU+HIW"¦ÆÔÆÁú½£¾÷¦Æ"NOR+HIB"¡ò ¹îÚÜÊ½ ¡ò"HIC"¡¶ ÖØÔÆÉîËø ¡·
"HIG"£¬ÕĞÊ½ÖĞÔÌº¬Á÷ÔÆÍò»¯µÄÉñÆæÌ¬ÊÆ£¬Ö»¼û$N·ÉÀ´Ò»½££¬$nÒ»Ê±ÎŞ·¨ÕĞ¼Ü¡£\n"NOR,
     "damage"    : 230,
     "dodge"     : 38,
     "parry"     : 38,
     "force"     : 30,
        "post_action": (: super :),
    ]),
    ([
        "action"     : HIC"
\t\t  ¨T¨T¨T¨j¨T¨T¨T      ¨j¨T¨m¨j ¨d¨T¨T¨s    ¨T¨T¨m¨T¨t¨T¨p¨T¨r
\t\t¨q¨T¨T¨T¨p¨T¨T¨T¨r    ¨m¨T¨T¨m ¨t¨T¨T¨r     ¨T¨T¨T     ¨U  ¨U
\t\t¨U¨t¨T¨r¨U¨q¨T¨s¨U    ¨X¨T¨T¨[ ¨q¨T¨T¨s     ¨T¨T¨T ¨T¨T¨p¨T¨m
\t\t   ¨T¨T¨T¨T¨T¨T       ¨d¨T¨T¨g ¨d¨T¨T¨s    ¨q¨T¨T¨r¨q¨T¨s¨T¨r
\t\t ¨T¨j¨T¨T¨T¨T¨T¨T     ¨d¨T¨T¨g ¨d¨T¨T¨s    ¨U    ¨U¨U      ¨U
\t\t   ¨t¨T¨T¨T¨T¨g       ¨s    ¨s ¨t¨T¨T¨r    ¨t¨T¨T¨s¨s      ¨t\n\n
"HIW"$NÒ»ÕĞ"HBBLU+HIW"¦ÆÔÆÁú½£¾÷¦Æ"NOR+HIB"¡ò ×Ü¾÷Ê½ ¡ò"HIG"¡¶ ÔÆÁúÎŞ¼Ê ¡·"HIW"Ê¹³ö£¬ÕæÓĞÈç°ÙÈËÎè½£°ã£¬
¼±ÊÖ¿ì½££¬¾øÃîÎŞÆ¥£¬Ç¡ËÆÓĞÒâÈôÎŞÒâ£¬¼ÈÈ¤Ì¬ºáÉú£¬È´ÓÖÊÇĞ×ÏÕÖÁ¼«¡£\n"NOR,
        "damage"     : 250,
        "dodge"      : 45,
        "parry"      : 45,
        "force"      : 25,
        "post_action": (: recover :),
    ]),
});
void recover(object me, object target, object weapon, int damage)
{
    int bell, recover, sklv = me->query_skill("cloud-sword",1);
    bell = me->query("bellicosity")/10;
    if(bell > 250) bell = 250;
    recover = sklv*2-bell;
    if(sklv < bell) recover = 0;

    if(me->query("family/family_name") != "ÔÆÁúÌì¹¬") return 0;
    if( !me->query_temp("berserk") && me->query("kee") < me->query("max_kee") && random(100) > sklv*2/3) {
        message_vision(HIY"\n$NÌåÄÚµÄÕæÆø±¬·¢£¬×Ô½£·æÉÁ³öÒ»µÀ»ÆÃ¢£¬²¢½«$NÍêÈ«ÁıÕÖ£¡\n
"HIW"$NÍ»È»¸Ğµ½×Ô¼ºµÄÆøÁ¦ËÆºõÒÑ¾­»Ø¸´ÁË²»ÉÙ£¡\n"NOR,me,target);
        me->receive_curing("kee",recover);
        me->receive_heal("kee",recover);
        me->add("force",sklv);
    } else return 0;
}
void busy(object me, object target, object weapon, int damage)
{
    int sklv = me->query_skill("cloud-sword",1);

    if(me->query("family/family_name") != "ÔÆÁúÌì¹¬") return 0;
    if(me->query("force") < sklv/2) return 0;
    if(me->query("force") < 200 || target->is_busy() >= 3) return 0;
        message_vision(HIM"\n\t$NÆø¹áµ¤Ìï£¬Âí²½Õ¾ÎÈ£¬Ë³ÊÆÊ¹ÉÏÒ»ÕĞ...\n
\t\t"HIY"¡«¡«¡«"HIC"¡¶ "HIW"ÔÆ×ÙÎŞÏÖ"HIC"¡«"HIR"Áú·ÉÑæ"HIC" ¡·"HIY"¡«¡«¡«\n
\t    "HIR"×Ô½£ÉíÉ¢·¢³öÒ»¹ÉĞÜĞÜ»ğ¹â£¬ºİºİµØ³¯$n"HIR"´ÌÈ¥£¡£¡\n\n"NOR,me,target);
    if(!me->query_temp("berserk") && random(75) > 60-me->query("cps")) {
        message_vision(HIB"$NµÄÒ»½£´ÌÖĞ$nµÄÒªº¦ÕÖÃÅ£¬Ò»¹É×ÆÈÈÖ®¸Ğ£¬×Ô½£¶ËÂşÏò$nÌåÄÚ£¬
$nµÇÊ±ÃæÎŞÑªÉ«£¬Ò»Á³Ä¿µÉ¿Ú´ô£¬·Â·ğ×ÔÒÔ¾ªº§ÎŞ±È...\n"NOR,me,target);
        target->receive_damage("kee",sklv*2);
        target->apply_condition("burn",random(sklv)+sklv/3);
        target->start_busy(random(2)+1);
        me->add("force",-sklv);
    } else {
        message_vision(HIR"$NµÄÒ»½£´ÌÆ«£¬Ö»ÇáÉ¨¹ı$nµÄË«¼ç£¬$n¼çÍ·µÇÊ±ÑªÈçÈªÓ¿£¬µ«²¢ÎŞ´ó°­...\n"NOR,me,target);
        target->receive_damage("kee",sklv*2);
        me->add("force",-sklv/2);
    }
}
void delbusy(object me, object target, object weapon, int damage)
{
    int sklv = me->query_skill("cloud-sword",1);

    if(me->query("family/family_name") != "ÔÆÁúÌì¹¬") return 0;
    if(sklv < 40 || me->query("force") < sklv*3/2) return 0;
    if(!me->query_temp("berserk") && random(100) > 50) {
        message_vision(HIG"\n$N±»$n±ÆµÃ´­²»¹ıÆø£¬È´Í»È»¿ñºğÒ»Éù£¬Èç·è¿ñ°ã¿ªÊ¼ÎèÆğÊÖÖĞÖ®½££¬²¢Ò÷µÀ£º\n\n
\t\t"HIW"¡®"HIC"¹ÂÍ¤Í»Ø£²å·ÉÁ÷"HIW"£¬"HIC"ÆøÑ¹ÔªÁú°Ù³ßÂ¥"HIW"¡¯\n
\t\t\t"HIW"¡®"HIY"ÍòÀï·çÌÎ°´å­º£"HIW"£¬"HIY"Ç§ÄêºÀ½Ü×³É½Çğ"HIW"¡¯\n
\t\t"HIW"¡®"HIG"ÊèĞÇå£ÔÂÓãÁúÒ¹"HIW"£¬"HIG"ÀÏÄ¾ÇåËªºèÑãÇï"HIW"¡¯\n
\t\t\t"HIW"¡®"HIR"ÒĞ½£³¤¸èÒ»±­¾Æ"HIW"£¬"HIR"¸¡ÔÆÎ÷±±ÊÇÉñÖİ"HIW"¡¯\n\n
        "NOR,me,target);
        message_vision(HIY"  Ğëô§...$NÖÕÓÚ°Ú\ÍÑÁË$nµÄÃàÃÜ¹¥ÊÆ£¬²¢ÇÒÒÔÇ¿ÊÆ¿ì½£·´½«$n±ÆÖÁ¾ø¾³...\n"NOR,me,target);
        target->receive_damage("kee",sklv*2);
        me->add("force",-sklv*3/2);
    } return 0;
}
void damage(object me, object target, object weapon, int damage)
{
    int bell, sklv = me->query_skill("cloud-sword",1);

    if(me->query("family/family_name") != "ÔÆÁúÌì¹¬") return 0;
    if(sklv < 90 || me->query("force") < sklv*2/3) return 0;
        message_vision(HIR"\n
    $NÊÖÄó½£¾÷£¬°µ×ÔÔËĞĞÕæÆøÈëÌå£¬ÓĞÈç¾ÅÖéÒ»°ã£¬ĞĞ±éÖÜÉí´óÑ¨£¬\n
\tÓÖËæ¼´ÎèÆğÊÖÖĞÖ®½££¬ËÆÒÑ»Ã»¯ÎŞÊı½£È¦£¬½Ó×Å×İÉíÔ¾\n
    ÆğÕÉÓà£¬Ò»¸öĞıÉí£¬ÓÉ°ë¿ÕÖĞ×ÔÏò$n¼²¹¥¶øÖÁ£¬¿ÚÖĞ²¢»º»ºÒ÷µÀ£º\n
\t  "HIW"--== "HBRED+HIY"ÔÆ"NOR+HIW" == "HBRED+HIC"Æğ"NOR+HIW" == "HBRED+HIC"É½"NOR+HIW" == "HBRED+HIC"ºÓ"NOR+HIW" == "HBRED+HIC"¶¯"NOR+HIW" == "HBRED+HIC"¾Å"NOR+HIW" == "HBRED+HIC"Ìì "NOR+HIW" ==--\n
\t      "HIW"--== "HBRED+HIY"Áú"NOR+HIW" == "HBRED+HIC"ÓÎ"NOR+HIW" == "HBRED+HIC"¸É"NOR+HIW" == "HBRED+HIC"À¤"NOR+HIW" == "HBRED+HIC"Ô¾"NOR+HIW" == "HBRED+HIC"¹Å"NOR+HIW" == "HBRED+HIC"Ô¨ "NOR+HIW" ==--\n
\t\t  "HIW"--== "HBRED+HIY"½£"NOR+HIW" == "HBRED+HIC"°Á"NOR+HIW" == "HBRED+HIC"¹Â"NOR+HIW" == "HBRED+HIC"¶À"NOR+HIW" == "HBRED+HIC"Êë"NOR+HIW" == "HBRED+HIC"Îª"NOR+HIW" == "HBRED+HIC"µĞ "NOR+HIW" ==--\n
\t\t      "HIW"--== "HBRED+HIY"¾÷"NOR+HIW" == "HBRED+HIC"°Ô"NOR+HIW" == "HBRED+HIC"½­"NOR+HIW" == "HBRED+HIC"ºş"NOR+HIW" == "HBRED+HIC"Àë"NOR+HIW" == "HBRED+HIC"ÖĞ"NOR+HIW" == "HBRED+HIC"Ô­ "NOR+HIW" ==--\n
\t    "HIY"´ËÕĞ¿ìÒâ×¿¾ø£¬Ãî¼«ÎŞÑÔ£¬Ğëô§Ö®ÄÚÒÑ³öÕĞÁË¶şÊ®¶à½££¬½£½£¹¥Ïò$n"HIY"Òªº¦£¬\n
\tÖ±±ÆµÃÆäºÁÎŞÍËÊØÖ®ÓàµØ£¬Ö»ÓĞÍ¦Éíµ²¸ñ£¬È´Òò´Ë¶ø±»´òÂÒÕó½Å£¬Í·¾±¸¹±³½ÔÒÔ¼ûºì¡£\n\n"NOR,me,target);
    if( !me->query_temp("berserk") && random(sklv) > 45) {
        message_vision(HIR"$N×îºóÊ¹ÉÏÒ»½£ÖĞ³å£¬Ö±È¡$nÖ®ÃüÃÅ´óÑ¨£¬$nÒ»¸öÉÁÉñ¶øÖĞÕĞ£¬µ¹µØØ£×ÔÁ÷Ñª²»ÒÑ...\n"NOR,me,target);
        target->receive_wound("kee",sklv*5+random(sklv));
        target->receive_damage("kee",sklv*2+random(sklv));
        target->start_busy(1);
        me->add("force",-sklv*2/3);
    } else {
        message_vision(HIR"$N×îºóÊ¹ÉÏÒ»½£ÖĞ³å£¬Ö±È¡$nÖ®ÃüÃÅ´óÑ¨£¬$nËä¾Ù±Ûµ²¼İ£¬È´ÉË¼°ÊÖ±Û£¬Á÷Ñª²»Ö¹...\n"NOR,me,target);
        target->receive_damage("kee",sklv);
        me->add("force",-sklv/3);
    }
}
void attack(object me, object target, object weapon, int damage)
{
    int bell, sklv = me->query_skill("cloud-sword",1)*2;
    bell = me->query("bellicosity")/10;
    if(sklv < 120) sklv = 120;
    if(bell > 100) bell = 100; 
    if(bell < 45) bell = 45;

    if(me->query("family/family_name") != "ÔÆÁúÌì¹¬") return 0;
    if(me->query("force") < sklv) return 0;
        message_vision(HIC"\n
\t$Nºö¶øÆğÊÖ±¼Ô¾£¬×ª¶øÆæÏ®¼±¹¥£¬ÓÖËÆĞé²Ø»¤Ìå£¬ÊµÎªÆøÍÌ×Ü¾÷£¬\n
    Ë²Ï¢Íò±ä£¬ÓĞÈçÁúÌÚ·ïÏèÒ»°ãµÄÎèÆğÊÖÖĞÖ®½££¬²¢Ë³ÊÆÊ¹ÉÏÒ»ÕĞ......\n
\t      "HIY"¡¶--¡·"HIW"¡«"HIC"ÔÆ"HIW"¡«"HIC"Áú"HIW"¡«"HIC"½£"HIW"¡«"HIC"¾÷"HIW"¡«"HIY"¡¶--¡·"HIR"¡®°ÂÒâÖ®Ê½¡¯"NOR"\n
"HIY"\t    ¡¾"HIW"¡«"HIC"ÓÎ"HIW"¡«"HIC"ÔÆ"HIW"¡«"HIC"ÎŞ"HIW"¡«"HIC"³£"HIW"¡«"HIC"Ïà"HIR"¨B"HIC"Ìì"HIW"¡«"HIC"Áú"HIW"¡«"HIC"Îè"HIW"¡«"HIC"¿Õ"HIW"¡«"HIC"Ïè"HIW"¡«"HIY"¡¿\n
    "HIC"Ò»Ê±½£¹â³ã³ã£¬½£Ã¢ÉÁÒ«£¬½£Æø¼±´Ü£¬½£¾¢Í»±¼£¬ÈË½£ºÏÒ»£¬Ïò$n¿ñ¹¥¶øÈ¥£¡\n\n"NOR,me,target);
    if(!me->query_temp("berserk") && random(sklv) > bell) {
        message_vision(HIR"$n±»½£¹âËùÕğÉã£¬ºöÈ»Ò»¸öÉÁÉñ£¬ÒÑ¾­Ôâ$N¸øÍ´»÷ÁËÒªº¦£¡£¡£¡\n"NOR,me,target);
        target->receive_damage("gin",sklv+random(sklv/2));
        target->receive_damage("kee",sklv*2+random(sklv));
        target->receive_damage("sen",sklv+random(sklv/2));
        target->receive_wound("gin",sklv/2+random(sklv));
        target->receive_wound("kee",sklv+random(sklv*2));
        target->receive_wound("sen",sklv/2+random(sklv));
        me->add("force",-sklv);
    } else {
        message_vision(HIG"$n½Å²È²½·¨£¬Ò»¸ö»ØÉí£¬¾¹ôæÈ»µÄÉÁ¹ıÕâÍşÁ¦²»ÈõµÄÒ»»÷...\n"NOR,me,target);
        me->add("force",sklv/3);
        target->start_busy(1);
    }
}
void super(object me, object target, object weapon, int damage)
{
    int sklv,bell = me->query("bellicosity")/10;
    sklv = me->query_skill("cloud-sword",1);
    if(bell < 0) bell = 0;
    if(bell > 60) bell = 60;

    if(me->query("family/family_name") != "ÔÆÁúÌì¹¬") return 0;
    if(sklv < 120) return 0;
    if(!me->query("quests/free_shasword")) return 0;
    if(me->query("force") < 1200) return 0;
    if(me->query_temp("berserk")) return 0;
        message_vision(HIY"\n$NÑÛÕÀ½ğ¹â£¬Îè½£ÈçÂÖ£¬´óºÈÒ»Éù£º¡¸ÄÉÃüÀ´£¡£¡£¡¡±£¬Ò»ÕĞÊ¹ÉÏ...\n
\t\t"HBRED+HIW"-= "HIY"ÔÆÁú°Ô½£Òâ"HIW"£­"HIC"Ê®¶şÊ½Æë³ö "HIW"=-"NOR+HIY"\n\n"NOR,me,target);
    if(random(100) > 30) {
    sklv = sklv - bell;
        message_vision(HIR"\n$N¿ñ±©½£Òâ£¬¾¢¹á½£·æ£¬Ê¹³ö"HIY"¡¶ÆğÊÖÊ½¡·"HIW"¨"NOR+GRN"ÔÆÓê²ÔÃ£"HIW"¨"HIR"£¬Ò»ÕĞ»¢»¢Éú·ç£¬È¥ÊÆĞÚĞÚµÄ¹¥Ïò$nµÄÕĞ×Ó¡£\n"NOR,me,target);
        target->receive_damage("kee",sklv/2);
        COMBAT_D->report_status(target);
        message_vision(HIR"\n$N¿ñ±©½£Òâ£¬¾¢¹á½£·æ£¬Ê¹³ö"HIY"¡¶±¼Ô¾Ê½¡·"HIW"¨"NOR+MAG"·çÆğÔÆÓ¿"HIW"¨"HIR"£¬Ò»ÕĞ»¢»¢Éú·ç£¬È¥ÊÆĞÚĞÚ¹¥Ïò$nµÄ¾±Ïî¡£\n"NOR,me,target);
        target->receive_damage("kee",sklv/2);
        COMBAT_D->report_status(target);
        message_vision(HIR"\n$N¿ñ±©½£Òâ£¬¾¢¹á½£·æ£¬Ê¹³ö"HIY"¡¶¼±¹¥Ê½¡·"HIW"¨"HIB"°Ë·½ÔÆ¶¯"HIW"¨"HIR"£¬Ò»ÕĞ»¢»¢Éú·ç£¬È¥ÊÆĞÚĞÚ¹¥Ïò$nµÄË«±Û¡£\n"NOR,me,target);
        target->receive_damage("kee",sklv/2);
        COMBAT_D->report_status(target);
        message_vision(HIR"\n$N¿ñ±©½£Òâ£¬¾¢¹á½£·æ£¬Ê¹³ö"HIY"¡¶ÆøÍÌÊ½¡·"HIW"¨"NOR+CYN"ÔÆÓÎ°ÙÉ½"HIW"¨"HIR"£¬Ò»ÕĞ»¢»¢Éú·ç£¬È¥ÊÆĞÚĞÚ¹¥Ïò$nµÄÊÖÍó¡£\n"NOR,me,target);
        target->receive_damage("kee",sklv*2/3);
        COMBAT_D->report_status(target);
        message_vision(HIR"\n$N¿ñ±©½£Òâ£¬¾¢¹á½£·æ£¬Ê¹³ö"HIY"¡¶¾ªÌÎÊ½¡·"HIW"¨"HIM"¸²Óê·­ÔÆ"HIW"¨"HIR"£¬Ò»ÕĞ»¢»¢Éú·ç£¬È¥ÊÆĞÚĞÚ¹¥Ïò$nµÄĞØ¿Ú¡£\n"NOR,me,target);
        target->receive_damage("kee",sklv*2/3);
        COMBAT_D->report_status(target);
        message_vision(HIR"\n$N¿ñ±©½£Òâ£¬¾¢¹á½£·æ£¬Ê¹³ö"HIY"¡¶Ğé²ØÊ½¡·"HIW"¨"NOR+WHT"ÔÆ³öÎŞĞÄ"HIW"¨"HIR"£¬Ò»ÕĞ»¢»¢Éú·ç£¬È¥ÊÆĞÚĞÚ¹¥Ïò$nµÄ¶ÇÆ¤¡£\n"NOR,me,target);
        target->receive_damage("kee",sklv+random(sklv));
        COMBAT_D->report_status(target);
        message_vision(HIR"\n$N¿ñ±©½£Òâ£¬¾¢¹á½£·æ£¬Ê¹³ö"HIY"¡¶ÆæÏ®Ê½¡·"HIW"¨"NOR+YEL"·üÔÆ°µÕİ"HIW"¨"HIR"£¬Ò»ÕĞ»¢»¢Éú·ç£¬È¥ÊÆĞÚĞÚ¹¥Ïò$nµÄÑü¼Ê¡£\n"NOR,me,target);
        target->receive_damage("kee",sklv*2);
        COMBAT_D->report_status(target);
        message_vision(HIR"\n$N¿ñ±©½£Òâ£¬¾¢¹á½£·æ£¬Ê¹³ö"HIY"¡¶ÆÆ¿ÕÊ½¡·"HIW"¨"HIG"ËÉ°Ø¸¡ÔÆ"HIW"¨"HIR"£¬Ò»ÕĞ»¢»¢Éú·ç£¬È¥ÊÆĞÚĞÚ¹¥Ïò$nµÄÊóŞÉ¡£\n"NOR,me,target);
        target->receive_damage("kee",sklv*2+random(sklv/2));
        COMBAT_D->report_status(target);
        message_vision(HIR"\n$N¿ñ±©½£Òâ£¬¾¢¹á½£·æ£¬Ê¹³ö"HIY"¡¶»¤ÌåÊ½¡·"HIW"¨"HIC"ÌìµØÔÆÁú"HIW"¨"HIR"£¬Ò»ÕĞ»¢»¢Éú·ç£¬È¥ÊÆĞÚĞÚ¹¥Ïò$nµÄ´óÍÈ¡£\n"NOR,me,target);
        target->receive_damage("kee",sklv*2+random(sklv));
        COMBAT_D->report_status(target);
        message_vision(HIR"\n$N¿ñ±©½£Òâ£¬¾¢¹á½£·æ£¬Ê¹³ö"HIY"¡¶¹îÚÜÊ½¡·"HIW"¨"HIY"ÖØÔÆÉîËø"HIW"¨"HIR"£¬Ò»ÕĞ»¢»¢Éú·ç£¬È¥ÊÆĞÚĞÚ¹¥Ïò$nµÄÏ¥Í·\n¡£"NOR,me,target);
        target->receive_damage("kee",sklv*3);
        COMBAT_D->report_status(target);
        message_vision(HIR"\n$N¿ñ±©½£Òâ£¬¾¢¹á½£·æ£¬Ê¹³ö"HIY"¡¶ºäÌìÊ½¡·"HIW"¨"HIR"ÔÆÆÆÉ½ºÓ"HIW"¨"HIR"£¬Ò»ÕĞ»¢»¢Éú·ç£¬È¥ÊÆĞÚĞÚ¹¥Ïò$nµÄĞ¡ÍÈ¡£\n"NOR,me,target);
        target->receive_damage("kee",sklv*3+random(sklv/2));
        COMBAT_D->report_status(target);
        message_vision(HIR"\n$N¿ñ±©½£Òâ£¬¾¢¹á½£·æ£¬Ê¹³ö"HIY"¡¶×Ü¾÷Ê½¡·"HIW"¨"HIW"ÔÆÁúÎŞ¼Ê"HIW"¨"HIR"£¬Ò»ÕĞ»¢»¢Éú·ç£¬È¥ÊÆĞÚĞÚ¹¥Ïò$nµÄ×ãõ×¡£\n"NOR,me,target);
        target->receive_damage("kee",sklv*4+random(sklv));
        COMBAT_D->report_status(target);
        COMBAT_D->report_status(target);
        COMBAT_D->report_status(target);
        target->start_busy(2);
        me->add("force",-1200);
        me->start_busy(1);
    } else {
        message_vision(HIB"Ã»ÁÏµ½¾ÓÈ»±»$n"HIB"Í»ÈçÆäÀ´µÄÒ»ÕĞ¸ø¹¥ÆÆ½£ÊÆ£¬¶ø$NÖ»ÉËµ½$n"HIB"µÄÒ»µãÆ¤Ã«£¬
²¢ÎŞ¸øÓèÖØ»÷£¬·´¶ø$N×ÔÉí¶ÙÊ±Ê§È¥ÖØĞÄ£¬×Ô¿ÕÖĞÖØË¤ÓÚµØ...\n"NOR,me,target);
        me->add("force",-200);
        target->receive_damage("kee",sklv*2);
    }
}
// ´Ó gold-blade Ö±½ÓÍµ¹ıÀ´¸ÄµÄà¸...by nike
void att1(object me, object victim, object weapon, int damage)
{
    int lose, i, bell = me->query("bellicosity")/100;
    if(bell < 1) bell = 1;
    if(bell > 15) bell = 15;
    lose = (int)me->query_skill("cloud-sword",1)/20-random(bell)+1;

    if(me->query_temp("berserk")) return 0;
    if(me->query("force") < 120) return 0;
    if(lose < 1) lose = 1;
    if(lose > 20) lose = 20;
    for(i = 0;i < lose; i++) {
        COMBAT_D->do_attack(me, victim, me->query_temp("weapon"), TYPE_QUICK);
        me->set_temp("berserk",1);
        me->add("force",-120);
        if(me->query("force") < 0) me->set("force",0);
    }
        me->delete_temp("berserk");
}
int valid_learn()
{
    object me = this_player();
    object ob = me->query_temp("weapon");

    if(me->query("max_force") < 60)
        return notify_fail("ÄãµÄÄÚ¹¦¸ù»ù²»×ã£¬ÎŞ·¨Ñ§Ï°¡¶ÔÆÁú½£¾÷¡·¡£\n");
    if(!ob) return notify_fail("ÄãÊÖÖĞÎŞ½££¬ÈçºÎÑ§Ï°¡¶ÔÆÁú½£¾÷¡·£¿\n");
        return 1;
}
int valid_enable(string usage) { return (usage=="sword"); }
mapping query_action(object me, object weapon)
{
    object target = offensive_target(me);
    int sk = me->query_skill("cloud-sword",1);
    int da = sk*(random(2)+5);
    da = random(da)+da/2;
    weapon = me->query_temp("weapon");

    if(weapon) {
    if(me->query("force") >= 450 && me->query("bellicosity") <= 50) {
    if(me->query("family/family_name") == "ÔÆÁúÌì¹¬"
    && weapon->query("id") == "cloud-dragon sword"
    && sk >= 80 && random(100) > 85 && target) {
message_vision(HIC"$NÊÖÖĞµÄ"+weapon->name()+"ÔÚÌåÄÚ¸¡ÔÆ¾¢ÆøµÄµ¼ÒıÖ®ÏÂ£¬¾¹»Ã»¯ÎªÒ»Î²Ïè¿ÕÔÆÁú£¬³¯$nÌÚ·É¶øÈ¥£¡\n"NOR,me,target);
message_vision(@LONG

[0;1;36m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m/[1m|[1m [1m [1m/[1m|[1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m,[1m^[1m^[1m^[1m-[1m-[1m_[1m/[1m|[0m
[0;1;36m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m_[1m-[1m^[1m^[1m^[1m^[1m^[1m^[1m-[1m_[1m/[1m|[1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m.[1m_[1m-[1m-[1m-[1m;[1m/[1m^[1m [1m^[1m [1m [1m [1m`[1m.[1m/[1m|[0m
[0;1;36m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1mv[1m [1m [1m [1m [1m [1m/[1m^[1m^[1m [1mv[1m [1m [1m^[1m^[1m [1m [1m^[1m/[1m|[1m [1m [1m [1m [1m [1m [1m [1m [1m [1m([1m([1m [1m)[1m;[1m/[1m^[1m [1m [1m [1m [1m [1m>[1m [1m>[1m [1m`[1m/[1m|[0m
[0;1;36m [1m [1m [1m\[1m [1m [1m [1m [1m [1m([1m:[1m)[1m [1m [1m [1m/[1m^[1m [1m^[1m([1m:[1m)[1m [1m [1m^[1m [1m [1m>[1m>[1m`[1m/[1m|[1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m,[1m/[1m [1m^[1m^[1m [1m [1m>[1m [1m [1m [1m [1m>[1m [1m>[1m`[1m/[1m|[0m
[0;1;36m [1m [1m [1m [1m [1m\[1m [1m [1m [1m [1m([1m:[1m:[1m)[1m [1m/[1m [1m [1m [1m([1m:[1m:[1m)[1m [1m;[1m>[1m [1m/[1m [1m>[1m>[1m`[1m/[1m|[1m [1m [1m [1m [1m [1m [1m [1m [1m,[1m/[1m^[1m^[1m^[1m [1m [1m [1m,[1m-[1m.[1m [1m [1m [1m>[1m [1m>[1m>[1m`[1m/[1m|[0m
[0;1;36m [1m [1m [1m [1m [1m [1m\[1m [1m [1m [1m([1m:[1m:[1m)[1m,[1m^[1m^[1m^[1m.[1m([1m:[1m:[1m)[1m/[1m`[1m/[1m [1m [1m [1m>[1m>[1m>[1m`[1m/[1m|[1m [1m [1m [1m [1m [1m [1m,[1m/[1m^[1m^[1m [1m [1m [1m^[1m;[1m [1m [1m [1m`[1m.[1m [1m [1m [1m>[1m [1m>[1m`[1m/[1m|[0m
[0;1;36m [1m [1m [1m [1m [1m [1m [1m [1m\[1m [1m [1m<[1m_[1m)[1m:[1m:[1m:[1m:[1m:[1m([1m_[1m>[1m/[1m [1m/[1m`[1m.[1m_[1m-[1m-[1m.[1m [1m [1m`[1m/[1m|[1m [1m [1m [1m [1m [1m;[1m/[1m^[1m [1m [1m^[1m [1m [1m;[1m-[1m_[1m.[1m [1m [1m`[1m.[1m.[1m [1m>[1m [1m [1m>[1m`[1m/[1m|[0m
[0;1;36m [1m [1m [1m [1m [1m [1m [1m [1m [1m\[1m [1m\[1m|[1m:[1m:[1m:[1m|[1m:[1m:[1m:[1m|[1m/[1m [1m/[1m [1m [1m [1m([1m [1m)[1m)[1m [1m [1m>[1m`[1m/[1m|[1m [1m [1m [1m,[1m/[1m^[1m [1m^[1m [1m [1m [1m;[1m([1m [1m)[1m)[1m [1m [1m [1m [1m [1m;[1m [1m [1m>[1m>[1m [1m`[1m/[0m
[0;1;36m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m\[1m [1m [1m\[1m_[1m:[1m|[1m:[1m_[1m/[1m [1m [1m/[1m [1m [1m [1m [1m`[1m.[1m [1m [1m [1m [1m [1m>[1m`[1m/[1m|[1m [1m,[1m/[1m^[1m^[1m [1m [1m [1m^[1m [1m;[1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m;[1m>[1m [1m [1m>[1m [1m/[1m;[0m
[0;1;36m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m\[1m [1m\[0;1;5;31m@[0;1;36m,[1m [1m.[0;1;5;31m@[0;1;36m/[1m [1m/[1m [1m [1m [1m [1m [1m [1m`[1m.[1m [1m [1m>[1m [1m>[1m [1m`[1m-[1m-[1m [1m^[1m^[1m [1m^[1m [1m^[1m [1m;[1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m;[1m [1m>[1m [1m>[1m [1m/[0m
[0;1;36m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m\[1m [1m\[1m=[1m:[1m=[1m/[1m [1m/[1m [1m [1m [1m [1m [1m [1m [1m_[1m`[1m.[1m [1m [1m [1m [1m>[1m [1m [1m>[1m [1m>[1m [1m [1m>[1m [1m [1m;[1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m,[1m`[1m [1m>[1m [1m [1m/[1m;[0m
[0;1;36m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m\[1m\[1m=[1m:[1m=[1m/[1m/[1m [1m [1m [1m [1m [1m [1m [1m([1m([1m,[1m`[1m.[1m>[1m [1m>[1m [1m [1m [1m [1m>[1m [1m>[1m [1m_[1m/[1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m,[1m'[1m [1m>[1m [1m>[1m [1m/[1m,[0m
[0;1;36m [1m [1m [1m [1m [1m [1m [1m [1;33m [1m_[1;36m [1m [1m [1m [1m<[1mo[1m_[1mo[1m>[1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m^[1m`[1m-[1m_[1m_[1m [1m>[1m [1m_[1m_[1m_[1m-[1m^[1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m_[1m,[1m'[1m [1m>[1m>[1m [1m [1m/[1m;[0m
[0;1m [1m [1;33m^[1m^[1m-[1m_[1m_[1m [1;31m/[1m^[1m^[1m\[1;33m [1m_[1m-[1;37m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1;36m^[1m^[1m^[1m^[1m^[1m_[1m-[1m^[1m=[1m-[1m-[1m^[1m^[1m.[1m.[1m.[1m_[1m'[1m [1m>[1m>[1m [1m [1m/[0m
[0;1m [1m [1m [1m [1;33m^[1m^[1m-[1;31m|[1m [1m [1m'[1m;[1m|[1;33m_[1m_[1m-[1m^[1m^[1m^[1m-[1m_[1m_[1m_[1m [1;37m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1;36m_[1m^[1m_[1m^[1m-[1m-[1m.[1m.[1m.[1m.[1m_[1m_[1m.[1m.[1m.[1m/[0m
[0;1m [1m [1m [1;33m_[1m_[1m_[1m-[1m_[1;31m\[1m_[1m_[1m/[1;33m-[1m-[1m^[1m^[1m^[1m [1m [1;37m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1;36m^[1m^[1m^[0m

LONG+NOR,me,target);
        message_vision(HIW"ÔÆÁúÌÚ·ÉÓÚ¿Õ£¬ºö¿ÚÍÂ³àºì»ğÖé£¬Ëæ¼´³¯$n¸©³åÖ±ÏÂ£¬¿ñ¾¢ËÆÀ×£¬Ñ¸¼²Èçµç£¡\n"NOR,me,target);
        message_vision(HIY"\nÔÆÁúĞıÎè³¤Ğ¥Ò»Éù£¬ÉùÈôºµÌìºéÀ×£¬ÕğµÃ$nÆß»è°ËËØ£¬ÄÔ×ÓÀïÎËÎËÂÒ½Ğ£¡\n"NOR,me,target);
        COMBAT_D->report_status(target);
        message_vision(HIR"ÔÆÁú»ÓÎè×ÅÈñ×¦Õ¹¿ª·è¿ñ¹¥»÷£¬$nÒ»Ê±ÉÁ¶ã²»¼°£¬¶øµ¼ÖÂÈ«ÉíÆ¤ÕÀÈâÁÑ£¡\n"NOR,me,target);
        COMBAT_D->report_status(target);
        message_vision(RED"ÔÆÁú¿ÚÖĞµÄ»ğÖéÍ»È»³¯$n³Û·É¶øÈ¥£¬ÓÉÓÚÀ´µÃÍ»È»£¬$n²ÒÔâ»ğÖé×ÆÉí£¬Í´¿à²»ÒÑ£¡\n"NOR,me,target);
        COMBAT_D->report_status(target);
        target->start_busy(1);
        target->receive_damage("kee",da);
        target->receive_damage("gin",da/5);
        target->receive_damage("sen",da/5);
        me->add("force",-(random(150)+300));
        message_vision(HIB"\nÔÆÁúÔÚÍê³ÉÊ¹ÃüÖ®ºó£¬ÓÖ»Ã»¯Îª½£ĞÎ£¬Âä»Ø$NµÄÊÖÖĞ¡£\n"NOR,me,target);
        }
    }
  }
    sk = sk/10;
    if(sk < 2) return action[random(3)];
    else if(sk < 4) return action[random(6)];
    else if(sk < 8) return action[random(9)];
    else return action[random(sizeof(action))];
}
string perform_action_file(string action)
{
        return CLASS_D("swordsman")+"/cloud-sword/"+action;
}


