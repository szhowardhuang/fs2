// Room: /u/f/fire/room/room1-27.c
inherit ROOM;
#include <ansi.h>
#include <marksman.h>
void create ()
{
  set ("short", "[1;33mÇ¿ÕßÖ®µÀ[2;37;0m");
  set ("long", @LONG
ÕâÀïµÄËÄÖÜµÄÇ½ÉÏÕÅÌù×ÅÊı°Ù·ù»­Ïñ£¬ÓĞºÜ´óµÄÓĞºÜĞ¡µÄ£¬È«²¿
¶¼ÊÇ¶àÄêÇ°Ó¢ĞÛÍ¼Ïñ¡£´ÓÌì»¨°å´¹ÏÂÀ´µÄÖÓ°Ú£¬²»Ê±Ò¡°Ú×Å·¢³öµÎ´ğ
µÎ´ğµÄÉùÒô£¬ÔÚÉúÃüÖ®ÈªµÄÁíÒ»±ßÓù·¿Ò²ÊÇÓĞ¹ÒÒ»¸ö¡£
LONG);

  set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"room1-25.c",
  "west" : __DIR__"room1-24",
  "north" : __DIR__"room1-29.c",
]));
  set("objects", ([ /* sizeof() == 1 */
C_NPC"/bowman1.c" : 2,
]));

  setup();
}
