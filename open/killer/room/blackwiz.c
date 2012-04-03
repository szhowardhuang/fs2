#include <room.h>
inherit ROOM;
 void create()
{
  set("short", "Íæ¼ÒÒé¼û·¢±íÊÒ");
  set("long", @LONG
  ¸÷Î»...×î½ü±¾ÅÉ·Ç·Ç·Ç·Ç·Ç³£Ö®ÀäÇå,Òò´ËÏ£ÍûÍæ¼ÒÄÜ¹»¶à¶à½¨ÒéÒ»Ð©
Ò²»¶Ó­ÔÝÊ±¹àË®Òà¿É....
                       Íæ¼Ò¿É¿ªÊ¼ÔÚ´ËÁôÑÔÁË....no idea.




LONG);
        set("exits", ([ /* sizeof() == 1 */
	"south":__DIR__"r3",
	"west":"/open/killer/room/r0.c",
  ]));
       setup();
        call_other("/obj/board/killerwiz_b","???");
}
int valid_leave(object me, string dir)
{
  if (me->query("class")!="killer" && dir=="west")
 return notify_fail("ÕâÊÇÉ±ÊÖµÄ½ûµØ!ÓÉÓÚÄãÃ»Á·[1m°ÔÓêó§»ê[0m,¹ÊÄãÎÞ·¨½øÈë!\n");

return ::valid_leave(me,dir);
}
void init()
{
  add_action("do_pass","pass");
}
int do_pass()
{
  object me;
  me = this_player();
  me->move("/open/center/room/inn");
  return 1;
}
