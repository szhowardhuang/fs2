inherit ROOM;
void create()
{
   set ("short","小道");
  set ("long",@LONG
这里是一片空地 .唯一令人注目的事物也只有中央的水井罢了 .
LONG);

  set("outdoors","/open/badman");
  set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"wolf12.c",
]));

  set("objects", ([ /* sizeof() == 1 */
  "/open/badman/obj/well.c" : 1,
]));
  set ("资源/液体", ([
       "种类" : "水",
       "名称" : "清水",
       "止渴" : 30
  ]) );

  setup();
}
