// Room: /u/j/judd/room/r24.c
inherit ROOM;

void create ()
{
  set ("short", "»Â√≈»Îø⁄");
  set ("long", @LONG
     **  ***********      ********  ********
        **        *           *      *  *      *
       **    ***********      *      *  *      *
      ****   * ** * ** *      ********  ********
     ** **   * ** * ** *      *      *  *      *
        **   * ** * ** *      *      *  *      *
        **                    ********  ********
        **   ***********      *                *
        **       *            *                *
        **   ***********      *                *
        **   * **   ** *      *                *
        **   * **   ** *      *                *
        **   * **   ** *      *                *
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"area.c",
  "out" : __DIR__"enter.c",
]));
  set("light_up", 1);
  set("objects", ([ /* sizeof() == 1 */
  "/open/scholar/npc/door_scholar.c" : 2,
]));

  setup();
}
