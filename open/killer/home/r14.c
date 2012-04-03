// Room: /open/killer/room/r14.c
inherit ROOM;

void create ()
{
  set ("short", "训练室");
  set ("long", @LONG
这里是要晋升成好的杀手的地方,有许多练习生会陪你们的。
在这个地方二级杀手们可以，好好的练习自己的匕首技。
有一对联：
      多多用匕首，技术可提升。
      太早用暗器，基础不稳固。
LONG);

  set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"r12.c",
    "up" : __DIR__"r14u.c",
]));
  set("objects", ([ /* sizeof() == 1 */
  "/open/killer/npc/train_b.c" : 3,
]));
  set("light_up", 10);

  setup();
}