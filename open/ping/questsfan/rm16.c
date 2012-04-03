// Room: /u/d/dhk/questsfan/rm15
inherit ROOM;
#include <ansi.h>
void create ()
{
  set ("short", "[0;37mÊ¯ÁÖ[0m");
  set ("long", @LONG
Õâ¶ùÊÇÒ»´¦´ç²İ²»Éú£¬¼áÊ¯ÁÖÁ¢µÄµØ·½¡£¶øÇÒÕâ¶ù¾»ÊÇÒ»Ğ©Ææ
ĞÎ¹Ö×´µÄ¾ŞÊ¯ËÄ´¦ÁÖÁ¢¡£µ«ÊÇÈ´ÓÖ²»ÊÇÈËÔì¶ø³ÉµÄ£¬ËùÒÔ´ËµØµÃÃû
£¢Ê¯ÁÖ¡åÒ²¡£ÔÚ×ĞÏ¸¿´¿´ÕâĞ©¾ŞÊ¯£¬ÓĞĞ©ÖÊµØËÉÉ¢¡¢ÓĞĞ©ÖÊµØ¼áÓ²
¸÷Ê½¸÷ÑùµÄÊ¯ĞÎ¶¼ÓĞ£¬ÓĞÒ»µãÏñÊ¯Í·´ó¹ÛÔ°Ò»°ã¡£

LONG);

  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/woman" : 2,
]));
  set("outdoors", "/u/d");
  set("exits", ([ /* sizeof() == 4 */
  "westup" : __DIR__"rm15",
  "eastup" : __DIR__"rm17",
  "eastdown" : __DIR__"rm9",
  "northup" : __DIR__"rm20",
]));

  setup();
}
