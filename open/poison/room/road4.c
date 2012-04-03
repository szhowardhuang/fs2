// Room: /open/main/room/f10.c

inherit ROOM;

void create ()
{
  set ("short", "林中小径");
  set ("long", @LONG
你身在一片原始森林里，两旁尽是高大的林木，微风吹
拂着你的身体，让你感到非常清凉，暑气尽消，地上则潮湿
泥泞，在此你听到西边传来隆隆的水声，看着你沾满泥巴的
鞋子，心想或许可以到那里清洗一番。
LONG);

 
 
 
  set("outdoors", "/open/main");
  set("exits", ([ /* sizeof() == 3 */
  "northeast" : __DIR__"road3",
  "south" : __DIR__"room14",
  "west" : __DIR__"road5",
]));

  setup();
}
