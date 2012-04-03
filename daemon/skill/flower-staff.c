//pd-staff.c editer.by Chan

#include <ansi.h>
#include <combat.h>
inherit SKILL;
inherit SSERVER;
void attack1(object me, object victim, object  weapon, int damage);
void again1(object me, object victim, object  weapon, int damage);
string *array_msg=
    ({
      "[1;33m$N¥¯¡Ï◊≈¥Ûº“£¨–ŒªØÀƒœÛ£¨∏¥ªØ∞Àÿ‘ π¥Úπ∑’Û∑®∑¢ª”÷¬º´µ„°£\n[0m",
      "[1;33m÷⁄»À∑¢ª”≥ˆ’Û∑®÷Æ∞¬√Ó±‰ªØ£¨ πµ–»Àœ›»Îæ¯Õ˚µƒ…Ó‘®°£\n[0m",
      "^[[1;33m$N÷∏ª”»Ù∂®£¨÷⁄»ÀŒ‰π¶≈‰∫œµƒÃÏ“¬Œﬁ∑Ï£¨Ω´’– Ωµ›œÚµ–»À°£\n^[[0m",
      "[1;33m÷⁄»À∑¢ª”≥ˆ’Û∑®÷ÆŒﬁ«Ó∞¬“Â£¨Ω´∂‘µ–»ÀµƒÀ∫¶∑¢ª”≥ˆ◊Ó¥Ûµƒæ≥ΩÁ\n[0m",
     });
mapping *action = ({
(["action":"$N∂‘◊º$nµƒ»ıµ„,øÒª”∂¯œ¬ π≥ˆ"HIW"°∏¡¶≈¸ª™…Ω°±"NOR",∂‘◊º$nµƒ$l≤ø∑›ª˜œ¬",
"dodge":-60,
"parry":90,
"force":60,
"damage":50,
"damage_type" : "ˆ…À",
]),
(["action":"$Nø¥≥ˆ$nµƒ’÷√≈ π“ª’–"HIW"°∏ª¢ª¢…˙∑Á°±"NOR", ÷÷–µƒ∞Ù◊”º–¥¯«ø¥Ûµƒ∆¯æ¢œÚ$nµƒ$lª”≥ˆ",
"dodge":-60,
"parry":90,
"force":70,
"damage":50,
"damage_type" : "ˆ…À",
]),
(["action":"$NΩ´ ÷…œµƒ∞Ù◊”,÷±÷±ÿ›œÚ$nµƒ$l’˝ «“ª’–"HIW"°∏÷±π•∂¯»Î°±"NOR,
"dodge":-90,
"parry":110,
"force":100,
"damage":60,
"damage_type" : "ÿ›…À",
]),
(["action":"$N‘æ÷¡∞Îø’÷–,∏ﬂæŸ ÷÷–µƒ∞Ù◊”√Õª”∂¯œ¬“ª’–"HIW"°∏¡˜–«∏œ‘¬°±"NOR"£¨»Á¡˜–«∞„œÚ$nµƒ$lº±≈¸∂¯œ¬",
"dodge":-90,
"parry":110,
"force":100,
"damage":70,
"damage_type" : "∏Ó…À",
]),
(["action":"$NΩ´ ÷÷–µƒ∞Ù◊”,º±ªÆ∑¥◊™ π≥ˆ¡´ª®’»∑®÷Æ∞¬“Â"HIW"°∏Œﬁæ°Œﬁª⁄°±"NOR"£¨¬˛ÃÏµƒ∞Ù”∞œÚ$nµƒ$lœÆ»•",
"dodge":-90,
"parry":110,
"force":100,
"damage":80,
"post_action":  (: again1 :),
"damage_type" : "ƒ⁄…À",
]),
(["action":"$N√Ê∂‘$n≥™≥ˆ¡´ª®¬‰÷Æ"HIW"°∏∆ÚÃ÷”‡∏˛°±"NOR"£¨Ω´$nµƒπ•ª˜“ª∑‚",
"dodge":-90,
"parry":120,
"force":100,
"damage":90,
"post_action":  (: attack1 :),
"damage_type" : "ˆ…À",
]),
(["action":"$N“‘µ–≤ª∂Ø,Œ“≤ª∂Ø√Ê∂‘$n“‘“ª’–∞¬“Â"HIC"°∏¡´ª®Œﬁ”∞°±"NOR" π$n±ªÃÙ÷¡ø’÷–≤¢¥”≈‘œÚ$lª˜≥ˆ",
"dodge":-100,
"parry":120,
"force":100,
"damage":90,
"damage_type" : "ˆ…À",
]),
(["action":"$NƒÊ‘À’Ê∆¯,ª√ªØŒﬁ–Œ¡´ª®∞¬“Â"HIC"°∏øÒ∑Á≈≠∫°±"NOR"£¨∞Ùæ¢À˘–Œ≥…µƒ∑Áæ¢œÚ$nµƒ$lœÆ»•",
"dodge":-100,
"parry":130,
"force":100,
"damage":90,
"damage_type" : "ˆ…À",
]),
});

