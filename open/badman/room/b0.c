// Room: /open/badman/room/e1.c

inherit ROOM;

void create ()
{
  set ("short", "恶人谷入口");
  set ("long", @LONG
这里就是传说中恶人谷的入口，据说在谷中之人没有一个不是
十恶不赦，满手血腥，没有一个不被江湖中人恨之入骨。但也正因
为聚集在此的都是江湖中的极恶之徒，别人纵然恨不得吃他们的肉
，却也没有人敢走近恶人谷一步。
    在凄迷的云雾中，一盏青灯制成的孔明灯正巧妙的嵌在山石间
的避风处，看来有如鬼火一般。在灯火的照耀下，山石上似乎刻着
两行字(words)。

LONG);

  set("item_desc", ([ /* sizeof() == 1 */
  "words" : "
	入谷如登天，
	来人走这边。
",
]));
  set("objects", ([ /* sizeof() == 1 */
  "/open/badman/npc/yen" : 1,
]));
  set("outdoors", "/open/badman");
  set("exits", ([ /* sizeof() == 2 */
  "leave" : "/open/badman/room/t6",
  "west" : "/open/badman/room/b1",
]));

  setup();
}

int valid_leave(object who, string dir)
{
  if( present("sma yen", this_object()) ) {
  if( dir=="west" && !present("badman license", who) ) {
    switch(random(4)) {
      case 0:
        return notify_fail("司马烟冷冷的对你笑道: 朋友，恶人谷不是你想来就来的地方，请留步。\n");
        break;
      case 1:
        return notify_fail("司马烟拿起手中的剑挡在你面前说道: 想入谷？先问问看我手中的穿肠剑答不答应！\n");
        break;
      default:
        return notify_fail("司马烟对你摇了摇头道: 谷主有令，无恶人证者不得擅入恶人谷，违者格杀勿论！\n");
    }
  }

  if( dir=="west" && present("badman license", who) )
    message_vision("司马烟看了看$N的恶人证说道: "+who->query("name")+"，你可以过去了。\n\n", who);
  }

  return ::valid_leave(who, dir);
}
