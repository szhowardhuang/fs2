// Room: /d/snow/smithy.c

inherit ROOM;

void create ()
{
  set ("short", "[1;35m¹ıÈ¥Ê±¿Õ[0m ´òÌúÆÌ×Ó");
  set ("long", @LONG
ÕâÀïÊÇÒ»¼ä´òÌúÆÌ×Ó£¬´Ó»ğÂ¯ÖĞÃ°³öµÄ»ğ¹â½«Ç½±ÚÓ³µÃÍ¨ºì£¬Îİ×Ó
µÄ½ÇÂäÀï¶ÑÂúÁË¸÷Ê½ÌúÆ÷µÄÍê³ÉÆ·»òÎ´Íê³ÉÆ·£¬ÏñÊÇ³úÍ·¡¢Ìú´¸¡¢²ù×Ó
µÈ£¬¶£¶£µ±µ±µÄÉùÒôÇÃµÃÂúÎİ×ÓÏì¡£
LONG);

  set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"mstreet2",
]));
  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/smith" : 1,
]));

  setup();
}
