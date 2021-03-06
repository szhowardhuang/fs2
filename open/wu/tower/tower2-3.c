// Room: /u/p/pokai/room/wu/tower2-3
inherit ROOM;

void create()
{
  set ("short", "武威七杀塔二楼--");
  set ("long", @LONG
来到这儿，由于有小气窗的关系，你觉得有这间房间给人的感觉和刚刚完全
不同，这使你原本紧绷的心情也为之松弛。这里有个通往七杀塔三楼的的楼梯，
四周的墙壁上刻划了一些人物形图像(figure)，你想可能是闯关的武者们研究守
关守卫的一些记录。
LONG);

  set("light_up", 1);
  set("item_desc", ([ /* sizeof() == 1 */
  "figure" : @LONG

             O/     / /       O  _|         H
          -- |    0 --        l \ __     -- I --
            / \    |  \         I           Q     #@%$@%^$^&#.........

                                你看了看，笑了一下，觉得有些不以为然的感觉。                 
LONG,
]) );
  set("exits", ([ /* sizeof() == 2 */
  "climb" : __DIR__"tower3-1",
  "east" : __DIR__"tower2-2",
]));
  setup();
}
