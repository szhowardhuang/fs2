// Room: /u/d/dhk/questsfan/room13
inherit ROOM;
#include <ansi.h>
void create ()
{
  set ("short", "[0;33méÙ[0m¾§²ã");
  set ("long", @LONG
ÕâÒ»²ãÎ»ÓÚ¹È¿ÚµÄ½á¾§¶¼³ÊÏÖéÙÉ«µÄ¹âÃ¢£¬ËùÒÔ¹ËÃû
Ë¼ÒåÕâÒ»²ãµÄ½á¾§½Ğ£¢éÙ¾§Ê¯ ¡å£¬´ËµØµÄÆø·Õ¡¢¹âÃ¢Ê¹Äã
ÓĞÈç´ºÌì°Ù»¨Ê¢¿ªµÄ¸Ğ¾õ£¬ĞÄÇéÑóÒç×Å´º·ç¡£ÄãÒ»Â·¹Û¿´
¹ıÑÓÍ¾Ò»²ã²ã¸÷Ê½¸÷É«µÄ¾§Ê¯£¬ÁíÄã¸Ğµ½ÖÂÉíÓÚÏÉ¾³ÖĞµÄ
¸Ğ¾õ¡¢ÑÛ»¨ÁÃÂÒ£¬ĞÄÇé¶ÙÊ±¿ªÀÊĞí¶à¡£

LONG);

  set("outdoors", "/u/d");
  set("no_transmit", 1);
  set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"room12",
  "north" : __DIR__"room14",
]));

  setup();
}
