inherit ROOM;
void create ()
{
  set ("short", "银针门库房");
  set ("long", @LONG

　　这里是银针门的库房，此地是专门用来放置一些还未用到的杂物
及药品的地方，这里有许多的药柜及药罐，诸如：天山雪莲、千年灵
芝及野山人参....等，都是极奇珍贵的稀有药材！

LONG);

  set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"3",     
]));

  set("objects", ([ /* sizeof() == 1 */
  "/open/doctor/npc/lan.c" : 1,
]));

  set("light_up", 1);
  setup();
}


