// ÓÉÓÚ¼ÓÉÏ killup ËùÒÔ¸¶³öµÄÒ²Òª´ó by swy
#include <ansi.h>
#include <combat.h>
inherit SKILL;
inherit SSERVER;
void movedown(object me, object victim, object weapon, int damage);
void sp_att3(object me, object victim, object  weapon, int damage);
void dragon(object me, object victim, object weapon, int damage);
void suck(object me, object victim, object weapon, int damage);
void sp_att1(object me, object victim, object  weapon, int damage);
void sp_att2(object me, object victim, object  weapon, int damage);
int kar=this_player()->query("kar",1);
int cps=this_player()->query("cps",1);
int str=this_player()->query("str",1);
int cor=this_player()->query("cor",1);
int int1=this_player()->query("int",1);
int spi=this_player()->query("spi",1);
int i;
mapping *action = ({
//1
       ([    "action" :
"$N×İÉí¶øÉÏ£¬ÉíĞÎÒ»×ª£¬Ê¹³ö"HIW"¿ñÁú°ËÕ¶"NOR"Ö®"HIR"¡¸»ØÁúÄæÕ¶¡±"NOR"£¬ÊÖÖĞ$wÍù$nºáÅü¹ıÈ¥¡£",
             "dodge"  :       -10,
             "parry"  :       -30,
             "damage" :       200,
             "force"  :       200,
             "damage_type": "¿³ÉË",
        ]),
//2
       ([    "action" :
"$NÔËÆøÓÚ$w£¬Ò»ÕĞ"HIW"¿ñÁú°ËÕ¶"NOR"Ö®"HIR"¡¸½­É½Ò×ÊÖ¡±"NOR"µ¶ÆøĞÛ°Ô£¬Ö±±Æ$n¡£",
             "dodge" :   -10,
             "parry" :   -30,
             "damage" :  200,
             "force"  :  200,
             "damage_type" :   "¿³ÉË",
         ]),
//3
        ([   "action" :
"$NÔËÆğÔª¹¦£¬½«ÕæÁ¦¹á×¢$w£¬Ò»ÕĞ"HIW"¿ñÁú°ËÕ¶"NOR"Ö®"HIG"¡¸ºôÁúĞ¥Ìì¡±"NOR"Ö±Åü$n¡£",
             "dodge"  :         -10,
             "parry"  :         -30,
             "damage" :         200,
             "force"  :         200,
             "damage_type":  "¿³ÉË",
        ]),
//4
        ([   "action" :
"$NÊÖÖĞ$wÁ¬»®£¬Ò»ÕĞ"HIW"¿ñÁú°ËÕ¶"NOR"Ö®"HIG"¡¸Ò¹ÁúÒ»¾æ¡±"NOR"ºöµØÍ¦³öÖ±¿³$n¡£",
             "dodge"  :         -10,
             "parry"  :         -30,
             "damage" :         250,
             "force"  :         250,
             "damage_type":  "¿³ÉË",
        ]),
//5
        ([   "action" :
"$NÒ»ÕĞ"HIW"¿ñÁú°ËÕ¶"NOR"Ö®"HIY"¡¸Íò½Ù¾¡Éá¡±"NOR"ÊÖÖĞ$wÎè³ÉÒ»Æ¬µ¶Íø£¬ÁıÕÖ$n¡£",
             "dodge"  :        -10,
             "parry"  :        -30,
             "damage" :        250,
             "force"  :        250,
             "damage_type":  "¿³ÉË",
        ]),
//6
        ([   "action" :
"$N»Ó¶¯ÊÖÖĞµ¶ÈĞ£¬Ê¹³ö"HIW"¿ñÁú°ËÕ¶"NOR"Ö®"HIB"¡¸Ò»×Öµ¶·¨¡±"NOR"Ö»¼û$wÏñÒ»µÀÉÁµç£¬Ö±Åü¶øÏÂ¡£",
             "dodge"  :       -10,
             "parry"  :       -30,
             "damage" :       250,
             "force"  :       250,
             "damage_type":  "¿³ÉË",
        ]),
//7
        ([   "action" :
"$NÊ¹³ö"HIW"¿ñÁú°ËÕ¶"NOR"Ö®"HIM"¡¸Àëµ¶ĞıÕ¶¡±"NOR"£¬Ö»¼û$wÏñ°×Ñ©°ã·×·×ÂäÏÂ¡£",
             "dodge"  :         -10,
             "parry"  :         -30,
             "damage" :         300,
             "force"  :         300,
             "damage_type":  "¿³ÉË",
        ]),
//8

        ([      "action":
"$N³Ö$wÒ»Ñï£¬Ê¹³ö"HIW"¿ñÁú°ËÕ¶"NOR"Ö®"HIC"¡¸¿ºÁúÓĞ»Ú¡±"NOR"£¬µ¶ÊÆÍò¾û£¬ÅüÏò$n¡£",
                "dodge":  -10,
                "parry":  -30,
                "damage": 300,
                "force":  300,
                "damage_type":  "ÅüÉË",
        ]),
//9
        ([      "action":
"$NÊ¹³ö¿ñÁú±ØÉ±¼¼£¬"HIM"¡¾ó´ÁúËø¹Ø¡¿"HIY"¡®¼ÉÌì¡«¡«¡«ºŞµØ¡«¡«¡«ÓãÁúÔÙÏÖ¡¯\n"NOR
"Å×Æğ$w£¬¿ÕÖĞ×ªÌåÈıÖÜ°ë£¬ÆøÊÆ°õíç¡£",
                "dodge":        -10,
                "parry":        -30,
                "damage":       300,
                "force":        300,
                "post_action":  (: sp_att3 :),
                "damage_type":  "¿³ÉË",
        ]),
//10
       ([      "action" :
"$NÊ¹³ö¿ñÁúÁ¬Îè»÷£¬"HIM"¡¾Ä§ĞÔÁùÕ¶¡¿"HIY"¡®¾ªÌì¡«¡«¡«ÃğµØ¡«¡«¡«Ñª»¨·×·É¡¯\n"NOR
"ÊÖÖĞ$wÔÚÖË¿ÕÏÂÎè¶¯£¬Ö¯³ÉÒ»µÀµ¶Íø¡£",
               "dodge":         -10,
               "parry":         -30,
               "damage":        350,
               "force":         350,
               "post_action":  (: movedown :),
               "damage_type":   "¿³ÉË",
        ]),
//11
       ([      "action" :
"$NÍ»È»ÏİÈë·è¿ñ£¬¿ÚÖĞ´óº°£¬"HIM"¡¾²ÔÌìÒÑËÀ¡«Ä§µ¶µ±Á¢¡«¿´Éã»êÍÀÏÉ´ó·¨¡¿"NOR"Ö»¼û$N\n"
"ÒÔ$wÖ¸Ïò$nµÄÉË¿Ú£¬Áè¿ÕÎüÈ¡$nµÄÏÊÑª£¡",
                "dodge" :       -10,
                "parry" :       -30,
                "damage":       350,
                "force" :       350,
                "post_action":  (: suck :),
                "damage_type":  "¿³ÉË",
        ]),
//12
       ([ "action" :
"$N¾Û¼¯¾ÅÌìÖ®Æø£¬Ê¹³ö[35m¡¾ÈıÕ¶¹éÔª¡«Ğ°ÁúÕ¶Ôª¡¿[0m\n"
"[1;32m£®£®£®[1;37m¡®"HIY"Ä§"HIC"Áú"HIY"ÊÈ"HIC"Ñª"HIW"¡«¡«"HIR"·Ù"HIW"Ìì"HIB"Ğ°"HIC"ÔÂ"HIW"¡¯[1;32m£®£®£®[0m\n"
"$n¾ªãµÖ®ÓÚ£¬Ö»¼û$N°Ñ$w²åÓÚµØÉÏ£¬†ˆÆğÃØÖä£¬Ë²Ê±»ğÑæš\ÕÅ\n"
"ÑÍÂşÕû¸öÌì¼Ê¡£",
"dodge": -10,
"parry": -30,
"force": 400,
"post_action": (: dragon :),
"damage": 400,
"damage_type": "ÉÕÉË",
]),
//13
([ "action" :
"$NÔËÓÃ¾ÅµØÖ®Æø£¬Ê¹³ö[35m¡¾ÈıÕ¶¹éÔª¡«ÓãÁúÊÈÔª¡¿[0m\n"
"[1;32m£®£®£®[1;37m¡®"HIY"Óã"HIC"Áú"HIY"¶¾"HIC"ğ²"HIW"¡«¡«"HIY"»Í"HIM"á°"HIG"´Ô"HIR"Ãğ"HIW"¡¯[1;32m£®£®£®[0m\n"
"ÃØÖäÓïÒôÓÌÔÚ¶ú£¬ö®ÄÇ¼ä£¬´Ó$w´Ü³ö¾Å²ÊÑÌÎí£¬Ë²Ê±±ßÅÔÖÜÎ§µÄÉúÎïËÀÖ®´ù¾¡¡£",
"dodge": -10,
"parry": -30,
"force": 400,
"post_action": (: sp_att1 :),
"damage": 400,
"damage_type": "¶¾ÉË",
]),
//14
([ "action" :
"$NÊ©Õ¹¾ÅÈËÖ®Æø£¬Ê¹³ö[35m¡¾ÈıÕ¶¹éÔª¡«Ñ©Ó°»¯Ôª¡¿[0m\n"
"[1;32m£®£®£®[1;37m¡®"HIY"¿ñ"HIC"Áú"HIY"Å­"HIC"Õğ"HIW"¡«¡«"HIC"Ñ©"HIM"Ó°"HIB"º®"HIC"Ëª"HIW"¡¯[1;32m£®£®£®[0m\n"
"$NÔËÆğÕæÔª£¬ÊÖ³Ö$wÍùÌìÒ»»Ó£¬¶ÙÊ±£¬É½Ò¡µØ¶¯£¬·çÔÆ±äÉ«£¬ÒÔÈÅÂÒÁË\n"
"ËÄ¼¾µÄÔË×ª£¬²ÔÌìÍ»È»µØÆ®ÏÂÂşÌìÑ©²Ê¡£",
"dodge": -10,
"parry": -30,
"force": 400,
"post_action": (: sp_att2 :),
"damage": 400,
"damage_type": "¶³ÉË",
]),
});
mapping query_action(object me, object weapon)
{
int skill, limit, f;
object victim;
skill=(int)(me->query_skill("dragon-blade", 1));
limit=(int)(skill/10);
f=random(6);
victim=offensive_target(me);
if(random(100)>=70&&me->query("combat_exp")>200000 && victim) {
message_vision(HIW+@LONG

                    ¨¨~¨                        ¨¨~¨
                      ¨¨~¨========================¨¨~¨
========================¨¨~¨========================¨¨~¨
==========================¨~¨~==========================¨~¨~
========================¨¨~¨========================¨¨~¨
                      ¨¨~¨========================¨¨~¨
                    ¨¨~¨                        ¨¨~¨

LONG +NOR,me);
message_vision(HIY"$N´óºÈÒ»Éù·¢³öË«µ¶Æø£¬µ¶ÆøĞÛ°Ô¹á´©$n¶ø¹ı¡£\n"NOR,me,victim);
victim->receive_wound("kee",300,me);
COMBAT_D->report_status(victim);
}
if((me->query("family/family_name")=="Ä§µ¶ÃÅ"||me->query("family/family_name")=="Ä§µ¶Äª²â")&&
me->query("m_blade")&&me->query("env/get_mblade")&&me->query("combat_exp")>3000000)
{
if(limit=12)
{
if(me->query_temp("mblade")==1) {
return action[13];
}
if(me->query_temp("mblade2")==1) {
return action[12];
}
if(me->query_temp("mblade3")==1) {
return action[11];
}
if((int)me->query("force")>2000)
{
if(f>3) return action[random(3)+11];
return action[random(3)+8];
}
if((int)me->query("force")>1500)
{
if(f>3) return action[random(2)+11];
return action[random(3)+8];
}
if((int)me->query("force")>1000)
{
if(f>3) return action[random(1)+11];
return action[random(3)+8];
}
}
}
if(limit<4)
{
return action[random(3)];
}
if(limit<5)
{
return action[random(4)];
}
if(limit<6)
{
return action[random(5)];
}
if(limit<7)
{
return action[random(6)];
}
if(limit<8)
{
return action[random(7)];
}
if(limit<9)
{
return action[random(9)];
}
if(limit<10)
{
return action[random(10)];
}
if(limit<11)
{
return action[random(10)];
}
if(limit<12)
{
return action[random(11)];
}
else
{
return action[random(11)];
}
}
void suck(object me, object victim, object weapon, int damage)
{
if(70>=random(100)&&me->query("force_factor",1)>=10&&me->query_temp("conti")==0
   && me->query("bellicosity")>11)
  {
     victim->receive_wound("kee",400,me);
     me->receive_curing("kee",400);
     me->receive_heal("kee",400);
     me->add("bellicosity",-10);
     victim->apply_condition("blade",3);
     COMBAT_D->report_status(victim);
     me->add("force",-70);
  } else
message_vision(sprintf("½á¹û$NµÄÑıÊõ±»$nÆÆ½â¡£\n"),me,victim);
}
void movedown(object me, object victim, object weapon, int damage)
{
int i,bell;
bell=me->query("bellicosity",1)/300;
if(bell < 1) bell=1;
if(bell > 6) bell=6;
if(70>=random(100)&&me->query("force_factor",1)>=5&&me->query_temp("conti")==0
   && me->query("env/Ä§ĞÔÁùÕ¶")&& me->query("bellicosity")>11)
{
  for(i=1;i<=bell;i++)
  {
    switch(i)
    {
     case 1:
message_vision(sprintf("$NÊ¹³öÄ§ĞÔÁùÕ¶Ö®"HIR"¡®¿ì¡¯"NOR"£¬ÊÖÖĞµ¶ÈĞÕ¶Ïò$nµÄĞØÌÅ¡£\n"),me,victim);
     break;
     case 2: 
message_vision(sprintf("$NÊ¹³öÄ§ĞÔÁùÕ¶Ö®"HIG"¡®ºİ¡¯"NOR"£¬ÊÖÖĞµ¶ÈĞÕ¶Ïò$nµÄÏÂÒõ¡£\n"),me,victim);
     break;
     case 3:
message_vision(sprintf("$NÊ¹³öÄ§ĞÔÁùÕ¶Ö®"HIY"¡®×¼¡¯"NOR"£¬ÊÖÖĞµ¶ÈĞÕ¶Ïò$nµÄÑÛ¾¦¡£\n"),me,victim);
     break;
     case 4:
message_vision(sprintf("$NÊ¹³öÄ§ĞÔÁùÕ¶Ö®"HIM"¡®¿Õ¡¯"NOR"£¬ÊÖÖĞµ¶ÈĞÕ¶Ïò$nµÄÊÖÍó¡£\n"),me,victim);
     break;
     case 5:
message_vision(sprintf("$NÊ¹³öÄ§ĞÔÁùÕ¶Ö®"HIB"¡®ÆÆ¡¯"NOR"£¬ÊÖÖĞµ¶ÈĞÕ¶Ïò$nµÄ×ãõ×¡£\n"),me,victim);
     break;
     case 6: 
message_vision(sprintf("$NÊ¹³öÄ§ĞÔÁùÕ¶Ö®"HIC"¡®Ãğ¡¯"NOR"£¬ÊÖÖĞµ¶ÈĞÕ¶Ïò$nµÄ¾±×Ó¡£\n"),me,victim);
     break;
     }
message_vision(sprintf(HIW"$NÈ·ÊµÃüÖĞ$nÒªº¦£¬$n¶ÙÊ±ÑªÁ÷ÂúµØ¡£\n"NOR),me,victim);
          victim->receive_wound("kee",140,me);
          COMBAT_D->report_status(victim);
   }
if(!me->query_temp("six-hurt")) {
   me->start_busy(1);
}
   me->add("force",-70);
   me->add("bellicosity",-10);
   victim->apply_condition("blade",3);
} else
message_vision(sprintf("½á¹û$NµÄÄ§ĞÔ²»¹»Ê¹²»³öÀ´¡£\n"),me,victim);
}

