// Room: /d/snow/crossroad.c

inherit ROOM;

void create ()
{
  set ("short", "[1;35m¹ıÈ¥Ê±¿Õ[0m É½Ûê");
  set ("long", @LONG
ÕâÀïÊÇÒ»´¦É½Ûê£¬ÍùÄÏ¾ÍÊÇÑ©Í¤Õò£¬Ò»ÌõòêÑÑµÄĞ¡¾¶Íù¶«Í¨ÍùÁíÒ»
¸öÁÚ½üµÄĞ¡É½´å£¬Ò»¿é¹Ù¸®Á¢µÄ¸æÊ¾ÅÆÁ¢ÔÚÂ·ÅÔ£¬ÉÏÃæĞ´×ÅÓĞ¹ØÒ°ÑòÉ½
ÍÁ·Ë³öÃ»µÄ¾¯¸æ±êÖ¾¡£
LONG);

  set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"mstreet4",
]));
  set("outdoors", "snow");

  setup();
}
