#include <ansi.h>
inherit F_CLEAN_UP;
int exert(object me,object target)
{
   int ski_lv;
   if (me->query("quests/evilup")!=1)
      return notify_fail("ÄãÔÚ¸ÉÂï ?\n");
   if (me->query("bellicosity")>=4000)
      return notify_fail("ÓĞÉ±ÆøÁË»¹ÒªÔËÂğ?\n");
   if (me->query_skill("badforce",1)<30)
      return notify_fail("ÄãÉĞÎ´¸ĞÈ¾¶ñ»¯Ä§¹¦µÄĞ°¶ñ¾«Òå ,ÔÙ¶à¼ÓÁ·Ï°°É\n");
   if (me->query("class") != "bandit")
      return notify_fail("ÄãµÄÖ°ÒµÎŞ·¨Ê¹ÓÃÌáÉıÉ±ÆøµÄ¾øÕĞ\n");
   if (me->query("force")<100)
      return notify_fail("ÏëËÀ°¡ ?Ã»ÄÚÁ¦»¹Îü ?\n");
   ski_lv=me->query_skill("badforce",1)*10;
          me->add("bellicosity",random(ski_lv)+1);
          me->add("force",-50);
          message_vision(
"[1;33m$NÀûÓÃ¶ñ»¯Ä§¹¦ËùÒşº¬µÄĞ°¶ñ¾«Òå ,³¢ÊÔÔö¼Ó×Ô¼ºµÄÉ±Òâ¡£[0m\n[35m½á¹ûÒ»¹ÉºÚÆø´Ó$NµÄÍ·ÉÏÃ°³ö ,$NËÄÖÜÉ±ÆøÌÚÌÚ¡õ[0m\n",me);
          return 1;

}
      
