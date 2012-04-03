// Room: /d/snow/school.c

inherit ROOM;

void create ()
{
  set ("short", "[1;35m¹ıÈ¥Ê±¿Õ[0m ÊéÔº");
  set ("long", @LONG
ÕâÀïÊÇÒ»¼ä¿í³¨µÄÊéÔº£¬ËäÈ»·¿×Ó¿´ÆğÀ´ºÜÀÏ¾ÉÁË£¬µ«ÊÇ´òÉ¨µÃºÜ
Õû½à£¬Ç½±ÚÉÏ¹Ò×ÅÒ»·ùÉ½Ë®»­£¬Òâ¾³ÆÄÎª²»Ë×£¬ÊéÔºµÄ´óÃÅ¿ªÔÚ±±±ß£¬
Î÷±ßÓĞÒ»ÉÈÄ¾ÃÅÍ¨Íù±ßÏá¡£
LONG);

  set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"sroad2",
]));
  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/teacher" : 1,
]));

  setup();
}
