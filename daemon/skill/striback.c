#include <ansi.h>
inherit SKILL;
void striback(object me,object victim);

string *parry_msg = ({
 "$nÇÆ×Å$NµÄ¹¥ÊÆ£¬½Å²½Ò»×ª£¬ÏÅÈ»×ª³öÁËÒ»Ê½[1;37m¡®Ð°á°×ªÊÆ¡¯[0m£¬Ë²¼ä±äÖÆ×¡ÁË$NµÄ¹¥ÊÆ£¬×ªÊØÎª¹¥\n",
 "$n´óºÈÒ»Éù£¬³Ã$N»÷³öÒ»»÷ÖØ»÷Ê±£¬Ê¹³öÒ»ÕÐ[1;36m¡®Ð×Õ×ÎèÊÆÂä¡¯[0m£¬$NµÄÉí×ÓÓ²ÊÇÄæ×Å$NµÄ¹¥ÊÆ±Æµ½$NÉíÇ°\n",
 "$n×¢ÊÓ×Å$NµÄ²ã²ã¹¥ÊÆ£¬½Å·æÒ»½Ý£¬µã³öÁËÒ»¼Ç[1;35m¡®É±Ôª¶å¡¯[0m£¬±ã³Ã×Å$NµÄ¹¥ÊÆÉÐÎ´Ê¹¾¡Ç°¼Ü×¡Æä·æ£¬Ó²ÊÇ°Ñ$NÔªÆøÍË»Ø£¬Ê¹µÃ$NÔªÆøÆÄÉË\n",
 "$n×¢Òâµ½$N¼´½«Õ¹¿ª¹¥ÊÆ£¬Ëæ¼´½«Éí·¨·ÅÇá£¬ÄÚÁ¦Äý¾Û£¬ÓÃ³öÁËÒ»ÕÐ[1;34m¡®¶ò¾ª¾õ¡¯[0m£¬$n¿´×¼ÁË$NµÄ¹¥ÊÆÉÐÎ´Õ¹¿ª±ã¿Û×¡ÆäÉí£¬»¢¿ÚÕý¶Ô×¼ÁË$NÄÇÉÐÎ´Ã÷ÁËµÄÁ³¿×ÉÏ\n",
 "$nÑÛ¿´×Å$NÇ¿´ó¹¥ÊÆ¼´½«ÂäÔÚ$nÉíÉÏ£¬ºöÈ»ÐÄÉñÒ»Õð£¬½Å²½¼±×ª³É·ç£¬Ê¹³öµÄÕýÊÇ[1;31m¡®ÎÞÐÄ¾÷¡¯[0m£¬Ö»¼ûµÃ$NµÄÉí×ÓºöÈ»ÄýÖÍ²»Ç°£¬$nÕýÔÚ$NÍ·ÉÏ¹¥ÏÂ\n",
                    });

int valid_enable(string usage)
{
  object me=this_player();
  if ( me->query("class") == "bandit" )
    return (usage=="parry");
 else
    return notify_fail("ÄãÓÖ²»ÊÇ¸ö»µ¶«Î÷ ,Æ¾É¶ÓÃÕâÕÐ ?\n");
}

string query_parry_msg(string limb)
{
  int sb;
  object me=this_player();
  sb = me->query_skill("evilstriback");
  if ( sb <= 80 )
  {
    call_out("striback",me);
  return parry_msg[random(4)];
  }
  else
  {
    call_out("striback",me);
  return parry_msg[random(sizeof(parry_msg))];
  }
}

int valid_learn(object me)
{
  if(me->query_skill("badstrike",1)<30)
    return notify_fail("È­½Å¹¦·ò²»ÔúÊµ»¹ÏëÓÐ·¬×÷Îª ?\n");
  else if (me->query_skill("badforce",1)<30)
    return notify_fail("ÏÈÑ§×ÅÔËÆø°É ,Ð¡×Ó\n");
  else if (me->query_skill("ghost-steps",1)<30)
    return notify_fail("Çá¹¦²»¸ß»¹ÏëÒªÖÆµÐ»úÏÈ ?\n");
  return 1; 
}

void striback(object me,object victim)
{
  int esb;
  esb = (me->query_skill("evilstriback")/10);
  if ( random(esb) >= 5 )
  {
    victim->start_busy(1);
    message_vision("[1;33m$N³É¹¦µÄ½«$nµÄ¹¥ÊÆ·´×ª¹ýÈ¥ ![0m\n", me, victim);
  }
  else
  {
    message_vision("[1;32m$N´í¹ýÁË·´»÷Á¼»ú!![0m\n", me, victim);
  }
}

