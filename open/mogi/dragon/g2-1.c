// Room: /u/p/poloer/dragon/g2-1
inherit ROOM;

void create ()
{
  set ("short", "魔王殿二楼");
  set ("long", @LONG

  　　　～ 一片暗暗的，伸手不见五指 ～　

LONG);

  set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"g2-2",
  "down" : __DIR__"g51",
]));
  set("evil", 1);
  set("no_auc", 1);
  set("no_transmit", 1);

  setup();
}
