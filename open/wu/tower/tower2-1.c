// Room: /u/p/pokai/room/wu/tower2-1
inherit ROOM;

void create ()
{
  set ("short", "武威七杀塔二楼--");
  set ("long", @LONG
走到了这儿，发现地上的血渍不像方才那么多，但四周的杀气比方才更加的浓
烈，你发现地砖上印有几个深深的脚印，你可以想见到过这儿的武者个个都是身怀
绝技。墙上贴有一张告示(note)。
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"tower2-2",
  "down" : __DIR__"tower1-3",
]));
  set("light_up", 1);

  set("item_desc", ([ /* sizeof() == 1 */
  "note" : @LONG
    血腥的考验将要展开，你可以考虑在此回头，或是接受二到五层的考验。
LONG,
]));

  setup();
}

