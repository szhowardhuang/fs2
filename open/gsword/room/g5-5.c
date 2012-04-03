// Room: /open/gsword/room/gsword3-7.c
inherit ROOM;
#include <ansi.h>
 int done;
void create ()
{
    seteuid(getuid());    // ²»ÊÇËµÒª¼ÓÕâÒ»ĞĞÂğ?
  set ("short", "²Ø½£ÊÒ");
  set ("long", @LONG
Ò»Èë·¿ÃÅ ,ÄãÂíÉÏ¸Ğµ½º®ÆøÆËÃæ¶øÀ´ ,ÂÔÒ»ÄıÉñ ,Ö»¼û×óÊ×Ò»¸öÆ½Ì¨ÉÏ ,Ò»¸ö
°µÂÌÉ«µÄºĞ×ÓÉ¢·¢³öÎŞ±ÈµÄº®Æø .¶øÓÒÊ×µÄÇ½±ÚÉÏµ¹ÊÇ¹ÒÕßĞíĞí¶à¶à²ÓÀÃ¶áÄ¿
µÄ±¦½£. Á½±ßµ¹ÊÇ³ÉÎªÃ÷ÏÔµÄ¶Ô±È.

LONG);


  set("exits", ([ /* sizeof() == 2 */
  "east":"/open/gsword/room/sproom.c"  
]));

  set("light_up", 1);
  set("no_clean_up",1);

  setup();
}

 void init()
{
 add_action("open_box","open");
 }
 
  int open_box(string str)
 {
  object me,ob;
  me =this_player();
  if( done== 0 )
      {
         message("system","[1;31mÖ»¼ûÊñÉ½ÉÏ¿ÕÒ»µÀºì¹â»®¿Õ¶ø¹ı[0m\n",users());
         message_vision("¾ªãµÖ®Óà ,ÄÇµÀºì¹âÒÑ½¥½¥µÄÄı¾ÛÔÚ$NÊÖÖĞ\n",me);
ob=new("/open/gsword/obj/spsword-1.c");
         ob->move(me);
       }
    
   else
    message_vision("ÏäÄÚ¾¹ÊÇ¿ÕÎŞÒ»Îï ,Äã²»½û´ôÁËÒ»»á\n",me);
  done=1;
  return 1;
  } 
