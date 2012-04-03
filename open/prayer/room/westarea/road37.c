//open/prayer/room/westarea/road37.c

#include <room.h>
#include "/open/open.h"
inherit ROOM;
int have=1;
int time=0; 
 
void create()
{
        set("short","½ÖµÀ");
        set("long",@LONG

        Ê¥»ğ½ÌÄÏ±±ÏòµÄ¿ìËÙµÀÂ·. Íù±±±ß×ß¿ÉÒÔµ½´ïÊ¥»ğ½ÌµÄ×ÜÌ³. 
        ËÄ·½Ôòµ½´¦¿É¼ûÊ¥»ğ½ÌµÄ¸÷¸öÖ§ÃÅ. ÄÏ±ßÊÇÓëÖĞÔ­ÎäÁÖÏàÍ¨µÄ
        ğ®µÀ. »ëÌìĞÄ·¨¹²ÓĞÊ®²ã, Ö»ÓĞ½ÌÖ÷±¾ÈËÁ·µ½µÚ¾Å²ãµÄ[ Ñªñ·
        ²Ô ], ÆäÓàµÄÃÅÖ÷ÖĞ, Ö»ÓĞÒ»Î»Ë¾Í½Öª»ªÁ·µ½µÚ°Ë²ã!!

LONG);

        set("outdoors", "/u/r/rence");
        set("exits", ([ /* sizeof() == 3 */
        "north":__DIR__"road33",        //½ÖµÀ
        "south":"/open/main/room/maiu-1",               //½ÖµÀ
        "east":__DIR__"road36",         //½ÖµÀ
        "west":__DIR__"road38",         //½ÖµÀ

        ]) );
        set("no_fight", 0);
        
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
      write("ÄãÔÚÕâÀïµÄËÄÖÜÇÃÇÃ´ò´òµÄ, ÖÕÓÚ·¢ÏÖÁËÒ»´¦ÍÚ¾ò¹ıµÄºÛ¼£..\n"+
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
    message_vision("[36mÒ»ÕóÍÚ¾òÖ®ºó, ÖÕÓÚÍÚ³öÀ´ÁËÒ»¿é½ğ¿ó!![0m\n", who);
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
