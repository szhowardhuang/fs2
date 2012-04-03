// ¡¨—Ù∆ﬂæ˜Ω£∑®
//»°¥˙‘≠¿¥µƒ—∏¿◊Ω£∑® && Ã·∏ﬂΩ‚√‘ƒ—∂»
//roger && taifar”⁄ 98/8/16

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
"\n∂¯$n ÷÷–µƒ≥§Ω£“ª∫·£¨“ª’–"HIB"°ÆÃ˙À¯∫·Ω≠°Ø"NOR" ∆–Æ«ßΩÔÕ˘«∞“ªÕ∆“ªÀÕ£¨µ±µƒ“ª…˘≈ˆ≥ˆ¡Àµ„µ„ªª®∑¥∞—$N ÷÷–µƒ$wœ’–©’∑…£°\n"NOR,
"\nµ´$n≥§Ω£“ª◊™£¨À≥◊≈$Nµƒ$w“‘“ª’–"HIC"°ÆÀ≥¡˜∂¯œ¬°Ø"NOR"Õ˘$Nµƒ ÷÷∏œ˜»•£¨$N¥Ûæ™ ß…´œ¬º±√¶ ’’–ªÿº‹\n",
"\n$nΩ£◊ﬂ«·¡È£¨ ÷÷–≥§Ω£∫ˆœ˜∫ˆ¥Ã“ª¡¨¥Æµƒ±¯∆˜◊≤ª˜…˘∫Û$n“—Ω´$NµƒøÏ’–»´≤øªØΩ‚£°\n",
HIW"\n$n“‘øÏ÷∆øÏ£¨$NøÏµ´$n∏¸øÏ£¨¡¨–¯¥Ã≥ˆ¡À∆ﬂ∆ﬂÀƒ Ææ≈Ω£÷Ø≥…“ªµ¿Ω£Õ¯Ω´$Nµƒ’– Ωæ° ˝µ¥ø™£°\n"NOR,    
        });

string *unarmed_parry_msg = ({
"µ´ «±ª$n∏Òø™¡À°£\n",
"Ω·π˚±ª$nµ≤ø™¡À°£\n",
});

