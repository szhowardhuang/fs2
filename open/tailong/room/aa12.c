inherit ROOM;

void create ()
{
  set ("short", "走道");
  set ("long", @LONG
往这里走来也有一段时间了,在路旁的石椅正好可以让你休息一下好
好看看这里的景色,四周扶疏的树木,旁边的小池塘,远处的华丽楼阁,都让
你觉得好像身处在大户人家的庭园中,而不是在寺庙中, 然而在不远处矗
立的高塔更引起你一探究竟的好奇心
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"aa10",
  "east" : __DIR__"aa14",
]));

  setup();
  replace_program(ROOM);
}
