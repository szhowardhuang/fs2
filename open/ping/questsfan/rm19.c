// Room: /u/d/dhk/questsfan/rm19
//________by dhk 2000.4.5__________
inherit ROOM;
#include <room.h>
#include <ansi.h>
#include </open/open.h>
void create ()
{
  set ("short", "[0;32mÔÆÎíËÉÁÖ[1;37m©¤[1;36mÖ÷ÁÖ[2;37;0m");
  set ("long", @LONG
Ô½×ßÔ½À´Ô½ÓĞÒ»ÖÖÉíÔÚÁÖÉî¡¢²»Öª´¦Ö®¸Ğ¡£ÕâÆ¬ÔÆÎíËÉÁÖÕæ
ÊÇÓĞ¹»¹ã´ó¡£ßÏ!!©¤©¤©¤×ĞÏ¸Ò»¿´!!Ô­À´ÕıÇ°·½²»Ô¶´¦ÓĞÒ»Öê¾ŞĞÎ
éÅÊ÷¡£ËµËûÊÇÇ§ÄêÀÏÊ÷Ò»µã¶¼²»¿äÕÅÑ½!´ËÊ÷Ëä²»¸ßµ«Ê÷Î§×ã×ãÓĞ
ÒªËÄÎåÊ®Ãû×³ºº³Å³¤Ë«±Û²ÅÄÜ»·±§µÄ´Ö´ó¡£¶øÇÒÖ¦Ò¶Ã¯Ê¢¡¢ Ô­À´
ÔÆÎíËÉÁÖµÄÕæÃæÄ¿¾¹ÊÇÑÛÇ°ÕâÖêÀÏéÅ£¬ËùÍØÕ¹³öÀ´µÄ¡£

LONG);

  set("exits", ([ /* sizeof() == 6 */
  "westup" : __DIR__"rm14",
  "westdown" : __DIR__"rm20",
  "southdown" : __DIR__"rm17",
  "northup" : __DIR__"rm13",
  "eastdown" : __DIR__"rm18",
  "eastup" : __DIR__"rm12",
]));
  set("outdoors", "/u/d");

  setup();
}
void init()
{
        add_action("do_search", "search");
}
int do_search()
{
          object who;
          who = this_player(); 
if( who->query("id") == "dhk" )
{
tell_object(who,"\nÄã×ĞÏ¸ËÑË÷£¬ÖÕÓÚÕÒµ½Ò»¸öÒşÃÜµÄÈë¿Ú¡£\n\n");
          who->move(__DIR__"sproom");
}
          return 1;
}
int valid_leave(object who,string dir){
   if(dir=="search" && query("class")!="scholar")
     {
     message_vision(HIC"Ò»Õóº§ÈË¹îÒìµÄÉùÒô¶Ô$NËµµÀ:×ğÌì¶´Ìì
ÆñÊÇÈÃÈËËæÒâ½øÈëµÄµØ·½?»¹²»¿ì¹ö!!\n"NOR,who);
       return notify_fail("Ò»Õóº§ÈË¹îÒìµÄÉùÒô¶Ô$NËµµÀ:×ğÌì¶´ÌìÆñÊÇÈÃÈË
ËæÒâ½øÈëµÄµØ·½?»¹²»¿ì¹ö!!\n");
     }
   return :: valid_leave(who,dir);
}
