//written by acelan...../u/a/acelan/ghost/room/ghost6.c

inherit ROOM;

void create()
{
        set("short", "土地公庙");
        set("long", @LONG
在杀手墓园里, 竟然还有这种东西, 可见杀手人杀多了, 心里还
是会不安的, 有土地公在这里镇镇鬼气, 大家胆子也大些, 只是不知
土地公真的能镇的住这些冤魂厉鬼吗。
LONG
        );
   set("exits", ([ /* sizeof() == 1 */
       "north" : __DIR__"ghost12.c",
       "south" : __DIR__"ghost3.c",
       "east"  : __DIR__"ghost7.c",
       "west"  : __DIR__"ghost5.c",
   ]));
set("objects", ([ /* sizeof() == 1 */
  "/open/killer/mon/ghost/npc/god.c" : 1,
  "/open/killer/mon/ghost/npc/black5.c" : 2,
]));


   setup();
}
