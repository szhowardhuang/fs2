// Room: /open/death/gate.c
#include <ansi.h>

inherit ROOM;

void create ()
{
  set ("short", "[1;37m¹íÃÅ¹Ø[2;37;0m");
  set ("long", @LONG
ÕâÀï¾ÍÊÇÖøÃûµÄÒõ¼äÈë¿Ú¡¸¹íÃÅ¹Ø¡±£¬ÔÚÄãÃæÇ°´£Á¢×ÅÒ»×ù¸ß´óµÄ
ºÚÉ«³ÇÂ¥£¬ÖÚ¶àÍö»êÕı¿Ş¿ŞÌäÌäµØÁĞ¶ÓÇ°½ø£¬ÒòÎªÒ»½ø¹íÃÅ¹Ø¾ÍÎŞ·¨ÔÙ
»ØÑô¼äÁË¡£
LONG);
 set("no_auc",1);
  set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"gateway",
  "south" : __DIR__"bridge3",
]));
  set("light_up", 1);
  set("no_fight", 1);
  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/wgargoyle" : 1,
]));
  set("no_magic", 1);
  set("no_transmit", 2);

  setup();
}

int valid_leave(mixed me, string dir)
{
        if (dir == "south") 
                return notify_fail("½øÁË¹íÃÅ¹Ø¾Í±ğÏë»ØÈ¥ÁË£¡\n");
        else
                return 1;
}

