#include <ansi.h>
inherit ROOM;
void create ()
{
  set ("short", "[1;37m´¬²Õ[2;37;0m");
  set ("long", @LONG
³ıÁËÄ¾ÖÆµÄµØ°åÉÏÓÉÓÚÊÜ²»ÁËÄãµÄÖØÁ¿¶ø¶à³öÁËÁ½¸öÆÆ¶´Ö®Íâ£¬ÕâÀïËÆºõÊ²Ã´
¶«Î÷Ò²Ã»ÓĞ£¬»òĞíÄãÓ¦¸ÃÍùÄÏ±ßÇ°½ø°É¡£
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "out" : __DIR__"is15",
  "south" : __DIR__"b_r01",
]));

  setup();
}
