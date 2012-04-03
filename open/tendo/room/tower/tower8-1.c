
#include <ansi.h>
inherit ROOM;

void create()
{
  string long;

set("short","ÃÜÊÒ");
        set("long", @LONG
ÕâÊÇÒ»¸ö¿Õ¿õ¡¢¸É¾»¡¢°ÚÉèÊ®·Ö¼òµ¥£¬Ö»ÓĞÒ»ÕÅ´²ºÍÒ»Ğ©¼òµ¥¼Ò
¾ãµÄ·¿¼ä£¬²»¹ıÄã×¢Òâµ½£¬¶«±ßµÄÇ½(wall)ºÍ±ğµÄµØ·½µÄÇ½ÑÕÉ«ÓĞµã
²»Í¬£¬ÄãÔÚÏë--¿ÉÄÜÊÇÒòÎªµØµÀµÄ¹ØÏµ°É!!ÇÒ×óÓÒµÄ»ğ°ÑÉÁË¸²»¶¨Ê¹
Äã¸ü¼ÓÈ·¶¨ÄãµÄÍÆ²â¡£
LONG);
set("item_desc", ([ /* sizeof() == 1 */
"wall" : "Äã·¢ÏÖÕâ¸öÇ½¹Ö¹ÖµÄ£¬ËÆºõ¿ÉÒÔÍÆ¶¯¡£
",
]));

  set("exits", ([ /* sizeof() == 1 */
  "out" : __DIR__"tower8.c",
]));
  set("no_transmit",1);
  setup();
}
void init()
{
        add_action("do_push","push");
}

int do_push(string str)
{
        object who;
        who = this_player();

        if(str!="wall"){return 0;}
        tell_object(who,"[1;33mÄãÇáÇáµÄÍÆÁËÒ»ÏÂÇ½£¬µ«Ç½È´¿ìËÙµÄ×ªÁËÒ»È¦£¬Ò²Á¬´ø°ÑÄã×ª"+"ÁË½øÈ¥¡£[0m\n");
        who->move("/open/tendo/room/tower/tower8-2");
        tell_room(this_object(),"[1;33mÄã¿´µ½¾¡Í·µÄÇ½±»[1;37m"+who->query("name")+"[1;33mÒ»ÍÆÖ®ÏÂ"
				+"[1;33m×ª¶¯ÁËÒ»È¦£¬¶ø[1;37m"+who->query("name")+"[1;33mÒ²±»Ç½¸ø"+
				"[1;33m×ªÁË½øÈ¥¡£[0m\n");
        return 1;
}


