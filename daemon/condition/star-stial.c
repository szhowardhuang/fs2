// Chan 1/5ÖØĞÂĞŞÕı
#include <ansi.h>

int update_condition(object me, int duration)
{
if(duration==0) return 0;
if( duration >= 1 )
  {
        tell_object( me , HIB "ÄãµÄËùÊÜµÄÄÚÉË·¢×÷£¬Ö»¾õµÃĞØ¿Ú³öÏÖÒ»ÕóÕó½ÊÍ´¡£\n" NOR);
        message("vision", me->name() + "[32mºöÈ»°µÉË·¢×÷,Á³ÉÏÏÔÊ¾Í´¿àÒì³£µÄ±íÇé.[0m \n",
        environment(me), me);
        me->add("kee",-150);
        me->add("eff_kee",-150);
        if( me->query("force") < 0 ) me->set("force",0);
        me->apply_condition("star-stial",duration -1);
        COMBAT_D->report_status(me, 1);
   }
  return 1;
}
