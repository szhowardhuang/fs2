// Room: /d/snow/eroad1.c

inherit ROOM;

void create ()
{
  set ("short", "[1;35m¹ıÈ¥Ê±¿Õ[0m »ÆÍÁĞ¡¾¶");
  set ("long", @LONG
ÕâÊÇÒ»ÌõÆÕÍ¨µÄ»ÆÍÁĞ¡¾¶£¬ÍäÍäÇúÇúÍù¶«±±Ò»Â·ÅÌĞıÉÏÉ½£¬±±±ßÓĞ
Ò»¼ä³ÇÚòÃí£¬ÍùÎ÷ÔòÊÇÑ©Í¤ÕòµÄ½ÖµÀ¡£
LONG);

  set("exits", ([ /* sizeof() == 3 */
  "northeast" : __DIR__"eroad2",
  "west" : __DIR__"sroad1",
  "north" : __DIR__"temple",
]));
  set("outdoors", "snow");

  setup();
}
