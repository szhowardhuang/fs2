///open/prayer/room/hole/13.c

#include <room.h>
#include "/open/open.h"
inherit ROOM;

int have=1;
int time=0;

void create()
{
        set("short", "¶´Ñ¨");
        set("long", @LONG

        ÄãÍ»È»¿ªÊ¼Ò¡Ò¡»Î»Î£¬Õ¾Ò²Õ¾²»ÎÈµ¹ÔÚµØÉÏ£¬ß×??µØÕð
        Âð??ºöÈ»Ô¶·½´«À´Ä§ÊÞµÄÅØÐ¥Éù"°¡¡«¡«ÎØ¡«!!"£¬½Ó×Å
        ºäÂ¡!!ºäÂ¡!!ÍÛ~~!!ÊÇÊ²Ã´¾ÞÊÞ£¬×ßÆðÂ·À´Ìì±ÀµØÁÑËÆ
        µÄ??

LONG    );
    set("objects", ([ /* sizeof() == 2 */
   "/open/prayer/npc/crab-ox" : 1,              
   "/open/prayer/npc/evil-tiger" : 1,           
]));
        set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"15",
  "west":__DIR__"11",
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
    ob=new("/open/prayer/obj/silver");
    have = 0;
    ob->move(who);
    message_vision("[36mÒ»ÕóÍÚ¾òÖ®ºó, ÖÕÓÚÍÚ³öÀ´ÁËÒ»¿éÒø¿ó!![0m\n", who);
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
