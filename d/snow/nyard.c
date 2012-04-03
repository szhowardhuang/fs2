// Room: /d/snow/nyard.c

inherit ROOM;

void create ()
{
  set ("short", "[1;35m╧Щх╔й╠©у[0m йИ╥©");
  set ("long", @LONG
уБюОйгр╩╪ДуШюМ╣цоЮ╣╠╦и╬╩╣дйИ╥©ё╛╨Лд╬вюрниофлвею╤ЁЯ╫Мё╛от╣ц
й╝╥ж©╪╬©ё╛нВцФ╣да╒вер╩╦ЖйИ╪эё╛иоцФ╥евер╩ееее╣д╧ейИё╛мЫдовъЁЖ╥©
це©ирт©╢╣╫лЛ╬╝║ё
LONG);

  set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"inneryard",
]));
  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/girl" : 1,
]));

  setup();
}
