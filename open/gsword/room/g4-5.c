// Room: /open/gsword/room/g4-4.c
inherit ROOM;

void create ()
{
  set ("short", "钟楼顶楼");
  set ("long", @LONG
你上到了顶楼，一个青铜巨钟挂在正中央，左首一个大木桩，往西方
望去，仙剑尽收眼底，仙剑虽然仅数十年的历史，却已甚具规模，你看到
西北方的远处有个高塔，却是从未去过，不知是否隶属仙剑？
 
LONG);

  set("exits", ([ /* sizeof() == 1 */
  "down" : "/open/gsword/room/g4-4.c",
]));

  set("objects", ([ /* sizeof() == 1 */
   "/open/gsword/npc/trainee-2":1,
]));

  set("light_up", 1);

  setup();
}
