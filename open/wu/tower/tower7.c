// Room: /u/p/pokai/room/wu/tower7
inherit ROOM;

void create()
{
  set ("short", "武威七杀塔七楼--");
  set ("long", @LONG
这里是武威七杀塔的最顶层，站在这里，你有一种说不出的成就感，一旁的小窗
子(window)还不断吹进微风；你忽然发现墙角阴暗处站着一个身形瘦小的人，你猜想
他大概就是这间房间的主人，或者是这个塔的主人！？
LONG);

  set("item_desc", ([ /* sizeof() == 1 */
  "window" : "    一个木框小窗，你由窗口往外看去，发现外下头正对一个水池，你不
禁突发奇想，想由这儿跳下去（jump）是不是比较快下到一楼！？
",
]));
  set("light_up", 1);
  set("exits", ([ /* sizeof() == 1 */
  "down" : __DIR__"tower6",
]));
  setup();
}
