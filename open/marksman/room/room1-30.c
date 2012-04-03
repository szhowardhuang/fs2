// Room: /u/f/fire/room/room1-30.c
inherit ROOM;
#include <ansi.h>
#include <marksman.h>
void create ()
{
  set ("short", "[1;33mÇ¿ÕßÖ®µÀ[2;37;0m");
  set ("long", @LONG
ÑÛÇ°Ò»Æ¬Ò«ÑÛµÄÉÁ¹âÏ®À´£¬ÄãÃãÇ¿Õö¿ªÑÛ¾¦Ò»¿´£¬ÑÛÇ°ËÊÁ¢×ÅÒ»
×ùÏâÂú±¦Ê¯£¬Á÷Â¶Ğí¶àÆß²ÊÏÊÑŞµÄ¹âÃ¢¡£ÕâÀïÆ®×Åµ­µ­µÄ»¨Ïã£¬Äã²»
½û´ó´óµÄÎüÁË¿ÚÆø£¬Í»È»Æ®À´ÁË¸÷ÖÖ»¨µÄÏãÎ¶£¬ÓĞÇåÏãµÄ¹ğ»¨Î¶£¬ÈÃ
ÈËÉñÇåÆøË¬¡£
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"room1-28.c",
  "east" : __DIR__"room1-31",
]));
  set("objects", ([ /* sizeof() == 1 */
C_NPC"/chang-yang.c" : 1,
]));

set("light_up",1);
  setup();
}
