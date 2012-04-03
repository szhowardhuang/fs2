// Room: /u/m/moner/room/r2.c 
inherit ROOM;
 
void create ()
{
  set ("short", "魔龙塔");
  set ("long", @LONG

这里是魔龙塔的第四层，一踏入这里，四周的杀气突然浓烈了起来，一
双双怖满杀气的眼睛正凝视着你。你定了定神后，注意到这个房间的四
周，地上满怖着刀痕，角落处推满一堆堆的骇骨，使你不寒儿凛。

LONG);

  set("exits", ([ /* sizeof() == 6 */
  "春" : __DIR__"r8.c",
"夏":__DIR__"r11.c",
  "冬" : __DIR__"r10.c",
  "秋" : __DIR__"r10.c",
]));
set("no_transmit",1);
set("objects",([
"/daemon/class/blademan/npc/corpse4.c":4,
]));
  setup();
  replace_program(ROOM);
}
