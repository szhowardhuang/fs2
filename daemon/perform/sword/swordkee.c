#include <combat.h>
#include <ansi.h>
inherit SSERVER;
inherit F_FUNCTION;
int perform(object me, object target)
{
   object *enemy,weapon;
   int damage,i,fun;
   object victim;
   victim=this_player()->enemy();
   enemy=me->query_enemy();
   i=sizeof(enemy);
   fun=me->query("functions/swordkee/level");
if(me->query("class") != "swordsman")
  return notify_fail("ƒ„µƒ÷∞“µŒﬁ∑® π≥ˆΩ£∆¯°£\n");
if( me->query("force") < 250)
  return notify_fail("ƒ„µƒƒ⁄¡¶≤ªπª°£\n");
if( me->query_skill("sword",1) < 70 )
  return notify_fail("ƒ„µƒª˘±æΩ£ ıÃ´≤Ó¡À°£\n");
if( !me->is_fighting() )
  return notify_fail("Ω£∆¯“™’Ω∂∑÷–≤≈ƒ‹ π”√°£\n");
if(!objectp(weapon=me->query_temp("weapon")) || (string)weapon->query("skill_type")!="sword")
  return notify_fail("“™”–Ω£≤≈ƒ‹∑¢Ω£∆¯°£\n");
if(fun==100) 
 {
    message_vision(HIC"$N¥Û∫»“ª…˘∑¢≥ˆÀ˘”–Ω£∆¯!!!\n\n"HIB"“ª’–"HIR"Ω£∆¯"HIW"∆∆µ–"HIY"---"HIG"  °Æ"HIR" Ø∆∆ÃÏæ™"HIG"°Ø!!!\n\n"NOR,me);
damage=me->query_skill("sword",1)*7+random(200);
 }
else if(fun<=20) 
 {

message_vision("[1;30m$NΩ´ƒ⁄¡¶π·◊¢‘⁄Ω£…œ£¨√Õ»ª“ªª”, ÷ªª”≥ˆº∏µ¿¡„–«µƒΩ£∆¯£°[0m\n",me);
    damage=me->query_skill("sword",1);
 }
else if(fun<=40&&fun>=21) 
 {
    message_vision("[1;31m$NΩ´ƒ⁄¡¶π·◊¢‘⁄Ω£…œ£¨√Õ»ª“ªª”£¨ ˝µ¿Ω£∆¯Ã⁄≥ˆ, ≤¢∑÷ª˜‘⁄≥°∏˜∏ˆµ–»À£°[0m\n",me);
    damage=me->query_skill("sword",1)*3/2;
 }
else if(fun<=60&&fun>=41) 
 {
    message_vision("[1;34m$NΩ´ƒ⁄¡¶π·◊¢‘⁄Ω£…œ£¨√Õ»ª“ªª”£¨ ˝ Æµ¿Ω£∆¯Ã⁄≥ˆ£¨Ω£∆¯∑÷±…‰œÚÀƒ√Ê∞À∑Ω£°[0m\n",me);
    damage=me->query_skill("sword",1)*2;
 }
else if(fun<=80&&fun>=61) 
 {
    message_vision("[1;32m$NΩ´ƒ⁄¡¶π·◊¢‘⁄Ω£…œ£¨√Õ»ª“ªª”£¨÷ªº˚“ªµ¿“´—€µƒ«‡Õ≠Ω£∆¯Ã⁄≥ˆ÷±±∆‘⁄≥°À˘”–…˙ŒÔ£°[0m\n",me);
    damage=me->query_skill("sword",1)*3;
 }
else if(fun>=81&&fun<=99) 
 {
    message_vision("[1;33m$NΩ´ƒ⁄¡¶π·◊¢‘⁄Ω£…œ£¨√Õ»ª“ªª”£¨ª∆ΩΩ£∆¯∂Ÿ ±¡˝’÷»´…Ì, ≤¢œÚÕ‚¿©…¢∑÷ª˜∏˜∂‘ ÷£°[0m\n",me);
   damage=me->query_skill("sword",1)*4;
 }
  me->add("force",-50);
  me->start_busy(1);
  while(i--) {
  if(!me || !enemy[i]) continue;
if(environment(me)!=environment(enemy[i])) continue;   
    if(random(me->query_skill("sword"))*10>enemy[i]->query_skill("dodge")+enemy[i]->query_skill("parry"))
      {
        enemy[i]->receive_wound("kee",damage);
        message_vision(HIR"$N…¡∂„≤ªº∞£¨Ω£∆¯“—‘⁄∆‰…Ì…œªÆ≥ˆ“ªµ¿—™¡‹¡‹µƒ…À∫€£°\n"NOR,enemy[i]);
        enemy[i]->start_busy(1);
        COMBAT_D->report_status(enemy[i],1);
      }
    else 
{
message_vision(YEL"$N≤‡…Ì“ª…¡£¨±‹ø™¡ÀΩ£∆¯£°\n"NOR,enemy[i]);
}
          }
if(fun<100) { function_improved("swordkee",random(300)); }
return 1;
}

