// Room: /u/m/moner/tree/room26.c
inherit ROOM;

void create()
{
  set ("short", "密室");
  set ("long", @LONG

这是一间狭窄的密室，室内仅有一个石床依偎在墙旁。石室的天顶上
有一个破洞，刺目的阳光从上方倾而入，映着光线，你慢慢的看清四周，
环顾四周，你惊讶的发现室内满怖刀痕，细细的观察那些刀痕，看起来好
像是高手所为。

LONG);

  set("light_up", 1);
        set("objects",([
"/daemon/class/blademan/master_oldman.c":1,
]));

  set("exits", ([ /* sizeof() == 2 */
"out" :"/open/snow/room/hole13.c",
]));
  setup();
}
