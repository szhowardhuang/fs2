//written by acelan...../u/a/acelan/ghost/room/ghost7.c

inherit ROOM;

void create()
{
        set("short", "墓园小径");
        set("long", @LONG
这是一条在墓园中的小径, 四通八达, 可以通往各个坟墓, 小径
向北不断地延伸, 西边有一间土地公庙, 而东边有一座好大的坟墓,
不知道是什么人埋在里面。
LONG
        );
   set("exits", ([ /* sizeof() == 1 */
       "north" : __DIR__"ghost13.c",
       "south" : __DIR__"ghost4.c",
       "east"  : __DIR__"ghost8.c",
       "west"  : __DIR__"ghost6.c",
   ]));
   set("no_clean_up", 0);

   setup();
}
