// Room: /open/death/room/h1-5
inherit ROOM;

void create ()
{
  set ("short", "第一殿--补经所");
  set ("long", @LONG
你站在这里，放眼望去，看到满屋子都是和尚和道士，每个人都低
着头，满头大汗的抄写着经文，只见墙上写着：‘生前僧道传道时故意
混水摸鱼错漏经文者，死后到此处抄写经文，补回生前错漏者，再发送
地狱受罪。’
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"h1-6",
  "south" : __DIR__"h1-9",
]));
  set("light_up", 1);

  setup();
}
