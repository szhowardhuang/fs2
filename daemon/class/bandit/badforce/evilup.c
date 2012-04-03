#include <ansi.h>
inherit F_CLEAN_UP;
int exert(object me,object target)
{
   int ski_lv;
   if (me->query("quests/evilup")!=1)
      return notify_fail("你在干嘛 ?\n");
   if (me->query("bellicosity")>=4000)
      return notify_fail("有杀气了还要运吗?\n");
   if (me->query_skill("badforce",1)<30)
      return notify_fail("你尚未感染恶化魔功的邪恶精义 ,再多加练习吧\n");
   if (me->query("class") != "bandit")
      return notify_fail("你的职业无法使用提升杀气的绝招\n");
   if (me->query("force")<100)
      return notify_fail("想死啊 ?没内力还吸 ?\n");
   ski_lv=me->query_skill("badforce",1)*10;
          me->add("bellicosity",random(ski_lv)+1);
          me->add("force",-50);
          message_vision(
"[1;33m$N利用恶化魔功所隐含的邪恶精义 ,尝试增加自己的杀意。[0m\n[35m结果一股黑气从$N的头上冒出 ,$N四周杀气腾腾□[0m\n",me);
          return 1;

}
      
