//written by acelan...../u/a/acelan/ghost/room/ghost39.c

inherit ROOM;

void create()
{
        set("short", "黑风组组长卫博战的闺房");
        set("long", @LONG
这里是黑风组组长卫博战的闺房, 房内摆设简单, 除了一张床及
圆桌外, 就只有墙上供俸着的神明了, 香火尚未燃尽, 看来黑风组组
长卫博战似乎做过了不少的亏心事, 以至现在必须常常烧香拜佛。
LONG
        );
   set("exits", ([ /* sizeof() == 1 */
       "south" : __DIR__"ghost37.c",
   ]));
   set("no_clean_up", 0);
 set("objects", ([ /* sizeof() == 1 */
  "/open/killer/mon/ghost/npc/chen.c" : 1,
]));

   setup();
}
