// Room: /d/snow/hockshop.c

#include <room.h>

inherit HOCKSHOP;

void create ()
{
  set ("short", "[1;35m╧Щх╔й╠©у[0m ╥А╣г╣╠фл");
  set ("long", @LONG
уБйгр╩╪ржп╣х╧Фдё╣д╣╠флё╛юо╬и╣д╧Ял╗ио╥евер╩уед╬еф(sign)ё╛нщ
юО╣д╧Боъ╡╩йг╨эааё╛мЫ╤╚╣дЁЖ©з╠╩р╩©Ию╤и╚╡╪а╠узвеё╛иоцФсп║╦╥ггКд╙
хК║╠╣двжяЫё╛нВ╠ъспр╩ихд╬╣Яце(door)м╗мЫ╢С╫ж║ё
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"mstreet3",
  "east" : __DIR__"hockshop2",
]));
  set("item_desc", ([ /* sizeof() == 2 */
  "west" : (: look_door,     "west" :),
  "sign" : "╠╬╣╠фл╡фа╕пш╨Яё╛м╞шенчфшё╛╩╤с╜╩щ╧кё╛╬Ь╤т╠ёцэ║ё
©мыд©ирттзуБюО╣Д╣╠(pawn)║╒бТ╤о(sell)╦Вжж╩УнОё╛м╜г╝║╒рЬа╫║╒╩ф╫П║╒рЬф╠
р╩╦ем╗сц║ё
",
]));

  setup();
}
