// Room: /u/d/dhk/questsfan/room24
inherit ROOM;
#include <ansi.h>
void create ()
{
  set ("short", "·½[0;37m¾§[0m²ã");
  set ("long", @LONG
ÕâÒ»ÇøµÄ½á¾§¾Í¹æÔò¶àÁË£¬È«ÊÇ³¤·½ĞÎÊ½µÄ½á¾§£¬
´ó´óĞ¡Ğ¡ËäÈ»²»Í¬¡£µ«ÊÇÈôÈ¡Ö®ÅÅÁĞÏë±ØÊÇÔìÊ¯Îİ (»¹
ÊÇ¸ß¼¶µÄÄÇÖÖ) µÄºÃ½¨²Ä°É£¡ËäÈ»´ËµØµÄ½á¾§ÒÀÈ»Ã»ÓĞ
Ñ¤ÀöµÄÑÕÉ«£¬µ«ÊÇËüÃÇ¾ßÓĞ·½Õı¡¢¾®È»ÓĞĞòµÄÆøÖÊ¡£Èô
Ó²ÒªĞÎÈİËü£¬ÄÇÎÒÖ»ÄÜÓÃ£¢ÑÅ¡åÕâÒ»¸ö×ÖÀ´ĞÎÈİ¡£

LONG);

  set("outdoors", "/u/d");
  set("no_transmit", 1);
  set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"room23",
  "north" : __DIR__"room25",
]));

  setup();
}
