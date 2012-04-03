// Á¬ÑôÆß¾÷½£·¨
//È¡´úÔ­À´µÄÑ¸À×½£·¨ && Ìá¸ß½âÃÔÄÑ¶È
//roger && taifarÓÚ 98/8/16

#include <ansi.h>
#include <combat.h>
inherit SKILL;
inherit SSERVER;

void sp_attack0(object me, object victim, object  weapon, int damage);
void sp_attack1(object me, object victim, object  weapon, int damage);
void sp_attack2(object me, object victim, object  weapon, int damage);
void sp_attack3(object me, object victim, object  weapon, int damage);
void sp_attack4(object me, object victim, object  weapon, int damage);
void sp_attack5(object me, object victim, object  weapon, int damage);
void sp_attack6(object me, object victim, object  weapon, int damage);

int kar=this_player()->query("kar",1);
int cps=this_player()->query("cps",1);
int str=this_player()->query("str",1);
int cor=this_player()->query("cor",1);
int int1=this_player()->query("int",1);
int spi=this_player()->query("spi",1);
int sp_value;

string *parry_msg = ({
"\n¶ø$nÊÖÖĞµÄ³¤½£Ò»ºá£¬Ò»ÕĞ"HIB"¡®ÌúËøºá½­¡¯"NOR"ÊÆĞ®Ç§½ïÍùÇ°Ò»ÍÆÒ»ËÍ£¬µ±µÄÒ»ÉùÅö³öÁËµãµã»ğ»¨·´°Ñ$NÊÖÖĞµÄ$wÏÕĞ©Õğ·É£¡\n"NOR,
"\nµ«$n³¤½£Ò»×ª£¬Ë³×Å$NµÄ$wÒÔÒ»ÕĞ"HIC"¡®Ë³Á÷¶øÏÂ¡¯"NOR"Íù$NµÄÊÖÖ¸Ï÷È¥£¬$N´ó¾ªÊ§É«ÏÂ¼±Ã¦ÊÕÕĞ»Ø¼Ü\n",
"\n$n½£×ßÇáÁé£¬ÊÖÖĞ³¤½£ºöÏ÷ºö´ÌÒ»Á¬´®µÄ±øÆ÷×²»÷Éùºó$nÒÑ½«$NµÄ¿ìÕĞÈ«²¿»¯½â£¡\n",
HIW"\n$nÒÔ¿ìÖÆ¿ì£¬$N¿ìµ«$n¸ü¿ì£¬Á¬Ğø´Ì³öÁËÆßÆßËÄÊ®¾Å½£Ö¯³ÉÒ»µÀ½£Íø½«$NµÄÕĞÊ½¾¡Êıµ´¿ª£¡\n"NOR,    
        });

string *unarmed_parry_msg = ({
"µ«ÊÇ±»$n¸ñ¿ªÁË¡£\n",
"½á¹û±»$nµ²¿ªÁË¡£\n",
});