mapping query_action(object me, object weapon)
{
int skill;
   skill=me->query_skill("follow-staff", 1);
   if( me->query_temp("use_form",1))
     message_vision( array_msg[random(sizeof(array_msg))],me );
   if( skill < 50)
      return action[random(4)];
   else if( skill < 60)
      return action[random(4)+1];
   else if( skill < 70)
      return action[random(4)+2];
   else if( skill < 90)
      return action[random(4)+3];
   else
      return action[random(4)+4];
}
void attack1(object me, object victim, object weapon, int damage)
{
 int busy_value,skill;
 skill=me->query_skill("follow-staff", 1);
 busy_value = skill / 3;
 if((me->query_skill_mapped("force")=="followforce")&&(me->query("force_factor") >= 1 ))
  {
   message_vision(HIY"$NΩ´¡´ª®’»∑®Ω·∫œ∫Õ¡´∑®–ƒ∑®∑¢≥ˆ∆¯Àø∑‚◊°$nµƒÀƒ÷´∞Ÿ∫°\n"NOR,me,victim);
   victim->start_busy( busy_value );
   COMBAT_D->report_status(victim, 1);
  }
}

void again1(object me, object victim, object weapon, int damage)
{
 int i,value,k=0,skill,l=5;
 skill=me->query_skill("follow-staff", 1);
 skill = skill / 10;
 if(skill > 9)
 {
  k = 6;
  l = 3;
 }
 else if (skill > 7)
      {
       k = 5;
       l = 4;
      }else if (skill > 4 )
       {
        k = 4;
        l = 5;
       }
 if(me->query("force")>100&&me->query("force_factor"))
 {
   for (i=0;i<k;i++)
    {

      message_vision(HIW"$N π≥ˆ¡´ª®∞Ù∑®÷Æ°∏¬“ª˜÷Æºº°±,Œﬁ ˝µƒ’»”∞œÚ$nøÒ…®∂¯»•°£\n"NOR, me, victim);
      value = random (10);
      if (value >= l)
       {
        message_vision("Ω·π˚±ª$N◊º»∑µƒ√¸÷–“™∫¶,$n…Ì…œ¡Ùœ¬…Ó∫Òµƒ∞Ù∫€°£\n", me, victim);
        victim->receive_wound("kee",25,me);
        me->add("force",-50);
        COMBAT_D->report_status(victim, 1);
       }
      else
        message_vision("Ω·π˚$n‘⁄¬˛ÃÏµƒ∞Ù”∞¥©¡À≥ˆ¿¥°£\n", me, victim);
    }
    message_vision(HIW"“ª’ÛøÒ…®÷Æ∫Û£¨$Nƒ⁄æ¢À∫ƒπ˝¥Û£¨Œﬁ∑®“∆∂Ø°£\n"NOR,me);
    me->start_busy(1);
    COMBAT_D->report_status(victim, 1);
  }
}

int practice_skill(object me)
{
  if( (int)me->query("kee") < 30 )
      return  notify_fail("ƒ„µƒ∆¯≤ªπª£¨Œﬁ∑®¡∑œ∞¡´ª®’»∑®°£\n");
  if( (int)me->query("force") < 5 )
      return  notify_fail("ƒ„µƒƒ⁄¡¶≤ªπª£¨≤ªƒ‹¡∑œ∞¡´ª®’»∑®°£\n");
  me->receive_damage("kee", 30);
  me->add("force", -5);
  return 1;
}

string perform_action_file(string action)
{
          return CLASS_D("beggar")+"/follow-staff/"+action;
}
int valid_learn(object me)
    {
        object weapon = me->query_temp("weapon");
        if( me->query("max_force") < 50 ) {
            tell_object(me, "ƒ„µƒƒ⁄¡¶–ﬁŒ™≤ªπª, ◊Ó…Ÿ“™”–ŒÂ Æµ„°£\n");
            return 0;
        }
        if(!(me->query("class") == "beggar")) {
            tell_object(me, "÷ª”–ÿ§∞Ôµ‹◊”≤≈ƒ‹—ß¡´ª®’»∑®°£\n");
            return 0;
        }
        if( me->query("str") >= 20 ) {
            tell_object(me, "ƒ„µƒ±€¡¶π˝¥ÛŒﬁ∑®—ß¡´ª®’»∑®°£\n");
            return 0;
        }
        if( !weapon || weapon->query("skill_type") != "staff" ) {
            tell_object(me, " ÷÷–Œﬁ∞Ù‘ı√¥∏ˆ¡∑∑®—Ω?\n");
            return 0;
        }
        return 1;
}
int valid_enable(string usage)
{        return ( usage=="staff" )||(usage=="parry");
}
