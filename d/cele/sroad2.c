inherit ROOM;

void create ()
{
  set ("short", "[1;35m¹ıÈ¥Ê±¿Õ[0m ÇàÊ¯¹ÙµÀ");
  set ("long", @LONG
    ÕâÊÇÒ»Ìõ¿í³¨¼áÊµµÄÇàÊ¯°å´óµÀ£¬´ÓÕâÀïÑØ×ÅÉ½ÊÆÍäÏòÎ÷±ß
£¬ÍùÎ÷²»Ô¶´¦¾ÍÊÇÍ¨ÍùË®ÑÌ¸óµÄÊ¯½×¡£

LONG);
  set("outdoors", "cele");
  set("exits", ([ /* sizeof() == 1 */
  "south" : "/d/cele/sroad1",
  "west"  : "/d/cele/sroad3",
]));

  setup();
}