string *lan_yan = ({
HIW"$NÊ¹³öÁÒÑôµÚÒ»Ê½"HIR"¡®ºÆÈÕ³õÉı¡¯"HIW"£¬ÊÖÖĞµÄ$w"HIW"¿ìËÙÎè¶¯×Å£¬Ğ®×ÅÕóÕóÁÒ·çÏ®ÏòËÄÖÜ£¬Ò»Ê±¼ä½£Æø×İºá\n"NOR,
HIW"$NÊÖÖĞ$w"HIW"Í»È»ÎËÎË¾ŞÏì£¬Ê¹³öÁÒÑôµÚ¶şÊ½"HIR"¡®ÁÒÈÕÆÈÊÀ¡¯"HIW"£¬ÊÖÖĞ$w"HIW"£¬·¢³öÅùö¨¾ŞÏì´ÌÏòËÄÖÜµÄµĞÈË\n"NOR,
HIW"$NÊÖÖĞ$w"HIW"¼±ËÙ²ü¶¯£¬Ë²¼äÂúÌì½£»¨ÉÁÉÁ£¬ÕıÊÇÁÒÑôµÚÈıÊ½"HIR"¡®Ç§»ªÓ³ÈÕ¡¯"HIW"£¬ÕĞÈçÆäÃû£¬Ö»¼ûµĞÈËµÄÑªÈçÂä»¨°ã·É½¦...\n"NOR,
HIW"$NÉíĞÎ¼±Ğı£¬Ê¹³öÁÒÑôµÚËÄÊ½"HIR"¡®·çÉ³×ÆÈÕ¡¯"HIW"£¬Ö»¼û»ëÌÌµÄ·ç¾íÆğ¹ö¹ö³¾É³£¬ÁîÈËÃş²»Çå$NÔÚºÎ·½...\n"NOR,
HIW"$NÊÖÄó½£¾÷£¬ºöÈ»ÊÖÖĞµÄ$w"HIW"ÍùÌì¿Õ·ÉÈ¥£¬Ë²Ê±¼äÊıµÀ½£ÆøÍùÏÂ¼¤Éä£¬ÕıÊÇÁÒÑôµÚÎåÊ½"HIR"¡®ºçÔÆ¹ıÈÕ¡¯\n"NOR,
HIW"$NÊ¹³öÁÒÑôµÚÁùÊ½"HIR"¡®ÉıÁúĞıÈÕ¡¯"HIW"ÉíĞÎÓÌÈçÒ»Ìõ»ÒÁú¼±Ğı¶øÉÏ£¬ÇÒÉ¢·¢³ö×ÆÈÈµÄÆøÏ¢Ï®ÏòËÄÖÜ£¬ºÃÏñÒªÒ»¾ÙÍÌÃ»µĞÈËËÆµÄ\n"NOR,
HIW"$N´óºÈÒ»Éù£¬Ê¹³öÁÒÑôµÚÆßÊ½"HIR"¡®ÁÒÈÕµ±¿Õ¡¯"HIW"£¬Ò»Ë²¼äÒÑÏòËÄÖÜ´Ì³öÁËÆßÆßËÄÊ®¾Å½£!\n"NOR,
HIW"$NÊÖÖĞµÄ$w"HIW"£¬ºöÅüºö´Ì£¬Ò»ÕĞÁÒÑôµÚ°ËÊ½£¬"HIR"¡®ÑæÈÕÆÈÀ×¡¯"HIW"Ê¹½«³öÀ´£¬ËÄÖÜÏìÆğÁËÂ¡Â¡¾ŞÏì!\n"NOR,
HIW"$NÊÖÖĞµÄ$w"HIW"½£Ã¢ºöÈ»Ò»³¤£¬Ê¹³öÁÒÑôµÚ¾ÅÊ½"HIR"¡®»®ÈÕ·Éµç¡¯"HIW"£¬Ö»¼û½£Ã¢²»Í£µÄÍÌÍÂÉÁË¸£¬ÁîÈËÑÛ»¨ÁÃÂÒ¼ä$w"HIW"£¬ÒÑ´©Ìå¶ø³ö...\n"NOR,
HIW"$NÊ¹³ö¾ø¶¥Çá¹¦£¬Ò»ÕĞÁÒÑôµÚÊ®Ê½"HIR"¡®±ÎÓêÈÈÈÕ¡¯"HIW"£¬Ê¹½«³öÀ´£¬ÖÜÎ§µĞÈË·×·×²»×¡µØµ¹ÍË...\n"NOR,
HIW"$NÉíĞÎÒ»»Î£¬ÊÖÖĞ$w"HIW"£¬²»¾øµÄÏòµĞÈË×·Ëæ¶øÈ¥£¬ÕıÊÇÁÒÑôµÚÊ®Ò»Ê½"HIR"¡®Ğ±ÈÕ¹ÒÓ°¡¯"HIW"£¬ÁîµĞÈË±ÜÎŞ¿É±Ü\n"NOR,
HIW"$NÊÖÖĞµÄ$w"HIW"ºöÈ»±ä³ÉÈíÈíÃàÃà£¬½£ÕĞÈ¥ÊÆ¹îÒìÄª²â£¬ÕıÊÇÁÒÑôµÚÊ®¶şÊ½"HIR"¡®ÒõÔÆÑÚÈÕ¡¯"HIW"ÁîµĞÈËÎŞ´ÓÕĞ¼ÜÆğ\n"NOR,
HIW"$NÊÖÖĞµÄ$w"HIW"·ÉÉä¶ø³ö£¬Ê¹³öÁÒÑôµÚÊ®ÈıÊ½"HIR"¡®ÈĞÈÕ·É·ç¡¯"HIW"£¬Ö»¼û$w"HIW"ÔÚ$NË«ÊÖÕæÆøµÄ¿ØÖÆÏÂÒÔ¼«¸ßµÄËÙ¶È´ÌÏòÖÜÎ§µÄµĞÈË¡£\n"NOR,
HIW"$NÊ¹³öÁÒÑôµÚÊ®ËÄÊ½"HIR"¡®Ñ×ÈÕÇ§Ó¡¡¯"HIW"£¬ÊÖÖĞµÄ$w"HIW"ºöÈ»·É¿ìµÄÎè¶¯£¬ĞÎ³ÉÒ»µÀµÀ»ÃÓ°´ÌÏòÖÜÎ§µÄµĞÈË¡£\n"NOR,
HIW"$NÊÖÖĞµÄ$w"HIW"ÍùÍâÒ»·Ö£¬ºöÈ»»¯³É³ÉÇ§ÉÏÍòµÄ»ÃÓ°ÁıÕÖ×ÅËÄÖÜµÄµĞÈË£¬ÕıÊÇÁÒÑôµÚÊ®ÎåÊ½"HIR"¡®»ÃÈÕÁ÷¹â¡¯"HIW"£¬ÖÜÎ§µĞÈË·×·×ÍËÈ´...\n"NOR,
HIW"$N½«ÊÖÖĞµÄ$w"HIW"ÎèµÃ¸ü¼±£¬Ê¹³öÁÒÑôµÚÊ®ÁùÊ½"HIR"¡®¿ñÈÕ¾¡Ê´¡¯"HIW"£¬½£·¨¿ìµÄÁ¬½£µÄ×ÙÓ°¶¼¿´²»µ½Ö»ÌıÒ»Éù²ÒºÅ$nÒÑ±»´ÌÉË!¡£\n"NOR,
HIW"$NÊ¹³öÁÒÑôµÚÊ®ÆßÊ½"HIR"¡®Î±ÈÕÎªÕæ¡¯"HIW"£¬½£·¨Ö®¿ì£¬ÕĞÊ½Ö®À±£¬ÊµÒÑÁîÈË·ËÒÄËùË¼£¬Ëù´Ì³öµÄÃ¿Ò»ÕĞ½ÔÁîµĞÈËÊÜµ½ÖØ´´\n"NOR,
});

