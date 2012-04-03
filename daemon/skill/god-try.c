// enable-archery.c
// by airke
// By Swy ×îºóÐÞÕý QC 98/6/23
#include <combat.h>
#include <ansi.h>
inherit SKILL;

void god_att(object me, object victim, object  weapon, int damage);
void shooting_att(object me,object victim, object weapon,int damage);
void sp_attack1(object me, object victim, object  weapon, int damage);
void sp_attack2(object me, object victim, object  weapon, int damage);
void sp_attack3(object me, object victim, object  weapon, int damage);
int cps=this_player()->query("cps",1);
int sp_value;

string *lan_yan = ({
"$NÊ¹³öÁ÷ÐÇ¼ý·¨µÚÒ»Ê½¡®Ò»Ð¹Ç§Àï¡¯£¬Éä³öµÄ$w»¯³ÉÒ»µÀÐÇÃ¢£¬Ð®×ÅÕóÕóÉ³ÀË£¬Ò»Ê±¼äÑÌ³¾ËÄÆð\n",

"$NÊ¹³öÁ÷ÐÇ¼ý·¨µÚ¶þÊ½¡®Ë«Áú³öº£¡¯£¬Éä³öµÄ$w»¯³ÉÁ½µÀÐÇÃ¢£¬Ò»×óÒ»ÓÒ£¬ÈçË«ÁúÇÀÖé°ã\n",

"$NÊ¹³öÁ÷ÐÇ¼ý·¨µÚÈýÊ½¡®Èý·Ö¶¦×ã¡¯£¬Éä³öµÄ$w»¯³ÉÈýµÀÐÇÃ¢£¬ÈçÈý¹ú¶¦Á¢°ã£¬³¯Í· ¸¹ ¼°ºíÁü¼²Éä¶øÈ¥\n",

"$NÊ¹³öÁ÷ÐÇ¼ý·¨µÚËÄÊ½¡®ËÄÃæ³þ¸è¡¯£¬Éä³öµÄ$w»¯³ÉËÄµÀÐÇÃ¢£¬ËÆÓÐÁéÐÔ£¬³¯ÊÖ×ãËÄ´¦¹Ø½Ú¼²Éä¹ýÈ¥\n",

"$NÊ¹³öÁ÷ÐÇ¼ý·¨µÚÎåÊ½¡®ÎåÂí·ÖÊ¬¡¯£¬Éä³öµÄ$w»¯³ÉÎåµÀÐÇÃ¢£¬ËÆÓÐÁéÐÔ£¬³¯Í·¼°ËÄÖ«¼²Éä¶øÈ¥\n",

"$NÊ¹³öÁ÷ÐÇ¼ý·¨µÚÁùÊ½¡®ÁùµÀÂÖ»Ø¡¯£¬Éä³öµÄ$w»¯³ÉÁùµÀÐÇÃ¢£¬ÁùµÀÐÇÃ¢²»¶ÏµÄÐý×ª×Å³¯Ç°¼²ËÙ·ÉÈ¥\n",

"$NÊ¹³öÁ÷ÐÇ¼ý·¨µÚÆßÊ½¡®ÆßÐÇÁ¬Ïß¡¯£¬Éä³öµÄ$w»¯³ÉÆßµÀÐÇÃ¢£¬ÆßµÀÐÇÃ¢ÅÅ³ÉÒ»Ïß¼²·É¶øÈ¥\n",

"$NÊ¹³öÁ÷ÐÇ¼ý·¨µÚ°ËÊ½¡®°ËÏÉ¹ýº£¡¯£¬Éä³öµÄ$w»¯³É°ËµÀÐÇÃ¢£¬°ËµÀÐÇÃ¢È¥ÊÆºö×óºöÓÒ£¬çÎç¿²»¶¨\n",

"$NÊ¹³öÁ÷ÐÇ¼ý·¨µÚ¾ÅÊ½¡®¾Å¾Å¹éÔª¡¯£¬Éä³öµÄ$w»¯³É¾ÅµÀÐÇÃ¢£¬¾ÅµÀÐÇÃ¢ÓÖºÏ¶øÎªÒ»£¬È¥ÊÆÊ®·ÖÐ×ÃÍ\n",
});

