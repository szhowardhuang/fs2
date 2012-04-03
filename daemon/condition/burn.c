// burn.c Desigh by Chan
//”–Œ Ã‚«Îpost
#include <combat.h>
inherit F_CLEAN_UP;
int update_condition(object me, int duration)
{
  if( !living(me) )
   {
     message("vision", me->name() + "[31m…Ì…œµƒ◊∆…À…–Œ¥»¨”˙, µ´ «æıµ√À∆∫ı”Õæ°µ∆ø›\¡À!![0m\n",
     environment(me), me);
   }
  else
  if( duration > 10)
   {
     tell_object(me, "[31mƒ„µƒ◊∆…ÀÀ∆∫ı∫‹—œ÷ÿ, …Àø⁄Ωπ∫⁄.[0m\n");
     message("vision", me->name() + "[1;31m…Ì…œ∑¢»»æﬁÕ¥, ≤¢”–—œ÷ÿÕ—ÀÆµƒœ÷œÛ.[0m \n",
     environment(me), me);
     me->receive_wound("kee", 300);
     me->receive_damage("kee",300);
     if( (int)me->query("water")>=50 )
      me->add("water", -50);
     else
      me->set("water", 0);
    }
    else
    if( duration > 5 )
     {
      tell_object(me, "[31mƒ„æıµ√…Ì…œµƒ◊∆…Àø™ ºÕ ∆§¡À, …Àø⁄∫Ï÷◊Ã€Õ¥.[0m \n");
      message("vision", me->name() + "[1;31m…Àø⁄»‘∑¢»»÷◊Õ¥, µ´Õ—ÀÆ÷¢◊¥”–À˘ºı«·[0m\n",
      environment(me), me);
      me->receive_wound("kee", 200);
      me->receive_damage("kee",200);
      if( (int)me->query("water")>=30 )
       me->add("water", -30);
      else
       me->set("water", 0);
      }
      else
      if( duration > 1)
      {
       tell_object(me, "[1;37mƒ„…Ì…œµƒ◊∆…Àø™ ºΩ·∞Ã¡À, “≤∏–æı≤ªµΩÕ¥ø‡¡À.[0m \n");
       message("vision", me->name() + "[1;31mµƒ…Ì…œ”–“ªµ¿–¬∞Ã, ∫√œÒ ‹µΩ≤ª«·µƒ…À∫¶.[0m \n",
       environment(me), me);
       me->receive_wound("kee", 100);
       me->receive_damage("kee",100);
       me->add("kee",-2);
       if( (int)me->query("water")>=10 )
        me->add("water", -10);
       else
        me->set("water", 0);
      }
  me->apply_condition("burn", duration - 1);
  COMBAT_D->report_status(me, 1);
  if( duration < 2 )
   return 0;
  return 1;
}
