// Room: /u/s/smore/room/suking/suking7.c

inherit ROOM;

void create ()
{
  set ("short", "右侍卫房");
  set ("long", @LONG
走到这里，你发现数名身材高大壮硕的侍卫正忠心耿耿的守
卫着将军席，虽然将军本身武功高强，但是昔日在战场上所树立
的敌人数目太多，甚至会有敌国派来的杀手，所以将军府还是有
从军队中精心挑选出来的人组成侍卫班，守护着将军府
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "south" : "/open/gsword/room/suking2",
  "west" : "/open/gsword/room/suking6",
]));
  set("objects", ([ /* sizeof() == 1 */
  "/open/gsword/mob/r_guard" : 1,
]));
  set("light_up", 1);

  setup();
}
