// Room: /open/capital/room/tower
inherit ROOM;

void create ()
{
  set ("short", "高台");
  set ("long", @LONG
一登上高台, 你才发现上面非常的宽阔, 地面上的石板成放射状排
列, 有如十二道光芒从中央的祭台发射出去。因为这儿是整个京城最高
的地方, 因此你可以毫无困难的俯视整个京城, 到处人车往来, 十分繁
忙, 京城外是一遍青青草原, 微风吹来, 便似一道道的波浪袭来, 景观
壮丽。

LONG);

  set("light_up", 1);
  set("capital_thief", 1);
  set("outdoors", "/open/capital");
  set("exits", ([ /* sizeof() == 2 */
  "northdown" : __DIR__"r08",
  "southdown" : __DIR__"r59",
]));

  setup();
}
