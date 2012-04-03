// Room: /u/o/ookami/newarea/aa6.c 
inherit ROOM;
 
void create ()
{
  set ("short", "中央走道");
  set ("long", @LONG
走进天龙寺的内部,放眼望去,四周有着装饰地美轮美奂的各式建筑
,简直不输给皇宫大内,不过这也难怪,段氏每年都会出资修筑,而经过这
些年的修建,天龙寺可说是全国数一数二的大寺院,只不过位在大理的山
上,又是段家先辈皈依之地,因此名号并不响亮
LONG);

  set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"aa5",
  "west" : __DIR__"aa7",
  "east" : __DIR__"aa8",
]));

set("objects", ([ /* sizeof() == 1 */
"/open/tailong/npc/monk2.c":1,
]));
  setup();
  replace_program(ROOM);
}
