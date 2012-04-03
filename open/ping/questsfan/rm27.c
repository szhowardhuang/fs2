// Room: /u/d/dhk/questsfan/rm27
inherit ROOM;
#include <ansi.h>
void create ()
{
  set ("short", "°Ù[1;32m²İ¹È[2;37;0m");
  set ("long", @LONG
¹ËÃûË¼Òå£¬¾ÍÊÇ³äÂú¸÷Ê½¸÷ÑùµÄÆæ»¨Òì²İµÄÉ½¹È¡£ÕâÀï¿ÉÒÔËµÊÇ
Õû×ùáÔÉ½ÊıÓĞÒ©ÓÃ¡¢ÁÆĞ§µÄÆæ»¨Òì²İ×î¾Û¼¯£¬Ò²ÊÇ×îÆëÈ«µÄµØ·½¡£¶ø
ÇÒ´«ÎÅÕâÀï×¡×ÅÒ»Î»ÓĞ×Å£¢¶¾ÉñÒ©Ê¥¡åÖ®³ÆµÄÇ°±²£¬Ò²ÒòÎªËûµÄ´æÔÚ
ÁîÕû×ù°Ù²İ¹È¸üÔöÌí²»ÉÙÉñÃØµÄÉ«²Ê¡£

LONG);

  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/oldman.c" : 1,
]));
  set("exits", ([ /* sizeof() == 1 */
  "eastup" : __DIR__"rm21",
]));
  set("outdoors", "/u/d");
  set("no_fight",1);

  setup();
}
