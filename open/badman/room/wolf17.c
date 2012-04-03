inherit ROOM;
void create()
{
  set ("short","狼谷");
  set ("long", @LONG
这里是狼谷谷壁突出的一块小平台。往下看去，还可模糊地看见刚
刚所待的破庙及村庄的影子。但你心中很清楚一件事，摔下去绝对没有
啥好下场。把你拉上来的人的武功一定非常厉害。谷壁有一条从上方悬
下来的藤蔓。
LONG);

  set("outdoors", "/open/badman");
  set("exits", ([ /* sizeof() == 1 */
  "up" :__DIR__"wolf06.c",
]));
  set("objects", ([ /* sizeof() == 2 */
  "/open/badman/npc/young.c" : 1,
]));

  setup();
}