string *lan_yan = ({
HIW"$N π≥ˆ¡“—Ùµ⁄“ª Ω"HIR"°Æ∫∆»’≥ı…˝°Ø"HIW"£¨ ÷÷–µƒ$w"HIW"øÏÀŸŒË∂Ø◊≈£¨–Æ◊≈’Û’Û¡“∑ÁœÆœÚÀƒ÷‹£¨“ª ±º‰Ω£∆¯◊›∫·\n"NOR,
HIW"$N ÷÷–$w"HIW"Õª»ªŒÀŒÀæﬁœÏ£¨ π≥ˆ¡“—Ùµ⁄∂˛ Ω"HIR"°Æ¡“»’∆» ¿°Ø"HIW"£¨ ÷÷–$w"HIW"£¨∑¢≥ˆ≈˘ˆ®æﬁœÏ¥ÃœÚÀƒ÷‹µƒµ–»À\n"NOR,
HIW"$N ÷÷–$w"HIW"º±ÀŸ≤¸∂Ø£¨À≤º‰¬˙ÃÏΩ£ª®…¡…¡£¨’˝ «¡“—Ùµ⁄»˝ Ω"HIR"°Æ«ßª™”≥»’°Ø"HIW"£¨’–»Á∆‰√˚£¨÷ªº˚µ–»Àµƒ—™»Á¬‰ª®∞„∑…Ω¶...\n"NOR,
HIW"$N…Ì–Œº±–˝£¨ π≥ˆ¡“—Ùµ⁄Àƒ Ω"HIR"°Æ∑Á…≥◊∆»’°Ø"HIW"£¨÷ªº˚ªÎÃÃµƒ∑ÁæÌ∆πˆπˆ≥æ…≥£¨¡Ó»À√˛≤ª«Â$N‘⁄∫Œ∑Ω...\n"NOR,
HIW"$N ÷ƒÛΩ£æ˜£¨∫ˆ»ª ÷÷–µƒ$w"HIW"Õ˘ÃÏø’∑…»•£¨À≤ ±º‰ ˝µ¿Ω£∆¯Õ˘œ¬º§…‰£¨’˝ «¡“—Ùµ⁄ŒÂ Ω"HIR"°Æ∫Á‘∆π˝»’°Ø\n"NOR,
HIW"$N π≥ˆ¡“—Ùµ⁄¡˘ Ω"HIR"°Æ…˝¡˙–˝»’°Ø"HIW"…Ì–Œ”Ã»Á“ªÃıª“¡˙º±–˝∂¯…œ£¨«“…¢∑¢≥ˆ◊∆»»µƒ∆¯œ¢œÆœÚÀƒ÷‹£¨∫√œÒ“™“ªæŸÕÃ√ªµ–»ÀÀ∆µƒ\n"NOR,
HIW"$N¥Û∫»“ª…˘£¨ π≥ˆ¡“—Ùµ⁄∆ﬂ Ω"HIR"°Æ¡“»’µ±ø’°Ø"HIW"£¨“ªÀ≤º‰“—œÚÀƒ÷‹¥Ã≥ˆ¡À∆ﬂ∆ﬂÀƒ Ææ≈Ω£!\n"NOR,
HIW"$N ÷÷–µƒ$w"HIW"£¨∫ˆ≈¸∫ˆ¥Ã£¨“ª’–¡“—Ùµ⁄∞À Ω£¨"HIR"°Æ—Ê»’∆»¿◊°Ø"HIW" πΩ´≥ˆ¿¥£¨Àƒ÷‹œÏ∆¡À¬°¬°æﬁœÏ!\n"NOR,
HIW"$N ÷÷–µƒ$w"HIW"Ω£√¢∫ˆ»ª“ª≥§£¨ π≥ˆ¡“—Ùµ⁄æ≈ Ω"HIR"°ÆªÆ»’∑…µÁ°Ø"HIW"£¨÷ªº˚Ω£√¢≤ªÕ£µƒÕÃÕ¬…¡À∏£¨¡Ó»À—€ª®¡√¬“º‰$w"HIW"£¨“—¥©ÃÂ∂¯≥ˆ...\n"NOR,
HIW"$N π≥ˆæ¯∂•«·π¶£¨“ª’–¡“—Ùµ⁄ Æ Ω"HIR"°Æ±Œ”Í»»»’°Ø"HIW"£¨ πΩ´≥ˆ¿¥£¨÷‹Œßµ–»À∑◊∑◊≤ª◊°µÿµπÕÀ...\n"NOR,
HIW"$N…Ì–Œ“ªªŒ£¨ ÷÷–$w"HIW"£¨≤ªæ¯µƒœÚµ–»À◊∑ÀÊ∂¯»•£¨’˝ «¡“—Ùµ⁄ Æ“ª Ω"HIR"°Æ–±»’π“”∞°Ø"HIW"£¨¡Óµ–»À±‹Œﬁø…±‹\n"NOR,
HIW"$N ÷÷–µƒ$w"HIW"∫ˆ»ª±‰≥…»Ì»Ì√‡√‡£¨Ω£’–»• ∆πÓ“Ïƒ™≤‚£¨’˝ «¡“—Ùµ⁄ Æ∂˛ Ω"HIR"°Æ“ı‘∆—⁄»’°Ø"HIW"¡Óµ–»ÀŒﬁ¥”’–º‹∆\n"NOR,
HIW"$N ÷÷–µƒ$w"HIW"∑……‰∂¯≥ˆ£¨ π≥ˆ¡“—Ùµ⁄ Æ»˝ Ω"HIR"°Æ»–»’∑…∑Á°Ø"HIW"£¨÷ªº˚$w"HIW"‘⁄$NÀ´ ÷’Ê∆¯µƒøÿ÷∆œ¬“‘º´∏ﬂµƒÀŸ∂»¥ÃœÚ÷‹Œßµƒµ–»À°£\n"NOR,
HIW"$N π≥ˆ¡“—Ùµ⁄ ÆÀƒ Ω"HIR"°Æ—◊»’«ß”°°Ø"HIW"£¨ ÷÷–µƒ$w"HIW"∫ˆ»ª∑…øÏµƒŒË∂Ø£¨–Œ≥…“ªµ¿µ¿ª√”∞¥ÃœÚ÷‹Œßµƒµ–»À°£\n"NOR,
HIW"$N ÷÷–µƒ$w"HIW"Õ˘Õ‚“ª∑÷£¨∫ˆ»ªªØ≥…≥…«ß…œÕÚµƒª√”∞¡˝’÷◊≈Àƒ÷‹µƒµ–»À£¨’˝ «¡“—Ùµ⁄ ÆŒÂ Ω"HIR"°Æª√»’¡˜π‚°Ø"HIW"£¨÷‹Œßµ–»À∑◊∑◊ÕÀ»¥...\n"NOR,
HIW"$NΩ´ ÷÷–µƒ$w"HIW"ŒËµ√∏¸º±£¨ π≥ˆ¡“—Ùµ⁄ Æ¡˘ Ω"HIR"°ÆøÒ»’æ° ¥°Ø"HIW"£¨Ω£∑®øÏµƒ¡¨Ω£µƒ◊Ÿ”∞∂ºø¥≤ªµΩ÷ªÃ˝“ª…˘≤“∫≈$n“—±ª¥Ã…À!°£\n"NOR,
HIW"$N π≥ˆ¡“—Ùµ⁄ Æ∆ﬂ Ω"HIR"°ÆŒ±»’Œ™’Ê°Ø"HIW"£¨Ω£∑®÷ÆøÏ£¨’– Ω÷Æ¿±£¨ µ“—¡Ó»À∑À“ƒÀ˘Àº£¨À˘¥Ã≥ˆµƒ√ø“ª’–Ω‘¡Óµ–»À ‹µΩ÷ÿ¥¥\n"NOR,
});

