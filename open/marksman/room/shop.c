// Room: /crystal/fantasy/Lbird_shop.c
inherit ROOM;

#include <ansi.h>
#include <room.h>
void create ()
{
  set ("short", "[1;36m³¤É³Õò[1;35m©¤[1;33m·ï»ËÂòÂôµê[2;37;0m");
  set ("long", @LONG
ÕâÀïÊÇ³¤É³ÕòÖøÃûµÄ·ï»ËÆÜÏ¢µØ£¬ËüÃÇÊÇÎªÁË°éËæÀî¹ã¶ø·ÉÀ´ÕâÀï£¬
ÓÉÒ»Î»Ğ¡Å®»¹ÕÕ¹ËËüÃÅ£¬Ò²´ğÓ¦µ±Àî¹ãÃÅÏÂµÄ×ùÆï£¬ÄãÈôÊÇ±¾ÅÉÃÅÉú£¬
¼´¿ÉÂòÒ»Ö»À´Æï£¬ÏêÇéÇë¿´(sign)¡£
LONG);

  set("objects", ([ /* sizeof() == 1 */
  "/open/marksman/npc/shopgirl" : 1,
]));
  set("item_desc", ([ /* sizeof() == 1 */
  "sign" : "    Èç¹ûÄãÏë¹ºÂòÒ»Ö»·ï»ËµÄ»°£¬ÔÚ³¤É³ÕòÖĞÄã±ØĞëÄÃµ½·ï»Ë
ÈÏÑøÖ´ÕÕ¨Û£¬Èç¹ûÄãÒÑ¾­·ûºÏ¹æ¶¨ÁË£¬Çë×ñÕÕÒÑÏÂ³ÌĞò¹ºÂò¡£

          1.Ñ¡Ôñ·ï»Ë--list.
          2.ÄÃ³öÇ®À´¹ºÂò·ï»Ë--shop.
          3.¹ºÂò·ï»Ë×¨ÓÃÉÚ×Ó--shop come-sum.

",
]));
  set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"room1-11",
]));
  set("light_up", 1);

  setup();
}
