// Room: /u/d/dhk/questsfan/rm9
inherit ROOM;
#include <ansi.h>
void create ()
{
  set ("short", "[0;32mÔÆÎíËÉÁÖ[2;37;0m");
  set ("long", @LONG
ËÉÁÖ±ÎÈÕ¡¢ÔÆÎíÃÔÃÉ¡¢ËÉ¹ûÂúµØ£¬Õâ¶ù×îÆæ¹ÖµÄÊÇÒ»Æ¬´óËÉÁÖ
¾¹Ã»¿´µ½°ëÖê¾¥¸É£¬¸ñÍâÌØ±ğ¡£²»Ê±ÓĞ¼¸Ö»º±¼ûµÄÁùÎ²ËÉÊó¿ñ±¼¶ø
¹ı£¬²»È»¾ÍÊÇÀ¥³æµÄÃù½ĞÉù£¬ÌØ±ğµÄÊÇ ­ÃÇµÄÒ»ÆğÍ»È»µÄ´óÃù£¬È»
ºóÔÙÒ»ÆğµÄ°²¾²£¬ÄÇÒ»ÆğÍ»·¢µÄÃù½ĞÉùÕæÊÇÏàµ±ÁîÈËÕğº³µÄ¡£

LONG);

  set("exits", ([ /* sizeof() == 4 */
  "westup" : __DIR__"rm16",
  "southdown" : __DIR__"rm8",
  "northup" : __DIR__"rm17",
  "eastup" : __DIR__"rm10",
]));
  set("outdoors", "/u/d");

  setup();
}