string *shasword = ({
"$N ÷ƒÛΩ£æ˜£¨≥§Ω£“ªÕ¶£¨ π≥ˆ“ª’–"HIC"°Æ»™√˘‹Ω»ÿ°Ø"NOR"£¨◊ÀÃ¨”∆—≈£¨∆ƒ”–ÃÏ…œœ…»Àœ¬∑≤º‰÷Æ“‚\n",
"$N“ª∏ˆ–˝…Ì£¨ ÷÷–µƒ$w‘⁄ø’÷–…¡π˝“ªµ¿π‚√¢÷±¥ÃœÚ$nµƒ$l£¨◊ÀÃ¨‰Ï»˜“ª∆¯∫«≥…£¨’˝ «“ª’–"HIY"°ÆΩ—„∫·ø’°Ø\n"NOR,
"$N◊ÛºÁŒ¢≥¡£¨◊Û ÷Ω£æ˜–±“˝£¨”“÷‚“ªÀı£¨ π≥ˆ“ª’–"HIM"°Æ”–∑Ô¿¥“«°Ø"NOR"Ω£ ∆—∏ÀŸ¡Ë¿˜÷±Õ˘$nµƒ$l¥Ã»•\n",
"$NΩ£ ∆“ª∏ƒÕ˘≥£µƒ∆Æ“›æ¯¬◊£¨ π≥ˆ“ª’–"HIW"°Æ"HIY"”ÒÀÈœ…∏‘"HIW"°Ø"NOR"÷±œ˜∫·≈¸°¢∆¯ ∆Õ˛√ÕµƒÕ˘$n…Ì…œ¥Û¡¶’∂»•\n",
"$NΩ£ ∆¥Ûø™¥Û„ÿ£¨ π≥ˆ“ª’–"HIC"°Æ≈¸÷Ò…®”∞°Ø"NOR"øÒ∑Á±©”Í∞„µƒ’– Ω π$n∏–µΩƒ—“‘’–º‹\n",
"$NΩ£º‚¡¨ªÆ≥ˆº∏∏ˆΩ£ª®£¨“ª’–"HIW"°Æ∆Æ‘∆¥©—©°Ø"NOR"»Á∏°‘∆∞„∆Æ“›£¨ªØ≥…∆¨∆¨∞◊—©ª∫ª∫¬‰”⁄$nµƒ…Ì…œ\n",
"$NΩ´ ÷÷–µƒ$w–±“˝£¨ π≥ˆ“ª’–"HIW"°Æ«Õ±⁄∂œ‘∆°Ø"NOR"£¨Ω£ ∆–€Œ∞æ´∆Ê∆¯ ∆◊›∫· π$n∏–µΩ◊Û÷ß”“◊æƒ—“‘’–º‹\n",
"$N’Ê∆¯π‡”⁄ ÷÷–µƒ$w£¨ π≥ˆ“ª’–"HIR"°Æ∑…∫Á∫·Ω≠°Ø"NOR"∂Ÿ ±Ω£º‚≥Â≥ˆ∞Î≥ﬂ¿¥≥§µƒ∫Ï…´Ω£√¢£¨ÕÃÕ¬…¡À∏£¨‡Õ‡Õ…˘œÏ¥¶Õ˘$nº≤¥Ã∂¯»•\n",
"$N ÷÷–µƒ$w“ª…¡≥ˆ« £¨∫Æ√¢ÕÃÕ¬£¨µÁ…¡–«À∏£¨“ª’–"HIB"°Æ∫Æ√¢≥Âœˆ°Ø"NOR"Ω£∆¯ªØ≥…µ„µ„∫Æ√¢Õ˘$n…Ì…œ∑…»•\n",
"$N“ª…˘«Â–•£¨ ÷÷–≥§Ω£∂∂∂Ø¥¶ ˝“‘∞Ÿº∆µƒ”Ò…´π‚√¢¥”$NµƒΩ£º‚º≤∑…∂¯≥ˆ£¨≤”¿√»Á“¯∫”∑…Ω¶£¨’˝ «“ª’–"HIW"°Æ"HIY"æ°«„“¯∫”"HIW"°Ø\n"NOR,
"$N π≥ˆœ…Ω£≈…÷Ææ¯’–"HIG"°Æ∏Ù÷Ω∂œ ˜°Ø"NOR"£¨ ÷÷–µƒ$w–ÈªÆ£¨$n„µ»ª≤ª√˜À˘“‘÷Æº ≤ª÷™◊‘º∫ΩÓ¬ˆ“—±ª’∂∂œ...\n",
"$NΩ£∑∫œ…∆¯£¨æ€æ´ª·…Òµÿ π≥ˆ¡Àœ…Ω£Ω£ ı÷–µƒ◊Ó∏ﬂæ≥ΩÁ"HIY"°Æœ…«„À™ÃÏ°Ø"NOR"£°Ω£”…œ…ªØ£¨ πΩ£»Ùœ…£¨Ωπ‚…¡“´œ¬$n»´…Ì“—±ª∏Ó…À∂‡¥¶...\n",
});



