// Room: /u/d/dhk/questsfan/room16
inherit ROOM;
#include <ansi.h>
void create ()
{
  set ("short", "[1;32mÂÌ[0m¾§²ã");
  set ("long", @LONG
ÕâÒ»²ãÎ»ÓÚ¹ÈÔµµÄ½á¾§¶¼³ÊÏÖÂÌÉ«µÄ¹âÃ¢£¬ËùÒÔÕâÒ»
²ãµÄ½á¾§ÓĞÒ»ÌØ±ğµÄÃû³Æ½Ğ£¢Óñ¾§Ê¯ ¡å£¬ÒòËüÉ¢·¢×Å±È×î
¸ß¼¶µÄÓñ¸üÂÌ¸üÌŞÍ¸µÄ¹âÔó¡£ÄãÒ»Â·¹Û¿´¹ıÑÓÍ¾Ò»²ã²ã¸÷
Ê½¸÷É«µÄ¾§Ê¯£¬ÁíÄã¸Ğµ½ÖÂÉíÓÚÏÉ¾³ÖĞµÄ¸Ğ¾õ¡¢ÑÛ»¨ÁÃÂÒ
£¬ĞÄÇé¶ÙÊ±¿ªÀÊĞí¶à¡£

LONG);

  set("outdoors", "/u/d");
  set("no_transmit", 1);
  set("exits", ([ /* sizeof() == 2 */
  "westdown" : __DIR__"room17",
  "eastup" : __DIR__"room15",
]));

  setup();
}