// ÓÐ¼ýÊ±µÄÐðÊö $wÊÇ¹­ $c ÊÇ¼ý
//Ó¦Íæ¼ÒÒªÇó.Ôö¼ÓÁ¬»÷ by poloer
mapping *arrow_action = ({
//1
        ([      "action":
"$N¿´¼û$nÕÐÊÆÒÑ¾¡£¬Ñ¸ËÙ½«$c´îÓÚ$wÖ®ÉÏ£¬Ê¹³öÁ÷ÐÇ¼ý·¨µÚÒ»Ê½¡¸Ò»Ð¹Ç§Àï¡±£¬¼ýÊÆÈçºéË®¿ñÐ¹°ã³¯$n$l·ÉÉä¶øÈ¥[m",
                "dodge":        -100,
                "damage":       130,
                "parry":        -100,
                "force":        130,
                "damage_type": "ÉäÉË",
        ]),
//2
([        "action":
"$N½«ÊÖÉÏ$cÑ¸ËÙ´îÓÚ$w·ÖÎªÁ½´ÎÉä³ö£¬Ê¹³öÁ÷ÐÇ¼ý·¨µÚ¶þÊ½"HIG"¡¸Ë«Áú³öº£¡±"NOR"£¬·ÖÉä³öÖ®$cÈçË«Áú¿ñÊÉ°ã³¯$n¶øÈ¥",
                "dodge":        -100,
                "damage":       130,
                "force" :       130,
                "damage_type": "ÉäÉË",
                "parry":        -100,
        ]),
//3
        ([      "action":
"$N°ÔÆøÍ»ÕÇ£¬½«ÊÖÖÐ$cÑ¸ËÙ´îÓÚ$wÈý¼ýÆë·¢£¬Ê¹³öÁ÷ÐÇ¼ý·¨µÚÈýÊ½"HIB"¡¸Èý·Ö¶¦×ã¡±"NOR"£¬Éä³öµÄ$cËÆº¬Èý¹ú¶¦Á¢Ö®°ÔÆø·ÖÈý´¦Ïò$n¼±Éä¶øÈ¥",
                "dodge":        -100,
                "damage":       130,
                "force":         130,
                "parry":        -100,
                "damage_type": "ÉäÉË",
        ]),
//4
        ([      "action":
"$N±»$n¹¥ÊÆËù¾ªÏÅ£¬½«ÊÖÖÐ$cÑ¸ËÙ´îÓÚ$wÖ®ÉÏ·ÖÉäËÄ¼ý£¬Ê¹³öÁ÷ÐÇ¼ý·¨µÚËÄÊ½"HIY"¡¸ËÄÃæ³þ¸è¡±"NOR"£¬Éä³öµÄ$cËÆÓÐÁéÐÔ°ãÓÉ$nÇ°ºó×óÓÒËÄÃæ·ÉÉä¶øÈ¥",
                "dodge":        -100,
                "damage":       130,
                "force":        130,
                "parry":        -100,
                "damage_type": "ÉäÉË",
        ]),
//5
        ([      "action":
"$NÐÄÖÐÉ±ÆøÍ»ÕÇ£¬½«ÊÖÖÐ$cÑ¸ËÙ´îÓÚ$wÉÏÎå¼ýÆëÉä£¬É±ÆøÈÚºÏÓÚ$cÊ¹³öÁ÷ÐÇ¼ý·¨µÚÎåÊ½"HIW"¡¸ÎåÂí·ÖÊ¬¡±"NOR"£¬$c³¯$nÍ·¼°Ë«ÊÖË«½ÅÆëÉä¶øÈ¥",
                "dodge":        -100,
                "damage":       110,
                "force":        130,
                "parry":        -100,
                "damage_type": "ÉäÉË",
        ]),
//6
        ([      "action":
"$N½«ÊÖÖÐ$cÑ¸ËÙ´îÓÚ$w£¬Éä³öÖ®¼ÊÈÚÈëÐý×ªÆø¾¢Ê¹³öÁ÷ÐÇ¼ý·¨µÚÁùÊ½"HIG"¡¸ÁùµÀÂÖ»Ø¡±"NOR"£¬$c¼±ËÙÐý×ª³¯×Å$n¼±Éä¶øÈ¥",
                "dodge":        -100,
                "damage":       115,
                "foece":        130,
                "parry":        -100,
                "damage_type": "ÉäÉË",
        ]),
//7
        ([      "action":
"$N½«ÊÖÖÐ$cÑ¸ËÙ´îÓÚ$wÁ¬ÐøÉä³öÆß¼ý£¬Ê¹³öÁ÷ÐÇ¼ý·¨µÚÆßÊ½"HIM"¡¸ÆßÐÇÁ¬Ïß¡±"NOR"£¬$cÆß¼ýÒ»¼ý½Ó×ÅÒ»¼ýÐÎ³ÉÒ»Ïß³¯$n¼±Éä¶øÈ¥",
                "dodge":        -100,
                "damage":       130,
                "force":        130,
                "parry":        -100,
                "damage_type": "ÉäÉË",
        ]),
//8
        ([      "action":
"$N½«ÊÖÖÐ$cÑ¸ËÙ´îÓÚ$w»º»ºÉä³ö£¬Ê¹³öÁ÷ÐÇ¼ý·¨µÚ°ËÊ½"HIC"¡¸°ËÏÉ¹ýº£¡±"NOR"£¬$cÈçÍ¬ÏÉÈË¹ýº£°ãçÎç¿°ãÁî$n²»ÖªËù´ë",
                "dodge":        -100,
                "damage":       130,
                "force":        130,
                "parry":        -100,
                "damage_type": "ÉäÉË",
                "post_action":  (: god_att :),
        ]),
//9
        ([      "action":
"$N½«ÊÖÖÐ$cÑ¸ËÙ´îÓÚ$w»º»ºÉä³ö¾Å¼ý£¬Ê¹³öÁ÷ÐÇ¼ý·¨µÚ¾ÅÊ½"HIR"¡¸¾Å¾Å¹éÔª¡±"NOR"£¬Éä³ö¾Å¼ýºÏÒ»£¬Áî$nÎÞ·¨ÕÐ¼Ü",
                "dodge":        -100,
                "damage":       130,
                "parry":        -100,
                "force":        130,
                "damage_type": "ÉäÉË",
                "post_action":  (: shooting_att :),
        ]),
//10
        ([      "action":
"        $NÁìÎòµ½Á÷ÐÇ¼ý·¨Ö®¸÷Ê½°ÂÃî£¬½«¾ÅÊ½¼ý·¨Á¬ÐøÊ¹³ö£¬»¯ÎªÒ»Ê½\n"
"            ¡®¡«¡«¡«¡«·ï¡«¡«¡«Îè¡«¡«¡«¾Å¡«¡«¡«Ìì¡«¡«¡«¡«¡¯      \n"
"        ¾ÅÊ½¼ý·¨¿´ËÆÍ¬Ê±Éä³ö°ã£¬$c»¯ÎªÎÞÊýÁ÷ÐÇ³¯×Å$n$l¸÷´¦ÉäÈ¥",
                "dodge":        -100,
                "damage":       130,
                "parry":        -100,
                "force":        130,
                "damage_type": "ÉäÉË",
                "post_action":  (: sp_attack1 :),
        ]),
//11
        ([      "action":
"        $N½«±ùÐÄ¾÷Ö®ÄÚ¾¢°µÔËÓÚ$cÉÏ£¬½«ÊÖÖÐ$c´îÓÚ$wÉä³ö£¬»¯ÎªÒ»Ê½\n "
"            ¡®¡«¡«¡«¡«Ê®¡«¡«¡«Íò¡«¡«¡«»ð¡«¡«¡«¼±¡«¡«¡«¡«¡¯      \n"
"        ¼ýÊÆ¿´ËÆÈáÈõÎÞÁ¦£¬$cÈ¥ÊÆçÎç¿²»¶¨µÄ³¯×Å$nÉíÌå¼²ËÙ·ÉÈ¥¡£    ",
                "dodge":        -100,
                "damage":       130,
                "parry":        -100,
                "force":        130,
                "damage_type": "ÉäÉË",
                "post_action":  (: sp_attack2 :),
        ]),
});

