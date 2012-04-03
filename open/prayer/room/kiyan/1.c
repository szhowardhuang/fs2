//open/prayer/room/kiyan/1.c

#include <room.h>
#include "/open/open.h"

inherit ROOM;
int have=1;
int time=0;
 
void create()
{
        set("short","ÃÅÖ÷µÄ·¿¼ä");
        set("long",@LONG

        ÃÅÖ÷µÄ·¿¼äÒ»ÑÛ¿´È¥·Ç³£µÄÕûÆë£¬Ô­ÒòÊÇ·¿¼äÄÚµÄ°Ú\ÉèÊµÔÚÊÇÌ«ÉÙ
        ÁË£¬Ö»ÓĞÒ»×ùĞ¡Ğ¡µÄÄ¾°å´²!!£®±ÚÉÏ¹Ò×ÅÒ»¿ÚºìÉ«Íâ¿ÇµÄ¶Ì½£!!ÅÔ
        ±ßÓĞÒ»ĞĞĞ¡Ğ¡µÄÓ¬Í·Ğ¡×Ö£®²»ÖªµÀÊÇ×Ô¼ºÎÄÑ§³Ì¶ÈÌ«²î»¹ÊÇÔõÃ´µÄ
        £¬¾ÍÊÇ¿´²»¶®ËûĞ´Ğ©Ê²Ã´??

LONG);
        set("exits", ([ /* sizeof() == 1 */
        "south":__DIR__"4",             //ÃÅÖ÷
]) );
        set("no_fight", 0);
        set("light_up", 1);
  setup();
}

void init()
{
    add_action("search_here", "search");
    add_action("take_it","take");
}

int search_here(string arg)
{
    if( (this_player()->query("combat_exp",1) > 100000)  && have)
      write("Äã³¯Ç½ÉÏÍûÑ½ÍûµÄ,·¢ÏÖÕâ¿Ú±¦½£ÊµÔÚÊÇ·Ç³£µÄÆ¯ÁÁÓë¸ß¹ó.ÕæÏëÍµÍµÄÃ×ß..\n"+
               "Äãµ¨×ÓÒ»´ó,¾ö¶¨Òª½«ËüÄÃ×ß(take it).\n");
    else
       write("Ò²ĞíÊÇÄãµÄµ¨×Ó²»¹»´ó,Äã²»¸Ò¶ÔÕâ¿Ú±¦½£ÓĞËùåÚË¼...\n");
    return 1;
}
int take_it(string arg)
{
    object user,ob;
    user = this_player();
    if( this_player()->query("quests/girlsword",1) && !present("Red-sword",user) )
    {
    ob=new("/open/prayer/obj/sword");
    have = 0;
    ob->move(this_player());
    message_vision("[36mµ±$N½«[32m±¦½£[36m³é³öÀ´,Ö»¼û±¦½£[33mºÀ¹âËÄÉä[36m.........ÍÛ!!Ò»¿ÚÉÏºÃµÄ½£Ò®!![0m\n", user);
    return 1;
    }
    return 0;
}   
void heart_beat()
{
 time++;
 if( time > 3000)
 {
   time=0;
   have=1;
  }
  return;
}   