string *shasword = ({
"$NÊÖÄó½£¾÷£¬³¤½£Ò»Í¦£¬Ê¹³öÒ»ÕĞ"HIC"¡®ÈªÃùÜ½ÈØ¡¯"NOR"£¬×ËÌ¬ÓÆÑÅ£¬ÆÄÓĞÌìÉÏÏÉÈËÏÂ·²¼äÖ®Òâ\n",
"$NÒ»¸öĞıÉí£¬ÊÖÖĞµÄ$wÔÚ¿ÕÖĞÉÁ¹ıÒ»µÀ¹âÃ¢Ö±´ÌÏò$nµÄ$l£¬×ËÌ¬äìÈ÷Ò»ÆøºÇ³É£¬ÕıÊÇÒ»ÕĞ"HIY"¡®½ğÑãºá¿Õ¡¯\n"NOR,
"$N×ó¼çÎ¢³Á£¬×óÊÖ½£¾÷Ğ±Òı£¬ÓÒÖâÒ»Ëõ£¬Ê¹³öÒ»ÕĞ"HIM"¡®ÓĞ·ïÀ´ÒÇ¡¯"NOR"½£ÊÆÑ¸ËÙÁèÀ÷Ö±Íù$nµÄ$l´ÌÈ¥\n",
"$N½£ÊÆÒ»¸ÄÍù³£µÄÆ®Òİ¾øÂ×£¬Ê¹³öÒ»ÕĞ"HIW"¡®"HIY"ÓñËéÏÉ¸Ô"HIW"¡¯"NOR"Ö±Ï÷ºáÅü¡¢ÆøÊÆÍşÃÍµÄÍù$nÉíÉÏ´óÁ¦Õ¶È¥\n",
"$N½£ÊÆ´ó¿ª´óãØ£¬Ê¹³öÒ»ÕĞ"HIC"¡®ÅüÖñÉ¨Ó°¡¯"NOR"¿ñ·ç±©Óê°ãµÄÕĞÊ½Ê¹$n¸Ğµ½ÄÑÒÔÕĞ¼Ü\n",
"$N½£¼âÁ¬»®³ö¼¸¸ö½£»¨£¬Ò»ÕĞ"HIW"¡®Æ®ÔÆ´©Ñ©¡¯"NOR"Èç¸¡ÔÆ°ãÆ®Òİ£¬»¯³ÉÆ¬Æ¬°×Ñ©»º»ºÂäÓÚ$nµÄÉíÉÏ\n",
"$N½«ÊÖÖĞµÄ$wĞ±Òı£¬Ê¹³öÒ»ÕĞ"HIW"¡®ÇÍ±Ú¶ÏÔÆ¡¯"NOR"£¬½£ÊÆĞÛÎ°¾«ÆæÆøÊÆ×İºáÊ¹$n¸Ğµ½×óÖ§ÓÒ×¾ÄÑÒÔÕĞ¼Ü\n",
"$NÕæÆø¹àÓÚÊÖÖĞµÄ$w£¬Ê¹³öÒ»ÕĞ"HIR"¡®·Éºçºá½­¡¯"NOR"¶ÙÊ±½£¼â³å³ö°ë³ßÀ´³¤µÄºìÉ«½£Ã¢£¬ÍÌÍÂÉÁË¸£¬àÍàÍÉùÏì´¦Íù$n¼²´Ì¶øÈ¥\n",
"$NÊÖÖĞµÄ$wÒ»ÉÁ³öÇÊ£¬º®Ã¢ÍÌÍÂ£¬µçÉÁĞÇË¸£¬Ò»ÕĞ"HIB"¡®º®Ã¢³åÏö¡¯"NOR"½£Æø»¯³Éµãµãº®Ã¢Íù$nÉíÉÏ·ÉÈ¥\n",
"$NÒ»ÉùÇåĞ¥£¬ÊÖÖĞ³¤½£¶¶¶¯´¦ÊıÒÔ°Ù¼ÆµÄÓñÉ«¹âÃ¢´Ó$NµÄ½£¼â¼²·É¶ø³ö£¬²ÓÀÃÈçÒøºÓ·É½¦£¬ÕıÊÇÒ»ÕĞ"HIW"¡®"HIY"¾¡ÇãÒøºÓ"HIW"¡¯\n"NOR,
"$NÊ¹³öÏÉ½£ÅÉÖ®¾øÕĞ"HIG"¡®¸ôÖ½¶ÏÊ÷¡¯"NOR"£¬ÊÖÖĞµÄ$wĞé»®£¬$nãµÈ»²»Ã÷ËùÒÔÖ®¼Ê²»Öª×Ô¼º½îÂöÒÑ±»Õ¶¶Ï...\n",
"$N½£·ºÏÉÆø£¬¾Û¾«»áÉñµØÊ¹³öÁËÏÉ½£½£ÊõÖĞµÄ×î¸ß¾³½ç"HIY"¡®ÏÉÇãËªÌì¡¯"NOR"£¡½£ÓÉÏÉ»¯£¬Ê¹½£ÈôÏÉ£¬½ğ¹âÉÁÒ«ÏÂ$nÈ«ÉíÒÑ±»¸îÉË¶à´¦...\n",
});



