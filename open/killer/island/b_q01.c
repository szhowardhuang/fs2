#include <ansi.h>
inherit ROOM;
void create ()
{
  set ("short", "[1;37m╥©╪Д[0m");
  set ("long", @LONG
тзр╩уС╣д╢МЦ╣ж╝обё╛дЦ╡╩п║пдл╓ффак╣в╟Её╛╣ЬЁЖакуБкр╢╛ж╝мБё╛╫Т╫свесжсппМ
╤Ю╣д╡п╨║╦Зве╣Такобю╢ё╛║╝еЖ║╞╣др╩иЫё╛дЦ╣дм╥ио╠╩дЁжж╫ПйТжьнО╢Р╣╫ё╛©╢ю╢уБкр
╢╛уФ╣д╡Н╡╩╤Ю©ЛкЗ╣Так║ё
LONG);

  set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"is15",
]));
  set("objects", ([ /* sizeof() == 1 */
  __DIR__"obj/box" : 1,
]));
  set("outdoors", 1);

  setup();
}
