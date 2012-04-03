#include <ansi.h>
inherit ROOM;
void create ()
{
  set ("short", "[31m[1m»ğÁú»Ã½ç[0m[1m--[35m×ÏÉ«½á½ç[0m");
  set ("long", @LONG
À´µ½´ËµØ, ÄãÍùËÄÖÜÌ½ÁËÌ½, ÕâÀïµÄ»·¾³¸ú¸Õ²ÅÄã¿´µ½µÄµØ·½²»Ì«Ò»Ñù
. µØÉÏ»­ÁËĞí¶àÆæĞÎ¹Ö×´µÄÍ¼°¸, ¸üÆæÌØµÄÊÇ, ÉÏ·½¾¹ÓĞÒ»µÀ°×É«¹âÃ¢ÕÕÉä
×ÅÕâÀï, Äã²»½û¸Ğµ½¾ªÆæ, ÔÚÈç´ËµÄµØ·½¾¹ÓĞÀàËÆ¼«¹âµÄ¾°Ïó, ÕæÁîÄã´ó¿ª
ÑÛ½ç¡£
LONG);

  set("outdoors", 1);
  set("exits", ([ /* sizeof() == 4 */
  "northwest" : __DIR__"f-31.c",
  "southeast" : __DIR__"f-45.c",
  "west" : __DIR__"f-36.c",
  "east" : __DIR__"f-38.c",
]));
  set("objects", ([ /* sizeof() == 1 */
  "/open/fire-hole/npc/dragon-p.c" : 1,
]));

  setup();
}
