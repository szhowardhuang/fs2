//open/prayer/room/westarea/road12.c

#include <room.h>
#include "/open/open.h"
inherit ROOM;
int have=1;
int time=0; 
 
void create()
{
        set("short","½ÖµÀ");
        set("long",@LONG
        Î÷ÎäÁÖ×Ô³ÉÒ»¸ñµÄ½ÖµÀ, ËÄÍ¨°Ë´ï, ´¦´¦·±»ª. Íù¶«¿ÉÒÔµ½´ï
        ÌìÊàÃÅÓëÌìÈ¨ÃÅ. ÖÁÓÚÆÆĞ°¶´¿ßµÄ´æÔÚ, ÊÇÒòÎªµ±Ê±Î´¿ª·¢µÄ
        Î÷Óòµ½´¦¶¼ÊÇÆæ¹ÖµÄ¹ÖÎï, ½ÌÖ÷ÎªÁËÒª¿ª±ÙÊ¥»ğ½Ì, ±ãÒÔÒ»¼º
        Ö®Á¦½«ËüÃÇÈ«²¿ÖÆ·şºó, ÔÙ½¨Ôì³öÀ´Ò»¸ö¶´¿ßµ±×ö·ÅÖÃ¹ÖÎïµÄ
        ³¡Ëù!! 
LONG);

        set("outdoors", "/open/prayer");
        set("exits", ([ /* sizeof() == 2 */
        "east":__DIR__"road11",                 //½ÖµÀ
        "west":__DIR__"road13",         //½ÖµÀ
 
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
    ob=new("/open/prayer/obj/copper");
    have = 0;
    ob->move(who);
    message_vision("[36mÒ»ÕóÍÚ¾òÖ®ºó, ÖÕÓÚÍÚ³öÀ´ÁËÒ»¿é[Í­¿ó]!![0m\n", who);
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
