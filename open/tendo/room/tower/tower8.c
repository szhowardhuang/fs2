
inherit ROOM;
#include <ansi.h>
void create ()
{
  set ("short", "ËøÑýËþ°ËÂ¥--");
  set ("long", @LONG
ÕâÊÇËøÑýËþÖÐµÄ×îºóÒ»²ã£¬¿´ÁË¿´ËÄÖÜ£¬ÐÄÖÐÉî¸Ð²»¿ÉË¼Òé£¬ÖÜÎ§
¾¡ÊÇÒ»¶Ñ¶ÑµÄ°×¹Ç£¬°×¹ÇÅÔÉ¢Âä×ÅÒ»¶Ñ¶ÑµÄÎäÆ÷¼°×°±¸£¬ÊÒÄÚµ½´¦ÃÖÂþ
×ÅÒ»ÖÖËµ²»³öµÄ¹îÒìÆø·Õ£¬Ê±ÓÐÌýµ½¶¯Îï²Ò½ÐµÄÉùÒô£¬Ê±¶øÎÅµ½Å¨ºñµÄ
ÑªÐÈÎ¶µÀÁîÄã²»º®¶ø²ü¡£Î÷²àµÄÇ½½ÇËÆºõ°ÚÁËÒ»ÕÅ¼Ü×Ó (shelf)£¬¿´Æð
À´Õæ²»Ð­µ÷¡£
LONG);

  set("item_desc", ([ /* sizeof() == 1 */
"shelf" : "Ò»ÕÅ³¤Âú»Ò³¾µÄ¼Ü×Ó£¬²»¹ýËÆºõ¿ÉÒÔÍÆµÄÑù×Ó¡£
",
]));
  set("exits", ([ /* sizeof() == 1 */
  "down" : __DIR__"tower7",
]));
       set("no_transmit",1);

  setup();
}

void init()
{
add_action ("do_push","push");
}

int do_push (string str)
{
  object        me;
   if (!str || (str != "shelf" && str != "±øÆ÷¼Ü"&& str != "¼Ü×Ó"))
return notify_fail("[1;32mÍÛßÖ£®£®Ã»ÊÂ²»ÒªÂÒÍÆ£¡[0m\n");

  me = this_player();
    message_vision("[1;32mµØÉÏÍ»È»³öÏÖÒ»¸ö¶´£¬ÄãÀ´²»¼°Ìø¿ª±ãË¤ÁËÏÂÈ¥!![0m\n", me);

    me->move(__DIR__"tower8-1.c");
    tell_room(environment(me), sprintf ("[1;32m%sÏñ¿ÅÊ¯Í·°ãË¤ÁËÏÂÀ´ .[0m\n",
     me->short()), me);
  return 1;
}


