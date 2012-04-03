
inherit ROOM;
void create()
{
  set ("short", "哨站");
  set ("long","
    这一个哨站几乎是反乱军中最重要的，因为这里是所
有人必经之路，这里的哨兵当然不是省油的灯，四个方向
都可以走，自己挑一条吧。

 ");
   set("exits", ([
   "southeast"   : __DIR__"r13.c",
   "southwest"   : __DIR__"r14.c",
   "northwest"   : __DIR__"r6.c",
   "northeast"   : __DIR__"r5.c",
  ]));      
  set("objects", ([ /* sizeof() == 2 */
    "/open/soldier/npc/sentry1":2,
]));
  set("light_up", 1);
  setup();
} 
