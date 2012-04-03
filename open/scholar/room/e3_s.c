// Room: /u/r/red/room/flower.c
inherit ROOM;

void create ()
{
  set ("short", "南厢房");
  set ("long", @LONG
这是学识厅的南厢房，你可以看到学识厅的长老正坐在那边
，看起来好像死了一般，真不知道他心理正在想些什么东西，令
人心中不寒而栗。
LONG);

  set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"e3.c",
]));
  set("objects", ([ /* sizeof() == 1 */
  "/open/scholar/npc/old_scholar.c" : 1,
]));

  setup();
}
