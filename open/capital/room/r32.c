// Room: /open/capital/room/r32.c

inherit ROOM;

void create ()
{
  set ("short", "永安胡同");
  set ("long", @LONG
这儿是‘南市’的中心。和其它市集相比，这儿算小多了，只有间
小茶馆，路边几担卖青菜水果的，几担小面摊子，一些卖姑娘家用的脂
粉的小贩，不过还是人挤人，水泄不通。
    这里有禁卫军四处的巡逻着，所以你还是不要在城内惹事的好。

LONG);

  set("outdoors", "/open/capital");

  set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"r31",
  "east" : __DIR__"r33",
]));

  set("gopath", "west");
  set("gopath2", "west");

  setup();
}