mapping *action = ({
//1
        ([      
                "action"     :               HIC"$NÊÕ¹âÎªÔÎÁ²¸Õ³ÉÈá£¬Ê¹³öÁËÏÉ½£½û¶ÏÖ®Á¬ÑôÆß¾÷µÚ¶şÊ½"HIY"¡®²ĞÑô¡¯"HIC"£¬Ë²¼äÉí»¯²ĞÓ°Âä²½£¬½£¼â·ÖÖ¸$n$l"NOR,
                "dodge"      :               -100,
                "parry"      :               -100,
                "damage"     :                200,
                "force"      :                200,
                "post_action":                (: sp_attack0 :),
                "damage_type":               "´ÌÉË"
        ]),
//2
        ([     
                "action"     :               HIC"$N²½ÈôÓÎ¹âÊ¹³öÏÉ½£½û¶ÏÖ®Á¬ÑôÆß¾÷µÚËÄÊ½"HIY"¡®Å¯Ñô¡¯"HIC"£¬½£ÆøºæÈ¼£¬Ò»Á÷ºê´óµÄ½£Ñ¹ÇúµØ±Æ½ü$n"NOR,
                "dodge"      :                -100,
                "parry"      :                -100,
                "damage"     :                200,
                "force"      :                200,
                "post_action":                (: sp_attack1 :),
                "damage_type":               "´ÌÉË"
        ]),
//3
        ([   
                "action"     :               HIC"$N·ÉÉí¸ßÔ¾Ù¿È»Ê¹³öÁËÏÉ½£½û¶ÏÖ®Á¬ÑôÆß¾÷µÚÈıÊ½"HIY"¡®ÑŞÑô¡¯"HIC"£¬½£¹âÈçºÆÈÕ»Ô»Í£¬±ÊÖ±ÂäÔÚ$nÃ¼ĞÄ"NOR,
                "dodge"      :                -100,
                "parry"      :                -100,
                "damage"     :                200,
                "force"      :                200,
                "post_action":                (: sp_attack2 :),
                "damage_type":               "´ÌÉË"
        ]),
//4
        ([  
                "action"     :               HIC"$N¸§½£Èç¾²£¬ĞÄÈôÖ¹Ë®½£¹âäòÑŞ£¬ÏÉ½£½û¶ÏÖ®Á¬ÑôÆß¾÷µÚÎåÊ½"HIY"¡®¶¬Ñô¡¯"HIC"·ºÆğ²¨²¨É±ÒâÈçÈĞÏò$nÈÆÁ÷¶øÈ¥"NOR,
                "dodge"      :                -100,
                "parry"      :                -100,
                "damage"     :                300,
                "force"      :                300,
                "post_action":                (: sp_attack3 :),
                "damage_type":               "¸îÉË"
        ]),
//5
        ([ 
                "action"     :               HIC"$NÊÖÀïµÄ$w"HIC"·º³öÕóÕóÈçÄºÉ«°ãµÄ½£Æø£¬ÏÉ½£½û¶ÏÖ®Á¬ÑôÆß¾÷µÚÆßÊ½"HIY"¡®Ï¦Ñô¡¯"HIC"ÓÌÈçÏ¼¹âÂúÌì¾¡Âä$nÉíÉÏ"NOR,
                "dodge"      :                -100,
                "parry"      :                -100,
                "damage"     :                300,
                "force"      :                300,
                "post_action":                (: sp_attack4 :),
                "damage_type":               "¸îÉË"
        ]),
//6
        ([
                "action"     :               HIC"$N·å»ØÂ·×ªÄÚ¾¢ÃÍÈ»ÉÏ´ÜÊ¹³öÏÉ½£½û¶ÏÖ®Á¬ÑôÆß¾÷µÚÒ»Ê½"HIY"¡®ÁÒÑô¡¯"HIC"£¬½£¹âÈçÁÒÑô¿ñÑæÖ±±¼$nĞÄ¿Ú"NOR,
                "dodge"      :                -100,
                "parry"      :                -100,
                "damage"     :                400,
                "force"      :                400,
                "post_action":                (: sp_attack5 :),
                "damage_type":               "´ÌÉË"
        ]),
//7
         ([     "action"     :               HIC"$N½«$w"HIC"ÊÕÇÊ¶øÈë£¬¾Û¾«ÄıÉñÊ¹³öÏÉ½£½û¶ÏÖ®Á¬ÑôÆß¾÷µÚÁùÊ½"HIY"¡®³¯Ñô¡¯"HIC"£¬Ö»¼û½£¹âÈç³¿¹âÕ§ÏÖ»®Ïò$n"NOR,
                "parry"      :                -100,
                "dodge"      :                -100,
                "damage"     :                400,
                "force"      :                400,
                "post_action":                (: sp_attack6 :),
                "damage_type":                "¸îÉË",
           ]),
});

