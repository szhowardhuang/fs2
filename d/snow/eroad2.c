// Room: /d/snow/eroad2.c

inherit ROOM;

void create ()
{
  set ("short", "[1;35m¹ıÈ¥Ê±¿Õ[0m »ÆÍÁĞ¡¾¶");
  set ("long", @LONG
ÕâÊÇÒ»ÌõÆÕÍ¨µÄ»ÆÍÁĞ¡¾¶£¬Ğ¡¾¶ÍùÎ÷ÄÏÍ¨ÍùÒ»´¦É½¼äµÄÆ½µØ£¬´ÓÕâ
Àï¿ÉÒÔÍû¼û²»ÉÙ·¿Îİ´íÂäÔÚÆ½µØÉÏ£¬Íù¶«±±ÔòÒ»Â·ÉÏÉ½¡£
LONG);

  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/dog" : 2,
]));
  set("outdoors", "snow");
  set("exits", ([ /* sizeof() == 2 */
  "northeast" : __DIR__"eroad3",
  "southwest" : __DIR__"eroad1",
]));

  setup();
}
