// Room: /d/snow/sroad3.c

inherit ROOM;

void create ()
{
  set ("short", "[1;35m¹ıÈ¥Ê±¿Õ[0m ÇàÊ¯¹ÙµÀ");
  set ("long", @LONG
ÕâÊÇÒ»Ìõ¿í³¨¼áÊµµÄÇàÊ¯°åÆÌ³ÉµÄ´óµÀ£¬Â·ÉÏ³µÂíµÄºÛ¼£ÒÑ¾­ÔÚÂ·
ÃæÉÏÁôÏÂÒ»ÌõÌõÃ÷ÏÔµÄ°¼ºÛ£¬Íù¶«ÊÇÒ»Ìõ½ÏĞ¡µÄ½ÖµÀÍ¨ÍùÑ©Í¤Õò£¬´óÂ·
´ÓÕâÀïÍù±±¿É´ïË®ÑÌ¸ó£¬ÍùÎ÷ÄÏ´©¹ı»ÆÊ¯°¯¿ÚÔòÍ¨ÍùÊùÊØ¾©çÜÖØµØµÄÌì
ÍÕ¹Ø¡£
LONG);

  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/crazy_dog" : 1,
]));
  set("outdoors", "snow");
  set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"sroad4",
  "east" : __DIR__"sroad2",
]));

  setup();
}
