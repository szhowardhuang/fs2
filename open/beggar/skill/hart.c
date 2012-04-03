// Chan 1/5ÖØĞÂĞŞÕı
// ÓÃÓÚãñÉ½µÄÎäÑ§Ö®ÖĞ
#include <ansi.h>

int update_condition(object me, int duration)
{
  if( duration > 1 )
  {
        tell_object( me , HIY "ÄãµÄÄÚÉË·¢×÷,Ö»¾õµÃÈ«Éí¾­ÂöºÃÏñÒÆÎ»°ã,Ê®·ÖÍ´¿à!!\n" NOR);
     message("vision", me->name() + "[1;37m°µÉË·¢×÷,Õû¸öÈËÇüÔÚµØÉÏ±íÏÖ³ö¼«ÎªÍ´¿àµÄ±íÇé.[0m \n",
     environment(me), me);
     if(me->is_fighting())
      me->start_busy(1);
        me->add("kee",-20);
        me->add("force",-40);
        if( me->query("force") < 0 ) me->set("force",0);
        me->apply_condition("hart",duration -1);
        COMBAT_D->report_status(me, 1);
   }
  if( duration < 2 )
   return 0;
  return 1;
}
