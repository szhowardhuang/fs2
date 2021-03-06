// Room: /open/capital/room/h04.c

inherit ROOM;

void create ()
{
  set ("short", "文来胡同");
  set ("long", @LONG
由于京城每三年会有一次状元的考试，会有许多的书生进京赶考，
而这里则是书生们时常聚集讨论、交换心得的地方，故称此胡同为文来
。街上铺的是美观的花岗石, 更显的出这条街的重要性。
    这儿来来往往的人潮, 都是来选购一些文房四宝--笔、墨、纸、砚
, 每件东西都算的上是精品。

LONG);

  set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"h01",
  "east" : __DIR__"r67",
]));
  set("outdoors", "/open/capital");

  setup();
}