// ÏÂÃæÊÇÃ»¼ýÊ±µÄ¹¥»÷ÐðÊö

mapping *bow_action = ({
        ([      "action":               "$N¾ÙÆð$wºÝºÝµØÍù$n$lÔÒÈ¥",
                "dodge":        -10,
                "damage":       10,
                "parry":        -10,
                "damage_type":  "ðöÉË",

        ]),
        ([      "action":               "$N³ÔÁ¦µØ»ÓÎè$wÊÔ×Å´òÉË$n",
                "dodge":        -5,
                "damage":       15,
                "parry":        -10,
                "damage_type":    "ðöÉË",

        ]),
});

int valid_learn(object me)
{
        object ob;

if(me->query_skill("archery",1)<15)
                return notify_fail("ÒªÁ·Á÷ÐÇ¼ý·¨ÒªÏÈÓÐÏàµ±µÄ¹­¼ý»ù´¡¡£\n");

        if( !(ob = me->query_temp("weapon"))
        ||      (string)ob->query("skill_type")!="archery")
                return notify_fail("ÄãÊÖÉÏÒªÓÐ¹­¼ý²ÅÄÜÁ·Á÷ÐÇ¼ý·¨¡£\n");

        return 1;
}

int valid_enable(string usage)
{
        return usage=="archery" || usage=="parry";
}


