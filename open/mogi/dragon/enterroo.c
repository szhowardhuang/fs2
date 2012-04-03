// Room: /u/p/poloer/dragon/enterroom
inherit ROOM;
#include <ansi.h>
void create ()
{
  set ("short", "[1;32mÑ×Áú¹ÈÈë¿Ú[2;37;0m");
  set ("long", @LONG
Ò»¸öÎ»ÓÚÉ½½ÅÏÂµÄµØ·½£¬Ò²¾ÍÊÇ´«ËµÖÐÐ×¶ñÑ×Áú¶ã²ØµÄµØ·½
¡£´ÓÕâÀïÍùÉ½ÉÏ¿´È¥ÒþÔ¼ÔÚÉ½¶¥ÉÏÓÐÒ»¼ä¿í´óµÄ¹¬µî£¬Ò»ÌõÐ¡Â·
´Ó¹¬µîÒ»Ö±ÑÓÉìµ½É½Ñü£¬µ«É½Ñü±»ÎíÕÚ¸Ç×¡ÁË£¬¿´²»³öÓÐÊ²Ã´¶«
Î÷¡£ËÄÖÜ¿´À´ËÀÆø³Á³Á£¬ºÁÎÞÉúÆø£¬¹Ö¿Ö²ÀµÄ¡£ÅÔ±ßÓÐÒ»¿éÊ¯±®
(stone)µ²ÔÚÂ·ÖÐÑë¡£
      ÕâÀïÒ»Æ¬ÎíÃ£Ã£¿´²»µ½ÈÎºÎ³öÂ·¡£
LONG);

  set("item_desc", ([ /* sizeof() == 1 */
  "stone" : "
   Îä¹¦Î´Êì£¬ËÀÂ·Ò»Ìõ
         
         
   ",
]));
  set("no_transmit", 1);
  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/fire-dra.c" : 2,
]));
  set("exits", ([ /* sizeof() == 2 */
  "enter" : __DIR__"a2",
  "east" : __DIR__"dr10",
]));

  setup();
}
int valid_leave(object me, string dir)

{
        if(dir=="enter"&&present("fire-dragon guard",environment(me)))
  {
if(me->query("combat_exp") < 299999 ||
me->query("max_force") <999)
{
message_vision("Ñ×ÁúÎäÊ¿¶Ô$NÅ­ºÈ : ÕâÀïÆñÄÜÈÃÄã×ÔÓÉ½ø³ö£¡£¿\n",me);
return 0;
}
}
return 1;
}
