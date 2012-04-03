//open/prayer/room/westarea/road31.c

#include <room.h>
#include "/open/open.h"
inherit ROOM;
int have=1;
int time=0;
 
void create()
{
        set("short","½ÖµÀ");
        set("long",@LONG

        Î÷ÎäÁÖ×Ô³ÉÒ»¸ñµÄ½ÖµÀ, ËÄÍ¨°Ë´ï, ´¦´¦·±»ª. ÕâÀïÊÇÎ÷ÓòÎ÷
        ±ßµÄÈı²æÂ·¿Ú. ±±±ßÊÇÍùÓñºâÃÅ, ÄÏ±ßÊÇÍùÑş¹âÃÅ. [ Ê¥»ğÈı
        ³¤ÀÏ ]ÔòÊÇÊôÓÚµÚÈı´óµÄÖ°µÈ, Èı³¤ÀÏ·Ö±ğÎª´«¹¦, ½äÂÉÒÔ¼°
        Ö´·¨³¤ÀÏ. Ö±½ÓÌıÁîÓÚ½ÌÖ÷µÄµ÷¶È.

LONG);

        set("outdoors", "/u/r/rence");
        set("exits", ([ /* sizeof() == 3 */
        "north":__DIR__"road26",        //½ÖµÀ
        "south":__DIR__"road34",        //½ÖµÀ
        "east":__DIR__"road30",         //½ÖµÀ
 
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
