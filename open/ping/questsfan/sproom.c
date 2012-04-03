// Room: /u/d/dhk/questsfan/sproom
inherit ROOM;
#include <ansi.h>
void create ()
{
  set ("short", "[1;36m×ğ[2;37;0mÌì[1;33m¶´[2;37;0mÌì");
  set ("long", @LONG

  ¡® [1;33mÁ½ ÑÛ ¿´ ÊÀ ¼ä £¬ ÈË ĞÄ ËÆ ±ù º® £¬

     °× Íù ½ñ Éú Â· £¬ Íõ Õß ºŞ ÖĞ Ì¾ ¡£ [2;37;0m¡¯

ÍûÑÛËù¼°ÖÜÎ§Ö»ÓĞ¼òµ¥µÄÆğ¾ÓÓÃÆ·£¬¶øÓÚ´Ë¶´ÕıÖĞÑë
´¦ÓĞÒ»Î»[1;36mÆøÓîĞù°º[1;31m¡¢[1;36m·ç¶È³¬·²[2;37;0mµÄ[1;33mÊ¥Õß[2;37;0mÕıÔÚ´ò×øÎüÄÉÌì
µØÖ®Æø¡£
LONG);

  set("no_magic", 1);
  set("objects", ([ /* sizeof() == 2 */
  "/u/d/dhk/obj/good.c" : 1,
  __DIR__"npc/sky.c" : 1,
]));
  set("light_up", 1);
  set("no_fight", 1);

  setup();
}
