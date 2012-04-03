// Room: /open/poison/room/road17
inherit ROOM;

void create ()
{
  set ("short", "内庭");
  set ("long", @LONG
这里是一个小庭院，院内种了许多梅花，好像是一个小
梅园般，微风轻拂，眼前一幅落花缤飞的景像，让人很难想
像这会是人称「魔教”的总坛所在地。
LONG);

  set("exits", ([ /* sizeof() == 3 */
  "southeast" : __DIR__"road6",
  "west" : __DIR__"road16",
  "east" : __DIR__"room8",
]));
  set("outdoors", "/open/poison");

  setup();
}
