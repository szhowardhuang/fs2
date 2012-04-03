// /u/j/judd/room/r19.c
inherit ROOM;

void create ()
{
  set ("short", "中堂西侧");
  set ("long", @LONG
有一条蓝色的道路延伸往西南方，想必就是通往儒门的四大图书
馆之一，水室图书馆，光从名称，是不会知道水室图书馆是放些什么
书的，只有亲自去看过，才能知道儒门四大图书馆到底是放些什么，
东边则通往出口方向。
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"r16.c",
  "southwest" : __DIR__"r23.c",
]));
  set("light_up", 1);

  setup();
}
