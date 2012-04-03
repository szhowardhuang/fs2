// Room: /u/f/fire/room/room1-1.c
#include <ansi.h>
#include <marksman.h>
inherit ROOM;

void create ()
{
  set ("short", "[32m³¤É³³Ç[2;37;0m");
  set ("long", @LONG
³¤É³³ÇÄËÀî¹ã´óÈËËùÉú³¤µÄµØ·½£¬ÄÇÀïÈËÈËÊÜ»İÎŞÇî£¬¸»¼×Ò»·½
¡£ÔÚ³¤É³³ÇµÄ¾ÓÃñ×¡×Å°²¾ÓÀÖÒµ£¬Æ½Æ½°²°²µÄ³ÇÕò£¬³äÂúÁËÒ»¹É°²Äş
ºÍĞ³µÄÆøÏó¡£Äã¿´µ½Ò»ÈºÈ«¸±Îä×°µÄÊØÎÀÕıÔÚ¹ËÊØ×Ô¼ºµÄ¸ÔÎ»ÉÏÊØ»¤
×ÅÒÔ·ÀÍâÈË¹¥»÷¡£
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"room2-5",
  "north" : __DIR__"room1-2.c",
]));
set("outdoors","/open/marksman");

  setup();
}
