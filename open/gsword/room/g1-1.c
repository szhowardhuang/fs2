// Room: /open/su/room/suroad9_1.c

inherit ROOM;

void create ()
{
  set ("short", "紫皇大殿");
  set ("long", @LONG
这是仙剑派的大殿，殿中数位剑士恭谨的站在两侧，看看这的陈设，
全以紫檀木造成，少了一种壮丽，确多一分莫名的英气。唯一令你不解是
大殿掌门人的位置上，却不见掌门人 ─ 郑士欣，坐在其上。看来想拜师
的话只好问问左右的剑士们了。
　
LONG);

  set("light_up",1);
  set("exits", ([ /* sizeof() == 3 */
  "north" : "/open/gsword/room/g1-3.c",
  "out" : "/open/gsword/room/test.c",
  "south": "/open/gsword/room/roomf",
  "east" : "/open/gsword/room/g1-2.c",
]));

  set("objects", ([ /* sizeof() == 2 */
  "/open/gsword/npc/swordsman" : 2,
  "/daemon/class/swordsman/chenfon" :1 ,
]));

   set("valid_startroom", 1);
    set("light_up", 1 );

  setup();
}
