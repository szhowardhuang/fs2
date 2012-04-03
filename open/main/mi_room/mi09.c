inherit ROOM;
#include <ansi.h>

void create ()
{
  set ("short", "[5m[1;37m¿ñ·çÆßĞÇÕóÕóĞÄ[2;37;0m");
  set ("long", @LONG

    Äã×ß½øÕâÀï, Í»È»Ò»Õó¿ñ·ç´µÆğ, À¨ÆğÂşÌì·çÉ³, ÄãÖÃ
ÉíÔÚÕâ¼²·çµ±ÖĞ, ¶Ù¸ĞÒ»ÕóÔÎìÅ, ÑÛÇ°Ò»Æ¬Ä£ºı, ¿´²»Çå³ö
ËÄÖÜµÄÊÂÎï¡£

LONG);

  set("exits", ([ /* sizeof() == 1 */
  "leave" : "/open/main/room/maiu-1.c",
]));
  set("light_up", 1);
  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/m-ya" : 1,
]));
  set("no_transmit", 1);

  setup();
  replace_program(ROOM);
}
