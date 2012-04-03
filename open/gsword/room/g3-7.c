// Room: /open/gsword/room/g3-7.c
inherit ROOM;

void create ()
{
  set ("short", "走廊");
  set ("long", @LONG
一条小走廊 ,连往仙剑派弟子们的寝居 ,在仙剑派中 ,除了掌门人及辈份
较高的仙剑七侠能拥有自己的寝居 ,其它弟子 ,只能一起睡通铺啰 !

LONG);

  set("exits", ([ /* sizeof() == 2 */
  "west" : "/open/gsword/room/g3-8.c",
  "east" : "/open/gsword/room/g3-6.c",
]));

  set("light_up", 1);

  setup();
}
