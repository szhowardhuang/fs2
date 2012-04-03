inherit ROOM;
#include <ansi.h>

void create ()
{
  set ("short", "¸ôÊÀÇÅ");
  set ("long", @LONG
×ßÉÏÇÅÃæ£¬Õâ×ùÇÅËÆºõÒÑÓĞÉÏ°ÙÄêµÄÀúÊ·£¬ËêÔÂµÄºÛ¼££¬Ò»µ¶µ¶
µÄ¿Ì»­ÔÚÕâ×ùÇÅÉÏ£¬ºÓÃæµÄÇå·çÎ¢Î¢µÄ´µÁË¹ıÀ´£¬ÖÃÉí´ËÇÅÓĞÖÖÈç¸ô
ÊÀ°ãµÄ¸Ğ¾õ£¬ÇÅÍ·ÉÏÓĞÒ»¿éÊ¯±® (stone)£¬ÉÏÃæËÆºõÌâÁËËÄ¸ö´ó×Ö£¬
Äã¿ÉÒÔ×ß½üÒ»¿´¡£
LONG);

  set("item_desc", ([ /* sizeof() == 1 */
  "stone" : "
¨t¨T¨p¨T¨T¨T¨p¨T¨s  ¨U    ¨U  ¨U        ¨q¨T¨s  ¨U      ¨U   ¨T¨j¨m¨j¨T
  ¨q¨T¨j¨T¨j¨T¨r  ¨t¨m¨[¨T¨m¨T¨t¨T¨s¨q¨T¨s  ¨r  ¨U  ¨q  ¨U   ¨T¨m¨T¨m¨T
¨q¨m¨j¨m¨T¨m¨T¨m¨r  ¨q¨s¨U¨T¨r¨T¨T¨[¨U  ¨U  ¨U  ¨U  ¨U¨T¨p¨T ¨d¨T¨T¨T¨g
¨U¨q¨s¨j¨T¨T¨T¨r¨U¡¡¨t¨[¨U  ¨U¨T¨p¨T    ¨U  ¨U  ¨U  ¨U  ¨U   ¨t¨j¨T¨j¨s
      ¨t¨r¨q¨T¨s  ¨X¨j¨s¨s  ¨s  ¨s      ¨U  ¨U  ¨U  ¨U¨T¨m¨T ¨q¨s  ¨U
      ¨q¨T¨s        ¨t¨T¨T¨T¨T¨T¨T¨s    ¨s  ¨t¨T¨m¨T¨s       ¨s    ¨t¨T

[0m",
]));
  set("objects", ([ /* sizeof() == 1 */
  __DIR__"obj/bembem.c" : 1,
]));
  set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"mon07",
  "south" : __DIR__"mon05",
]));

  setup();
}