mapping query_action(object me, object weapon)
{
  int skill_level, limit;
  object wpn = me->query_temp("weapon");
  int i;
//ÒÔÏÂ¼¸ÐÐ¶¼ÊÇ±ØÐëµÄ..
//-----------------------------------------------------
//
// i = Ä¿Ç°¹­ÉÏµÄ¼ýÊý
  i=wpn->query("arrow/amount");
if ( !userp(me) )
        i ++;

//Õ½¶·ÖÐÉäÍêÒ²±ØÐë½«¹­³õÊ¼»¯
// 1µÄÊ±ºò¾Í¿ÉÒÔ³õÊ¼»¯....ÒòÎª³õÊ¼»¯Íê»¹»á¹¥»÷Ò»´Î

 if(i==1) {
        tell_object(me, "\nÄãµÄ" + wpn->query("arrow/name") + "ÓÃÍêÁË£¡\n\n");
        wpn->set("arrow/id","none");
        wpn->set("arrow/name","¿ÕµÄ");
        wpn->set("weapon_prop/damage",wpn->query("bow/attack"));

  }
  if (i > 0) {
        i--;
        wpn->set("arrow/amount",i);
                // ºô½ÐÓÐ¼ýÊ±µÄÐðÊö
        return arrow_action[random(sizeof(arrow_action))];
  }

  if( i <= 0) {
                //ºô½ÐÃ»¼ýµÄ¹¥»÷ÐðÊö
        return bow_action[random(sizeof(bow_action))];
  }
//----- under by poloer from --------------------------------------------


        skill_level=(int)me->query_skill("god-shooting", 1);

       if (skill_level < 10)
                return arrow_action[random(2)];
        else if (skill_level < 20 )
                return arrow_action[random(3)];
        else if (skill_level < 30 )
               return arrow_action[random(4)];
                else if (skill_level < 50 )
                return arrow_action[random(5)];
               else if (skill_level < 70 )
                       return arrow_action[random(6)];
               else if (skill_level < 80 )
                      return arrow_action[random(6)+1];
        else if(skill_level<90)
return arrow_action[random(6)+2];
        else
return arrow_action[random(6)+3];


}

