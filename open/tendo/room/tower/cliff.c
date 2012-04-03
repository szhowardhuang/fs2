#include <room.h>
inherit ROOM;
void create()
{
        set("short", "ÇÍ±Ú");
	set("long", @LONG
ÕâÊÇÒ»Æ¬ÇÍ±ÚµÄÕıÏÂ·½£¬ÓÉÓÚÕâ¸öµØ·½Ö»ÊÇÒ»Æ¬ÇÍ±Ú£¬ËùÒÔ¸ù±¾ºÜ
ÉÙÈËÔÚ´Ë¶ºÁô£¬¶øÕâÀïÒ²ÊÇÒ»Æ¬»ÄÎßµÄ¾°Ïó£¬ÇÍ±ÚÉÏ´¹ÂúÁËÂûÉúµÄÌÙ£¬
¶øÇÍ±ÚÏÂÒ²¶¼³¤ÂúÁË¸ß¹ıÈËÍ·µÄÔÓ²İ(brush)¡£
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south"  : "/open/tendo/room/tower/cave2",
]));
	set("outdoors", 1);
	setup();
}
void init()
{
        add_action("enter_brush", "enter" );
}
int enter_brush(string str)
{
    if(str!="brush")
      {
       write("ÄãÒª½øÈ¥ÄÇÀï°¡£¿\n");
        return 0;
      }
      else
      {
       write("[1;32mÄã²¦¿ªÁË²İ´Ô£¬×ßÁË½øÈ¥¡£[0m\n");
        say("[1;32m"+this_player()->query("name")+"´©¹ıÁË²İ´Ô£¬·¢³öÉ³É³Éù¡£[0m\n");
       this_player()->move("/open/tendo/room/tower/room5a");
       say("[1;32m²İ´Ô·¢³öÉ³É³Éù£¬"+this_player()->query("name")+"²¦¿ªÁË²İ´Ô£¬×ßÁË½øÀ´¡£[0m\n");
       return 1;
}
}