int valid_learn(object me)
{
        object ob;
        if((int)me->query("max_force")<100)
        return notify_fail("ÄãµÄÄÚÁ¦²»¹»£¬²»ÄÜÁ·¿ñÁúµ¶·¨¡£\n");
        if((string)me->query_skill_mapped("force")!= "powerforce")
        return notify_fail("¿ñÁúµ¶·¨±ØĞèÅäºÏĞşÑôÉñ¹¦²ÅÄÜÓÃ¡£\n");
 if(!(ob=me->query_temp("weapon"))||(string)ob->query("skill_type")!="blade")
        return notify_fail("Äã±ØĞëÓĞµ¶²ÅÄÜÁ·µ¶·¨¡£\n");
        return 1;
}
int valid_enable(string usage)
{
        return usage=="blade" || usage=="parry";
}
string perform_action_file(string action)
{
        return CLASS_D("blademan") + "/dragon-blade/" + action;
}
void dragon(object me, object victim, object weapon, int damage)
{
if(me->query_temp("mblade3")==1) {
me->set_temp("mblade3",0); }
if(me->query("bellicosity")<21) return;
if(me->query("env/Ğ°µ¶Á¬»÷")) {
if(weapon->query("id")=="shi-blade" || (weapon->query("id")=="evil-mblade" &&
weapon->query("mblade-mark")))
{
string acti;
mapping do_action;
object enemy,weaponn;
int j,force,bell,dak,das,dag;
force=me->query("force",1);
enemy=offensive_target(me);
bell=me->query("bellicosity",1);
if(bell>=9000&&force>700&&me->query_temp("conti")==0)
{
message_vision(sprintf(HIM"
$NÔËÆğÈıÕ¶¹éÔª¹¦£¬Ö»¼û$NÕû¸öÈË³äÂúìåÆø£¬¾Ùµ¶Ïò$nÁ¬¿³¶øÀ´£¡\n"NOR),me,enemy);
me->set_temp("conti",1);
for(j=0; j < 14; j++) {
do_action=action[j];
acti = "\n";
acti += do_action["action"];
if(weaponn=me->query_temp("weapon") )
acti=replace_string(acti, "$w", weaponn->name());
message_vision(acti, me, enemy);
if(random(me->query("combat_exp"))>random(enemy->query("combat_exp"))/10) {
message_vision(HIR"\n$NÉÁ¶ã²»¹ı£¬ÉíÉÏ¶ÙÊ±¶àÁËÒ»µÀÉË¼°¼û¹ÇµÄµ¶ºÛ¡£\n"NOR,enemy);
dak=enemy->query("max_kee")/30;
if(dak > 160) dak=160;
das=enemy->query("max_sen")/30;
if(das > 100) das=100;
dag=enemy->query("max_gin")/30;
if(dag > 100) dag=100;
enemy->receive_wound("gin",dag,me);
enemy->receive_wound("kee",dak,me);
enemy->receive_wound("sen",das,me);
me->add("force",-20);
COMBAT_D->report_status(enemy);
}
else message_vision("\n$NÔË¹¦Ò»Ô¾£¬¾ªÏÕµØÉÁ¹ıÁËÕâÒ»µ¶ÕĞ¡£\n" , enemy);
}
if(random(me->query("cps")) < 6 )
{
message_vision("\n$NÌåÄÚÉ±ÆøÓ¿ÉÏëşÖĞÎŞÒÔ¾ÛÁ¦£¬Ö»ºÃÊÍ·ÅĞ©Ğí¡£\n",me);
me->start_busy(1);
me->add("bellicosity",-20);
}
me->delete_temp("conti");
}
} else {
int sp_1=4*(cps+kar)+str+cor+spi+int1;
int bell=me->query("bellicosity")/500;
if(bell < 1) bell=1;
if(bell > 8) bell=8;
for(i=1;i<=bell;i++)
{
message_vision(HIW"Äã¼ÀÆğµ¶ÈĞ£¬Æø³Áµ¤Ìï£¬Á÷³©¿ìÒâµÄÊ©Õ¹¿ñÁúµ¶·¨£¡\n"NOR,me,victim);
switch(i)
{
case 1:
message_vision(sprintf("$NÊ¹³öµÚÒ»Ê½¡®"HIC"»ØÁúÄæÕ¶"NOR"¡¯Õ¶Ïò$n¡£\n"),me,victim);
break;
case 2:
message_vision(sprintf("$NÊ¹³öµÚ¶şÊ½¡®"HIC"½­É½Ò×ÊÖ"NOR"¡¯Õ¶Ïò$n¡£\n"),me,victim);
break;
case 3:
message_vision(sprintf("$NÊ¹³öµÚÈıÊ½¡®"HIC"ºôÁúĞ¥Ìì"NOR"¡¯Õ¶Ïò$n¡£\n"),me,victim);
break;
case 4:
message_vision(sprintf("$NÊ¹³öµÚËÄÊ½¡®"HIC"Ò¹ÁúÒ»¾æ"NOR"¡¯Õ¶Ïò$n¡£\n"),me,victim);
break;
case 5:
message_vision(sprintf("$NÊ¹³öµÚÎåÊ½¡®"HIC"Íò½Ù¾¡Éá"NOR"¡¯Õ¶Ïò$n¡£\n"),me,victim);
break;
case 6:
message_vision(sprintf("$NÊ¹³öµÚÁùÊ½¡®"HIC"Ò»×Öµ¶·¨"NOR"¡¯Õ¶Ïò$n¡£\n"),me,victim);
break;
case 7:
message_vision(sprintf("$NÊ¹³öµÚÆßÊ½¡®"HIC"Àëµ¶ĞıÕ¶"NOR"¡¯Õ¶Ïò$n¡£\n"),me,victim);
break;
case 8:
message_vision(sprintf("$NÊ¹³öµÚ°ËÊ½¡®"HIC"¿ºÁúÓĞ»Ú"NOR"¡¯Õ¶Ïò$n¡£\n"),me,victim);
break;
}
victim->receive_wound("kee",sp_1/2,me);
message_vision(sprintf(HIR"$nÂ¶³öÆÆÕÀ£¬±»µ¶ÈĞÖ±Õ¶Òªº¦£¬ÏÊÑªÖ±Á÷¡£\n"NOR),me,victim);
COMBAT_D->report_status(victim);
}
me->add("force",-50);
me->add("bellicosity",-20);
me->start_busy(1);
}
}
victim->apply_condition("blade",5);
}

void sp_att1(object me, object victim, object weapon, int damage)
{
int sp_2 = 4*(str+cor)+cps+kar+spi+int1;
if(me->query_temp("mblade2")==1) {
me->set_temp("mblade2",0);
me->set_temp("mblade3",1); }
if(me->query("bellicosity")<21) return;
if(weapon->query("id")=="ublade" || (weapon->query("id")=="evil-mblade" &&
weapon->query("mblade-mark")))
{
message_vision(HIY"ÄãÎüÊÕÂúÌì¶¾ÎíÔËÆøÓÚµ¶£¬ö®ÄÇ¼äÊÖÖĞµ¶ÈĞÉ¢·¢³ö¾ªÈËº§¶¾£¬ÁıÕÖËÄ·½¡£\n"NOR,me,victim);
message_vision(sprintf(HIB"$nÁ³É«·¢ºÚ£¬ËÆºõÖĞÁË¾ç¶¾¡£\n"NOR),me,victim);
         victim->receive_wound("kee",sp_2*2,me);
         victim->apply_condition("blade",7);
         victim->apply_condition("u-stial",7);
         victim->start_busy(1);
         COMBAT_D->report_status(victim);
         me->add("force",-120);
}
       else
{
if(me->query_temp("conti")==0) {
message_vision(HIY"ÄãÔËÆøÓÚµ¶£¬°µÊ¹ÕæÔª£¬Ö»¼ûµ¶ÌÚ¿Õ·É³ö£¬Ö±±¼$nµÄĞØÌÅ¡£\n"NOR,me,victim);
          victim->receive_wound("kee",sp_2,me);
          victim->apply_condition("blade",7);
          COMBAT_D->report_status(victim);
          me->add("force",-60);
 }
 }
 me->add("bellicosity",-20);
 }
void sp_att2(object me, object victim, object weapon, int damage)
{
int sp_3 = 4*(kar+int1)+2*str+cor+cps+spi;
if(me->query_temp("mblade")==1) {
me->set_temp("mblade",0);
me->set_temp("mblade2",1); }
if(me->query("bellicosity")<21) return;
if(weapon->query("id")=="iceblade" || (weapon->query("id")=="evil-mblade" &&
weapon->query("mblade-mark")))
{
message_vision(HIC"ÊÖÖĞµ¶ÈĞ£¬ËÆÓĞËÆÎŞ£¬±àÖ¯ÂşÌìÑ©²Ê£¬Ö»¼û$nÀ§ÔÚÆäÖĞ¡£\n"NOR,me,victim);
    victim->start_busy(1);
    victim->receive_wound("kee",sp_3*2,me);
    victim->apply_condition("blade",9);
    COMBAT_D->report_status(victim);
    me->add("force",-150);
}
    else
{
if(me->query_temp("conti")==0) {
message_vision(HIC"ÂşÌìÑ©²Ê£¬Ö»¼û$n¿´µÄÊ§»ê£¬ÒÑ±»µ¶ÈĞËùÉË¡£\n"NOR,me,victim);
    victim->receive_wound("kee",sp_3,me);
    victim->apply_condition("blade",9);
    COMBAT_D->report_status(victim);
    me->add("force",-75);
} }
me->add("bellicosity",-20);
}
void sp_att3(object me, object victim, object  weapon, int damage)
{
int sk_lv;
sk_lv = me->query_skill("dragon-blade",1);
if(sk_lv>=105&&me->query_temp("conti")==0&&me->query("bellicosity")>11
&&70>=random(100)&&me->query("force",1)>70&&me->query("have_book",1))
{
message_vision(sprintf(HIR"
Í»È»$NÑÛÂ¶ºì¹âÏòÌìÅ­ºğ£¬¿ñ±©ÔËÆğÔª¹¦£¬Ê¹³öÄ§µ¶Ê§´«Ö®°ÂÒå"HIW"¡®Â¬É½²»¶¯Ò»½£ºÛ¡¯\n"NOR),me,victim);
message_vision(sprintf(HIB"$N»Ó×Åµ¶ÈĞ£¬Ë³×ÅËÄ¼¾µÄÔË×ª£¬Ïò$n¿³³ö¡®´ºÓê¡¯¡®ÏÄÒ¹¡¯"+
"¡®Çï·ç¡¯¡®¶¬Ñ©¡¯\n"HIY"$n±»Õâ¹É¿ñ°Ôµ¶ÆøÕğÏÅ×¡£¬Ò»Ë²¼ä$nÉíÉÏÒÑÁôÏÂÉî¼°¼û¹ÇµÄËÄµÀÉËºÛ\n\n"NOR),me,victim);
         victim->receive_wound("kee",400,me);
         victim->start_busy(1);
         victim->apply_condition("blade",3);
         COMBAT_D->report_status(victim);
         me->add("force",-50);
         me->add("bellicosity",-10);
}
}
