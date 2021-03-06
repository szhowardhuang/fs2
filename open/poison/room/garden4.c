// Room: /u/r/ranko/garden4.c
inherit ROOM;

void create ()
{
  set ("short", "毒园中央部份");
  set ("long", @LONG
这里是靠近毒园的中央部份,此处所种的毒花,毒草也较一般所
常见到的毒性要来的强.也因此寻常毒物亦不敢轻异接近此处,除了
具有较猛烈毒性的毒物外,这里已看不到其它的生物了。
LONG);

  set("exits", ([ /* sizeof() == 3 */
  "north" : __DIR__"garden2.c",
  "west" : __DIR__"garden4-1.c",
  "south" : __DIR__"garden4-3.c",
]));
  set("light_up", 1);
  set("objects", ([ /* sizeof() == 1 */
  "/obj/source/rose_flower.c" : 2,
]));

  setup();
}
