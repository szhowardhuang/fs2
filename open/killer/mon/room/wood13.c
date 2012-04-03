//written by acelan...../u/a/acelan/room/wood13.c

inherit ROOM;

void create()
{
        set("short", "后山的森林");
        set("long", @LONG
来到这里, 已经到了森林的边缘, 无法在前进了, 你可以清楚的
看到地下有一个地道入口, 但却无法开启, 在一番努力之后, 你决定
放弃, 另寻出路。
LONG
        );
   set("exits", ([ /* sizeof() == 1 */
       "south" : "/open/killer/mon/room/wood7.c",
   ]));
   set("objects", ([ /* sizeof() == 1 */
       "/open/killer/mon/npc/grnnpc3.c":2,
   ]));
   set("no_clean_up", 0);

   setup();
}