mapping *action = ({
//1
        ([      
                "action"     :               HIC"$N ’π‚Œ™‘Œ¡≤∏’≥…»·£¨ π≥ˆ¡Àœ…Ω£Ω˚∂œ÷Æ¡¨—Ù∆ﬂæ˜µ⁄∂˛ Ω"HIY"°Æ≤–—Ù°Ø"HIC"£¨À≤º‰…ÌªØ≤–”∞¬‰≤Ω£¨Ω£º‚∑÷÷∏$n$l"NOR,
                "dodge"      :               -100,
                "parry"      :               -100,
                "damage"     :                380,
                "force"      :                330,
                "post_action":                (: sp_attack0 :),
                "damage_type":               "¥Ã…À"
        ]),
//2
        ([     
                "action"     :               HIC"$N≤Ω»Ù”Œπ‚ π≥ˆœ…Ω£Ω˚∂œ÷Æ¡¨—Ù∆ﬂæ˜µ⁄Àƒ Ω"HIY"°Æ≈Ø—Ù°Ø"HIC"£¨Ω£∆¯∫Ê»º£¨“ª¡˜∫Í¥ÛµƒΩ£—π«˙µÿ±∆Ω¸$n"NOR,
                "dodge"      :                -100,
                "parry"      :                -100,
                "damage"     :                350,
                "force"      :                340,
                "post_action":                (: sp_attack1 :),
                "damage_type":               "¥Ã…À"
        ]),
//3
        ([   
                "action"     :               HIC"$N∑……Ì∏ﬂ‘æŸø»ª π≥ˆ¡Àœ…Ω£Ω˚∂œ÷Æ¡¨—Ù∆ﬂæ˜µ⁄»˝ Ω"HIY"°Æ—ﬁ—Ù°Ø"HIC"£¨Ω£π‚»Á∫∆»’ª‘ªÕ£¨± ÷±¬‰‘⁄$n√º–ƒ"NOR,
                "dodge"      :                -100,
                "parry"      :                -100,
                "damage"     :                400,
                "force"      :                350,
                "post_action":                (: sp_attack2 :),
                "damage_type":               "¥Ã…À"
        ]),
//4
        ([  
                "action"     :               HIC"$N∏ßΩ£»Áæ≤£¨–ƒ»Ù÷πÀÆΩ£π‚‰Ú—ﬁ£¨œ…Ω£Ω˚∂œ÷Æ¡¨—Ù∆ﬂæ˜µ⁄ŒÂ Ω"HIY"°Æ∂¨—Ù°Ø"HIC"∑∫∆≤®≤®…±“‚»Á»–œÚ$n»∆¡˜∂¯»•"NOR,
                "dodge"      :                -100,
                "parry"      :                -100,
                "damage"     :                420,
                "force"      :                370,
                "post_action":                (: sp_attack3 :),
                "damage_type":               "∏Ó…À"
        ]),
//5
        ([ 
                "action"     :               HIC"$N ÷¿Ôµƒ$w"HIC"∑∫≥ˆ’Û’Û»Áƒ∫…´∞„µƒΩ£∆¯£¨œ…Ω£Ω˚∂œ÷Æ¡¨—Ù∆ﬂæ˜µ⁄∆ﬂ Ω"HIY"°Æœ¶—Ù°Ø"HIC"”Ã»Áœºπ‚¬˙ÃÏæ°¬‰$n…Ì…œ"NOR,
                "dodge"      :                -100,
                "parry"      :                -100,
                "damage"     :                430,
                "force"      :                380,
                "post_action":                (: sp_attack4 :),
                "damage_type":               "∏Ó…À"
        ]),
//6
        ([
                "action"     :               HIC"$N∑Âªÿ¬∑◊™ƒ⁄æ¢√Õ»ª…œ¥‹ π≥ˆœ…Ω£Ω˚∂œ÷Æ¡¨—Ù∆ﬂæ˜µ⁄“ª Ω"HIY"°Æ¡“—Ù°Ø"HIC"£¨Ω£π‚»Á¡“—ÙøÒ—Ê÷±±º$n–ƒø⁄"NOR,
                "dodge"      :                -100,
                "parry"      :                -100,
                "damage"     :                440,
                "force"      :                390,
                "post_action":                (: sp_attack5 :),
                "damage_type":               "¥Ã…À"
        ]),
//7
         ([     "action"     :               HIC"$NΩ´$w"HIC" ’« ∂¯»Î£¨æ€æ´ƒ˝…Ò π≥ˆœ…Ω£Ω˚∂œ÷Æ¡¨—Ù∆ﬂæ˜µ⁄¡˘ Ω"HIY"°Æ≥Ø—Ù°Ø"HIC"£¨÷ªº˚Ω£π‚»Á≥øπ‚’ßœ÷ªÆœÚ$n"NOR,
                "parry"      :                -100,
                "dodge"      :                -100,
                "damage"     :                450,
                "force"      :                400,
                "post_action":                (: sp_attack6 :),
                "damage_type":                "∏Ó…À",
           ]),
//8 ≈—¿Îœ…Ω£≤ªƒ‹”√ by swy
(["action":"$N≈—¿Îœ…Ω£À˘“‘≤ªƒ‹Ω´¡¨—ÙΩ£ π≥ˆ°£",
  "force":10,
  "damage":10,
  "damage_type":"∞◊≥’…À",
]),
});

