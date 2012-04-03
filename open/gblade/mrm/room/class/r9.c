// Room: /open/gsword/room/wghouse.c
inherit ROOM;

void create ()
{
set("short","魔龙塔");
  set ("long", @LONG

这里是魔龙塔最后的一层，一踏入这里，四周的空气好像沉重了起来，
耳中听不到一丝的声音，令你以为自己的双耳已失去作用了，你努力的
睁眼四顾，地上覆着一层薄薄的灰尘，显示这里少有人来。

LONG);
set("no_plan",1);
  set("exits", ([ /* sizeof() == 2 */
     "north" : __DIR__"r10.c",
]));
set("no_transmit",1);
  set("objects", ([ /* sizeof() == 1 */
"/open/gblade/npc/mou.c":1,
]));

  set("light_up", 1);

  setup();
}
int valid_leave(object me, string dir)
{
if( dir=="north" && present("degu mou",environment(me)))
   return notify_fail(" 邢涛说道 :这里是仙剑重地 ,你还是快离开吧!!!\n");
return ::valid_leave(me,dir);
}
