#include <ansi.h>
inherit ROOM;
void create ()
{
  set ("short", "[31m[1m»ğÁú»Ã½ç[0m[1m--[36mÀ¶É«½á½ç[0m");
  set ("long", @LONG
À´µ½´ËµØ, ÄãÍùËÄÖÜÌ½ÁËÌ½, ÕâÀïµÄ»·¾³¸ú¸Õ²ÅÄã¿´µ½µÄµØ·½²»Ì«Ò»Ñù
. µØÉÏ»­ÁËĞí¶àÆæĞÎ¹Ö×´µÄÍ¼°¸, ¸üÆæÌØµÄÊÇ, ÉÏ·½¾¹ÓĞÒ»µÀÀ¶É«¹âÃ¢ÕÕÉä
×ÅÕâÀï, Äã²»½û¸Ğµ½¾ªÆæ, ÔÚÈç´ËµÄµØ·½¾¹ÓĞÀàËÆ¼«¹âµÄ¾°Ïó, ÕæÁîÄã´ó¿ª
ÑÛ½ç¡£
LONG);

  set("objects", ([ /* sizeof() == 1 */
  "/open/fire-hole/npc/dragon-b.c" : 1,
]));
  set("exits", ([ /* sizeof() == 5 */
  "northwest" : __DIR__"f-22.c",
  "southeast" : __DIR__"f-29.c",
  "northeast" : __DIR__"f-23.c",
  "west" : __DIR__"fire1.c",
  "southwest" : __DIR__"f-28.c",
]));
  set("outdoors", 1);

  setup();
}
