// Room: /u/d/dhk/questsfan/room11
inherit ROOM;
#include <ansi.h>
void create ()
{
  set ("short", "[0;31m×Ø[0m¾§²ã");
  set ("long", @LONG
ÕâÒ»²ãÎ»ÓÚ¹È¿ÚµÄ½á¾§¶¼³ÊÏÖ×ØÉ«µÄ¹âÃ¢£¬ËùÒÔ¹ËÃû
Ë¼ÒåÕâÒ»²ãµÄ½á¾§½Ğ£¢×Ø¾§Ê¯ ¡å£¬Æä²ÄÖÊºÍ¹ÈÍâµÄ¾§ÇÅ´ó
Í¬Ğ¡ÒìÒ²ÊÇÒ»ÆæÊ¯Ò²¡£ö®Ê±Äã¸ĞÌ¾¼ûÎÅÌ«ÉÙ£¬ÊÀÉÏ¾¹ÓĞ´Ë
Ææ¾°¡¢ÆæÕä¾¹µÚÒ»´Î¼ûÊ¶¡£

LONG);

  set("outdoors", "/u/d");
  set("no_transmit", 1);
  set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"room10",
  "east" : __DIR__"room12",
]));

  setup();
}
