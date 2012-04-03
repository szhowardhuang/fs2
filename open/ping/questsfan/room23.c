// Room: /u/d/dhk/questsfan/room23
inherit ROOM;
#include <ansi.h>
void create ()
{
  set ("short", "Áâ[0;32m¾§[0m²ã");
  set ("long", @LONG
ÕâÒ»ÇøµÄ½á¾§¾ÍÃ»ÓĞÑÕÉ«ÁË£¬½Ô³ÊÏÖÍ¸Ã÷ÇÒ¸÷¾§Ê¯µÄ
Áâ½Ç»áÉÁË¸×ÅĞ©ĞíµÄÎ¢¹â¡£¶øÇÒÑÓÍ¾µÄ½á¾§¶¼³Ê²»¹æÔòÓÖ
ÁâÁâ½Ç½ÇµÄĞÎ×´£¬ÓëÖ®Ç°É«²ÊçÍ·×¡¢²ÓÀÃÓĞ×ÅÌì²îµØÔ¶µÄ
²îÒì¡£Æä·´Ó³³ö¶à±ä¡¢³öÆæÖ®ÆøÖÊ¡£ÈôÓ²ÒªĞÎÈİËü£¬ÄÇÎÒ
Ö»ÄÜÓÃ£¢±ä¡åÕâÒ»¸ö×ÖÀ´ĞÎÈİ¡£

LONG);

  set("outdoors", "/u/d");
  set("no_transmit", 1);
  set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"room22",
  "east" : __DIR__"room24",
]));

  setup();
}
