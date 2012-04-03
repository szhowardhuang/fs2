// Room: /d/snow/sroad1.c

inherit ROOM;

void create ()
{
  set ("short", "[1;35m¹ıÈ¥Ê±¿Õ[0m Ñ©Í¤Õò½ÖµÀ");
  set ("long", @LONG
ÕâÀïÊÇÑ©Í¤ÕòµÄ½ÖµÀ£¬Íù±±ÊÇÒ»¸öÈÈÄÖµÄ¹ã³¡£¬ÄÏ±ßÊÇÌõĞ¡Â·Í¨Íù
Ò»×ùÁÖ×Ó£¬¶«±ßÔòÓĞÒ»ÌõĞ¡¾¶ÑØ×ÅÉ½ÑüÍ¨ÍùÉ½ÉÏ£¬ÍùÎ÷ÊÇÒ»Ìõ±È½ÏÕ­µÄ
½ÖµÀ£¬²Î²î²»ÆëµÄÍßÎİÖ®¼ä´«À´¼¸ÉùÈ®·Í¡£
LONG);

  set("exits", ([ /* sizeof() == 3 */
  "north" : __DIR__"square",
  "west" : __DIR__"sroad2",
  "east" : __DIR__"eroad1",
]));
  set("outdoors", "snow");

  setup();
}