int valid_learn(object me)
{
       if(!me->query("quest/sun_fire_sword",1)){
        tell_object(me,"ƒ„ªπ≤ªπª◊ ∏Ò¡∑¡¨—Ù∆ﬂæ˜Ω£∑®°£\n");
        return 0;
}
        if(!me->query("get_sha_sp",1)){
        tell_object(me,"ƒ„ªπ≤ªπª◊ ∏Ò¡∑¡¨—Ù∆ﬂæ˜Ω£∑®°£\n");
        return 0;
                                               }

       if( !me->query_temp("weapon")){
        tell_object(me,"¡∑¡¨—Ù∆ﬂæ˜Ω£∑®±ÿ–Ëœ»ƒ√∞—Ω£°£\n");
        return 0;
                                     }
       if( (me->query("potential") - me->query("learned_points")) < 5 ) {
        tell_object(me, "ƒ„µƒ«±ƒ‹≤ªµΩŒÂµ„£¨Œﬁ∑®¡∑¥ÀΩ£∑®°£\n");
        return 0;
                                                                         }
        me->add("potential", -5);
        return   1;
}

int valid_study(object me)
{
       if(!me->query("quest/sun_fire_sword",1)){
        tell_object(me,"ƒ„ªπ≤ªπª◊ ∏Ò¡∑¡¨—Ù∆ﬂæ˜Ω£∑®°£\n");
        return 0;
}
        if(!me->query("get_sha_sp",1)){
        tell_object(me,"ƒ„ªπ≤ªπª◊ ∏Ò¡∑¡¨—Ù∆ﬂæ˜Ω£∑®°£\n");
        return 0;
                                               }

       if( !me->query_temp("weapon")){
        tell_object(me,"¡∑¡¨—Ù∆ﬂæ˜Ω£∑®±ÿ–Ëœ»ƒ√∞—Ω£°£\n");
        return 0;
                                     }
       if( (me->query("potential") - me->query("learned_points")) < 5 ) {
        tell_object(me, "ƒ„µƒ«±ƒ‹≤ªµΩŒÂµ„£¨Œﬁ∑®¡∑¥ÀΩ£∑®°£\n");
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
if(me->query("family/family_name")!="œ…Ω£≈…"  || me->query("killyao")==1)
return action[7];
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
//≥ˆœ÷¬  1/2*1/7=~7%

  if( random(2) == 0 && me->query("force") > 360 && !me->query_temp("conti",1)) {
  
message_vision(HIY"
æÕ‘⁄$n±ªª˜÷–µƒÀ≤º‰£¨$N–ƒ◊™"HIR"°Æ≤–—Ù«ß“‚°Ø"HIY"£¨¬“≤Ω∑÷”∞’⁄π‚Œ™ª√
“ª–ƒ«ß«–£¨Õ¨“ª∞—Ω££¨ŒËµƒ»¥ «≤ªÕ¨µƒ’– Ω£¨’–’–≥Ø◊≈$nµƒ“™—®¥‹»•
\n"NOR,me,victim);
          
    for(j=0; j < 12; j++) {
       do_action = shasword[j];
       actionn = "\n";
       actionn += do_action;
     
       if( weaponn=me->query_temp("weapon") )
       actionn = replace_string(actionn, "$w", weaponn->name());
       if(i>=sizeof(enemy)) i=0;
       if(!sizeof(enemy)) return ;
       if(!enemy[i]) i=0;
       if(!enemy[i] && !i) return;
       message_vision(actionn, me, enemy[i]);
          if( random(me->query("combat_exp")) >
        random(enemy[i]->query("combat_exp"))/6 ) {
        message_vision("\nµ´ «$N…¡∂„≤ªº∞£¨…Ì…œ∂Ÿ ±∂‡≥ˆ¡À“ªµ¿—™¡‹¡‹µƒΩ£∫€°£\n" , enemy[i]);
        enemy[i]->receive_damage("kee",45,me);
        me->add("force",-30);
        COMBAT_D->report_status(enemy[i]);
                                                  }
   else message_vision("\n$N»À±»Ω£øÏ, æ™œ’µÿ…¡π˝¡À’‚“ª’–°£\n" , enemy[i]);
                             }

     if( random(me->query("cps")) < 4 ) {
        me->add("force",-100);
        message_vision("\n$N πÕÍ"HIY"°Æ≤–—Ù«ß“‚°Ø"NOR"∫Û£¨”…”⁄∂®¡¶≤ª◊„£¨ÃÂƒ⁄’Ê∆¯“ª ±Œﬁ“‘Œ™ºÃ\n",me);
        me->start_busy(1);
                                        }
                                                          }
 
}

void sp_attack1(object me, object victim, object  weapon, int damage)
{
  sp_value =6*(str+cor)+cps+kar+spi+int1;

    message_vision(HIW"
Ω£—π¡˜∂Ø£¨ÀÊ◊≈$Nµƒ–ƒƒÓ‘Ω∑¢«ø¡“£¨$nŒﬁ¥”∑¥∂Ø£¨ÕÍÕÍ»´»´
 ‹µΩΩ£—πµƒøÿ÷∆£¨—‹…˙“ª Ω"HIY"°Æ≈Ø—Ù”°æ≥°Ø"HIW"º§≥ˆµƒΩ£∫Á‘⁄ø’÷–≤ªÕ£µÿæ€
∫œ≈Ã–˝£¨…≤ƒ«º‰!!ÃÏµÿ±‰…´∑Á∆‘∆”ø£¨“ª¬÷≈Ø»’‘⁄ø’∆¯÷Æº‰œ÷–Œ∂¯…˙
$n±ª¥À«Èæ∞À˘’…Â£¨“ªÀ≤º‰“—±ªÕÃ√ª”⁄π‚√¢÷Æ÷–
\n"NOR,me,victim);

   victim->receive_damage("kee",sp_value,me);
   COMBAT_D->report_status(victim);
}

void sp_attack2(object me, object victim, object  weapon, int damage)
{
  sp_value =6*(spi+int1)+cps+kar+str+cor;  

    message_vision(HIY"
æÕ‘⁄Õ¨ ±£¨$N–ƒ¿©ÃÏµÿ£¨ª≥»Ù”Ó÷Ê£¨øÒ±ºµƒÏÂ∆¯À≤º‰∆Ωœ¢£¨$N”Î
ÃÏµÿ∑¬∑Ω·∫œŒ™“ª£¨»π‚—ﬁ¿ˆπ‚≤ ∂·ƒø£¨ƒ˝÷π◊°»´≤øµƒµƒ∂Ø◊˜ 
“ª Ω"HIW"°Æ—ﬁ—Ù»˝Ω£--ÃÏµÿ»À°Ø"HIY"—∏»Á¿◊π‚¬‰œÚ$n
\n"NOR,me,victim);

   victim->receive_damage("kee",sp_value,me);
   victim->set_temp("no_power",1);
   victim->apply_condition("no_power",2);
   COMBAT_D->report_status(victim);
}

void sp_attack3(object me, object victim, object  weapon, int damage)
{
  sp_value =6*(cps+cor)+kar+cor+spi+int1;

    message_vision(HIW"
$Nƒ⁄æ¢∂Ÿ◊™ π≥ˆ¡¨—ÙŒ®“ª“ı∫Æ÷Æ’–£¨À≤ ±º‰“ªπ…∫Æ∆¯¡˝’÷…Ì≈‘£¨÷ªº˚
Ω£…œ±°±˘Ω•∆ª√≥…±˘÷˘£¨$N”˙ π”˙øÏ£¨Õ»Ù–⁄”øæﬁ¿ÀÀ≤ ±—π¡¶Â·‘ˆ
ˆÆ ±Àƒ÷‹ÀÆ≤®‘∆∆¯±‰ªØÕÚ«ß£¨$nÀ≤º‰∑÷≤ª«ÂΩ£‘⁄∫Œ∑Ω, æÕ‘⁄≥Ÿ“…÷Æ
º £¨$N“ª Ω"HIC"°Æ∂¨—ÙÃÏ±˘°Ø"HIW"æÌ∆øÒÀ™¬“—©÷±µ∑$n–ƒø⁄
\n"NOR,me,victim);

    victim->receive_damage("kee",sp_value,me);
    victim->set_temp("no_power",1);
    victim->apply_condition("no_power",2);
    COMBAT_D->report_status(victim);
}

void sp_attack4(object me, object victim, object  weapon, int damage)
{
    int i;
    message_vision(HIR"
$N≥√ ∆∑≠…Ì∑…‘æ£¨–±ªÿΩ£º‚£¨ƒÓ◊™¡È∂Ø π≥ˆ"HIW"°Æ∫Ï»æœ¶—Ù°Ø"HIR"£¨ˆÆ ±
…±“‚øÒ±º£¨”˚ …—™–»Œﬁ∑®◊‘÷∆£¨Ω£πƒ∑Á–˝£¨¡¨À¯≥…Œﬁ ˝Œﬁ–Œ∑Á»–£¨œ˜
»‚πŒπ«”˚∞’≤ªƒ‹
"NOR,me,victim);

    me->set_temp("conti",1);
    for(i=0; i<3 ;i++)
    COMBAT_D->do_attack(me, victim, me->query_temp("weapon"), TYPE_QUICK);
    me->delete_temp("conti");
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
  if(i>=sizeof(enemy)) i=0;
    if(!enemy[i]) i=0;
    if(!enemy[i]) return ;
  
//≥ˆœ÷¬  1/2*1/7=~7%

   if( random(2) == 0 && me->query("force") > 510 && !me->query_temp("conti",1) && enemy[i]) {
message_vision(HIR"
’£—€º‰£¨Ω£∑Ê∑∫ª£¨ªπ‚Ω•»Á—Ê»’±∆»À£¨$N»ÁªØ◊£»⁄»´…Ìª∫Ï
›Îµÿ“ª…˘¥Û∫»"HIW"°Æ[31;1m°ı[37;1mP[31;1m°ı[37;1m°ı[31;1m°ı[37;1mQ[31;1m°ı[37;1mC[31;1m°ı[37;1m©xz"HIR"£¨ ÷÷–≥§Ω£”ÃÀ∆ª¡˙¥›ÃÏ£¨Ω£ª√«ßÕÚª
æÊ÷ª‘⁄“ªÀ≤º‰$n“—ÕÍ»´ª¡˙±ªÕÃ√ª


                               ®x®Ü
                                 ®Ñ®Ü
                                ®Å  ®Ü                       ®Ü
                                 ®Ä  ®Ü                     ®x®Ü
                                ®Ä®Ä  ®Ü                      ®Ä
       ®x®Ü                    ®Ä ®Ä®Ñ ®Ü                   ®Ä®Ä®Ä
        ®Ñ ®Ü               ®Ä®Ä ®Ä®Ä®Ñ                ®Ü ®Ä®Ä ®Ä
        ®Ñ ®Ü               ®Ä®Ä ®Ä®Ä®Ñ                ®Ü ®Ä®Ä ®Ä
       ®Å ®Ü               ®Ä®Ä   ®Ä®Ä®Ä              ®Ç®Ä®Ä®Ä  ®Ä
     ®Ä®Ä ®Ç®Ñ            ®Ä®Ä®Ä    ®Ä®Ä®Ä®Ä           ®Ä®Ä®Ä  ®Ä®Ä®Ä®Ä
     ®Ä®Ä ®Ä®Ñ®Ç         ®Ä®Ä®Ä®Ä®Ä  ®Ä®Ä®Ä®Ä®Ä        ®Ä®Ä®Ä    ®Ä®Ä®Ä®Ä
    ®Ä®Ä  ®Ä®Ä®Ä®Ä    ®Ä®Ä®Ä®Ä®Ä®Ä  ®Ä®Ä®Ä®Ä®Ä       ®Ä®Ä®Ä®Ä®Ä    ®Ä®Ä®Ä®Ä
  ®Ä®Ä®Ä    ®Ä®Ä    ®Ä®Ä®Ä®Ä®Ä®Ä    ®Ä®Ä®Ä®Ä®Ä®Ä  ®Ä®Ä®Ä®Ä®Ä®Ä®Ä    ®Ä®Ä®Ä®Ä
®Ä®Ä®Ä    ®Ä®Ä®Ä®Ä   ®Ä®Ä®Ä®Ä®Ä    ®Ä®Ä®Ä®Ä®Ä®Ä     ®Ä®Ä®Ä®Ä®Ä®Ä®Ä    ®Ä®Ä®Ä
"NOR,me,victim);
message_vision(HIR" ®Ä®Ä®Ä  ®Ä®Ä®Ä®Ä®Ä ®Ä®Ä®Ä®Ä®Ä®Ä    ®Ä®Ä®Ä®Ä®Ä       ®Ä®Ä®Ä®Ä®Ä®Ä    ®Ä®Ä®Ä®Ä
  ®Ä®Ä®Ä  ®Ä®Ä®Ä®Ä   ®Ä®Ä®Ä®Ä®Ä®Ä    ®Ä®Ä®Ä®Ä     ®Ä®Ä®Ä®Ä®Ä®Ä      ®Ä®Ä®Ä®Ä
   ®Ä®Ä®Ä    ®Ä®Ä®Ä   ®Ä®Ä®Ä®Ä®Ä    ®Ä®Ä®Ä     ®Ä®Ä®Ä®Ä®Ä®Ä®Ä®Ä      ®Ä®Ä®Ä
     ®Ä®Ä®Ä  ®Ä®Ä®Ä®Ä®Ä®Ä®Ä®Ä®Ä®Ä    ®Ä®Ä®Ä    ®Ä®Ä®Ä®Ä®Ä®Ä      ®Ä®Ä®Ä®Ä®Ä
   ®Ä®Ä®Ä®Ä    ®Ä®Ä®Ä  ®Ä®Ä®Ä®Ä®Ä®Ä  ®Ä®Ä®Ä®Ä ®Ä®Ä®Ä®Ä®Ä®Ä    ®Ä®Ä®Ä®Ä®Ä®Ä
    ®Ä®Ä®Ä®Ä      ®Ä®Ä®Ä  ®Ä®Ä®Ä®Ä  ®Ä®Ä®Ä®Ä  ®Ä®Ä®Ä®Ä®Ä    ®Ä®Ä®Ä®Ä®Ä®Ä®Ä
   ®Ä®Ä®Ä®Ä®Ä®Ä    ®Ä®Ä®Ä  ®Ä®Ä®Ä®Ö  ®Ä®Ä®Ä ®Ä®Ä®Ä®Ä®Ñ   ®Ä®Ä®Ä®Ä®Ä®Ä®è
       ®Ä®Ä®Ä®Ä®Ä    ®Ä®Ä®Ä®Ä®Ä®Ä®é    ®ê®Ä®Ä®Ä®Ä®Ä  ®Ä®Ä®Ä®Ä®Ä®è
           ®ê®Ä®Ä®Ä®é      ®ê®Ä®Ä®è      ®ê®Ä®è®ç®Ä®Ä®Ä®Ä®Ä®è
                ®â             ®â                 ®â®â®â
"NOR,me,victim);            
    for(j=0; j < 17; j++) {
       do_action = lan_yan[j];
       actionn = "\n";
       actionn += do_action;

       if( weaponn=me->query_temp("weapon") )
       actionn = replace_string(actionn, "$w", weaponn->name());
       message_vision(actionn, me, enemy[i]);
       if( random(me->query("combat_exp")) > random(enemy[i]->query("combat_exp"))/6 ) {
        message_vision("\nµ´ «$N…¡∂„≤ªº∞£¨…Ì…œ∂Ÿ ±∂‡≥ˆ¡À“ªµ¿—™¡‹¡‹µƒΩ£∫€°£\n" , enemy[i]);
        enemy[i]->receive_damage("kee",55,me);
        me->add("force",-30);
        COMBAT_D->report_status(enemy[i]);
                                                  }
   else message_vision("\n$N»À±»Ω£øÏ£¨æ™œ’µÿ…¡π˝¡À’‚“ª’–°£\n" , enemy[i]);
                             }

     if( random(me->query("cps")) < 3 ) {
        me->add("force",-100);
        message_vision("\n$N πÕÍ"HIR"°Æ¡“—Ù Æ∆ﬂ Ω°Ø"NOR"∫Û£¨”…”⁄∂®¡¶≤ª◊„£¨ÃÂƒ⁄’Ê∆¯“ª ±Œﬁ“‘Œ™ºÃ\n",me);
        me->start_busy(1);
                                        }
                                                  }
 
}


void sp_attack6(object me, object victim, object  weapon, int damage)
{
    int i;
  sp_value =6*(str+cor+cps)+spi+int1+kar;

    message_vision(HIY"
À≤º‰£¨$N‘Ÿ ’Ω£»Î« £¨–ƒƒ˝“ª Ω"HIW"°Æ≥Ø—Ù‘Ÿœ÷°Ø"HIY"£¨ªÿ…Ì∑…–˝£¨º∏∫ı «
Õ¨ ±£¨≥§Ω£“—¿Î« ÷±ªÆ$nµƒ— ∫Ì
\n"NOR,me,victim);
   if( weapon->query("id")=="sun_fire_sword" ||  weapon->query("id")=="sun_moon_sword"){
    message_vision(HIY"
¡ÈΩ£¡¨—ÙÀÊ◊≈°Æ≥Ø—Ù‘Ÿœ÷°Ø’‚“ª Ω…¢∑¢≥ˆø™ÃÏ«±≤ÿµƒ¡È∆¯£¨…≤ƒ«º‰!Ω£∑∫Ωπ‚
ÕÍ»´’’¡¡¡À∞µ”∞£¨»Á«ß∞Ÿ∏ˆÃ´—Ù‘⁄$Nµƒ ÷÷–£¨“ª∆Î…‰≥ˆŒﬁ”Î¬◊±»µƒΩπ‚£¨¡Ó
$n∏˘±æŒﬁ∑®±∆ ”
\n"NOR,me,victim);
    victim->receive_wound("kee",sp_value+130,me);
    victim->start_busy(2);
    victim->set_temp("no_power",1);
    victim->apply_condition("no_power",2);
    COMBAT_D->report_status(victim);
                                             }
   else{
    victim->receive_wound("kee",sp_value,me);
    victim->start_busy(1);
    COMBAT_D->report_status(victim);
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
          return CLASS_D("swordsman")+"/sun_fire_sword/"+action;
}   
        
