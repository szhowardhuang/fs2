// Room: /open/badman/room/r13

#include </open/open.h>

inherit ROOM;

void create ()
{
  set ("short", "³ø·¿");
  set ("long", @LONG
ÄãË³×ÅÏãÎ¶µÄÀ´Ô´×ßÁË½øÀ´£¬Ô­À´ÕâÀï¾ÍÊÇÕâ¼Ò·¹¹İµÄ³ø·¿£¬
ÁîÈË¾ªÑÈµÄÊÇ£¬ÕâÀïµÄÕÆ³ø¾¹È»ÊÇ°®³ÔÈËÈâ³öÃûµÄÀî´ó×ì£¬ÈÃÄã²»
½ûÒª»³ÒÉÕâÀïÂôµÄÊÇÊ²Ã´ÈâÁË¡£Ïëµ½ÕâÀï£¬Ô­±¾Â¯×ÓÉÏÁîÈË´¹ÏÑÈı
³ßµÄÏãÎ¶Ò²¿ªÊ¼±äµÃÁîÈË×÷¶ñ£¬ÄãºöÈ»·¢ÏÖÀî´ó×ìÕıÁ÷×Å¿ÚË®¶¢×Å
ÄãÃÍ¿´ÄØ£¡Ê¶ÏàµÄ»¹ÊÇ¿ìÁï°É¡£

LONG);

  set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"r1",
]));
  set("objects", ([ /* sizeof() == 1 */
  BAD_NPC"lee" : 1,
]));
  set("light_up", 1);

  setup();
}

int valid_leave(object who, string dir)
{
  if( present("lee da tswei", this_object()) ) {
  if( dir=="south" && who->query_skill("badforce",1)>30 && who->query("bellicosity")>200 && who->query("quests/evilup")!=1 && who->query_temp("evilup")!=1) {
  switch(random(3)) {
  case 0:
    who->set_temp("evilup",1);
   who->set_temp("yang",1);
   tell_object(who,"[1;33mÀî´ó×ìßÖ×ìËµµÀ :°¦ßÏ ,ÔõÀ² ?³îÃ¼¿àÁ³µÄ ,É¶ ?²»ÖªµÀÔõÃ´¸üºÃ\nºÃÀûÓÃ¶ñ»¯Ä§¹¦ ?ºÙ ,Õâ¸ö¼òµ¥....²»¹ıÄãµ¹Òª°ïÎÒ×ö¼şÊÂ ,Ö»Òª\nÄã°ÑÑîĞÄæÃÄÇĞ¡Äİ×ÓÄÃÀ´¸øÎÒ‡Ÿ‡Ÿ ,°ü×¼½Ìµ½Äã»áÎªÖ¹ !....¼ÇµÃ\n ,ÒªĞÂÏÊµÄà¸¡£[0m\n");
    break;
  case 1:
    who->set_temp("evilup",1);
   who->set_temp("kou",1);
   tell_object(who,"[1;33mÀî´ó×ìßÖ×ìËµµÀ :°¦ßÏ ,ÔõÀ² ?³îÃ¼¿àÁ³µÄ ,É¶ ?²»ÖªµÀÔõÃ´¸üºÃ\nºÃÀûÓÃ¶ñ»¯Ä§¹¦ ?ºÙ ,Õâ¸ö¼òµ¥....²»¹ıÄãµ¹Òª°ïÎÒ×ö¼şÊÂ ,Ö»Òª\nÄã°Ñ¹ùĞ¥·çÄÇÌõºº×ÓÄÃÀ´ÈÃÎÒ‡Ÿ‡Ÿ ,°ü×¼½Ìµ½Äã»áÎªÖ¹ !....¼ÇµÃ\n ,ÒªĞÂÏÊµÄà¸¡£[0m\n");
    break;
  case 2:
    who->set_temp("evilup",1);
   who->set_temp("chen",1);
   tell_object(who,"[1;33mÀî´ó×ìßÖ×ìËµµÀ :°¦ßÏ ,ÔõÀ² ?³îÃ¼¿àÁ³µÄ ,É¶ ?²»ÖªµÀÔõÃ´¸üºÃ\nºÃÀûÓÃ¶ñ»¯Ä§¹¦ ?ºÙ ,Õâ¸ö¼òµ¥....²»¹ıÄãµ¹Òª°ïÎÒ×ö¼şÊÂ ,Ö»Òª\nÄã°Ñ³ÂĞşÁúÄÇ½áÊµµÄÉí×ÓÄÃÀ´ÈÃÎÒÆ·Î¶Æ·Î¶ ,°ü×¼½Ìµ½Äã»áÎªÖ¹ !\n....¼ÇµÃ ,ÒªĞÂÏÊµÄà¸¡£[0m\n");
    break;
    default:
    return notify_fail("ºÙ ,¼ÓÓÍ°¡ !\n");
   }
  }
}
    return ::valid_leave(who, dir);
}
