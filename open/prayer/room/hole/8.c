///open/prayer/room/hole/8.c

#include <room.h>
#include "/open/open.h"
inherit ROOM;
int have=1;
int time=0;

void create()
{
        set("short", "¶´Ñ¨");
        set("long", @LONG

        ÕâÀï¾ÍÊÇÆÆÐ°¶´¿ßµÄÄÚ²¿ÁË!!ÑªºìÉ«µÄÅ¨ÎíÆ®À´£¬ÎÅÆðÀ´
        ÓÐ¹ÉÐÈÎ¶!!ÁîÈËµÄÒâÊ¶½¥½¥Ä£ºý....... È¥ËÀ°É!!¿´ÎÒµÄ
        "ÎÞµÐ·ç»ðÂÖ"!!ß×??Ç°ÃæºÃÏñºÜ¾«²ÊµÄÑù×Ó£¬²»¸Ï¿ì¹ýÈ¥
        ÇÆÇÆ¾Í¿´²»µ½ºÃÏ·†ª!!ÄãÐÄÉñÒ»Õñ£¬¼Ó½ô½Å²½¼ÌÐøÍùÇ°ËÑ
        Ñ².....

LONG    );
        set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"10",
  "south":__DIR__"6",
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
    ob=new("/open/prayer/obj/copper");
    have = 0;
    ob->move(who);
    message_vision("[36mÒ»ÕóÍÚ¾òÖ®ºó, ÖÕÓÚÍÚ³öÀ´ÁËÒ»¿éÍ­¿ó!![0m\n", who);
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