int valid_learn(object me)
{
       if(!me->query("quest/sun_fire_sword",1)){
        tell_object(me,"Äã»¹²»¹»×Ê¸ñÁ·Á¬ÑôÆß¾÷½£·¨¡£\n");
        return 0;
                                               }

       if( !me->query_temp("weapon")){
        tell_object(me,"Á·Á¬ÑôÆß¾÷½£·¨±ØĞèÏÈÄÃ°Ñ½£¡£\n");
        return 0;
                                     }
       if( (me->query("potential") - me->query("learned_points")) < 5 ) {
        tell_object(me, "ÄãµÄÇ±ÄÜ²»µ½Îåµã£¬ÎŞ·¨Á·´Ë½£·¨¡£\n");
        return 0;
                                                                         }
        me->add("potential", -5);
        return   1;
}

int valid_enable(string usage)
{
        return ( usage=="sword" || usage=="parry" );
}


mapping query_action(object me, object *weapon)
{

 int skill_level,limit,i;

 skill_level = (int)(me->query_skill("sun_fire_sword",1));
 limit= skill_level;
     
        if (limit < 15)
                return action[random(1)];
        else if (limit < 30)
                return action[random(2)];
        else if (limit < 45)
                return action[random(3)];
        else if (limit < 60)
                return action[random(4)];
        else if (limit < 75)
                return action[random(5)];
        else if (limit < 90)
                return action[random(6)];
        else       
          return action[random(7)]; 
}

