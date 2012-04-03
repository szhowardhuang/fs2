///open/prayer/room/hole/5.c

#include <room.h>
#include "/open/open.h"
inherit ROOM;
int have=1;
int time=0;

void create()
{
        set("short", "¶´Ñ¨");
        set("long", @LONG

        ¶´¿ßÄÚµÄÊ¯±ÚÉÏ¶¼ÊÇÒ°ÊÞµÄ×¦ºÛ£¬»¹Õ´ÂúÁËÐí¶àµÄÑª¼£!!
        Ô¶´¦²»Ê±ÓÐÒ°ÊÞµÄ½ÐÉù£¬ÔÚÕâ¶´¿ßÄÚ»ØÏì²»ÒÑ.......°¡~
        !!Ô¶´¦´«À´Ò»Õó²Ò½ÐÉù£¬à¸à¸!!¿´À´Ç°ÃæÓÐÈË±»Ô×ÁË£¬ËÄ
        ´¦Å¨ÎíÃÔÂþ£¬ÉìÊÖÄÑ¼ûÎåÖ¸£¬Ö»ÒªÉÔÒ»Êèºö£¬ËæÊ±¶¼»á±ä
        ³ÉÒ°ÊÞµÄµãÐÄ......

LONG    );
        set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"7",
  "north":__DIR__"3",
]));
        set("evil",1);
        set("no_auc",1);
        set("no_transmit",1);
        setup();
}

void init()
{
    add_action("search_here", "search");
    add_action("dig_it","dig");
}

int search_here(string arg)
{
    object who=this_player();
if( who->query_temp("metal/where",7) )
      write("ÄãÔÚÕâÀïµÄËÄÖÜÇÃÇÃ´ò´òµÄ, ÖÕÓÚ·¢ÏÖÁËÒ»´¦ÍÚ¾ò¹ýµÄºÛ¼£..\n"+
      "ÍÚÍÚ¿´ (dig) °É!! Ëµ²»¶¨ÕæÄÜÍÚ³öÊ²Ã´¶«¶«À´Ò®!!\n");
      else
      write("ÄãÔÚ¸ÉÂïÑ½??\n");
    return 1;
}

int dig_it(string arg)
{
    object who,ob;
    who = this_player();
    if( who->query_temp("metal/where",7)  )
    {
    ob=new("/open/prayer/obj/gold");
    have = 0;
    ob->move(who);
    message_vision("[36mÒ»ÕóÍÚ¾òÖ®ºó, ÖÕÓÚÍÚ³öÀ´ÁËÒ»¿é½ð¿ó!![0m\n", who);
    who->delete_temp("metal/where");
    return 1;
    }
    return 0;
}   
void heart_beat()
{
 time++;
 if( time > 6000)
 {
   time=0;
   have=1;
  }
  return;
}   
