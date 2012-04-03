inherit ROOM;
void create ()
{
  set ("short", "密室");
  set ("long", @LONG
这是一间极为隐密的房间, 每当段家的弟子修行遇到瓶颈,
便会来这里闭关, 有时一来就是好几年, 这里的陈设极为简陋,
但是冬暖夏凉,非常适合在这里练功.

LONG);

  set("exits", ([ /* sizeof() == 1 */
  "out" : __DIR__"road3",
]));
  set("no_fight", 1);
  set("light_up", 10);
  set("valid_startroom", 1);

  setup();
  replace_program(ROOM);
}
