// Room: /d/snow/mstreet2.c

inherit ROOM;

void create ()
{
  set ("short", "[1;35m¹ıÈ¥Ê±¿Õ[0m Ñ©Í¤Õò½ÖµÀ");
  set ("long", @LONG
ÄãÏÖÔÚÕı×ßÔÚÑ©Í¤ÕòµÄ´ó½Ö£¬ÍùÄÏÖ±×ß²»Ô¶´¦ÊÇÕòÉÏµÄ¹ã³¡£¬ÔÚÄã
µÄ¶«±ßÊÇÒ»¼ä´óÕ¬Ôº£¬²»¹ıÕıÃÅ²»ÔÚÕâ¸ö·½Ïò£¬ÍùÎ÷ÊÇÒ»¼Ò´òÌúÆÌ×Ó£¬
¶£¶£µ±µ±µÄÉùÒô´óÀÏÔ¶¿ÉÒÔÌıµÃµ½£¬½ÖµÀÍù±±±ßÒ»Ö±Í¨ÍùÕòÍâ¡£
LONG);

  set("objects", ([ /* sizeof() == 2 */
  __DIR__"npc/scavenger" : 1,
  __DIR__"npc/drunk" : 1,
]));
  set("outdoors", "snow");
  set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"smithy",
  "south" : __DIR__"mstreet1",
  "north" : __DIR__"mstreet3",
]));

  setup();
}
