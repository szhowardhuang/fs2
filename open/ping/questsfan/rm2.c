// Room: /u/d/dhk/questsfan/rm2
inherit ROOM;
#include <ansi.h>
void create ()
{
  set ("short", "É½ÁÖ[1;34mÆæ[0mÂ·");
  set ("long", @LONG
Ò»Ì¤ÈëáÔÉ½µÄÍÁµØ£¬¾Í¿ÉÒÔ¸Ğ¾õµ½·Ç³£ÊæÊÊ¡¢âùÈ»×ÔµÃ
µÄ¸Ğ¾õ£¬Ò»Â·ÉÏ±¡±¡µÄÇáÎí£¬ÍğÈô´ËµØÁéÆø³äÅæ¡¢Éú»úÎŞÏŞ
Ö®¸Ğ£¬ÁîÈË²»½û¸ĞÌ¾áÔÉ½Õæ²»À¢¹óÎªÎåÔÀÖªÊ×Ñ½¡£

LONG);

  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/man1.c" : 1,
]));
  set("exits", ([ /* sizeof() == 2 */
  "eastdown" : __DIR__"rm1",
  "eastup" : __DIR__"rm3",
]));
  set("outdoors", "/u/d");

  setup();
}
