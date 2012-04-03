// Room: /u/s/sueplan/newplan/area/f7.c
inherit ROOM;

void create ()
{
  set ("short", "树道");
  set ("long", @LONG
你步行于此，道路两旁青翠树木排列整齐，列行相对，频频映青，形成
浓浓的树荫，当微风轻佛而过，在炎炎夏日当中带了几分的凉爽，消除了夏
日所带了的暑气，当为秋天之时，道路两旁数目爰首穑，落叶缤纷之际，颇
有萧然虚清之美，此处往南行走，可到达名山云山。
LONG);

  set("outdoors", "/u/s");
  set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"f8.c",
  "west" : __DIR__"f6",
]));

  setup();
}
