// Room: /u/s/sueplan/newplan/area/f9.c
inherit ROOM;

void create ()
{
  set ("short", "云山山腰");
  set ("long", @LONG
你随着盘峦山径登上云山，满眼挺拔苍松高耸入云，山风徐来松林低吟
，透着几分洒脱泰然；独立苍茫不觉有些凄怆，薄纱般雾气笼罩四周，酿成
了这挥之不去的沁骨凉意，几只苍鹰自远处呼啸而过的和流水的声音，前方
不远处仿佛有一个朦胧的不为人知的瀑布，不知前方是何等的景色，只让
人脚步加快，想要去窥探其景色。
LONG);

  set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"f10.c",
]));
  set("outdoors", "/u/s");

  setup();
}
