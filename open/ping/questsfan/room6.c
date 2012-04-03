// Room: /u/d/dhk/questsfan/room6
inherit ROOM;
#include <room.h>
#include <ansi.h>
void create ()
{
  set ("short", "[0;32mºóÉ½²İ´Ô[0m");
  set ("long", @LONG
ÕâÀï¾ÍÊÇ´óÀíÆ½ÄÏ³ÇµÄºóÉ½£¬µ«ÊÇÕâÀïµÄÔÓ²İÓÖ¸ßÓÖ
³¤¾¹±ÈÄã»¹¸ß£¬×ã×ãÓĞÁ½ÕÉ³¤¡£²»¹ı´ËµØµÄ·ç´óµÄÒì³££¬
Èô²»¶à¿÷ÕâĞ©²İ£¬Ëµ²»¶¨ÓĞ±»·ç´µµ¹µÄÎ£ÏÕÄØ£¡

LONG);

  set("out_door", 1);
  set("no_transmit", 1);
  set("item_desc", ([ /* sizeof() == 1 */
  "out" : "q
",
]));
  set("exits", ([ /* sizeof() == 2 */
  "enter" : __DIR__"room5",
  "north" : __DIR__"qroom/room0",
]));

  setup();
}