void sp_attack0(object me, object victim, object  weapon, int damage)
{
  string do_action;
  string arg;
  mixed all;
  object *enemy,who,room,weaponn,obj;
  string actionn;
  int i,j,force;

  force=me->query("force",1);
  enemy = me->query_enemy();
  i=random(sizeof(enemy));
if( me->query("family/family_name")=="ÏÉ½£ÅÉ"){  
//³öÏÖÂÊ 1/2*1/7=~7%

  if( random(2) == 0 && me->query("force") > 360 && !me->query_temp("conti",1)) {
  
message_vision(HIY"
¾ÍÔÚ$n±»»÷ÖĞµÄË²¼ä£¬$NĞÄ×ª"HIR"¡®²ĞÑôÇ§Òâ¡¯"HIY"£¬ÂÒ²½·ÖÓ°ÕÚ¹âÎª»Ã
Ò»ĞÄÇ§ÇĞ£¬Í¬Ò»°Ñ½££¬ÎèµÄÈ´ÊÇ²»Í¬µÄÕĞÊ½£¬ÕĞÕĞ³¯×Å$nµÄÒªÑ¨´ÜÈ¥
\n"NOR,me,victim);
          
    for(j=0; j < 12; j++) {
       do_action = shasword[j];
       actionn = "\n";
       actionn += do_action;
     
       if( weaponn=me->query_temp("weapon") )
       actionn = replace_string(actionn, "$w", weaponn->name());
       message_vision(actionn, me, enemy[i]);
          if( random(me->query("combat_exp")) >
        random(enemy[i]->query("combat_exp"))/6 ) {
        message_vision("\nµ«ÊÇ$NÉÁ¶ã²»¼°£¬ÉíÉÏ¶ÙÊ±¶à³öÁËÒ»µÀÑªÁÜÁÜµÄ½£ºÛ¡£\n" , enemy[i]);
        enemy[i]->receive_damage("kee",40,me);
        me->add("force",-30);
        COMBAT_D->report_status(enemy[i]);
                                                  }
   else message_vision("\n$NÈË±È½£¿ì, ¾ªÏÕµØÉÁ¹ıÁËÕâÒ»ÕĞ¡£\n" , enemy[i]);
                             }
//ÕâÀï¸øcpsµÈÓÚ10µÄppl »ú»áÒÔ¸ßexp Ñ¹µÍ delay »úÂÊ
     if( random(me->query("cps")) < 8 && random(me->query("combat_exp",1)) < 900000) {
        me->add("force",-100);
        message_vision("\n$NÊ¹Íê"HIY"¡®²ĞÑôÇ§Òâ¡¯"NOR"ºó£¬ÓÉÓÚ¶¨Á¦»ò¾­Ñé²»×ã£¬ÌåÄÚÕæÆøÒ»Ê±ÎŞÒÔÎª¼Ì\n",me);
        me->start_busy(1);
                                        }
                                                          }
                                                }
 
}

void sp_attack1(object me, object victim, object  weapon, int damage)
{
    sp_value =4*(str+cor)+cps+kar+spi+int1;
if( me->query("family/family_name")=="ÏÉ½£ÅÉ"){
    message_vision(HIW"
½£Ñ¹Á÷¶¯£¬Ëæ×Å$NµÄĞÄÄîÔ½·¢Ç¿ÁÒ£¬$nÎŞ´Ó·´¶¯£¬ÍêÍêÈ«È«
ÊÜµ½½£Ñ¹µÄ¿ØÖÆ£¬ÑÜÉúÒ»Ê½"HIY"¡®Å¯ÑôÓ¡¾³¡¯"HIW"¼¤³öµÄ½£ºçÔÚ¿ÕÖĞ²»Í£µØ¾Û
ºÏÅÌĞı£¬É²ÄÇ¼ä!!ÌìµØ±äÉ«·çÆğÔÆÓ¿£¬Ò»ÂÖÅ¯ÈÕÔÚ¿ÕÆøÖ®¼äÏÖĞÎ¶øÉú
$n±»´ËÇé¾°ËùÕğÉå£¬Ò»Ë²¼äÒÑ±»ÍÌÃ»ÓÚ¹âÃ¢Ö®ÖĞ
\n"NOR,me,victim);

   victim->receive_damage("kee",sp_value/2,me);
   COMBAT_D->report_status(victim);
                                              }
}

void sp_attack2(object me, object victim, object  weapon, int damage)
{
    sp_value =4*(spi+int1)+cps+kar+str+cor;
if( me->query("family/family_name")=="ÏÉ½£ÅÉ"){
    message_vision(HIY"
¾ÍÔÚÍ¬Ê±£¬$NĞÄÀ©ÌìµØ£¬»³ÈôÓîÖæ£¬¿ñ±¼µÄìåÆøË²¼äÆ½Ï¢£¬$NÓë
ÌìµØ·Â·ğ½áºÏÎªÒ»£¬Èğ¹âÑŞÀö¹â²Ê¶áÄ¿£¬ÄıÖ¹×¡È«²¿µÄµÄ¶¯×÷ 
Ò»Ê½"HIW"¡®ÑŞÑôÈı½£--ÌìµØÈË¡¯"HIY"Ñ¸ÈçÀ×¹âÂäÏò$n
\n"NOR,me,victim);

   victim->receive_damage("kee",sp_value/2,me);
if(random(100) > 80) {
   victim->set_temp("no_power",1);
   victim->apply_condition("no_power",1);
}
   COMBAT_D->report_status(victim); 
                                              }
}

void sp_attack3(object me, object victim, object  weapon, int damage)
{
    sp_value =4*(cps+kar)+str+cor+spi+int1;
if( me->query("family/family_name")=="ÏÉ½£ÅÉ"){
    message_vision(HIW"
$NÄÚ¾¢¶Ù×ªÊ¹³öÁ¬ÑôÎ¨Ò»Òõº®Ö®ÕĞ£¬Ë²Ê±¼äÒ»¹Éº®ÆøÁıÕÖÉíÅÔ£¬Ö»¼û
½£ÉÏ±¡±ù½¥Æğ»Ã³É±ùÖù£¬$NÓúÊ¹Óú¿ì£¬ÍğÈôĞÚÓ¿¾ŞÀËË²Ê±Ñ¹Á¦åáÔöö®
Ê±ËÄÖÜË®²¨ÔÆÆø±ä»¯ÍòÇ§£¬$nË²¼ä·Ö²»Çå½£ÔÚºÎ·½, ¾ÍÔÚ³ÙÒÉÖ®
¼Ê£¬$NÒ»Ê½"HIC"¡®¶¬ÑôÌì±ù¡¯"HIW"¾íÆğ¿ñËªÂÒÑ©Ö±µ·$nĞÄ¿Ú
\n"NOR,me,victim);

    victim->receive_damage("kee",sp_value/2,me);
    COMBAT_D->report_status(victim);
                                              }
}

void sp_attack4(object me, object victim, object  weapon, int damage)
{
    int i;
if( me->query("family/family_name")=="ÏÉ½£ÅÉ"){
    message_vision(HIR"
$N³ÃÊÆ·­Éí·ÉÔ¾£¬Ğ±»Ø½£¼â£¬Äî×ªÁé¶¯Ê¹³ö"HIW"¡®ºìÈ¾Ï¦Ñô¡¯"HIR"£¬ö®Ê±
É±Òâ¿ñ±¼£¬ÓûÊÉÑªĞÈÎŞ·¨×ÔÖÆ£¬½£¹Ä·çĞı£¬Á¬Ëø³ÉÎŞÊıÎŞĞÎ·çÈĞ£¬Ï÷
Èâ¹Î¹ÇÓû°Õ²»ÄÜ
"NOR,me,victim);

    me->set_temp("conti",1);
    for(i=0; i<3 ;i++)
    COMBAT_D->do_attack(me, victim, me->query_temp("weapon"), TYPE_QUICK);
    me->delete_temp("conti");
                                              }  
}

void sp_attack5(object me, object victim, object  weapon, int damage)
{
  string do_action;
  string arg;
  mixed all;
  object *enemy,who,room,weaponn,obj;
  string actionn;
  int i,j,force;
  
  force=me->query("force",1);
  enemy = me->query_enemy();
  i=random(sizeof(enemy));
  
//³öÏÖÂÊ 1/2*1/7=~7%
if( me->query("family/family_name")=="ÏÉ½£ÅÉ"){
if( random(2) == 0 && me->query("force") > 510 && !me->query_temp("conti",1)) {
message_vision(HIR"
Õ£ÑÛ¼ä£¬½£·æ·º»ğ£¬»ğ¹â½¥ÈçÑæÈÕ±ÆÈË£¬$NÈç»¯×£ÈÚÈ«Éí»ğºì
İëµØÒ»Éù´óºÈ"HIW"¡®[31;1m¡õ[37;1mP[31;1m¡õ[37;1m¡õ[31;1m¡õ[37;1mQ[31;1m¡õ[37;1mC[31;1m¡õ[37;1m©xz"HIR"£¬ÊÖÖĞ³¤½£ÓÌËÆ»ğÁú´İÌì£¬½£»ÃÇ§Íò»ğ
¾æÖ»ÔÚÒ»Ë²¼ä$nÒÑÍêÈ«»ğÁú±»ÍÌÃ»
\n"NOR,me,victim);            
    for(j=0; j < 17; j++) {
       do_action = lan_yan[j];
       actionn = "\n";
       actionn += do_action;

       if( weaponn=me->query_temp("weapon") )
       actionn = replace_string(actionn, "$w", weaponn->name());
       message_vision(actionn, me, enemy[i]);
          if( random(me->query("combat_exp")) >
        random(enemy[i]->query("combat_exp"))/6 ) {
        message_vision("\nµ«ÊÇ$NÉÁ¶ã²»¼°£¬ÉíÉÏ¶ÙÊ±¶à³öÁËÒ»µÀÑªÁÜÁÜµÄ½£ºÛ¡£\n" , enemy[i]);
        enemy[i]->receive_damage("kee",60,me);
        me->add("force",-30);
        COMBAT_D->report_status(enemy[i]);
                                                  }
   else message_vision("\n$NÈË±È½£¿ì£¬¾ªÏÕµØÉÁ¹ıÁËÕâÒ»ÕĞ¡£\n" , enemy[i]);
                             }
//ÕâÀï¸øcpsµÈÓÚ10µÄppl »ú»áÒÔ¸ßexp Ñ¹µÍ delay »úÂÊ
     if( random(me->query("cps")) < 10 && random(me->query("combat_exp",1)) < 900000) {
        me->add("force",-100);
        message_vision("\n$NÊ¹Íê"HIR"¡®ÁÒÑôÊ®ÆßÊ½¡¯"NOR"ºó£¬ÓÉÓÚ¶¨Á¦»ò¾­Ñé²»×ã£¬ÌåÄÚÕæÆøÒ»Ê±ÎŞÒÔÎª¼Ì\n",me);
        me->start_busy(1);
                                        }
                                                  }
                                             }
 
}


void sp_attack6(object me, object victim, object  weapon, int damage)
{
    int i;
    sp_value =4*(str+cor+cps)+spi+int1+kar;
  if (sp_value > 250) sp_value=250;
if( me->query("family/family_name")=="ÏÉ½£ÅÉ"){
    message_vision(HIY"
Ë²¼ä£¬$NÔÙÊÕ½£ÈëÇÊ£¬ĞÄÄıÒ»Ê½"HIW"¡®³¯ÑôÔÙÏÖ¡¯"HIY"£¬»ØÉí·ÉĞı£¬¼¸ºõÊÇ
Í¬Ê±£¬³¤½£ÒÑÀëÇÊÖ±»®$nµÄÑÊºí
\n"NOR,me,victim);
   if( weapon->query("id")=="sun_fire_sword"){
    message_vision(HIY"Áé½£Á¬ÑôËæ×Å¡®³¯ÑôÔÙÏÖ¡¯ÕâÒ»Ê½É¢·¢³ö¿ªÌìÇ±²ØµÄÁéÆø£¬É²ÄÇ¼ä!½£·º½ğ¹â
ÍêÈ«ÕÕÁÁÁË°µÓ°£¬ÈçÇ§°Ù¸öÌ«ÑôÔÚ$NµÄÊÖÖĞ£¬Ò»ÆëÉä³öÎŞÓëÂ×±ÈµÄ¹âÃ¢£¬Áî$n¸ù±¾ÎŞ·¨
±ÆÊÓ\n"NOR,me,victim);
    victim->receive_wound("kee",sp_value+150,me);
    victim->start_busy(1);
if(random(100) > 70) {
    victim->set_temp("no_power",1);
    victim->apply_condition("no_power",1);
}
    COMBAT_D->report_status(victim);
                                             }
   else{
    victim->receive_wound("kee",sp_value,me);
if(random(100) > 80) {
    victim->set_temp("no_power",1);
    victim->apply_condition("no_power",1);
}
    COMBAT_D->report_status(victim);
       }
                                              }
}


string query_parry_msg(string limb)
{
 object me=this_player();
 object weapon=me->query_temp("weapon");

  if(weapon && weapon->query("skill_type")=="sword")
      return parry_msg[random(sizeof(parry_msg))];
  else 
      return unarmed_parry_msg[random(sizeof(unarmed_parry_msg))];
}

string perform_action_file(string action)
{
          return CLASS_D("swordsman")+"/shasword/"+action;
}   
        
