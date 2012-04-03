// Room: /open/badman/room/wizroom
inherit ROOM;

void create ()
{
  set ("short", "恶人谷幕后黑手专用刑求室");
  set ("long", @LONG
你一进门就看到墙上挂着一幅巨大的对联，上联写着‘有话快
说’，下联则是‘有屁快放’，上头还有一个大大的横批‘无事退
朝’。看着看着你忽然发现墙角边有一行小字(word)....

LONG);

  set("item_desc", ([ /* sizeof() == 1 */
  "word" : "无聊透顶....oda 到此一游x...游 :b
世事无常... powell :P
我也要来留个言... Sincerely yous, Caesar ... :P
",
]));
  set("exits", ([ /* sizeof() == 2 */
  "down" : __DIR__"g1",
]));
  set("light_up", 1);
  set("no_fight", 1);
  set("no_magic", 1);

  setup();
  call_other("/obj/board/badwiz_b", "???");
}