int practice_skill(object me)
{
        if( (int)me->query("kee") < 30
        ||      (int)me->query("force") < 3 )
                return notify_fail("ÄãµÄÄÚÁ¦»òÆø²»¹»£¬²»ÄÜÁ·Á÷ÐÇ¼ý·¨¡£\n");
        me->receive_damage("kee", 30);
        me->add("force", -3);
        return 1;
}

string perform_action_file(string action)
{
        return CLASS_D("marksman")+"/god-shooting/"+action;
}

void god_att(object me, object victim, object  weapon, int damage)
{
if((random(80)<me->query_skill("iceforce",1))&&!me->set_temp("break"))
{
victim->start_busy(1);
message_vision(HIB"$N°µÊ¹±ùÐÄ¾÷Ö®Òõº®ÄÚ¾¢£¬½«$nÊÜÄÚ¾¢ËùÀ§¶¯µ¯²»µÃ¡£\n"NOR, me, victim);

}
}

void shooting_att(object me, object victim, object  weapon, int damage)
{
        int lose, i;
int bellpower = (int)me->query("cps")/3;
        // modify by oda
        // combat_exp Ö®±È½ÏÔÚ×ÔÉíÖ® exp ¼ÓÉÏ random
        // lose = skill/10 + 1 ¸ÄÎª random(skill/10) + 3
        // Ôö¼ÓÁ¬»÷Íê±Ï busy Ò»»ØºÏ
if(random(100)<70)
        {
        if(bellpower > 5) bellpower=5;
        lose=random(10);
                me->set_temp("berserk", 1);
                for(i = 0;i < lose; i++)
                {
       message_vision(HIR"$NÄÃÆðÊýÖ§¼ýÊ¹¾¢µÄÍù$nÁ¬Éä¹ýÈ¥¡£\n"NOR, me,victim);
                       }
                victim->add("kee",-50);
                me->delete_temp("berserk");
                message_vision(HIW"Ò»Õó»ìÂÒºó£¬$NÓÃ¾¢¹ý¶È£¬¸Ï½ô³Ã»úµ÷Ï¢¡£\n"NOR,me);

        }
}

void sp_attack1(object me, object victim, object  weapon, int damage)
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
if( me->query("family/family_name")=="ÉäÈÕÅÉ"){
message_vision(HIY"
giggle
\n"NOR,me,victim);

  if( me->query("max_force") > 1000) {
    for(j=0; j < 9; j++) {
       do_action = lan_yan[j];
       actionn = "\n";
       actionn += do_action;

       if( weaponn=me->query_temp("weapon") )
       actionn = replace_string(actionn, "$w", weaponn->name());
       message_vision(actionn, me, enemy[i]);
          if( random(me->query("combat_exp")) >
        random(enemy[i]->query("combat_exp"))/6 ) {
        message_vision("\nµ«ÊÇ$NÉÁ¶ã²»¼°£¬ÉíÉÏ²åÁËÒ»Ö»Ö»µÄÀû¼ý¡£\n" ,enemy[i]);
        enemy[i]->receive_damage("kee",50,me);
        me->add("force",-30);
        COMBAT_D->report_status(enemy[i]);
                                                  }
   else message_vision("\n$N¿´×¼¼ýµÄÀ´ÊÆ£¬²»»Å²»Ã¦µÄÇáÒ×ÉÁ±Ü¡£\n" ,enemy[i]);
     if( random(me->query("cps")) < 10 && random(me->query("combat_exp",1)) < 1000000) {
        me->add("force",-100);

message_vision("\n$NÊ¹³ö"HIR"¡®¡«¡«¡«¡«·ç¡«¡«¡«Îè¡«¡«¡«¾Å¡«¡«¡«Ìì¡«¡«¡«¡«¡¯"NOR"ºó£¬ÓÉÓÚ¶¨Á¦»ò¾­Ñé²»×ã£¬ÌåÄÚÕæÆøÒ»Ê±ÎÞÒÔÎª¼Ì\n",me);
        me->start_busy(1);
                                        }
                                                  }
                                             }

}
}
