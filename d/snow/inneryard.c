// Room: /d/snow/inneryard.c

inherit ROOM;

void create ()
{
  set ("short", "[1;35m¹ıÈ¥Ê±¿Õ[0m Ìì¾®");
  set ("long", @LONG
ÕâÀïÊÇ´¾·çÎä¹İÖĞµÄÌì¾®£¬ÍùÎ÷×ß¿ÉÒÔ»Øµ½ÕıÌü£¬Íù±±±ßÊÇÊé·¿£¬
ÄÏ±ßÊÇÕĞ´ı¿ÍÈËµÄÏá·¿£¬Íù¶«Ò»Ìõ³¤ÀÈÍ¨ÍùÎä¹İÄÚÔº£¬Ìì¾®ÖĞÖÖÂúÁËĞí
¶àÆæ»¨Òì²İ£¬ÖĞÑëÁ¢×ÅÒ»¸ùÊ¯Öù(pillar)£¬ÉÏÃæËÆºõ¿Ì×Å×Ö¡£
LONG);

  set("item_desc", ([ /* sizeof() == 1 */
  "pillar" : "Ê¯ÖùÉÏ¿Ì×Å£º½£ÆøÖ¸Ìì¡¢½£ĞÄÄÚÁ²¡¢½£Ã¢²»ÏÔ¡¢½£ÉñÈçµç¡£
",
]));
  set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"schoolhall",
  "north" : __DIR__"nyard",
  "south" : __DIR__"guestroom",
  "east" : __DIR__"innerhall",
]));
  set("outdoors", "snow");

  setup();
}
