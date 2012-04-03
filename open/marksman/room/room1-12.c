// Room: /u/f/fire/room/room1-12.c
inherit ROOM;
#include <ansi.h>
#include <marksman.h>
void create ()
{
  set ("short", "[1;31mÑî¼ÒÒ©µê[2;37;0m");
  set ("long", @LONG
Äã×ß½øÒ»¼ä³äÂú×ÅÒ©Î¶µÄ·¿×ÓÖĞ£¬ÕâÀïÊÇÒ»¼äÒ©ÆÌ¡£ÔÚÕâÀïÄã¿É
ÒÔÂòµ½¸÷Ê½¸÷ÑùµÄÒ©²Ä¡£ÔÚ·¿×ÓµÄËÄÖÜÊÇÒ»ÅÅµÄÄ¾¹ñ×Ó£¬ÔÚ¹ñ×ÓÉÏµ½
´¦Ğ´ÂúÁË¸÷Ê½µÄÒ©Æ·Ãû³Æ£¬ÁîÄã¿´ÁË¶¼¾õµÃÑÛ»¨ÁÊÂÒ¡£ÔÚ¹ñ×ÓÇ°Ãæ»¹
ÓĞÒ»Î»³¤Âú°×ºú×ÓµÄÀÏÈË²»¶ÏµÄ¿ªÆô²»Í¬µÄ³éÌëÄÃÈ¡Ò©²Ä¡£
LONG);

  set("objects", ([ /* sizeof() == 1 */
C_NPC"/yangming-teck" : 1,
]));
set("outdoors","/open");
  set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"room1-11",
]));

  setup();
}
