// Room: /u/d/dhk/questsfan/room12
inherit ROOM;
#include <ansi.h>
void create ()
{
  set ("short", "[1;31mºì[0m¾§²ã");
  set ("long", @LONG
ÕâÒ»²ãÎ»ÓÚ¹È¿ÚµÄ½á¾§¶¼³ÊÏÖºìÉ«µÄ¹âÃ¢£¬ËùÒÔ¹ËÃû
Ë¼ÒåÕâÒ»²ãµÄ½á¾§½Ğ£¢ºì¾§Ê¯ ¡å£¬ÆäÑÕÉ«Í¨ÌåºìÍ¸£¬ËÆÒ»
ãü½«Òç³öµÄÏÊÑªÒ»°ã¡£ÄãÒ»Â·¹Û¿´¹ıÑÓÍ¾Ò»²ã²ã¸÷Ê½¸÷É«
µÄ¾§Ê¯£¬ÁíÄã¸Ğµ½ÖÂÉíÓÚÏÉ¾³ÖĞµÄ¸Ğ¾õ¡¢ÑÛ»¨ÁÃÂÒ£¬ĞÄÇé
¶ÙÊ±¿ªÀÊĞí¶à¡£


LONG);

  set("outdoors", "/u/d");
  set("no_transmit", 1);
  set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"room11",
  "north" : __DIR__"room13",
]));

  setup();
}
