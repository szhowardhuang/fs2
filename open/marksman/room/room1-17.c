// Room: /u/f/fire/room/room1-17.c
inherit ROOM;
#include <ansi.h>
#include <marksman.h>
void create ()
{
  set ("short", "[1;37mÌìÁú¿ÍÕ»[2;37;0m");
  set ("long", @LONG
ÄãÕıÕ¾ÔÚÌìÁú¿ÍÕ»Ö®ÖĞ£¬ËäËµÕâÀïÊÇ³ÇÄÚ×î´óµÄ¿ÍÕ»£¬ÕâÀïËÆºõ
ÊÇÎäÁÖÈËÊ¿ËùĞİÏ¢µÄµØ·½¡£ÀïÃæÖ»°ÚÊÎ×ÅÒ»Ğ©¼òµ¥µÄ¼Ò¾ã£¬¿´µ½¿ÍÕ»
ÀïÃæµÄĞ¡¶şÕıÔÚÃ¦µÄ²»¿É¿ª½»¡£
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"room1-16",
  "up" : __DIR__"room1-18.c",
]));
  set("objects", ([ /* sizeof() == 1 */
C_NPC"/cheng-chong" : 1,
]));

  setup();
}
