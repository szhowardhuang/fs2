#include <ansi.h>
inherit ROOM;
void create ()
{
  set ("short", "[0;1;31m¡õ[1m¡õ[1m¡õ[1ms[1m¡õ[1m¡õ[1m¡õ[1m¡õ[0m");
  set ("long", @LONG
»ğ¹âËÄÉä, ÁÒÑæÖ±³åÌì¶¥, Ê¹µÃÕâÀïµÄÆøºòÊ®·ÖÑ×ÈÈ, ËÄÖÜ¶¼ÊÇ»ğ¹â,
Õâ´ó¸ÅÊÇÍ³ÖÎ×ÅÕâÀïµÄ¹ÖÎïÒÔÎŞÇîµÄÁ¦Á¿ËùÔì³ÉµÄ»ğÖ®½á½ç, µ±ÄãÀ´µ½ÁËÕâ
Ê±, Í¬Ê±±»ËüµÄ»ğ¹âÃÔ»ó, ÕÒ²»µ½ÕıÈ·µÄ³öÂ·¡£
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "northwest" : __DIR__"f-17.c",
  "southeast" : __DIR__"f-25.c",
]));
  set("outdoors", 1);

  setup();
}
